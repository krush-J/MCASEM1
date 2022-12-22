#include <iostream>
#include <stdlib.h>
using namespace std;
class Stack{
    int size, *arr, top = -1;
    public:
    Stack(int s){
        size = s;
        arr = (int*)malloc(sizeof(int) * s);        
    }
    bool isEmpty(){
        return top == -1? true: false;
    }
    bool isFull(){
        return top == size - 1? true: false;
    }
    void push(){
        if(!isFull()){
            cout << "enter element : ";
            cin >> arr[++top];
            cout << "elment inserted into Stack"<<endl;
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
	void print(){
		if(isEmpty()){
			cout << "Stack is empty!"<<endl;
		}else{
			cout << "Stack : ";
			for(int i = top; i >= 0; i--)
				cout << arr[i] << " ";
			cout << endl;
		}
	} 
};
void utilStack(){
	int choice = 1, size;
	cout << "enter stack size : ";
    cin >> size ;
	Stack *s = new Stack(size); 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Stack Operations"<<endl;
		cout << "1 : push\n2 : pop\n3 : display\nother : exit" << endl;
		cin >> choice;
		switch(choice){
			case 1: s->push(); break;
			case 2: s->pop(); break;
			case 3: s->print(); break;
		}
	}
}
int main(){
   utilStack();
    return 0;
}
