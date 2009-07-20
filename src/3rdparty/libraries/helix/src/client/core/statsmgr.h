/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: statsmgr.h,v 1.4 2007/07/06 21:58:12 jfinnecy Exp $
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
 * terms of the GNU General Public License Version 2 (the
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

#ifndef _STATSMGR_H_
#define _STATSMGR_H_

typedef struct _STATSMAPENTRY
{
    UINT32	ulFrom;
    UINT32	ulTo;
    HXPropType	type;
} StatsMapEntry;

typedef struct _PROPWATCHENTRY
{    
    UINT32	    ulPropID;
    IHXPropWatch*  pPropWatch;
} PropWatchEntry;

class StatsManager : public IHXPropWatchResponse
{
public:
    StatsManager(HXClientRegistry*  pRegistry,
		 UINT32		    ulRegistryID,
		 UINT32		    ulRepeatedRegistryID);
    ~StatsManager();

    HX_RESULT	Copy(void);

    LONG32		    m_lRefCount;    
    UINT32		    m_ulRegistryID;
    UINT32		    m_ulRepeatedRegistryID;
    UINT32		    m_ulOffset;
    char*		    m_pRegistryName;
    HXClientRegistry*	    m_pRegistry;
    CHXMapLongToObj*	    m_pStatsMap;
    CHXSimpleList*	    m_pPropWatchList;

    /*
     *	IUnknown methods
     */
    STDMETHOD(QueryInterface)	(THIS_
				REFIID riid,
				void** ppvObj);

    STDMETHOD_(ULONG32,AddRef)	(THIS);

    STDMETHOD_(ULONG32,Release)	(THIS);

    // IHXPropWatchResponse methods
    STDMETHOD(AddedProp)	(THIS_
				const UINT32		ulHash,
				const HXPropType	type,
				const UINT32		ulParentHash);
    STDMETHOD(ModifiedProp)	(THIS_
				const UINT32		ulHash,
				const HXPropType	type,
				const UINT32		ulParentHash);
    STDMETHOD(DeletedProp)	(THIS_
				const UINT32		ulHash,
				const UINT32		ulParentHash);

    HX_RESULT	SetWatch(UINT32	ulRegistryID);
    HX_RESULT	DoCleanup(void);
    HX_RESULT	UpdateRegistry(UINT32 ulRegistryID);
};

#endif /* _STATSMGR_H_ */


