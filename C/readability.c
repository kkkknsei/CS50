#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string s = get_string("Input: ");
    int a = strlen(s);
    int b;
    int c = 0;
    int d;
    int e = 0;
    int g;
    double h = 0;

    for (int i = 0; i < a; i++)
    {
        if ((s[i] == '.') || (s[i] == ',') || (s[i] == ';') || (s[i] == '!') || (s[i] == '?') || ((char)s[i] == 39))
        {
        c++;
        }
    }

    for (d = 0; d < a; d++)
    {
        if (s[d] == ' ')
        {
            e++;
        }
    }

    for (g = 0; g < a; g++)
    {
        if ((s[g] == '.') || (s[g] == '!') || (s[g] == '?'))
        {
            h++;
        }
    }

    int w = (e+1);
    float f = a - (e + c);
    
    f /= w;
    f = f*100;
    h /= w;
    h = h*100;
    float index = (0.0588 * f - 0.296 * h - 15.8);
    index = round(index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index <= 15)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}