//============================================================================
/// \file   Base.cpp
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Implementation of CBase
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "Base.h"
#include "Base_p.h"

using namespace jbcoe;

PIMPL_IMPLEMENT_BASE(CBase);


CBase::CBase(BasePrivatePtr _priv)
	: d_ptr(_priv ? _priv : make_polymorphic_value<CBase::PrivateImpl>(this))
{

}


int CBase::baseIntValue() const
{
	PIMPL_D(const CBase);
	return d->BaseIntValue;
}


void CBase::setBaseIntValue(int Value)
{
	PIMPL_D(CBase);
	d->BaseIntValue = Value;
}


bool CBase::equals(const CBase& r) const
{
	PIMPL_D(const CBase);
	return d->BaseIntValue == r.d_func()->BaseIntValue;
}


bool operator==(const CBase& l, const CBase& r)
{
	return l.equals(r);
}


CBase* CBase::q_ptr() const
{
	PIMPL_D(const CBase);
	return d->q_ptr;
}


//---------------------------------------------------------------------------
// EOF Base.cpp
