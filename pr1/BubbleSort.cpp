#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int n){
    cout << "Array Before Sorting: ";
    printArray(arr, n);
    for(int i = 0; i < n-1; i++){
        bool flag = true;
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1] ){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                flag = false;
            }
        }
        if(flag)
            break;
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
    bubbleSort(arr, n);
    return 0;
}
