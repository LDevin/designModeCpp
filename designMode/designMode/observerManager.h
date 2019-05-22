/***
*	@brief 观察者模式
***/
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Observer;
class ObserverManager
{

public:
	ObserverManager();
	virtual ~ObserverManager();

	virtual void registerObserver(Observer*) = 0;
	virtual void removeObserver(Observer*) = 0;
	virtual void notifyObserver(const string&) = 0;

private:

};

class WechatServer : public ObserverManager
{

public:
	WechatServer();
	virtual ~WechatServer();

	void registerObserver(Observer*) override;
	void removeObserver(Observer*) override;
	void notifyObserver(const string&) override;

	/*******
	*	@brief
	******/
	void getDataFromDb();

private:
	vector<Observer*> m_Observers;
};