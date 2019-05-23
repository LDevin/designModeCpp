#pragma once
#include <iostream>

using namespace std;

class Observer
{
public:
	Observer() = default;

	Observer(string name);
	virtual ~Observer();

	virtual void update(const string&) = 0;
	void setName(const string& name) { m_name = name; }
	string name() const { return m_name; }

private:
	string m_name;
};

class User : public Observer
{

public:
	User(string name);
	virtual ~User();

	void update(const string&) override;
	User(const User&);
	User& operator=(const User&);

private:

};