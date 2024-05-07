//
//  main.cpp
//  DSA6
//
//  Created by ANSH BHUTADA on 06/06/23.
//
#include <iostream>
#include <string>
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
    T frontElement();
    void push(T);
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
    else if(isEmpty()){
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
    int dst;
    Node* next;
public:
    Node();
    Node(int);
    friend class Graph;
};
Node::Node(){
    next=NULL;
}
Node::Node(int dst){
    this->dst=dst;
    next=NULL;
}
class Graph{
    int nV,nE;
    int* visited;
    string* name;
    Node** adjList;
public:
    Graph();
    Graph(int,int);
    void create();
    void display();
    void reset();
    void dfsR(int);
    void dfs(int);
    void bfs(int);
};
Graph::Graph(){}
Graph::Graph(int nV,int nE){
    this->nE=nE;
    this->nV=nV;
    visited=new int[nV];
    name=new string[nV];
    adjList=new Node*[nV];
    for(int i=0;i<nV;i++){
        visited[i]=0;
        name[i]="default";
        adjList[i]=NULL;
    }
}
void Graph::create(){
    for(int i=0;i<nV;i++){
        cout<<"\nEnter the name of landmark:-> "<<endl;
        cin>>name[i];
    }
    for(int i=0;i<nE;i++){
        int src=0,dst=0;
        cout<<"\nEnter the source:-> "<<endl;
        cin>>src;
        cout<<"\nEnter the destination:-> "<<endl;
        cin>>dst;
        Node* temp=new Node(dst);
        if(adjList[src]==NULL){
            adjList[src]=temp;
        }else{
            Node* temp1=adjList[src];
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=temp;
        }
    }
}
void Graph::display(){
    for(int i=0;i<nV;i++){
        Node* temp=adjList[i];
        cout<<name[i]<<" :-> ";
        while(temp!=NULL){
            cout<<name[temp->dst]<<" :-> ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}
void Graph::reset(){
    for(int i=0;i<nV;i++){
        visited[i]=0;
    }
}
void Graph::dfsR(int temp){
    visited[temp]=1;
    cout<<name[temp]<<" :-> ";
    Node* temp1=adjList[temp];
    while(temp1!=NULL){
        if(visited[temp1->dst]==0){
            dfsR(temp1->dst);
        }
        temp1=temp1->next;
    }
}
void Graph::dfs(int temp){
    Stack<int> s;
    visited[temp]=1;
    s.push(temp);
    while(!s.isEmpty()){
        int temp2=s.pop();
        cout<<name[temp2]<<" :-> ";
        Node* temp3=adjList[temp2];
        while(temp3!=NULL){
            int w=temp3->dst;
            if(visited[w]==0){
                visited[w]=1;
                s.push(w);
            }
            temp3=temp3->next;
        }
    }
}
void Graph::bfs(int temp){
    Queue<int> q;
    visited[temp]=1;
    q.push(temp);
    while(!q.isEmpty()){
        int temp1=q.frontElement();
        q.pop();
        cout<<name[temp1]<<" :-> ";
        Node* temp2=adjList[temp1];
        while(temp2!=NULL){
            int w=temp2->dst;
            if(visited[w]==0){
                visited[w]=1;
                q.push(w);
            }
            temp2=temp2->next;
        }
    }
}
int main(){
    int v=0,e=0;
    cout << "Enter the no of vertex :" << endl;
    cin >> v;
    cout << "Enter the no of edges :" << endl;
    cin >> e;
    int start;
    Graph g(v, e);
    int chc;
    while (true)
    {
        cout<<endl;
        cout << " ------------------Menu------------------ " << endl;
        cout << " 1. Create Graph " << endl;
        cout << " 2. Display Graph " << endl;
        cout << " 3. DFS " << endl;
        cout << " 4. DFS iterative " << endl;
        cout << " 5. BFS " << endl;
        cout << " 6. Exit" << endl;
        cout << "Enter the option :-> "<<endl;;
        cin >> chc;
        if (chc == 1)
        {
            g.create();
        }
        else if (chc == 2)
        {
            g.display();
        }
        else if (chc == 3)
        {
            cout << "Enter the vertex which you want to start from :";
            cin >> start;
            g.dfsR(start);
            
        }
         else if (chc == 4)
        {
            g.reset();
            cout << "Enter the vertex which you want to start from :";
            cin >> start;
            g.dfs(start);
            
        }
        else if (chc == 5)
        {
            g.reset();
            cout << "Enter the vertex which you want to start from :";
            cin >> start;
            g.bfs(start);
        }
        else if (chc == 6)
        {
            break;
        }
    }
    return 0;

}
