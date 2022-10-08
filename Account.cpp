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

void Account::deposit(const double &amount) {
    balance+=amount;
}

void Account::withdraw(const double &amount) {
    if(isSufficient(amount))
        balance-=amount;
}

Account& Account::operator=(const Account &other) {
    this->balance = other.getBalance();
    this->PIN = other.getPIN();
    this->accountNumber = other.getAccountNumber();
    return *this;
}

bool Account::isSufficient(double amount) const {
    return amount<= this->balance;
}







