#include <iostream>
#include <string>
#include <iomanip>
#include"Person.h"
using namespace std;

int main(){
	string name,sure,patro;
	cin >> name >> sure >> patro;
	Person p(name,sure,patro);
	p.Show();
	p.ShowFormal()

}