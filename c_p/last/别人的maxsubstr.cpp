#include<iostream>
using namespace std;
int main()
{
	int N;
	int *input;
	int i;
	int begin=0, end=0, sum=0;  //��������������е���ʼλ�ã���ֹλ�ã��Լ������к͡�
	int tempSum=0, tempBegin=0, tempEnd=0;  //Ŀǰ���ڿ���������е���ʼλ�ã���ֹλ�ã��Լ������еĺ͡�
	
	cin>>N;	
	input = new int[N];	
	for(i=0; i<N; i++)
		cin>>input[i];

	end = N-1;  
	for(i=0; i<N; i++)
	{
		if(tempSum >= 0)
		{
			tempSum += input[i];
			tempEnd = i;
		}
		else {
			//���tempSum<0,��ôtempSum+input[i]<input[i]
			//���Դ�ʱ����Ҫ��ʼ�����µ�������
			tempSum = 0; 
			tempSum += input[i];
			tempBegin = i;
			tempEnd = i;
		}

		//if(tempSum > sum) ����д����AC��Ӧ��Ϊ���£�
		if(tempSum > sum || (tempSum == 0 && end == N-1))
		{
			sum = tempSum;
			begin = tempBegin;
			end = tempEnd;
		}		
	}
	cout<<sum<<" "<<input[begin]<<" "<<input[end]<<endl;
	return 0;
}
