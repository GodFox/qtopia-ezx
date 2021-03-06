/****************************************************************************
**
** This file is part of the Qtopia Opensource Edition Package.
**
** Copyright (C) 2008 Trolltech ASA.
**
** Contact: Qt Extended Information (info@qtextended.org)
**
** This file may be used under the terms of the GNU General Public License
** versions 2.0 as published by the Free Software Foundation and appearing
** in the file LICENSE.GPL included in the packaging of this file.
**
** Please review the following information to ensure GNU General Public
** Licensing requirements will be met:
**     http://www.fsf.org/licensing/licenses/info/GPLv2.html.
**
**
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>

#include <QTimer>
#include <QDebug>

#include <qtopiaserverapplication.h>
#include <qtopiaipcenvelope.h>

#include "zylonitevolumeservice.h"


ZyloniteVolumeService::ZyloniteVolumeService():
    QtopiaIpcAdaptor("QPE/AudioVolumeManager/ZyloniteVolumeService")
{
    publishAll(Slots);

    QTimer::singleShot(0, this, SLOT(registerService()));
}

ZyloniteVolumeService::~ZyloniteVolumeService()
{
}

//public slots:
void ZyloniteVolumeService::setVolume(int volume)
{
    adjustVolume(volume, volume, Absolute);
}

void ZyloniteVolumeService::setVolume(int leftChannel, int rightChannel)
{
    adjustVolume(leftChannel, rightChannel, Absolute);
}

void ZyloniteVolumeService::increaseVolume(int increment)
{
    adjustVolume(increment, increment, Relative);
}

void ZyloniteVolumeService::decreaseVolume(int decrement)
{
    decrement *= -1;

    adjustVolume(decrement, decrement, Relative);
}

void ZyloniteVolumeService::setMute(bool)
{
}

void ZyloniteVolumeService::registerService()
{
    QtopiaIpcEnvelope   e("QPE/AudioVolumeManager", "registerHandler(QString,QString)");

    e << QString("Headset") << QString("QPE/AudioVolumeManager/ZyloniteVolumeService");

    QTimer::singleShot(0, this, SLOT(setCallDomain()));
}

void ZyloniteVolumeService::setCallDomain()
{
    QtopiaIpcEnvelope   e("QPE/AudioVolumeManager", "setActiveDomain(QString)");

    e << QString("Headset");
}

void ZyloniteVolumeService::adjustVolume(int leftChannel, int rightChannel, AdjustType adjust)
{
    qWarning("ZyloniteVolumeService::adjustVolume()");
    int mixerFd = open("/dev/mixer", O_RDWR);
    if (mixerFd >= 0)
    {
        unsigned int leftright;
        unsigned int left;
        unsigned int right;

        if (adjust == Relative)
        {
            ioctl(mixerFd, SOUND_MIXER_READ_ALTPCM, &leftright);

            left = (leftright & 0xff00) >> 8;
            right = (leftright & 0x00ff);

            left += leftChannel;
            right += rightChannel;
        }
        else
        {
            left = leftChannel;
            right = rightChannel;
        }

        if (left < 0)
            left = 0;
        if (left > 100)
            left = 100;

        if (right < 0)
            right = 0;
        if (right > 100)
            right = 100;

        leftright = (left << 8) | right;
        ioctl(mixerFd, SOUND_MIXER_WRITE_ALTPCM, &leftright);

        // ??
        leftright = (100 << 8) | 100;
        ioctl(mixerFd, SOUND_MIXER_WRITE_SPEAKER, &leftright);

        close(mixerFd);
    }
}

QTOPIA_TASK(ZyloniteVolumeService, ZyloniteVolumeService);

