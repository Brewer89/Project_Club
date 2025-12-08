#include "mainwindow.h"
#include "charsheet.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QCheckBox>
#include <QMessageBox>
#include <algorithm>

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

    updatePreviewStats();
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

    updatePreviewStats();
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
//if the user has remaing trait/stat points this will prompt the user to go back and use them or coninue
//then this displays the charsheet window
void MainWindow::createChar()
{
    // Make sure preview stats are current (in case user changed something last second)
    updatePreviewStats();

    // Check for unused stat points and traits
    int unusedStats  = stats; // remaining points from your checkStats logic
    int maxTraits    = 2; // change if you allow more later
    int usedTraits   = static_cast<int>(selectedTraitIds.size());
    int unusedTraits = maxTraits - usedTraits;

    bool hasUnusedStats  = (unusedStats > 0);
    bool hasUnusedTraits = (unusedTraits > 0);

    if (hasUnusedStats || hasUnusedTraits) {
        QString warningText = "You still have:\n";

        if (hasUnusedStats) {
            warningText += QString(" • %1 unspent stat point%2\n")
                               .arg(unusedStats)
                               .arg(unusedStats == 1 ? "" : "s");
        }

        if (hasUnusedTraits) {
            warningText += QString(" • %1 unused trait slot%2\n")
                               .arg(unusedTraits)
                               .arg(unusedTraits == 1 ? "" : "s");
        }

        warningText += "\nDo you want to go back and spend these before creating your character?";

        QMessageBox::StandardButton reply = QMessageBox::question(
            this,
            "Unused Points",
            warningText,
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::Yes
            );

        // Yes -> go back to the creator (do NOT create the character)
        // No -> continue and create anyway
        if (reply == QMessageBox::Yes) {
            return;
        }
    }

    // Actually create the character
    // Use the preview stats (base + traits)
    userChar.setArmor(previewArmor);
    userChar.setHealth(previewHealth);
    userChar.setStamina(previewStamina);
    userChar.setMagic(previewMagic);
    userChar.setStrength(previewStrength);
    userChar.setCharClass(charClass);
    userChar.setRace(race);
    userChar.setName(name);

    // Show sheet and close creator
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

    initTraits();

    connect(ui->toughCheckBox,   &QCheckBox::toggled, this, &MainWindow::traitToggled);
    connect(ui->agileCheckBox,   &QCheckBox::toggled, this, &MainWindow::traitToggled);
    connect(ui->mysticCheckBox,  &QCheckBox::toggled, this, &MainWindow::traitToggled);
    connect(ui->bulwarkCheckBox, &QCheckBox::toggled, this, &MainWindow::traitToggled);

    updatePreviewStats();

}

void MainWindow::traitToggled()
{
    QCheckBox *check = qobject_cast<QCheckBox*>(sender());
    if (!check) return;

    string id;

    if (check == ui->toughCheckBox)      id = "tough";
    else if (check == ui->agileCheckBox) id = "agile";
    else if (check == ui->mysticCheckBox) id = "mystic";
    else if (check == ui->bulwarkCheckBox) id = "bulwark";
    else return;

    if (check->isChecked()) {
        // user is trying to select this trait
        if (selectedTraitIds.size() >= 2) {
            // too many – roll back the check
            check->blockSignals(true);
            check->setChecked(false);
            check->blockSignals(false);

            QMessageBox::information(this, "Trait Limit",
                                     "You can only choose up to 2 traits.");
            return;
        }

        // add it
        selectedTraitIds.push_back(id);
    } else {
        // user unchecked - remove it
        auto it = std::find(selectedTraitIds.begin(), selectedTraitIds.end(), id);
        if (it != selectedTraitIds.end()) {
            selectedTraitIds.erase(it);
        }
    }

    updatePreviewStats();
}


//Initialize traits
void MainWindow::initTraits()
{
    availableTraits.clear();

    availableTraits.push_back({
        "tough", "Tough", "Resilient and hardy (+3 Health)",
        0, 3, 0, 0, 0
    });

    availableTraits.push_back({
        "agile", "Agile", "Quick on their feet (+3 Stamina)",
        0, 0, 3, 0, 0
    });

    availableTraits.push_back({
        "mystic", "Mystic", "Attuned to the arcane (+3 Magic, -1 Strength)",
        0, 0, 0, 3, -1
    });

    availableTraits.push_back({
        "bulwark", "Bulwark", "Heavily protected (+3 Armor)",
        3, 0, 0, 0, 0
    });

    // Optional: set tooltips on checkboxes
    ui->toughCheckBox->setToolTip("Resilient and hardy (+3 Health)");
    ui->agileCheckBox->setToolTip("Quick on their feet (+3 Stamina)");
    ui->mysticCheckBox->setToolTip("Attuned to the arcane (+3 Magic, -1 Strength)");
    ui->bulwarkCheckBox->setToolTip("Heavily protected (+3 Armor)");
}

//Helper function to find a specific trait
const MainWindow::Trait* MainWindow::findTraitById(const string &id) const
{
    for (const auto &t : availableTraits) {
        if (t.id == id) return &t;
    }
    return nullptr;
}


void MainWindow::updatePreviewStats()
{
    // Start from what’s currently in the spin boxes
    previewArmor    = ui->armorBox->value();
    previewHealth   = ui->healthBox->value();
    previewStamina  = ui->staminaBox->value();
    previewMagic    = ui->magicBox->value();
    previewStrength = ui->strengthBox->value();

    // Add trait modifiers on top
    for (const auto &id : selectedTraitIds) {
        const Trait* t = findTraitById(id);
        if (!t) continue;

        previewArmor    += t->armorMod;
        previewHealth   += t->healthMod;
        previewStamina  += t->staminaMod;
        previewMagic    += t->magicMod;
        previewStrength += t->strengthMod;
    }

    // Safety: no negatives
    previewArmor    = std::max(0, previewArmor);
    previewHealth   = std::max(0, previewHealth);
    previewStamina  = std::max(0, previewStamina);
    previewMagic    = std::max(0, previewMagic);
    previewStrength = std::max(0, previewStrength);

    // Update labels so user can see the final numbers
    ui->armorTotalLabel->setText(QString::number(previewArmor));
    ui->healthTotalLabel->setText(QString::number(previewHealth));
    ui->staminaTotalLabel->setText(QString::number(previewStamina));
    ui->magicTotalLabel->setText(QString::number(previewMagic));
    ui->strengthTotalLabel->setText(QString::number(previewStrength));
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
