#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* right;
    Node* left;

    Node(int x){
        key = x;
        right = left = NULL;
    }
};

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

void preorder(Node* root){
     if(root != NULL){
         cout<<root->key<<" ";
         preorder(root->left);
         preorder(root->right);
     }
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

int getSize(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1 + getSize(root->left) + getSize(root->right);
    }
}

int getMax(Node* root){
    if(root == NULL){
        return INT_MIN;
    }
    else{
        return max(root->key, max(getMax(root->left), getMax(root->right)));
    }
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    else{
        return max(height(root->left), height(root->right)) + 1;
    }
}

void iterativeInorder(Node* root){
    Node* curr = root;
    stack<Node*> s;
    while(curr != NULL or !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr = curr->right;
    }
}

void iterativePreorder(Node* root){
    if(root == NULL) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* curr = s.top();
        cout<<curr->key<<" ";
        s.pop();
        if(curr->right != NULL) s.push(curr->right);
        if(curr->left != NULL) s.push(curr->left);
    }
}

void optimizediterativePreorder(Node* root){
    if(root == NULL) return;
    stack<Node*> s;
    Node* curr = root;
    while(curr!= NULL or !s.empty()){
        while(curr != NULL){
            cout<<curr->key<<" ";
            if(curr->right != NULL) s.push(curr->right);
            curr = curr->left;
        }
        if(!s.empty()){
            curr = s.top();
            s.pop();
        }
    }
}

void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->key<<" ";
        q.pop();
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    // inorder(root);
    // preorder(root);
    // postorder(root);
    // cout<<getSize(root);
    // cout<<getMax(root)<<" ";
    // cout<<height(root)<<" ";
    // iterativeInorder(root);
    // iterativePreorder(root);
    // optimizediterativePreorder(root);
    levelOrder(root);
    return 0;
}