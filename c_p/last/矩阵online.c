#include<stdio.h>
#include<math.h>
void jiafa()
{
int m, n;
float a[20][20], b[20][20], c[20][20];
int i,j;
printf("请输入矩阵行数： ");
scanf("%d", &m);
printf("请输入矩阵列数：");
scanf("%d", &n);
printf("请输入第一个矩阵:");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f", &a[i][j]);
printf("请输入第二个矩阵");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f",&b[i][j]);
printf("矩阵相加的结果为：");
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
printf("请输入矩阵行数： ");
scanf("%d", &m);
printf("请输入矩阵列数：");
scanf("%d", &n);
printf("请输入第一个矩阵");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%f", &a[i][j]);
printf("请输入第二个矩阵：");
for(i=0;i<m;i++)
for(j=0; j<n;j++)
scanf("%f", &b[i][j]);
printf("矩阵相减的结果为：");
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
printf("请输入矩阵行数：");
scanf("%d", &m);
printf("请输入矩阵列数："); 
scanf("%d", &n);

printf("请输入第一个矩阵");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%f",&a[i][j]);

printf("请输入第二个矩阵： ");
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
printf("请输入矩阵行数： ");
scanf("%d", &m);
printf("请输入矩阵列数：");
scanf("%d", &n);
printf("请输入一个矩阵：");
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
printf("输入矩阵的阶数N:\n");
scanf("%d", &N);
float a[10][10],b[10][20],c[10][10],t;
int i,j,m;
printf("请输入行列式不为0的矩阵A(%d阶)An", N); 
//矩阵A的各元素存入二维数组a中。
for(i=0;i<N;i++)
for(j=0;j<N;j++)
scanf("%f", &a[i][j]);
//增广矩阵（ A|E)存入二维数组b中
for(i=0;i<N;i++)
for(j=0; j<N;j++)
b[i][j]=a[i][j];
for(i=0;i<N;i++)
for(j=N;j<2*N;j++)
b[i][j]=0;
for(i=0;i<N;i++)
b[i][N+i]=1;
for(m=0;m<N;m++) //对每行进行处理。
{
t=b[m][m];
i=m;
while(b[m][m]==0)
//预存 b[m][m]。
b[m][m]=b[i+1][m];
i++;
}
if(i>m)
{
b[i][m]=t; //实现交换。
//交换其它各列相应位置的元素
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
/*m=0 时,将第一行的-b[i][0] /b[0][0]倍加到以
下各行。这样以下每行第一个元素b[i][0]就为0。*/

for(j=2*N-1 ;j>=m;j--)
b[m][j]/=b[m][m]; 
//对第m行作行变换,同除以b[m][m],使b[m][m]为1。

printf("第一步变换后得到的增广矩阵为： \n");
for(i=0;i<N;i++)
	{
	for(j=0;j<2*N;j++)printf("%3.5f ",b[i][j]);
	printf("\n"); //实现了 ：每个i对应一个换行。
	}
	m=N-1;
while(m>0)
{
	for(i=0;i<m;i++)
	for(j=2*N-1;j>=m;j--) //千万注意,此处j必须递减,否则先变为0,后面的计算就无效！
	b[i][j]-=b[i][m]*b[m][m];
	m--;
}
printf("最后得到的增广矩阵为： \n");
for(i=0;i<N;i++)
	{
		for(j=0; j<2*N;j++)printf("%3.5f ",b[i][j]);
		printf("\n"); //实现了 ：每个i对应一个换行。
	}
	
		//将逆矩阵存入二维数组c中。
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		c[i][j]=b[i][N+j];printf("故逆矩阵为： \n");
for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)printf("%3.5f ",c[i][j]);
		printf("\n"); //实现了 ：每个i对应一个换行。
	}
}
int main()
{
int w;
printf("1矩阵加法\n");
printf("2 矩阵减法\n");
printf("3 矩阵乘法\n");
printf("4 矩阵转置\n");
printf("5矩阵求逆\n");
printf("\n");
printf("请选择要进行的运算:");
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
