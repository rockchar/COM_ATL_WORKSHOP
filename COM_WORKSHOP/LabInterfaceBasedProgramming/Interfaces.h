#include<Windows.h>

#ifndef _IFACES
#define _IFACES

enum FILLTYPE {
	HATCH    = 0,
	SOLID    = 1,
	POLKADOT = 2
};

enum INTERFACEID{
	IDRAW      = 0,
	ISHAPEEDIT = 1
};

interface IDraw{
	virtual void Draw() = 0;
};

interface IShapeEdit{
	virtual void Fill(FILLTYPE fType) = 0;
	virtual void Inverse() = 0;
	virtual void Stretch(int factor) = 0;
};




#endif