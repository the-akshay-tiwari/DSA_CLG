# include <iostream>
using namespace std;

struct node{
  int data;
  node *next,*pre;
};

node *first , *temp , *ttemp, *p, *ptemp, *ntemp ;

void init(){
  first=temp=ttemp=NULL;

}

void create_first(int x){
  first = new node;
  first -> next = NULL;
  first->pre=NULL;
  // cout<<"enter data for first node : ";
  // cin>>first->data;
  first->data=x;
}

void add_node(int x){
  temp=first;
  while(temp -> next !=NULL){
    temp=temp -> next;
  }
  ttemp=new node;
  ttemp -> next =NULL;
  ttemp->data=x;
  ttemp->pre=temp;
  temp -> next =ttemp;
}

void display(){
  temp = first;
  while(temp !=NULL){
  cout<<temp -> data<<" ";
  temp=temp->next;
  }
  cout<<endl;
}

void add_after(int x , int y){
    temp=first;
    while(temp->data!=x){
      temp=temp->next;
      ttemp=temp->next;
    }
    p=new node;
    p->data=y;
    temp->next=p;
    p->pre=temp;
    p->next=ttemp;
    ttemp->pre=p;
}

void add_before(int x , int y){
  temp=first;
  while(temp->data!=x){
      ttemp=temp;
      temp=temp->next;
  }
  p=new node;
  p->data=y;
  p->next=temp;
  temp->pre=p;
  ttemp->next=p;
  p->pre=ttemp;
}

void add_before_first(int x){
  temp= new node;
  temp->data=x;
  temp->pre=NULL;
  temp->next=first;
  first->pre=temp;
  first=temp;

}

void add_before_last(int y){
  temp=first;
  while(temp->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  p= new node;
  p->data=y;
  p->next=temp;
  temp->pre=p;
  ttemp->next=p;
  p->pre=ttemp;
}

void del_after(int x){
  temp=first;
  while(temp->data!=x){
    temp=temp->next;
  }
  ttemp=temp->next;
  temp->next=ttemp->next;
  ttemp->next->pre=temp;
  ttemp->next=ttemp->pre=NULL;
  delete ttemp;
}

void del_before(int x){
  temp=first;
  while(temp->next->data!=x){
    temp=temp->next;
  }
  ttemp=temp->pre;
  ttemp->next=temp->next;
  temp->next->pre=ttemp;
  temp->next=temp->pre=NULL;
  delete temp;
}

void swap12(){
  temp=first;
  ttemp=temp->next;
  p=ttemp->next;
  ttemp->next=temp;
  ttemp->pre=NULL;
  temp->next=p;
  temp->pre=ttemp;
  first=ttemp;
}

int main(){
  init();
  create_first(10);
  add_node(20);
  add_node(30);
  add_node(40);
  add_node(50);
  display();
  del_before(30);
  display();
  return 0;
}