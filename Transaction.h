
#ifndef MAIN_CPP_TRANSACTION_H
#define MAIN_CPP_TRANSACTION_H
#include "Account.h"
#include "Screen.h"
#include "Keypad.h"

class Transaction {
public:
    Transaction(Account* account,Screen* screen);
    virtual ~Transaction() = default;

    virtual void performTransactions()=0;

    Account* getAccount()const;
    Screen* getScreen()const;

private:
    Account* account;
    Screen* screen;
};


#endif //MAIN_CPP_TRANSACTION_H
