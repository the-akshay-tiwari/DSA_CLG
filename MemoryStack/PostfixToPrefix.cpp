# include <iostream>
# include <string>
using namespace std;

struct Lstack{
  string data;
  Lstack *next; 
};

Lstack *pre,*temp;

void init(){
  pre=temp=NULL;
}

void push(string x){
  temp= new Lstack;
  if(temp==NULL){
    return;
  }
  temp->data = x;
  temp->next=pre;
  pre=temp;
}

string pop(){
  string x;
  if(pre==NULL){
    return x;
  }
  x=pre->data;
  temp=pre;
  pre=pre->next;
  temp->next=NULL;
  delete temp;
  return x;
}

int main(){

  init();
  string str;
  cout<<"Enter the postfix expression : ";
  cin>>str;

  for(int i=0;i<str.length();i++){
    if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
      push(string(1 ,str[i]));
    }
    else{
      string str1=pop();
      string str2=pop();
      string str3=string(1,str[i]);
      push(str3+str2+str1);
    }
  }

  cout<<pre->data;

  return 0;
}