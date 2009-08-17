/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: hxval2util.cpp,v 1.1 2004/07/29 00:26:06 acolwell Exp $
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
#include "hxval2util.h"

HX_RESULT 
CHXIHXValues2Util::GetIHXValues2(IHXValues* pHdr, REF(IHXValues2*) pVal)
{
    HX_RESULT res = HXR_INVALID_PARAMETER;

    if (pHdr)
    {
        res = pHdr->QueryInterface(IID_IHXValues2, (void**)&pVal);
    }

    return res;
}

HX_RESULT 
CHXIHXValues2Util::GetIHXValues2Property(IHXValues* pHdr, const char* pKey,
                                         REF(IHXValues2*) pVal)
{
    return GetProperty(pHdr, pKey, IID_IHXValues2, (void**)&pVal);
}

HX_RESULT 
CHXIHXValues2Util::GetIHXValues2Property(IHXValues2* pHdr, const char* pKey,
                                         REF(IHXValues2*) pVal)
{
    return GetProperty(pHdr, pKey, IID_IHXValues2, (void**)&pVal);
}

HX_RESULT 
CHXIHXValues2Util::GetIHXListProperty(IHXValues* pHdr, const char* pKey,
                                         REF(IHXList*) pVal)
{
    return GetProperty(pHdr, pKey, IID_IHXList, (void**)&pVal);
}

HX_RESULT 
CHXIHXValues2Util::GetIHXListProperty(IHXValues2* pHdr, const char* pKey,
                                      REF(IHXList*) pVal)
{
    return GetProperty(pHdr, pKey, IID_IHXList, (void**)&pVal);
}

HX_RESULT 
CHXIHXValues2Util::GetProperty(IHXValues* pHdr, const char* pKey,
                               REFIID riid, void** ppvObj)
{
    IHXValues2* pHdr2 = NULL;
    HX_RESULT res = GetIHXValues2(pHdr, pHdr2);

    if (HXR_OK == res)
    {
        res = GetProperty(pHdr2, pKey, riid, ppvObj);
    }
    HX_RELEASE(pHdr2);

    return res;
}

HX_RESULT 
CHXIHXValues2Util::GetProperty(IHXValues2* pHdr, const char* pKey,
                               REFIID riid, void** ppvObj)
{
    HX_RESULT res = HXR_INVALID_PARAMETER;

    if (pHdr && pKey)
    {
        IUnknown* pUnk = NULL;
        res = pHdr->GetPropertyObject(pKey, pUnk);

        if (HXR_OK == res)
        {
            res = pUnk->QueryInterface(riid, ppvObj);
        }
        HX_RELEASE(pUnk);
    }

    return res;
}




