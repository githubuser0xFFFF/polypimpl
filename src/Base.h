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
class CBase
{
protected:
	class Private;
	using BasePrivatePtr = jbcoe::polymorphic_value<CBase::Private>;

public:
	CBase(BasePrivatePtr _priv = BasePrivatePtr());
	virtual ~CBase() {}

	int baseIntValue() const;
	void setBaseIntValue(int Value);

	virtual bool equals(const CBase& r) const;
	friend bool operator==(const CBase& l, const CBase& r);

protected:
	jbcoe::polymorphic_value<CBase::Private> d_ptr;

private:
	PIMPL_DECLARE_PRIVATE(CBase);
};

//---------------------------------------------------------------------------
#endif // BaseH
