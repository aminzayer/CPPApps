#include <iostream.h>
#include <conio.h>
#include <stdio.h>

int lenstr(char str[]);
int findstr(char str[], char sub[]);
void main(void)
{
   char str[100], sub[100];
   cout << "Enter string: ";
   gets(str);
   cout << "What to search? ";
   gets(sub);

   cout << "position: " << findstr(str, sub);

   getch();
}

int lenstr(char str[])
{
   int i = 0;
   while (str[i])
      i++;

   return (i);
}

int findstr(char str[], char sub[])
{
   int i, j, pos = -1;
   for (i = 0; i <= lenstr(str) - lenstr(sub); i++)
   {
      j = i;
      while (str[j] == sub[j - i] && sub[j - i])
         j++;

      if (j - i == lenstr(sub))
      {
         pos = i;
         break;
      }
   }
   return (pos);
}