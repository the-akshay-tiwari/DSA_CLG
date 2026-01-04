# include <iostream>
# include <string>
using namespace std;

struct Lstack{
  string data;
  Lstack *next; 
};

Lstack *infix,*temp;

void init(){
  infix=temp=NULL;
}

void push(string x){
  temp= new Lstack;
  if(temp==NULL){
    return;
  }
  temp->data = x;
  temp->next=infix;
  infix=temp;
}

string pop(){
  string x;
  if(infix==NULL){
    return x;
  }
  x=infix->data;
  temp=infix;
  infix=infix->next;
  temp->next=NULL;
  delete temp;
  return x;
}

int main(){

  init();
  string str;
  cout<<"Enter the prefix expression : ";
  cin>>str;

  int i=0,j=str.length()-1;

  while(i<=j){
    char temp = str[i];
    str[i]=str[j];
    str[j]=temp;
    i++;
    j--;
  }

  for(int i=0;i<str.length();i++){
    if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
      push(string(1 ,str[i]));
    }
    else{
      string str1=pop();
      string str2=pop();
      string str3=string(1,str[i]);
      push(str1+str3+str2);

    }
  }

  cout<<infix->data;


  return 0;
}