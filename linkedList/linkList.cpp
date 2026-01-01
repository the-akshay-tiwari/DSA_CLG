# include <iostream>
using namespace std;

struct node{    
  int data;
  node *next;
};

node *even, *odd ,*first , *temp , *ttemp, *p, *ptemp, *ntemp ,*nttemp , *mtemp ,*mttemp,*nptemp,*mptemp;

void init(){
  first=temp=ttemp=NULL;

}

void create_first(int x){
  first = new node;
  first -> next = NULL;
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

void add_After(int x , int y){
  temp =first;
  while(temp -> data != x){
    temp = temp -> next; 
  }
  ttemp = temp-> next;
  p = new node;
  p->data=y;
  temp ->next = p;
  p-> next= ttemp;
}

void add_Before(int x , int y){
  temp=first;
  ttemp=temp->next;
  while(ttemp->data!=x){
    ttemp=ttemp->next;
    temp=temp->next;
  }
  /*or we can do
    temp=first;
    while(temp->data!=x){
      ttemp=temp
      temp=temp->next
    } */
  p = new node;
  p->data=y;
  temp ->next = p;
  p-> next= ttemp;

}

void add_Before_First(int x){
  temp =new node;
  temp->data=x;
  temp->next=first;
  first=temp;
}

void add_Before_Last(int y){
  temp=first;
  //ttemp=temp->next;
  while(ttemp->next!=NULL){
    // ttemp=ttemp->next;
    // temp=temp->next;
    ttemp=temp;
    temp=temp->next;
  }
  p = new node;
  p->data=y;
  temp ->next = p;
  p-> next= ttemp;
}  
void del_After(int x){
  temp = first;
  while(temp->data!=x){
    temp = temp->next;
  }
    ttemp = temp->next;
    p=ttemp->next;
    temp->next=p;
    ttemp-> next= NULL;
    delete ttemp;
}

void del_Before(int x){
  temp=first;
  while(temp->next->data!=x){
    ttemp=temp;
    temp=temp->next;
  }
  p=temp->next;
  ttemp->next=p;
  temp->next=NULL;
  delete temp;
}

void reverse(){
  temp = first;
  ptemp=NULL;
  ntemp=NULL;
  while(temp!=NULL){
    ntemp=temp->next;
    temp->next=ptemp;
    ptemp=temp;
    temp=ntemp;
  }
  first=ptemp;
}

void del_Sec_Last(){
  temp=first;
  while(temp->next->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  p=temp->next;
  ttemp->next=p;
  temp->next=NULL;
  delete temp;
}

void swap12(){
  temp=first;
  ttemp=temp->next;
  p=ttemp->next;
  ttemp->next=temp;
  temp->next=p;
  first=ttemp;
}

void swapfl(){
  temp=first;
  while(temp->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  temp->next=first->next;
  ttemp->next=first;
  first->next=NULL;
  first=temp;
}

void swapSecLast_Last(){
  temp = first;
  while(temp->next->next!=NULL){
    ttemp=temp;
    temp=temp->next;
  }
  ttemp->next=temp->next;
  temp->next->next=temp;
  temp->next=NULL;
}

void swap_m_n(int m,int n){
  mtemp=first;
  ntemp=first;

  for(int i=1;i<m;i++){
    mptemp=mtemp;
    mtemp=mtemp->next;
    mttemp=mtemp->next;
  }
  for(int i=1;i<n;i++){
    nptemp=ntemp;
    ntemp=ntemp->next;
    nttemp=ntemp->next;
  }
  mtemp->next=nttemp;
  ntemp->next=mttemp;
  nptemp->next=mtemp;
  mptemp->next=ntemp;

}


int main(){
  init();
  create_first(1);
  add_node(2);
  add_node(3);
  add_node(4);
  add_node(5);
  add_node(6);
  add_node(7);
  add_node(8);
  add_node(9);
  display();
  swap_m_n(4,7);
  display();

  return 0;
}