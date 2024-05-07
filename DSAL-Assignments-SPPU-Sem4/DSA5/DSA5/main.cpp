//
//  main.cpp
//  DSA5
//
//  Created by ANSH BHUTADA on 07/06/23.
//
#include <iostream>
#include <string>
#define size 11
using namespace std;
class Node{
    string data,meaning;
    Node* next;
public:
    Node();
    Node(string,string);
    friend class Hash;
};
Node::Node(){
    next=NULL;
}
Node::Node(string data,string meaning){
    this->data=data;
    this->meaning=meaning;
    next=NULL;
}
class Hash{
    Node* arr=new Node[size];
public:
    Hash();
    int hashCode(string);
    void insert(string,string);
    void display();
    bool search(string);
    void deleteData(string);
};
Hash::Hash(){}
int Hash::hashCode(string data){
    int hashIndex=0;
    for(int i=0;i<data.length();i++){
        hashIndex+=int(data[i]);
    }
    return hashIndex%size;
}
void Hash::insert(string data,string meaning){
    int hashIndex=hashCode(data);
    Node* temp=new Node(data,meaning);
    if(arr[hashIndex].next==NULL){
        arr[hashIndex].next=temp;
    }else{
        Node* temp2=&arr[hashIndex];
        while (temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
    }
}
void Hash::display(){
    Node* temp=NULL;
    for(int i=0;i<size;i++){
        temp=&arr[i];
        if(temp->next!=NULL){
            temp=temp->next;
            while(temp){
                cout<<temp->data<<" : "<<temp->meaning<<" --> ";
                temp=temp->next;
            }
        }else{
            cout<<" Empty ";
        }
        cout<<"\n";
    }
}
bool Hash::search(string data){
    int hashIndex=hashCode(data);
    Node* temp=&arr[hashIndex];
    temp=temp->next;
    while (temp){
        if(temp->data==data){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void Hash::deleteData(string data){
    if(!search(data)){
        cout<<"\nWord is not present in the dictionary"<<endl;
    }else{
        int hashIndex=hashCode(data);
        Node* temp=&arr[hashIndex];
        Node* temp2=temp->next;
        while(temp2->data!=data){
            temp=temp2;
            temp2=temp2->next;
        }
        temp->next=temp2->next;
        string found=temp2->data;
        temp2->next=NULL;
        delete temp2;
    }
}
int main(){
    Hash h;
    h.insert("apple","red");
    h.insert("banana","yellow");
    h.insert("dog","domestic");
    h.insert("lion","king");
    h.insert("cat","meow");
    h.display();
    cout<<"\n";
    cout<<h.search("apple");
    cout<<"\n";
    h.deleteData("apple");
    h.display();
    cout<<"\n";
    h.deleteData("cat");
    h.display();
    cout<<"\n";
    h.deleteData("dog");
    h.display();
    cout<<"\n";
    h.deleteData("lion");
    h.display();
    cout<<"\n";
    h.deleteData("banana");
    h.display();
    cout<<"\n";
    return 0;
}

