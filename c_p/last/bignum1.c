#include"stdio.h"

void BigFactorial(int m)
{
    static int a[50000]= {0,1}; //第一位不用
    int i,j,k,carry,tmp,lenth=1;//carry表示进位

    for (i=2; i<=m; i++)
    {
        carry=0;
        for (j=1; j<=lenth; j++)
        {
            //乘法转化为加法和进位
            tmp=a[j]*i+carry;
            a[j]=tmp%10;
            carry=tmp/10;

            //如果有进位，则向前扩展一位
            if (j==lenth&&carry!=0)
                lenth++;
        }
    }
    for(k=lenth; k>=1; k--)
        printf("%d",a[k]);
}
int main()
{
    int n;
    printf("input a interger ");
    scanf("%d",&n);
    printf("%d!=",n);
    BigFactorial(n);
}
