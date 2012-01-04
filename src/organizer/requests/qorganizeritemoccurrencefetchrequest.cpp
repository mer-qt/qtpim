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

#include <qorganizeritemoccurrencefetchrequest.h>
#include <private/qorganizeritemrequests_p.h>

QTORGANIZER_BEGIN_NAMESPACE

/*!
    \class QOrganizerItemOccurrenceFetchRequest
    \brief The QOrganizerItemOccurrenceFetchRequest class allows a client to asynchronously fetch
           occurrences generated by a recurring item.
    \inmodule QtOrganizer
    \ingroup organizer-requests

    This request will fetch both generated occurrences and persisted occurrences, which match the
    specified criteria, of the given parent item.
 */

/*!
    Constructs a new organizer item occurrence fetch request whose parent is the specified \a parent.
*/
QOrganizerItemOccurrenceFetchRequest::QOrganizerItemOccurrenceFetchRequest(QObject *parent)
    : QOrganizerAbstractRequest(new QOrganizerItemOccurrenceFetchRequestPrivate, parent)
{
}

/*!
    Frees memory in use by this request.
*/
QOrganizerItemOccurrenceFetchRequest::~QOrganizerItemOccurrenceFetchRequest()
{
    QOrganizerAbstractRequestPrivate::notifyEngine(this);
}

/*!
    Sets the parent item, whose occurrences are to be fetched to \a item.
*/
void QOrganizerItemOccurrenceFetchRequest::setParentItem(const QOrganizerItem &item)
{
    Q_D(QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_generator = item;
}

/*!
    Sets the start period of the request to \a date.

    A default-constructed (invalid) start date time specifies an open start date time (matches anything
    which occurs up until the end date time).
*/
void QOrganizerItemOccurrenceFetchRequest::setStartDate(const QDateTime &date)
{
    Q_D(QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_startDate = date;
}

/*!
    Sets the end period of the request to \a date.

    A default-constructed (invalid) end date time specifies an open end date time (matches anything
    which occurs after the start date time).
*/
void QOrganizerItemOccurrenceFetchRequest::setEndDate(const QDateTime &date)
{
    Q_D(QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_endDate = date;
}

/*!
    Sets the maximum number of occurrences to fetch to \a maxCount.

    Note that backends will decide how many items are fetched if \a maxCount is negative.
 */
void QOrganizerItemOccurrenceFetchRequest::setMaxOccurrences(int maxCount)
{
    Q_D(QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_maxOccurrences = maxCount;
}

/*!
    Sets the fetch hint which may be used by the backend to optimize item retrieval to \a fetchHint.

    A client should not make changes to a item which has been retrieved using a fetch hint other than
    the default fetch hint.  Doing so will result in information loss when saving the item back to
    the manager (as the "new" restricted item will replace the previously saved item in the backend).
 */
void QOrganizerItemOccurrenceFetchRequest::setFetchHint(const QOrganizerItemFetchHint &fetchHint)
{
    Q_D(QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    d->m_fetchHint = fetchHint;
}

/*!
    Returns the parent item, whose occurrences are to be fetched.
*/
QOrganizerItem QOrganizerItemOccurrenceFetchRequest::parentItem() const
{
    Q_D(const QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_generator;
}

/*!
    Returns the date-time which is the lower bound for the range in which occurrences will be returned.
 */
QDateTime QOrganizerItemOccurrenceFetchRequest::startDate() const
{
    Q_D(const QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_startDate;
}

/*!
    Returns the date-time which is the upper bound for the range in which occurrences will be returned.
 */
QDateTime QOrganizerItemOccurrenceFetchRequest::endDate() const
{
    Q_D(const QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_endDate;
}

/*!
    Returns the maximum number of occurrences to return for the request.
 */
int QOrganizerItemOccurrenceFetchRequest::maxOccurrences() const
{
    Q_D(const QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_maxOccurrences;
}

/*!
    Returns the list of organizer item occurrences retrieved by this request.
*/
QList<QOrganizerItem> QOrganizerItemOccurrenceFetchRequest::itemOccurrences() const
{
    Q_D(const QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_organizeritems;
}

/*!
    Returns the fetch hint which may be used by the backend to optimize item retrieval.

    A client should not make changes to a item which has been retrieved using a fetch hint other than
    the default fetch hint.  Doing so will result in information loss when saving the item back to
    the manager (as the "new" restricted item will replace the previously saved item in the backend).
 */
QOrganizerItemFetchHint QOrganizerItemOccurrenceFetchRequest::fetchHint() const
{
    Q_D(const QOrganizerItemOccurrenceFetchRequest);
    QMutexLocker ml(&d->m_mutex);
    return d->m_fetchHint;
}

#include "moc_qorganizeritemoccurrencefetchrequest.cpp"

QTORGANIZER_END_NAMESPACE
