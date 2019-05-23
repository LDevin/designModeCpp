// designMode.cpp: 定义应用程序的入口点。
//

#include <iostream>
#include "proxy.h"
#include <intrin.h>
#include "observerManager.h"
#include "observer.h"

#include <string>

using namespace std;

int main()
{
	cout << "Hello CMake。" << endl;

	Seller* mediator = new Mediator();
	Buyer* houseBuyer = new HouseBuyer(mediator);

	houseBuyer->buy();

	ObserverManager* wechatServer = new WechatServer();

	Observer* ob = nullptr;

	for (auto i = 0; i < 20; ++i) {
		Observer* hh = new User("devin" + std::to_string(i));
		wechatServer->registerObserver(hh);
		if (i == 10) ob = hh;
	}

	wechatServer->notifyObserver("hahah");

	wechatServer->removeObserver(ob);
	wechatServer->notifyObserver("cccc");

	WechatServer *server = dynamic_cast<WechatServer*>(wechatServer);
	server->getDataFromDb();

	system("pause");

	return 0;
}
