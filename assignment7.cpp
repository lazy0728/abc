
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int priority(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        return 1;

    return 0;
}

int isOperand(char ch)
{
    if((ch>='A' && ch<='Z') ||
       (ch>='a' && ch<='z') ||
       (ch>='0' && ch<='9'))
        return 1;

    return 0;
}

// Infix to Postfix
string infixToPostfix(string exp)
{
    stack<char> s;
    string result="";

    for(int i=0; i<exp.length(); i++)
    {
        char ch=exp[i];

        if(ch==' ')
            continue;

        if(isOperand(ch))
            result=result+ch;

        else if(ch=='(')
            s.push(ch);

        else if(ch==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                result=result+s.top();
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }
        else
        {
            while(!s.empty() && isOperator(s.top()) &&
            (priority(s.top())>priority(ch) ||
            (priority(s.top())==priority(ch) && ch!='^')))
            {
                result=result+s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty())
    {
        result=result+s.top();
        s.pop();
    }

    return result;
}

// Infix to Prefix
string infixToPrefix(string exp)
{
    stack<char> s;
    string result="";

    for(int i=exp.length()-1; i>=0; i--)
    {
        char ch=exp[i];

        if(ch==' ')
            continue;

        if(isOperand(ch))
            result=result+ch;

        else if(ch==')')
            s.push(ch);

        else if(ch=='(')
        {
            while(!s.empty() && s.top()!=')')
            {
                result=result+s.top();
                s.pop();
            }

            if(!s.empty())
                s.pop();
        }
        else
        {
            while(!s.empty() && isOperator(s.top()) &&
            (priority(s.top())>priority(ch) ||
            (priority(s.top())==priority(ch) && ch=='^')))
            {
                result=result+s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while(!s.empty())
    {
        result=result+s.top();
        s.pop();
    }

    string ans="";

    for(int i=result.length()-1; i>=0; i--)
        ans=ans+result[i];

    return ans;
}

// Prefix to Postfix
string prefixToPostfix(string exp)
{
    stack<string> s;

    for(int i=exp.length()-1; i>=0; i--)
    {
        char ch=exp[i];

        if(ch==' ')
            continue;

        if(isOperand(ch))
            s.push(string(1,ch));

        else if(isOperator(ch))
        {
            if(s.size()<2)
                return "Invalid Expression";

            string a=s.top();
            s.pop();

            string b=s.top();
            s.pop();

            s.push(a+b+ch);
        }
    }

    if(s.size()!=1)
        return "Invalid Expression";

    return s.top();
}

// Prefix to Infix
string prefixToInfix(string exp)
{
    stack<string> s;

    for(int i=exp.length()-1; i>=0; i--)
    {
        char ch=exp[i];

        if(ch==' ')
            continue;

        if(isOperand(ch))
            s.push(string(1,ch));

        else if(isOperator(ch))
        {
            if(s.size()<2)
                return "Invalid Expression";

            string a=s.top();
            s.pop();

            string b=s.top();
            s.pop();

            s.push("("+a+ch+b+")");
        }
    }

    if(s.size()!=1)
        return "Invalid Expression";

    return s.top();
}

// Postfix to Infix
string postfixToInfix(string exp)
{
    stack<string> s;

    for(int i=0; i<exp.length(); i++)
    {
        char ch=exp[i];

        if(ch==' ')
            continue;

        if(isOperand(ch))
            s.push(string(1,ch));

        else if(isOperator(ch))
        {
            if(s.size()<2)
                return "Invalid Expression";

            string b=s.top();
            s.pop();

            string a=s.top();
            s.pop();

            s.push("("+a+ch+b+")");
        }
    }

    if(s.size()!=1)
        return "Invalid Expression";

    return s.top();
}

// Postfix to Prefix
string postfixToPrefix(string exp)
{
    stack<string> s;

    for(int i=0; i<exp.length(); i++)
    {
        char ch=exp[i];

        if(ch==' ')
            continue;

        if(isOperand(ch))
            s.push(string(1,ch));

        else if(isOperator(ch))
        {
            if(s.size()<2)
                return "Invalid Expression";

            string b=s.top();
            s.pop();

            string a=s.top();
            s.pop();

            s.push(ch+a+b);
        }
    }

    if(s.size()!=1)
        return "Invalid Expression";

    return s.top();
}

int main()
{
    string exp;
    int choice;

    do
    {
        cout<<"\n\n1. Infix to Prefix";
        cout<<"\n2. Prefix to Postfix";
        cout<<"\n3. Prefix to Infix";
        cout<<"\n4. Postfix to Infix";
        cout<<"\n5. Postfix to Prefix";
        cout<<"\n6. Infix to Postfix";
        cout<<"\n7. Exit";

        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice>=1 && choice<=6)
        {
            cout<<"Enter expression: ";
            cin>>exp;
        }

        if(choice==1)
            cout<<"Prefix: "<<infixToPrefix(exp);

        else if(choice==2)
            cout<<"Postfix: "<<prefixToPostfix(exp);

        else if(choice==3)
            cout<<"Infix: "<<prefixToInfix(exp);

        else if(choice==4)
            cout<<"Infix: "<<postfixToInfix(exp);

        else if(choice==5)
            cout<<"Prefix: "<<postfixToPrefix(exp);

        else if(choice==6)
            cout<<"Postfix: "<<infixToPostfix(exp);

        else if(choice==7)
            cout<<"Program Ended";

        else
            cout<<"Invalid Choice";

    }while(choice!=7);

    return 0;
}
