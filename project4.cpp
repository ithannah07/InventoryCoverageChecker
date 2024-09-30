//=======================================================================================================
//  Hyeonseo Lee
//  Sep 27, 2024
//  project4.cpp
//  The program reads two files and stores their contents in arrayA and arrayB. The first number in each file indicates the array size, and the remaining numbers are the contents. It then checks if all the numbers in arrayA appear in arrayB, accounting for duplicates. If any numbers in arrayA are missing or the duplicates don’t match, the program outputs “does not satisfy.” Otherwise, it prints “satisfies.”
//=======================================================================================================
#include <iostream>
#include <fstream>
using namespace std;

//=======================================================================================================
//  selectionSort
//  This function sorts the array by using selection sort method. During each iteration, it finds the smallest number in the unsorted portion of the array and swaps it with the current position. This process repeats until the array is fully sorted.
//  Parameters:
//    array[]: an array of n integers. Values in the array are all > 0.
//    size: the size of the array where size > 0.
//  Return Value:
//    The array that is sorted
//=======================================================================================================
void selectionSort (int array[], int size);

//=======================================================================================================
//  coversNeeds
//  This function checks and compares each element of arrayA with those in arrayB. If arrayB contains all the values from arrayA, the function will return true
//  Parameters:
//    arrayA[]: an array of n integers. Values in the array are all > 0. It contains "Needs."
//    sizeA: the size of the arrayA where sizeA > 0.
//    arrayB[]: an array of n integers. Values in the array are all > 0. It contains "Inventory."
//    sizeB: the size of the arrayB where sizeB > 0.
//  Return Value:
//    It will return true if arrayB contains all the values from arrayA, otherwise, it will return false.
//=======================================================================================================
bool coversNeeds (int arrayA[], int sizeA, int arrayB[], int sizeB);

//=======================================================================================================
//  printResult
//  This function prints the result of coversNeeds function.
//  Parameters:
//    result: the result(true or false) of the coversNeeds function
//=======================================================================================================
void printResult (bool result);

int main()
{
  ifstream inputFileA;
  ifstream inputFileB;
  
  inputFileA.open("test1a.txt");
  inputFileB.open("test1b.txt");
  
  int sizeA = 0;
  int numA = 0;
  inputFileA >> sizeA;
  if (sizeA <= 0)
  {
    cout << "Error occurred. The size of the arrayA is invalid." << endl;
    return 1;
  }
  int arrayA[sizeA];
  for (int count = 0; count < sizeA; count++ )
  {
    inputFileA >> numA;
    arrayA[count] = numA;
  }
  
  int sizeB = 0;
  int numB = 0;
  inputFileB >> sizeB;
  if (sizeB <= 0)
  {
    cout << "Error occurred. The size of the arrayB is invalid." << endl;
    return 1;
  }
  int arrayB[sizeB];
  for (int count = 0; count < sizeB; count++ )
  {
    inputFileB >> numB;
    arrayB[count] = numB;
  }
  
  bool result = false;
  result = coversNeeds(arrayA, sizeA, arrayB, sizeB);
  
  printResult(result);
  
  inputFileA.close();
  inputFileB.close();


  return 0;
}

  
void selectionSort (int array[], int size)
{
  int minIndex;
  int minValue;
  
  for (int start = 0; start < (size - 1); start++)
  {
    minIndex = start;
    minValue = array[start];
    for (int index = start + 1; index < size; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }
    }
    swap(array[minIndex], array[start]);
  }
}

bool coversNeeds (int arrayA[], int sizeA, int arrayB[], int sizeB)
{
  // two position markers
  int posA = 0;
  int posB = 0;
  bool result = false;
  
  if (sizeA > sizeB)
  {
    cout << "The size of the arrayA is larger than the arrayB." << endl;
    return result;
  }
  selectionSort(arrayA, sizeA);
  selectionSort(arrayB, sizeB);

  while (posA < sizeA && posB < sizeB)
  {
    if (arrayA[posA] == arrayB[posB]) // 같은 포지션에 있는데, 두개의 값이 같을 때 | If there in the same position, and both of values are same
    {
      posA++;
      posB++;
    }
    else if (arrayA[posA] > arrayB[posB]) // A에 있는 값이 더 클때, B 포지션만 다음걸로 넘김 | If the value of posA is larger than the value of posB
    {
      posB++;
    }
    else
    {
      result = false;
      return result;
    }
  }
  if (posA == sizeA)
  {
    result = true;
  }
  return result;
  
}

void printResult (bool result)
{
  if (result)
  {
    cout << "satisfies" << endl;
  }
  else
  {
    cout << "does not satisfy" << endl;
  }
}
