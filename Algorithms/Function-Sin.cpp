#include <iostream.h>
#include <conio.h>

int pow(int a, int b);
int fact(int a);
double sin(int (*p)(int a, int b), int (*q)(int b), int x);
void main()
{
    int x;
    clrscr();
    cout << "Please Enter Number : ";
    cin >> x;
    cout << fact(x) << endl
         << pow(x, x);
    //cout<<sin(pow,fact,x);
    getch();
}
int pow(int a, int b)
{
    int pow = 1;
    for (int i = 1; i <= b; i++)
        pow *= a;
    return pow;
}
int fact(int a)
{
    int fact = 1;
    for (int i = 1; i <= a; i++)
        fact *= i;
    return fact;
}
double sin(int (*p)(int a, int b), int (*q)(int b), int x)
{
    double sum = 0;
    int b = 1;
    for (int i = 1; i <= 15; i += 2)
    {
        sum += (pow)(x, i) / (fact)(i)*b;
        b = -b;
    }
    return sum;
}