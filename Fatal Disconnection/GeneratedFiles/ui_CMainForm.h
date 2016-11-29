/********************************************************************************
** Form generated from reading UI file 'CMainForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINFORM_H
#define UI_CMAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxOneClickBoardGameDisconnect;

    void setupUi(QMainWindow *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName(QString::fromUtf8("MainForm"));
        MainForm->resize(163, 36);
        MainForm->setStyleSheet(QString::fromUtf8("QMainWindow\n"
"{\n"
"background:white;\n"
"}\n"
"\n"
"QTabWidget::pane\n"
"{\n"
"background:white;\n"
"border:1px solid gray;\n"
"}\n"
"\n"
"QTabWidget#tabwMain::pane\n"
"{\n"
"background:white;\n"
"border:none;\n"
"border-top:1px solid gray;\n"
"border-bottom:1px solid gray;\n"
"}\n"
"\n"
"QGroupBox\n"
"{\n"
"border:1px solid gray;\n"
"margin-top:5px;\n"
"}\n"
"\n"
"QGroupBox::title\n"
"{\n"
"color:blue;\n"
"top:-7px;\n"
"left:5px;\n"
"}\n"
"\n"
"QCheckBox:checked\n"
"{\n"
"color:green;\n"
"}"));
        centralWidget = new QWidget(MainForm);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxOneClickBoardGameDisconnect = new QCheckBox(centralWidget);
        checkBoxOneClickBoardGameDisconnect->setObjectName(QString::fromUtf8("checkBoxOneClickBoardGameDisconnect"));

        gridLayout->addWidget(checkBoxOneClickBoardGameDisconnect, 0, 0, 1, 1);

        MainForm->setCentralWidget(centralWidget);

        retranslateUi(MainForm);
        QObject::connect(checkBoxOneClickBoardGameDisconnect, SIGNAL(toggled(bool)), MainForm, SLOT(CheckBoxToggled(bool)));

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainForm)
    {
        MainForm->setWindowTitle(QApplication::translate("MainForm", "Step Game Fucker", 0, QApplication::UnicodeUTF8));
        checkBoxOneClickBoardGameDisconnect->setText(QApplication::translate("MainForm", "Active", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINFORM_H
