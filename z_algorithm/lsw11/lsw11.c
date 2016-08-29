#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 10
void fun1(double  args[], FILE *into);
void fun2(double  args[], FILE *into);

int RandomNumber;
int toRate[] = { -1, -1, -1, -1, -1, -1, -1, -5, +10, +10 };
double Bet = 0.1;
double Sum = 1.0;
int count = 1;
int countNegtive = 0;

int main()
{
	FILE *into;
	double ans[4];
	srand(time(NULL));
	if ((into = fopen("pol.txt", "wt")) == NULL)
	{
		printf("Can't open file.\n");
		exit(EXIT_FAILURE);
	}
		fprintf(into,"Count\tMax_his\tMin_his\tThe_end\n");
	fun2(ans, into);
	fclose(into);
	return 0;
}

void fun1(double  args[], FILE *into)
{
	int jj = 0;
	args[0] = 1.0;
	args[1] = 1.0;
	args[2] = 1.0;
	Sum = 1.0;
	for (jj = 0; jj < 1000; jj++)
	{

		RandomNumber = (rand() % N);
		Sum = Sum + Bet * toRate[RandomNumber];
		if (Sum > args[0])
			args[0] = Sum;
		if (Sum < args[1])
			args[1] = Sum;
		if (Sum <= 0)
			{countNegtive ++;break;}
		//printf("\n%d\t%d\t%.1f\n",jj,RandomNumber,Sum);
	}
	printf("%.2f\t%.2f\n", args[0], args[1]);
	fprintf(into,"%d\t%.2f\t%.2f\t%.2f\n", count++, args[0], args[1],Sum);
	args[2] = Sum;
}

void fun2(double  args[], FILE *into)
{
	int ii = 0;
	args[0] = 1.0;
	args[1] = 1.0;
	args[2] = 1.0;
	args[3] = 1.0;
	double ans[3];
	for (ii = 0; ii < 100; ii++)
	{
		fun1(ans, into);
		if (ans[0] > args[0])
			args[0] = ans[0];
		if (ans[1] < args[1])
			args[1] = ans[1];
		if(ans[2]>args[2])args[2] = ans[2];
		if(ans[2]<args[3])args[3] = ans[2];
	}
	printf("%.2f\t%.2f\n", args[0], args[1]);
	printf("Negtive Rate = %d/100",countNegtive);
	fprintf(into,"ALL_in_history\t%.2f\t%.2f\n", args[0], args[1]);
	fprintf(into,"ALL_in_the_end\t%.2f\t%.2f\n", args[2], args[3]);
}