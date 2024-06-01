#ifndef IBANK_H
#define IBANK_H


class IBank
{
public:
    float InterestRate;
    virtual ~IBank() = default;
    virtual float CalculateInterest( float a_capital ) = 0;
};

#endif // IBANK_H
