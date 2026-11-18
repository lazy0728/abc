
#include<iostream>
using namespace std;

int main()
{
    int pizza[5];
    int front = -1;
    int rear = -1;
    int choice, order;
    int i;

    do
    {
        cout << "\n1. Place Order";
        cout << "\n2. Serve Order";
        cout << "\n3. Get Front";
        cout << "\n4. Display Order";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            if((rear + 1) % 5 == front)
            {
                cout << "Queue is Full";
            }
            else
            {
                cout << "Enter order: ";
                cin >> order;

                if(front == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else
                {
                    rear = (rear + 1) % 5;
                }

                pizza[rear] = order;
                cout << "Order Added Successfully";
            }
        }

        else if(choice == 2)
        {
            if(front == -1)
            {
                cout << "Queue is Empty";
            }
            else
            {
                cout << "Served Order: " << pizza[front];

                if(front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % 5;
                }
            }
        }

        else if(choice == 3)
        {
            if(front == -1)
            {
                cout << "Queue is Empty";
            }
            else
            {
                cout << "Front Order: " << pizza[front];
            }
        }

        else if(choice == 4)
        {
            if(front == -1)
            {
                cout << "Queue is Empty";
            }
            else
            {
                cout << "Pizza Orders: ";

                i = front;

                while(i != rear)
                {
                    cout << pizza[i] << " ";
                    i = (i + 1) % 5;
                }

                cout << pizza[rear];
            }
        }

        else if(choice == 5)
        {
            cout << "Program Ended";
        }

        else
        {
            cout << "Invalid Choice";
        }

    } while(choice != 5);

    return 0;
}
