//
// Created by Ismail Magdy on 08/10/2022.
//

#include "Withdrawal.h"
using namespace std;

Withdrawal::Withdrawal(Account *account,Screen* screen,Keypad* keypad,CashDispenser* cashDispenser)
: Transaction(account,screen){
    amount = 0;
    this->keypad = keypad;
    this->dispenser = cashDispenser;
    Menu[0]=20;
    Menu[1]=40;
    Menu[2]=60;
    Menu[3]=100;
    Menu[4]=200;
}


void Withdrawal::performTransactions() {
    displayMenu();
    Account* account  = getAccount();
    Screen* screen = getScreen();

    bool performedTransaction = false;
    bool cancelled = false;

    while (!performedTransaction && !cancelled){
        int input = keypad->getInput();
        while (!validInput(input))// validate input
        {
             input = keypad->getInput();
        }

        if(input == 6 ) // cancelling transaction
        {
            screen->display("Cancelling Transaction.....");
            cancelled = true;
        }
        else
        {
            amount = Menu[input-1];
            bool transaction  = account->withdraw(amount); // withdrawing money from account
            if(!transaction) // check if successful withdrawal
            {
                screen->display("Current Balance is not sufficient for this transaction,please choose lower amount");
            }
            else
            {
                // check if there is enough money in dispenser
                bool dispensed =  dispenser->dispenseMoney(amount);
                if(dispensed)
                {
                    // dispense money;
                    screen->display("Withdraw your money from CashDispenser");
                    performedTransaction = true;
                }
                else
                {
                    screen->display("Cannot dispense that amount of money, please choose lower amount");
                }
            }
        }
    }
}

void Withdrawal::displayMenu() const {
    Screen* screen = getScreen();
    for (int i = 0; i <5; ++i) {
        string option;
        option+=i+1+'0';
        option+="-";
        option+= to_string(Menu[i]);
        option+='$';
        screen->display(option);
    }
    screen->display("6-Cancel Transaction");
}

bool Withdrawal::validInput(int input) const {
    if(input<1||input>6)
        return false;
    return true;
}

