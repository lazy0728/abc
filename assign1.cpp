
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string coding[50];
    string project[50];
    string paper[50];
    string mastermind[50];

    int n1, n2, n3, n4;
    int choice;

    cout << "Enter number of Coding participants: ";
    cin >> n1;

    cout << "Enter number of Project participants: ";
    cin >> n2;

    cout << "Enter number of Paper participants: ";
    cin >> n3;

    cout << "Enter number of Mastermind participants: ";
    cin >> n4;

    cout << "\nEnter Coding participants:\n";
    for(int i = 0; i < n1; i++)
    {
        cin >> coding[i];
    }

    cout << "\nEnter Project participants:\n";
    for(int i = 0; i < n2; i++)
    {
        cin >> project[i];
    }

    cout << "\nEnter Paper participants:\n";
    for(int i = 0; i < n3; i++)
    {
        cin >> paper[i];
    }

    cout << "\nEnter Mastermind participants:\n";
    for(int i = 0; i < n4; i++)
    {
        cin >> mastermind[i];
    }

    do
    {
        cout << "\n\n===== SET OPERATIONS =====";
        cout << "\n1. Coding AND Project";
        cout << "\n2. Coding OR Project OR Mastermind";
        cout << "\n3. Coding BUT NOT Mastermind";
        cout << "\n4. Students in All Four Events";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "\nCommon Students are:\n";

                for(int i = 0; i < n1; i++)
                {
                    for(int j = 0; j < n2; j++)
                    {
                        if(coding[i] == project[j])
                        {
                            cout << coding[i] << " ";
                        }
                    }
                }
                break;
            }

            case 2:
            {
                cout << "\nUnion of Students:\n";

                for(int i = 0; i < n1; i++)
                {
                    cout << coding[i] << " ";
                }

                for(int i = 0; i < n2; i++)
                {
                    int flag = 0;

                    for(int j = 0; j < n1; j++)
                    {
                        if(project[i] == coding[j])
                        {
                            flag = 1;
                        }
                    }

                    if(flag == 0)
                    {
                        cout << project[i] << " ";
                    }
                }

                for(int i = 0; i < n4; i++)
                {
                    int flag = 0;

                    for(int j = 0; j < n1; j++)
                    {
                        if(mastermind[i] == coding[j])
                        {
                            flag = 1;
                        }
                    }

                    for(int j = 0; j < n2; j++)
                    {
                        if(mastermind[i] == project[j])
                        {
                            flag = 1;
                        }
                    }

                    if(flag == 0)
                    {
                        cout << mastermind[i] << " ";
                    }
                }
                break;
            }

            case 3:
            {
                cout << "\nCoding but not Mastermind:\n";

                for(int i = 0; i < n1; i++)
                {
                    int flag = 0;

                    for(int j = 0; j < n4; j++)
                    {
                        if(coding[i] == mastermind[j])
                        {
                            flag = 1;
                        }
                    }

                    if(flag == 0)
                    {
                        cout << coding[i] << " ";
                    }
                }
                break;
            }

            case 4:
            {
                cout << "\nStudents in All Four Events:\n";

                for(int i = 0; i < n1; i++)
                {
                    int a = 0, b = 0, c = 0;

                    for(int j = 0; j < n2; j++)
                    {
                        if(coding[i] == project[j])
                        {
                            a = 1;
                        }
                    }

                    for(int j = 0; j < n3; j++)
                    {
                        if(coding[i] == paper[j])
                        {
                            b = 1;
                        }
                    }

                    for(int j = 0; j < n4; j++)
                    {
                        if(coding[i] == mastermind[j])
                        {
                            c = 1;
                        }
                    }

                    if(a == 1 && b == 1 && c == 1)
                    {
                        cout << coding[i] << " ";
                    }
                }
                break;
            }

            case 5:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
