/* ***** BEGIN LICENSE BLOCK *****
 * Source last modified: $Id: CHXSymbianAudioSession.h,v 1.1 2007/04/03 18:24:49 rrajesh Exp $
 * 
 * Copyright Notices: 
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
 * available at  http://www.helixcommunity.org/content/rpsl unless  
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
 * Contributors: Nokia Inc
 *
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef _AUDIO_SESSION_H_
#define _AUDIO_SESSION_H_

#include <e32base.h>
#include <e32des8.h>
#include <stdio.h>

#include "CHXBaseAudioSession.h"
#include "CHXSymbianAudioDevice.h"

// Forward declaration
class CHXAudDevStatusObserver;

class CHXSymbianAudioSession
: public CHXBaseAudioSession
, public MHXSymbianAudioDevice
{ 

public:
    CHXSymbianAudioSession();
    virtual ~CHXSymbianAudioSession();


    // MHXSymbianAudioDevice functions
    virtual TInt Open();
    virtual void CloseDevice();
	// initialize audio device
    virtual TInt Init(int sampleRate, int channels,
              TMMFPrioritySettings* pPrioritySettings, HXBOOL bSecureAudio);

    virtual TInt Write(const IHXBuffer* pAudioBuf);

    // get the current time played out in ms
    virtual TUint GetTime();
	// get the number of blocks buffered in device
    virtual TUint GetBlocksBuffered();
	// enable playback
    virtual TInt Play();
	// pause playback
    virtual void Pause();
	// stop playback
    virtual void Stop();
	// returns true if not playing
    virtual  HXBOOL Stopped();
	// get the current volume
    virtual TInt GetVolume() const;
	// get the max volume
    virtual TInt GetMaxVolume() const;
	// get the min volume
    virtual TInt GetMinVolume() const;
	// set the current volume
    virtual void SetVolume(TInt volume);

    virtual void RequestDeviceTakenNotification(
        CHXAudDevStatusObserver* pDevStatusObserver);

    virtual void CancelDeviceTakenNotification();

    // Override CHXBaseDevSoundObserver callbacks
    void InitializeComplete(TInt aError);
    void PlayError(TInt aError);

private:

    TInt Init();
    TInt Write();

private:
    
    HXBOOL m_stopped;
    TInt   m_lAsyncWaitError;
    CHXAudDevStatusObserver* m_pAudDevStatusObserver;
    CActiveSchedulerWait*    m_pActiveSchedulerWait;
    HXBOOL m_bDevInitCompleted;

   
};

#endif // _AUDIO_SESSION_H_
