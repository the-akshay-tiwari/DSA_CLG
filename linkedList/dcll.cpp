# include <iostream>
using namespace std;

struct DCLL{
  int data;
  DCLL *next,*pre;
};

DCLL *first , *temp , *ttemp, *p, *ptemp, *ntemp ,*q ,*r;

void init(){
  first=temp=ttemp=NULL;

}

void create_first(int x){
  first = new DCLL;
  first -> next = first;
  first->pre=first;
  first->data=x;
}

void add_node(int x){
  temp=first->pre;
  ttemp = new DCLL;
  ttemp->data=x;
  ttemp->next=first;
  first->pre=ttemp;
  ttemp->pre=temp;
  temp->next=ttemp;
}

void display(){
  temp=first;
  do{
    cout<<temp->data<<" ";
    temp=temp->next;
  }while(temp!=first);
  cout<<endl;
}

void add_before_first(int x){
  temp = new DCLL;
  temp->data=x;
  temp->pre=first->pre;
  temp->next=first;
  first->pre->next=temp;
  first->pre=temp;
  first=temp;
}

void del_first(){
  temp=first;
  first->next->pre=first->pre;
  first->pre->next=first->next;
  first = first->next;
  temp->next=NULL;
  temp->pre=NULL;
  delete temp;
}

void swapfl(){
  temp=first->pre;
  ttemp=first->pre->pre;
  ttemp->next=first;
  first->pre=ttemp;
  temp->next=first->next;
  first->next->pre=temp;
  first->next=temp;
  temp->pre=first;
  first=temp;
}

void swap_last_sec_last(){
  p=first->pre;
  q=p->pre;
  r=q->pre;
  r->next=p;
  p->pre=r;
  p->next=q;
  q->pre=p;
  q->next=first;
  first->pre=q;

}

void del_last(){
  temp=first->pre;
  temp->pre->next=first;
  first->pre=temp->pre;
  temp->next=NULL;
  temp->pre=NULL;
  delete temp;
}

int main(){
  init();
  create_first(1);
  add_node(2);
  add_node(3);
  add_node(4);
  add_node(5);
  display();
  swap_last_sec_last();
  display();
  return 0;
}