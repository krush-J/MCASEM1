#include <iostream>
using namespace std;
//Array Bucket
int arr[100] = {0};
int getHashCode(long long  data){
    if(data < 1000){
        return data;
    }
    long long k = data * data;
    string n = to_string(k);
    int spliter = n.length()/4;
    n = n.substr(spliter, spliter*2);
    return getHashCode(stoi(n));
}
void midSquareHashing(int data){
    int index, k = data;
    while(true){      
        index = getHashCode(k);  
        if(arr[index] == 0)
            break;
        else if(arr[index] == data)
            return;
        else
            k = index;             
    }
    
    arr[index] = data;
    printf("%d added at index %d in bucket\n", data, index);
}
void searchElement(int data){
    int index = getHashCode(data);
    if(arr[index] == data){
        printf("%d found at index %d in bucket\n", data, index);        
    }else{
        printf("%d not found at any index in bucket\n", data);        
    }
}
int main(int argc, char const *argv[])
{
    int data[] = {7644,379, 5487, 3456, 3234, 4534};
    for(int i = 0; i < 6; i++)
        midSquareHashing(data[i]);
    searchElement(5487);
    searchElement(54734);
    searchElement(3456);
    return 0;
}
