#include <algorithm>
#include "observerManager.h"
#include "define.h"
#include "observer.h"
#include <thread>


ObserverManager::ObserverManager()
{
}

ObserverManager::~ObserverManager()
{
}

WechatServer::WechatServer()
{
	m_Observers.reserve(100);
}

WechatServer::~WechatServer()
{
	for_each(m_Observers.begin(), m_Observers.end(), [](auto item) {RELEASE(item); });
	vector<Observer*>().swap(m_Observers);
}

void WechatServer::registerObserver(Observer* observer)
{
	auto iter = find(m_Observers.begin(), m_Observers.end(), observer);
	if (iter == m_Observers.end()) {
		m_Observers.emplace_back(observer);
	}
}

void WechatServer::removeObserver(Observer* observer)
{
	auto  iter = find(m_Observers.begin(), m_Observers.end(), observer);
	if (iter != m_Observers.end()) {
		RELEASE(*iter);
	}
}

void WechatServer::notifyObserver(const string& msg)
{
	for_each(m_Observers.begin(), m_Observers.end(), [&](auto item) {
		item->update(msg);
	});
}

void WechatServer::getDataFromDb()
{
	std::thread th([&]() {
		while (true) {
			std::this_thread::sleep_for(std::chrono::seconds(5));
			notifyObserver("fdfdsf");
		}
	});

	th.detach();
}