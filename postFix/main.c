#include<stdio.h>
#include<string.h>
#define max 10
int top=-1;
void push(char stack[],char n);
char pop(char stack[]);
void inputExpression(char a[]);
void evalExpression(char a[],char p[],char stack[]);
void outputPostfix(char a[],char p[]);
int findBracket(char a);
int main(){
    char stack[max];
    char a[15],p[15];
    inputExpression(a);
    evalExpression(a,p,stack);
    outputPostfix(a,p);
    return 0;
}
void push(char stack[],char n){
    if(top==max-1)
        printf("Stack Overflow\n");
    else{
        top++;
        stack[top]=n;
    }
}
char pop(char stack[]){
    char ele;
    if(top==-1)
        printf("Stack UnderFlow!\n");
    else{
        ele=stack[top];
        top--;
    } 
    return ele;
}
void inputExpression(char a[]){
    printf("Please enter the expression to be converted to postfix\n");
    fflush(stdin);
    gets(a);
}
void evalExpression(char a[],char p[],char stack[]){
    int i,pi=0,b;
    char ele;
    for(i=0;i<strlen(a);i++){
        if(a[i]>=48 && a[i]<=57 ||
                a[i]>=65 && a[i]<=90 ||
                a[i]>=97 && a[i]<=122
                )//If number add to postfix expression
        {
            p[pi]=a[i];
            pi++;
        }else if(a[i]==40||
                   a[i]==91||
                   a[i]==123 )//If open bracket push to stack
        {
            push(stack,a[i]);
        }
        else if(a[i]==41||
                    a[i]==93||
                    a[i]==125)//If closed bracket pop all elements till open bracket
        {
            b=findBracket(a[i]);
            if(top!=-1){
                ele=pop(stack);
                while(ele!=b){
                    p[pi]=ele;
                    pi++;
                    ele=pop(stack);
                }
            }
        }
        else if(a[i]==94)//If power operator check is there is another power operator and pushto stack
        {
            if(stack[top]==a[i]){
                ele=pop(stack);
                push(stack,a[i]);
                p[pi]=ele;
                pi++;
            }else
                push(stack,a[i]);
        }
        else if(a[i]==42 || a[i]==47 )//If * or / , anything in lower then push to stack
        {
            if(stack[top]==94 || stack[top]==42 || stack[top]==47){
                ele=pop(stack);
                push(stack,a[i]);
                p[pi]=ele;
                pi++;
            }else{
                push(stack,a[i]);
            }
        }
        else if(a[i]==43||a[i]==45)
        {
            if(stack[top]==94 || 
                stack[top]==42 ||
                stack[top]==47||
                stack[top]==43||
                stack[top]==45)//If + or - check is any higher is in stack
            {
                ele=pop(stack);
                push(stack,a[i]);
                p[pi]=ele;
                pi++;
            }else{
                push(stack,a[i]);
            }
        }
        if(i==strlen(a)-1)//If done with the loop  then pop all elemts in stack
        {
            while(top!=-1){
                p[pi]=pop(stack);
                pi++;
            }
        }
    }
    p[pi]='\0';
}
void outputPostfix(char a[],char p[]){
    printf("The input infix expression is: \n");
    puts(a);
    printf("The resultant postfix expression is\n ");
    puts(p);
}
int findBracket(char a){
    switch (a)
    {
    case ')':
        return 40;
    case '}':
        return 123;
    case ']':
        return 91;
    }
}