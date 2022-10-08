//
// Created by Ismail Magdy on 08/10/2022.
//

#ifndef MAIN_CPP_BALANCEINQUIRY_H
#define MAIN_CPP_BALANCEINQUIRY_H
#include "Account.h"
#include "Screen.h"
#include "Transaction.h"

class BalanceInquiry :public Transaction{
public:
    BalanceInquiry(Account* account,Screen* screen);
    virtual void performTransactions() override;
private:
};


#endif //MAIN_CPP_BALANCEINQUIRY_H
