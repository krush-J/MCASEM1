#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertionSort(int arr[], int n){
    cout << "Array Before Sorting: ";
    printArray(arr, n);
    int j;
    for(int i = 0; i < n; i++){
        j = i;
        while(j-1 >= 0 && arr[j] < arr[j-1]){
            int t = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = t;
            j--;
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
    insertionSort(arr, n);
    return 0;
}
