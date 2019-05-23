// designMode.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include "proxy.h"
#include <intrin.h>
#include "observerManager.h"
#include "observer.h"

#include <string>

using namespace std;

void func(User &user) {
	cout << "name " << user.name() << endl;
}

int main()
{
	cout << "Hello CMake。" << endl;

	Seller* mediator = new Mediator();
	Buyer* houseBuyer = new HouseBuyer(mediator);

	houseBuyer->buy();

	ObserverManager* wechatServer = new WechatServer();

	Observer* ob = nullptr;

	for (auto i = 0; i < 0; ++i) {
		Observer* hh = new User("devin" + std::to_string(i));
		wechatServer->registerObserver(hh);
		if (i == 10) ob = hh;
	}

	wechatServer->notifyObserver("hahah");

	wechatServer->removeObserver(ob);
	wechatServer->notifyObserver("cccc");

	WechatServer *server = dynamic_cast<WechatServer*>(wechatServer);
	//server->getDataFromDb();

	vector<User> data;
	{
		//data.emplace_back(User("lllizhu"));
		User &u = User("lllizhu");
		func(u);
	}
	//User &&ff = User("lllizhu");
	//int i = 0;

	system("pause");

	return 0;
}
