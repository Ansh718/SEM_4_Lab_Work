//
//  main.cpp
//  DSA9
//
//  Created by ANSH BHUTADA on 06/06/23.
//
#include <iostream>
#include <string>
using namespace std;
class Node{
    string word,meaning;
    Node* lchild;
    Node* rchild;
    int ht;
public:
    Node();
    Node(string,string);
    friend class AVL;
};
Node::Node(){
    lchild=rchild=NULL;
}
Node::Node(string word,string meaning){
    this->word=word;
    this->meaning=meaning;
    ht=1;
    lchild=rchild=NULL;
}
class AVL{
public:
    Node* root;
    AVL();
    void setRoot(Node*);
    int height(Node*);
    int balanceFactor(Node*);
    void updateHeight(Node*);
    Node* RR(Node*);
    Node* LL(Node*);
    Node* LR(Node*);
    Node* RL(Node*);
    Node* balance(Node*);
    Node* insert(Node*,string,string);
    void inorder(Node*);
    void preorder(Node*);
    bool search(Node*,string);
};
AVL::AVL(){
    root=NULL;
}
void AVL::setRoot(Node* temp){
    temp=NULL;
}
int AVL::height(Node* temp){
    if(temp==NULL){
        return 0;
    }
    return temp->ht;
}
int AVL::balanceFactor(Node* temp){
    if(temp==NULL){
        return 0;
    }
    return height(temp->lchild)-height(temp->rchild);
}
void AVL::updateHeight(Node* temp){
    temp->ht=1+max(height(temp->lchild),height(temp->rchild));
}
Node* AVL::RR(Node* temp){
    Node* temp2=temp->rchild;
    temp->rchild=temp2->lchild;
    temp2->lchild=temp;
    updateHeight(temp);
    updateHeight(temp2);
    return temp2;
}
Node* AVL::LL(Node* temp){
    Node* temp2=temp->lchild;
    temp->lchild=temp2->rchild;
    temp2->rchild=temp;
    updateHeight(temp);
    updateHeight(temp2);
    return temp2;
}
Node* AVL::LR(Node* temp){
    temp->lchild=RR(temp->lchild);
    return LL(temp);
}
Node* AVL::RL(Node* temp){
    temp->rchild=LL(temp->rchild);
    return RR(temp);
}
Node* AVL::balance(Node* temp){
    if(balanceFactor(temp)==2){
        if(balanceFactor(temp->lchild)<0){
            temp=LR(temp);
        }else{
            temp=LL(temp);
        }
    }
    if(balanceFactor(temp)==-2){
        if(balanceFactor(temp->rchild)>0){
            temp=RL(temp);
        }else{
            temp=RR(temp);
        }
    }
    updateHeight(temp);
    return temp;
}
Node* AVL::insert(Node* temp,string word,string meaning){
    if(temp==NULL){
        return new Node(word,meaning);
        
    }
    if(temp->word>word){
        temp->lchild=insert(temp->lchild,word,meaning);
    }
    else if(temp->word<word){
        temp->rchild=insert(temp->rchild,word,meaning);
    }
    else{
        temp->meaning=meaning;
        return temp;
    }
    return balance(temp);
}
void AVL::inorder(Node* temp){
    if(temp==NULL){
        return;
    }
    inorder(temp->lchild);
    cout<<temp->word<<" ";
    inorder(temp->rchild);
}
void AVL::preorder(Node* temp){
    if(temp==NULL){
        return;
    }
    cout<<temp->word<<" ";
    preorder(temp->lchild);
    preorder(temp->rchild);
}
bool AVL::search(Node* temp,string word){
    if(temp==NULL){
            return false;
        }
    if(temp->word<word){
        return search(temp->rchild,word);
    }
    else if(temp->word>word){
        return search(temp->lchild,word);
    }
    else{
        return true;
    }
}
int main(){
    AVL obj;
    string word,meaning;
    Node* temp = NULL;
    int choice = 0;
    do
    {
        cout << "Menu" << endl;
        cout << "1. Insert key-value pair" << endl;
        cout << "2. Search key" << endl;
        cout << "3. Preorder traversal" << endl;
        cout << "4. Inorder traversal" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:


                cout << "Enter key: ";
                cin >> word;
                cout << "Enter value: ";
                cin >> meaning;
                temp = obj.insert(temp, word, meaning);
                cout << "Inserted key-value pair: " << word << ":" << meaning << endl;
                break;

            case 2:

                cout << "Enter key to search: ";
                cin >> word;
                if(obj.search(temp,word)){
                    cout<<"\nFound"<<endl;
                }
                else{
                    cout<<"\nNot Found"<<endl;
                }
                break;

            case 3:
                    cout << "Preorder traversal: ";
                    obj.preorder(temp);
                    cout << endl;
                    break;
            case 4:

                cout << "Inorder traversal: ";
                obj.inorder(temp);
                cout << endl;
                break;

            case 5:
                cout << "Quitting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
