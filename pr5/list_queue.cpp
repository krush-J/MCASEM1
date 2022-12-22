#include <iostream>
using namespace std;
template<typename T>
class Queue{
    class Node{
        public:
        T data;
        Node *prev;
        Node *next;
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    }*front, *back;
    int cnt = 0;
    public:
    bool isEmpty(){
        return this->cnt == 0?true:false;       
    }
    int size(){
        return this->cnt;
    }
    void enqueue(T data){
        Node* n = new Node(data); 
        if(this->isEmpty()){
            this->front = n;
            this->back = n;
        }else{
            (this->back)->next = n;
            n->prev = this->back;
            this->back = n;
        }          
        cnt++;             
    }
    bool dequeue(){
        if(isEmpty())
            return false;    
        Node *n = this->front;
        front = front->next;
        if(this->front != NULL)
            (this->front)->prev = NULL;
        delete n; 
        cnt--;
        return true;                  
    }   
    string toString(){
        if(this->isEmpty()){
            return  "Queue is empty!\n";            
        }
        Node *temp = this->front;
        string str = "Queue [";
        while(temp != NULL){
            str = str.append(to_string(temp->data));
            str = str.append(", ");
            temp = temp -> next;
        }
        str = str.substr(0, str.length()-2);
        str.append("]\n");
        return str;
    } 
};
void utilQueue(){
	int choice = 1;
	Queue<int> *queue = new Queue<int>(); 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Queue Operations {1 : enqueue, 2 : dequeue, 3 : display, other : exit}\nchoice : ";
		cin >> choice;
		switch(choice){
			case 1: 
                int data;
                cout << "enter element : ";
                cin >> data;
                queue->enqueue(data);
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
