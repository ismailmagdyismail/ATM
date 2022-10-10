

#ifndef MAIN_CPP_WITHDRAWAL_H
#define MAIN_CPP_WITHDRAWAL_H

#include "Transaction.h"
#include "CashDispenser.h"
#include "Keypad.h"
#include "DataBase.h"
class Withdrawal :public Transaction{
public:

    Withdrawal(Account* account,Screen* screen,Keypad* keypad,CashDispenser* cashDispenser,DataBase* dataBase);
    virtual ~Withdrawal()=default;
    virtual void performTransactions() override;

private:
    double amount;// amount of money to be withdrawn
    CashDispenser* dispenser;// interact with ATM's cash dispenser
    Keypad* keypad;// interact with ATM's keypad
    DataBase* dataBase;
    int displayMenu()const;// display list of available transactions
    bool validInput(int input)const;// check if input is valid
};


#endif //MAIN_CPP_WITHDRAWAL_H
