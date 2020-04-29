#ifndef Derived_pH
#define Derived_pH
//============================================================================
/// \file   Derived_p.h
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Declaration of 
//============================================================================


//============================================================================
//                                   INCLUDES
//============================================================================
#include "Base_p.h"


class CDerived::PrivateImpl : public CBase::PrivateImpl
{
private:
	PIMPL_DECLARE_PUBLIC(CDerived);

public:
	double DerivedDoubleValue = 2.2;
	PrivateImpl(CDerived* q) : CBase::PrivateImpl(q) {}
};

//---------------------------------------------------------------------------
#endif // Derived_pH
