
#ifndef MAIN_CPP_ACCOUNT_H
#define MAIN_CPP_ACCOUNT_H
#include <iostream>
class Account {
public:
    Account(const int &accountNumber, const int &PIN, const double& balance);

    double getBalance()const;
    int getAccountNumber()const;
    int getPIN()const;

    bool isSufficient(double amount)const;
    void withdraw(const double &amount);
    void deposit(const double &amount);

    Account& operator=(const Account& other);
private:
    int accountNumber;
    int PIN;
    double balance;
    const int accountSize = 5;
};


#endif //MAIN_CPP_ACCOUNT_H
