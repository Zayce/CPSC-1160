#include <iostream>
using namespace std;

void selectionSort(double [], int);
int findMax(double[], int listSize, int maxIndex);
void printArray(double[], int arraySize); // function prototype

int main(){
    int arraySize = 7;
    double list[] = {9, 1, 2, 5, 4, 8, 6};
    selectionSort(list, arraySize);

    printArray(list, 7);
    return 0;
}

/**
 * @return max value at each subarrays
 */
void selectionSort(double[] list, int listSize){
    //base case listSize is 1
    if(listSize <= 1){
      return;
    }

    int currentMax = listSize - 1;
    int l = listSize - 2;
    int nextMax = findMax(list, l);
    if (list[currentMax] < list[nextMax]){
      double temp = list[nextMax];
      list[nextMax] = list[currentMax];
      list[currentMax] = temp;
    }
    listSize--;
    selectionSort(list, listSize);

    // Swap list[i] with list[currentMinIndex] if necessary;
    // if (currentMaxIndex != i)
    // {
    //   // list[currentMinIndex] = list[i];
    //   // list[i] = currentMin;
    // }
  // }

    
}

int findMax(double list[], int listSize, int maxIndex){
    if(listSize == 1){
      return list[0];
    }
      // Find the minimum in the list[i..listSize-1]
    int currentMaxIndex = maxIndex;
    double currentMax = list[maxIndex];

  
    listSize--;
    int nextMaxIndex = findMax(list, listSize, maxIndex);
    double nextMax = list[nextMaxIndex];

      if (currentMax < nextMax){
        return nextMaxIndex;
      }
      else{
        return currentMaxIndex;
      }
}

void printArray(double list[], int arraySize)
{
  for (int i = 0; i < arraySize - 1; i++)
  {
    cout << list[i] <<  " ";
  }
}
