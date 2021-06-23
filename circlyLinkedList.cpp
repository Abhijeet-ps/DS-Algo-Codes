#include<bits/stdc++.h>
using namespace std;

//Structure to create a node in a linkedlist.

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

//Prints all the elements of the linkedlist using for loop.

void printList(Node* head){
    if(head == NULL) return;
    cout<<head->data<<" ";
    for(Node* p=head->next;p!=head;p=p->next){
        cout<<p->data<<" ";
    } 
}

//Prints all the elements of the linkedlist using a do while loop.

void printList1(Node* head){
    if(head == NULL) return;
    Node* p = head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p != head);
}

//Inserts a node with data x at the head position in the linkedlist.

Node* insertatBegin(Node* head, int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return head;
    }
}

//Inserts a node with data x at the end of the linkedlist.

Node* insertatEnd(Node* head, int x){
    Node* temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;
        return temp;
    }
}

//Deletes the head of the linkedlist and return the new head.

Node* delHead(Node* head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    head->data = head->next->data;
    Node* temp = head->next;
    head->next = head->next->next;
    delete(temp);
    return head;
}

//Deletes the node at the kth position of the linkedlist.

Node* deletekth(Node* head, int k){
    if(head == NULL) return head;
    if(k==1){
        return delHead(head);
    }
    Node* curr = head;
    for(int i=0;i<k-2;i++){
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete(temp);
    return head;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;
    //head = insertatBegin(head, 0);
    //head = insertatEnd(head, 50);
    //delHead(head);
    head = deletekth(head, 2);
    printList1(head);
    return 0;
}