
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX=50
int top=-1;
char s[],ch;
void push(char ch){
 s[++top]=ch;
 }

char pop(){
 return s[top--];
 }

int pr(char symbol){
 if (ch=='^')
    return (3);
 else if (ch=='*' ||ch=='/')
        return (2);
 else if (ch=='+' ||ch=='-')
      return (1);
 else
    return (0);
}

void main(){
    char infix[50],postfix[50],ch,elem;
    int i=0,k=0;
    printf("Enter infix expression:");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0'){
        if(ch=='('){
            push(ch);
           }
        else if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else{
            if(ch==')'){
                while(s[top]!='('&&s[top]!='#'){
                        postfix[k++]=pop();
                        elem=pop();
                }
            }
            else{
                while(pr(s[top])>pr(ch)){
                    postfix[k++]=pop();
                }
                push(ch);
                }
            }

            }
    while(s[top]!='#'){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("POstfix expression is %s",postfix);
}


