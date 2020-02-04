#ifndef BaseH
#define BaseH
//============================================================================
/// \file   Base.h
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Declaration of CBase
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "poly_pimpl.h"


//===========================================================================
/**
 * A base class with a polymorphic private data pointer
 */
class CBase
{
protected:
	class PrivateImpl;
	using BasePrivatePtr = jbcoe::polymorphic_value<CBase::PrivateImpl>;

public:
	CBase(BasePrivatePtr _priv = BasePrivatePtr());
	virtual ~CBase() {}

	int baseIntValue() const;
	void setBaseIntValue(int Value);

	virtual bool equals(const CBase& r) const;
	friend bool operator==(const CBase& l, const CBase& r);

protected:
	jbcoe::polymorphic_value<CBase::PrivateImpl> d_ptr;

private:
	PIMPL_DECLARE_PRIVATE(CBase);
};

//---------------------------------------------------------------------------
#endif // BaseH
