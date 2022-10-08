//
// Created by Ismail Magdy on 08/10/2022.
//

#include <iostream>
#include "BalanceInquiry.h"

using namespace std;

BalanceInquiry::BalanceInquiry(Account *account, Screen *screen) : Transaction(account, screen) {}


void BalanceInquiry::performTransactions() {
    Screen* screen = getScreen();
    Account* account = getAccount();
    double amount = account->getBalance();
    string inquiry = to_string(amount)+'$';
    screen->display("Current Balance : ");
    screen->display(inquiry);
}
