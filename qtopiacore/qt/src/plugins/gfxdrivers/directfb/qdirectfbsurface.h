/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDIRECFBWINDOWSURFACE_H
#define QDIRECFBWINDOWSURFACE_H

#include "qdirectfbpaintengine.h"

#include <private/qpaintengine_raster_p.h>
#include <private/qwindowsurface_qws_p.h>
#include <directfb.h>

class QDirectFBSurface :
    public QWSWindowSurface, public QCustomRasterPaintDevice
{
public:
    QDirectFBSurface();
    QDirectFBSurface(QWidget *widget);
    ~QDirectFBSurface();

    bool isValid() const;

    void setGeometry(const QRect &rect, const QRegion &mask);

    QString key() const { return QLatin1String("directfb"); }
    QByteArray permanentState() const;
    void setPermanentState(const QByteArray &state);

    bool scroll(const QRegion &area, int dx, int dy);

    bool move(const QPoint &offset);
    QRegion move(const QPoint &offset, const QRegion &newClip);

    QImage image() const { return QImage(); }
    QPaintDevice* paintDevice() { return this; }
    QPaintEngine* paintEngine() const;

    void flush(QWidget *widget, const QRegion &region, const QPoint &offset);

    IDirectFBSurface* surface() const { return dfbSurface; }

    void beginPaint(const QRegion &);
    void endPaint(const QRegion &);

    QImage* buffer(const QWidget *widget);
    void* memory() const;
    int bytesPerLine() const;

    bool lockDirectFB();
    void unlockDirectFB();

private:
#ifndef QT_NO_DIRECTFB_WM
    void createWindow();
    IDirectFBWindow *dfbWindow;
#endif
    IDirectFBSurface *dfbSurface;
    QDirectFBPaintEngine *engine;

    bool onscreen;

    QList<QImage*> bufferImages;
    QImage *surfaceImage;
};

#endif // QDIRECFBWINDOWSURFACE_H
