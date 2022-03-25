#ifndef MONEY_H
#define MONEY_H

#include <iostream>

class Money{
private:
	int m_dollars;
	int m_cents;
	
public:
	Money();
	Money(int dollars, int cents);
	Money(const Money& otherMoney);
	
	void setMoney(int dollars, int cents);
	
	Money operator=(Money other);

	friend std::ostream& operator<<(std::ostream& out, Money& m);
	friend Money operator+(const Money &op1, const Money& op2);
	friend Money operator-(const Money &op1, const Money& op2);
	friend bool operator>(const Money &op1, const Money& op2);
	friend bool operator<(const Money &op1, const Money& op2);
	friend bool operator==(const Money &op1, const Money& op2);
	friend bool operator!=(const Money &op1, const Money& op2);
	friend bool operator>=(const Money &op1, const Money& op2);

};

#endif
