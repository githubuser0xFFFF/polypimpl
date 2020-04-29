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

/**
 * Use this macro to declare the private data class in your public class
 * \code
 *  class CDerived : public CBase
	{
	public:
		CDerived();

	private:
		class PrivateImpl;
		PIMPL_DECLARE_PRIVATE(CDerived);
	};
 * \endcode
 */
#define PIMPL_DECLARE_PRIVATE(Class) \
    inline Class::PrivateImpl* d_func() { return reinterpret_cast<Class::PrivateImpl *>(&*d_ptr); } \
    inline const Class::PrivateImpl* d_func() const { return reinterpret_cast<const Class::PrivateImpl *>(&*d_ptr); } \
    friend class Class::PrivateImpl;


/**
 * Use this macro to declare the public interface class in your private
 * implementation
 * \code
	class CDerived::PrivateImpl : public CBase::PrivateImpl
	{
	private:
		PIMPL_DECLARE_PUBLIC(CDerived);

	public:
		PrivateImpl(CDerived* q) : CBase::PrivateImpl(q) {}
	};
 * \endcode
 */
#define PIMPL_DECLARE_PUBLIC(Class)                                \
    inline Class* q_func() { return static_cast<Class *>(q_ptr); } \
    inline const Class* q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;


/**
 * Use this macro in your base class declaration to provide all required
 * constructors and operators for proper copy of q_ptr of private data class
 * \code
	class CBase
	{
	protected:
		class PrivateImpl;
		using BasePrivatePtr = Usl::polymorphic_value<CBase::PrivateImpl>;

	public:
		PIMPL_DECLARE_BASE(CBase);

		CBase(BasePrivatePtr _priv = BasePrivatePtr());
		virtual ~CBase() {}

	protected:
		Usl::polymorphic_value<CBase::PrivateImpl> d_ptr;

	private:
		PIMPL_DECLARE_PRIVATE(CBase);
	};
 * \endcode
 */
#define PIMPL_DECLARE_BASE(Class) \
	Class(const Class& Other); \
	Class(Class&& Other);  \
	Class& operator=(const Class& other); \
	Class& operator=(Class&& other);


/**
 * Use this macro in the source file of your class implementation to
 * provide the implementation for the required copy constructors and assignment
 * operators. Just add the following line to your source file
 * \code
 * PIMPL_IMPLEMENT_BASE(CBase);
 * \endcode
 */
#define PIMPL_IMPLEMENT_BASE(Class) \
	Class::Class(const Class& Other) : d_ptr(Other.d_ptr) {d_ptr->q_ptr = this;} \
	Class::Class(Class&& Other) : d_ptr(std::move(Other.d_ptr)) {d_ptr->q_ptr = this;} \
	Class& Class::operator=(const Class& other) { \
		d_ptr = other.d_ptr; d_ptr->q_ptr = this; return *this;} \
	Class& Class::operator=(Class&& other)	{ \
		d_ptr = std::move(other.d_ptr); d_ptr->q_ptr = this; return *this;}


#define PIMPL_D(Class) Class::PrivateImpl * const d = d_func()
#define PIMPL_Q(Class) Class * const q = q_func()


//---------------------------------------------------------------------------
#endif // poly_pimplH
