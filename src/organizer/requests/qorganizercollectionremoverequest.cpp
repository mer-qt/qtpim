/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtOrganizer module of the Qt Toolkit.
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

#include <qorganizercollectionremoverequest.h>
#include <private/qorganizeritemrequests_p.h>

QTORGANIZER_BEGIN_NAMESPACE

/*!
    \class QOrganizerCollectionRemoveRequest
    \brief The QOrganizerCollectionRemoveRequest class allows a client to asynchronously remove
           collections from a backend.
    \inmodule QtOrganizer
    \ingroup organizeritems-requests
 */

/*!
    Constructs a new collection remove request whose parent is the specified \a parent.
*/
QOrganizerCollectionRemoveRequest::QOrganizerCollectionRemoveRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerCollectionRemoveRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QOrganizerCollectionRemoveRequest::~QOrganizerCollectionRemoveRequest()
{
    QOrganizerAbstractRequestPrivate::notifyEngine(this);
}

/*!
    Sets the ID of collection which will be removed by this request to  \a collectionId.
*/
void QOrganizerCollectionRemoveRequest::setCollectionId(const QOrganizerCollectionId &collectionId)
{
    Q_D(QOrganizerCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collectionIds.clear();
    d->m_collectionIds.append(collectionId);
}

/*!
    Sets the list of IDs of collections which will be removed by this request to \a collectionIds.
*/
void QOrganizerCollectionRemoveRequest::setCollectionIds(const QList<QOrganizerCollectionId> &collectionIds)
{
    Q_D(QOrganizerCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_collectionIds = collectionIds;
}

/*!
    Returns the list of IDs of collections which will be removed by this request.
*/
QList<QOrganizerCollectionId> QOrganizerCollectionRemoveRequest::collectionIds() const
{
    Q_D(const QOrganizerCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_collectionIds;
}

/*!
    Returns any errors which occurred during the request.
*/
QMap<int, QOrganizerManager::Error> QOrganizerCollectionRemoveRequest::errorMap() const
{
    Q_D(const QOrganizerCollectionRemoveRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_errors;
}

#include "moc_qorganizercollectionremoverequest.cpp"

QTORGANIZER_END_NAMESPACE
