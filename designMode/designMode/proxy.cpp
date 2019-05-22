#include "proxy.h"
#include "define.h"
#include <stack>

Person::Person(): m_name(""), m_gender(1)
{
}

Person::~Person()
{
}

void Person::setName(const string& name)
{
	m_name = name;
}

string Person::name() const
{
	return m_name;
}

void Person::setGender(int gender)
{
	m_gender = gender;
}

int Person::gender() const
{
	return m_gender;
}

void Person::rtti()
{
	cout << "run Person instance\n" << endl;
}

//
Buyer::Buyer(Seller* seller) : m_pSeller(seller)
{
}

Buyer::~Buyer()
{
	RELEASE(m_pSeller)
}

void Buyer::setSeller(Seller* seller)
{
	RELEASE(m_pSeller)
	m_pSeller = seller;
}
Seller* Buyer::getSeller() const
{
	return m_pSeller;
}

void Buyer::buy()
{
	m_pSeller->sell();
}

HouseBuyer::HouseBuyer(Seller* seller) : Buyer(seller)
{
	
}

HouseBuyer::~HouseBuyer()
{

}

void HouseBuyer::buy() 
{
	cout << "house buyer start buy house \n" << endl;
	getSeller()->sell();
}

//
Seller::Seller()
{
}

Seller::~Seller()
{
}

HouseSeller::HouseSeller()
{

}

HouseSeller::~HouseSeller()
{

}

void HouseSeller::sell()
{
	cout << "house seller start sell\n" << endl;
}

Mediator::Mediator() : m_pSeller(nullptr)
{

}

Mediator::~Mediator()
{
	RELEASE(m_pSeller)
}

void Mediator::sell()
{
	if (!m_pSeller) {
		m_pSeller = new HouseSeller();
	}

	m_pSeller->sell();
}