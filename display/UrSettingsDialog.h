// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: 2020-2024 The Monero Project

#ifndef URSETTINGSDIALOG_H
#define URSETTINGSDIALOG_H

#include <QDialog>
#include "ui_UrSettingsDialog.h"

namespace Ui {
    class UrSettingsDialog;
}

class UrSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UrSettingsDialog(QWidget *parent = nullptr, int fragmentLength = 150, int speed = 80, bool fountainCodeEnabled = false);
    ~UrSettingsDialog() override;

    int getFragmentLength() const;
    int getSpeed() const;
    bool getFountainCodeEnabled() const;
    void setDefault(int fragmentLength, int speed, bool fountainCodeEnabled);

signals:
    void settingsChanged(int fragmentLength, int speed, bool fountainCodeEnabled);
    void fragmentLengthChanged(int fragmentLength);
    void speedChanged(int speed);
    void fountainCodeEnabledChanged(bool fountainCodeEnabled);

public slots:
    void updateSettings(int fragmentLength, int speed, bool fountainCodeEnabled);
    void setFragmentLength(int value);
    void setSpeed(int value);
    void setFountainCodeEnabled(bool enabled);

private:
    int defaultFragmentLength = 150;
    int defaultSpeed = 80;
    bool defaultFountainCodeEnabled = false;

    QScopedPointer<Ui::UrSettingsDialog> ui;
    void onUpdate();
};

#endif //URSETTINGSDIALOG_H
