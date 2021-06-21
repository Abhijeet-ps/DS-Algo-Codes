#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    Node *curr = head;

    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

void printListR(Node *head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printListR(head->next);
}

int search(Node* head, int x){
    int index = 0;
    while(head != NULL){
        index++;
        if(head -> data == x){
            return index;
        }
        head = head -> next;
    }
    return -1;
}
int searchr(Node *head, int x){
    if(head == NULL){
        return -1;
    }
    if(head -> data == x){
        return 1;
    }
    else{
        int res = searchr(head -> next, x);
        if(res == -1 ) return -1;
        else return(res + 1);
    }
}

Node * insertBegin(Node* head, int x){
    Node*temp = new Node(x);
    temp->next = head;
    return temp;
}
Node * insertEnd(Node* head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr-> next!= NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node* deleteHead(Node*head){
    if(head == NULL){
        return NULL;
    }
    else{
    Node* temp = head->next;
    delete head;
    return temp;
    }
}

Node * dellast(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return NULL;
    }
    Node* curr = head; 
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;

}

Node* insertpos(Node* head, int pos, int x){
    Node* temp = new Node(x);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    for(int i=1;i<=pos-2 and curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr==NULL){
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* insertinorder(Node* head, int x){
    Node* temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    if(head->data>x){
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    while(curr->next->data<x and curr->next != NULL){
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

void printMiddle(Node * head){
    if(head == NULL){
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data;
}

void printfromEnd(Node *head, int n){
    if(head == NULL) return;
    Node *first = head;
    for(int i=0;i<n;i++){
        if(first == NULL) return;
        first = first->next;
    }
    Node* second = head;
    while(first != NULL){
        second = second->next;
        first =  first->next;
    }
    cout<<second->data;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* reverserec1(Node* head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    Node* rest_head = reverserec1(head->next);
    Node* rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
}

Node* reverserec2(Node* curr, Node* prev){
    if(curr == NULL){
        return prev;
    }
    Node* next = curr->next;
    curr->next = prev;
    return reverserec2(next, curr);
}

void removeDups(Node* head){
    Node* curr = head;
    while(curr != NULL and curr->next != NULL){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete(temp);
        }
        else{
            curr = curr->next;
        }
    }
}

int main(){
//   Node * head = new Node(10);
//   head -> next = new Node(5);
//   head -> next -> next = new Node(20);
//   head -> next -> next -> next = new Node(15);
  //printList(head);
  //printListR(head);
  //cout<<search(head, 20)<<endl;
  //cout<<searchr(head, 20)<<endl;
  Node *head = NULL;
  //head = insertBegin(head, 30);
  head = insertEnd(head, 10);
  head = insertEnd(head, 20);
  head = insertEnd(head, 20);
  head = insertEnd(head, 50);
  //head = deleteHead(head);
  //head = dellast(head);
  head = insertpos(head, 5, 50);
  //head = insertinorder(head, 20);
  //printMiddle(head);
  //printList(head);
  //printfromEnd(head, 1);
  //head = reverse(head);
  //head = reverserec1(head);
  //head = reverserec2(head, NULL);
  removeDups(head);
  printList(head);
}