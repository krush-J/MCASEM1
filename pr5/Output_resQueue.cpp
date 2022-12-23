#include <iostream>
using namespace std;
template<typename T>
class Output_resQueue{
    class Node{
        public:
        T data;
        Node *prev;
        Node *next;
        Node(T data){
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
    void enqueue(T data, char insertFrom){
        Node* newNode = new Node(data); 
        if(this->isEmpty()){
            this->front = newNode;
            this->back = newNode;
        }else{
            if(insertFrom == 'r'){
                (this->back)->next = newNode;
                newNode->prev = this->back;
                this->back = newNode;
            }else{
                newNode->next = front;
                front = newNode;
            }            
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
        cout << n->data << " removed from the queue"<<endl;
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
            str = str.append(temp->data);
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
	Output_resQueue<string> *queue = new Output_resQueue<string>(); 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Queue Operations {1 : enqueue, 2 : dequeue, 3 : display, other : exit}\nchoice : ";
		cin >> choice;
		switch(choice){
			case 1:{ 
                string data;
                char insertFrom;
                cout << "enter element : ";
                cin >> data;
                cout << "enter place where you want to insert a element(r : back) : ";
                cin >> insertFrom;
                queue->enqueue(data, insertFrom);
            }break;
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
