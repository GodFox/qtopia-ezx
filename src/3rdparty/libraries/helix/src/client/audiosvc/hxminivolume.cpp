/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: hxminivolume.cpp,v 1.4 2005/05/03 20:07:22 albertofloyd Exp $
 * 
 * Portions Copyright (c) 1995-2004 RealNetworks, Inc. All Rights Reserved.
 * 
 * The contents of this file, and the files included with this file,
 * are subject to the current version of the RealNetworks Public
 * Source License (the "RPSL") available at
 * http://www.helixcommunity.org/content/rpsl unless you have licensed
 * the file under the current version of the RealNetworks Community
 * Source License (the "RCSL") available at
 * http://www.helixcommunity.org/content/rcsl, in which case the RCSL
 * will apply. You may also obtain the license terms directly from
 * RealNetworks.  You may not use this file except in compliance with
 * the RPSL or, if you have a valid RCSL with RealNetworks applicable
 * to this file, the RCSL.  Please see the applicable RPSL or RCSL for
 * the rights, obligations and limitations governing use of the
 * contents of the file.
 * 
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 or later (the
 * "GPL") in which case the provisions of the GPL are applicable
 * instead of those above. If you wish to allow use of your version of
 * this file only under the terms of the GPL, and not to allow others
 * to use your version of this file under the terms of either the RPSL
 * or RCSL, indicate your decision by deleting the provisions above
 * and replace them with the notice and other provisions required by
 * the GPL. If you do not delete the provisions above, a recipient may
 * use your version of this file under the terms of any one of the
 * RPSL, the RCSL or the GPL.
 * 
 * This file is part of the Helix DNA Technology. RealNetworks is the
 * developer of the Original Code and owns the copyrights in the
 * portions it created.
 * 
 * This file, and the files included with this file, is distributed
 * and made available on an 'AS IS' basis, WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS HEREBY DISCLAIMS
 * ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET
 * ENJOYMENT OR NON-INFRINGEMENT.
 * 
 * Technology Compatibility Kit Test Suite(s) Location:
 *    http://www.helixcommunity.org/content/tck
 * 
 * Contributor(s):
 * 
 * ***** END LICENSE BLOCK ***** */

#include "hxresult.h"
#include "hxtypes.h"
#include "hxcom.h"
#include "hxausvc.h"
#include "hxminivolume.h"

#ifdef _DEBUG
#undef HX_THIS_FILE             
static const char HX_THIS_FILE[] = __FILE__;
#endif

/************************************************************************
 *  Method:
 *              IHXVolume::CHXVolume()
 *      Purpose:
 *              Constructor. Clean up and set free.
 */
CHXVolume::CHXVolume() :
                         m_lRefCount(0),
                         m_bMute(FALSE),
                         m_uVolume(HX_INIT_VOLUME),
                         m_pAdviseSink(NULL)
{
}

CHXVolume::~CHXVolume()
{
    HX_RELEASE(m_pAdviseSink);
}

HX_RESULT CHXVolume::QueryInterface(REFIID riid, void** ppvObj)
{
    QInterfaceList qiList[] =
        {
            { GET_IIDHANDLE(IID_IHXVolume), (IHXVolume*)this },
            { GET_IIDHANDLE(IID_IUnknown), (IUnknown*)(IHXVolume*)this },
        };
    
    return ::QIFind(qiList, QILISTSIZE(qiList), riid, ppvObj);
}

ULONG32 CHXVolume::AddRef()
{
    return InterlockedIncrement(&m_lRefCount);
}

ULONG32 CHXVolume::Release()
{
    if (InterlockedDecrement(&m_lRefCount) > 0)
    {
        return m_lRefCount;
    }

    delete this;
    return 0;
}

/*
 *  IHXVolume methods
 */

HX_RESULT CHXVolume::SetVolume( const UINT16 uVolume)
{
    m_uVolume   = uVolume;
    if( m_pAdviseSink)
        m_pAdviseSink->OnVolumeChange(uVolume);
    return HXR_OK;
}

HX_RESULT CHXVolume::SetMute(const HXBOOL bMute)
{
    m_bMute = bMute;
    if( m_pAdviseSink )
        m_pAdviseSink->OnMuteChange(bMute);
    return HXR_OK;
}


HX_RESULT CHXVolume::AddAdviseSink(IHXVolumeAdviseSink* pSink)
{
    HX_RESULT res = HXR_FAIL;
    if( pSink && pSink != m_pAdviseSink )
    {
        pSink->AddRef();
        HX_RELEASE(m_pAdviseSink);
        m_pAdviseSink = pSink;
        res = HXR_OK;
    }
    return res;
}

HX_RESULT CHXVolume::RemoveAdviseSink(IHXVolumeAdviseSink* pSink)
{
    HX_RESULT res =HXR_FAIL;
    if( pSink == m_pAdviseSink)
    {
        HX_RELEASE(m_pAdviseSink);
        res = HXR_OK;
    }
    
    return res;
}
