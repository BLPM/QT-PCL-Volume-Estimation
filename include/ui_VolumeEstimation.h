/********************************************************************************
** Form generated from reading UI file 'VolumeEstimationqJrodg.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef VOLUMEESTIMATIONQJRODG_H
#define VOLUMEESTIMATIONQJRODG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VolumeEstimation
{
public:
    QAction *actionInput_File;
    QWidget *centralwidget;
    QVTKWidget *qvtkWidget;
    QSplitter *splitter;
    QLabel *PointCloudInf_text;
    QTextEdit *cloudInf_textedit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *point1_label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *point1_x_label;
    QLabel *point1_y_label;
    QLabel *point1_z_label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *point1_x_lineEdit;
    QLineEdit *point1_y_lineEdit;
    QLineEdit *point1_z_lineEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *point2_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *point2_x_label_2;
    QLabel *point2_y_label;
    QLabel *point2_z_label;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *point2_x_lineEdit;
    QLineEdit *point2_y_lineEdit;
    QLineEdit *point2_z_lineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *LoadPC_button;
    QPushButton *filter_button;
    QPushButton *VolumeEstimate_button;

    void setupUi(QMainWindow *VolumeEstimation)
    {
        if (VolumeEstimation->objectName().isEmpty())
            VolumeEstimation->setObjectName(QString::fromUtf8("VolumeEstimation"));
        VolumeEstimation->setWindowModality(Qt::NonModal);
        VolumeEstimation->setEnabled(true);
        VolumeEstimation->resize(1258, 720);
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
        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(435, 21, 806, 661));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(11, 23, 417, 661));
        splitter->setOrientation(Qt::Vertical);
        PointCloudInf_text = new QLabel(splitter);
        PointCloudInf_text->setObjectName(QString::fromUtf8("PointCloudInf_text"));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        PointCloudInf_text->setFont(font);
        splitter->addWidget(PointCloudInf_text);
        cloudInf_textedit = new QTextEdit(splitter);
        cloudInf_textedit->setObjectName(QString::fromUtf8("cloudInf_textedit"));
        cloudInf_textedit->setEnabled(true);
        splitter->addWidget(cloudInf_textedit);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        point1_label = new QLabel(widget);
        point1_label->setObjectName(QString::fromUtf8("point1_label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        point1_label->setFont(font1);

        verticalLayout->addWidget(point1_label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        point1_x_label = new QLabel(widget);
        point1_x_label->setObjectName(QString::fromUtf8("point1_x_label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yu Gothic UI Semibold"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        point1_x_label->setFont(font2);

        horizontalLayout_3->addWidget(point1_x_label);

        point1_y_label = new QLabel(widget);
        point1_y_label->setObjectName(QString::fromUtf8("point1_y_label"));
        point1_y_label->setFont(font2);

        horizontalLayout_3->addWidget(point1_y_label);

        point1_z_label = new QLabel(widget);
        point1_z_label->setObjectName(QString::fromUtf8("point1_z_label"));
        point1_z_label->setFont(font2);

        horizontalLayout_3->addWidget(point1_z_label);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        point1_x_lineEdit = new QLineEdit(widget);
        point1_x_lineEdit->setObjectName(QString::fromUtf8("point1_x_lineEdit"));

        horizontalLayout->addWidget(point1_x_lineEdit);

        point1_y_lineEdit = new QLineEdit(widget);
        point1_y_lineEdit->setObjectName(QString::fromUtf8("point1_y_lineEdit"));

        horizontalLayout->addWidget(point1_y_lineEdit);

        point1_z_lineEdit = new QLineEdit(widget);
        point1_z_lineEdit->setObjectName(QString::fromUtf8("point1_z_lineEdit"));

        horizontalLayout->addWidget(point1_z_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(widget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        point2_label = new QLabel(layoutWidget);
        point2_label->setObjectName(QString::fromUtf8("point2_label"));
        point2_label->setFont(font1);

        verticalLayout_4->addWidget(point2_label);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        point2_x_label_2 = new QLabel(layoutWidget);
        point2_x_label_2->setObjectName(QString::fromUtf8("point2_x_label_2"));
        point2_x_label_2->setFont(font2);

        horizontalLayout_4->addWidget(point2_x_label_2);

        point2_y_label = new QLabel(layoutWidget);
        point2_y_label->setObjectName(QString::fromUtf8("point2_y_label"));
        point2_y_label->setFont(font2);

        horizontalLayout_4->addWidget(point2_y_label);

        point2_z_label = new QLabel(layoutWidget);
        point2_z_label->setObjectName(QString::fromUtf8("point2_z_label"));
        point2_z_label->setFont(font2);

        horizontalLayout_4->addWidget(point2_z_label);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        point2_x_lineEdit = new QLineEdit(layoutWidget);
        point2_x_lineEdit->setObjectName(QString::fromUtf8("point2_x_lineEdit"));

        horizontalLayout_5->addWidget(point2_x_lineEdit);

        point2_y_lineEdit = new QLineEdit(layoutWidget);
        point2_y_lineEdit->setObjectName(QString::fromUtf8("point2_y_lineEdit"));

        horizontalLayout_5->addWidget(point2_y_lineEdit);

        point2_z_lineEdit = new QLineEdit(layoutWidget);
        point2_z_lineEdit->setObjectName(QString::fromUtf8("point2_z_lineEdit"));

        horizontalLayout_5->addWidget(point2_z_lineEdit);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout_4);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        LoadPC_button = new QPushButton(layoutWidget1);
        LoadPC_button->setObjectName(QString::fromUtf8("LoadPC_button"));
        sizePolicy.setHeightForWidth(LoadPC_button->sizePolicy().hasHeightForWidth());
        LoadPC_button->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(20);
        LoadPC_button->setFont(font3);

        horizontalLayout_2->addWidget(LoadPC_button);

        filter_button = new QPushButton(layoutWidget1);
        filter_button->setObjectName(QString::fromUtf8("filter_button"));
        sizePolicy.setHeightForWidth(filter_button->sizePolicy().hasHeightForWidth());
        filter_button->setSizePolicy(sizePolicy);
        filter_button->setFont(font3);
        filter_button->setCheckable(false);

        horizontalLayout_2->addWidget(filter_button);

        VolumeEstimate_button = new QPushButton(layoutWidget1);
        VolumeEstimate_button->setObjectName(QString::fromUtf8("VolumeEstimate_button"));
        sizePolicy.setHeightForWidth(VolumeEstimate_button->sizePolicy().hasHeightForWidth());
        VolumeEstimate_button->setSizePolicy(sizePolicy);
        VolumeEstimate_button->setFont(font3);
        VolumeEstimate_button->setCheckable(false);

        horizontalLayout_2->addWidget(VolumeEstimate_button);

        splitter->addWidget(layoutWidget1);
        VolumeEstimation->setCentralWidget(centralwidget);

        retranslateUi(VolumeEstimation);

        filter_button->setDefault(false);
        VolumeEstimate_button->setDefault(false);


        QMetaObject::connectSlotsByName(VolumeEstimation);
    } // setupUi

    void retranslateUi(QMainWindow *VolumeEstimation)
    {
        VolumeEstimation->setWindowTitle(QCoreApplication::translate("VolumeEstimation", "VolumeEstimation", nullptr));
        actionInput_File->setText(QCoreApplication::translate("VolumeEstimation", "Input File", nullptr));
        PointCloudInf_text->setText(QCoreApplication::translate("VolumeEstimation", "\351\273\236\351\233\262\350\263\207\350\250\212", nullptr));
        point1_label->setText(QCoreApplication::translate("VolumeEstimation", "point1", nullptr));
        point1_x_label->setText(QCoreApplication::translate("VolumeEstimation", "x", nullptr));
        point1_y_label->setText(QCoreApplication::translate("VolumeEstimation", "y", nullptr));
        point1_z_label->setText(QCoreApplication::translate("VolumeEstimation", "z", nullptr));
        point2_label->setText(QCoreApplication::translate("VolumeEstimation", "point2", nullptr));
        point2_x_label_2->setText(QCoreApplication::translate("VolumeEstimation", "x", nullptr));
        point2_y_label->setText(QCoreApplication::translate("VolumeEstimation", "y", nullptr));
        point2_z_label->setText(QCoreApplication::translate("VolumeEstimation", "z", nullptr));
        LoadPC_button->setText(QCoreApplication::translate("VolumeEstimation", "\350\274\211\345\205\245\351\273\236\351\233\262", nullptr));
        filter_button->setText(QCoreApplication::translate("VolumeEstimation", "\345\210\207\347\257\204\345\234\215", nullptr));
        VolumeEstimate_button->setText(QCoreApplication::translate("VolumeEstimation", "\350\250\210\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VolumeEstimation: public Ui_VolumeEstimation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // VOLUMEESTIMATIONQJRODG_H
