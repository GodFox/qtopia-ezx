/* ***** BEGIN LICENSE BLOCK ***** 
 * 
 * Portions Copyright (c) 1995-2006 RealNetworks, Inc. All Rights Reserved.
 * 
 * Patent Notices: This file may contain technology protected by one or 
 * more of the patents listed at www.helixcommunity.org
 * 
 * 1.   The contents of this file, and the files included with this file,
 * are protected by copyright controlled by RealNetworks and its 
 * licensors, and made available by RealNetworks subject to the current 
 * version of the RealNetworks Public Source License (the "RPSL") 
 * available at  * http://www.helixcommunity.org/content/rpsl unless 
 * you have licensed the file under the current version of the 
 * RealNetworks Community Source License (the "RCSL") available at
 * http://www.helixcommunity.org/content/rcsl, in which case the RCSL
 * will apply.  You may also obtain the license terms directly from
 * RealNetworks.  You may not use this file except in compliance with
 * the RPSL or, if you have a valid RCSL with RealNetworks applicable
 * to this file, the RCSL.  Please see the applicable RPSL or RCSL for
 * the rights, obligations and limitations governing use of the
 * contents of the file.
 * 
 * 2.  Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 (the
 * "GPL") in which case the provisions of the GPL are applicable
 * instead of those above.  Please note that RealNetworks and its 
 * licensors disclaim any implied patent license under the GPL.  
 * If you wish to allow use of your version of this file only under 
 * the terms of the GPL, and not to allow others
 * to use your version of this file under the terms of either the RPSL
 * or RCSL, indicate your decision by deleting Paragraph 1 above
 * and replace them with the notice and other provisions required by
 * the GPL. If you do not delete Paragraph 1 above, a recipient may
 * use your version of this file under the terms of any one of the
 * RPSL, the RCSL or the GPL.
 * 
 * This file is part of the Helix DNA Technology.  RealNetworks is the
 * developer of the Original Code and owns the copyrights in the
 * portions it created.   Copying, including reproducing, storing, 
 * adapting or translating, any or all of this material other than 
 * pursuant to the license terms referred to above requires the prior 
 * written consent of RealNetworks and its licensors
 * 
 * This file, and the files included with this file, is distributed
 * and made available by RealNetworks on an 'AS IS' basis, WITHOUT 
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, AND REALNETWORKS 
 * AND ITS LICENSORS HEREBY DISCLAIM  ALL SUCH WARRANTIES, INCLUDING 
 * WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS 
 * FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * 
 * Technology Compatibility Kit Test Suite(s) Location: 
 *    http://www.helixcommunity.org/content/tck
 * 
 * Contributor(s): 
 *
 * ***** END LICENSE BLOCK ***** */ 

#ifndef HXBUFFERPOOL_H
#define HXBUFFERPOOL_H

// Includes
#include "ihxpckts.h"
#include "baseobj.h"

// Forward declarations
_INTERFACE IHXMutex;
class CHXBufferPoolManager;
class CHXSimpleList;

class CHXBufferFromPool : public IHXBuffer,
                          public CHXBaseCountingObject
{
    friend class CHXBufferPoolManager;
public:
    // IUnknown methods
    STDMETHOD(QueryInterface)   (THIS_ REFIID riid, void** ppvObj);
    STDMETHOD_(ULONG32,AddRef)  (THIS);
    STDMETHOD_(ULONG32,Release) (THIS);

    // IHXBuffer methods
    STDMETHOD(Get)               (THIS_ REF(UCHAR*) rpData, REF(ULONG32) rulLength);
    STDMETHOD(Set)               (THIS_ const UCHAR* pData, ULONG32 ulLength);
    STDMETHOD(SetSize)           (THIS_ ULONG32 ulLength);
    STDMETHOD_(ULONG32,GetSize)  (THIS);
    STDMETHOD_(UCHAR*,GetBuffer) (THIS);
protected:
    INT32                 m_lRefCount;
    CHXBufferPoolManager* m_pBufferPoolManager;
    IHXBuffer*            m_pBuffer;
    UINT32                m_ulSizeUsed;

    // Private constructor and destructor
    CHXBufferFromPool(CHXBufferPoolManager* pMgr, IHXBuffer* pBuffer, UINT32 ulSizeUsed);
    ~CHXBufferFromPool();
};

class CHXBufferPoolManager : public IUnknown,
                             public CHXBaseCountingObject
{
    friend class CHXBufferFromPool;
public:
    CHXBufferPoolManager();

    // IUnknown methods
    STDMETHOD(QueryInterface)   (THIS_ REFIID riid, void** ppvObj);
    STDMETHOD_(ULONG32,AddRef)  (THIS);
    STDMETHOD_(ULONG32,Release) (THIS);

    // CHXBufferPoolManager methods
    HX_RESULT Init(IUnknown* pContext);
    HX_RESULT GetBufferFromPool(UINT32 ulSize, REF(IHXBuffer*) rpBuffer);
    void      Close();
protected:
    INT32          m_lRefCount;
    IUnknown*      m_pContext;
    CHXSimpleList* m_pFreeList;
    IHXMutex*      m_pFreeListMutex;

    ~CHXBufferPoolManager();

    HX_RESULT FindBufferInPool(UINT32 ulSize, REF(IHXBuffer*) rpBuffer);
    void      PutBufferInPool(IHXBuffer* pBuffer);
    void      ClearFreeList();
};

#endif /* #ifndef HXBUFFERPOOL_H */
