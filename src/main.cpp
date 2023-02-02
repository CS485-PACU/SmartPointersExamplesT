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

//***************************************************************************
// Function:    acceptUniquePtr
//
// Description: Accept a unique_ptr as an argument
//
// Parameters:  rpData - the unique_ptr, passed by reference
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
void acceptUniquePtr(std::unique_ptr<bigData> &rpData)
{
  std::cout << "acceptUniquePtr: " << *rpData << std::endl;
  std::cout << std::endl;
}

//***************************************************************************
// Function:    acceptSharedPtr
//
// Description: Accept a shared_ptr as an argument
//
// Parameters:  pData - the shared_ptr
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
void acceptSharedPtr(std::shared_ptr<bigData> cData)
{
  std::cout << "acceptSharedPtr: " << *cData << std::endl;
  std::cout << std::endl;
}

//***************************************************************************
// Function:    callFunctionsWithPointers
//
// Description: Demonstrate the use of smart pointers with function calls
//
// Parameters:  None
//
// Returned:    A shared_ptr
//***************************************************************************
std::shared_ptr<bigData> callFunctionsWithPointers()
{
  auto pUniquePtr = std::make_unique<bigData>(100);
  auto pSharedPtr = std::make_shared<bigData>(101);

  acceptUniquePtr(pUniquePtr);
  acceptSharedPtr(pSharedPtr);

  return pSharedPtr;
}


//***************************************************************************
// Function:    main
//
// Description: Demonstrate the use of smart pointers.
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{


  std::cout << "Call useUniquePtrs" << std::endl;

  useUniquePtrs();

  std::cout << "return from useUniquePtrs" << std::endl;

  std::cout << "Call useSharedPtrs" << std::endl;

  useSharedPtrs();

  std::cout << "return from useSharedPtrs" << std::endl;

  auto pSharedPtr  = callFunctionsWithPointers();

  std::cout << "Returned Shared Pointer: " << *pSharedPtr;
  std::cout << std::endl << std::endl;

  pSharedPtr = nullptr;

	bigData *pNormalPtr;

	pNormalPtr = new bigData (1);

	std::cout << *pNormalPtr << std::endl;

	//*pNormalPtr = 3;

	//std::cout << *pNormalPtr << std::endl;

	delete pNormalPtr; // lack of delete causes a memory leak!

	return EXIT_SUCCESS;
}