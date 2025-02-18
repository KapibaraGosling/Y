#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person
{
public:
	Person();
	Person(const string ln, const string fn, const string pn);
	void Show();
	void ShowFormal();
	~Person();

private:
	string lastname;
	string firstname;
	string patronomyc;
};

Person::Person()
{
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

Person::~Person()
{
}