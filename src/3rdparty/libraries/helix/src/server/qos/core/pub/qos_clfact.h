/* ***** BEGIN LICENSE BLOCK *****  
 * Source last modified: $Id: qos_clfact.h,v 1.4 2004/07/08 22:07:28 ghori Exp $ 
 *   
 * Portions Copyright (c) 1995-2003 RealNetworks, Inc. All Rights Reserved.  
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

#ifndef _QOS_CF_H_
#define _QOS_CF_H_

#ifdef HELIX_FEATURE_QOS
class RNQoSClassFactory;
#endif

class HXQoSClassFactory : public IHXQoSClassFactory
{
public:
    // Constructors
    HXQoSClassFactory();
    HXQoSClassFactory(Process* proc);

    // Destructors
    ~HXQoSClassFactory();
    // IUnknown methods
    STDMETHOD(QueryInterface)		(THIS_
					REFIID riid,
					void** ppvObj);

    STDMETHOD_(ULONG32,AddRef)		(THIS);

    STDMETHOD_(ULONG32,Release)		(THIS);

    // IHXQoSClassFactory methods    
    STDMETHOD(CreateInstance)		(THIS_
					 IHXQoSProfileConfigurator* pConfig,
					 REFCLSID   /*IN*/  rclsid,
					 void**	    /*OUT*/ ppUnknown); 

private:
    ULONG32                     m_lRefCount;
    Process*			m_proc;
#ifdef HELIX_FEATURE_QOS
    RNQoSClassFactory*          m_pRNQoSClassFactory;
#endif
};

#endif
