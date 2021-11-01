#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
	string name;
	int age;
	float monthly_income;

public:
	Customer();
	Customer(string name, int age, float monthly_income);
	void set_name(string name);
	string get_name();
	void set_age(int age);
	int get_age();
	void set_monthly_income(float monthly_income);
	float get_monthly_income();
};

