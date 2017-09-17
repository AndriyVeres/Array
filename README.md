# Some usefull functions for working with arrays

### namespace _Array_

### ABBREVIATIONS

_pArr_   - pointer to array

_SIZE_   - array size

_iSymbolWidth_   - width of symbols in showing order for leveling for each array element

_cSpaceSymbol_  - symbol, that will be used as spacing symboll between two array elements

_iDivider_      - divider as used as upper threshold for pseudo-random numbers  generation

_Key_            - searching key

_iMax_           - maximum index of searching (size of array as well)

_iMin_           - minimum index of seearching (0 as well)

_ASC_ - ascending order

<<<<<<< HEAD
_DESC_ - descending order

=======
>>>>>>> dad66c1cd4fab0b0405f713f6c4e978dcf01f7a8
### SHOW AND FILLING FUNCTION

**void Show(const T *pArr,const int SIZE,unsigned int iSymbolWidth,char cSpaceSymbol);**

>*function, that show input array*

**void Random(T *pArr,const int SIZE, int iDivider);**

>*function: pseudo-randow fill the input array*

### SEARCH FUNCTIONS

**int BinarySeacrch(T Key,T * pArr,unsigned int iMax,unsigned int iMin);**

>*function: binary search algorithm on input array, return position of Key in the array*

### SORTING FUNCTIONS

**void BubbleSort (T *pArr,const int SIZE, bool (*pOrder)(T,T));**

>*bubble sort algorithm*

**void BubbleSortOptimized (T *pArr,const int SIZE,bool (*pOrder)(T,T));**

>*Optimized bubble sort algorithm*

**void SelectionSort(T * pArr,const unsigned int SIZE, bool (*pOrder)(T,T));**

>*selection sort algorithm*

### EXAMPLE

	#include <iostream>
	#include "Array.hpp"
	
	using namespace std;

	int main()
	{	
    	const int SIZE = 10;                             //size of array
    	int Arr[SIZE];                                   //creating array of int values

    	Array::Random(Arr,SIZE,5);                       //random array filling

    	Array::BubbleSortOptimized(Arr,SIZE,Array::ASC); //Optimized bubble sort in ascending order
    	Array::Show(Arr,SIZE,3,' ');                     //Array show
	
    	return 0;
	}
