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

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverseList(node* &head){
    node* temp=head->next;
    node* curr=NULL;
    while(temp!=NULL){
        head->next=curr;
        curr=head;
        head=temp;
        temp=temp->next;
    }
}

int main(){
    node* list1=new node(10);
    node* head=list1;
    insertAtHead(head,9);
    insertAtHead(head,8);
    insertAtHead(head,7);
    insertAtHead(head,6);
    print(head);
    reverseList(head);
    print(head);
    return 0;
}
