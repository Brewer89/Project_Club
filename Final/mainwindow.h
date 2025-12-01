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
};
#endif // MAINWINDOW_H
