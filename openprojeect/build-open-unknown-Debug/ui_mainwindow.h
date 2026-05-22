/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Loadimage;
    QPushButton *btn_Grey;
    QPushButton *btn_Meanimage;
    QPushButton *btn_canny;
    QGroupBox *groupBox;
    QLabel *lbi_show1;
    QGroupBox *groupBox_2;
    QLabel *lbi_show2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1203, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalGroupBox = new QGroupBox(centralwidget);
        horizontalGroupBox->setObjectName(QString::fromUtf8("horizontalGroupBox"));
        horizontalGroupBox->setGeometry(QRect(20, 0, 1061, 111));
        horizontalLayout = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_Loadimage = new QPushButton(horizontalGroupBox);
        btn_Loadimage->setObjectName(QString::fromUtf8("btn_Loadimage"));

        horizontalLayout->addWidget(btn_Loadimage);

        btn_Grey = new QPushButton(horizontalGroupBox);
        btn_Grey->setObjectName(QString::fromUtf8("btn_Grey"));

        horizontalLayout->addWidget(btn_Grey);

        btn_Meanimage = new QPushButton(horizontalGroupBox);
        btn_Meanimage->setObjectName(QString::fromUtf8("btn_Meanimage"));

        horizontalLayout->addWidget(btn_Meanimage);

        btn_canny = new QPushButton(horizontalGroupBox);
        btn_canny->setObjectName(QString::fromUtf8("btn_canny"));

        horizontalLayout->addWidget(btn_canny);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 110, 531, 411));
        lbi_show1 = new QLabel(groupBox);
        lbi_show1->setObjectName(QString::fromUtf8("lbi_show1"));
        lbi_show1->setGeometry(QRect(0, 20, 531, 391));
        lbi_show1->setFrameShape(QFrame::Panel);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(550, 110, 531, 411));
        lbi_show2 = new QLabel(groupBox_2);
        lbi_show2->setObjectName(QString::fromUtf8("lbi_show2"));
        lbi_show2->setGeometry(QRect(-30, 20, 561, 391));
        lbi_show2->setFrameShape(QFrame::Panel);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        horizontalGroupBox->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206\345\212\237\350\203\275\345\214\272\345\237\237", nullptr));
        btn_Loadimage->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\345\233\276\345\203\217", nullptr));
        btn_Grey->setText(QApplication::translate("MainWindow", "\347\201\260\345\272\246\345\214\226", nullptr));
        btn_Meanimage->setText(QApplication::translate("MainWindow", "\345\235\207\345\200\274\346\273\244\346\263\242", nullptr));
        btn_canny->setText(QApplication::translate("MainWindow", "\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\216\237\345\233\276", nullptr));
        lbi_show1->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\244\204\347\220\206\345\220\216\345\233\276\345\203\217", nullptr));
        lbi_show2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
