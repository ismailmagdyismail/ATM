//
// Created by Ismail Magdy on 07/10/2022.
//

#ifndef MAIN_CPP_CASHDISPENSER_H
#define MAIN_CPP_CASHDISPENSER_H


class CashDispenser {
public:

    CashDispenser(const double& availableMoney);

    bool dispenseMoney(double& amount);

private:
    double availableMoney;
};


#endif //MAIN_CPP_CASHDISPENSER_H
