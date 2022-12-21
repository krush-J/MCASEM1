#include <iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int maxElement(int arr[], int n){
    int index = 0;
    for(int i = 1; i < n; i++)
        if(arr[i] > arr[index])
            index = i;
    return arr[index];
}
void countingSort(int arr[], int n, int exp){
    int count[10] = {0,0,0,0,0,0,0,0,0,0}, i;

    for(i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        count[i] += count[i-1];
    int outputArr[n];
    for(i = n-1; i >= 0; i--){
        int lastDigit = (arr[i] / exp) % 10;
        outputArr[count[lastDigit]-1] = arr[i];
        count[lastDigit]--;
    }
    for(i = 0; i < n; i++)
        arr[i] = outputArr[i];
}
void radixSort(int arr[], int n){
    cout << "Array Before Sorting: ";
    printArray(arr, n);
    int max = maxElement(arr, n);
    for(int exp = 1; max/exp > 0; exp *= 10){
        countingSort(arr, n, exp);
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
    radixSort(arr, n);
    return 0;
}
