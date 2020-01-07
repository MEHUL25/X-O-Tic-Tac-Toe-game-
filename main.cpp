#include <iostream>

using namespace std;
class game
{
    int a[3][3],t,x,y;
    public:
    game()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                a[i][j]=0;
            }
        }
    }
    void start()
    {
        int c=1,f=0,n;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                print();
                if(c%2!=0)
                {
                    cout<<"\nPlayer one turn( Enter index number ) : ";
                    cin>>n;
                    n--;
                    x=n/3;
                    y=(n%3);
                    if(a[x][y]==0)
                        a[x][y]=1;
                    else
                    {
                        cout<<"\nInvalid Move\n";
                        goto last;
                    }
                    if(check(1))
                    {
                        print();
                        cout<<"\n\nCongrats!Player one wins .\n";f=1;
                        goto last;
                    }
                }
                else
                {
                    cout<<"\nPlayer two turn( Enter index number ) : ";
                    cin>>n;n--;
                    x=n/3;
                    y=(n%3);
                    if(a[x][y]==0)
                        a[x][y]=2;
                    else
                    {
                        cout<<"\nInvalid Move\n";
                        goto last;
                    }
                    if(check(2))
                    {
                        print();
                        cout<<"\n\nCongrats!Player two wins .\n";f=1;
                        goto last;
                    }
                }

                c++;
            }
        }
        last:
        if(f==0)
        {
            cout<<"\n\n\t\t------------Game Draw---------------\n\n";
        }
        else
        {
            cout<<"\n\n\t\t------------Game Over---------------\n\n";
        }
    }
    void print()
    {
        cout<<"\nBoard:\n\n";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(a[i][j]==0)
                {
                    cout<<"\t_\t";
                }
                else if(a[i][j]==1)
                {
                    cout<<"\tX\t";
                }
                else if(a[i][j]==2)
                {
                    cout<<"\tO\t";
                }
            }
            cout<<"\n";
        }
    }
    bool check(int n)
    {
        int f=0;
        if(a[0][0]==n&&a[1][1]==n&&a[2][2]==n)
        {
            f=1;
        }
        else if(a[0][1]==n&&a[0][0]==n&&a[0][2]==n)
        {
            f=1;
        }
        else if(a[1][0]==n&&a[1][1]==n&&a[1][2]==n)
        {
            f=1;
        }
        else if(a[2][0]==n&&a[2][1]==n&&a[2][2]==n)
        {
            f=1;
        }
        else if(a[0][2]==n&&a[1][1]==n&&a[2][0]==n)
        {
            f=1;
        }
        else if(a[0][0]==n&&a[1][0]==n&&a[2][0]==n)
        {
            f=1;
        }
        else if(a[0][1]==n&&a[1][1]==n&&a[2][1]==n)
        {
            f=1;
        }
        else if(a[0][2]==n&&a[1][2]==n&&a[2][2]==n)
        {
            f=1;
        }
        if(f==0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};


int main()
{
    game g;
    cout<<"\nWelcome to X-O game : \n";
    g.start();
    return 0;
}
