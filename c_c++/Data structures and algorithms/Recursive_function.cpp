#include<iostream>
#include<string>


int count_total(int size_of_string,std::string s){
    if  (s[size_of_string] != '\0') return 1+count_total(++size_of_string,s);
    else return 0;
}


int main(){
    std::string word="hello world";
    count_total(0,word);
    std::cout<< count_total(0,word);

    return 0;
}