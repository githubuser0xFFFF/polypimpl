#ifndef poly_pimplH
#define poly_pimplH
//============================================================================
/// \file   poly_pimpl.h
/// \author Uwe Kindler
/// \date   27.01.2020
/// \brief  Declaration of some convenience macros for pimpl
//============================================================================


//============================================================================
//                                   INCLUDES
//============================================================================
#include "polymorphic_value.h"

#define PIMPL_DECLARE_PRIVATE(Class) \
    inline Class::Private* d_func() { return reinterpret_cast<Class::Private *>(&*d_ptr); } \
    inline const Class::Private* d_func() const { return reinterpret_cast<const Class::Private *>(&*d_ptr); } \
    friend class Class::Private;

#define PIMPL_DECLARE_PUBLIC(Class)                                    \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define PIMPL_D(Class) Class::Private * const d = d_func()
#define PIMPL_Q(Class) Class * const q = q_func()


//---------------------------------------------------------------------------
#endif // poly_pimplH
