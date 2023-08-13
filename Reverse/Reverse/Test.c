#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void reverse(char* start, char* end)
{
    if (start != NULL && end != NULL)
    {
        while (start < end)
        {
            *start ^= *end;
            *end ^= *start;
            *start ^= *end;
            start++;
            end--;
        }
    }
    else
        return;
}

void left_rotate(char* str, int len, int k)
{
    if (str != NULL && len > 0)
    {
        if (k > len)
            k %= len;
        //ÄæĞòÇ°k¸ö×Ö·û
        reverse(str + 0, str + k - 1);
        //ÄæĞòºók¸ö×Ö·û
        reverse(str + k, str + len - 1);
        //ÄæĞòÕû¸ö×Ö·û
        reverse(str, str + len - 1);
    }
    else
        return;
}

int IsRotate()
{

}

int main()
{
    char ch[] = "ABCD1234";
    int len = strlen(ch);
    int k = 0;
    scanf("%d", &k);

    left_rotate(ch, len, k);
    printf("%s\n", ch);

    return 0;
}