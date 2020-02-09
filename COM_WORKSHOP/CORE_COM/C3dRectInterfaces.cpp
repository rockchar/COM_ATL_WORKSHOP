#include "C3dRectInterfaces.h"

CoHexagon::CoHexagon()
{
	//resetting the reference count
	m_referenceCount = 0;
}

CoHexagon::~CoHexagon()
{
}

//add ref will be implemented with STDMETHODIMP_ as it does not return HRESULT
STDMETHODIMP_(ULONG) CoHexagon::AddRef()
{
	return InterlockedIncrement(&m_referenceCount);
}

//Release will be implemented with STDMETHODIMP_ as it does not return HRESULT
STDMETHODIMP_(ULONG) CoHexagon::Release()
{
	//the last connection to this object is no more, hence delete the object.
	if (m_referenceCount == 0)
	{
		delete this;
		return (ULONG)0;
	}
	else
		return InterlockedDecrement(&m_referenceCount);
}

//QueryInterface will be implmented with STDMETHODIMP as it returns HRESULT
STDMETHODIMP CoHexagon::QueryInterface(REFIID IID, void ** ppv)
{
	if (IID == IID_IUnknown)
	{
		/*
		Notice the extra cast for the IUnknown provision. As both IDraw and IShapeEdit derive from IUnknown, we get an ambiguity error if we cast 
		directly to IUnknown*. This extra cast keeps the compiler happy (we could have used any interface supported by the coclass as part of this 
		cast, not just IDraw). All we are doing here is taking some IUnknown- derived interface and sucking out the "IUnknown-ness" from it.
		*/
		*ppv = (IUnknown *)(IDraw*) this;
	}
	else if (IID == IID_IDRAW)
	{
		*ppv = (IDraw*) this;
	}
	else if (IID == IID_ISHAPEEDIT)
	{
		*ppv = (IShapeEdit*) this;
	}

	if (*ppv) {
		((IUnknown*)(*ppv))->AddRef();//NOTE: Always call AddRef() when handing out interfaces
		return S_OK;
	}
	*ppv = NULL;
	return E_NOINTERFACE;//default return
}

STDMETHODIMP_(HRESULT) CoHexagon::Draw()
{
	return S_OK;
}

STDMETHODIMP_(HRESULT) CoHexagon::Fill(FILLTYPE fType)
{
	return S_OK;
}

STDMETHODIMP_(HRESULT) CoHexagon::Inverse()
{
	return S_OK;
}

STDMETHODIMP_(HRESULT) CoHexagon::Stretch(int nFactor)
{
	return S_OK;
}
