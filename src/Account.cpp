//Tanner Ashby
#include "Account.h"

Account::Account(Money& newMoney)
    : m_mustUpdate(false), m_balance(newMoney), m_depCount(0), m_withCount(0),
    m_depString(""), m_withString("")
{ }

void Account::updateBalance(){

    if (m_deposits.size() > 0){
        while (m_depCount < m_deposits.size()){
            m_depString << "(" << m_depCount+1 << ") " << m_deposits[m_depCount] << std::endl;
            m_balance = m_balance + m_deposits[m_depCount];

            m_depCount++;
        }
    }

    if (m_withdrawals.size() > 0){
        while (m_withCount < m_withdrawals.size()){
            m_withString << "(" << m_withCount+1 << ") " << m_withdrawals[m_withCount] << std::endl;
            m_balance = m_balance - m_withdrawals[m_withCount];

            m_withCount++;
        }
    }

    m_mustUpdate = false;
}

void Account::makeDeposit(const Money& m){
    m_mustUpdate = true;
    m_deposits.push_back(m);
}

void Account::makeWithdrawals(const Money& m){
    m_mustUpdate = true;
    m_withdrawals.push_back(m);
}

std::ostream& operator<<(std::ostream& out, Account& ac){
    if(ac.m_mustUpdate) { ac.updateBalance(); }

    out << "Account Details" << std::endl;
    out << "--------------------------" << std::endl;

    out << "Current Balance: " << ac.m_balance << std::endl;
    out << "--------------------------" << std::endl;

    out << "Number of Deposits: " << ac.m_deposits.size() << std::endl;
    out << "--------------------------" << std::endl;

    if (ac.m_depCount > 0){
        out << ac.m_depString.str();
        out << "--------------------------" << std::endl;
    }

    out << "Number of Withdrawals: " << ac.m_withdrawals.size() << std::endl;
    out << "--------------------------" << std::endl;
    if (ac.m_withCount > 0){
        out << ac.m_withString.str();
    }
    
    return out;
}
