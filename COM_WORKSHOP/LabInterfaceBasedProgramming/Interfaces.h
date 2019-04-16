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
	ISHAPEEDIT = 1,
	IDRAW2     = 2,
	IDRAW3     = 3
};

interface IDraw{
	virtual void Draw() = 0;
};

interface IShapeEdit {
	virtual void Fill(FILLTYPE fType) = 0;
	virtual void Inverse() = 0;
	virtual void Stretch(int factor) = 0;
};

/**************************************************************************************************************
Now we will versoion an existing interface.
Let us add another new class called the C3DRectEx in the existing project.
This class will support a number of versioned interface for example IDraw, IDraw2,and IDraw3
   Step1: we will define the intrfaces  in the interfaces.h file
   Step2: Derive C3DRectEx directly from IDraw3
***************************************************************************************************************/
interface IDraw2 : public IDraw{
	virtual void DrawToMemory()  = 0;
	virtual void DrawToPrinter() = 0;
};

interface IDraw3 : public IDraw2 {
	virtual void DrawToMetaFile() = 0;
};

#endif