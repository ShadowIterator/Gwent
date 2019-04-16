/********************************************************************************
** Form generated from reading UI file 'fieldwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELDWIDGET_H
#define UI_FIELDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FieldWidget
{
public:

	void setupUi(QWidget *FieldWidget)
    {
        if (FieldWidget->objectName().isEmpty())
            FieldWidget->setObjectName(QStringLiteral("FieldWidget"));
        FieldWidget->resize(1200, 709);

        retranslateUi(FieldWidget);

        QMetaObject::connectSlotsByName(FieldWidget);
    } // setupUi

	void retranslateUi(QWidget *FieldWidget)
    {
        FieldWidget->setWindowTitle(QApplication::translate("FieldWidget", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FieldWidget: public Ui_FieldWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELDWIDGET_H
