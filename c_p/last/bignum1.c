#include"stdio.h"

void BigFactorial(int m)
{
    static int a[50000]= {0,1}; //��һλ����
    int i,j,k,carry,tmp,lenth=1;//carry��ʾ��λ

    for (i=2; i<=m; i++)
    {
        carry=0;
        for (j=1; j<=lenth; j++)
        {
            //�˷�ת��Ϊ�ӷ��ͽ�λ
            tmp=a[j]*i+carry;
            a[j]=tmp%10;
            carry=tmp/10;

            //����н�λ������ǰ��չһλ
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
