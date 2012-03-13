/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtContacts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef QCONTACTNAME_H
#define QCONTACTNAME_H

#include <QString>

#include <qcontactsglobal.h>
#include <qcontactdetail.h>
#include <qcontactfilter.h>

QTCONTACTS_BEGIN_NAMESPACE

/* Leaf class */
class Q_CONTACTS_EXPORT QContactName : public QContactDetail
{
public:
#ifndef Q_QDOC
    Q_DECLARE_CUSTOM_CONTACT_DETAIL(QContactName)
#else
    static const DetailType Type;
#endif

    enum NameField {
        FieldPrefix = 0,
        FieldFirstName,
        FieldMiddleName,
        FieldLastName,
        FieldSuffix
    };

    QString prefix() const {return value(FieldPrefix).toString();}
    QString firstName() const {return value(FieldFirstName).toString();}
    QString middleName() const {return value(FieldMiddleName).toString();}
    QString lastName() const {return value(FieldLastName).toString();}
    QString suffix() const {return value(FieldSuffix).toString();}

    void setPrefix(const QString& prefix) {setValue(FieldPrefix, prefix);}
    void setFirstName(const QString& firstName) {setValue(FieldFirstName, firstName);}
    void setMiddleName(const QString& middleName) {setValue(FieldMiddleName, middleName);}
    void setLastName(const QString& lastName) {setValue(FieldLastName, lastName);}
    void setSuffix(const QString& suffix) {setValue(FieldSuffix, suffix);}

    // Convenience filter
    static QContactFilter match(const QString& name);
    static QContactFilter match(const QString& firstName, const QString& lastName);
};

QTCONTACTS_END_NAMESPACE

#endif
