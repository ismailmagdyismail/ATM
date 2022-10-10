
#ifndef MAIN_CPP_DATABASE_H
#define MAIN_CPP_DATABASE_H
#include <iostream>
#include "Account.h"
#include <vector>


class DataBase {
public:
    DataBase();
    std::pair<bool,Account> authenticateAccount(const int &accountNumber, const int &PIN)const;
    void updateAccount(const Account&);
private:
    std::vector<Account>accounts; // accounts stored in dataBase
    int findAccount(const int &accountNumber )const;// search the dataBase (helper function)
};


#endif //MAIN_CPP_DATABASE_H
