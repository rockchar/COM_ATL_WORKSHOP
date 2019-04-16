// LabInterfaceBasedProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "rectfunctions.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CreateA3DRect();
	IDraw * pDrawRect = NULL;
	IShapeEdit * pShapeEdit = NULL;

	//get the IDRAW interface
	if (GetInterfaceFrom3DRect(IDRAW, (void**)&pDrawRect) == true)
	{
		std::cout << "interface IDRAW acqired" << std::endl;
	}
	else
	{
		std::cout << "Failed to acquire interface" << std::endl;
	}
	//get the ISHAPEEDIT interface
	if (GetInterfaceFrom3DRect(ISHAPEEDIT, (void**)&pShapeEdit) == true)
	{
		std::cout << "interface ISHAPEEDIT acqired" << std::endl;
	}
	else
	{
		std::cout << "Failed to acquire interface" << std::endl;
	}

	pDrawRect->Draw();
	pShapeEdit->Fill(POLKADOT);
	pShapeEdit->Inverse();
	pShapeEdit->Stretch(100);
	//free the memory
	Destroy3DRect();
	return 0;
}

