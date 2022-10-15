
#include "Withdrawal.h"
using namespace std;

Withdrawal::Withdrawal(Account *account,Screen* screen,Keypad* keypad,CashDispenser* cashDispenser,DataBase* dataBase)
: Transaction(account,screen){
    amount = 0;
    this->keypad = keypad;
    this->dispenser = cashDispenser;
    this->dataBase = dataBase;
}


void Withdrawal::performTransactions() {
    Account* account  = getAccount();
    Screen* screen = getScreen();

    bool performedTransaction = false;
    bool cancelled = false;

    while (!performedTransaction && !cancelled){

        // displaying withdrawal options
        int input = displayMenu();

        if(input == 0 ) // cancelling transaction
        {
            screen->display("Cancelling Transaction.....\n");
            cancelled = true;
        }
        else
        {
            amount = input;
            if(account->isSufficient(amount))// check if account hass sufficcient balance
            {
                if(dispenser->isSufficient(amount))// check if there is enough money in dispenser
                {
                    account->withdraw(amount); // withdrawing money from account
                    dispenser->dispenseMoney(amount);// dispense money;
                    dataBase->updateAccount(*account);

                    screen->display("Withdraw your money from CashDispenser.....\n");
                    performedTransaction = true;
                }
                else
                {
                    screen->display("Cannot dispense that amount of money, please choose lower amount\n");
                }
            }
            else
            {
                screen->display("Current Balance is not sufficient for this transaction,please choose lower amount\n");
            }
        }
    }
}


// display list of available transactions
int Withdrawal::displayMenu() const {

    int menu[]={20,40,60,100,200,0}; // list of  available withdrawal options

    Screen* screen = getScreen();
    bool valid = false;
    int input;

    while (!valid)
    {
        for (int i = 0; i <5; ++i) {
            string option;
            option+=i+1+'0';
            option+="-";
            option+= to_string(menu[i]);
            option+='$';
            screen->display(option+'\n');
        }
        screen->display("6-Cancel Transaction\n");
        screen->display("Choose option : ");
        input = keypad->getInput();
        if(validInput(input))
        {
            valid = true;
        }
    }
    return menu[input-1];

}

// check if input belongs to the menu options
bool Withdrawal::validInput(int input) const {
    if(input<1||input>6)
        return false;
    return true;
}

