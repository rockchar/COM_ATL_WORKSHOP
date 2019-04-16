// LabInterfaceBasedProgramming.cpp : Defines the entry point for the console application.


/***************************************************************************************************
The purpose of this lab and exercise is to prepare for the real COM development. As we know that the 
separation of the interface from the implementation is what COM-based programming is all about. 

1.	This lab will give the chance to define some interfcaes in C++ as well as develop two classes 
	supporting a number of these Interfaces.
2. We will create your own API that creates,destroys, and extracts interfcae pointers from a given object.
3. We will have a chance to work with interfcae hierarchies and functions which take interfcae pointers as 
   parameters.
****************************************************************************************************/

#include "stdafx.h"
#include "C3DRect.h"
#include "rectfunctions.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CreateA3DRect();
	IDraw * pDraw;
	IShapeEdit * pShapeEdit;
	GetInterfaceFrom3DRect(IDRAW,(void**) &pDraw);
	GetInterfaceFrom3DRect(ISHAPEEDIT, (void**) &pShapeEdit);
	pDraw->Draw();
	pShapeEdit->Fill(POLKADOT);
	pShapeEdit->Stretch(20);

	Destroy3DRect();
	return 0;
}
