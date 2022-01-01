#include <iostream.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void main(void)
{
    const array_size = 10;
    int arr[array_size];
    int flag, search;

    randomize();
    for (int i = 0; i < array_size; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "\t";
    }

    cout << "Enter number to search: ";
    cin >> search;
    flag = -1;
    for (int i = 0; i < array_size; i++)
        if (arr[i] == search)
            flag = i;

    if (flag >= 0)
        cout << flag << ") " << arr[flag] << " Founded. ";
    else
        cout << " Not Find.";

    getch();
}