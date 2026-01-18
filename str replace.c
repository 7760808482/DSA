#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void stringmatch();
char str[100],pat[10],rep[10],res[10];
int a=0,b=0,c=0,d=0,e=0,flag=0;
int main()
{
    printf("Enter the string:");
    scanf("%s",str);
    printf("Enter the pattern:");
    scanf("%s",pat);
    printf("Enter the replace string:");
    scanf("%s",rep);
    printf("Original string:%s",str);
    stringmatch();
    if(flag==1)
        printf("New string:%s",res);
    else
        printf("element not found");
}
void stringmatch()
{
    while(str[a]!='\0')
    {
        b=a;
        c=0;
        while(str[b]==pat[c]&& pat[c]!='\0')
        {
            b++;
            c++;
        }
        if(pat[c]=='\0')
        {
            flag=1;
            for(d=0;rep[d]!='\0';d++)
            {
                res[e]=rep[d];
                e++;
            }
            a=b;
        }
        else
        {
            res[e]=str[a];
            e++;
            a++;
        }
    }
    res[e]='\0';
}