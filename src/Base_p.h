#ifndef Base_pH
#define Base_pH
//============================================================================
/// \file   Base_p.h
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Declaration of CBase
//============================================================================

//============================================================================
//                                   INCLUDES
//============================================================================
#include "Base.h"

/**
 * Private data of CBase
 */
class CBase::PrivateImpl
{
protected:
	CBase* q_ptr;

private:
	PIMPL_DECLARE_PUBLIC(CBase);

public:
	int BaseIntValue = 1;
};

//---------------------------------------------------------------------------
#endif // BaseH
