//============================================================================
/// \file   Derived.cpp
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Implementation of CDerived
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "Derived.h"
#include "Derived_p.h"

using namespace jbcoe;




CDerived::CDerived()
	: CBase(make_polymorphic_value<CBase::PrivateImpl, CDerived::PrivateImpl>(this))
{

}


double CDerived::derivedDoubleValue() const
{
	PIMPL_D(const CDerived);
	return d->DerivedDoubleValue;
}


void CDerived::setDerivedDoubleValue(double Value)
{
	PIMPL_D(CDerived);
	d->DerivedDoubleValue = Value;
}


bool CDerived::equals(const CBase& r) const
{
	PIMPL_D(const CDerived);
	auto rpriv = static_cast<const CDerived&>(r).d_func();
	return CBase::equals(r) &&
		d->DerivedDoubleValue == rpriv->DerivedDoubleValue;
}


bool operator==(const CDerived& l, const CDerived& r)
{
	return l.equals(r);
}

//---------------------------------------------------------------------------
// EOF Derived.cpp
