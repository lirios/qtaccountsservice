/****************************************************************************
 * This file is part of Qt AccountsService Addon.
 *
 * Copyright (C) 2012-2013 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * Author(s):
 *    Pier Luigi Fiorini
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#ifndef ACCOUNTSSERVICE_GLOBAL_H
#define ACCOUNTSSERVICE_GLOBAL_H

#include <qglobal.h>

#if defined(QT_ACCOUNTSSERVICE_LIB)
#  define Q_ACCOUNTSSERVICE_EXPORT Q_DECL_EXPORT
#else
#  define Q_ACCOUNTSSERVICE_EXPORT Q_DECL_IMPORT
#endif

#if defined(QT_NAMESPACE)
#  define QT_BEGIN_NAMESPACE_ACCOUNTSSERVICE namespace QT_NAMESPACE { namespace QtAddOn { namespace AccountsService {
#  define QT_END_NAMESPACE_ACCOUNTSSERVICE } } }
#  define QT_USE_NAMESPACE_ACCOUNTSSERVICE using namespace QT_NAMESPACE::QtAddOn::AccountsService;
#  define QT_PREPEND_NAMESPACE_ACCOUNTSSERVICE(name) ::QT_NAMESPACE::QtAddOn::AccountsService::name
#else
#  define QT_BEGIN_NAMESPACE_ACCOUNTSSERVICE namespace QtAddOn { namespace AccountsService {
#  define QT_END_NAMESPACE_ACCOUNTSSERVICE } }
#  define QT_USE_NAMESPACE_ACCOUNTSSERVICE using namespace QtAddOn::AccountsService;
#  define QT_PREPEND_NAMESPACE_ACCOUNTSSERVICE(name) ::QtAddOn::AccountsService::name
#endif

// A workaround for moc - if there is a header file that doesn't use the namespace,
// we still force moc to do "using namespace" but the namespace have to
// be defined, so let's define an empty namespace here
QT_BEGIN_NAMESPACE_ACCOUNTSSERVICE
QT_END_NAMESPACE_ACCOUNTSSERVICE

#endif // ACCOUNTSSERVICE_GLOBAL_H
