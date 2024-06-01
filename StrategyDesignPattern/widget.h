#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <customitemdelegate.h>
#include <QLabel>
#include <QDebug>
#include <QLineEdit>
#include "ibank.h"
#include "ziraatbank.h"
#include "vakifbank.h"
#include <QIntValidator>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QComboBox* BankSelection;
    QPushButton* SelectButton;
    QPushButton* CalculateButton;
    QLineEdit *CapitalLine;
    QLabel *InterestLabel;
    CustomItemDelegate* itemDelegate;
    IBank* BankConfiguration;
    void ShowSelectedBank();
    void SetBankConfiguration( int a_index );
    int GetCapital();
public slots:
    void Calculate();
    void EnableCalculateButton();
};
#endif // WIDGET_H
