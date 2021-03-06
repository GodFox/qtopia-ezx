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

#ifndef VENDOR_ERICSSON_P_H
#define VENDOR_ERICSSON_P_H

#include <qmodemservice.h>
#include <qmodemcall.h>
#include <qmodemcallprovider.h>
#include <qmodemsimtoolkit.h>
#include <qbandselection.h>

class QValueSpaceObject;
class QTimer;
class EricssonModemService;

class EricssonCallProvider : public QModemCallProvider
{
    Q_OBJECT
public:
    EricssonCallProvider( QModemService *service );
    ~EricssonCallProvider();

protected:
    QModemCallProvider::AtdBehavior atdBehavior() const;

private slots:
    void ecavNotification( const QString& msg );
};

class TrolltechSimToolkit : public QModemSimToolkit
{
    Q_OBJECT
public:
    TrolltechSimToolkit( QModemService *service );
    ~TrolltechSimToolkit();

public slots:
    void initialize();
    void begin();
    void end();

private slots:
    void tstb( bool ok );
    void tcmd( const QString& value );
    void tcc( const QString& value );
};

class TrolltechBandSelection : public QBandSelection
{
    Q_OBJECT
public:
    TrolltechBandSelection( EricssonModemService *service );
    ~TrolltechBandSelection();

public slots:
    void requestBand();
    void requestBands();
    void setBand( QBandSelection::BandMode mode, const QString& value );

private slots:
    void tbandGet( bool ok, const QAtResult& result );
    void tbandSet( bool ok, const QAtResult& result );
    void tbandList( bool ok, const QAtResult& result );

private:
    EricssonModemService *service;
};

class EricssonModemService : public QModemService
{
    Q_OBJECT
public:
    EricssonModemService
        ( const QString& service, QSerialIODeviceMultiplexer *mux,
          QObject *parent = 0, bool trolltechExtensions = false );
    ~EricssonModemService();

    void initialize();

private slots:
    void signalStrength( const QString& msg );
    void smsMemoryFull( const QString& msg );
    void ttzNotification( const QString& msg );
    void reset();

private:
    bool trolltechExtensions;
};

#endif
