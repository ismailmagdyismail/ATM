


#include "ATM.h"

ATM::ATM():dispenser(500*20), account(0,0,0){
    userAuthenticated = false;

}

void ATM::run() {
    while (true)
    {
        screen.display("Welcome.....\n");
        authenticateUser();
        while (true)
        {
            int menuOption=displayMenu();
            if(menuOption == 4)
            {
                userAuthenticated = false;
                account = Account(0,0,0);
                break;
            }
            Transaction* transaction;
            if(menuOption==1)
            {
                transaction = new Withdrawal(&account,&screen,&keypad,&dispenser,&dataBase);
            }
            else if(menuOption==2)
            {
                transaction = new Deposit(&account,&screen,&keypad,&depositSlot,&dataBase);
            }
            else
            {
                transaction = new BalanceInquiry(&account,&screen);
            }
            transaction->performTransactions();
            delete transaction;
        }
    }

}

void ATM::authenticateUser(){
    while (!userAuthenticated){
        screen.display("Enter your account number : ");
        int accountNumber = keypad.getInput();
        screen.display("Enter your PIN  : ");
        int PIN = keypad.getInput();

        std::pair<bool,Account>searchResult=dataBase.authenticateAccount(accountNumber,PIN);
        userAuthenticated = searchResult.first;
        account = searchResult.second;
        if(!userAuthenticated)
        {
            screen.display("Credentials not found...\n");
        }
    }
}

int ATM::displayMenu() const {
    std::string menu[]={"Withdraw","Deposit","ViewBalance","EXIT"};
    int input ;
    bool valid = false;
    while (!valid)
    {
        for (int i = 0; i <4; ++i) {
            std::string option;
            option+= i+1+'0';
            option+='-';
            option+= menu[i];
            screen.display(option+'\n');
        }
        input = keypad.getInput();
        if(input>0&&input<5)
        {
            valid = true;
        }
    }
    return input;
}

