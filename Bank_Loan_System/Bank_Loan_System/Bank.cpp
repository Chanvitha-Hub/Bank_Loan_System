#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Bank.h"

using namespace std;

Bank::Bank() {};

Bank::Bank(string loan_type, float max_loan_amount, float max_repay_period, float annual_interest_rate)
{
	this->loan_type = loan_type;
	this->max_loan_amount = max_loan_amount;
	this->max_repay_period = max_repay_period;
	this->annual_interest_rate = annual_interest_rate;
}

void Bank::set_loan_type(string loan_type)
{
	this->loan_type = loan_type;
}

string Bank::get_loan_type()
{
	return loan_type;
}

void Bank::set_max_loan_amount(int max_loan_amount)
{
	this->max_loan_amount = max_loan_amount;
}

int Bank::get_max_loan_amount()
{
	return max_loan_amount;
}

void Bank::set_max_repay_period(float max_repay_period)
{
	this->max_repay_period = max_repay_period;
}

float Bank::get_max_repay_period()
{
	return max_repay_period;
}

void Bank::set_annual_interest_rate(float annual_interest_rate)
{
	this->annual_interest_rate = annual_interest_rate;
}

float Bank::get_annual_interest_rate()
{
	return annual_interest_rate;
}
