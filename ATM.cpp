


#include "ATM.h"

ATM::ATM():dispenser(500*20), account(0,0,0){
    userAuthenticated = false;

}

void ATM::run() {
    while (true)
    {
        screen.display("Welcome.....\n");
        authenticateUser();// authenticate user
        while (true)
        {
            int menuOption=displayMenu();// display mainMenu , get user choice
            if(menuOption == 4)
            {
                // log out , return to mainMenu
                userAuthenticated = false;
                account = Account(0,0,0); // dummy account
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
            // execute transaction that the user chose
            transaction->performTransactions();
            delete transaction;
        }
    }

}

void ATM::authenticateUser(){
    while (!userAuthenticated){
        // prompting user for account number , PIN
        screen.display("Enter your account number : ");
        int accountNumber = keypad.getInput();
        screen.display("Enter your PIN  : ");
        int PIN = keypad.getInput();

        // search dataBase for user credentials
        std::pair<bool,Account>searchResult=dataBase.authenticateAccount(accountNumber,PIN);
        userAuthenticated = searchResult.first;
        account = searchResult.second;
        if(!userAuthenticated)
        {
            // prompting user that account was not found
            screen.display("Credentials not found...\n");
        }
    }
}

int ATM::displayMenu() const {
    // menu options
    std::string menu[]={"Withdraw","Deposit","ViewBalance","EXIT"};
    int input ;
    bool valid = false;
    while (!valid) // validating user's input
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
    // return user's choice
    return input;
}

