//
// Created by Ismail Magdy on 05/10/2022.
//

#include "DataBase.h"
#include <map>
#include "Account.h"
using namespace std;
std::pair<bool, Account> DataBase::authenticateAccount(const string &accountNumber, const string &PIN)const{

    Account dummy ("","",0);  // DUMMY ACCOUNT in case of not finding account
    pair<bool,Account> searchResult={false,dummy}; // result of search {found or not,account searched}

    int idx = findAccount(accountNumber); // searching for an account with this account number
    if(idx!=-1)
    {
        if(accounts[idx].getPIN()==PIN) // validating PIN
        {
            searchResult.second  = accounts[idx];
            searchResult.first = true;
        }
    }
    return searchResult;
}


void DataBase::updateAccount(const Account & account) {
    int idx = findAccount(account.getAccountNumber());
    accounts[idx] = account;
}


int DataBase::findAccount(const string &accountNumber) const { // searching for an account with this account number
    for(int i = 0 ;i<accounts.size();i++)
    {
        if(accounts[i].getAccountNumber()==accountNumber)
            return  i;
    }
    return -1;
}
