#include <stdio.h>
#include <cs50.h>
//Get the value of size
int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    //This one is the function I was talking about: if you give (!(... && ...)) you can limit the numbers of accepted inputs
    while (!((n > 0) && (n < 9)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //From start, the code will add 1 to both i and j, so that means i+j=2 and the code will add blank spaces until there's no need to
            if (i + j < n - 1)
            printf(" ");
            else
            printf("#");
        }
        
        printf ("  ");
        
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        for (int j = 0; j < i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}