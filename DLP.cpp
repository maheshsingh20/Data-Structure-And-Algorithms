#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(node* &head, int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}


int main(){
    node* 
}