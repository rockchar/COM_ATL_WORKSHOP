#pragma once
#include <iostream>
#include "C3DRect.h"
/*
The problem with global variables is that since every function has access to these, it becomes increasingly hard 
to figure out which functions actually read and write these variables.

To understand how the application works, you pretty much have to take into account every function which modifies the global state. 
That can be done, but as the application grows it will get harder to the point of being virtually impossible (or at least a complete waste of time).

If you don't rely on global variables, you can pass state around between different functions as needed. 
That way you stand a much better chance of understanding what each function does, as you don't need to take the global state into account.

Using a single global pointer as in this case that is managed by this file is OK
*/
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