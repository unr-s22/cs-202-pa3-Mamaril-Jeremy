//Tanner Ashby
#pragma once

#include <vector>
#include <sstream>
#include "Money.h"

class Account{
    bool m_mustUpdate;
    Money m_balance;
    std::vector<Money> m_deposits;
    std::vector<Money> m_withdrawals;
    unsigned int m_depCount;
    unsigned int m_withCount;
    std::stringstream m_depString;
    std::stringstream m_withString;

    void updateBalance();
public:
    Account(Money& newMoney);

    void makeDeposit(const Money& m);
    void makeWithdrawals(const Money& m);

    friend std::ostream& operator<<(std::ostream& out, Account& ac);
};
