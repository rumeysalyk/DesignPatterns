#include "ziraatbank.h"

ZiraatBank::ZiraatBank(QObject *parent)
    : QObject{parent}
{
    InterestRate = 0.45;
}

float ZiraatBank::CalculateInterest(float a_capital)
{
    float interest = a_capital*InterestRate;
    return interest;
}
