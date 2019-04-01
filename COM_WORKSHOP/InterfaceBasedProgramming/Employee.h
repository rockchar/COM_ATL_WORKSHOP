#pragma once
#include<iostream>

using namespace std;
/* CEmployee class with virtual methods */
class CEmployee
{
public:
	CEmployee();
	virtual ~CEmployee();

	//class methods
public:
	//although we define a default implementaion for these functions we also allow subclasses 
	//to override 
	virtual void DisplayClassType()
	{
		cout << "This is a CEmployee object" << endl;
	}
	//pure virtual functions are a good way to enforce derived class behaviour
	virtual float GetPay() = 0;
};

//we will inherit the base class to create a new employee called the sales employee

class CSalesEmployee : public CEmployee
{
public :
	//the virtual keyword is optional in the derived class // subclass 
	virtual void DisplayClassType()
	{
		cout << "This is a CSalesEmployee object" << endl;
	}

	virtual float GetPay();

};