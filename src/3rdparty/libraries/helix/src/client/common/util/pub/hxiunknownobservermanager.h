/* ***** BEGIN LICENSE BLOCK *****
* Source last modified: $Id: hxiunknownobservermanager.h,v 1.3 2006/05/11 16:06:09 dcollins Exp $
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

#ifndef _HXIUNKNOWN_LIST_MANAGER_H_
#define _HXIUNKNOWN_LIST_MANAGER_H_

#include "hxtypes.h"
#include "ihxiunknownobservermanager.h"
#include "unkimp.h"
#include "ihxiunknownelementfunctor.h"
#include "hxslist.h"


class CHXIUnknownElementFunctor
    : public IHXIUnknownElementFunctor
    , public CUnknownIMP
{
public:
    CHXIUnknownElementFunctor( void ) {};
    virtual ~CHXIUnknownElementFunctor( void ) {};

    DECLARE_UNKNOWN(CHXIUnknownElementFunctor)

    //-------IHXIUnknownElementFunctor
    STDMETHOD_( void, Invoke )( THIS_ IUnknown* pIUnknownListElement );
    STDMETHOD_( void, Invoke )( THIS_ const IUnknown* pIUnknownListElement );
    STDMETHOD_( HXBOOL, ShouldStopInvoking) ( THIS );

    virtual void operator() ( IUnknown* pIUnknownListElement );
    virtual void operator() ( const IUnknown* pIUnknownListElement );
    virtual HXBOOL ShouldStopIterating( void );
};

class CHXIUnknownObserverManagerBase
{
public:

    CHXIUnknownObserverManagerBase( void );
    virtual ~CHXIUnknownObserverManagerBase( void );
    
    void AddIUnknownToList( IUnknown* pIUnknown );
    void RemoveIUnknownFromList( IUnknown* pIUnknown );
    void RemoveAllIUnknowns( void );
    void IterateOverIUnknowns( CHXIUnknownElementFunctor& IUnknownElementFunctor );
    void IterateOverIUnknowns( CHXIUnknownElementFunctor& IUnknownElementFunctor ) const;

protected:
    struct IUnknownObserverManagerEntry
    {
	IUnknown *pIUnknown;
	LONG32	 ulCount;
    };

    IUnknownObserverManagerEntry *FindIUnknownListEntry(IUnknown* pIUnknown);

    CHXSimpleList m_ListElements; 

private:
};

class CHXIUnknownObserverManagerMixin :    public CHXIUnknownObserverManagerBase,
					    public IHXIUnknownObserverManager
{
public:
    CHXIUnknownObserverManagerMixin( void ) {};
    virtual ~CHXIUnknownObserverManagerMixin( void ) {};
    
    //declare the base class implementation of IterateOverIUnknowns using the keyword "using" so that it
    //is not hidden this classes function of the same name.
    using CHXIUnknownObserverManagerBase::IterateOverIUnknowns;

    //-------------IHXIUnknownObserverManager
    STDMETHOD_( void, IterateOverIUnknowns ) ( THIS_ IHXIUnknownElementFunctor *pIUnkFunctor );

private:
    
};

#endif // _HXIUNKNOWN_LIST_MANAGER_H_
