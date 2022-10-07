//
// Created by Ismail Magdy on 07/10/2022.
//

#include "CashDispenser.h"

CashDispenser::CashDispenser(const double &availableMoney) {
    if(availableMoney>=0)
        this->availableMoney = availableMoney;
}


bool CashDispenser::dispenseMoney(double &amount) {
    if(amount>availableMoney)
        return false;
    availableMoney-=amount;
    return true;
}

