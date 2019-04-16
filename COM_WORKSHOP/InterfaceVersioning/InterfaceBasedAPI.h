#include"InterfaceDefinitions.h"




/**************************** |NOTE| ***********************************

In this section we will examine how we migh provide functionality to work 
with classes supporting multiple interfaces and develop our own custom API 
to create and extract interface pointers from C3DRect object already defined 
in InterfaceDefinitions.h 


In "Real COM" the API we use is collectively called the COM library, and 
our API provides a similar, but extemely limited functionality. We will 
need to contend with the following:

	- A client needs to be able to create a C3DRect object.
	- A client must be able to ask for access to given interface on the
	  object.
	- A client must be able to destroy the object when finished.

************************************************************************/

C3DRect * ptheRect = NULL;

void CreateThe3Drect()
{
	ptheRect = new C3DRect();
}

/*************************************************************************
The destroy 3D rect function simply deallocates the memory acquired from the
CreateThe3DRect() call.
**************************************************************************/

//custom API to destroy a valid Object
void DestroyThe3DRect()
{
	if (ptheRect)
		delete ptheRect;
}


/***************************************************************************
Till now everything is Okay. A client can Activate and deactivate the C3DRect
object withe the above two functions, part of our 3DRect API.
****************************************************************************/

void MainFunction()
{
	//activate the Rect
	CreateThe3Drect();
	//Terminate the Rect
	DestroyThe3DRect();
}


/******************************************************************************
IDENTIFYING INTERFACES:





********************************************************************************/