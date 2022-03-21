#include "Money.h"

Money::Money() : m_dollars(0), m_cents(0){}

Money::Money(int dollars, int cents): m_dollars(dollars), m_cents(cents){}

Money::Money(const Money& otherMoney): m_dollars(otherMoney.m_dollars), m_cents(otherMoney.m_cents){}

void Money::setMoney(int dollars, int cents){
	m_dollars = dollars;
	m_cents = cents;
}

Money Money::operator=(Money other){
	this->m_dollars = other.m_dollars;
	this->m_cents = other.m_cents;
	
	return *this;
}

std::ostream& operator<<(std::ostream& out, Money& m){
	out << "$" << m.m_dollars << ".";
	if(m.m_cents < 10){
		out << "0";
	}
	
	out<<m.m_cents;
	
	return out;
}

Money operator+(const Money& op1, const Money& op2){
	int dollars = op1.m_dollars + op2.m_dollars;
	int cents = op1.m_cents + op2.m_cents;
	
	if(cents > 100){
		int carry = cents/100;
		dollars += carry;
		cents -= carry * 100;
	}
	
	Money result(dollars, cents);
	
	return result;
}

Money operator-(const Money& op1, const Money& op2){
	int dollars = op1.m_dollars - op2.m_dollars;
	int cents = op1.m_cents - op2.m_cents;	
	if(cents < 0){
		int borrow = ((-1) * cents) / 100;
		dollars -= borrow;
		
		cents += borrow * 100;
	}
	
	Money result(dollars, cents);
	
	return result;
}

bool operator>(const Money& op1, const Money& op2){
	float m1 = op1.m_dollars + (op1.m_cents / 100);
	float m2 = op2.m_dollars + (op2.m_cents / 100);
	
	return m1 > m2;
}

bool operator<(const Money& op1, const Money& op2){
	float m1 = op1.m_dollars + (op1.m_cents / 100);
	float m2 = op2.m_dollars + (op2.m_cents / 100);
	
	return m1 < m2;
}

bool operator==(const Money& op1, const Money& op2){
	float m1 = op1.m_dollars + (op1.m_cents / 100);
	float m2 = op2.m_dollars + (op2.m_cents / 100);
	
	return m1 == m2;
}

bool operator!=(const Money& op1, const Money& op2){
	float m1 = op1.m_dollars + (op1.m_cents / 100);
	float m2 = op2.m_dollars + (op2.m_cents / 100);
	
	return m1 != m2;
}

bool operator>=(const Money& op1, const Money& op2){
	float m1 = op1.m_dollars + (op1.m_cents / 100);
	float m2 = op2.m_dollars + (op2.m_cents / 100);
	
	return m1 >= m2;
}
