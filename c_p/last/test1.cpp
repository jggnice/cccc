#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::ios;

#include <fstream>
using std::ofstream;

#include <cstdlib>

#include <ctime>

int convertToDec(char *,int);

void main()
{
	const int SIZE=30;
	char datas[SIZE];
	int decs;
	cout<<"请输入一行二进制代码:";
	int i=0,n;
    while((datas[i]=cin.get())!='\n')
	{
		i++;
	}
    decs=convertToDec(datas,i);

    ofstream outFile("output.txt",ios::out);
	if(!outFile)
	{
		cerr<<"File could not be opened"<<endl;
		exit(1);
	}
	srand(time(0));
	n = rand()%10 +1;
	cout<<decs<<"  "<<n<<endl;
    while(n--)
	{
		outFile<<decs<<endl;
	}

}

int convertToDec(char data[],int size)
{
	int decNum=0;
	int temp;
	for(int i=0;i<size;i++)
	{
		temp=(int)data[i]-48;
		decNum=decNum * 2;
		decNum+=temp;
	}
	return decNum;
}