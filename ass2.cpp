#include<iostream>
using namespace std;

class String
{
public:
char str[100];
void frequency(){

    char ch;
    int count = 0;

    cout<<"Enter character";
    cin>>ch;

    for(int i=0; str[i] != '\0'; i++){
        if(str[i]==ch){

            count++;
        }
    }
    cout<<"frequency:"<<count << endl;
}
void extract(){

    int start, len;
    cout<<"Enter starting position";
    cin>>start;
    cout<<"Enter lenght";
    cin>>len;

    for(int i=start; i<start+len;i++){

        cout<<str[i];
        cout<<endl;
    }
}
void removeChar(){

    char ch;
    int j=0;

    cout<<"Enter character to remove";
    cin>>ch;

    for(int i=0; str[i] != '\0'; i++) {

        if(str[i] != ch){

            str[j]=str[i];
            j++;
        }
    }
    str[j]='\0';
    cout<<"new string:"<<str;
}
void replaceString() {

    char w[50], x[50], temp[100];
    int pos =-1, len =0, k=0;

    cout<<"Enter old word";
    cin>>w;
    cout<<"Enter new word";
    cin>>x;

    for(int i=0; w[i] != '\0'; i++)
    len++;
    
    for(int i=0; str[i] != '\0'; i++){

        int j=0;
        while(j<len && str[i+j]!='\0' && str[i+j]==w[j])
        j++;

        if(j==len) {
            pos =i;
            break;
        }
    }
    if(pos==-1)
    cout<<"Word not fount!";

    else {

        for(int i=0; i<pos; i++)
        temp[k++]=str[i];

        for(int i=0; x[i] != '\0'; i++) 
        temp[k++]=x[i];

        for(int i=pos+len; str[i] != '\0'; i++)
        temp[k++]=str[i];

        temp[k]='\0';

        for(int i=0; temp[i] != '\0'; i++)
        str[i]=temp[i];

        str[k]='\0';

        cout<<"New string:"<<str;


    }
}
void palindrome()
{

    int len =0;
    int flag =1;

    for(int i=0; str[i] != '\0'; i++)
    {
        len++;
    }
    for(int i=0; i<len/2;i++)
    {
        if(str[i] != str[len-1-i]){
            flag =0;
            break;
        }
    }
    if(flag==1)
        cout<<"palindrome";
        else 
        cout<<"Not palindrome";

    
}
};


int main(){

    String s;
    int choice;

    cout<<"Enter string:";
    cin>>s.str;
    cout<<endl;
    do {

        cout<<"\n1. frequency";
        cout<<"\n2. extract";
        cout<<"\n3. remove character";
        cout<<"\n4. replace substring";
        cout<<"\n5. palindrome";
        cout<<"\n6. exit";

        cout<<"Enter choice";
        cin>>choice;

        switch(choice)
        {
            case 1:
            s.frequency();
            break;

            case 2:
                s.extract();
                break;

            case 3:
                s.removeChar();
                break;

            case 4:
                s.replaceString();
                break;

            case 5:
                s.palindrome();
                break;

            case 6:
                cout << "Program Ended";
                cout<<endl;
                break;

            default:
                cout << "Invalid Choice";
        }
            
        }while(choice!=6);

        return 0;
    }

    


