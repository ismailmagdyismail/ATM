

#include "Account.h"

using namespace std;

Account::Account(const int &accountNumber, const int &PIN, const double &balance)
:accountNumber{accountNumber},PIN{PIN},balance{balance}{}


double Account::getBalance() const {
    return this->balance;
}

int Account::getAccountNumber()const{
    return accountNumber;
}

int  Account::getPIN() const {
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







