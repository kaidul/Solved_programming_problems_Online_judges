#include<stdio.h>

int is_prime(int i);
int rev(int n);
int main()
{
    long int n,a;
    while(scanf("%ld",&n)!=EOF)
    {
        a=is_prime(n);
    if(a!=1)
        printf("%ld is not prime.\n",n);
    else
    {
        int n1=rev(n);
        int n2=is_prime(n1);
        if(n2==1&&n1!=n2)
          printf("%ld is emirp.\n",n);
        else
            printf("%ld is prime.\n",n);

    }
    }
    return 0;
}
int is_prime(int l)
{
    long int i;
        for ( i = 2; i<l; i++)
    {
    if (l % i == 0)
    return 0;
    }
        return 1;
}
int rev(int n)
{  long int r;
    do
        r = r * 10 + n % 10;
    while ((n=n/10) > 0);
    return r;
}
