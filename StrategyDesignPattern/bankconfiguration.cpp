#include "bankconfiguration.h"

BankConfiguration::BankConfiguration(QWidget *parent)
    : QWidget{parent}
{

}

void BankConfiguration::ShowSelectedBank( QString a_selectedItem )
{
    qDebug() << "Deneem";
    SelectedBank->setText("Selected Bank Name : " + a_selectedItem);
    SelectedBank->show();
}
