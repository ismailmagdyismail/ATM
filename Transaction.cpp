
#include "Transaction.h"

Transaction::Transaction(Account* account,Screen* screen) {
    this->account = account;
    this->screen = screen;
}

Account* Transaction::getAccount()const {
    return account;
}


Screen *Transaction::getScreen() const {
    return  screen;
}
