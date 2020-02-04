#ifndef CompositionH
#define CompositionH
//============================================================================
/// \file   Composition.h
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Declaration of CComposition
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "Derived.h"


//===========================================================================
class CComposition
{
public:
	CComposition();
	friend bool operator==(const CComposition& l, const CComposition& r);

	void setDerivedPtr(CDerived* Value);
	void setBasePtr(CBase* Value);
	CDerived* derivedPtr();
	CBase* basePtr();

protected:
	class PrivateImpl;
	jbcoe::polymorphic_value<CComposition::PrivateImpl> d_ptr;

private:
	PIMPL_DECLARE_PRIVATE(CComposition);
};

//---------------------------------------------------------------------------
#endif // CompositionH
