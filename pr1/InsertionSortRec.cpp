// Recursive C++ program for insertion sort
#include <iostream>
using namespace std;

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
	for (int i=0; i < n; i++)
		cout << arr[i] <<" ";
    cout << endl;
}

// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
    // if array reached at position 1
	if(n <= 1)
        return;
    insertionSortRecursive(arr, n-1);
    int j = n - 2, last=arr[n-1]; 
    while(j >= 0 && arr[j] < last){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
     
}



/* Driver program to test insertion sort */
int main()
{
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSortRecursive(arr, n);
	printArray(arr, n);

	return 0;
}
