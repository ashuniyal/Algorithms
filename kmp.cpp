#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    char c[30],m[10];
    int len1=0,len2=0;
    cout<<"\n Enter the string : ";
    gets(c);
    cout<<"\n Enter word to be match : ";
    gets(m);
    for(len1=0;c[len1]!='\0';len1++);
    for(len2=0;m[len2]!='\0';len2++);
    int k=0;
    int *lps;
    lps=new int[len2];
    lps[0]=0;
    int i=0;
    for(int j=1;j<len2;)
    {
        if(m[i]==m[j])
            {
                lps[j]=i+1;
                i=i+1;
                j=j+1;
            }
        else
        {
            if(i==0)
            {
                lps[j]=0;
                j=j+1;
            }
            else
            {
                while(i!=0)
                {
                    i=lps[i-1];
                    if(m[i]==m[j])
                    {
                        lps[j]=i+1;
                        i=i+1;
                        j=j+1;
                        break;
                    }
                }
            }
        }
    }
    cout<<"LPS :- ";
    for(i=0;i<len2;i++)
        cout<<lps[i]<<" ";
    cout<<"\n";
    int j=0;
    for(i=0;i<len1;i++)
    {
        if(c[i]==m[j] && j==(len2-1))
        {
            cout<<"\nPattern found at : "<<i-len2+1;
            j=0;
            k=1;
        }
        else if(c[i]==m[j] && j!=len2)
        {
            j=j+1;
        }
        else
        {
            while(j!=0)
            {
                j=lps[j-1];
                if(c[i]==m[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    if(k==0)
        cout<<"\n Match not found. \n";
    cout<<"\n";
    return 0;
}
