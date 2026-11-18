
#include<iostream>
using namespace std;

struct Element
{
    int row, col, value;
};

class sparseMatrix
{
public:
    Element sp[101];

    void read()
    {
        int r, c, n;

        cout << "Enter rows: ";
        cin >> r;
        cout << "Enter columns: ";
        cin >> c;
        cout << "Enter non-zero elements: ";
        cin >> n;

        sp[0].row = r;
        sp[0].col = c;
        sp[0].value = n;

        for(int i=1; i<=n; i++)
        {
            cout << "Enter row, column, value: ";
            cin >> sp[i].row >> sp[i].col >> sp[i].value;
        }
    }

    void display()
    {
        cout << "\nRow Column Value\n";

        for(int i=0; i<=sp[0].value; i++)
        {
            cout << sp[i].row << "    ";
            cout << sp[i].col << "    ";
            cout << sp[i].value << endl;
        }
    }

    void add(sparseMatrix a, sparseMatrix b)
    {
        int mat[50][50] = {0};
        int k = 1;

        if(a.sp[0].row != b.sp[0].row ||
           a.sp[0].col != b.sp[0].col)
        {
            cout << "Addition not possible";
            sp[0].value = 0;
            return;
        }

        for(int i=1; i<=a.sp[0].value; i++)
        {
            mat[a.sp[i].row][a.sp[i].col] = a.sp[i].value;
        }

        for(int i=1; i<=b.sp[0].value; i++)
        {
            mat[b.sp[i].row][b.sp[i].col] =
            mat[b.sp[i].row][b.sp[i].col] + b.sp[i].value;
        }

        sp[0].row = a.sp[0].row;
        sp[0].col = a.sp[0].col;

        for(int i=0; i<sp[0].row; i++)
        {
            for(int j=0; j<sp[0].col; j++)
            {
                if(mat[i][j] != 0)
                {
                    sp[k].row = i;
                    sp[k].col = j;
                    sp[k].value = mat[i][j];
                    k++;
                }
            }
        }

        sp[0].value = k-1;
        cout << "Addition Complete!";
    }

    void simpleTranspose(sparseMatrix a)
    {
        int k = 1;

        sp[0].row = a.sp[0].col;
        sp[0].col = a.sp[0].row;
        sp[0].value = a.sp[0].value;

        for(int j=0; j<a.sp[0].col; j++)
        {
            for(int i=1; i<=a.sp[0].value; i++)
            {
                if(a.sp[i].col == j)
                {
                    sp[k].row = a.sp[i].col;
                    sp[k].col = a.sp[i].row;
                    sp[k].value = a.sp[i].value;
                    k++;
                }
            }
        }

        cout << "\nSimple Transpose Complete!";
    }
};

int main()
{
    sparseMatrix a, b, c;
    int choice;

    do
    {
        cout << "\n\n1. Read";
        cout << "\n2. Display";
        cout << "\n3. Addition";
        cout << "\n4. Simple Transpose";
        cout << "\n5. Fast Transpose";
        cout << "\n6. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "\nFirst Matrix:\n";
            a.read();

            cout << "\nSecond Matrix:\n";
            b.read();
        }
        else if(choice == 2)
        {
            cout << "\nFirst Matrix:\n";
            a.display();

            cout << "\nSecond Matrix:\n";
            b.display();
        }
        else if(choice == 3)
        {
            c.add(a, b);
            cout << "\nAddition Result:\n";
            c.display();
        }
        else if(choice == 4)
        {
            c.simpleTranspose(a);
            c.display();
        }
        else if(choice == 5)
        {
            cout << "Fast Transpose not implemented";
        }
        else if(choice == 6)
        {
            cout << "Program Ended";
        }
        else
        {
            cout << "Invalid Choice";
        }

    } while(choice != 6);

    return 0;
}
