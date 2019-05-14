// designMode.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include "proxy.h"

using namespace std;

int main()
{
	cout << "Hello CMake。" << endl;

	Seller* mediator = new Mediator();
	Buyer* houseBuyer = new HouseBuyer(mediator);

	houseBuyer->buy();

	system("pause");
	return 0;
}
