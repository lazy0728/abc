
#include<iostream>
using namespace std;

class Dictionary
{
    struct Node
    {
        int key;
        char value[50];
        Node *next;
    };

    Node *table[10];

    int hashFunction(int key)
    {
        return key%10;
    }

public:

    Dictionary()
    {
        for(int i=0; i<10; i++)
            table[i]=NULL;
    }

    void insert()
    {
        int key, index;

        cout<<"Enter key: ";
        cin>>key;

        index=hashFunction(key);

        Node *temp=table[index];

        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                cout<<"Key already exists";
                return;
            }

            temp=temp->next;
        }

        Node *newNode=new Node;

        newNode->key=key;

        cout<<"Enter value: ";
        cin>>newNode->value;

        newNode->next=table[index];
        table[index]=newNode;

        cout<<"Inserted Successfully";
    }

    void find()
    {
        int key, index;

        cout<<"Enter key to find: ";
        cin>>key;

        index=hashFunction(key);

        Node *temp=table[index];

        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                cout<<"Value: "<<temp->value;
                return;
            }

            temp=temp->next;
        }

        cout<<"Key not found";
    }

    void deleteKey()
    {
        int key, index;

        cout<<"Enter key to delete: ";
        cin>>key;

        index=hashFunction(key);

        Node *temp=table[index];
        Node *prev=NULL;

        while(temp!=NULL && temp->key!=key)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)
        {
            cout<<"Key not found";
        }
        else
        {
            if(prev==NULL)
                table[index]=temp->next;
            else
                prev->next=temp->next;

            delete temp;

            cout<<"Deleted Successfully";
        }
    }
};

int main()
{
    Dictionary d;
    int choice;

    do
    {
        cout<<"\n\n1. Insert";
        cout<<"\n2. Find";
        cout<<"\n3. Delete";
        cout<<"\n4. Exit";

        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
            d.insert();

        else if(choice==2)
            d.find();

        else if(choice==3)
            d.deleteKey();

        else if(choice==4)
            cout<<"Program Ended";

        else
            cout<<"Invalid Choice";

    }while(choice!=4);

    return 0;
}
