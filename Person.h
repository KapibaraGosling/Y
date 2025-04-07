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

private:
	string lastname;
	string firstname;
	string patronomyc;
};
