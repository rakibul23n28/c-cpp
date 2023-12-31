#include<iostream>
#include<stack>
std::string infix_to_postfix(const std::string& infix);
bool is_operator(const char ch);
int precedence(const char op);

int main(){
    std::string infix,postfix;
    std::cout<<"enter a infix Expression: "<<std::endl;
    std::getline(std::cin, infix);
    std::cout<<"Infix Expression: "<<infix<<std::endl;
    postfix = infix_to_postfix(infix);

    std::cout<<"postfix Expression: "<<postfix<<std::endl;
    
    return 0;
}

std::string infix_to_postfix(const std::string& infix){
    std::stack<char> stack;
    std::string postfix;
    for(int i=0;i<infix.length();i++){
        if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z'))  postfix+=infix[i];
        else if(infix[i]=='(') stack.push(infix[i]);
        else if(infix[i]==')'){
            while ((!stack.empty()) && stack.top()!='(')
            {
                char temp=stack.top();
                postfix+=temp;
                stack.pop();
            }
            if(stack.top()=='(') stack.pop();
        }
        else if(is_operator(infix[i])){
            if(stack.empty()) stack.push(infix[i]);
            else if(!stack.empty()){
                if(precedence(infix[i])>precedence(stack.top())){
                    stack.push(infix[i]);
                }
                else if (infix[i] == '^' && precedence(infix[i]) == precedence(stack.top())){
                    stack.push(infix[i]);
                }
                else{
                    while ( (!stack.empty() )&& (precedence(infix[i])<=precedence(stack.top())))
                    {
                        char temp=stack.top();
                        postfix+=temp;
                        stack.pop();
                    }
                    stack.push(infix[i]);
                }
            }
        }
    }
    while ( !stack.empty() )
    {
        postfix+=stack.top();
        stack.pop();
    }
    
    return postfix;
}
bool is_operator(const char ch){
    return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}
int precedence(const char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^') return 3;
    return 0;
}