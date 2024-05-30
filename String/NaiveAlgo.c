#include<stdio.h>
#include<string.h>

void naive(char*text, char*pattern)
{
    int i,j;
    int m=strlen(text);
    int n=strlen(pattern);

    for(i=0;i<m-n;i++)
    {
        for(j=0;j<n;j++)
        if(text[i+j]!=pattern[j])
        break;

        if(j==n)
        printf("Pattern found at index : %d \n",i);
    }
}

int main()
{
    char text[]="ABABDABACDABABCABAB";
    char pattern[]= "ABAB";

    naive(text,pattern);

    return 0;

}