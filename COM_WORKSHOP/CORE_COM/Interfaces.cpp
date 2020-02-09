#include "Interfaces.h"

CoHexagon::CoHexagon()
{
	m_refCount = NULL;
}

CoHexagon::~CoHexagon()
{
}

ULONG CoHexagon::AddRef()
{
	return InterlockedIncrement(&m_refCount);
}

ULONG CoHexagon::Release()
{
	InterlockedDecrement(&m_refCount);
	//check if we lost our final connection to the object
	if (m_refCount == 0)
	{
		//remove the coclass from the memory
		delete this;
		return 0;
	}
	return m_refCount;
}

HRESULT CoHexagon::QueryInterface(const REFIID riid, void ** ppv)
{
	return E_NOTIMPL;
}

/******************************************************************************************
// QueryInterface() is implemented by each and every coclass, and provides
// a way to return an interface pointer to the client.
HRESULT CoHexagon::QueryInterface(REFIID riid, void** ppv)
{
	 // Which interface does the client want?
	 if(riid == IID_IUnknown)          // Human readable version of GUID
		  *ppv = (IUnknown*)this;
	 else if(riid == IID_IDraw)
		  *ppv = (IDraw*)this;         // Generalized "*ppv = (IDraw*)theRect"
	 if(*ppv)                          // Did we have the IID?
	 {
		  // Must call AddRef() if we hand out an interface.
		  ((IUnknown*)(*ppv))->AddRef();
		  return S_OK;
	 }
	 *ppv = NULL;           // NULL pointer if we do not have the interface.
	 return E_NOINTERFACE;  // Standard return if we don't support the IID.
}

Note  Recall every standard interface already has a GUID assigned to it. As well, every standard interface has a 
human readable constant, using the IID_ prefix convention (for example, IID_IUnknown, IID_IMalloc, IID_IClassFactory, 
and so on).


Implementing QueryInterface(), like maintaining an object reference count, is also a very mechanical process. 
Basically, each interface supported on the object requires an additional two lines of code:

// Each interface supported by a COM object entails these two lines of code.
if(riid == interface ID)                    // If you want this...
	 *ppv = (interface name*)this;          //...you get this.
When implementing QI, remember the basics of reference counting: If an object hands off an interface pointer to the client
, the object must AddRef() itself. Every implementation of QI will have code the equivalent of the following after all 
IIDs have been checked (if we do not support the IID, return E_NOINTERFACE):

// Be sure to AddRef() the object if you have found the requested interface.
if(*ppv)
{
	 ((IUnknown*)(*ppv))->AddRef();     // We have another active client.
	 return S_OK;          // Informs the client we supported the requested IID.
}

__________________________________________________________________________________________________________________________

Implementing QueryInterface() Using static_cast<>
As an alternative to traditional C++ casting, you may find other implementations of QueryInterface() making use of static_cast<>. One advantage of this approach is that compile-time errors will be generated if an illegal cast is attempted. Functionally, however, each approach yields the same result: returning a portion of the object to the interested client (i.e., casting the this pointer).

If we were to rewrite CoHexagon's QueryInterface() implementation using static_cast<>, we would see the following:

// QueryInterface() à la static_cast<>
HRESULT CoHexagon::QueryInterface(REFIID riid, void** ppv)
{
	 if(riid == IID_IUnknown)
		  *ppv = static_cast<IUnknown*>(this);
	 else if(riid == IID_IDraw)
		  *ppv = static_cast<IDraw*>(this);
	 if(*ppv)
	 {
		  ((IUnknown*)(*ppv))->AddRef();
		  return S_OK;
	 }
	 *ppv = NULL;
	 return E_NOINTERFACE;
}

*************************************************************************************************************************/