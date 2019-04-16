#pragma once
#include <Windows.h>



//lets create a basic interface for a car
interface ICar
{
	// all the ICar methods
};

//ISportsCar
interface ISportsCar : public ICar
{	
	//
};

interface IReallyFastSportsCar : public ISportsCar
{
	//
};

interface IFamilyCar : public ICar
{
	//
};

interface IBoringFamilyCar : public IFamilyCar{

};

/******************************* NOTE ******************************************
As defined before a class wishing to suport all the behaviours must derive from 
the nth-most interfcae in the hierarchy, and acquire all functionality up in the 
inheritance chain. E.g.
********************************************************************************/

class CMiniVan : public IBoringFamilyCar{
public:
	//ICarMethods
	//IFamilyCar methods
	//IBoringFamilyCar methods

};

//this automobile implements Icar and IsportsCar
class CSportsCedan : public ISportsCar{


};