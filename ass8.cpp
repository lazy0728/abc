#include<iostream>
#include<stack>
using namespace std;

void reverseString(char str[]) {

    stack<char> s;
    int i=0;

    cout <<"Orignal String :"<<str;

    while(str[i] != '\0') {

        if(str[i] != ' ') {

            s.push(str[i]);
        }

        i++;
    }

    cout<<"\nReversed String :";

    while(!s.empty())
    {
        cout<<s.top();
        s.pop();

    }


}

void checkPalindrome(char str[]) {

    stack<char> s;
    int i=0;
    int flag =1;

    while(str[i] != '\0') {

        s.push(str[i]);
        i++;


    }

    i=0;

    while(!s.empty()) {

        if(str[i] != s.top()) {

            flag = 0;
            break;
        }

        s.pop();
        i++;
    }
    if(flag==1) 
        cout<<"\npalindrome";
        else
        cout<<"\nNot palindrome"; 
        
    
    


}

int main() {

    char str[100];

    cout<<"Enter String : ";
    cin.getline(str, 100);

    reverseString(str);
    checkPalindrome(str);

    return 0;
}