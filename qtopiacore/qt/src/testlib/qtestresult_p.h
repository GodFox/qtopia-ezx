/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the QtTest module of the Qt Toolkit.
**
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
** Qt for Windows(R) Licensees
** As a special exception, Nokia, as the sole copyright holder for Qt
** Designer, grants users of the Qt/Eclipse Integration plug-in the
** right for the Qt/Eclipse Integration to link to functionality
** provided by Qt Designer and its related libraries.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
**
****************************************************************************/

#ifndef QTESTRESULT_P_H
#define QTESTRESULT_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtTest/qtest_global.h>

QT_BEGIN_NAMESPACE

class QTestResultPrivate;
class QTestData;

class QTestResult
{
public:
    enum TestLocation { NoWhere = 0, DataFunc = 1, InitFunc = 2, Func = 3, CleanupFunc = 4 };

    static const char *currentTestObjectName();
    static bool currentTestFailed();
    static bool allDataPassed();
    static QTestData *currentTestData();
    static QTestData *currentGlobalTestData();
    static const char *currentTestFunction();
    static TestLocation currentTestLocation();
    static const char *currentDataTag();
    static const char *currentGlobalDataTag();
    static void finishedCurrentTestFunction();
    static void reset();

    static int passCount();
    static int failCount();
    static int skipCount();

    static void ignoreMessage(QtMsgType type, const char *msg);

    static void addFailure(const char *message, const char *file, int line);
    static bool compare(bool success, const char *msg, const char *file, int line);
    static bool compare(bool success, const char *msg, char *val1, char *val2,
                        const char *actual, const char *expected, const char *file, int line);

    static void setCurrentGlobalTestData(QTestData *data);
    static void setCurrentTestData(QTestData *data);
    static void setCurrentTestFunction(const char *func);
    static void setCurrentTestLocation(TestLocation loc);
    static void setCurrentTestObject(const char *name);
    static void addSkip(const char *message, QTest::SkipMode mode,
                        const char *file, int line);
    static bool expectFail(const char *dataIndex, const char *comment,
                           QTest::TestFailMode mode, const char *file, int line);
    static bool verify(bool statement, const char *statementStr, const char *extraInfo,
                       const char *file, int line);
    static bool testFailed();
    static void setSkipCurrentTest(bool value);
    static bool skipCurrentTest();

private:
    Q_DISABLE_COPY(QTestResult)
};

QT_END_NAMESPACE

#endif
