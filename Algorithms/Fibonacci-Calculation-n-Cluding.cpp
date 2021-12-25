#include <iostream.h>
#include <conio.h >

main()
{
    int x = 1;
    int y = 1, z = 0;
    int n;
    cout << "\n enter number:";
    cin >> n;
    cout << x;
    cout << y;
    for (int i = 2; i < n; i++)
    {
        z = x + y;
        x = y;
        y = z;
        cout << z;
    }
    getch();
}