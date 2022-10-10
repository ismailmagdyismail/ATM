
#ifndef MAIN_CPP_ATM_H
#define MAIN_CPP_ATM_H
#include "Screen.h"
#include "CashDispenser.h"
#include "Keypad.h"
#include "DataBase.h"
#include "DepositSlot.h"
#include "Withdrawal.h"
#include "BalanceInquiry.h"
#include "Deposit.h"
#include "DataBase.h"

class ATM {
public:
        ATM();
        void run();
private:
    Screen screen;
    CashDispenser dispenser;
    Keypad keypad;
    DepositSlot depositSlot;
    DataBase dataBase;
    bool userAuthenticated ;// state of user authentication
    Account account; // current account which will get transactions executed upon it
    void authenticateUser();
    int displayMenu()const;
};


#endif //MAIN_CPP_ATM_H
