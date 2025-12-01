#include "charsheet.h"
#include "ui_charsheet.h"
#include "character.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <string>
charSheet::charSheet(const character &userChar, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::charSheet)
    , userChar(userChar)
{
    ui->setupUi(this);
    init();
}

charSheet::~charSheet()
{
    delete ui;
}
/*
* I got the (QString::fromStdString( from stack overflow as I was having trouble
* when trying to concat the stat labals text using the to_string conversion.
*
* Code taken from here:
* https://stackoverflow.com/questions/14249488/qt-string-problems
*/
void charSheet::init(){
    //display stats
    ui->armorLabel->setText(QString::fromStdString("Armor " + to_string(userChar.getArmor())));
    ui->healthLabel->setText(QString::fromStdString("Health " + std::to_string(userChar.getHealth())));
    ui->staminaLabel->setText(QString::fromStdString("Stamina " + std::to_string(userChar.getStamina())));
    ui->magicLabel->setText(QString::fromStdString("Magic " + std::to_string(userChar.getMagic())));
    ui->strengthLabel->setText(QString::fromStdString("Strength " + std::to_string(userChar.getStrength())));
    //display name
    ui->nameLabel->setText(QString::fromStdString(userChar.getName()));
    //display class
    if(userChar.getCharClass() == "wizard"){
        ui->classLabel->setText(QString::fromStdString("Wizard"));
        ui->classTrait->setText("Deals more magic damage");
    }
    if(userChar.getCharClass() == "knight"){
        ui->classLabel->setText(QString::fromStdString("Knight"));
        ui->classTrait->setText("Increased armor durability");
    }
    if(userChar.getCharClass() == "rogue"){
        ui->classLabel->setText(QString::fromStdString("Rogue"));
        ui->classTrait->setText("Innate access to invisibilty");
    }
    display();
}
/*
* This displays the character race picture on the new window
* I ran into a bug with this where the picture was displaying tiny within the graphics view, turns out calling
* this before the windown was fully drawn was causing the bug, I tried moving display call to the end of init()
* that didn't fix it so I went back to google. I found the showEvent() override method on stack overflow, this
* method is called by QT after the widget has is final size and is drawn so the picture is able to fit the correct
* aspect ratio.
*
* Code taken from here:
* https://stackoverflow.com/questions/17028680/image-doesnt-fit-graphics-view-frame
*/
void charSheet::display(){
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    //if statements select which pic to display
    if(userChar.getRace() == "elf"){
        //displaying pictures
        QPixmap elfPic(":/images/images/elf.png");
        scene->addPixmap(elfPic);

    }
    else if(userChar.getRace() == "human"){
        //displaying pictures
        QPixmap humanPic(":/images/images/human.jpg");
        scene->addPixmap(humanPic);
    }
    else if(userChar.getRace() == "orc"){
        //displaying pictures
        QPixmap orcPic(":/images/images/orc.png");
        scene->addPixmap(orcPic);
    }
}
void charSheet::showEvent(QShowEvent *event){
    QDialog::showEvent(event);

    ui->graphicsView->fitInView(ui->graphicsView->scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
}
