#ifndef VAKIFBANK_H
#define VAKIFBANK_H

#include <QObject>
#include "ibank.h"
#include <QDebug>

class VakifBank : public QObject, public IBank
{
    Q_OBJECT
public:
    explicit VakifBank(QObject *parent = nullptr);
    float CalculateInterest(float a_capital) override;
signals:

};

#endif // VAKIFBANK_H
