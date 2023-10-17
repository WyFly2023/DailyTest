#include <stdio.h>

void printBinary(int num)
{
    for (int i = 8 - 1; i >= 0; i--)
        printf("%d", (num >> i) & 1);   // 右移i位后和1进行按位与运算，以获取第i位的值
    printf("\n");
}

#define SWAP_BINARY_BIT(n) (n = ((n & 0x55555555) << 1) + ((n & 0xaaaaaaaa) >> 1))
int main()
{
    int n = 0;
    printf("Enter a number:");
    scanf("%d", &n);
    printf("二进制奇偶位交换前：\n");
    printBinary(n);
    SWAP_BINARY_BIT(n);
    printf("二进制奇偶位交换后：\n");
    printBinary(n);
    return 0;
}