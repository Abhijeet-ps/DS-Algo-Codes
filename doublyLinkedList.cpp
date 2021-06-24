#include<bits/stdc++.h>
using namespace std;

//Structure of a Node.

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

//Inserts a new node at the end of the linkedlist and returns the head.

Node* insert(Node* head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        temp->next = temp->prev = NULL;
        return temp;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    temp->next = NULL;
    return head;
}

//Prints all the elements of the linkedlist.

void display(Node* head){
    if(head == NULL){
        cout<<-1;
        return;
    }
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

//Inserts a new node at the head of the linkedlist and returns the new head.

Node* insertBegin(Node* head, int data){
    // Node* temp = new Node(data);
    // if(head == NULL){
    //     temp->prev = temp->next = NULL;
    //     return temp;
    // }
    // head->prev = temp;
    // temp->prev = NULL;
    // temp->next = head;
    // return temp;
    Node* temp = new Node(data);
    temp->next = head;
    if(head != NULL){
        head->prev = temp;
    }
    return temp;
}

//Inserts a new node at the end of the linkedlist and returns head.

Node* insertEnd(Node* head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        return temp;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

//Reverses the linkedlist and returns the new head.

Node* reverseDLL(Node* head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    Node* prev = NULL; 
    Node* curr = head;
    while(curr != NULL){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

//Deletes the head of the linkedlist and returns the new head.

Node* delHead(Node* head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        delete(head);
        return NULL;
    }
    Node* curr = head->next;
    curr->prev = NULL;
    delete(head);
    return curr;
}

//Deletes the last element of the linkedlist and returns the head of the linkedlist.

Node* delTail(Node* head){
    if(head == NULL or head->next == NULL){
        return delHead(head);
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->prev->next = NULL;
    delete(curr);
    return head;
}

int main(){
    Node* head = new Node(1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = delTail(head);
//    head = delHead(head);
//    reverse1(&head);
//    head = insertBegin(head, 0);
//    head = insertEnd(head, 6);
//    head = reverseDLL(head);
    display(head);
    
    return 0;
}