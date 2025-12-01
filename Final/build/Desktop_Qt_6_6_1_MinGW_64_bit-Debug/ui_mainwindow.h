/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *charView;
    QPushButton *elfSelect;
    QPushButton *humanSelect;
    QPushButton *orcSelect;
    QFrame *line;
    QLabel *nameLabel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *knightButton;
    QPushButton *wizardButton;
    QPushButton *rogueButton;
    QPushButton *createButton;
    QLineEdit *nameInput;
    QLabel *label_10;
    QLabel *statsLeft;
    QSpinBox *armorBox;
    QSpinBox *healthBox;
    QSpinBox *staminaBox;
    QSpinBox *magicBox;
    QSpinBox *strengthBox;
    QLabel *classTrait;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        charView = new QGraphicsView(centralwidget);
        charView->setObjectName("charView");
        charView->setGeometry(QRect(90, 140, 211, 271));
        elfSelect = new QPushButton(centralwidget);
        elfSelect->setObjectName("elfSelect");
        elfSelect->setGeometry(QRect(40, 460, 80, 24));
        humanSelect = new QPushButton(centralwidget);
        humanSelect->setObjectName("humanSelect");
        humanSelect->setGeometry(QRect(150, 460, 80, 24));
        orcSelect = new QPushButton(centralwidget);
        orcSelect->setObjectName("orcSelect");
        orcSelect->setGeometry(QRect(270, 460, 80, 24));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(500, 160, 291, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(140, 30, 111, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 420, 211, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(540, 200, 211, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 250, 49, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(480, 300, 49, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(470, 350, 49, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(480, 400, 49, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(470, 450, 49, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(570, 40, 151, 31));
        knightButton = new QPushButton(centralwidget);
        knightButton->setObjectName("knightButton");
        knightButton->setGeometry(QRect(510, 100, 80, 24));
        wizardButton = new QPushButton(centralwidget);
        wizardButton->setObjectName("wizardButton");
        wizardButton->setGeometry(QRect(610, 100, 80, 24));
        rogueButton = new QPushButton(centralwidget);
        rogueButton->setObjectName("rogueButton");
        rogueButton->setGeometry(QRect(700, 100, 80, 24));
        createButton = new QPushButton(centralwidget);
        createButton->setObjectName("createButton");
        createButton->setGeometry(QRect(560, 490, 141, 51));
        nameInput = new QLineEdit(centralwidget);
        nameInput->setObjectName("nameInput");
        nameInput->setGeometry(QRect(140, 70, 113, 24));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(600, 330, 111, 41));
        statsLeft = new QLabel(centralwidget);
        statsLeft->setObjectName("statsLeft");
        statsLeft->setGeometry(QRect(720, 330, 51, 41));
        armorBox = new QSpinBox(centralwidget);
        armorBox->setObjectName("armorBox");
        armorBox->setGeometry(QRect(520, 240, 71, 31));
        healthBox = new QSpinBox(centralwidget);
        healthBox->setObjectName("healthBox");
        healthBox->setGeometry(QRect(520, 290, 71, 31));
        staminaBox = new QSpinBox(centralwidget);
        staminaBox->setObjectName("staminaBox");
        staminaBox->setGeometry(QRect(520, 340, 71, 31));
        magicBox = new QSpinBox(centralwidget);
        magicBox->setObjectName("magicBox");
        magicBox->setGeometry(QRect(520, 390, 71, 31));
        strengthBox = new QSpinBox(centralwidget);
        strengthBox->setObjectName("strengthBox");
        strengthBox->setGeometry(QRect(520, 440, 71, 31));
        classTrait = new QLabel(centralwidget);
        classTrait->setObjectName("classTrait");
        classTrait->setGeometry(QRect(498, 130, 291, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(nameInput, SIGNAL(textChanged(QString)), MainWindow, SLOT(nameInput()));
        QObject::connect(elfSelect, SIGNAL(clicked()), MainWindow, SLOT(raceSelect()));
        QObject::connect(humanSelect, SIGNAL(clicked()), MainWindow, SLOT(raceSelect()));
        QObject::connect(orcSelect, SIGNAL(clicked()), MainWindow, SLOT(raceSelect()));
        QObject::connect(knightButton, SIGNAL(clicked()), MainWindow, SLOT(classSelect()));
        QObject::connect(wizardButton, SIGNAL(clicked()), MainWindow, SLOT(classSelect()));
        QObject::connect(rogueButton, SIGNAL(clicked()), MainWindow, SLOT(classSelect()));
        QObject::connect(armorBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderChanged()));
        QObject::connect(healthBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderChanged()));
        QObject::connect(staminaBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderChanged()));
        QObject::connect(magicBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderChanged()));
        QObject::connect(strengthBox, SIGNAL(valueChanged(int)), MainWindow, SLOT(sliderChanged()));
        QObject::connect(createButton, SIGNAL(clicked()), MainWindow, SLOT(createChar()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        elfSelect->setText(QCoreApplication::translate("MainWindow", "Elf", nullptr));
        humanSelect->setText(QCoreApplication::translate("MainWindow", "Human", nullptr));
        orcSelect->setText(QCoreApplication::translate("MainWindow", "Orc", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Name</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Race</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Stats</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Armor", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Health</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Stamina</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Magic</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Strength</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">Class</span></p></body></html>", nullptr));
        knightButton->setText(QCoreApplication::translate("MainWindow", "Knight", nullptr));
        wizardButton->setText(QCoreApplication::translate("MainWindow", "Wizard", nullptr));
        rogueButton->setText(QCoreApplication::translate("MainWindow", "Rogue", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Points Left:</span></p></body></html>", nullptr));
        statsLeft->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">15</span></p></body></html>", nullptr));
        classTrait->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
