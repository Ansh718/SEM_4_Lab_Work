//
//  main.cpp
//  DSA3
//
//  Created by ANSH BHUTADA on 06/06/23.
//
#include <iostream>
using namespace std;
class Node{
    int data;
    Node* lchild;
    Node* rchild;
    bool l,r;
public:
    Node();
    Node(int);
    friend class TBST;
};
Node::Node(){
    data=0;
    lchild=rchild=NULL;
    l=r=0;
}
Node::Node(int data){
    this->data=data;
    lchild=rchild=NULL;
    l=r=0;
}
class TBST{
    Node* root;
    Node* header;
public:
    TBST();
    Node* getRoot();
    void insert(int);
    void inorder(Node*);
    void preorder(Node*);
    void search(int,Node*&,Node*&);
    void deleteFunction(int);
};
TBST::TBST(){
    root=header=NULL;
}
Node* TBST::getRoot(){
    return root;
}
void TBST::insert(int data){
    if(root==NULL){
        header=new Node(-1);
        root=new Node(data);
        header->lchild=root;
        header->l=1;
        header->rchild=header;
        root->lchild=header;
        root->rchild=header;
    }else{
        Node* temp=root;
        while(true){
            if(data<temp->data){
                if(temp->l==1){
                    temp=temp->lchild;
                }else{
                    Node* temp1=new Node(data);
                    temp1->lchild=temp->lchild;
                    temp1->rchild=temp;
                    temp->lchild=temp1;
                    temp->l=1;
                    break;
                }
            }else{
                if(temp->r==1){
                    temp=temp->rchild;
                }else{
                    Node* temp1=new Node(data);
                    temp1->lchild=temp;
                    temp1->rchild=temp->rchild;
                    temp->rchild=temp1;
                    temp->r=1;
                    break;
                }
            }
        }
    }
}
void TBST::inorder(Node* temp){
    if(temp==NULL){
        return;
    }else{
        while(temp->l==1){
            temp=temp->lchild;
        }
        while(temp!=header){
            cout<<temp->data<<" ";
            if(temp->r==1){
                temp=temp->rchild;
                while(temp->l==1){
                    temp=temp->lchild;
                }
            }else{
                temp=temp->rchild;
            }
        }
    }
}
void TBST::preorder(Node* temp){
    if(temp==NULL){
        return;
    }else{
        while(temp!=header){
            cout<<temp->data<<" ";
            if(temp->l==1){
                temp=temp->lchild;
            }
            else if(temp->r==1){
                temp=temp->rchild;
            }else{
                while(temp!=header && temp->r==0){
                    temp=temp->rchild;
                }
                if(temp!=header){
                    temp=temp->rchild;
                }
            }
        }
    }
}
void TBST::search(int data,Node*& current,Node*& parent){
    while(current!=header){
        if(data<current->data){
            parent=current;
            current=current->lchild;
        }
        else if(data>current->data){
            parent=current;
            current=current->rchild;
        }else{
            cout<<"\nFound!"<<endl;
            return;
        }
    }
    cout<<"\nNot Foubnd!"<<endl;
}
void TBST::deleteFunction(int data){
    Node* parent=NULL;
    Node* current=root;
    Node* temp=NULL;
    Node* temp1=NULL;
    search(data,current,parent);
    if(current->l==1 && current->r==1){
        temp=current;
        temp1=current->rchild;
        while(temp1->l!=0){
            temp=temp1;
            temp1=temp1->lchild;
        }
        current->data=temp1->data;
        current=temp1;
        parent=temp;
    }
    if(current->l==0 && current->r==0){
        if(parent==NULL && current==root){
            root=NULL;
        }
        else if(parent->lchild==current){
            parent->lchild=current->lchild;
            parent->l=current->l;
        }else{
            parent->rchild=current->rchild;
            parent->r=current->r;
        }
    }
    if(current->l==1 && current->r==0){
        temp=current->lchild;
        if(parent->lchild==current){
            temp->rchild=current->rchild;
            temp->r=current->r;
            parent->lchild=temp;
        }else{
            temp->rchild=current->rchild;
            temp->r=current->r;
            parent->rchild=temp;
        }
        delete current;
    }
    if(current->l==0 && current->r==1){
        temp=current->rchild;
        if(parent->lchild==current){
            temp->lchild=current->lchild;
            temp->l=current->l;
            parent->lchild=temp;
        }else{
            temp->lchild=current->lchild;
            temp->l=current->l;
            parent->rchild=temp;
        }
        delete current;
    }
}
int main(){
    TBST a;
    int chc, flag = 1;
    int num;
    while (flag){
        cout
            << "Enter your choice : \n 1.Insert \n 2.Inorder \n 3.Preorder\n 4.Search\n 5.Delete\n"
            << endl;
        cin >> chc;
        switch (chc)
        {
            case 1:{
                cout << "Enter the Number:" << endl;
                cin >> num;
                a.insert(num);
                break;
            }
            case 2:{
                cout << "Inorder: " << endl;
                a.inorder(a.getRoot());
                break;
            }
            case 3:{
                cout << "Preorder: " << endl;
                a.preorder(a.getRoot());
                break;
            }
            case 4:{
                cout << "Enter the Number you want to search :" << endl;
                cin >> num;
                Node* current=a.getRoot();
                Node* parent=NULL;
                a.search(num,current,parent);
                break;
            }
            case 5:{
                cout << "Enter the Number you want to delete :" << endl;
                cin >> num;
                a.deleteFunction(num);
                break;
            }
            default:{
                cout << "Enter valid choice" << endl;
                break;
            }
        }
        cout << "Do you want to continue?(1/0):" << endl;
        cin >> flag;
    }
    return 0;
}
