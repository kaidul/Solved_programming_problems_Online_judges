#include <stdio.h>
unsigned long long int addFirst(int i, char* expression) {

    unsigned long long int res = 0;
    for(; expression[i] && expression[i] != '*'; i++)
        if(expression[i] != '+')
            res  = res + expression[i];
    if(!expression[i])
        return res;
    else
        return res * addFirst(i + 1, expression);
}
unsigned long long int multiplyFirst(int i, char* expression) {
    unsigned long long int res = expression[i++];
    for(; expression[i] && expression[i] != '+'; i++)
        if(expression[i] != '*')
            res  = res * expression[i];
    if(!expression[i])
        return res;
    else
        return res + multiplyFirst(i + 1, expression);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int i, res, top, c;
    char inp[50];
    char expression[50];
    gets(inp);
    sscanf(inp, "%d", &c);
    while(c--) {
        gets(inp);
        top = 0;
        for(i=0; inp[i];)
            if(inp[i] == '*' || inp[i] == '+')
                expression[top++] = inp[i++];
            else {
                res = inp[i++] - '0';
                if(inp[i] && inp[i] != '*' && inp[i] != '+')
                    res = res * 10 + inp[i++] - '0';
                expression[top++] = res;
            }
        expression[top] = 0;
        printf("The maximum and minimum are %llu and %llu.\n",addFirst(0, expression),multiplyFirst(0, expression));
    }
    return 0;
}
