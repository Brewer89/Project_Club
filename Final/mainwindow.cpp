#include "mainwindow.h"
#include "charsheet.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
    //these connect the race buttons to the raceSelect function
    connect(ui->elfSelect, &QPushButton::clicked, this, [this](){raceSelect("elf");});
    connect(ui->humanSelect, &QPushButton::clicked, this, [this](){raceSelect("human");});
    connect(ui->orcSelect, &QPushButton::clicked, this, [this](){raceSelect("orc");});
    //these connect the class buttons to the classSelect function
    connect(ui->wizardButton, &QPushButton::clicked, this, [this](){classSelect("wizard");});
    connect(ui->knightButton, &QPushButton::clicked, this, [this](){classSelect("knight");});
    connect(ui->rogueButton, &QPushButton::clicked, this, [this](){classSelect("rogue");});
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
* This is called when any of the button for race selection is pushed
* it displays a picture in the GraphicsView and also adds some stat point into different stats
* depending on which button was pushed. It also assigned the charClass variable
*
* I got some of the code for how to display a picture and the idea of using a resource
* file for the pictures in the project from here.
*
* https://stackoverflow.com/questions/25019076/qt-resource-file-images-not-showing-when-running
*
* as well as googling some of the smaller syntax details.
*/
void MainWindow::raceSelect(string inRace){
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->charView->setScene(scene);
    if(inRace == "elf"){
        race = inRace;
        //displaying pictures
        QPixmap elfPic(":/images/images/elf.png");
        QGraphicsPixmapItem *picItem = scene->addPixmap(elfPic);
        ui->charView->fitInView(picItem, Qt::KeepAspectRatio);
        //modify stats
        stamina = 5;
        ui->staminaBox->setValue(stamina);
        magic = 5;
        ui->magicBox->setValue(magic);
        armor = 0;
        ui->armorBox->setValue(armor);
        health = 0;
        ui->healthBox->setValue(health);
        strength = 0;
        ui->strengthBox->setValue(strength);
    }
    else if(inRace == "human"){
        race = inRace;
        //displaying pictures
        QPixmap humanPic(":/images/images/human.jpg");
        QGraphicsPixmapItem *picItem = scene->addPixmap(humanPic);
        ui->charView->fitInView(picItem, Qt::KeepAspectRatio);
        //modify stats
        health = 5;
        ui->healthBox->setValue(health);
        stamina = 5;
        ui->staminaBox->setValue(stamina);
        armor = 0;
        ui->armorBox->setValue(armor);
        magic = 0;
        ui->magicBox->setValue(magic);
        strength = 0;
        ui->strengthBox->setValue(strength);
    }
    else if(inRace == "orc"){
        race = inRace;
        //displaying pictures
        QPixmap orcPic(":/images/images/orc.png");
        QGraphicsPixmapItem *picItem = scene->addPixmap(orcPic);
        ui->charView->fitInView(picItem, Qt::KeepAspectRatio);
        //displaying pictures
        armor = 5;
        ui->armorBox->setValue(armor);
        strength = 5;
        ui->strengthBox->setValue(strength);
        magic = 0;
        ui->magicBox->setValue(magic);
        health = 0;
        ui->healthBox->setValue(health);
        stamina = 0;
        ui->staminaBox->setValue(stamina);
    }
}
/*
* This function gave me a lot of trouble, setting values within the function was causing recursive
* function calls but I couldn't think of a way stop users from allocating stat points beyond the
* alloted amount. After going down a google hole I saw the solution of combining these three lines
* to stop the recursive calls within the Google AI at the top of the search window
*
*   QSpinBox *spin = qobject_cast<QSpinBox*>(sender());
*   spin->blockSignals(true);
*   spin->blockSignals(false);
*
* QSpinBox *spin line sends the specific object signal to a pointer, it's not used in this
* function but wanted to keep the code in my program true to what I found online.
* then spin->blockSignals(true) stops all outgoing signals till you set it to false
*/
void MainWindow::sliderChanged(){
    QSpinBox *spin = qobject_cast<QSpinBox*>(sender());//taken from google search AI
    //get new values from the spinboxes
    int tempArmor = ui->armorBox->value();
    int tempHealth = ui->healthBox->value();
    int tempStamina = ui->staminaBox->value();
    int tempMagic = ui->magicBox->value();
    int tempStrength = ui->strengthBox->value();
    //get total stats and check if they are more then the amount of stats available with checkStats()
    int allStats = tempArmor + tempHealth + tempStamina + tempMagic + tempStrength;
    //if checkStats() returns false then the stat boxes are returned to previous values
    if(!checkStats(allStats)){
        spin->blockSignals(true);//taken from google search AI
        ui->armorBox->setValue(armor);
        ui->healthBox->setValue(health);
        ui->staminaBox->setValue(stamina);
        ui->magicBox->setValue(magic);
        ui->strengthBox->setValue(strength);
        spin->blockSignals(false);//taken from google search AI
        return;
    }
    /* if checkStats() returns true then stat variables are updated to the new values
     * and the ui is changed to reflect the new values.
     */
    armor = tempArmor;
    health = tempHealth;
    stamina = tempStamina;
    magic = tempMagic;
    strength = tempStrength;

    spin->blockSignals(true);
    ui->armorBox->setValue(armor);
    ui->healthBox->setValue(health);
    ui->staminaBox->setValue(stamina);
    ui->magicBox->setValue(magic);
    ui->strengthBox->setValue(strength);
    spin->blockSignals(false);
    //any Qfont within the program is used to keep the font similar when the text is changed
    QFont font("Ariel", 16);
    ui->statsLeft->setNum(stats);
    ui->statsLeft->setFont(font);
}
//any class button pushes call this function which update the charClass variable and display a trait on the ui
void MainWindow::classSelect(string inClass){
    if(inClass == "wizard"){
        charClass = inClass;
        ui->classTrait->setText("Deals more magic damage");
    }
    if(inClass == "knight"){
        charClass = inClass;
        ui->classTrait->setText("Increased armor durability");
    }
    if(inClass == "rogue"){
        charClass = inClass;
        ui->classTrait->setText("Innate access to invisibilty");
    }
}
//assignes input to name variable and displays it on the window
void MainWindow::nameInput(){
    QFont font("Ariel", 18);
    name = ui->nameInput->text().toStdString();
    ui->nameLabel->setText(ui->nameInput->text());
    ui->nameLabel->setFont(font);
}
//this is called when the user clicks create and assigns all character variables to the character object
//then this displays the charsheet window
void MainWindow::createChar(){
    //sets all variables within the userChar object
    userChar.setArmor(armor);
    userChar.setHealth(health);
    userChar.setStamina(stamina);
    userChar.setMagic(magic);
    userChar.setStrength(strength);
    userChar.setCharClass(charClass);
    userChar.setRace(race);
    userChar.setName(name);
    //creates the new window that displays the final charsheet
    charSheet *newWindow = new charSheet(userChar, nullptr);
    newWindow->show();
    close();
}
//this function is called on window creation to initialize anything needed to be done first
void MainWindow::init(){
    ui->healthBox->setRange(0, 30);
    ui->armorBox->setRange(0, 30);
    ui->staminaBox->setRange(0, 30);
    ui->magicBox->setRange(0, 30);
    ui->strengthBox->setRange(0, 30);

}
//compares inStats to MAXSTATS to see if the current assigned amount goes over maximum allowed
bool MainWindow::checkStats(int inStats){
    const int MAXSTATS = 15;

    if (!race.empty()) {
        inStats -= 10;
    }

    if (inStats > MAXSTATS) {
        return false;
    }

    stats = MAXSTATS - inStats;
    return true;
}
