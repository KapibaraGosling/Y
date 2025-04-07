#include <iostream>
#include <string>
#include <iomanip>
#include"Person.h"
using namespace std;



Person::Person()
{
	lastname = "";
    firstname = "";
    patronomyc = "";
}
Person::Person(const string ln, const string fn, const string pn)
{
	lastname = ln;
	firstname = fn;
	patronomyc = pn;
}
void Person::Show()
{
	cout << left << setw(15) << "Surname: " << lastname << endl
		<< setw(15) << "Name: " << firstname << endl;
}
void Person::ShowFormal()
{
	cout <<left << setw(15) << "Surname: " << lastname << endl
		<< setw(15) << "Name: " << firstname << endl
		<< setw(15) << "Patronomyc: " << patronomyc << endl;
}
