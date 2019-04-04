//versioning published interfaces
/* once an interface is published we cannot change it in any way. But what is a good path foreward for extending the interfaces.
The standard way to extend an interface is to derive a new interface from an existing one. This technique is called interface inheritance.

*/

#include <Windows.h>

interface IDraw{

	virtual void Draw() = 0;

};

//lets create a class that makes a 3D rectangle
// step 1
/*class C3DRect : public IDraw{
public:
	//No longer pure virtual.It is mandatory to implement it now or we cannot create an instance of the class.Linker error.
	void Draw();
private:
	//any data points or private helper functions

	//the C3DRect class may need to draw itself
};
*/

//Step2
//Let us create a class called ISahepeEdit which provides use behaviour to modify an existing shape
enum FILLTYPE { HATCH = 0 , SOLID = 1 , POLKADOT = 2 };

interface IShapeEdit{
	virtual void Fill(FILLTYPE afType) = 0; //Solid, hatch or polkadots.
	virtual void Inverse() = 0;             //method to inverse color.
	virtual void Stretch(int factor) = 0;   //method to stretch the shape by a factor.
};

/**************************** NOTES **********************************
The above interface allows a the object user to manipulate an existing 
shape in a number of ways. If we extend the functionality of C3DRect to
support the IShapeEdit interface, we have now changed the physical 
layout of the vTables. Using the standard multiple inherutance,we may modify
the class definition to support IDraw and IshapeEdit. 
*********************************************************************/

class C3DRect :public IDraw, public IShapeEdit{

public:
	//IDraw interface methods
	void Draw();
	//IShapeEdit interface methods
	void Fill(FILLTYPE afType);
	void Inverse();
	void Stretch(int factor);
private:
	//state data used to give life to interface methods

};

/****************** C3DRect now has the following layout ************************
________________________________________________________________________________
|C3DRect|

|IDRaw(VPTR)| ----------------------->|&Draw|-------------------->|Draw(){}|

|IShapeEdit(VPTR)|------------------->|&Fill|-------------------->|Fill(){}|
                                      |
				                      |&Inverse|----------------->|Inverse(){}|
				                      |
				                      |&Stretch|----------------->|Stretch(int)|
________________________________________________________________________________

**********************************************************************************/


////// versioning published inerfaces

/*********************************** NOTES ***************************************
Once an interface is published, we cannot change it in anyway. Interfaces define a 
contract. In interface-based programming the contract revolves around the 
Object User( referred as client ) and the object itself ( often called the co-class in
COM lingo.
The interface contract is fairly simple, the object itself agrees to the following 
"once an object supports a given interface,the object in question must continue to 
support the interface without modification(e.g. you canot chane the names or parameter 
sets of the methods,you cant reorder the methods, canot rename the interface itself.
Te client also agrees to the following in the same contract:
As a client i will abide by the calling conventions as set forth by the interfaces and 
methods contained within them. 
**********************************************************************************/