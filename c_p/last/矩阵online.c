#include<stdio.h>
#include<math.h>
void jiafa()
{
int m, n;
float a[20][20], b[20][20], c[20][20];
int i,j;
printf("��������������� ");
scanf("%d", &m);
printf("���������������");
scanf("%d", &n);
printf("�������һ������:");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f", &a[i][j]);
printf("������ڶ�������");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f",&b[i][j]);
printf("������ӵĽ��Ϊ��");
for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
				printf("%4f ", c[i][j] );
			}
		printf ("\n");
	}
}
void jianfa()
{
int m,n;
float a[20][20],b[20][20],c[20][20];
int i,j;
printf("��������������� ");
scanf("%d", &m);
printf("���������������");
scanf("%d", &n);
printf("�������һ������");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%f", &a[i][j]);
printf("������ڶ�������");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f", &b[i][j]);
printf("��������Ľ��Ϊ��");
for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			{
				c[i][j]=a[i][j]-b[i][j];
				printf("%4f ", c[i][j]);
			}
		printf("\n");
	}
}
void chengfa()
{
int m, n;
float s;
float a[20][20],b[20][20],c[20][20];
int i,j,k;
printf("���������������");
scanf("%d", &m);
printf("���������������"); 
scanf("%d", &n);

printf("�������һ������");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%f",&a[i][j]);

printf("������ڶ������� ");
for(i=0;i<n;i++)
for(j=0; j<m;j++)
scanf("%4f", &b[i][j]);

for(i=0;i<m;i++)
	{
	for(j=0; j<m;j++)
		{
			s=0;
			for(k=0;k<n;k++)
				{
					s=s+a[i][k]*b[k][j];
					c[i][j]=s;
				}
		}
	}
for(i=0;i<m;i++)
	{
	for(j=0; j<m;j++)
		{
			printf("%4f ", c[i][j] );
		}
	printf("\n");
	}
}
void zhuanzhi()
{
int m, n;
float a[20][20], b[20][20];
int i,j;
printf("��������������� ");
scanf("%d", &m);
printf("���������������");
scanf("%d", &n);
printf("������һ������");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f", &a[i][j] );
for(i=0;i<m;i++)\
	{
		for(j=0; j<n;j++)
		{
		b[i][j]=a[j][i];
		printf("%4f ", b[i][j]);
	}
	printf("\n");
	}
}
void qiuni()
{
int N;
printf("�������Ľ���N:\n");
scanf("%d", &N);
float a[10][10],b[10][20],c[10][10],t;
int i,j,m;
printf("����������ʽ��Ϊ0�ľ���A(%d��)An", N); 
//����A�ĸ�Ԫ�ش����ά����a�С�
for(i=0;i<N;i++)
for(j=0;j<N;j++)
scanf("%f", &a[i][j]);
//������� A|E)�����ά����b��
for(i=0;i<N;i++)
for(j=0; j<N;j++)
b[i][j]=a[i][j];
for(i=0;i<N;i++)
for(j=N;j<2*N;j++)
b[i][j]=0;
for(i=0;i<N;i++)
b[i][N+i]=1;
for(m=0;m<N;m++) //��ÿ�н��д���
{
t=b[m][m];
i=m;
while(b[m][m]==0)
//Ԥ�� b[m][m]��
b[m][m]=b[i+1][m];
i++;
}
if(i>m)
{
b[i][m]=t; //ʵ�ֽ�����
//��������������Ӧλ�õ�Ԫ��
for(j=0; j<m;j++)
{
t=b[m][j];
b[m][j]=b[i][j];
b[i][j]=t;
}
for(j=m+1 ;j<2*N;j++)
	{
	t=b[m][j];
	b[m][j]=b[i][j];
	b[i][j]=t;
	}
}
for(i=m+1 ;i<N;i++)
for(j=2*N-1 ;j>=m;j--)
b[i][j]-=b[i][m]*b[m][j]/b[m][m]; 
/*m=0 ʱ,����һ�е�-b[i][0] /b[0][0]���ӵ���
�¸��С���������ÿ�е�һ��Ԫ��b[i][0]��Ϊ0��*/

for(j=2*N-1 ;j>=m;j--)
b[m][j]/=b[m][m]; 
//�Ե�m�����б任,ͬ����b[m][m],ʹb[m][m]Ϊ1��

printf("��һ���任��õ����������Ϊ�� \n");
for(i=0;i<N;i++)
	{
	for(j=0;j<2*N;j++)printf("%3.5f ",b[i][j]);
	printf("\n"); //ʵ���� ��ÿ��i��Ӧһ�����С�
	}
	m=N-1;
while(m>0)
{
	for(i=0;i<m;i++)
	for(j=2*N-1;j>=m;j--) //ǧ��ע��,�˴�j����ݼ�,�����ȱ�Ϊ0,����ļ������Ч��
	b[i][j]-=b[i][m]*b[m][m];
	m--;
}
printf("���õ����������Ϊ�� \n");
for(i=0;i<N;i++)
	{
		for(j=0; j<2*N;j++)printf("%3.5f ",b[i][j]);
		printf("\n"); //ʵ���� ��ÿ��i��Ӧһ�����С�
	}
	
		//�����������ά����c�С�
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		c[i][j]=b[i][N+j];printf("�������Ϊ�� \n");
for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)printf("%3.5f ",c[i][j]);
		printf("\n"); //ʵ���� ��ÿ��i��Ӧһ�����С�
	}
}
int main()
{
int w;
printf("1����ӷ�\n");
printf("2 �������\n");
printf("3 ����˷�\n");
printf("4 ����ת��\n");
printf("5��������\n");
printf("\n");
printf("��ѡ��Ҫ���е�����:");
scanf("%d", &w);
switch (w)
{
case 1 :jiafa();break;
case 2:jianfa();break;
case 3:chengfa();break;
case 4:zhuanzhi();break;
case 5:qiuni();break;
}
return 0;
}
