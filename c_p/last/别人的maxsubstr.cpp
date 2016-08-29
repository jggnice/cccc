#include<iostream>
using namespace std;
int main()
{
	int N;
	int *input;
	int i;
	int begin=0, end=0, sum=0;  //最终所求的子序列的起始位置，终止位置，以及子序列和。
	int tempSum=0, tempBegin=0, tempEnd=0;  //目前正在考察的子序列的起始位置，终止位置，以及子序列的和。
	
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
			//如果tempSum<0,那么tempSum+input[i]<input[i]
			//所以此时我们要开始考察新的子序列
			tempSum = 0; 
			tempSum += input[i];
			tempBegin = i;
			tempEnd = i;
		}

		//if(tempSum > sum) 这样写不能AC，应改为如下：
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
