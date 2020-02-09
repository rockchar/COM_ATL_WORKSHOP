#pragma once
#include<wtypes.h>

enum FILLTYPE {
	HATCH = 0,
	SOLID = 1,
	POLKADOT = 2
};

#if _COMCOMPLIANT
/*************************************************************************************************************************
When defining COM interfaces using the set of macros, we do have some other helper items defined in <objbase.h>:

// Additional, but not core, COM macros.
#define PURE   = 0
#define DECLARE_INTERFACE(iface)  interface iface
#define DECLARE_INTERFACE_(iface, baseiface)  interface iface : public baseiface
The PURE macro evaluates to the =0 suffix of a pure virtual function definition. The DECLARE_INTERFACE variations 
allow you to send in interface names and any base interface as parameters. These macros are not necessary, but can help streamline interface definitions. Here would be a final variation of IShapeEdit using these optional macros:

// A very COM compliant interface definition.
DECLARE_INTERFACE_(IShapeEdit, IUnknown)
{
	 STDMETHOD(Fill) (FILLTYPE fType) PURE;
	 STDMETHOD(Inverse) () PURE;
	 STDMETHOD(Stretch) (int factor) PURE;
};
With the above interface definition, we can rest assured that the macros expand correctly on a given platform. 
This is becoming more and more important, as COM is being ported to many flavors of UNIX, IBM variations, and so forth. 
If you write COM interface definitions in C++, get in the habit of learning these macros and sticking to them. 
Better yet, use IDL and let the MIDL compiler add them for you automatically
*************************************************************************************************************************/

// A very COM compliant interface definition.
DECLARE_INTERFACE_(IShapeEdit, IUnknown)
{
	STDMETHOD(Fill) (FILLTYPE fType) PURE;
	STDMETHOD(Inverse) () PURE;
	STDMETHOD(Stretch) (int factor) PURE;
};

DECLARE_INTERFACE_(IDraw, IUnknown)
{
	STDMETHOD(Draw)() PURE;
};

#elif

/*
When we are developing COM interfaces, we use the STDMETHOD or STDMETHOD_ macros.

1. If our interface returns HRESULT,use the STDMETHOD macro. The STDMETHOD macro has only one parameter and it is the name
   of the method. Here is the expansion of the STDMEMTHOD macro in win32.

		#define STDMETHOD (methodname) virtual HRESULT STDMETHODCALLTYPE methodname.

2. If our interface returns anything other than HRESULT( including void) then use STDMETHOD_ macro. This has two parameters
   - return type
   - method name
   Here is the expansion of the STDMETHOD_ macro in Win32

		#define STDMETHOD_ (type,methodname) virtual type STDMETHODCALLTYPE methodname

NOTE: Notice that these two macros also make use of another macro called STDMETHODCALLTYPE which is simply translated
as:

		#define STDMETHODCALLTYPE _stdcall
*/

//now lets rewrite the IShapeEdit interface, this time using the correct COM macros

//IShapeEdit using the COM macros
interface IShapeEdit :public IUnknown {
	STDMETHOD_(void, Fill)(FILLTYPE fType) PURE;
	STDMETHOD_(void, Inverse)() PURE;
	STDMETHOD_(void, Stretch)(int factor) PURE;

};

//But to be more COM compliant we must return HRESULT so we will use STDMETHOD
interface IShapeEdit :public IUnknown {
	STDMETHOD(Fill)(FILLTYPE fType) PURE;
	STDMETHOD(Inverse)() PURE;
	STDMETHOD(Stretch)(int nFactor) PURE;
};

#endif