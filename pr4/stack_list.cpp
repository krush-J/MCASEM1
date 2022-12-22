#include <iostream>
using namespace std;
template<typename T>
class Stack{
    class Node{
        public:
        T data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
    };
    public:
    Node *head = NULL;
    int cnt = 0;
    bool isEmpty(){
        return this->head == NULL?true:false;
    }
    int size(){
        return this->cnt;
    }
    void push(T data){
        Node *n = new Node(data);
        if(this->isEmpty()){
            this->head = n;
        }else{
            n->next = this->head;
            this->head = n;
        }
        cnt++;
    }
    bool pop(){
        if(this->isEmpty()) 
            return false;    
        cout << head->data <<" removed from the stack" << endl;
        Node *temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    string toString(){
        if(this->isEmpty()){
            return  "Stack is empty!\n";            
        }
        Node *temp = head;
        string str = "stack [";
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

void utilStack(){
    int choice = 1;
	Stack<int> *s = new Stack<int>(); 
	while(choice == 1 || choice == 2 || choice == 3 ){
		cout << "Stack Operations {1 : push, 2 : pop, 3 : display, other : exit}\nchoice : ";
		cin >> choice;
		switch(choice){
			case 1: {
                int data;
                cout << "enter element : ";
                cin >> data;
                s-> push(data);
            }; break;
			case 2: if(!s->pop())
                    cout <<"underflow!" << endl;
                    break;
			case 3: cout << s->toString(); break;
		}
	}
    cout << "closing the application..." << endl;
}
int main(int argc, char const *argv[])
{
    utilStack();
    return 0;
}
