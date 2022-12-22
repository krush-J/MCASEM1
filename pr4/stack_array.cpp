#include <iostream>
#include <stdlib.h>
using namespace std;
template<typename T>
class Stack{
    T *arr;
    int size, top = -1;
    public:
    Stack(int s){
        size = s;
        arr = new T[size];        
    }
    bool isEmpty(){
        return top == -1? true: false;
    }
    bool isFull(){
        return top == size - 1? true: false;
    }
    void push(){
        if(!isFull()){
            T data;
            cout << "enter element : ";
            cin >> data;
            arr[++top] = data; 
            cout << arr[top] <<" inserted into Stack"<<endl;
        }else{
            cout << "Overflow!!"<<endl;
        }
    }
    void pop(){
        if(!isEmpty()){
            cout << arr[top] <<" removed from Stack"<<endl;
            top--;
        }else{
            cout << "Underflow!!"<<endl;
        }
    }   
	string toString(){        
        if(this->isEmpty()){
            return  "Stack is empty!\n";            
        }
        string str = "stack [";
        for(int i = this->top; i >= 0; i--){
            str.append(arr[i]);
            if(i != 0)
                str.append(", ");
        }
        return str.append("]\n");
    }
};
void utilStack(){
	int choice = 1, size;
	cout << "enter stack size : ";
    cin >> size ;
	Stack<string> *s = new Stack<string>(size); 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Stack Operations {1 : push, 2 : pop, 3 : display, other : exit}\nchoice : ";
		cin >> choice;
		switch(choice){
			case 1: s->push(); break;
			case 2: s->pop(); break;
			case 3: cout << s->toString(); break;
		}
	}
    cout << "closing the application..." << endl;
}
int main(){
   utilStack();
    return 0;
}
