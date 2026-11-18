
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int grid[50][50]={0};
    int r,c;
    int x,y;
    int nx,ny;
    int moves=0;
    int d;

    int dx[8]={0,1,1,-1,1,0,-1,-1};
    int dy[8]={1,0,1,1,-1,-1,0,-1};

    srand(time(0));

    cout<<"Enter number of rows: ";
    cin>>r;

    cout<<"Enter number of columns: ";
    cin>>c;

    if(r<3 || c<3 || r>50 || c>50)
    {
        cout<<"Invalid grid size";
        return 0;
    }

    // Starting position at center

    x=r/2;
    y=c/2;

    grid[x][y]=1;

    cout<<"\nStarting Position: "<<x<<" "<<y;

    // Random walk

    while(x!=0 && x!=r-1 && y!=0 && y!=c-1)
    {
        do
        {
            d=rand()%8;

            nx=x+dx[d];
            ny=y+dy[d];

        }while(nx<0 || nx>=r || ny<0 || ny>=c);

        x=nx;
        y=ny;

        grid[x][y]=1;

        moves++;

        cout<<"\nMove "<<moves<<": ";
        cout<<x<<" "<<y;
    }

    cout<<"\n\nCockroach reached the wall!";
    cout<<"\nTotal Moves: "<<moves;

    // Display final grid

    cout<<"\n\nFinal Grid:\n";

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(i==x && j==y)
                cout<<" R ";

            else if(grid[i][j]==1)
                cout<<" * ";

            else
                cout<<" . ";
        }

        cout<<endl;
    }

    return 0;
}
