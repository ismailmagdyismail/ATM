
#include "CashDispenser.h"

CashDispenser::CashDispenser(const double &availableMoney) {
    if(availableMoney>=0)
        this->availableMoney = availableMoney;
}


void CashDispenser::dispenseMoney(const double &amount) {
    if(isSufficient(amount))
        availableMoney-=amount;
}

bool CashDispenser::isSufficient(const double &amount) {
    return amount<=availableMoney;
}

