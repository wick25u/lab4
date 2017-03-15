// Rick Bowman, Brian Harrah, Alex Wick, Mike Langworthy
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;
bool EnterEmployeeAgain();

struct Employee
{
	int ID;
	string firstName;
	string lastName;
	double payRate;
	double hours;
};

int main()
{
	vector<Employee> E;

	do
	{
		Employee eTemp;
		cout << "Enter an employee ID: ";
		cin >> eTemp.ID;
		cout << "Enter employee first name: ";
		cin >> eTemp.firstName;
		cout << "Enter employee last name: ";
		cin >> eTemp.lastName;
		cout << "Enter employee pay rate: ";
		cin >> eTemp.payRate;
		cout << "Enter employee hours: ";
		cin >> eTemp.hours;
		E.push_back(eTemp);
	} while (EnterEmployeeAgain());

	double sum = 0;

	vector<Employee>::iterator it;
	for (it = E.begin(); it != E.end(); it++)
	{
		sum += it->payRate * it->hours;

		cout << it->ID << "\t" << it->firstName << "\t" << it->lastName << "\t" << it->payRate * it->hours << endl;
	}
	cout << "The total gross for all employees is: " << sum;

	_getch();
	return 0;
}
bool EnterEmployeeAgain()
{
	char in = '\0';
	while (in != 'y' && in != 'n' && in != 'N' && in != 'Y')
	{
		std::cout << "Would you like to add another employee? (y/n) ";
		std::cin >> in;
	}

	return (in == 'y' || in == 'Y');
}