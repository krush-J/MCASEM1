#include <iostream>
using namespace std;

int findByLinierSearch(int arr[], int n, int value){
    cout << "Finding using linear search"<<endl;
    for(int i = 0; i < n; i++){
        if(arr[i] == value)
            return i;
    }
    return -1;
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

    int index = findByLinierSearch(arr, n, value);
    if(index != -1){
        cout << "Your element is found at index "<<index<<endl;
    }else{
        cout << "No element found That you given to search"<<endl;
    }
    return 0;
}
