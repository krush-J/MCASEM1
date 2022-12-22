#include <iostream>
#include <stdlib.h>
int *arr, size, capacity = 0;
void setSize(){
    arr = (int*)malloc(sizeof(int)*size);
    std::cout << "Size Allocated!" << std::endl;
    return;
}
// to get linear index which is empty
int linearProbe(int index, int data){
    int i, k;
    for(i = 0; i < size; i++){
        k = (index+i)%size;
        if(arr[k] == 0){
            capacity++;
            break;
        }else if(arr[k] == data){
            break;
        }            
    }
    return k;
}
void hashingWithLinearProbe(int data){
    int index =data % size;
    if(arr[index] == 0){
        capacity++;
        arr[index] = data;
    }else if(arr[index] == data){
         return;
    }else{
        arr[linearProbe(index+1, data)] = data;
    }
}

void hashingWithLinearProbeSearch(int data){
    int i, k;
    for(i = 0; i < size; i++){
        k = ((data % size) + i) % size;
        if(arr[k] == data)
            break;
    }
    if(i != size)
        std::cout<<data << " found at index "<< k << std::endl;
    else
        std::cout<<data << " element not found!"<< std::endl;
    return;
}

int main() {
    int data;
    std::cout << "Enter Size of Array : ";
    std::cin >> size;
    setSize();
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
    while(capacity < size){
        std::cout << "Enter elements : ";
        std::cin >> data;
        hashingWithLinearProbe(data);
    }
    std::cout << "Array element stored using hashing are : ";
    for(int i = 0; i < size; i++){
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    std::cout << "Enter element to find : ";
    std::cin >> data;
    hashingWithLinearProbeSearch(data);
    return 0;
}
