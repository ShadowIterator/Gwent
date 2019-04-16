/********************************************************************************
** Form generated from reading UI file 'cardsetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDSETWIDGET_H
#define UI_CARDSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CardSetWidget
{
public:

	void setupUi(QWidget *CardSetWidget)
    {
        if (CardSetWidget->objectName().isEmpty())
            CardSetWidget->setObjectName(QStringLiteral("CardSetWidget"));
		CardSetWidget->resize(1000, 60);

        retranslateUi(CardSetWidget);

        QMetaObject::connectSlotsByName(CardSetWidget);
    } // setupUi

	void retranslateUi(QWidget *CardSetWidget)
    {
        CardSetWidget->setWindowTitle(QApplication::translate("CardSetWidget", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardSetWidget: public Ui_CardSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDSETWIDGET_H
