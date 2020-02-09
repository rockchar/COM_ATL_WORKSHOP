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
