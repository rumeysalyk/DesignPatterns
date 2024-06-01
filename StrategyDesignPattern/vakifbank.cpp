#include "vakifbank.h"

VakifBank::VakifBank(QObject *parent)
    : QObject{parent}
{
    InterestRate = 0.5;
}

float VakifBank::CalculateInterest(float a_capital)
{
    float interest = a_capital*InterestRate;
    return interest;
}
