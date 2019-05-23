#include "observer.h"

Observer::Observer(string name) : m_name(name)
{
}

Observer::~Observer()
{
}

User::User(string name) : Observer(name)
{
	cout << "construct is runing \n" << endl;
}

User::~User()
{
	cout << "destruct is runing \n" << endl;
}

void User::update(const string& msg)
{
	cout << "my name is: " << name().data() << ", receive msg: " << msg.data() << endl;
}

User::User(const User& rhs)
{
	this->setName(rhs.name());
	cout << "copy construct is runing \n" << endl;
}

User& User::operator=(const User& rhs)
{
	cout << "operator= is runing \n" << endl;
	this->setName(rhs.name());
	return *this;
}