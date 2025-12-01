#ifndef CHARSHEET_H
#define CHARSHEET_H

#include <QDialog>
#include "character.h"
using namespace std;

namespace Ui {
class charSheet;
}

class charSheet : public QDialog
{
    Q_OBJECT

public:
    explicit charSheet(const character &userChar, QWidget *parent = nullptr);
    ~charSheet();

protected:
    void showEvent(QShowEvent *event) override;

private:
    Ui::charSheet *ui;
    character userChar;
    void init();
    void display();
};

#endif // CHARSHEET_H
