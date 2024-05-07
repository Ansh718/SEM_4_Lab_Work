//
//  main.cpp
//  DSA8
//
//  Created by ANSH BHUTADA on 06/06/23.
//

#include <iostream>
using namespace std;
class Node{
    char data;
    Node* lchild;
    Node* rchild;
public:
    Node();
    Node(char);
    friend class OBST;
};
Node::Node(){
    lchild=rchild=NULL;
}
Node::Node(char data){
    this->data=data;
    lchild=rchild=NULL;
}
class OBST{
    Node* root;
    int n;
    char* input;
    double* p;
    double* q;
    double** w;
    double** c;
    double** r;
public:
    OBST();
    Node* getRoot();
    void getInfo();
    void calculateWeight();
    void display();
    Node* create(int,int);
    void inorder(Node* root);
    void preorder(Node* root);
    void postorder(Node* root);
};
OBST::OBST(){
    root=NULL;
    p=q=NULL;
    input=NULL;
    n=0;
}
Node* OBST::getRoot(){
    return root;
}
void OBST::getInfo(){
    cout<<"\nEnter the number of identifiers:-> "<<endl;
    cin>>n;
    input=new char[n+1];
    input[0]=' ';
    for(int i=1;i<n+1;i++){
        cout<<"I"<<i<<" :-> "<<endl;
        cin>>input[i];
    }
    p=new double[n];
    for(int i=0;i<n;i++){
        cout<<"p"<<i<<" :-> "<<endl;
        cin>>p[i];
    }
    q=new double[n+1];
    for(int i=0;i<n+1;i++){
        cout<<"q"<<i<<" :-> "<<endl;
        cin>>q[i];
    }
    this->calculateWeight();
}
void OBST::calculateWeight(){
    w=new double*[n+1];
    c=new double*[n+1];
    r=new double*[n+1];
    for(int i=0;i<n+1;i++){
        w[i]=new double[n+1];
        c[i]=new double[n+1];
        r[i]=new double[n+1];
    }
    for(int i=0;i<n;i++){
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
        w[i][i+1]=q[i]+p[i]+q[i+1];
        c[i][i+1]=w[i][i+1];
        r[i][i+1]=i+1;
    }
    w[n][n]=q[n];
    c[n][n]=r[n][n]=0;
    for(int m=2;m<=n;m++){
        for(int i=0;i<=n-m;i++){
            double min=999;
            int j=i+m;
            int k=0;
            w[i][j]=w[i][j-1]+p[j-1]+q[j];
            for(int l=i+1;l<=j;l++){
                double sum=c[i][l-1]+c[l][j];
                if(sum<min){
                    min=sum;
                    k=l;
                }
            }
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
    root=create(0,n);
}
Node* OBST::create(int i,int j){
    if(i!=j){
        int k=r[i][j];
        Node* temp=new Node(input[k]);
        temp->lchild=create(i,k-1);
        temp->rchild=create(k,j);
        return temp;
    }else{
        return NULL;
    }
}
void OBST::display(){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            cout<<"{"<<w[j][i]<<","<<c[j][i]<<","<<r[j][i]<<"}"<<" ";
        }
        cout<<"\n";
    }
    cout<<"\nThe minimum cost is :-> "<<c[0][n]<<endl;
}
void OBST::inorder(Node* temp){
    if(temp!=NULL){
    inorder(temp->lchild);
    cout<<temp->data<<" ";
    inorder(temp->rchild);
    }
}
void OBST::preorder(Node* temp){
    if(temp!=NULL){
    cout<<temp->data<<" ";
    preorder(temp->lchild);
    preorder(temp->rchild);
    }
}
void OBST::postorder(Node* temp){
    if(temp!=NULL){
    postorder(temp->lchild);
    postorder(temp->rchild);
    cout<<temp->data<<" ";
    }
}
int main(){
    //    string input[]={" ","a","b","c","d};
    //    double p[]={0.1875, 0.1875, 0.0625,0.0625};
    //    double q[]={0.125,0.1875,0.0625,0.0625,0.0625};
        OBST obj;
        obj.getInfo();
        while(true){
            int option=0;
            obj.calculateWeight();
            cout<<"\n1.Inorder\n2.Preoder\n3.Postorder\n4.Display Mat\n5.Exit\nChose an option:";
            cin>>option;
            if(option==1){
                obj.inorder(obj.getRoot());
                cout<<endl;
            }
            else if(option==2){
                obj.preorder(obj.getRoot());
                cout<<endl;
            }
            else if(option==3){
                obj.postorder(obj.getRoot());
                cout<<endl;
            }
            else if(option==4){
                obj.display();
            }
            else{
                cout<<"\n-----------THANK YOU !!!!----------\n";
                break;
            }
        }
        return 0;
}
