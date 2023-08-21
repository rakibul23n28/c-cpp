#include<iostream>
#include<stack>
using namespace std;
string infix_to_prefix( string& infix);
bool is_operator(const char& ch);
bool is_operant(const char& ch);
int precedence(const char& ch);
void reverse(string& infix);


int main(){
    string infix,prefix;
    cout<<"enter a infix Expression: "<<endl;
    getline(cin, infix);
    cout<<"Infix Expression: "<<infix<<endl;
    prefix = infix_to_prefix(infix);

    cout<<"Prefix Expression: "<<prefix<<endl;
    return 0;
}
string infix_to_prefix( string& infix){
    stack<char> stack;
    string prefix;
    reverse(infix);
    for(int i=0;i<infix.length();i++){
        if(is_operant(infix[i])) prefix+=infix[i];
        else if(infix[i]=='(') stack.push(infix[i]);
        else if(infix[i]==')'){
            while((!stack.empty()) && stack.top()!='('){
                prefix+=stack.top();
                stack.pop();
            }
            if(stack.top()=='(') stack.pop();
        }
        else if(is_operator(infix[i])){
            if(stack.empty()) stack.push(infix[i]);
            else{
                if(precedence(infix[i]) > precedence(stack.top())) stack.push(infix[i]);
                else if((precedence(infix[i]) == precedence(stack.top())) && (infix[i]=='^')){
                    while ( (!stack.empty()) && (precedence(infix[i]) == precedence(stack.top())) && (infix[i]=='^'))
                    {
                        prefix+=stack.top();
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }
                else if(precedence(infix[i]) == precedence(stack.top())) stack.push(infix[i]);
                else{
                    while ((!stack.empty()) && (precedence(infix[i]) < precedence(stack.top())))
                    {
                        prefix+=stack.top();
                        stack.pop();
                    }
                    stack.push(infix[i]);
                    
                }
            }
        }
    }
    while ( !stack.empty() )
    {
        prefix+=stack.top();
        stack.pop();
    }
    reverse(prefix);
    return prefix;
    
}

bool is_operator(const char& ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}
bool is_operant(const char& ch){
    return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
}
int precedence(const char& ch){
    if(ch=='+'||ch=='-') return 1;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='^') return 3;
    else return -1;
}

void reverse(string& infix){
    int len=infix.length();
    for(int i=0;i<len/2;i++){
        char temp=infix[i];
        infix[i]=infix[len-1-i];
        infix[len-i-1]=temp;
    }
    for(int i=0;i<len;i++){
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }
}

