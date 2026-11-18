
#include<iostream>
using namespace std;

class Polynomial
{
public:

    struct Term
    {
        int coeff;
        int expo;
    };

    Term p[50];
    int n;

    void read()
    {
        cout << "Enter number of terms: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter coefficient: ";
            cin >> p[i].coeff;

            cout << "Enter exponent: ";
            cin >> p[i].expo;
        }
    }

    void display()
    {
        cout << "Polynomial: ";

        for(int i = 0; i < n; i++)
        {
            cout << p[i].coeff << "x^" << p[i].expo;

            if(i != n - 1)
            {
                cout << " + ";
            }
        }

        cout << endl;
    }
};

void add(Polynomial P1, Polynomial P2)
{
    Polynomial P3;

    int i = 0, j = 0, k = 0;

    while(i < P1.n && j < P2.n)
    {
        if(P1.p[i].expo > P2.p[j].expo)
        {
            P3.p[k] = P1.p[i];
            i++;
            k++;
        }

        else if(P1.p[i].expo < P2.p[j].expo)
        {
            P3.p[k] = P2.p[j];
            j++;
            k++;
        }

        else
        {
            P3.p[k].coeff = P1.p[i].coeff + P2.p[j].coeff;
            P3.p[k].expo = P1.p[i].expo;

            i++;
            j++;
            k++;
        }
    }

    while(i < P1.n)
    {
        P3.p[k] = P1.p[i];
        i++;
        k++;
    }

    while(j < P2.n)
    {
        P3.p[k] = P2.p[j];
        j++;
        k++;
    }

    P3.n = k;

    cout << "\nAddition Result:\n";
    P3.display();
}

int main()
{
    Polynomial P1, P2;

    P1.n = 0;
    P2.n = 0;

    int choice;

    do
    {
        cout << "\n1. Read Polynomial";
        cout << "\n2. Display Polynomial";
        cout << "\n3. Add Polynomials";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter First Polynomial:\n";
                P1.read();

                cout << "\nEnter Second Polynomial:\n";
                P2.read();
                break;

            case 2:
                if(P1.n == 0 || P2.n == 0)
                {
                    cout << "\nPlease read both polynomials first.";
                }
                else
                {
                    cout << "\nFirst Polynomial:\n";
                    P1.display();

                    cout << "Second Polynomial:\n";
                    P2.display();
                }
                break;

            case 3:
                if(P1.n == 0 || P2.n == 0)
                {
                    cout << "\nPlease read both polynomials first.";
                }
                else
                {
                    add(P1, P2);
                }
                break;

            case 4:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 4);

    return 0;
}
