#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bank
{
private:
	string loan_type;
	int max_loan_amount;
	float max_repay_period;
	float annual_interest_rate;

public:
	Bank();
	std::ofstream my_file;
	Bank(string loan_type, float max_loan_amount, float max_repay_period, float annual_interest_rate);
	void set_loan_type(string loan_type);
	string get_loan_type();
	void set_max_loan_amount(int max_loan_amount);
	int get_max_loan_amount();
	void set_max_repay_period(float max_repay_period);
	float get_max_repay_period();
	void set_annual_interest_rate(float annual_interest_rate);
	float get_annual_interest_rate();
	//float monthly_repay_amount(int periods, float annual_interest_rate, float loan_amount);
};

