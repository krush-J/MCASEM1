#include <iostream>
#include <stdlib.h>
int *arr, size;
void setSize(){
    arr = (int*)malloc(sizeof(int)*size);
    std::cout << "Size Allocated!" << std::endl;
    return;
}
int linearProbe(int index){
    int i;
    for(i = 0; i < size; i++){
        if(arr[(index+i)%size] == 0)
            return (index+i)%size;
    }
}
void hashingWithLinearProbe(int data){
    int index =data % size;
    if(arr[index] == 0){
        arr[index] = data;
    }else{
        arr[linearProbe(index+1)] = data;
    }
}

void hashingWithLinearProbeSearch(int data){
    int i;
    for(i = 0; i < size; i++){
        if(arr[((data % size) + i)%size] == data)
            break;
    }
    if(i != size)
        std::cout<<data << " found at index "<< ((data % size) + i)%size << std::endl;
    else
        std::cout<<data << " element not found!"<< std::endl;
}

int main() {
    int data;
    std::cout << "Enter Size of Array : ";
    std::cin >> size;
    setSize();
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < size; i++){
        std::cout << "Enter element " << i+1 << " : ";
        std::cin >> data;
        hashingWithLinearProbe(data);
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    std::cout << "Enter element to find : ";
    std::cin >> data;
    hashingWithLinearProbeSearch(data);
    return 0;
}