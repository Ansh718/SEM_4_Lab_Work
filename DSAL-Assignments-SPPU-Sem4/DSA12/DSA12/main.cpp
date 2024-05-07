//
//  main.cpp
//  DSA12
//
//  Created by ANSH BHUTADA on 06/06/23.
//
#include <iostream>
#include <fstream>
#include <string>
#define size 10
using namespace std;
class Hash{
    int empId,location;
public:
    Hash();
    int hashCode(int);
    void create();
    void show();
    void insert(int,int);
    int search();
    friend class MYF;
}Ht[size];
Hash::Hash(){
    empId=location=0;
}
int Hash::hashCode(int temp){
    return temp%size;
}
void Hash::create(){
    for(int i=0;i<size;i++){
        Ht[i].empId=Ht[i].location=0;
    }
}
void Hash::show(){
    for(int i=0;i<size;i++){
        cout<<i<<"\n"<<Ht[i].empId<<" :-> "<<Ht[i].location<<endl;
    }
}
void Hash::insert(int temp,int temp1){
    int hashIndex=hashCode(temp);
    if(Ht[hashIndex].location==0){
        Ht[hashIndex].empId=temp;
        Ht[hashIndex].location=temp1;
    }else{
        while(Ht[hashIndex].location!=0){
            if(hashIndex==size-1){
                hashIndex=0;
            }else{
                hashIndex++;
            }
        }
        Ht[hashIndex].empId=temp;
        Ht[hashIndex].location=temp1;
    }
}
int Hash::search(){
    int hashIndex=0,temp1=0;
    cout<<"\nEnter the employee Id you want to search:-> "<<endl;
    cin>>temp1;
    hashIndex=hashCode(temp1);
    if(Ht[hashIndex].empId==temp1){
        return Ht[hashIndex].location;
    }else{
        while(Ht[hashIndex].empId!=temp1){
            if(Ht[hashIndex].empId==temp1){
                break;
            }else{
                ++hashIndex;
                hashIndex%=size;
            }
        }
        return Ht[hashIndex].location;;
    }
}
class MYF{
    char b[40],fname[40];
    int empid,cnt;
    string name,address;
    fstream f;
    Hash Ht;
public:
    MYF();
    void write();
    void read();
    void search();
};
MYF::MYF(){
    empid=cnt=0;
    name=address="default";
    cout<<"\n Enter name of the file :-> "<<endl;
    cin>>fname;
}
void MYF::write(){
    f.open(fname,ios::out);
    if(!f){
        cout<<"\n ERROR"<<endl;
    }else{
        cout<<"\n SUCCESS"<<endl;
        cout<<"\n Enter the number of records:-> "<<endl;
        cin>>cnt;
        for(int i=0;i<cnt;i++){
            cout<<"\n Enter Id:->"<<endl;
            cin>>empid;
            cout<<"\n Enter Name:->"<<endl;
            cin>>name;
            cout<<"\n Enter Address:->"<<endl;
            cin>>address;
            cout<<"\n Location:-> "<<f.tellp()<<endl;
            Ht.insert(empid,int(f.tellp()));
            f<<empid<<"\t"<<name<<"\t"<<address<<endl;
        }
    }
}
void MYF::read(){
    f.open(fname,ios::in);
    if(!f){
        cout<<"\n ERROR"<<endl;
    }else{
        cout<<"\n SUCCESS"<<endl;
        int i=0;
        while(!f.eof()){
            f.getline(b,40);
            cout<<"\n Record:-> "<<i<<": "<<b<<endl;
            i++;
        }
    }
    f.close();
    cout<<"\n Hash Table:-> "<<endl;
    Ht.show();
}
void MYF::search(){
    f.open(fname,ios::in);
    if(!f){
        cout<<"\n ERROR"<<endl;
    }else{
        cout<<"\nSUCCESS"<<endl;
        int temp=Ht.search();
        f.seekg(temp,ios::beg);
        f.getline(b,40);
        cout<<"\nRecord Found!"<<endl<<b<<endl;
    }
    f.close();
}
int main(){
    MYF ftemp;
    ftemp.write();
    ftemp.read();
    ftemp.search();
    return 0;
}
