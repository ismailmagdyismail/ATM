
#include "DataBase.h"
#include <map>
#include "Account.h"
using namespace std;

DataBase::DataBase() {

    // two accounts for  testing
    Account account1(12345, 12345, 1200.0);
    Account account2(98765, 56789, 200.0);

    // store the accounts in database
    accounts.push_back(account1);
    accounts.push_back(account2);
}


std::pair<bool, Account> DataBase::authenticateAccount(const int &accountNumber, const int &PIN)const{

    Account dummy (0,0,0);  // DUMMY ACCOUNT in case of not finding account
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


int DataBase::findAccount(const int &accountNumber) const { // searching for an account with this account number
    for(int i = 0 ;i<accounts.size();i++)
    {
        if(accounts[i].getAccountNumber()==accountNumber)
            return  i;
    }
    return -1;
}
