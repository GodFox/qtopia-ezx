/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: rtspclntext.h,v 1.6 2007/07/06 20:51:36 jfinnecy Exp $
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

#ifndef _RTSPCLNTEXT_H_
#define _RTSPCLNTEXT_H_

#include "rtspclnt.h"

class RTSPClientProtocolExt: public RTSPClientProtocol
{
    DECLARE_MANAGED_COMPONENT(RTSPClientProtocolExt);
private:
    UINT16		m_uRDTFeatureLevel;

	    HX_RESULT	handleChallengeResponse(RTSPResponseMessage* pMsg);

protected:
    virtual HXBOOL	IsRealServer(void);
    virtual HX_RESULT   RetrieveChallenge(RTSPResponseMessage* pMessage);
    virtual HX_RESULT	sendSetupRequestMessageExt(RTSPStreamInfo* pStreamInfo, 
						   IHXValues*& pIHXValuesRequestHeaders,
						   HXBOOL bFirstSetup,
						   RTSPSetupMessage*& pMsg);
    virtual HX_RESULT	handleSetupResponseExt(RTSPStreamInfo* pStreamInfo,
					       RTSPResponseMessage* pMsg, 
					       RTSPSetupMessage* pSetupMsg);
    virtual HX_RESULT	DoSendRTTRequest(void);
    virtual HX_RESULT	DoSendBWReport(INT32 aveBandwidth,
				       INT32 packetLoss,
				       INT32 bandwidthWanted);

public:
    RTSPClientProtocolExt();
    ~RTSPClientProtocolExt();

    STDMETHOD_(UINT16, GetRDTFeatureLevel)(THIS) { return m_uRDTFeatureLevel; };
    
    STDMETHOD(Init)	(THIS_
			IUnknown*     pContext,
			const char*   pHostName,
			UINT16	      hostPort,
			IHXRTSPClientProtocolResponse* pClient,
			UINT32	      initializationType,
			IHXValues*    pSessionHeaders,
			IHXValues*    pInfo,
			HXBOOL	      bHTTPCloak,
			UINT16	      uCloakPort,
			HXBOOL	      bNoReuseConnection);
};

REGISTER_MANAGED_COMPONENT(RTSPClientProtocolExt);

#endif /* _RTSPCLNTEXT_H_ */