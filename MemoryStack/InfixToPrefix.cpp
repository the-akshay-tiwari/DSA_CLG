# include <iostream>
# include <string>
using namespace std;

struct Lstack{
  string data;
  Lstack *next; 
};

Lstack *oprtr,*oprnd,*temp,*ptemp,*ntemp;

void init(){
  oprtr=oprnd=temp=NULL;

}

void push(string x ,Lstack **top){
  temp= new Lstack;
  if(temp==NULL){
    return;
  }
  temp->data = x;
  temp->next=*top;
  *top=temp;
}

string pop(Lstack *&top){
  string x;
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
  cout<<"Enter the infix expression : ";
  cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='('){
      push(string(1, str[i]) , &oprtr);
    }

    else if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
      push(string(1, str[i]) , &oprnd);
    }

    else if(str[i]==')'){
      while(oprtr->data!="("){
        string str1=pop(oprnd);
        string str2=pop(oprnd);
        string str3=pop(oprtr);
        push(str3+str2+str1, &oprnd);
      }
      pop(oprtr);
    }

    else if(oprtr!=NULL){
      switch(str[i]){
        case '^' : push(string(1,str[i]),&oprtr);break;

        case '/' : 

        case '*' : while(oprtr->data=="^" || oprtr->data=="/" || oprtr->data=="*"){
                      string str1=pop(oprnd);
                      string str2=pop(oprnd);
                      string str3=pop(oprtr);
                      push(str3+str2+str1, &oprnd);
                   }
                   push(string(1,str[i]),&oprtr);
                   break;
           
        case '+' : 

        case '-' : while(oprtr->data!="("){
                      string str1=pop(oprnd);
                      string str2=pop(oprnd);
                      string str3=pop(oprtr);
                      push(str3+str2+str1, &oprnd);
                   }
                   push(string(1,str[i]),&oprtr);
                   break;    
      }
    }


  }
  cout<<oprnd->data;


  return 0;
}