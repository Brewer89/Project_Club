/********************************************************************************
** Form generated from reading UI file 'charsheet.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARSHEET_H
#define UI_CHARSHEET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_charSheet
{
public:
    QGraphicsView *graphicsView;
    QLabel *nameLabel;
    QLabel *classLabel;
    QLabel *armorLabel;
    QLabel *healthLabel;
    QLabel *staminaLabel;
    QLabel *magicLabel;
    QLabel *strengthLabel;
    QFrame *line;
    QLabel *label_6;
    QLabel *classTrait;

    void setupUi(QDialog *charSheet)
    {
        if (charSheet->objectName().isEmpty())
            charSheet->setObjectName("charSheet");
        charSheet->resize(595, 420);
        graphicsView = new QGraphicsView(charSheet);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 100, 211, 271));
        nameLabel = new QLabel(charSheet);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(20, 50, 211, 41));
        classLabel = new QLabel(charSheet);
        classLabel->setObjectName("classLabel");
        classLabel->setGeometry(QRect(390, 40, 121, 21));
        armorLabel = new QLabel(charSheet);
        armorLabel->setObjectName("armorLabel");
        armorLabel->setGeometry(QRect(430, 150, 81, 21));
        healthLabel = new QLabel(charSheet);
        healthLabel->setObjectName("healthLabel");
        healthLabel->setGeometry(QRect(430, 200, 81, 21));
        staminaLabel = new QLabel(charSheet);
        staminaLabel->setObjectName("staminaLabel");
        staminaLabel->setGeometry(QRect(430, 250, 81, 21));
        magicLabel = new QLabel(charSheet);
        magicLabel->setObjectName("magicLabel");
        magicLabel->setGeometry(QRect(430, 300, 81, 21));
        strengthLabel = new QLabel(charSheet);
        strengthLabel->setObjectName("strengthLabel");
        strengthLabel->setGeometry(QRect(430, 350, 81, 21));
        line = new QFrame(charSheet);
        line->setObjectName("line");
        line->setGeometry(QRect(360, 100, 191, 20));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        label_6 = new QLabel(charSheet);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(430, 110, 121, 31));
        classTrait = new QLabel(charSheet);
        classTrait->setObjectName("classTrait");
        classTrait->setGeometry(QRect(358, 75, 191, 21));

        retranslateUi(charSheet);

        QMetaObject::connectSlotsByName(charSheet);
    } // setupUi

    void retranslateUi(QDialog *charSheet)
    {
        charSheet->setWindowTitle(QCoreApplication::translate("charSheet", "Dialog", nullptr));
        nameLabel->setText(QCoreApplication::translate("charSheet", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        classLabel->setText(QCoreApplication::translate("charSheet", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        armorLabel->setText(QCoreApplication::translate("charSheet", "TextLabel", nullptr));
        healthLabel->setText(QCoreApplication::translate("charSheet", "TextLabel", nullptr));
        staminaLabel->setText(QCoreApplication::translate("charSheet", "TextLabel", nullptr));
        magicLabel->setText(QCoreApplication::translate("charSheet", "TextLabel", nullptr));
        strengthLabel->setText(QCoreApplication::translate("charSheet", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("charSheet", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Stats</span></p></body></html>", nullptr));
        classTrait->setText(QCoreApplication::translate("charSheet", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class charSheet: public Ui_charSheet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARSHEET_H
