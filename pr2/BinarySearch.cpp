
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n){
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
}

int findByBinarySearch(int arr[], int start, int end, int value){
    int mid = (start+end)/2;
    if(mid > end)
        return -1;
    else if(arr[mid] < value)
        return findByBinarySearch(arr, mid+1, end, value);
    else if(arr[mid] > value)
        return findByBinarySearch(arr, start, mid-1, value);
    return mid;
}
int performBinarySearch(int arr[], int n, int value){
    cout << "Finding using Binary search"<<endl;
    insertionSort(arr,n);
    return findByBinarySearch(arr, 0, n, value);
}
int main()
{
    int n, value;
    cout<<"Enter how many number you are going to enter : ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "Element " << i+1 << " : ";
        cin >> arr[i];
    }
    cout<<"Enter which number you want to find : ";
    cin >> value; 
    int index = performBinarySearch(arr, n, value);
    if(index != -1){
        cout << "Your element is found"<<endl;
    }else{
        cout << "No element found That you given to search"<<endl;
    }
    return 0;
}
