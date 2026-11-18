#include<iostream>
using namespace std;

struct Node {

    int startTime;
    int endTime;
    char patientName[50];

    Node *prev;
    Node *next;

};
class Appointment {

    Node *head;
    Node *tail;

    public:

    Appointment() {

        head = NULL;
        tail = NULL;
    }

    void bookAppointment() {

        Node *newNode = new Node;

        cout<<"Enter patient name:";
        cin>>newNode->patientName;

        cout<<"Enter start time:";
        cin>>newNode->startTime;

        cout<<"Enter End time:";
        cin>>newNode->endTime;

        newNode->prev =NULL;
        newNode->next =NULL;

        if(head==NULL) {

            head = newNode;
            tail = newNode;
        }
        else {

            tail->next =newNode;
            newNode->prev=tail;
            tail = newNode;
        }
        cout<<"\nAppointment booked succesfully";


    }

    void displayAppointment() {
        Node *temp =head;

        if(head==NULL) {

            cout<<"\nNo appointment booked";
        }
        else {

            while(temp != NULL) {

                cout<<"\nPatient Name :"<<temp->patientName;
                cout<<"\nStart Timr :"<<temp->startTime;
                cout<<"\nEnd Time :"<<temp->endTime;

                temp = temp->next;
            }
        }


    }

    void displayFreeSlots() {

        int time = 900;

        while(time<1700)
        {

            Node *temp = head;
            int booked =0;

            while(temp != NULL) {
                
                if(temp->startTime<=time && temp->endTime>time){

                    booked = 1;
                    break;
                }
                temp= temp->next;


            }
            if(booked == 0) {

                cout << time <<" "<<time + 100 << endl;
            }

            time = time + 100;
        }  
    }

    void cancelAppointment()
{
    int time;

    cout << "\nEnter appointment start time to cancel: ";
    cin >> time;

    Node *temp = head;

    while(temp != NULL && temp->startTime != time)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "\nAppointment not found!";
    }
    else
    {
        if(temp == head && temp == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else if(temp == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else if(temp == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;

        cout << "\nAppointment cancelled successfully!";
    }
}
};

int main(){

    Appointment a;
    a.bookAppointment();
    a.displayAppointment();
    a.displayFreeSlots();
    a.cancelAppointment();

    return 0;
}
