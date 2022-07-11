#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int N = 9;
void print(int grid[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
        cout << "         ";
    }
}
bool checkH(int grid[][N], int n, int i)
{ // check in whole column
    for (int a = 0; a < N; a++)
        if (grid[i][a] == n)
            return false;
    return true;
}
bool checkV(int grid[][N], int n, int j)
{ // check in whole row
    for (int a = 0; a < N; a++)
        if (grid[a][j] == n)
            return false;
    return true;
}
bool checkB(int grid[][N], int n, int i, int j)
{
    int x = -1, y = -1; // check which block is used
                        // we can also use the block index by i/3*3 + j/3 + 1
                        // it require extra function for calling check
    if (i / 3 == 0)
        x = 2;
    else if (i / 3 == 1)
        x = 5;
    else
        x = 8;

    if (j / 3 == 0)
        y = 2;
    else if (j / 3 == 1)
        y = 5;
    else
        y = 8;

    // check in it's Block
    for (int a = x - 2; a <= x; a++)
        for (int b = y - 2; b <= y; b++)
            if (grid[a][b] == n)
                return false;
    return true;
}
bool solve(int grid[][N])
{
    bool fill = true;
    int i = -1, j = -1;
    for (int a = 0; a < N; a++)
    {
        for (int b = 0; b < N; b++)
        {
            if (grid[a][b] == 0)
            {
                i = a;
                j = b;
                fill = false;
                break;
            }
        }
        if (!fill)
            break;
    }
    if (fill) // base case
    {
        return true;
    }

    for (int n = 1; n < 10; n++)
    {

        if ((checkB(grid, n, i, j) && checkH(grid, n, i) && checkV(grid, n, j)) == true)
        {
            grid[i][j] = n; // set value

            if (solve(grid))
                return true;

            grid[i][j] = 0; // backtrack
        }
    }
    return false;
}
int main()
{
    bool f = true;
    while (f)
    {
        system("CLS");
        f = false;
        cout << "=============================================================" << endl;
        cout << "                        * SUDOKU SOLVER ^_^ * " << endl;
        cout << "=============================================================" << endl;
        cout << endl;
        cout << "   Please Enter Your Sudoku in Row wise order " << endl;
        cout << "   Press 0 for Blank Spaces " << endl;
        cout << endl;
        int grid[N][N];
        cout << "         ";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cin >> grid[i][j];
            cout << "         ";
        }
        cout << endl;
        bool s = solve(grid);
        Sleep(2000);
        cout << "     Solving ";
        for (int i = 0; i < 3; i++)
        {
            Sleep(2000);
            cout << ".  ";
            for (int j = 0; j < 100; j++)
            {
                cout << "->";
                cout << "\b";
                cout << "\b";
            }
        }
        cout << endl;
        if (s)
            print(grid);
        else
            cout << "           No Possible Solution :( " << endl;
        cout << endl;
        cout << "=============================================================" << endl;
        cout << "=============================================================" << endl;
    here:
        cout << "         Do you want to continue? Press Y/N    ";
        char c;
        cin >> c;
        cout << endl;
        if (c == 'Y' || c == 'y')
            f = true;
        else if (c == 'N' || c == 'n')
        {
            Sleep(5000);
            system("CLS");
            cout << "             THANK YOU!    ^_~      ";
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
            cout << "     Press ONLY Y or N" << endl;
            Sleep(2000);
            goto here;
        }
    }
    return 0;
}