//============================================================================
/// \file   Composition.cpp
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Implementation of CComposition
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "Composition.h"

using namespace jbcoe;

class CComposition::PrivateImpl
{
public:
	polymorphic_value<CBase> DerivedPtr;
	polymorphic_value<CBase> BasePtr;
};


CComposition::CComposition()
	: d_ptr(make_polymorphic_value<CComposition::PrivateImpl>())
{

}


void CComposition::setDerivedPtr(CDerived* Value)
{
	PIMPL_D(CComposition);
	d->DerivedPtr = polymorphic_value<CBase>(Value);
}


void CComposition::setBasePtr(CBase* Value)
{
	PIMPL_D(CComposition);
	d->BasePtr = polymorphic_value<CBase>(Value);
}

CDerived* CComposition::derivedPtr()
{
	PIMPL_D(CComposition);
	return static_cast<CDerived*>(&*d->DerivedPtr);
}

CBase* CComposition::basePtr()
{
	PIMPL_D(CComposition);
	return &*d->BasePtr;
}

bool operator==(const CComposition& l, const CComposition& r)
{
	auto lpriv = l.d_func();
	auto rpriv = r.d_func();
	return *lpriv->BasePtr == *rpriv->BasePtr
		&& *lpriv->DerivedPtr == *rpriv->DerivedPtr;
}


//---------------------------------------------------------------------------
// EOF Composition.cpp
