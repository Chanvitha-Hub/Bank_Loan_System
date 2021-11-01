#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <fstream>
#include "Customer.h"
#include "Bank.h"

using namespace std;

int main()
{
	Customer customer;
	Bank vehicle("Vehicle", 1000000.0f, 60.0f, 14.0f);
	Bank housing("Housing", 2500000.0f, 60.0f, 8.0f);
	Bank education("Education", 1500000.0f, 84.0f, 6.0f);
	Bank senior("Senior", 500000.0f, 60.0f, 4.5f);
	Bank personal_1("Personal_1", 2000000.0f, 60.0f, 14.5f);
	Bank personal_2("Personal_2", 3000000.0f, 84.0f, 16.2f);
	
	cout << "\n\t\t**************************BANK LOAN SYSTEM**************************\n\n";
	string user_name;
	int age;
	float income;
	cout << "\tEnter the customer name: ";
	cin >> user_name;
	customer.set_name(user_name);
	cout << "\tEnter the customer age: ";
	cin >> age;
	customer.set_age(age);
	cout << "\tEnter the customer monthly income: ";
	cin >> income;
	customer.set_monthly_income(income);

	//print the loan list
	cout << "\n\tLoan Type\t\tMax Loan amount\t\tmax repay amount\tannual interest rate\n\n";
	cout << "\t1." << vehicle.get_loan_type() << "\t\t" << vehicle.get_max_loan_amount() << "\t\t\t" << vehicle.get_max_repay_period() << "\t\t\t" << vehicle.get_annual_interest_rate() << endl;
	cout << "\t2." << housing.get_loan_type() << "\t\t" << housing.get_max_loan_amount() << "\t\t\t" << housing.get_max_repay_period() << "\t\t\t" << housing.get_annual_interest_rate() << endl;
	cout << "\t3." << education.get_loan_type() << "\t\t" << education.get_max_loan_amount() << "\t\t\t" << education.get_max_repay_period() << "\t\t\t" << education.get_annual_interest_rate() << endl;
	cout << "\t4." << senior.get_loan_type() << "\t\t" << senior.get_max_loan_amount() << "\t\t\t" << senior.get_max_repay_period() << "\t\t\t" << senior.get_annual_interest_rate() << endl;
	cout << "\t5." << personal_1.get_loan_type() << "\t\t" << personal_1.get_max_loan_amount() << "\t\t\t" << personal_1.get_max_repay_period() << "\t\t\t" << personal_1.get_annual_interest_rate() << endl;
	cout << "\t6." << personal_2.get_loan_type() << "\t\t" << personal_2.get_max_loan_amount() << "\t\t\t" << personal_2.get_max_repay_period() << "\t\t\t" << personal_2.get_annual_interest_rate() << endl;

	//selecting a loan plan by user
	int choice;
	cout << "\n\tEnter your prefer plan: ";
	cin >> choice;
	//transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

	int loan_amount;
	int possible_period;
	cout << "\tEnter the loan amount you want: ";
	cin >> loan_amount;
	cout << "\tEnter the possible repay period(months): ";
	cin >> possible_period;

	std::ofstream my_file;
	my_file.open("Mr." + customer.get_name() + ".txt");
	my_file << "\n\tCusomer Name:\t\t" << customer.get_name() << endl;
	my_file << "\tRequested Loan Amount:\t" << loan_amount << endl;
	my_file << "\tPossible Period:\t" << possible_period << endl;

	switch (choice)
	{
		case 1:
		{
			if (loan_amount <= vehicle.get_max_loan_amount() && possible_period <= vehicle.get_max_repay_period() &&
				customer.get_age() >=18 && customer.get_age() <= 55)
			{
				my_file << "\tLoan Type:\t\t" << vehicle.get_loan_type() << endl;
				my_file << "\tMax. Repay Period:\t" << vehicle.get_max_repay_period() << endl;
				my_file << "\tAnnual Interest Rate:\t" << vehicle.get_annual_interest_rate() << endl;
				//cout << "\tMonthly Repay amount:\t" << vehicle.monthly_repay_amount(possible_period, vehicle.get_annual_interest_rate(), loan_amount) << endl;
				//my_file << "\tMonthly Repay amount:\t" << vehicle.monthly_repay_amount(possible_period, vehicle.get_annual_interest_rate(), loan_amount) << endl;
				
				int n = possible_period;
				float IR = vehicle.get_annual_interest_rate() / (100 * n);
				float D;
				float monthly_interest = 0;
				float monthly_repaid = 0;
				float total_interest = 0;
				float total_repaid = 0;
				D = ((pow((1 + IR), n) - 1) / (IR * (pow((1 + IR), n))));
				float total_monthly_payment = loan_amount / D;
				//std::ofstream my_file;
				//myfile.open("myfile.txt", std::ios::app);

				cout << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (vehicle.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (vehicle.get_annual_interest_rate() / (100 * 12))) << endl;

				my_file << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (vehicle.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (vehicle.get_annual_interest_rate() / (100 * 12))) << endl;

				for (int i = 0; i < possible_period; i++)
				{
					monthly_interest = loan_amount * (vehicle.get_annual_interest_rate() / (100 * 12));
					monthly_repaid = total_monthly_payment - monthly_interest;
					total_interest += monthly_interest;
					total_repaid += monthly_repaid;
					loan_amount -= monthly_repaid;
					cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					
				}

				cout << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				cout << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				cout << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;
				
				my_file << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				my_file << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				my_file << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;
				
				break;
			}
			else
			{
				cout << "\tInvalid loan amount or repay period or age!!!\n";
				break;
			}
		}

		case 2:
		{
			if (loan_amount <= housing.get_max_loan_amount() && possible_period <= housing.get_max_repay_period() &&
				customer.get_age() >= 25 && customer.get_age() <= 55)
			{
				my_file << "\tLoan Type:\t\t" << housing.get_loan_type() << endl;
				my_file << "\tMax. Repay Period:\t" << housing.get_max_repay_period() << endl;
				my_file << "\tAnnual Interest Rate:\t" << housing.get_annual_interest_rate() << endl;
				//cout << "\tMonthly Repay amount:\t" << housing.monthly_repay_amount(possible_period, housing.get_annual_interest_rate(), loan_amount) << endl;
				//my_file << "\tMonthly Repay amount:\t" << housing.monthly_repay_amount(possible_period, housing.get_annual_interest_rate(), loan_amount) << endl;
				

				int n = possible_period;
				float IR = housing.get_annual_interest_rate() / (100 * n);
				float D;
				float monthly_interest = 0;
				float monthly_repaid = 0;
				float total_interest = 0;
				float total_repaid = 0;
				D = ((pow((1 + IR), n) - 1) / (IR * (pow((1 + IR), n))));
				float total_monthly_payment = loan_amount / D;
				//std::ofstream my_file;
				//myfile.open("myfile.txt", std::ios::app);

				cout << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (housing.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (housing.get_annual_interest_rate() / (100 * 12))) << endl;

				my_file << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (housing.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (housing.get_annual_interest_rate() / (100 * 12))) << endl;

				for (int i = 0; i < possible_period; i++)
				{
					monthly_interest = loan_amount * (housing.get_annual_interest_rate() / (100 * 12));
					monthly_repaid = total_monthly_payment - monthly_interest;
					total_interest += monthly_interest;
					total_repaid += monthly_repaid;
					loan_amount -= monthly_repaid;
					cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;

				}

				cout << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				cout << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				cout << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				my_file << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				my_file << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				my_file << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				break;
			}
			else
			{
				cout << "\tInvalid loan amount or repay period or age!!!\n";
				break;
			}
		}

		case 3:
		{
			if (loan_amount <= education.get_max_loan_amount() && possible_period <= education.get_max_repay_period() &&
				customer.get_age() >= 25 && customer.get_age() <= 35)
			{
				my_file << "\tLoan Type:\t\t" << education.get_loan_type() << endl;
				my_file << "\tMax. Repay Period:\t" << education.get_max_repay_period() << endl;
				my_file << "\tAnnual Interest Rate:\t" << education.get_annual_interest_rate() << endl;
				//cout << "\tMonthly Repay amount:\t" << education.monthly_repay_amount(possible_period, education.get_annual_interest_rate(), loan_amount) << endl;
				//my_file << "\tMonthly Repay amount:\t" << education.monthly_repay_amount(possible_period, education.get_annual_interest_rate(), loan_amount) << endl;
				

				int n = possible_period;
				float IR = education.get_annual_interest_rate() / (100 * n);
				float D;
				float monthly_interest = 0;
				float monthly_repaid = 0;
				float total_interest = 0;
				float total_repaid = 0;
				D = ((pow((1 + IR), n) - 1) / (IR * (pow((1 + IR), n))));
				float total_monthly_payment = loan_amount / D;
				//std::ofstream my_file;
				//myfile.open("myfile.txt", std::ios::app);

				cout << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (education.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (education.get_annual_interest_rate() / (100 * 12))) << endl;

				my_file << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (education.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (education.get_annual_interest_rate() / (100 * 12))) << endl;

				for (int i = 0; i < possible_period; i++)
				{
					monthly_interest = loan_amount * (education.get_annual_interest_rate() / (100 * 12));
					monthly_repaid = total_monthly_payment - monthly_interest;
					total_interest += monthly_interest;
					total_repaid += monthly_repaid;
					loan_amount -= monthly_repaid;
					cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;

				}

				cout << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				cout << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				cout << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				my_file << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				my_file << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				my_file << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				break;
			}
			else
			{
				cout << "\tInvalid loan amount or repay period or age!!!\n";
				break;
			}
		}

		case 4:
		{
			if (loan_amount <= senior.get_max_loan_amount() && possible_period <= senior.get_max_repay_period() &&
				customer.get_age() >= 60)
			{
				my_file << "\tLoan Type:\t\t" << senior.get_loan_type() << endl;
				my_file << "\tMax. Repay Period:\t" << senior.get_max_repay_period() << endl;
				my_file << "\tAnnual Interest Rate:\t" << senior.get_annual_interest_rate() << endl;
				//cout << "\tMonthly Repay amount:\t" << senior.monthly_repay_amount(possible_period, senior.get_annual_interest_rate(), loan_amount) << endl;
				//my_file << "\tMonthly Repay amount:\t" << senior.monthly_repay_amount(possible_period, senior.get_annual_interest_rate(), loan_amount) << endl;
				

				int n = possible_period;
				float IR = senior.get_annual_interest_rate() / (100 * n);
				float D;
				float monthly_interest = 0;
				float monthly_repaid = 0;
				float total_interest = 0;
				float total_repaid = 0;
				D = ((pow((1 + IR), n) - 1) / (IR * (pow((1 + IR), n))));
				float total_monthly_payment = loan_amount / D;
				//std::ofstream my_file;
				//myfile.open("myfile.txt", std::ios::app);

				cout << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (senior.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (senior.get_annual_interest_rate() / (100 * 12))) << endl;

				my_file << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (senior.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (senior.get_annual_interest_rate() / (100 * 12))) << endl;

				for (int i = 0; i < possible_period; i++)
				{
					monthly_interest = loan_amount * (senior.get_annual_interest_rate() / (100 * 12));
					monthly_repaid = total_monthly_payment - monthly_interest;
					total_interest += monthly_interest;
					total_repaid += monthly_repaid;
					loan_amount -= monthly_repaid;
					cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;

				}

				cout << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				cout << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				cout << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				my_file << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				my_file << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				my_file << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				break;
			}
			else
			{
				cout << "\tInvalid loan amount or repay period or age!!!\n";
				break;
			}
		}

		case 5:
		{
			if (loan_amount <= personal_1.get_max_loan_amount() && possible_period <= personal_1.get_max_repay_period() &&
				customer.get_age() >= 30 && customer.get_age() <= 55)
			{
				my_file << "\tLoan Type:\t\t" << personal_1.get_loan_type() << endl;
				my_file << "\tMax. Repay Period:\t" << personal_1.get_max_repay_period() << endl;
				my_file << "\tAnnual Interest Rate:\t" << personal_1.get_annual_interest_rate() << endl;
				//cout << "\tMonthly Repay amount:\t" << personal_1.monthly_repay_amount(possible_period, personal_1.get_annual_interest_rate(), loan_amount) << endl;
				//my_file << "\tMonthly Repay amount:\t" << personal_1.monthly_repay_amount(possible_period, personal_1.get_annual_interest_rate(), loan_amount) << endl;
				

				int n = possible_period;
				float IR = personal_1.get_annual_interest_rate() / (100 * n);
				float D;
				float monthly_interest = 0;
				float monthly_repaid = 0;
				float total_interest = 0;
				float total_repaid = 0;
				D = ((pow((1 + IR), n) - 1) / (IR * (pow((1 + IR), n))));
				float total_monthly_payment = loan_amount / D;
				//std::ofstream my_file;
				//myfile.open("myfile.txt", std::ios::app);

				cout << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (personal_1.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (personal_1.get_annual_interest_rate() / (100 * 12))) << endl;

				my_file << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (personal_1.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (personal_1.get_annual_interest_rate() / (100 * 12))) << endl;

				for (int i = 0; i < possible_period; i++)
				{
					monthly_interest = loan_amount * (personal_1.get_annual_interest_rate() / (100 * 12));
					monthly_repaid = total_monthly_payment - monthly_interest;
					total_interest += monthly_interest;
					total_repaid += monthly_repaid;
					loan_amount -= monthly_repaid;
					cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;

				}

				cout << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				cout << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				cout << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				my_file << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				my_file << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				my_file << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				break;
			}
			else
			{
				cout << "\tInvalid loan amount or repay period or age!!!\n";
				break;
			}
		}

		case 6:
		{
			if (loan_amount <= personal_2.get_max_loan_amount() && possible_period <= personal_2.get_max_repay_period() &&
				customer.get_age() >= 30 && customer.get_age() <= 55)
			{
				my_file << "\tLoan Type:\t\t" << personal_2.get_loan_type() << endl;
				my_file << "\tMax. Repay Period:\t" << personal_2.get_max_repay_period() << endl;
				my_file << "\tAnnual Interest Rate:\t" << personal_2.get_annual_interest_rate() << endl;
				//cout << "\tMonthly Repay amount:\t" << personal_2.monthly_repay_amount(possible_period, personal_2.get_annual_interest_rate(), loan_amount) << endl;
				//my_file << "\tMonthly Repay amount:\t" << personal_2.monthly_repay_amount(possible_period, personal_2.get_annual_interest_rate(), loan_amount) << endl;
				

				int n = possible_period;
				float IR = personal_2.get_annual_interest_rate() / (100 * n);
				float D;
				float monthly_interest = 0;
				float monthly_repaid = 0;
				float total_interest = 0;
				float total_repaid = 0;
				D = ((pow((1 + IR), n) - 1) / (IR * (pow((1 + IR), n))));
				float total_monthly_payment = loan_amount / D;
				//std::ofstream my_file;
				//myfile.open("myfile.txt", std::ios::app);

				cout << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (personal_2.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (personal_2.get_annual_interest_rate() / (100 * 12))) << endl;

				my_file << "\n\tLoan amount\tInterest\tRepaid loan amount\n\n";
				my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
					<< fixed << setprecision(2) << loan_amount * (personal_2.get_annual_interest_rate() / (100 * 12))
					<< "\t\t" << fixed << setprecision(2) << total_monthly_payment - (loan_amount * (personal_2.get_annual_interest_rate() / (100 * 12))) << endl;

				for (int i = 0; i < possible_period; i++)
				{
					monthly_interest = loan_amount * (personal_2.get_annual_interest_rate() / (100 * 12));
					monthly_repaid = total_monthly_payment - monthly_interest;
					total_interest += monthly_interest;
					total_repaid += monthly_repaid;
					loan_amount -= monthly_repaid;
					cout << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;
					my_file << "\t" << fixed << setprecision(2) << loan_amount << "\t\t"
						<< fixed << setprecision(2) << monthly_interest << "\t\t"
						<< fixed << setprecision(2) << monthly_repaid << endl;

				}

				cout << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				cout << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				cout << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				my_file << "\n\tTotal Interest:\t" << fixed << setprecision(2) << total_interest << endl;
				my_file << "\tTotal Repaid:\t" << fixed << setprecision(2) << total_repaid << endl;
				my_file << "\tTotal Amount should pay:\t" << fixed << setprecision(2) << total_repaid + total_interest << endl;

				break;
			}
			else
			{
				cout << "\tInvalid loan amount or repay period or age!!!\n";
				break;
			}
		}

		default:
		{
			cout << "\tInvalid Loan Type!!\n";
			break;
		}
	}

	return 0;
}