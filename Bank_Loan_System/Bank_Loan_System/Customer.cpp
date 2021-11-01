#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;

Customer::Customer() {};

Customer::Customer(string name, int age, float monthly_income)
{
	this->name = name;
	this->age = age;
	this->monthly_income = monthly_income;
}

void Customer::set_name(string name)
{
	this->name = name;
}

string Customer::get_name()
{
	return name;
}

void Customer::set_age(int age)
{
	this->age = age;
}

int Customer::get_age()
{
	return age;
}

void Customer::set_monthly_income(float monthly_income)
{
	this->monthly_income = monthly_income;
}

float Customer::get_monthly_income()
{
	return monthly_income;
}

