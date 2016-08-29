#include"stdio.h"
#include"stdlib.h"

typedef struct
{
    long  aa;
    long bb;
} fen;											//分数结构类型
fen R2[20][20];												//全局变量
fen addfen(fen a1,fen a2);							//分数加法
fen mulfen(fen a1,fen a2);							//分数乘法
fen sumadd(fen a1[20][20],long n1,fen a2[20][20],long n2,long m);//向量积
void yuefen(fen *a1);									//分数约分
void pingfang(fen a1[20][20],long m);			//矩阵平方
void hilb2(long n,int t);													//希尔伯特的平方
void printfen(fen R[20][20],long m);				//打印分数矩阵
void printb(double d[40][40],long n1,long n2);//打印一般矩阵
long hilb_1(long n);														//浮点hilb矩阵
long hilb_2(long n);														//有理hilb矩阵
void qiuni(long N,int t);
void printmenu();													//浮点hilb逆矩阵

int count(int num)
{
    int num1=(num),i=0;
    if(num<0)
    {
        i++;
        num1=-num;
    }
    while(num1>0)
    {
        num1/=10;
        i++;
    }
    return i;
}
//分数求负
fen subfen(fen a1)
{
    fen a3;
    a3.aa=-(a1.aa);
    a3.bb=(a1.bb);
    return a3;
}
//分数倒数
fen divfen(fen a1)
{
    fen a3;
    a3.aa=(a1.bb);
    a3.bb=(a1.aa);
    return a3;
}
//分数加法
fen addfen(fen a1,fen a2)
{
    fen a3;
    a3.aa=(a1.aa)*(a2.bb)+(a1.bb)*(a2.aa);
    a3.bb=(a1.bb)*(a2.bb);
    yuefen(&a3);
    return a3;
}
//分数乘法
fen mulfen(fen a1,fen a2)
{
    fen a3;
    a3.aa=(a1.aa)*(a2.aa);
    a3.bb=(a1.bb)*(a2.bb);
    yuefen(&a3);
    return a3;
}
//分数约分
void yuefen(fen *a1)
{
    long r,m=(*a1).bb,n=(*a1).aa;
    if(a1->aa==0)
    {
        a1->bb=1;
        return;
    }
    r=m%n;										//当m小时，下面的m变大，n变小
    while(r!=0)
    {
        m=n;
        n=r;
        r=m%n;
    }
    //n是最大公约数；
    (*a1).bb/=n;
    (*a1).aa/=n;
    return;
}
//向量积
fen sumadd(fen a1[20][20],long n1,fen a2[20][20],long n2,long m)
{
    fen a3,a4;
    long i;
    a3.aa=0;
    a3.bb=1;
    for(i=0; i<m; i++)
    {
        a4=mulfen(a1[n1][i],a2[i][n2]);//断点printf("[so far mul]");system("pause");
        a3=addfen(a3,a4);		/*printf("[so far add%d/%d]",a3.aa,a3.bb);system("pause");*/
    }
//断点	printf("[so far3]");system("pause");
    return a3;
}
//矩阵平方
void pingfang(fen a1[20][20],long m)
{
    long i,j;
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
        {
            R2[i][j]=sumadd(a1,i,a1,j,m);/*printf("[so far sum %d/%d]",R2[i][j].aa,R2[i][j].bb);system("pause");*/
        }
//断点	printf("[so far4]");system("pause");
    return;
}
//希尔伯特的平方
void hilb2(long n,int t)
{
    long i,j;
    fen a1[20][20];
//断点	printf("[so far]");system("pause");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            a1[i][j].aa=1;
            a1[i][j].bb=i+j+1;
        }
    pingfang(a1,n);

//断点	printf("[so far--]");system("pause");
    if(t==1)printfen(R2,n);
    else
    {
        //system("cls");
        printf("矩阵:\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                printf("%9f",(float)R2[i][j].aa/(float)R2[i][j].bb);
            printf("\n");
        }
    }

    return;
}
//打印分数矩阵
void printfen(fen R[20][20],long m)
{
    long i,j,k;
    //system("cls");
    printf("分数矩阵:\n");
    for(i=0; i<m; i++)
    {
        printf("[");
        for(j=0; j<m; j++)
        {
            printf("%9d/%d",R[i][j].aa,R[i][j].bb);
            for(k=0; k<6-count(R[i][j].bb); k++)printf(" ");
        }
        printf("]\n");
        if(i<m-1)
        {
            printf("[");
            for(k=1; k<=16*m; k++)
                printf(" ");
            printf("]\n");
        }
    }
}
//打印一般矩阵
void printb(double d[40][40],long n1,long n2)
{
    long i,j;

    printf("矩阵:\n");
    for(i=0; i<n1; i++)
    {
        for(j=0; j<n2; j++)printf("%9.2f ",d[i][j]);
        printf("\n");
    }

}
void printbfen(fen d[40][40],long n1,long n2)
{
    long i,j,k;
    //system("cls");
    printf("矩阵:\n");
    for(i=0; i<n1; i++)
    {
        for(j=0; j<n2; j++)
        {
            printf("%7d/%d ",d[i][j].aa,d[i][j].bb);
            for(k=0; k<4-count(d[i][j].bb); k++)printf(" ");
        }
        printf("\n");
    }

}
//浮点hilb矩阵
long hilb_1(long n)
{
    long i,j;

    //system("cls");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%6.3f",1.0/(i+j-1));
        printf("\n");
    }
    return 0;

}
//有理hilb矩阵
long hilb_2(long n)
{
    long i,j,k;

    //system("cls");
    for(i=1; i<=n; i++)
    {
        printf("[");
        for(j=1; j<=n; j++)
            printf("1/%-4d",(i+j-1));
        printf("]\n");
        if(i<n)
        {
            printf("[");
            for(k=1; k<=6*n; k++)
                printf(" ");
            printf("]\n");
        }
    }

    return 0;

}
//浮点hilb逆矩阵
void qiuni(long N,int t)
{
    double a[20][20],b[20][40],c[20][20];
    long i,j,m;
//矩阵A的各元素存入二维数组a中。
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            a[i][j]=1.0/(i+j+1);

//增广矩阵(A|E)存入二维数组b中
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            b[i][j]=a[i][j];
    for(i=0; i<N; i++)
        for(j=N; j<2*N; j++)
            b[i][j]=0;
    for(i=0; i<N; i++)
        b[i][N+i]=1;

//对每行进行处理，目标为上三角矩阵
    for(m=0; m<N; m++)
    {
//第m行不动
        for(i=m+1 ; i<N; i++)
        {
            for(j=2*N-1 ; j>=m; j--)
            {
                b[i][j]=-b[i][m]*b[m][j]/b[m][m]+b[i][j];
            }
        }
        /*m=0 时,将第一行的-b[i][0]/b[0][0]倍加到以下各行。这样以下每行第一个元素b[i][0]就为0。*/
//断点printb(b,N,2*N);
        for(j=2*N-1 ; j>=m; j--)b[m][j]=b[m][j]/b[m][m];
//第m行归一,除以b[m][m],使b[m][m]为1。

    }
//上三角矩阵完毕

    m=N-1;
//上三角矩阵变单位矩阵
    while(m>0)
    {
        for(i=0; i<m; i++)
            for(j=2*N-1; j>=m; j--)			//从后面计算。
                b[i][j]=b[i][j]-b[i][m]*b[m][j];
        m--;							//断点printb(b,N,2*N);
//最后一行消第一行、第二行…然后是倒数第二行消第一行、第二行…
    }
//将逆矩阵存入二维数组c中。
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            c[i][j]=b[i][N+j];
//打印
    //system("cls");
    printf("逆矩阵为： \n");
    if(t==1)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)printf("%9.2f ",c[i][j]);
            printf("\n");
        }
    }
    else
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)printf("%9d ",(long)(c[i][j]));
            printf("\n");
        }
    }

}
void qiuni2(long N)
{
    fen a[20][20],b[20][40],c[20][20],t1,t2;
    long i,j,m;
//矩阵A的各元素存入二维数组a中。
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            a[i][j].aa=1;
            a[i][j].bb=(i+j+1);
        }

//增广矩阵(A|E)存入二维数组b中
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            b[i][j]=a[i][j];
    for(i=0; i<N; i++)
        for(j=N; j<2*N; j++)
        {
            b[i][j].aa=0;
            b[i][j].bb=1;
        }
    for(i=0; i<N; i++)
    {
        b[i][N+i].aa=1;
        b[i][N+i].bb=1;
    }

//对每行进行处理，目标为上三角矩阵
    for(m=0; m<N; m++)
    {
//第m行不动
        for(i=m+1 ; i<N; i++)
        {
            for(j=2*N-1 ; j>=m; j--)
            {
                //b[i][j]=-b[i][m]*b[m][j]/b[m][m]+b[i][j];
                t1=mulfen(b[i][m],b[m][j]);
                t2=mulfen(t1,divfen(b[m][m]));
                b[i][j]=addfen(subfen(t2),b[i][j]);

            }
        }
//m=0 时,将第一行的-b[i][0]/b[0][0]倍加到以下各行。这样以下每行第一个元素b[i][0]就为0。

        printbfen(b,N,2*N);
        for(j=2*N-1 ; j>=m; j--)
        {
            //b[m][j]=b[m][j]/b[m][m];
            b[m][j]=mulfen(divfen(b[m][m]),b[m][j]);
        }
//第m行归一,除以b[m][m],使b[m][m]为1。

    }
//上三角矩阵完毕

    m=N-1;
//上三角矩阵变单位矩阵
    while(m>0)
    {
        for(i=0; i<m; i++)
            for(j=2*N-1; j>=m; j--)			//从后面计算。
                //b[i][j]=b[i][j]-b[i][m]*b[m][j];
            {
                b[i][j]=addfen(subfen(mulfen(b[i][m],b[m][j])),b[i][j]);
            }
        m--;

        printbfen(b,N,2*N);
//最后一行消第一行、第二行…然后是倒数第二行消第一行、第二行…
    }
//将逆矩阵存入二维数组c中。
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            c[i][j]=b[i][N+j];
        }
//打印
    printfen(c,N);
}
void printmenu()
{
    printf("1. 以浮点数的形式打印 4 阶 Hilbert 矩阵.\n");
    printf("2. 以浮点数的形式打印 n 阶 Hilbert 矩阵.\n");
    printf("3. 以有理数的形式打印 4 阶 Hilbert 矩阵.\n");
    printf("4. 以有理数的形式打印 n 阶 Hilbert 矩阵.\n");
    printf("5. 以浮点数的形式计算 4 阶 Hilbert 矩阵的平方.\n");
    printf("6. 以有理数的形式计算 4 阶 Hilbert 矩阵的平方.\n");
    printf("7. 以浮点数的形式计算 4 阶 Hilbert 矩阵的逆.\n");
    printf("8. 以有理数的形式计算 4 阶 Hilbert 矩阵的逆.\n");
    printf("9. 以有理数的形式计算 6 阶 Hilbert 矩阵的逆.\n");
}
long main()
{
    char menu;
    long n;
    printmenu();
    while((menu=getchar())!='q')
    {
        switch(menu)
        {
        case '1' :
            hilb_1(4);
            break;
            system("pause");
            system("cls");
            printmenu();
        case '2' :
            printf("矩阵的阶数 n=");
            scanf("%d",&n);
            if(n<1||n>20)
            {
                printf("1<=n&&n<=20");
                break;
            }
            hilb_1(n);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '3' :
            hilb_2(4);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '4' :
            printf("矩阵的阶数 n=");
            scanf("%d",&n);
            if(n<1||n>20)
            {
                printf("1<=n&&n<=20");
                break;
            }
            hilb_2(n);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '5' :
            hilb2(4,2);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '6' :
            hilb2(4,1);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '7' :
            qiuni(4,1);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '8' :
            qiuni2(4);
            system("pause");
            system("cls");
            printmenu();
            break;
        case '9' :
            qiuni2(6);
            system("pause");
            system("cls");
            printmenu();
            break;
        case 'a' :
            printf("矩阵的阶数 n=");
            scanf("%d",&n);
            if(n<1||n>20)
            {
                printf("1<=n&&n<=20");
                break;
            }
            qiuni(n,2);
            system("pause");
            system("cls");
            printmenu();
            break;
        case 'b' :
            printf("矩阵的阶数 n=");
            scanf("%d",&n);
            if(n<1||n>20)
            {
                printf("1<=n&&n<=20");
                break;
            }
            qiuni2(n);
            system("pause");
            system("cls");
            printmenu();
            break;
        }
    }
    return 0;
}

