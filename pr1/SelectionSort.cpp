#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int n){
    cout << "Array Before Sorting: ";
    printArray(arr, n);
    int minIndex;
    for(int i = 0; i < n; i++){
        minIndex = i;
        for(int j = i+1; j < n-1; j++){
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        if(minIndex != i){
            int t = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = t;
        }

    }
    cout << "Array After Sorting : ";
    printArray(arr, n);
}
int main()
{
    int n;
    cout<<"Enter how many number you are going to enter : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Element " << i+1 << " : ";
        cin >> arr[i];
    }
    selectionSort(arr, n);
    return 0;
}
