#include <iostream>

#include "Composition.h"

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"


SCENARIO( "pimpl classes can be copied and assigned", "[pimpl]" )
{
	CBase Base1;
	CBase Base2;
	CDerived Derived1;
	CDerived Derived2;

	GIVEN("A base class")
	{
		WHEN ( "an int value is assigned")
		{
			Base1.setBaseIntValue(10);
			THEN ( "the value is stored")
			{
				REQUIRE(Base1.baseIntValue() == 10);
			}
		}

		WHEN ( "a second base object is copy constructed")
		{
			CBase Base(Base2);
			THEN ( "then the objects are equal")
			{
				REQUIRE(Base1 == Base);
			}
		}
	}

	GIVEN("A second base class")
	{
		WHEN ( "the first base class is assigned")
		{
			Base2 = Base1;
			THEN ( "then the objects are equal")
			{
				REQUIRE(Base1 == Base2);
			}
		}
	}

	GIVEN("Two derived classes")
	{
		Derived1.setBaseIntValue(10);
		Derived1.setDerivedDoubleValue(10.1);
		WHEN ("a second derived object is copy constructed")
		{
			CDerived Derived(Derived1);
			THEN ( "then the objects are equal")
			{
				REQUIRE(Derived1 == Derived);
			}
		}

		WHEN ( "different values are assigned to the classes")
		{
			Derived2.setBaseIntValue(20);
			Derived2.setDerivedDoubleValue(20.2);
			THEN ( "then the objects are not equal")
			{
				REQUIRE_FALSE(Derived1 == Derived2);
			}
		}

		WHEN ( "the same value is assigned to the derived double value")
		{
			Derived2.setDerivedDoubleValue(20.2);
			THEN ( "then the objects are still not equal")
			{
				REQUIRE_FALSE(Derived1 == Derived2);
			}
		}
	}

	GIVEN(" Two composition objects")
	{
		Base1.setBaseIntValue(10);
		Derived1.setBaseIntValue(10);
		Derived1.setDerivedDoubleValue(10.1);
		Derived2.setBaseIntValue(20);
		Derived2.setDerivedDoubleValue(20.2);
		CComposition Composition1;
		CComposition Composition2;

		Composition1.setBasePtr(&Base1);
		Composition1.setDerivedPtr(&Derived1);
		Composition2 = Composition1;

		WHEN ( "values are assigned to base pointer and derived pointer")
		{
			THEN ( "then the stored values are correct")
			{
				REQUIRE(Composition1.basePtr()->baseIntValue() == 10);
				REQUIRE(Composition1.derivedPtr()->derivedDoubleValue() == 10.1);
			}

			THEN ( "the stored derived value is equal to the derived value")
			{
				REQUIRE(*Composition1.derivedPtr() == Derived1);
			}
		}


		WHEN ( "the fist object are assigned to a second object")
		{
			THEN ( "then both object should be equal")
			{
				REQUIRE(Composition2 == Composition1);
			}
		}

		WHEN ("one composition object is changed")
		{
			Composition2.derivedPtr()->setDerivedDoubleValue(30);
			THEN ( "then both object should not be equal")
			{
				REQUIRE_FALSE(Composition2 == Composition1);
			}
		}

	}
}


int main( int argc, char* argv[] )
{
  // global setup...
  int result = Catch::Session().run( argc, argv );

  // global clean-up...
  return result;
}
