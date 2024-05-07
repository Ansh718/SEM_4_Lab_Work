//
//  main.cpp
//  DSA2
//
//  Created by ANSH BHUTADA on 06/06/23.
//
#include <iostream>
using namespace std;
template <class T>
class Stack{
    int top;
    T arr[20];
public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(T);
    T pop();
};
template <class T>
Stack<T>::Stack(){
    top=-1;
}
template <class T>
bool Stack<T>::isEmpty(){
    if(top==-1){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool Stack<T>::isFull(){
    if(top==19){
        return true;
    }else{
        return false;
    }
}
template <class T>
void Stack<T>::push(T x){
    if(isFull()){
        return;
    }else{
        top++;
        arr[top]=x;
    }
}
template <class T>
T Stack<T>::pop(){
    if(isEmpty()){
        return NULL;
    }else{
        top--;
        return arr[top+1];
    }
}
template <class T>
class Queue{
    int front,rear;
    T arr[20];
public:
    Queue();
    bool isEmpty();
    bool isFull();
    void push(T);
    T frontElement();
    T pop();
};
template <class T>
Queue<T>::Queue(){
    front=rear=-1;
}
template <class T>
bool Queue<T>::isEmpty(){
    if(front==rear && rear==-1){
        return true;
    }else{
        return false;
    }
}
template <class T>
bool Queue<T>::isFull(){
    if(rear==19){
        return true;
    }else{
        return false;
    }
}
template <class T>
void Queue<T>::push(T x){
    if(isFull()){
        return;
    }
    else if (isEmpty()){
        front++;
        rear++;
        arr[rear]=x;
    }else{
        rear++;
        arr[rear]=x;
    }
}
template <class T>
T Queue<T>::frontElement(){
    return arr[front];
}
template <class T>
T Queue<T>::pop(){
    if(isEmpty()){
        return NULL;
    }
    else if(front==rear){
        T ans=arr[front];
        front=rear=-1;
        return ans;
    }else{
        T ans=arr[front];
        front+=1;
        return ans;
    }
}
class Node{
    int data;
    Node* lchild;
    Node* rchild;
public:
    Node();
    Node(int);
    friend class BT;
};
Node::Node(){
    lchild=rchild=NULL;
}
Node::Node(int data){
    this->data=data;
}
class BT{
    Node* root;
public:
    BT();
    Node* getRoot();
    void setRoot(Node*);
    void createR();
    void creator(Node*);
    void create();
    void inorderR(Node*);
    void inorder();
    void preorderR(Node*);
    void preorder();
    void postorderR(Node*);
    void postorder();
    void mirror(Node*);
    void operator=(BT&);
    Node* copyTree(Node*);
    int height(Node*);
    void inorderLeaf(Node*,int&);
    int leafCount(Node*);
    void inorderInternal(Node*,int&);
    int internalCount(Node*);
    void deleteFunction(Node*);
};
BT::BT(){
    root=NULL;
}
Node* BT::getRoot(){
    return root;
}
void BT::setRoot(Node* temp){
    temp=NULL;
}
void BT::createR(){
    int temp=0;
    cout<<"\nEnter the data of the root"<<endl;
    cin>>temp;
    root=new Node(temp);
    creator(root);
}
void BT::creator(Node* temp){
    int temp1=0;
    cout<<"Enter the left child of "<<temp->data<<"\n enter -1 to quit"<<endl;
    cin>>temp1;
    if(temp1!=-1){
        Node* temp2=new Node(temp1);
        temp->lchild=temp2;
        creator(temp2);
    }
    cout<<"Enter the right child of "<<temp->data<<"\n enter -1 to quit"<<endl;
    cin>>temp1;
    if(temp1!=-1){
        Node* temp2=new Node(temp1);
        temp->rchild=temp2;
        creator(temp2);
    }
}
void BT::create(){
    Queue<Node*> q;
    if(root==NULL){
        int temp=0;
        cout<<"\nEnter the data of the root"<<endl;
        cin>>temp;
        root=new Node(temp);
        q.push(root);
    }
    while(!q.isEmpty()){
        Node* temp=q.frontElement();
        q.pop();
        int temp1=0;
        cout<<"Enter the left child of "<<temp->data<<"\n enter -1 to quit"<<endl;
        cin>>temp1;
        if(temp1!=-1){
            temp->lchild=new Node(temp1);
            q.push(temp->lchild);
        }
        cout<<"Enter the right child of "<<temp->data<<"\n enter -1 to quit"<<endl;
        cin>>temp1;
        if(temp1!=-1){
            temp->rchild=new Node(temp1);
            q.push(temp->rchild);
        }
    }
}
void BT::inorderR(Node* temp){
    if(temp==NULL){
        return;
    }else{
        inorderR(temp->lchild);
        cout<<temp->data<<" ";
        inorderR(temp->rchild);
    }
}
void BT::inorder(){
    Stack<Node*> s;
    Node* temp=root;
    while(!s.isEmpty() || temp!=NULL){
        while(temp!=NULL){
            s.push(temp);
            temp=temp->lchild;
        }
        temp=s.pop();
        cout<<temp->data<<" ";
        temp=temp->rchild;
    }
}
void BT::preorderR(Node* temp){
    if(temp==NULL){
        return;
    }else{
        cout<<temp->data<<" ";
        preorderR(temp->lchild);
        preorderR(temp->rchild);
    }
}
void BT::preorder(){
    Stack<Node*> s;
    Node* temp=root;
    s.push(temp);
    while(!s.isEmpty()){
        temp=s.pop();
        cout<<temp->data<<" ";
        if(temp->rchild!=NULL){
            s.push(temp->rchild);
        }
        if(temp->lchild!=NULL){
            s.push(temp->lchild);
        }
    }
}
void BT::postorderR(Node* temp){
    if(temp==NULL){
        return;
    }else{
        postorderR(temp->lchild);
        postorderR(temp->rchild);
        cout<<temp->data<<" ";
    }
}
void BT::postorder(){
    Stack<Node*> s1;
    Stack<Node*> s2;
    Node* temp=root;
    s1.push(temp);
    while(!s1.isEmpty()){
        temp=s1.pop();
        s2.push(temp);
        if(temp->lchild!=NULL){
            s1.push(temp->lchild);
        }
        if(temp->rchild!=NULL){
            s1.push(temp->rchild);
        }
    }
    while(!s2.isEmpty()){
        Node* temp2=s2.pop();
        cout<<temp2->data<<" ";
    }
}
void BT::mirror(Node* temp){
    if(temp==NULL){
        return;
    }else{
        Node* temp2=new Node();
        mirror(temp->lchild);
        mirror(temp->rchild);
        temp2=temp->lchild;
        temp->lchild=temp->rchild;
        temp->rchild=temp2;
    }
}
void BT::operator=(BT& temp){
    root=copyTree(temp.getRoot());
}
Node* BT::copyTree(Node* temp){
    if(temp==NULL){
        return NULL;
    }else{
        Node* temp1=new Node(temp->data);
        temp1->lchild=copyTree(temp->lchild);
        temp1->rchild=copyTree(temp->rchild);
        return temp1;
    }
}
int BT::height(Node* temp){
    if(temp==NULL){
        return 0;
    }else{
        return 1+max(height(temp->lchild),height(temp->rchild));
    }
}
void BT::inorderLeaf(Node* temp,int& cnt){
    if(temp==NULL){
        return;
    }
    inorderLeaf(temp->lchild,cnt);
    if(temp->lchild==NULL && temp->rchild==NULL){
        cnt++;
    }
    inorderLeaf(temp->rchild,cnt);
}
int BT::leafCount(Node* temp){
    int cnt=0;
    inorderLeaf(temp,cnt);
    return cnt;
}
void BT::inorderInternal(Node* temp,int& cnt){
    if(temp==NULL){
        return;
    }
    inorderLeaf(temp->lchild,cnt);
    if(temp->lchild!=NULL || temp->rchild!=NULL){
        cnt++;
    }
    inorderLeaf(temp->rchild,cnt);
}
int BT::internalCount(Node* temp){
    int cnt=0;
    inorderInternal(temp,cnt);
    return cnt;
}
void BT::deleteFunction(Node* temp){
    if(temp==NULL){
        return;
    }
    deleteFunction(temp->lchild);
    deleteFunction(temp->rchild);
    delete temp;
}
int main(){
    BT a;
    BT b;
    a.create();
    int ch, flag = 1;
    do
    {
        cout << " Operations : " << endl;
        cout << "1. Inorder, Preorder and Postorder" << endl;
        cout << "2. Mirror Image" << endl;
        cout << "3. Height of the tree" << endl;
        cout << "4. Number of leaves" << endl;
        cout << "5. Delete all nodes" << endl;
        cout << "6. Copy tree" << endl;
        cout << "7. Number of Internal Nodes" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Inorder recursive : " << endl;
            a.inorderR(a.getRoot());
            cout << "\n";
            cout << "Inorder iterative : " << endl;
            a.inorder();
            cout << "\n";
            cout << "Preorder recursive : " << endl;
            a.preorderR(a.getRoot());
            cout << "\n";
            cout << "Preorder iterative : " << endl;
            a.preorder();
            cout << "\n";
            cout << "Postorder recursive : " << endl;
            a.postorderR(a.getRoot());
            cout << "\n";
            cout << "Postorder iterative : " << endl;
            a.postorder();
            cout << "\n";
            break;
        case 2:
            cout << "Mirror image" << endl;
            a.mirror(a.getRoot());
            cout << "Inorder : " << endl;
            a.inorderR(a.getRoot());
            break;
        case 3:
            cout << "Height of Tree is:" << endl;
            cout << a.height(a.getRoot());
            cout << "\n";
            break;
        case 4:
            cout << "Number of leaves:" << endl;
            cout << a.leafCount(a.getRoot());
            cout << "\n";
            break;
        case 5:
            a.deleteFunction(a.getRoot());
            a.setRoot(NULL);
            break;
        case 6:
            b = a;
            cout << "Inorder of a:" << endl;
            a.inorderR(a.getRoot());
            cout << "\n";
            cout << "Inorder of b:" << endl;
            b.inorderR(b.getRoot());
            cout << "\n";
            break;
        case 7:
            cout << "Number of internal Nodes:" << endl;
            cout << a.internalCount(a.getRoot());
            cout << "\n";
            break;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
        cout << "Do you want to continue?(1/0):" << endl;
        cin >> flag;
    } while (flag == 1);
    return 0;
}
