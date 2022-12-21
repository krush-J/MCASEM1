#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shellSort(int arr[], int n){
    cout << "Array Before Sorting: ";
    printArray(arr, n);
    for(int gap = n/2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int j, temp = arr[i];
            for(j = i; j >= gap && temp < arr[j-gap]; j -= gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
            
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
    shellSort(arr, n);
    return 0;
}
