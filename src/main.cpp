//***************************************************************************
// File name:  main.cpp
// Author:     Chadd Williams
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Example
// Purpose:    Demonstrate dynamic memory, pointers, const, nullptr
//***************************************************************************


#include <iostream>
#include <memory>
#include "BigData.h"

//***************************************************************************
// Function:    useUniquePtrs
//
// Description: Demonstrate the use of unique_ptr.
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void useUniquePtrs()
{
	// unique_ptr
	std::unique_ptr<bigData> pBigData(new bigData(40));
  auto pBigDataAgain(std::make_unique<bigData>(41));
	// auto pBigDataAgain = std::make_unique<bigData>(41);

  pBigData = std::make_unique<bigData>(42);

	std::cout << *pBigData << std::endl;

	std::cout << *pBigDataAgain << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	*pBigData = 1;

	std::cout << *pBigData << std::endl;

	std::cout << *pBigDataAgain << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
}

//***************************************************************************
// Function:    useSharedPtrs
//
// Description: Demonstrate the use of shared_ptr.
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void useSharedPtrs()
{
	// shared_ptr
	std::shared_ptr<bigData> pBigDataShared(new bigData(7));

	auto pBigDataSecondShared = pBigDataShared;
	auto pBigDataSharedAgain (std::make_shared<bigData> (41));


	std::cout << *pBigDataShared << std::endl;

	std::cout << *pBigDataSecondShared << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	*pBigDataShared = 9;

	std::cout << *pBigDataShared << std::endl;

	std::cout << *pBigDataSecondShared << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	pBigDataSecondShared = nullptr;
	std::cout << *pBigDataShared << std::endl;
	pBigDataShared = std::make_shared<bigData>(8);

	std::cout << std::endl;

	std::cout << "Just set both shared pointers to new values";

	std::cout << std::endl;

	std::cout << *pBigDataShared << std::endl;

	std::cout << std::endl;

}

int main()
{


  std::cout << "Call useUniquePtrs" << std::endl;

  useUniquePtrs();

  std::cout << "return from useUniquePtrs" << std::endl;

  std::cout << "Call useSharedPtrs" << std::endl;

  useSharedPtrs();

  std::cout << "return from useSharedPtrs" << std::endl;


	bigData *pNormalPtr;

	pNormalPtr = new bigData (1);

	std::cout << *pNormalPtr << std::endl;

	//*pNormalPtr = 3;

	//std::cout << *pNormalPtr << std::endl;

	delete pNormalPtr; // lack of delete causes a memory leak!

	return EXIT_SUCCESS;
}