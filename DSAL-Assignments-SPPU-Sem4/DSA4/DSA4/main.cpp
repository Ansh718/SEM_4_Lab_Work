//
//  main.cpp
//  DSA4
//
//  Created by ANSH BHUTADA on 05/06/23.
//
#include <iostream>
#include <string>
#define size 11
using namespace std;
class DataItem{
    string name;
    long long int data;
public:
    DataItem();
    friend class Hash;
};
DataItem::DataItem(){};
class Hash{
    DataItem ht[size];
public:
    Hash();
    int hashCode(long long int);
    void insertWOR(long long int,string);
    void insertWR(long long int,string);
    void display();
    void search(long long int);
    void deleteFunction(long long int);
};
Hash::Hash(){
    for(int i=0;i<size;i++){
        ht[i].name="default";
        ht[i].data=-1;
    }
}
int Hash::hashCode(long long int data){
    return data%size;
}
void Hash::insertWOR(long long int data,string name){
    int temp=hashCode(data);
    if(ht[temp].data==-1){
        ht[temp].data=data;
        ht[temp].name=name;
    }else{
        while(ht[temp].data!=-1){
            if(temp==size-1){
                temp=0;
                continue;
            }else{
                temp++;
            }
        }
        ht[temp].data=data;
        ht[temp].name=name;
    }
}
void Hash::insertWR(long long int data,string name){
    int temp=hashCode(data);
    if(ht[temp].data==-1){
        ht[temp].data=data;
        ht[temp].name=name;
    }else{
        if(hashCode(ht[temp].data)==temp){
            while(ht[temp].data!=-1){
                if(temp==size-1){
                    temp=0;
                    continue;
                }else{
                    temp++;
                }
            }
            ht[temp].data=data;
            ht[temp].name=name;
        }else{
            long long int prevdata=ht[temp].data;
            string prevname=ht[temp].name;
            ht[temp].data=data;
            ht[temp].name=name;
            while(ht[temp].data!=-1){
                if(temp==size-1){
                    temp=0;
                    continue;
                }else{
                    temp++;
                }
            }
            ht[temp].data=prevdata;
            ht[temp].name=prevname;
        }
    }
}
void Hash::display(){
    for(int i=0;i<size;i++){
        cout<<i<<" \t "<<ht[i].name<<" \t "<<ht[i].data<<endl;
    }
}
void Hash::search(long long int data){
    int temp=hashCode(data);
    if(ht[temp].data==-1){
        cout<<"\nData Not Present!"<<endl;
        return;
    }else{
        while(ht[temp].data!=-1){
            if(ht[temp].data==data){
                cout<<"\nData Found!"<<endl;
                return;
            }else{
                ++temp;
                temp%=size;
            }
        }
    }
}
void Hash::deleteFunction(long long int data){
    int temp=hashCode(data);
    if(ht[temp].data==-1){
        cout<<"\nData Not Present!"<<endl;
        return;
    }else{
        if(ht[temp].data==data){
            ht[temp].data=-1;
            ht[temp].name="default";
            int temp2=temp,temp3=temp+1;
            while(hashCode(ht[temp3].data)==temp2){
                ht[temp].data=ht[temp3].data;
                ht[temp].name=ht[temp3].name;
                ht[temp3].data=-1;
                ht[temp3].name="default";
                temp=temp3;
                temp3++;
            }
        }else{
            while(ht[temp].data!=-1){
                if(ht[temp].data==data){
                    break;
                }else{
                    ++temp;
                    temp%=size;
                }
            }
            int temp2=temp,temp3=temp+1;
            ht[temp].data=-1;
            ht[temp].name="default";
            while(hashCode(ht[temp3].data)==temp2-1){
                ht[temp].data=ht[temp3].data;
                ht[temp].name=ht[temp3].name;
                ht[temp3].data=-1;
                ht[temp3].name="default";
                temp=temp3;
                temp3++;
            }
        }
    }
}
int main(){
    Hash a;
    a.insertWR(10,"q");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(10,"q");
    a.insertWR(21,"w");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(21,"w");
    a.insertWR(22,"r");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(22,"r");
    a.insertWR(12,"t");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(12,"t");
    a.insertWR(60,"o");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(60,"o");
    a.insertWR(71,"i");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(71,"i");
    a.insertWR(93,"y");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(93,"y");
    a.insertWR(109,"e");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(109,"e");
    a.insertWR(46,"k");
//    a.display();
//    cout<<"\n\n";
//    a.insertWOR(46,"k");
    a.display();
//    a.search(60);
//    cout<<"\n";
//    a.search(20);
//    cout<<"\n";
    a.deleteFunction(71);
    cout<<"\n";
    a.display();
    return 0;
}
