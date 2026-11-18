
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

void selectionSort(float a[], int n)
{
    int min;
    float temp;

    for(int i=0; i<n-1; i++)
    {
        min=i;

        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
                min=j;
        }

        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

void bubbleSort(float a[], int n)
{
    float temp;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertionSort(float a[], int n)
{
    float key;
    int j;

    for(int i=1; i<n; i++)
    {
        key=a[i];
        j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=key;
    }
}

void shellSort(float a[], int n)
{
    float temp;

    for(int gap=n/2; gap>0; gap=gap/2)
    {
        for(int i=gap; i<n; i++)
        {
            temp=a[i];
            int j;

            for(j=i; j>=gap && a[j-gap]>temp; j=j-gap)
            {
                a[j]=a[j-gap];
            }

            a[j]=temp;
        }
    }
}

void display(float a[], int n)
{
    cout<<"\nSorted Marks: ";

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}

int main()
{
    float marks[100];
    int n, choice, input;

    cout<<"Enter number of students: ";
    cin>>n;

    cout<<"\n1. Enter marks manually";
    cout<<"\n2. Generate random marks";
    cout<<"\nEnter choice: ";
    cin>>input;

    if(input==1)
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Enter marks: ";
            cin>>marks[i];
        }
    }
    else
    {
        srand(time(0));

        for(int i=0; i<n; i++)
        {
            marks[i]=rand()%101;
        }
    }

    do
    {
        cout<<"\n\n1. Selection Sort";
        cout<<"\n2. Bubble Sort";
        cout<<"\n3. Insertion Sort";
        cout<<"\n4. Shell Sort";
        cout<<"\n5. STL Sort";
        cout<<"\n6. Display Top Five";
        cout<<"\n7. Exit";

        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
        {
            selectionSort(marks,n);
            display(marks,n);
        }
        else if(choice==2)
        {
            bubbleSort(marks,n);
            display(marks,n);
        }
        else if(choice==3)
        {
            insertionSort(marks,n);
            display(marks,n);
        }
        else if(choice==4)
        {
            shellSort(marks,n);
            display(marks,n);
        }
        else if(choice==5)
        {
            sort(marks,marks+n);
            display(marks,n);
        }
        else if(choice==6)
        {
            sort(marks,marks+n);

            cout<<"\nTop Five Marks: ";

            for(int i=n-1, count=0; i>=0 && count<5; i--,count++)
            {
                cout<<marks[i]<<" ";
            }
        }
        else if(choice==7)
        {
            cout<<"Program Ended";
        }
        else
        {
            cout<<"Invalid Choice";
        }

    }while(choice!=7);

    return 0;
}
