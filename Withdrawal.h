//
// Created by Ismail Magdy on 08/10/2022.
//

#ifndef MAIN_CPP_WITHDRAWAL_H
#define MAIN_CPP_WITHDRAWAL_H

#include "Transaction.h"
#include "CashDispenser.h"
#include "Keypad.h"
#include "DataBase.h"
class Withdrawal :Transaction{
public:

    Withdrawal(Account* account,Screen* screen,Keypad* keypad,CashDispenser* cashDispenser);
    virtual void performTransactions() override;

private:
    int Menu[5];
    double amount;
    CashDispenser* dispenser;
    Keypad* keypad;
    void displayMenu()const;
    bool validInput(int input)const;
};


#endif //MAIN_CPP_WITHDRAWAL_H
