#include"stdio.h"
#include"stdlib.h"

typedef struct
{
    long  aa;
    long bb;
} fen;											//�����ṹ����
fen R2[20][20];												//ȫ�ֱ���
fen addfen(fen a1,fen a2);							//�����ӷ�
fen mulfen(fen a1,fen a2);							//�����˷�
fen sumadd(fen a1[20][20],long n1,fen a2[20][20],long n2,long m);//������
void yuefen(fen *a1);									//����Լ��
void pingfang(fen a1[20][20],long m);			//����ƽ��
void hilb2(long n,int t);													//ϣ�����ص�ƽ��
void printfen(fen R[20][20],long m);				//��ӡ��������
void printb(double d[40][40],long n1,long n2);//��ӡһ�����
long hilb_1(long n);														//����hilb����
long hilb_2(long n);														//����hilb����
void qiuni(long N,int t);
void printmenu();													//����hilb�����

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
//������
fen subfen(fen a1)
{
    fen a3;
    a3.aa=-(a1.aa);
    a3.bb=(a1.bb);
    return a3;
}
//��������
fen divfen(fen a1)
{
    fen a3;
    a3.aa=(a1.bb);
    a3.bb=(a1.aa);
    return a3;
}
//�����ӷ�
fen addfen(fen a1,fen a2)
{
    fen a3;
    a3.aa=(a1.aa)*(a2.bb)+(a1.bb)*(a2.aa);
    a3.bb=(a1.bb)*(a2.bb);
    yuefen(&a3);
    return a3;
}
//�����˷�
fen mulfen(fen a1,fen a2)
{
    fen a3;
    a3.aa=(a1.aa)*(a2.aa);
    a3.bb=(a1.bb)*(a2.bb);
    yuefen(&a3);
    return a3;
}
//����Լ��
void yuefen(fen *a1)
{
    long r,m=(*a1).bb,n=(*a1).aa;
    if(a1->aa==0)
    {
        a1->bb=1;
        return;
    }
    r=m%n;										//��mСʱ�������m���n��С
    while(r!=0)
    {
        m=n;
        n=r;
        r=m%n;
    }
    //n�����Լ����
    (*a1).bb/=n;
    (*a1).aa/=n;
    return;
}
//������
fen sumadd(fen a1[20][20],long n1,fen a2[20][20],long n2,long m)
{
    fen a3,a4;
    long i;
    a3.aa=0;
    a3.bb=1;
    for(i=0; i<m; i++)
    {
        a4=mulfen(a1[n1][i],a2[i][n2]);//�ϵ�printf("[so far mul]");system("pause");
        a3=addfen(a3,a4);		/*printf("[so far add%d/%d]",a3.aa,a3.bb);system("pause");*/
    }
//�ϵ�	printf("[so far3]");system("pause");
    return a3;
}
//����ƽ��
void pingfang(fen a1[20][20],long m)
{
    long i,j;
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
        {
            R2[i][j]=sumadd(a1,i,a1,j,m);/*printf("[so far sum %d/%d]",R2[i][j].aa,R2[i][j].bb);system("pause");*/
        }
//�ϵ�	printf("[so far4]");system("pause");
    return;
}
//ϣ�����ص�ƽ��
void hilb2(long n,int t)
{
    long i,j;
    fen a1[20][20];
//�ϵ�	printf("[so far]");system("pause");

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            a1[i][j].aa=1;
            a1[i][j].bb=i+j+1;
        }
    pingfang(a1,n);

//�ϵ�	printf("[so far--]");system("pause");
    if(t==1)printfen(R2,n);
    else
    {
        //system("cls");
        printf("����:\n");
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                printf("%9f",(float)R2[i][j].aa/(float)R2[i][j].bb);
            printf("\n");
        }
    }

    return;
}
//��ӡ��������
void printfen(fen R[20][20],long m)
{
    long i,j,k;
    //system("cls");
    printf("��������:\n");
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
//��ӡһ�����
void printb(double d[40][40],long n1,long n2)
{
    long i,j;

    printf("����:\n");
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
    printf("����:\n");
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
//����hilb����
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
//����hilb����
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
//����hilb�����
void qiuni(long N,int t)
{
    double a[20][20],b[20][40],c[20][20];
    long i,j,m;
//����A�ĸ�Ԫ�ش����ά����a�С�
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            a[i][j]=1.0/(i+j+1);

//�������(A|E)�����ά����b��
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            b[i][j]=a[i][j];
    for(i=0; i<N; i++)
        for(j=N; j<2*N; j++)
            b[i][j]=0;
    for(i=0; i<N; i++)
        b[i][N+i]=1;

//��ÿ�н��д���Ŀ��Ϊ�����Ǿ���
    for(m=0; m<N; m++)
    {
//��m�в���
        for(i=m+1 ; i<N; i++)
        {
            for(j=2*N-1 ; j>=m; j--)
            {
                b[i][j]=-b[i][m]*b[m][j]/b[m][m]+b[i][j];
            }
        }
        /*m=0 ʱ,����һ�е�-b[i][0]/b[0][0]���ӵ����¸��С���������ÿ�е�һ��Ԫ��b[i][0]��Ϊ0��*/
//�ϵ�printb(b,N,2*N);
        for(j=2*N-1 ; j>=m; j--)b[m][j]=b[m][j]/b[m][m];
//��m�й�һ,����b[m][m],ʹb[m][m]Ϊ1��

    }
//�����Ǿ������

    m=N-1;
//�����Ǿ���䵥λ����
    while(m>0)
    {
        for(i=0; i<m; i++)
            for(j=2*N-1; j>=m; j--)			//�Ӻ�����㡣
                b[i][j]=b[i][j]-b[i][m]*b[m][j];
        m--;							//�ϵ�printb(b,N,2*N);
//���һ������һ�С��ڶ��С�Ȼ���ǵ����ڶ�������һ�С��ڶ��С�
    }
//�����������ά����c�С�
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            c[i][j]=b[i][N+j];
//��ӡ
    //system("cls");
    printf("�����Ϊ�� \n");
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
//����A�ĸ�Ԫ�ش����ά����a�С�
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            a[i][j].aa=1;
            a[i][j].bb=(i+j+1);
        }

//�������(A|E)�����ά����b��
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

//��ÿ�н��д���Ŀ��Ϊ�����Ǿ���
    for(m=0; m<N; m++)
    {
//��m�в���
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
//m=0 ʱ,����һ�е�-b[i][0]/b[0][0]���ӵ����¸��С���������ÿ�е�һ��Ԫ��b[i][0]��Ϊ0��

        printbfen(b,N,2*N);
        for(j=2*N-1 ; j>=m; j--)
        {
            //b[m][j]=b[m][j]/b[m][m];
            b[m][j]=mulfen(divfen(b[m][m]),b[m][j]);
        }
//��m�й�һ,����b[m][m],ʹb[m][m]Ϊ1��

    }
//�����Ǿ������

    m=N-1;
//�����Ǿ���䵥λ����
    while(m>0)
    {
        for(i=0; i<m; i++)
            for(j=2*N-1; j>=m; j--)			//�Ӻ�����㡣
                //b[i][j]=b[i][j]-b[i][m]*b[m][j];
            {
                b[i][j]=addfen(subfen(mulfen(b[i][m],b[m][j])),b[i][j]);
            }
        m--;

        printbfen(b,N,2*N);
//���һ������һ�С��ڶ��С�Ȼ���ǵ����ڶ�������һ�С��ڶ��С�
    }
//�����������ά����c�С�
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            c[i][j]=b[i][N+j];
        }
//��ӡ
    printfen(c,N);
}
void printmenu()
{
    printf("1. �Ը���������ʽ��ӡ 4 �� Hilbert ����.\n");
    printf("2. �Ը���������ʽ��ӡ n �� Hilbert ����.\n");
    printf("3. ������������ʽ��ӡ 4 �� Hilbert ����.\n");
    printf("4. ������������ʽ��ӡ n �� Hilbert ����.\n");
    printf("5. �Ը���������ʽ���� 4 �� Hilbert �����ƽ��.\n");
    printf("6. ������������ʽ���� 4 �� Hilbert �����ƽ��.\n");
    printf("7. �Ը���������ʽ���� 4 �� Hilbert �������.\n");
    printf("8. ������������ʽ���� 4 �� Hilbert �������.\n");
    printf("9. ������������ʽ���� 6 �� Hilbert �������.\n");
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
            printf("����Ľ��� n=");
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
            printf("����Ľ��� n=");
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
            printf("����Ľ��� n=");
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
            printf("����Ľ��� n=");
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

