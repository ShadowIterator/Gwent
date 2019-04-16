/********************************************************************************
** Form generated from reading UI file 'cardwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDWIDGET_H
#define UI_CARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include"global.h"
QT_BEGIN_NAMESPACE

class Ui_CardWidget
{
public:

	void setupUi(QWidget *CardWidget)
    {
        if (CardWidget->objectName().isEmpty())
            CardWidget->setObjectName(QStringLiteral("CardWidget"));
		CardWidget->resize(ROW_HEIGHT*2/3, ROW_HEIGHT);

		retranslateUi(CardWidget);

        QMetaObject::connectSlotsByName(CardWidget);
    } // setupUi

	void retranslateUi(QWidget *CardWidget)
    {
        CardWidget->setWindowTitle(QApplication::translate("CardWidget", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardWidget: public Ui_CardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDWIDGET_H
