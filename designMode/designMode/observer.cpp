#include "observer.h"

Observer::Observer(string name) : m_name(name)
{
}

Observer::~Observer()
{
}

User::User(string name) : Observer(name)
{

}

User::~User()
{

}

void User::update(const string& msg)
{
	cout << "my name is: " << name().data() << ", receive msg: " << msg.data() << endl;
}