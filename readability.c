#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int count_letters(string t, int l)
{
    int i, c = 0;
    for (i = 0; i < l; ++i)
    {
        if (isalpha(t[i]))
        {
            c++;
        }
    }
    return c;
}
int count_words(string t, int l)
{
    int i, c = 1;
    for (i = 0; i < l; ++i)
    {
        if (t[i] == ' ')
        {
            c++;
        }
    }
    return c;
}
int count_sentences(string t, int l)
{
    int i, c = 0;
    for (i = 0; i < l; ++i)
    {
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            c++;
        }
    }
    return c;
}
int main(void)
{
    int cl, wl, sl, index;
    float L, S, in;
    string text = get_string("Text:");
    int l = strlen(text);
    cl = count_letters(text, l);
    wl = count_words(text, l);
    sl = count_sentences(text, l);
    L = ((float)cl / (float)wl) * 100;
    S = ((float)sl / (float)wl) * 100;
    in = 0.0588 * L - 0.296 * S - 15.8;
    if (in < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (in > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        index = round(in);
        printf("Grade %d\n", index);
    }
}