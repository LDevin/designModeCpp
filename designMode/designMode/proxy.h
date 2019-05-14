/***
*	@brief 代理模式
***/

#pragma once
#include <iostream>

using namespace std;

class Person
{

public:
	Person();
	virtual ~Person();
	
	virtual void rtti();

	string name() const;
	void setName(const string& name);

	void setGender(int gender);
	int gender() const;

private:
	string m_name;
	int m_gender;
};

class Seller : public Person
{

public:
	Seller();
	virtual ~Seller();

	/***
	*	@brief interface
	***/
	virtual void sell() = 0;
private:

};


class Buyer : public Person
{

public:
	Buyer(Seller* seller = nullptr);
	virtual ~Buyer();

	void setSeller(Seller* seller);
	Seller* getSeller() const;

	/***
	*	@brief interface
	***/
	virtual void buy();

private:
	Seller* m_pSeller;
};

class HouseBuyer : public Buyer
{

public:
	HouseBuyer(Seller* seller = nullptr);
	~HouseBuyer();

	/***
	*	@brief interface
	***/
	void buy() override;
private:

};

class HouseSeller : public Seller
{

public:
	HouseSeller();
	~HouseSeller();

	/***
	*	@brief interface
	***/
	void sell() override;

private:

};


//中介
class Mediator : public Seller
{

public:
	Mediator();
	~Mediator();

	/***
	*	@brief interface
	***/
	void sell() override;

private:
	Seller* m_pSeller;
};

