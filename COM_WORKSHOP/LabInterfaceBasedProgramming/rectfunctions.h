#pragma once
#include <iostream>
#include "C3DRect.h"

C3DRect * ptheRect = NULL;

void CreateA3DRect();
void Destroy3DRect();


void CreateA3DRect(){

	ptheRect = new C3DRect();

}

void Destroy3DRect()
{
	delete ptheRect;
}

bool GetInterfaceFrom3DRect(INTERFACEID iid, void ** iFacePtr)
{
	if (ptheRect == NULL)
		std::cout << "The 3D rectangle is not created yet" << std::endl;

	if (iid == IDRAW)
	{
		*iFacePtr = (IDraw *) ptheRect;
		return true;
	}
	if (iid == ISHAPEEDIT)
	{
		*iFacePtr = (IShapeEdit *)ptheRect;
		return true;
	}

	std::cout << "Interface not supported " << iid << std::endl;
	return false;
}