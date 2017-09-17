#ifndef ARRAYFUNCTIONS1_H
#define ARRAYFUNCTIONS1_H
#include <iostream>
#include <iomanip>
#include <cstdlib>

namespace Array
{

//--------------ABBREVIATIONS---------------------//
/*
pArr           - pointer to array
SIZE           - array size
iSymbolWidth   - width of symbols in showing order for leveling for each array element
cSpaceSymbol   - symbol, that will be used as spacing symboll between two array elements
iDivider       - divider as used as upper threshold for pseudo-random numbers  generation
Key            - searching key
iMax           - maximum index of searching (size of array as well)
iMin           - minimum index of seearching (0 as well)
(*pOrder)(T,T) - ASC or DESC
*/
//--------------MANIPULATION FUNCTIONS------------//

/*
This functions used for manipulating order of 
sorting in sorting functions as logic eqiuation 
return value result
*/

//Ascending order
template <typename T>
bool ASC(T a1, T a2)
{
  if(a1 < a2) return true;
  else        return false;
}

//Descending order
template <typename T>
bool DESC(T a1, T a2)
{
    if(a1 > a2) return true;
    else        return false;
}

//-------------SHOW AND FILLING FUNCTION--------------//

//function, that show input array
template <typename T>
void Show(const T *pArr,const int SIZE,unsigned int iSymbolWidth,char cSpaceSymbol)
{
  for(int i=0;i<SIZE;++i)
    {
        std::cout<<std::setw(iSymbolWidth)<<pArr[i]<<cSpaceSymbol;
    }
}

//function: pseudo-randow fill the input array
template <typename T>
void Random(T *pArr,const int SIZE, int iDivider)
{
  static bool isFirstCall = true;

  std::cout<<"Template"<<std::endl;

  //prevent reusing same rand sequence
  if(isFirstCall)
    srand((unsigned int)time(0));

  isFirstCall = false;

  for(int i=0;i<SIZE;++i)
    {
      pArr[i] = rand()%iDivider;
    }
}

//function: rand() overload function for double values
void Random(double *pArr,const int SIZE, int iDivider)
{
  static bool isFirstCall = true;

  std::cout<<"Non-Template-Double"<<std::endl;

  //prevent reusing same rand sequence
  if(isFirstCall)
    srand((unsigned int)time(0));

  isFirstCall = false;

  for(int i=0;i<SIZE;++i)
    {
      pArr[i] = rand()%iDivider + double(rand()/iDivider);
      //check pseudo-random number and it decreasing in case when it great than iDivider
      if(pArr[i]>iDivider) pArr[i] = pArr[i] - iDivider;
    }

}

//function: rand() overload function for float values
void Random(float *pArr,const int SIZE, int iDivider)
{
  static bool isFirstCall = true;

  std::cout<<"Non-Template-Float"<<std::endl;

  //prevent reusing same rand sequence
  if(isFirstCall)
    srand((unsigned int)time(0));

  isFirstCall = false;

  for(int i=0;i<SIZE;++i)
    {
      pArr[i] = rand()%iDivider + float(rand()/iDivider);
      //check pseudo-random number and it decreasing in case when it great than iDivider
      if(pArr[i]>iDivider) pArr[i] = pArr[i] - iDivider;
    }

}

//----------------SEARCH FUNCTIONS-------------------//
//function: binary search algorithm on input array, returns position of key in the array
template <typename T>
int BinarySeacrch(T Key,T * pArr,unsigned int iMax,unsigned int iMin)
{
  unsigned int iMiddle = ( iMax + iMin ) / 2;

  if(iMin + 1 == iMax)
    {

      if(Key == pArr[iMax])
        return iMax;
      else if(Key == pArr[iMin])
        return iMin;
      else
        return -1;
    }
  else if (Key == pArr[iMiddle])
    return iMiddle;

  else if(Key <= pArr[iMiddle])
    return BinarySeacrch(Key,pArr,iMiddle,iMin);

  else if(Key >= pArr[iMiddle])
    return BinarySeacrch(Key,pArr,iMax,iMiddle);

}

//-----------------SORTING FUNCTIONS-----------------------//


//function: bubble sort algorithm on input array
template <typename T>
void BubbleSort (T *pArr,const int SIZE, bool (*pOrder)(T,T))
{
  T Temp; //temporary variable

  for(int i=0;i<SIZE-1;++i)
    for(int j=0;j<SIZE-1;++j)
      if(pOrder(pArr[j+1],pArr[j])) //use manipulation functions for order manipulation by pointer
        {
          Temp = pArr[j+1];
          pArr[j+1] = pArr[j];
          pArr[j] = Temp;
        }
}

//function: optimized bubble sort algorithm on input array
template <typename T>
void BubbleSortOptimized (T *pArr,const int SIZE,bool (*pOrder)(T,T))
{
T Temp; //temporary variable

//ascending order
for(int i=0;i<SIZE-1;++i)
  for(int j=0;j<SIZE-1-i;++j)
    if(pOrder(pArr[j+1],pArr[j]))
      {
        Temp = pArr[j+1];
        pArr[j+1] = pArr[j];
        pArr[j] = Temp;
      }
}


//function: selection sort algorithm on input array
template <typename T>
void SelectionSort(T * pArr,const unsigned int SIZE, bool (*pOrder)(T,T))
{
  T nMin;
  unsigned int iMinIndex;
  for(int i=0;i<SIZE;++i)
    {
      nMin = pArr[i];
      iMinIndex = i;
      for(int j = i+1;j < SIZE;++j)
        {
          if(pOrder(pArr[j],pArr[iMinIndex])) //use manipulation functions for order manipulation by pointer
            {
              iMinIndex = j;
            }
        }
      pArr[i] = pArr[iMinIndex];
      pArr[iMinIndex] = nMin;
    }
}

} //End of array namespace

#endif // ARRAYFUNCTIONS1_H
