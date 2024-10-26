#include<stdio.h>
#include<ctype.h>
#include<string.h>

int getPrecedence(char a){
    switch(a){
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-' : return 1; 
        default : return 0;
    }
}
int main(){

    char eq[] = "a+(b*c+d*(e*f)+g)";
    char arr[100];
    int arrTop = -1;
    char postfix[100];
    int postfixTop = -1;
    printf("Length of eq: %d\n",strlen(eq));
    for(int i=0 ; i<strlen(eq);i++){
        if(isalnum(eq[i])){
            postfix[++postfixTop] = eq[i];
        }
        else{
            if(eq[i]=='(')
            {
                arr[++arrTop] = eq[i];
            }
            else if(eq[i]==')')
            {
                while(arrTop!=-1 && arr[arrTop]!='('){
                    postfix[++postfixTop] = arr[arrTop--];
                }
                arrTop--;
            }
            else{
                while(arrTop!=-1 && getPrecedence(arr[arrTop])>= getPrecedence(eq[i])){
                    postfix[++postfixTop] = arr[arrTop--];
                }
                arr[++arrTop] = eq[i];
            }
        }
    }
    for(int i=arrTop;i>-1;i--){
        postfix[++postfixTop] = arr[arrTop--];
    }
    printf("Equation : %s",eq);
    printf("Postfix Expression : ");
    for(int i = 0;i<=postfixTop;i++){
        printf("%c ",postfix[i]);
    }
}