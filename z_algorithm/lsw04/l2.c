#include<stdio.h>
#include<stdlib.h>



int main(int argc, char* argv[])
{
	char *str=(argv[1]);long amount=0,i=0,year=0,month=0,day=0,hour=0,minute=0,second=0;
	//puts(str);
	while(str[i]!='Y')
	{year=year*10+(str[i]-'0');i++;}
	i++;
	while(str[i]!='M')
	{month=month*10+(str[i]-'0');i++;}
	i++;
	while(str[i]!='D')
	{day=day*10+(str[i]-'0');i++;/*printf("\nday=%ld\n",day);*/}
	i++;
	while(str[i]!='h')
	{hour=hour*10+(str[i]-'0');i++;}
	i++;
	while(str[i]!='m')
	{minute=minute*10+(str[i]-'0');i++;}
	i++;
	while(str[i]!='s')
	{second=second*10+(str[i]-'0');i++;}
	
	amount=((((year*12+month)*30+day)*24+hour)*60+minute)*60+second;
	printf("%ld",amount);
	return 0;
}