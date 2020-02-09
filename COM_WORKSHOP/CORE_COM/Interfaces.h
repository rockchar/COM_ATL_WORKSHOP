#pragma once
#include<wtypes.h>
/**********************************************************************************************
DEFINING COM INTERFACES USING STANDARD COM MACROS

When programming to write COM interfaces and starting COM development, we can start directly
by using straight C++ and define a COM interface using the CLASS, STRUCT or INTERFACE keywords.

However, these interfaces will be less robust than the same interfaces defined by using the 
standard COM MACROS provided to us by the COM framework.

We will see how IDL generates the COM interfaces in C++. For the time being we will make use of 
the COM macros directly.
************************************************************************************************/

interface IDraw :public IUnknown {
	//brings in pure virtual definintions of AddRef(), QueryInterface(REFIID riid, void ** ppv) 
	//and Release();
	virtual void Draw() PURE;
};

//now lets derive a class from IDRAW

class CoHexagon :public IDraw {
	//constructor and destructor
public:
	CoHexagon();
	~CoHexagon();
	ULONG AddRef();
	ULONG Release();
	HRESULT QueryInterface(const REFIID riid, void ** ppv);
private:
	ULONG m_refCount;
};