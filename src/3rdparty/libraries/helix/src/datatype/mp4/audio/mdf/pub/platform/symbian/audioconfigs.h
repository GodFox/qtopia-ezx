/* ***** BEGIN LICENSE BLOCK ***** 
 * Version: RCSL 1.0/RPSL 1.0 
 *  
 * Portions Copyright (c) 1995-2002 RealNetworks, Inc. All Rights Reserved. 
 *      
 * The contents of this file, and the files included with this file, are 
 * subject to the current version of the RealNetworks Public Source License 
 * Version 1.0 (the "RPSL") available at 
 * http://www.helixcommunity.org/content/rpsl unless you have licensed 
 * the file under the RealNetworks Community Source License Version 1.0 
 * (the "RCSL") available at http://www.helixcommunity.org/content/rcsl, 
 * in which case the RCSL will apply. You may also obtain the license terms 
 * directly from RealNetworks.  You may not use this file except in 
 * compliance with the RPSL or, if you have a valid RCSL with RealNetworks 
 * applicable to this file, the RCSL.  Please see the applicable RPSL or 
 * RCSL for the rights, obligations and limitations governing use of the 
 * contents of the file.  
 *  
 * This file is part of the Helix DNA Technology. RealNetworks is the 
 * developer of the Original Code and owns the copyrights in the portions 
 * it created. 
 *  
 * This file, and the files included with this file, is distributed and made 
 * available on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER 
 * EXPRESS OR IMPLIED, AND REALNETWORKS HEREBY DISCLAIMS ALL SUCH WARRANTIES, 
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS 
 * FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. 
 * 
 * Technology Compatibility Kit Test Suite(s) Location: 
 *    http://www.helixcommunity.org/content/tck 
 *
 * Contributor(s):
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef __AUDIO_CONFIGS_H__
#define __AUDIO_CONFIGS_H__

// extern
class CAudioSpecificConfig;

// factory method
HXAudioConfigurator* CreateAudioConfigFromFourCC(const char* pFourCC);

//*** AMR NB *****************************************************************

class HXAudioConfiguratorAMRNB: public HXAudioConfigurator
{
public:

    HXAudioConfiguratorAMRNB();
};

//*** AMR WB *****************************************************************

class HXAudioConfiguratorAMRWB: public HXAudioConfigurator
{
public:

    HXAudioConfiguratorAMRWB();
};

//*** AAC ********************************************************************

class HXAudioConfiguratorAAC: public HXAudioConfigurator
{
public:

    HXAudioConfiguratorAAC();

    virtual HX_RESULT ValidateDecoderConfig(UINT32 cfgType,
                                            const void* config,
                                            UINT32 nBytes);

    virtual HX_RESULT ConfigureDecoder(CMMFCodec* pDecoder);

private:

    HX_RESULT ExtractDecoderInfo(UINT32 cfgType,
                                 const void* config,
                                 UINT32 nBytes,
                                 CAudioSpecificConfig* pASConfig);
    HX_RESULT StoreDecoderInfo(CAudioSpecificConfig* pASConfig);
    HX_RESULT ValidateDecoderInfo();
    HX_RESULT ConfigureEAACPDecoder(CMMFCodec* pDecoder);
    HX_RESULT ConfigureAACDecoder(CMMFCodec* pDecoder);
    HX_RESULT SetFourCC();
    void SetProfile(UINT16 uObjectType);

    // AAC
    INT16                 m_nProfileType;

    // eAAC+
    HXBOOL                m_bIsSBR;
    UINT16                m_uDownSampleMode;
    UINT32                m_ulOutSamplesPerSecond;
    UINT16                m_uExtObjectType;
};

#endif // __AUDIO_CONFIGS_H__
