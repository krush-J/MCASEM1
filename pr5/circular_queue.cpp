#include <iostream>
using namespace std;
template<typename T>
class Queue{
    T *queue;
    int front = -1, rear = -1, capacity, cnt = 0;
    public:
    Queue(int capacity){
        queue = new T[capacity]{0};
        this->capacity = capacity;
    }
    bool isEmpty(){
        return this->cnt == 0?true:false;       
    }
    bool isFull(){
        return this->cnt == this->capacity?true:false;       
    }
    int size(){
        return this->capacity;
    }
    bool enqueue(){
        if(this->isFull()){
            return false;
        }
        int data;
        cout << "enter element : ";
        cin >> data;
        if(this->front == -1 && this->rear == -1){
            this->front = this->front + 1;
            this->rear = this->rear + 1; 
            this->cnt = this->cnt + 1;           
            this->queue[this->rear] = data;
        }else{
            this->rear = (this->rear+1)%capacity;
            this->queue[this->rear] = data;
            this->cnt = this->cnt + 1;       
        } 
        return true;      
    }
    bool dequeue(){
        if(isEmpty())
            return false;  
        cout << this->queue[this->front] <<" removed from queue."<<endl;
        this->queue[this->front] = 0;  
        this->front = (this->front+1)%capacity;
        this->cnt = this->cnt-1;
        return true;                  
    }   
    string toString(){
        if(this->isEmpty()){
            return  "Queue is empty!\n";            
        }
        string str = "stack [";
        int index;
        for(int i = 0; i < this->capacity; i++){
            index = (i+this->front)%this->capacity;
            str.append(to_string(this->queue[index]));
            if(i != capacity-1)
                str.append(", ");
        }
        return str.append("]\n");
    } 
};
void utilQueue(){
	int choice;
    cout << "enter queue capacity : ";
    cin >> choice;
	Queue<int> *queue = new Queue<int>(choice);
    choice = 1; 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Queue Operations {1 : enqueue, 2 : dequeue, 3 : display, other : exit}\nchoice : ";
		cin >> choice;
		switch(choice){
			case 1: 
                
                cout << (queue->enqueue()?"inserted!":"overflow")<<endl;
                break;
			case 2: if(!queue->dequeue())
                    cout <<"underflow!" << endl;
                    break;
			case 3: cout << queue->toString(); break;
		}
	}
    cout << "closing the application..." << endl;
}
int main(){
    utilQueue();
    return 0;
}
