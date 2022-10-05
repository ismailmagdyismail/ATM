//
// Created by Ismail Magdy on 04/10/2022.
//

#include "Account.h"

using namespace std;

Account::Account(const std::string &accountNumber, const std::string &PIN, const double &balance)
:accountNumber{accountNumber},PIN{PIN},balance{balance}{}


double Account::getBalance() const {
    return this->balance;
}

std::string Account::getAccountNumber()const{
    return accountNumber;
}

std::string Account::getPIN() const {
    return  PIN;
}

bool Account::operator==(const Account &other) const {
    return (accountNumber==accountNumber&&PIN==PIN);
}

void Account::deposit(double amount) {
    balance+=amount;
}

bool Account::withdraw(double amount) {
    if(amount>balance)
        return false;
    balance-=amount;
    return true;
}







