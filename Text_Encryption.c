#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void encrypt(string pt, string k)//function to encrypt the text
{
    int plen, i, n;
    string ct = pt;
    plen = strlen(pt);
    for (i = 0; i < plen; ++i)
    {
        if (isalpha(pt[i]))//checks if the character is an alphabet
        {
            if (isupper(pt[i]))
            {
                n = (int)pt[i] - 65; 
                ct[i] = toupper(k[n]);
            }
            else
            {
                n = (int)pt[i] - 97; 
                ct[i] = tolower(k[n]);
            }
        }
        else 
        {
            ct[i] = pt[i];
        }
    }
    printf("ciphertext: %s\n", ct);//displays encrypted text
}
int main(int argc, string key[])//inputs key
{
    int i, j, l, f;
    string pt;
    if (argc != 2)//checks if only 1 key is entered
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    l = strlen(key[1]);
    if (l != 26)//checks if there are 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (i = 0; i < 26; ++i)
    {
        if (!isalpha(key[1][i]))//checks if key contains only alphabets
        {
            printf("Key must contain only alphabets.\n");
            return 1;
        }
    }
    for (i = 0; i < 26; ++i)
    {
        f = 0;
        for (j = i + 1; j < 26; ++j)
        {
            if (tolower(key[1][i]) == tolower(key [1][j]))//checks for repeated characters
            {
                f++;
            }
        }
        if (f > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    pt = get_string("plaintext: ");//inputs text
    encrypt(pt, key[1]);
    return 0;
}
