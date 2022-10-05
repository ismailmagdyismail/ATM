//
// Created by Ismail Magdy on 05/10/2022.
//

#ifndef MAIN_CPP_DATABASE_H
#define MAIN_CPP_DATABASE_H
#include <iostream>
#include "Account.h"
#include <vector>


class DataBase {
public:
    std::pair<bool,Account> AthenticateUser(const std::string &accountNumber, const std::string &PIN);

private:
    std::vector<Account>accounts; // accounts stored in dataBase
    int findAccount(const std::string& accountNumber )const;// search the dataBase (helper function)
};


#endif //MAIN_CPP_DATABASE_H
