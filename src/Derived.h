#ifndef DerivedH
#define DerivedH
//============================================================================
/// \file   Derived.h
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Declaration of CDerived
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "Base.h"


//===========================================================================
class CDerived : public CBase
{
public:
	CDerived();

	double derivedDoubleValue() const;
	void setDerivedDoubleValue(double Value);

	virtual bool equals(const CBase& r) const override;
	friend bool operator==(const CDerived& l, const CDerived& r);

private:
	class Private;
	PIMPL_DECLARE_PRIVATE(CDerived);
};

//---------------------------------------------------------------------------
#endif // DerivedH
