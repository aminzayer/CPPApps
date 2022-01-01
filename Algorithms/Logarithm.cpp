#include <stdio.h>
#include <conio.h>
#include <iostream.h>

float loge(float x)
{
    float y = (x - 1) / (1 + x);
    float ln1 = 0, ln2 = 2 * y;
    float k = 1;
    float p = y;
    while (k < 10000)
    {
        ln1 = ln2;
        k += 2;
        p = p * y * y;
        ln2 += 2 / k * p;
    }
    return ln2;
}
float log(int x, int k)
{
    return loge(x) / loge(k);
}
void main()
{
    clrscr();
    int n, k;
    cout << "Logarithm of: ";
    cin >> n;
    cout << "Base of: ";
    cin >> k;
    cout << "\n"
         << log(n, k);
    getch();
}