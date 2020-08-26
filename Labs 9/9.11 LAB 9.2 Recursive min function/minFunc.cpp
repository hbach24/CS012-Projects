#include "minFunc.h"

const int * min(const int arr[], int arrSize) {
    const int* tempMin = &(arr[0]);
    
    if(arrSize <= 1)
    {
        return tempMin;
    }

    if(arr[arrSize-1] < *tempMin) 
    {
        return min(arr+1, arrSize - 1);
    }
    else {
        return min(arr, arrSize - 1);
    }
}

 




//  if(arr[arrSize-1] < tempMin) {
//         tempMin = arr[arrSize-1];
//         //arr[0] = arr[arrSize-1];
//         return min(arr, arrSize - 1);
//       }
//     else {
//         return min(arr, arrSize - 1);
//         }