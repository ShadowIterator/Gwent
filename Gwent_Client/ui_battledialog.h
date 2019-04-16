/********************************************************************************
** Form generated from reading UI file 'battledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEDIALOG_H
#define UI_BATTLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BattleDialog
{
public:

    void setupUi(QDialog *BattleDialog)
    {
        if (BattleDialog->objectName().isEmpty())
            BattleDialog->setObjectName(QStringLiteral("BattleDialog"));
        BattleDialog->resize(1073, 957);

        retranslateUi(BattleDialog);

        QMetaObject::connectSlotsByName(BattleDialog);
    } // setupUi

    void retranslateUi(QDialog *BattleDialog)
    {
        BattleDialog->setWindowTitle(QApplication::translate("BattleDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BattleDialog: public Ui_BattleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEDIALOG_H
