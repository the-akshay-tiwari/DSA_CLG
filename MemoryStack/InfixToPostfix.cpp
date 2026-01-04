# include <iostream>
using namespace std;

struct Lstack{
  int data;
  Lstack *next; 
};

Lstack *top,*temp;

void init(){
  top=temp=NULL;
}

void push(int x){
  temp= new Lstack;
  if(temp==NULL){
    return;
  }
  temp->data = x;
  temp->next=top;
  top=temp;
}

int pop(){
  int x;
  if(top==NULL){
    return x;
  }
  x=top->data;
  temp=top;
  top=top->next;
  temp->next=NULL;
  delete temp;
  return x;
}

int main(){

  init();
  string str;
  string post="";
  cout<<"Enter the infix expression : ";
  cin>>str;

  for(int i=0;i<str.length();i++){
    if(str[i]=='('){
      push(str[i]);
    }
    else if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
      post+=str[i];
    }
    else if(str[i]==')'){
      while(top->data!='('){
        post+=pop();
      }
      pop();
    }
    else /*if(str[i]=='^' ||str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' )*/{
      switch(str[i]){
        case '^' : push(str[i]);break;

        case '/' : 

        case '*' : while(top->data=='^' || top->data=='/' || top->data=='*'){
                      post+=pop();
                   }
                   push(str[i]);
                   break;
           
        case '+' : 

        case '-' : while(top->data!='('){
                      post+=pop();
                   }
                   push(str[i]);
                   break;    
      }
    }
  }
  cout<<post;


  return 0;
}