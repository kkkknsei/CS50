#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
if (argc == 2)
{
    bool go = true;
    char upper[26];
    char lower[26];
    int a;
    int k;
    int g;
    int m = 0;
    char checku[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char checkl[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    
    for (k = 0; argv[1][k] != '\0'; k++)
    {
        if (((argv[1][k] >= 65) && (argv[1][k] <= 90)) || ((argv[1][k] >= 97) && (argv[1][k] <= 122)))
        {
            go = true;
        }
        else
        {
            go = false;
            break;
        }
    }
    
    if ((go = true) && (argc == 2)) {go = true;}
    else if ((go = true) && (k == 26)) {go = true;}
    
    
    for (int b = 0; argv[1][b] != '\0'; b++)
    {
        if (((int)argv[1][b] >= 65) && ((int)argv[1][b] <= 90))
        {
            lower[b] = (((int)argv[1][b]) + 32);
            upper[b] = ((int)argv[1][b]);
        }
        else if (((int)argv[1][b] >= 97) && ((int)argv[1][b] <= 122))
        {
            lower[b] = ((int)argv[1][b]);
            upper[b] = (((int)argv[1][b]) - 32);
            }
    }
    
    for (int q = 0; argv[1][q] != '\0'; q++)
    {
        for (int z = q + 1; argv[1][z] != '\0'; z++)
        {
            if (argv[1][z] == argv[1][q])
            {
                m++;
            }
        }
    }
    if (m > 0)
    {
        go = false;
        return 1;
    }
    else if ((go = true) && (k != 26))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if ((go = false))
    {
        printf("You're doing shomething you shouldn't... just sayin.\n");
        return 1;
    }
    else if ((go = true))
    {
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
        for (int i = 0; s[i] != '\0'; i++)
        {
            if ((s[i] >= 97) && (s[i] <= 122))
            {
                a = -1;
                do (a++);
                while (checkl[a] != s[i]);
                
                if ((checkl[a] = s[i]))
                {
                    s[i] = lower[a];
                }
            }
            else if ((s[i] >= 65) && (s[i] <= 90))
            {
                g = -1;
                do (g++);
                while (checku[g] != s[i]);
                
                if ((checku[g] = s[i]))
                {
                    s[i] = upper[g];
                }
            }
        }
        
        printf("%s", s);
        printf("\n");
    return 0;
    }
}
else
{
    printf("You're doing something you shouldn't... just saying.\n");
    return 1;
}
}