//
//  main.cpp
//  DSA7
//
//  Created by ANSH BHUTADA on 06/06/23.
//
#include <iostream>
using namespace std;
class Graph{
    int nV,nE;
    int** adjMatrix;
public:
    Graph();
    Graph(int,int);
    void create();
    void display();
    int findParent(int,int*);
    void addEdge(int,int,int,int*,int**);
    void kruskal();
    void prim();
};
Graph::Graph(){}
Graph::Graph(int nV,int nE){
    this->nV=nV;
    this->nE=nE;
    adjMatrix=new int*[nV];
    for(int i=0;i<nV;i++){
        adjMatrix[i]=new int[nV];
    }
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            adjMatrix[i][j]=0;
        }
    }
}
void Graph::create(){
    int src=0,dst=0,w=0;
    for(int i=0;i<nE;i++){
        cout<<"\nEnter the edge between :-> "<<endl;
        cin>>src>>dst;
        cout<<"\nEnter the weight of the edge between "<<src<<" & "<<dst<<" :-> "<<endl;
        cin>>w;
        adjMatrix[src][dst]=w;
    }
}
void Graph::display(){
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int Graph::findParent(int temp,int* parent){
    int temp1=temp;
    while(temp1!=parent[temp1]){
        temp1=parent[temp1];
    }
    return temp1;
}
void Graph::addEdge(int temp,int temp1,int weight,int* parent,int** MST){
    int p1=findParent(temp,parent),p2=findParent(temp1,parent);
    if(p1==p2){
        return;
    }
    parent[p2]=p1;
    MST[temp][temp1]=weight;
}
void Graph::kruskal(){
    int** mst;
    int* parent;
    int* visited;
    int cost=0;
    mst=new int*[nV];
    parent=new int[nV];
    visited=new int[nV];
    for(int i=0;i<nV;i++){
        mst[i]=new int[nV];
        parent[i]=i;
        visited[i]=0;
    }
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            mst[i][j]=0;
        }
    }
    for(int i=0;i<nE;i++){
        int min=9999,a=0,b=0;
        for(int j=0;j<nV;j++){
            for(int k=0;k<nV;k++){
                if(adjMatrix[j][k]!=0 && adjMatrix[j][k]<min){
                    min=adjMatrix[j][k];
                    a=j;
                    b=k;
                }
            }
        }
        adjMatrix[a][b]=0;
        addEdge(a,b,min,parent,mst);
    }
    cout<<"\n MST:-> "<<endl;
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            cost+=mst[i][j];
            cout<<mst[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nThe minimum cost is:-> "<<cost<<endl;
}
void Graph::prim(){
    int* key=new int[nV];
    int* parent=new int[nV];
    bool* MST=new bool[nV];
    int cost=0;
    for(int i=0;i<nV;i++){
        key[i]=9999;
        parent[i]=1;
        MST[i]=false;
    }
    int** mst=new int*[nV];
    for(int i=0;i<nV;i++){
        mst[i]=new int[nV];
    }
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            mst[i][j]=0;
        }
    }
    int src=0;
    cout<<"\nEnter source vertex:->"<<endl;
    cin>>src;
    key[src]=0;
    for(int i=0;i<nE;i++){
        int min=9999,k=0;
        for(int j=0;j<nV;j++){
            if(MST[j]!=true && key[j]<min){
                min=key[j];
                k=j;
            }
        }
        MST[k]=true;
        for(int i=0;i<nV;i++){
            if(adjMatrix[k][i]!=0){
                int temp=adjMatrix[k][i];
                if(temp<key[i] && MST[i]!=true){
                    key[i]=temp;
                    parent[i]=k;
                }
            }
        }
    }
    for(int i=1;i<nV;i++){
        int p=parent[i];
        mst[p][i]=key[i];
    }
    cout<<"\nMST:->\n"<<endl;
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            cost+=mst[i][j];
            cout<<mst[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nThe minimum cost is:-> "<<cost<<endl;
}
int main(){
    Graph g(9, 14);
    g.create();
    g.display();
    g.prim();
    cout<<endl;
    g.kruskal();
    cout<<endl;
    return 0;
}
