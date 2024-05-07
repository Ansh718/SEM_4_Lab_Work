//
//  main.cpp
//  DSA10
//
//  Created by ANSH BHUTADA on 05/06/23.
//
#include <iostream>
using namespace std;
class Heap{
public:
    int* arr;
    int n;
    Heap();
    void create();
    void swap(int&,int&);
    void creator1(int [],int,int);
    void maxHeap(int []);
    void creator2(int [],int,int);
    void minHeap(int []);
    void heapSort(int []);
    void display();
    void insert(int []);
    void deleteFunction(int []);
};
Heap::Heap(){
    cout<<"\nEnter the number of elements:-> "<<endl;
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
}
void Heap::create(){
    int root=0,lchild=0,rchild=0;
    cout<<"\nEnter the data of the root:-> "<<endl;
    cin>>root;
    arr[0]=root;
    for(int i=0;i<n;i++){
        if(2*i+1<n){
            cout<<"\nEnter the data of the left child of "<<arr[i]<<" :-> "<<endl;
            cin>>lchild;
            arr[2*i+1]=lchild;
        }
        if(2*i+2<n){
            cout<<"\nEnter the data of the right child of "<<arr[i]<<" :-> "<<endl;
            cin>>rchild;
            arr[2*i+2]=rchild;
        }
    }
}
void Heap::swap(int& a,int& b){
    int temp=a;
    a=b;
    b=temp;
}
void Heap::creator1(int* arr,int n,int i){
    int largest=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if (r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        creator1(arr,n,largest);
    }
}
void Heap::maxHeap(int* arr){
    for(int i=(n/2)-1;i>=0;i--){
        creator1(arr,n,i);
    }
}
void Heap::creator2(int* arr,int n,int i){
    int smallest=i,l=2*i+1,r=2*i+2;
    if(l<n && arr[l]<arr[smallest]){
        smallest=l;
    }
    if (r<n && arr[r]<arr[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        creator2(arr,n,smallest);
    }
}
void Heap::minHeap(int* arr){
    for(int i=(n/2)-1;i>=0;i--){
        creator2(arr,n,i);
    }
}
void Heap::heapSort(int* arr){
    for(int i=(n/2)-1;i>=0;i--){
        creator1(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        creator1(arr,i,0);
    }
}
void Heap::display(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void Heap::insert(int* arr){
    int temp=0;
    cout<<"\nEnter the number you want to insert:-> "<<endl;
    cin>>temp;
    n++;
    arr[n-1]=temp;
    int i=n-1;
    while(i>0 && arr[i]>arr[(i-1)/2]){
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void Heap::deleteFunction(int* arr){
    swap(arr[0],arr[n-1]);
    n=n-1;
    creator1(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    Heap h;
    h.create();
    h.display();
    cout<<"\n\n";
    h.heapSort(h.arr);
    h.display();
    cout<<"\n\n";
    h.maxHeap(h.arr);
    h.display();
    cout<<"\n\n";
    h.minHeap(h.arr);
    h.display();
    cout<<"\n\n";
    return 0;
}
