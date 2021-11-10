/********************************************************************************
** Form generated from reading UI file 'VolumeEstimationTinbvi.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VOLUMEESTIMATIONTINBVI_H
#define VOLUMEESTIMATIONTINBVI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VolumeEstimation
{
public:
    QAction* actionInput_File;
    QWidget* centralwidget;
    QVTKWidget* qvtkWidget;
    QFrame* frame;
    QTextEdit* cloudInf_textedit;
    QLabel* PointCloudInf_text;
    QGroupBox* groupBox;
    QPushButton* reserve_4;
    QPushButton* reserve_2;
    QPushButton* reserve_3;
    QPushButton* reserve;
    QPushButton* filter_button_rmoutlier;
    QPushButton* filter_button_pass;
    QPushButton* VolumeEstimate_button;
    QPushButton* LoadPC_button;
    QGroupBox* groupBox_2;
    QLabel* point1_label;
    QLineEdit* point1_x_lineEdit;
    QLineEdit* point1_z_lineEdit;
    QLabel* point1_y_label;
    QLabel* point1_x_label;
    QLineEdit* point1_y_lineEdit;
    QLabel* point1_z_label;
    QLabel* point2_y_label;
    QLabel* point2_z_label;
    QLineEdit* point2_x_lineEdit;
    QLineEdit* point2_y_lineEdit;
    QLabel* point2_x_label_2;
    QLineEdit* point2_z_lineEdit;
    QLabel* point2_label;

    void setupUi(QMainWindow* VolumeEstimation)
    {
        if (VolumeEstimation->objectName().isEmpty())
            VolumeEstimation->setObjectName(QString::fromUtf8("VolumeEstimation"));
        VolumeEstimation->setWindowModality(Qt::NonModal);
        VolumeEstimation->setEnabled(true);
        VolumeEstimation->resize(1099, 488);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VolumeEstimation->sizePolicy().hasHeightForWidth());
        VolumeEstimation->setSizePolicy(sizePolicy);
        VolumeEstimation->setMinimumSize(QSize(0, 0));
        VolumeEstimation->setMaximumSize(QSize(5000, 5000));
        VolumeEstimation->setMouseTracking(false);
        VolumeEstimation->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        VolumeEstimation->setAnimated(true);
        VolumeEstimation->setDocumentMode(false);
        VolumeEstimation->setUnifiedTitleAndToolBarOnMac(false);
        actionInput_File = new QAction(VolumeEstimation);
        actionInput_File->setObjectName(QString::fromUtf8("actionInput_File"));
        centralwidget = new QWidget(VolumeEstimation);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(361, 10, 720, 451));
        sizePolicy.setHeightForWidth(qvtkWidget->sizePolicy().hasHeightForWidth());
        qvtkWidget->setSizePolicy(sizePolicy);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 346, 149));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        cloudInf_textedit = new QTextEdit(frame);
        cloudInf_textedit->setObjectName(QString::fromUtf8("cloudInf_textedit"));
        cloudInf_textedit->setEnabled(true);
        cloudInf_textedit->setGeometry(QRect(10, 40, 321, 91));
        PointCloudInf_text = new QLabel(frame);
        PointCloudInf_text->setObjectName(QString::fromUtf8("PointCloudInf_text"));
        PointCloudInf_text->setGeometry(QRect(10, 10, 96, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        PointCloudInf_text->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 164, 346, 87));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        reserve_4 = new QPushButton(groupBox);
        reserve_4->setObjectName(QString::fromUtf8("reserve_4"));
        reserve_4->setGeometry(QRect(92, 45, 75, 28));
        sizePolicy.setHeightForWidth(reserve_4->sizePolicy().hasHeightForWidth());
        reserve_4->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font1.setPointSize(12);
        reserve_4->setFont(font1);
        reserve_4->setCheckable(false);
        reserve_2 = new QPushButton(groupBox);
        reserve_2->setObjectName(QString::fromUtf8("reserve_2"));
        reserve_2->setGeometry(QRect(267, 11, 75, 28));
        sizePolicy.setHeightForWidth(reserve_2->sizePolicy().hasHeightForWidth());
        reserve_2->setSizePolicy(sizePolicy);
        reserve_2->setFont(font1);
        reserve_2->setCheckable(false);
        reserve_3 = new QPushButton(groupBox);
        reserve_3->setObjectName(QString::fromUtf8("reserve_3"));
        reserve_3->setGeometry(QRect(11, 45, 75, 28));
        sizePolicy.setHeightForWidth(reserve_3->sizePolicy().hasHeightForWidth());
        reserve_3->setSizePolicy(sizePolicy);
        reserve_3->setFont(font1);
        reserve_3->setCheckable(false);
        reserve = new QPushButton(groupBox);
        reserve->setObjectName(QString::fromUtf8("reserve"));
        reserve->setGeometry(QRect(186, 11, 75, 28));
        sizePolicy.setHeightForWidth(reserve->sizePolicy().hasHeightForWidth());
        reserve->setSizePolicy(sizePolicy);
        reserve->setFont(font1);
        reserve->setCheckable(false);
        filter_button_rmoutlier = new QPushButton(groupBox);
        filter_button_rmoutlier->setObjectName(QString::fromUtf8("filter_button_rmoutlier"));
        filter_button_rmoutlier->setGeometry(QRect(92, 11, 88, 28));
        sizePolicy.setHeightForWidth(filter_button_rmoutlier->sizePolicy().hasHeightForWidth());
        filter_button_rmoutlier->setSizePolicy(sizePolicy);
        filter_button_rmoutlier->setFont(font1);
        filter_button_rmoutlier->setCheckable(false);
        filter_button_pass = new QPushButton(groupBox);
        filter_button_pass->setObjectName(QString::fromUtf8("filter_button_pass"));
        filter_button_pass->setGeometry(QRect(11, 11, 75, 28));
        sizePolicy.setHeightForWidth(filter_button_pass->sizePolicy().hasHeightForWidth());
        filter_button_pass->setSizePolicy(sizePolicy);
        filter_button_pass->setFont(font1);
        filter_button_pass->setCheckable(false);
        VolumeEstimate_button = new QPushButton(groupBox);
        VolumeEstimate_button->setObjectName(QString::fromUtf8("VolumeEstimate_button"));
        VolumeEstimate_button->setGeometry(QRect(267, 45, 75, 28));
        sizePolicy.setHeightForWidth(VolumeEstimate_button->sizePolicy().hasHeightForWidth());
        VolumeEstimate_button->setSizePolicy(sizePolicy);
        VolumeEstimate_button->setFont(font1);
        VolumeEstimate_button->setCheckable(false);
        LoadPC_button = new QPushButton(groupBox);
        LoadPC_button->setObjectName(QString::fromUtf8("LoadPC_button"));
        LoadPC_button->setGeometry(QRect(186, 45, 75, 28));
        sizePolicy.setHeightForWidth(LoadPC_button->sizePolicy().hasHeightForWidth());
        LoadPC_button->setSizePolicy(sizePolicy);
        LoadPC_button->setFont(font1);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 256, 346, 205));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        point1_label = new QLabel(groupBox_2);
        point1_label->setObjectName(QString::fromUtf8("point1_label"));
        point1_label->setGeometry(QRect(12, 12, 59, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        point1_label->setFont(font2);
        point1_x_lineEdit = new QLineEdit(groupBox_2);
        point1_x_lineEdit->setObjectName(QString::fromUtf8("point1_x_lineEdit"));
        point1_x_lineEdit->setGeometry(QRect(12, 73, 112, 20));
        point1_z_lineEdit = new QLineEdit(groupBox_2);
        point1_z_lineEdit->setObjectName(QString::fromUtf8("point1_z_lineEdit"));
        point1_z_lineEdit->setGeometry(QRect(227, 73, 112, 20));
        point1_y_label = new QLabel(groupBox_2);
        point1_y_label->setObjectName(QString::fromUtf8("point1_y_label"));
        point1_y_label->setGeometry(QRect(130, 48, 16, 19));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        point1_y_label->setFont(font3);
        point1_x_label = new QLabel(groupBox_2);
        point1_x_label->setObjectName(QString::fromUtf8("point1_x_label"));
        point1_x_label->setGeometry(QRect(12, 48, 16, 19));
        point1_x_label->setFont(font3);
        point1_y_lineEdit = new QLineEdit(groupBox_2);
        point1_y_lineEdit->setObjectName(QString::fromUtf8("point1_y_lineEdit"));
        point1_y_lineEdit->setGeometry(QRect(130, 73, 91, 20));
        point1_z_label = new QLabel(groupBox_2);
        point1_z_label->setObjectName(QString::fromUtf8("point1_z_label"));
        point1_z_label->setGeometry(QRect(227, 48, 16, 19));
        point1_z_label->setFont(font3);
        point2_y_label = new QLabel(groupBox_2);
        point2_y_label->setObjectName(QString::fromUtf8("point2_y_label"));
        point2_y_label->setGeometry(QRect(123, 137, 16, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        point2_y_label->setFont(font4);
        point2_z_label = new QLabel(groupBox_2);
        point2_z_label->setObjectName(QString::fromUtf8("point2_z_label"));
        point2_z_label->setGeometry(QRect(234, 137, 16, 20));
        point2_z_label->setFont(font4);
        point2_x_lineEdit = new QLineEdit(groupBox_2);
        point2_x_lineEdit->setObjectName(QString::fromUtf8("point2_x_lineEdit"));
        point2_x_lineEdit->setGeometry(QRect(12, 163, 105, 20));
        point2_y_lineEdit = new QLineEdit(groupBox_2);
        point2_y_lineEdit->setObjectName(QString::fromUtf8("point2_y_lineEdit"));
        point2_y_lineEdit->setGeometry(QRect(123, 163, 105, 20));
        point2_x_label_2 = new QLabel(groupBox_2);
        point2_x_label_2->setObjectName(QString::fromUtf8("point2_x_label_2"));
        point2_x_label_2->setGeometry(QRect(12, 137, 16, 20));
        point2_x_label_2->setFont(font4);
        point2_z_lineEdit = new QLineEdit(groupBox_2);
        point2_z_lineEdit->setObjectName(QString::fromUtf8("point2_z_lineEdit"));
        point2_z_lineEdit->setGeometry(QRect(234, 163, 105, 20));
        point2_label = new QLabel(groupBox_2);
        point2_label->setObjectName(QString::fromUtf8("point2_label"));
        point2_label->setGeometry(QRect(12, 101, 63, 30));
        point2_label->setFont(font2);
        VolumeEstimation->setCentralWidget(centralwidget);

        retranslateUi(VolumeEstimation);

        reserve_4->setDefault(false);
        reserve_2->setDefault(false);
        reserve_3->setDefault(false);
        reserve->setDefault(false);
        filter_button_rmoutlier->setDefault(false);
        filter_button_pass->setDefault(false);
        VolumeEstimate_button->setDefault(false);


        QMetaObject::connectSlotsByName(VolumeEstimation);
    } // setupUi

    void retranslateUi(QMainWindow* VolumeEstimation)
    {
        VolumeEstimation->setWindowTitle(QCoreApplication::translate("VolumeEstimation", "VolumeEstimation", nullptr));
        actionInput_File->setText(QCoreApplication::translate("VolumeEstimation", "Input File", nullptr));
        PointCloudInf_text->setText(QCoreApplication::translate("VolumeEstimation", "\351\273\236\351\233\262\350\231\225\347\220\206\346\270\254\350\251\246", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VolumeEstimation", "\346\277\276\346\263\242", nullptr));
        reserve_4->setText(QCoreApplication::translate("VolumeEstimation", "\344\277\235\347\225\2314", nullptr));
        reserve_2->setText(QCoreApplication::translate("VolumeEstimation", "\344\277\235\347\225\2312", nullptr));
        reserve_3->setText(QCoreApplication::translate("VolumeEstimation", "\344\277\235\347\225\2313", nullptr));
        reserve->setText(QCoreApplication::translate("VolumeEstimation", "\344\277\235\347\225\2311", nullptr));
        filter_button_rmoutlier->setText(QCoreApplication::translate("VolumeEstimation", "\347\247\273\351\231\244\351\233\242\347\276\244\351\273\236", nullptr));
        filter_button_pass->setText(QCoreApplication::translate("VolumeEstimation", "\347\233\264\351\200\232\346\277\276\346\263\242", nullptr));
        VolumeEstimate_button->setText(QCoreApplication::translate("VolumeEstimation", "\350\250\210\347\256\227", nullptr));
        LoadPC_button->setText(QCoreApplication::translate("VolumeEstimation", "\350\274\211\345\205\245\346\252\224\346\241\210", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("VolumeEstimation", "\346\273\221\351\274\240\351\201\270\345\256\232\351\273\236", nullptr));
        point1_label->setText(QCoreApplication::translate("VolumeEstimation", "point1", nullptr));
        point1_y_label->setText(QCoreApplication::translate("VolumeEstimation", "y", nullptr));
        point1_x_label->setText(QCoreApplication::translate("VolumeEstimation", "x", nullptr));
        point1_z_label->setText(QCoreApplication::translate("VolumeEstimation", "z", nullptr));
        point2_y_label->setText(QCoreApplication::translate("VolumeEstimation", "y", nullptr));
        point2_z_label->setText(QCoreApplication::translate("VolumeEstimation", "z", nullptr));
        point2_x_label_2->setText(QCoreApplication::translate("VolumeEstimation", "x", nullptr));
        point2_label->setText(QCoreApplication::translate("VolumeEstimation", "point2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeEstimation : public Ui_VolumeEstimation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VOLUMEESTIMATIONTINBVI_H
