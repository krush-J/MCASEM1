#include <iostream>
using namespace std;
template<typename T>
class Priority_Queue{
    class Node{
        public:
        T data;
        int priority;
        Node *next;
        Node(T data, int priority){
            this->priority = priority;
            this->data = data;
            this->next = NULL;
        }
    }*front;
    int cnt = 0;
    public:
    bool isEmpty(){
        return this->cnt == 0?true:false;       
    }
    int size(){
        return this->cnt;
    }
    bool getPriority(int p1, int p2){
        return (p1 < p2) ? true: false;       
    }
    void enqueue(T data, int priority){
        Node *curr, *newNode;
        newNode = new Node(data, priority); 
        if(front == NULL || getPriority(priority, front->priority)){
            newNode->next = front;
            front = newNode;            
        }else{
            curr = this->front;
            while(curr->next != NULL && getPriority(curr->next->priority, priority))
                curr = curr->next;
            newNode->next = curr->next;
            curr->next = newNode;
        }          
        cnt++;             
    }
    bool dequeue(){
        if(isEmpty())
            return false;    
        Node *n = this->front;
        cout << n->data << " removed from the queue"<<endl;
        this->front = (this->front)->next;
        delete n; 
        cnt--;
        return true;                  
    }   
    string toString(){
        if(this->isEmpty()){
            return  "Priority Queue is empty!\n";            
        }
        Node *temp = this->front;
        string str = "Priority Queue [";
        while(temp != NULL){
            str = str.append(to_string(temp->data));
            if(temp->next != NULL)
                str = str.append(", ");
            temp = temp -> next;
        }
        str.append("]\n");
        return str;
    } 
};
void utilQueue(){
	int choice = 1;
	Priority_Queue<int> *queue = new Priority_Queue<int>(); 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Priority Queue Operations {1 : enqueue, 2 : dequeue, 3 : display, other : exit}\nchoice : ";
		cin >> choice;
		switch(choice){
			case 1: 
                int data, priority;
                cout << "enter element : ";
                cin >> data;
                cout << "enter priority : ";
                cin >> priority;
                queue->enqueue(data, priority);
                break;
			case 2:
                if(!queue->dequeue())
                    cout <<"underflow!" << endl;
                break;
			case 3: 
                cout << queue->toString();
                break;
		}
	}
    cout << "closing the application..." << endl;
}
int main(){
    utilQueue();
    // int arr[] = {3,5,2,6,2,9,4,6};
    // int priority_arr[] = {5,3,6,2,6,1,4,2};
    // Priority_Queue<int> *queue = new Priority_Queue<int>();

    // for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
    //     (*queue).enqueue(arr[i], priority_arr[i]);
    // }
    // for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
    //     queue->dequeue();
    // }
    return 0;
}
