#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        
        Node(int value){
            data=value;
            next=NULL;
        }
};
class Stack{
    private:
         Node *top;
         int size; //actual size of stack
    public:
        Stack(){
            top=NULL;
            size=0;
        }
        //push
        void push(int value){
            Node *temp=new Node(value);
            if(temp==NULL){
                cout<<"stack overflow\n";
                return;
            }
            else{
            temp->next=top;
            top=temp;
            size++;
            cout<<"Pushed "<<value<<" to the stack\n";
          }
        }
        //pop
        void pop(){
            if(top==NULL){
                cout<<"stack underflow\n";
                return;
            }
            else{
                Node *temp=top;
                cout<<"popped "<<top->data<<" from the stack\n";
                top=top->next;
                delete temp;
                size--;
            }
        }
        //peek
        int peek(){
            if(top==NULL){
                cout<<"stack is empty\n";
                return -1;
            }
            else{
                return top->data;
            }
        }
        //IsEmpty
        bool IsEmpty(){
            return top==NULL;
        }
        //Issize
        int IsSize(){
            return size;
        }
        //display stacl
        void display(){
            Node *temp=top;
            while(temp!=NULL){
                cout<<temp->data<<endl;
               temp=temp->next;
            }
        }
    
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.IsSize()<<endl;
    return 0;
}
