#include <stacks.h>
#include <iostream.h>

TStack<int> s[3];
void transfer(int n, int from, int to, int temp)
{
    if (n > 0)
    {
        // move n-1 disks from origin to temporary
        transfer(n - 1, from, temp, to);
        // move n th disk from origin to destination
        s[to].Push(s[from].Pop());
        //move n-1 disks  from  temporary to  destination
        transfer(n - 1, temp, to, from);
    }
}
void PrintStacks()
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\n<";
        while (!s[i].IsEmpty())
        {
            cout << s[i].Pop() << ',';
        }
        cout << ']';
    }
}
main()
{
    int n;
    cout << "n:";
    cin >> n;
    for (int i = n; i > 0; i--)
        s[0].Push(i);

    transfer(n, 0, 1, 2);
    PrintStacks();
}