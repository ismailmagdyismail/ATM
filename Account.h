//
// Created by Ismail Magdy on 04/10/2022.
//

#ifndef MAIN_CPP_ACCOUNT_H
#define MAIN_CPP_ACCOUNT_H
#include <iostream>
class Account {
public:
    Account(const std::string& accountNumber,const std::string& PIN,const double& balance);

    double getBalance()const;
    std::string getAccountNumber()const;
    std::string getPIN()const;

    bool isSufficient(double amount)const;
    void withdraw(const double &amount);
    void deposit(const double &amount);

    Account& operator=(const Account& other);
private:
    std::string accountNumber;
    std::string PIN;
    double balance;
    const int accountSize = 5;
};


#endif //MAIN_CPP_ACCOUNT_H
