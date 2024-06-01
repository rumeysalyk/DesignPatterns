#ifndef ZIRAATBANK_H
#define ZIRAATBANK_H

#include <QObject>
#include "ibank.h"
#include <QDebug>

class ZiraatBank : public QObject, public IBank
{
    Q_OBJECT
public:
    explicit ZiraatBank(QObject *parent = nullptr);
    float CalculateInterest(float a_capital) override;
signals:

};

#endif // ZIRAATBANK_H
