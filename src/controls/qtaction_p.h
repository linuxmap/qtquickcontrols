/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Quick Controls module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QTACTION_H
#define QTACTION_H

#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtGui/qkeysequence.h>

QT_BEGIN_NAMESPACE

class QtExclusiveGroup;

class QtAction : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QUrl iconSource READ iconSource WRITE setIconSource NOTIFY iconSourceChanged)
    Q_PROPERTY(QString iconName READ iconName WRITE setIconName NOTIFY iconNameChanged)
    Q_PROPERTY(QVariant __icon READ iconVariant NOTIFY iconChanged)
    Q_PROPERTY(QString toolTip READ tooltip WRITE setToolTip NOTIFY toolTipChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool checkable READ isCheckable WRITE setCheckable NOTIFY checkableChanged)
    Q_PROPERTY(bool checked READ isChecked WRITE setChecked DESIGNABLE isCheckable NOTIFY toggled)

    Q_PROPERTY(QtExclusiveGroup *exclusiveGroup READ exclusiveGroup WRITE setExclusiveGroup NOTIFY exclusiveGroupChanged)
#ifndef QT_NO_SHORTCUT
    Q_PROPERTY(QString shortcut READ shortcut WRITE setShortcut NOTIFY shortcutChanged)
    Q_PROPERTY(QString mnemonic READ mnemonic WRITE setMnemonic NOTIFY mnemonicChanged)
#endif

public:
    explicit QtAction(QObject *parent = 0);
    ~QtAction();

    QString text() const { return m_text; }
    void setText(const QString &text);

    QString shortcut() const;
    void setShortcut(const QString &shortcut);

    QString mnemonic() const;
    void setMnemonic(const QString &mnemonic);

    QString iconName() const;
    void setIconName(const QString &iconName);

    QUrl iconSource() const { return m_iconSource; }
    void setIconSource(const QUrl &iconSource);

    QString tooltip() const { return m_toolTip; }
    void setToolTip(const QString &toolTip);

    bool isEnabled() const { return m_enabled; }
    void setEnabled(bool e);

    bool isCheckable() const { return m_checkable; }
    void setCheckable(bool c);

    bool isChecked() const { return m_checked; }
    void setChecked(bool c);

    QtExclusiveGroup *exclusiveGroup() const { return m_exclusiveGroup; }
    void setExclusiveGroup(QtExclusiveGroup * arg);

    QIcon icon() const { return m_icon; }
    QVariant iconVariant() const { return QVariant(m_icon); }
    void setIcon(QIcon icon) { m_icon = icon; emit iconChanged(); }

    bool event(QEvent *e);

public Q_SLOTS:
    void trigger();

Q_SIGNALS:
    void triggered();
    void toggled(bool);

    void textChanged();
    void shortcutChanged(QString shortcut);
    void mnemonicChanged(QString mnemonic);

    void iconChanged();
    void iconNameChanged();
    void iconSourceChanged();
    void toolTipChanged(QString arg);
    void enabledChanged();
    void checkableChanged();

    void exclusiveGroupChanged();

private:
    QString m_text;
    QUrl m_iconSource;
    QIcon m_icon;
    bool m_enabled;
    bool m_checkable;
    bool m_checked;
    QtExclusiveGroup *m_exclusiveGroup;
    QKeySequence m_shortcut;
    QKeySequence m_mnemonic;
    QString m_toolTip;
};

QT_END_NAMESPACE

#endif // QTACTION_H