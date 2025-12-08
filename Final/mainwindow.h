#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "character.h"
#include <QMainWindow>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void sliderChanged();
    void raceSelect(string inRace);
    void classSelect(string inClass);
    void nameInput();
    void createChar();

    void traitToggled();

private:
    Ui::MainWindow *ui;
    void init();
    string name;
    string charClass;
    string race;
    int armor;
    int health;
    int stamina;
    int magic;
    int strength;
    int stats = 15;
    character userChar;
    bool checkStats(int inStats);

    // New trait data
    struct Trait {
        string id;
        string displayName;
        string description;
        int armorMod = 0;
        int healthMod = 0;
        int staminaMod = 0;
        int magicMod = 0;
        int strengthMod = 0;
    };

    // list of all possible traits
    vector<Trait> availableTraits;

    // currently chosen (max 2)
    vector<string> selectedTraitIds;

    void initTraits();
    const Trait* findTraitById(const string &id) const;
    void enforceTraitLimit(QObject *senderCheckBox);

    int previewArmor    = 0;
    int previewHealth   = 0;
    int previewStamina  = 0;
    int previewMagic    = 0;
    int previewStrength = 0;
    void updatePreviewStats();

};
#endif // MAINWINDOW_H
