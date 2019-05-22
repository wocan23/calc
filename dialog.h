#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "model.h"
#include "QPushButton"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
void inputNum(int num);
void inputSymbols(QString synmol);
void setLastSymbols(QString synmol);

private:
    Ui::Dialog *ui;
    Model model;
    QString tmp;
    QString lastSymbol;
};

#endif // DIALOG_H
