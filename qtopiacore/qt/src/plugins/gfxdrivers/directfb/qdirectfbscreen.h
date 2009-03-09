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

#ifndef QDIRECTFBSCREEN_H
#define QDIRECTFBSCREEN_H

#include <QtGui/qscreen_qws.h>

QT_BEGIN_HEADER

QT_MODULE(Gui)

#include <directfb.h>

#define Q_DIRECTFB_VERSION ((DIRECTFB_MAJOR_VERSION << 16) | (DIRECTFB_MINOR_VERION << 8) | DIRECTFB_MICRO_VERSION)

class QDirectFBScreenPrivate;

class Q_GUI_EXPORT QDirectFBScreen : public QScreen
{
public:
    QDirectFBScreen(int display_id);
    ~QDirectFBScreen();

    bool connect(const QString &displaySpec);
    void disconnect();
    bool initDevice();
    void shutdownDevice();

    void exposeRegion(QRegion r, int changing);
    void blit(const QImage &img, const QPoint &topLeft, const QRegion &region);
    void scroll(const QRegion &region, const QPoint &offset);
    void solidFill(const QColor &color, const QRegion &region);

    void setMode(int width, int height, int depth);
    void blank(bool on);

    QWSWindowSurface* createSurface(QWidget *widget) const;
    QWSWindowSurface* createSurface(const QString &key) const;

    static inline QDirectFBScreen* instance() {
        Q_ASSERT(QScreen::instance()->classId() == QScreen::DirectFBClass);
        return static_cast<QDirectFBScreen*>(QScreen::instance());
    }

    IDirectFB* dfb();
    IDirectFBSurface* dfbSurface();
#ifndef QT_NO_DIRECTFB_LAYER
    IDirectFBDisplayLayer* dfbDisplayLayer();
#endif

    // Track surface creation/release so we can release all on exit
    IDirectFBSurface* createDFBSurface(const DFBSurfaceDescription* desc);
    void releaseDFBSurface(IDirectFBSurface* surface);

    static int depth(DFBSurfacePixelFormat format);

    static DFBSurfacePixelFormat getSurfacePixelFormat(const QImage &image);
    static DFBSurfaceDescription getSurfaceDescription(const QImage &image);
    static DFBSurfaceDescription getSurfaceDescription(const uint *buffer,
                                                       int length);
    static QImage::Format getImageFormat(DFBSurfacePixelFormat  format);

#ifndef QT_NO_DIRECTFB_PALETTE
    static void setSurfaceColorTable(IDirectFBSurface *surface,
                                     const QImage &image);
#endif

private:
    void compose(const QRegion &r);
    void blit(IDirectFBSurface *src, const QPoint &topLeft,
              const QRegion &region);

    QDirectFBScreenPrivate *d_ptr;
};

QT_END_HEADER

#endif // QDIRECTFBSCREEN_H
