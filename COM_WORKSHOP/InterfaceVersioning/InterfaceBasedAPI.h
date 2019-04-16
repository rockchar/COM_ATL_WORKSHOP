#include"InterfaceDefinitions.h"
#include<stdio.h>



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


/***********************************************************************************
IDENTIFYING INTERFACES:
In order for a client to extract a specific interface from the object, we need to 
setup sum further API level support.

We will create a method that is able to return an interface pointer to a client. 
But first we need a way to uniquely identify every possible interface used by our
current application.

1. Approach 1 : Assign a text literal to each interface and perform some sort of
				string comparisons to test which interface pointer to return.

2. Approach 2 : A simpler approach and one taken by COM is to use unique numerical 
                values. Lets use numerical tags and define a custom enumeration called 
				INTERFACEID:

*************************************************************************************/

enum INTERFACEID
{
	//id for Draw
	IDRAW      = 0,
	//id for shape edit
	ISHAPEEDIT = 1,
	// id for draw2
	IDRAW2     = 2,
	//id for draw3
	IDRAW3     = 3
};

/**************************************************************************************
Now we have a way to refer to an interfcae by name in our code, we can create the final
function in our API GetInterfaceFrom3DRect() This function will take two parameters:
The requested interfcae identifier( a value from the INTERFACE ID enum ) and also some 
place in the memory where to store the retrieved.

This will be very handy for the client as it can also use to test the success or the 
failure of the function invocaion.

***************************************************************************************/

bool GetInterfaceFromC3DRect(INTERFACEID iiD, void ** iInterFacePtr)
{
	if (ptheRect == NULL){
		printf("Error you forgot to create the Rectangle");
		return false;
	}

	if (iiD == IDRAW){
			//the client wants an access to IDraw
			*iInterFacePtr = (IDraw *) ptheRect;
			return true;
		}
	if (iiD == ISHAPEEDIT){
		//client wants access to IShape edit
		*iInterFacePtr = (IShapeEdit *)ptheRect;
		return true;

	}

	//the IID does not exist
	*iInterFacePtr = NULL;
	printf("Interface %d not supported",iiD);
	return false;
}