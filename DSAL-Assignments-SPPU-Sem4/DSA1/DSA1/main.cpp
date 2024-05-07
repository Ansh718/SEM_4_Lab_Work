//
//  main.cpp
//  DSA1
//
//  Created by ANSH BHUTADA on 07/06/23.
//
#include <iostream>
#include <string>
using namespace std;
class Node{
    string word,meaning;
    Node* lchild;
    Node* rchild;
public:
    Node();
    Node(string,string);
    friend class BST;
};
Node::Node(){
    lchild=rchild=NULL;
}
Node::Node(string word,string meaning){
    this->word=word;
    this->meaning=meaning;
    lchild=rchild=NULL;
}
class BST{
    Node* root;
public:
    BST();
    Node* getRoot();
    void insert(string,string);
    void ascending(Node*);
    void descending(Node*);
    bool search(string,Node*&,Node*&);
    void update(string,string);
    void deleteWord(string);
};
BST::BST(){
    root=NULL;
}
Node* BST::getRoot(){
    return root;
}
void BST::insert(string word,string meaning){
    Node* temp=new Node(word,meaning);
    if(root==NULL){
        root=temp;
    }
    else{
        Node* current=root;
        Node* parent=NULL;
        while (current!=NULL){
            parent=current;
            if(word<current->word){
                current=parent->lchild;
            }
            else{
                current=parent->rchild;
            }
        }
        if(word<parent->word){
            parent->lchild=temp;
        }
        else{
            parent->rchild=temp;
        }
    }
}
void BST::ascending(Node* temp){
    if(temp!=NULL){
        ascending(temp->lchild);
        cout<<temp->word<<" : "<<temp->meaning<<endl;
        ascending(temp->rchild);
    }
}
void BST::descending(Node* temp){
    if(temp!=NULL){
        descending(temp->rchild);
        cout<<temp->word<<" : "<<temp->meaning<<endl;
        descending(temp->lchild);
    }
}
bool BST::search(string key,Node*& current,Node*& parent){
    Node* temp=root;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(key==temp->word){
            cout<<"\nFound after "<<cnt<<" comparisons"<<endl;
            current=temp;
            return true;
        }
        else if(key<temp->word){
            parent=temp;
            temp=temp->lchild;
        }
        else{
            parent=temp;
            temp=temp->rchild;
        }
    }
    cout<<"\n The word,"<<key<<" you want to search is not present"<<endl;
    parent=current=NULL;
    return false;
}
void BST::update(string key,string meaning){
    Node* temp=root;
    while (temp!=NULL){
        if(temp->word==key){
            temp->meaning=meaning;
            return;
        }
        else if (temp->word>key){
            temp=temp->lchild;
        }
        else{
            temp=temp->rchild;
        }
    }
    cout<<"\n The word,"<<key<<" you want to update is not present"<<endl;
}
void BST::deleteWord(string key){
    Node* parent=NULL;
    Node* current=NULL;
    Node* child=NULL;
    this->search(key,current,parent);
    if(current==NULL){
        cout<<"\n The word whose you wished to delete is not present in the Dictionary"<<endl;
        return;
    }else{
        if(current->lchild!=NULL && current->rchild!=NULL){
            child=current->rchild;
            while (child->lchild!=NULL){
                child=child->lchild;
            }
            string tw=child->word,tm=child->meaning;
            this->deleteWord(tw);
            current->word=tw;
            current->meaning=tm;
        }else{
            if(current->lchild!=NULL){
                child=current->lchild;
            }
            else if(current->rchild!=NULL){
                child=current->rchild;
            }
            else{
                child=NULL;
            }
            if(current==root){
                root=child;
                delete current;
                return;
            }
            if(parent->word>key){
                parent->lchild=child;
            }else{
                parent->rchild=child;
            }
            delete current;
        }
    }
}
int main(){
    BST a;
    int chc, flag = 1;
    string word, meaning;
    while (flag==1)
    {
        cout << "Enter your choice : \n 1.Insert a Word in the Dictionary \n 2.Search a Word from the Dictionary \n 3.Update the Meaning of a Word in the Dictionary \n 4.Display the Dictionary in Ascending order \n 5.Display the Dictionary in Descending order\n 6.Delete a Word from the Dictionary" << endl;
        cin >> chc;
        switch (chc)
        {
        case 1:
            {
                cout << "Enter the Word:" << endl;
                cin >> word;
                cout << "Enter the Meaning:" << endl;
                cin >> meaning;
                a.insert(word, meaning);
                break;
                
            }
        case 2:
            {
                cout << "Enter the Word you want to search in the Dictionary:" << endl;
                cin >> word;
                Node* current=NULL;
                Node* parent=NULL;
                a.search(word, current, parent);
                break;
            }
        case 3:
            {
                cout << "Enter the Word whose meaning you wish to update:" << endl;
                cin >> word;
                cout << "Enter the Meaning you want:" << endl;
                cin >> meaning;
                a.update(word, meaning);
                break;
            }
        case 4:
            {
                a.ascending(a.getRoot());
                break;
            }
        case 5:
            {
                a.descending(a.getRoot());
                break;
            }
        case 6:
            {
                cout << "Enter the Word which you wish to delete:" << endl;
                cin >> word;
                a.deleteWord(word);
                a.ascending(a.getRoot());
                break;
            }
        default:
            {
                cout << "Enter valid choice" << endl;
                break;
            }
            
        }
        cout << "Do you want to continue?(1/0):" << endl;
        cin >> flag;
    }
    return 0;
}
