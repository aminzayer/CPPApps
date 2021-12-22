#include <conio.h>
#include <iostream.h>
#include <string.h>

#define MAX 64

void path(int i, int j, int p[MAX][MAX])
{
    if (p[i][j] != 0)
    {
        path(i, p[i][j], p);
        cout << "masire :" << i << " , " << j << " =:>>" << p[i][j];
        cout << endl;
        path(p[i][j], j, p);
    }
}

void floyd(int D[MAX][MAX], int n, int p[MAX][MAX])
{
    int i, j, k;

    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if ((D[i][k] + D[k][j]) < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    p[i][j] = k;
                }
    cout << "\njadvale tanzim shodeh ba algoritme floyd :\n\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (D[i][j] == 9999)
                cout << "* ";
            else

            {
                cout << D[i][j] << ' ';
                if (D[i][j] <= 9)
                    cout << ' ';
            }
        cout << endl;
    }
    cout << endl;
    cout << "____________________________________________________";
    cout << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << "____________________________________________________";
    cout << endl;

    for (int ii = 1; ii <= n; ii++)

        for (int jj = 1; jj <= n; jj++)
            path(ii, jj, p);
}
//**********

int main()
{
    clrscr();
    int i, j = 0, n;
    int W[MAX][MAX], p[MAX][MAX];
    cout << "tedade satr va sotoon ra bedahid : ";
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            W[i][j] = 0;
            if (i != j)
            {
                cout << "adade [" << i << "] [" << j << "] :=>> ";
                cin >> W[i][j];
            }
            else
                W[i][j] = 0;
        }
    cout << "Matrix Adad :\n\n";
    for (i = 1; i <= n; i++)
    {
        cout << '\t';
        for (j = 1; j <= n; j++)
            if (W[i][j] == 9999)
                cout << "* ";
            else

                cout << W[i][j] << ' ';
        cout << endl;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            p[i][j] = 0;
    floyd(W, n, p);
    getch();
}