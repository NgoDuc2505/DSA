
#include <bits/stdc++.h>
using namespace std;
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int countIfEleLessThanPivot = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            countIfEleLessThanPivot++;
    }
 
    int pivotIndex = start + countIfEleLessThanPivot;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    if (start >= end)
        return;
 
    int currentPivot = partition(arr, start, end);
 
    quickSort(arr, start, currentPivot - 1);
 
    quickSort(arr, currentPivot + 1, end);
}
 
int main()
{
 
    int arr[] = { 6,2,4,7,1,8,3,12,2 };
    int arr2[] = {843, 729, 165, 543, 986, 112, 320, 486, 532, 789, 245, 879, 653, 442, 591, 876, 934, 273, 661, 198, 764, 321, 598, 409, 937, 286, 502, 714, 624, 157};
    int n = 30;

    quickSort(arr2, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
 
    return 0;
}