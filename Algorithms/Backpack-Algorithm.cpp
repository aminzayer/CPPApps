#include <conio.h>
#include <stdio.h>
#include <iostream.h>

void sortbypw(int p[], int w[], int n)
{
    int i, t, j;
    for (i = 0; i <= n - 1; i++)
        for (j = i + 1; j <= n; j++)
            if (((float)p[i] / w[i]) < ((float)p[j] / w[j]))
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
                t = w[i];
                w[i] = w[j];
                w[j] = t;
            }
}

////////////////////////////////////////////////////////////////////////

class = "lang:c++ decode:true" float knapsack(int p[], int w[], int n, int m)
{
    sortbypw(p, w, n);
    int w1 = m;
    int i = 0;
    float pp = 0;
    while (i <= n && w1 > 0)
    {
        if (w[i] < w1)
        {
            cout << " p : " << p[i];
            w1 -= w[i];
            pp += p[i];
            i++;
        }
        else
        {
            cout << " p : " << p[i];
            pp += w1 * ((float)p[i] / w[i]);
            w1 = 0;
        }
    }
    return pp;
}

void main()
{
    int p[100] = {6, 12, 7, 18, 9, 30};
    int w[100] = {1, 5, 3, 9, 5, 20};
    clrscr();
    cout << "If You Want Input Data Press (Y) Else Press (N) :";
    char ch = getche();
    if (ch == 'n')
        cout << "\n\n Arzesh Knapsack : " << knapsack(p, w, 5, 20);
    else
    {
        int n, m;
        cout << "\nEnter Weight Knapsack : ";
        cin >> m;
        cout << "Enter Num : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Arzesh : ";
            cin >> p[i];
            cout << "\nEnter Weight : ";
            cin >> w[i];
            gotoxy(20, wherey() - 2);
            cout << " P/W Is : " << (float)p[i] / w[i];
            gotoxy(1, wherey() + 2);
            cout << ".......................................\n";
        }
        cout << "\n\n Arzesh Knapsack : " << knapsack(p, w, n - 1, m);
    }
    getch();
}