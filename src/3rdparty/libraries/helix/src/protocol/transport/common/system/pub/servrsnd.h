/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: servrsnd.h,v 1.4 2005/03/10 20:59:21 bobclark Exp $
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

#ifndef _SERVER_RESEND_H_
#define _SERVER_RESEND_H_

class HX_deque;
class BasePacket;

class RTSPResendBuffer
{
public:
    RTSPResendBuffer(UINT32 bufferDuration, UINT32 maxBufferDuration,
                     UINT32 growthRate, UINT32 wrapSequenceNumber);
    ~RTSPResendBuffer();

    void		Clear();
    void		Grow();
    void		Add(BasePacket* pPacket);
    void		Remove(UINT16 uSeqNo);
    BasePacket*		Find(UINT16 uSeqNo, HXBOOL bIsNAK);
    void		SetFirstSequenceNumber(UINT16 uSeqNo);
    UINT32		GetIndex(UINT32 uBaseSequenceNumber, UINT16 uSeqNo);
    UINT32		GetPacketIndex(UINT16 uSeqNo);
    UINT32		GetForceIndex(UINT16 uSeqNo);
    void		DiscardExpiredPackets(HXBOOL bForce,
			                      UINT32 uParameter);
    void		SetBufferDepth(UINT32 uMilliseconds);
    void		SetMaxBufferDepth(UINT32 uMilliseconds);
    HX_RESULT		UpdateStatistics(UINT32& ulResendSuccess,
			                 UINT32& ulResendFailure);

private:
    HX_deque*		m_pPacketDeque;
    HX_deque*		m_pTSWindowQ;
    UINT32		m_bufferDuration;
    UINT32		m_maxBufferDuration;
    UINT32		m_growthRate;
    UINT32		m_wrapSequenceNumber;
    UINT16		m_uFirstSequenceNumber;
    UINT16		m_uForceSequenceNumber;
    UINT32		m_ulResendSuccess;
    UINT32		m_ulResendFailure;
    HXBOOL		m_bSetFirstSequenceNumber;
};

inline UINT32
RTSPResendBuffer::GetPacketIndex(UINT16 uSeqNo)
{
    return GetIndex(m_uFirstSequenceNumber, uSeqNo);
}

inline UINT32
RTSPResendBuffer::GetForceIndex(UINT16 uSeqNo)
{
    return GetIndex(m_uForceSequenceNumber, uSeqNo);
}

#endif /* _SERVER_RESEND_H_ */
