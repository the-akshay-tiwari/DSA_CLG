# include <iostream>
using namespace std;

struct CLL{    
  int data;
  CLL *next;
};

CLL *even, *odd ,*first , *temp , *ttemp, *p,*q, *ptemp, *ntemp ,*nttemp , *mtemp ,*mttemp,*nptemp,*mptemp;

void init(){
  first=temp=ttemp=NULL;

}

void create_first(int x){
  first = new CLL;
  first -> next = first;
  // cout<<"enter data for first  : ";
  // cin>>first->data;+
  first->data=x;
}

void add_node(int x){
  temp=first;
  while(temp -> next !=first){
    temp=temp -> next;
  }
  ttemp=new CLL;
  ttemp -> next =first;
  ttemp->data=x;
  temp -> next =ttemp;
}

void display(){
  temp=first;
  do{
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=first);
  cout<<endl;
}

void add_Before_First(int x){
  temp =new CLL;
  temp->data=x;
  temp->next=first;
  ttemp=first;
  while(ttemp -> next !=first){
    ttemp=ttemp -> next;
  }
  first=temp;
  ttemp->next=first;
}

void del_first(){
  temp=first;
  while(temp -> next !=first){
    temp=temp -> next;
  }
  ttemp=first;
  first=first->next;
  temp->next=first;
  ttemp->next=NULL;
  delete ttemp;
}

void del_last(){
  ttemp=first;
  while(ttemp -> next->next !=first){
    ttemp=ttemp -> next;
    temp=ttemp->next;
  }
  ttemp->next=first;
  temp->next=NULL;
  delete temp;
}

void swap12(){
  q=first;
  while(q->next!=first){
    q=q->next;
  }
  temp=first;
  ttemp=temp->next;
  p=ttemp->next;
  ttemp->next=temp;
  temp->next=p;
  first=ttemp;
  q->next=first;

}

void swapSecLast_Last(){
  temp = first;
  while(temp->next->next!=first){
    ttemp=temp;
    temp=temp->next;
  }
  ttemp->next=temp->next;
  temp->next->next=temp;
  temp->next=first;
}

void swapfl(){
  temp=first;
  while(temp->next!=first){
    ttemp=temp;
    temp=temp->next;
  }
  temp->next=first->next;
  ttemp->next=first;
  first->next=temp;
  first=temp;
}

int main(){
  init();
  create_first(1);
  add_node(2);
  add_node(3);
  add_node(4);
  add_node(5);
  add_node(6);
  display();
  swapfl();
  display();
  return 0;
}