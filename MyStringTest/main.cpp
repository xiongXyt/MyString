#include <iostream>
#include "MyStringTest.h"
using namespace std;

int main() {
	char const* strnum1 = "qwe";
	MyStringTest str1(strnum1);
	cout << str1.GetStr() << endl;
	cout << str1.GetStrLen() << endl;

	char const* strnum2 = "asd";
	MyStringTest str2(&str1);
	cout << str2.GetStr() << endl;
	cout << str2.GetStrLen() << endl;

	MyStringTest str3(strnum2);
	cout << str3.GetStr() << endl;
	cout << str3.GetStrLen() << endl;
	
	str3 = str1;
	cout << str3.GetStr() << endl;
	cout << str3.GetStrLen() << endl;

	return 0;
}
