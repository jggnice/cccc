#include<stdio.h>
#include<stdlib.h>
int next = 0;
int rear = 0;
unsigned int swappage1(int flag,unsigned int page[],unsigned int mem[],unsigned int start,unsigned int current,unsigned int max_memory,unsigned int num_of_page)
{
	if(!flag)return 0;
	int pos = next;
	next = (next + 1) % max_memory;
	return pos;
}
unsigned int swappage2(int flag,unsigned int page[],unsigned int mem[],unsigned int start,unsigned int current,unsigned int max_memory,unsigned int num_of_page)
{
	unsigned int pos = 0;
	int maxv = -1;
	int i,j;
	if(!flag)return 0;
	for(i = 0; i < max_memory; i++)
	{
		int findflag = 0;
		for(j = start;j < num_of_page; j++)
		{
			if(page[j] == mem[i])
			{
				findflag = 1;
				if(j > maxv)
				{
					maxv = j;
					pos = i;
				}
				break;
			}
		}
		if(findflag)
		continue;
	/// if mem[i] end of page
	maxv = num_of_page;
	pos = i;
	return pos;
	}
	return pos;
}
unsigned int swappage3(int flag,unsigned int page[],unsigned int mem[],unsigned int start,unsigned int current,unsigned int max_memory,unsigned int num_of_page)
{
	int pos = rear;
	/// in the queue
	int i;
	if(!flag)
	{
		int temp = mem[current];
		for(i = current; i != rear; i= (i - 1 + max_memory) % max_memory)
		{
			mem[i] = mem[(i - 1 + max_memory) % max_memory];
		}
		mem[rear] = temp;
		rear = (rear + 1) % max_memory;
		return pos;
	}
	else
	{
	/// not in queue
		rear = (rear + 1) % max_memory;
	return pos;
	}
}
int main(int argc,char** argv)
{
	unsigned int i;
	unsigned int max_memory;
	unsigned int num_of_page;
	unsigned int success = 0;
	unsigned int failed = 0;
	FILE *fp;
//	if (2 != argc)
//		printf("\nTips: a.exe data.txt");
	fp = fopen("case2.txt", "rt");
	fscanf(fp, "%u", &num_of_page);
	fscanf(fp, "%u", &max_memory);
	////////////////////////////
	unsigned int page[num_of_page];
	////////////////////////////
	unsigned int mem[max_memory];
	printf("\n num of page : %u\n limit of memory : %u", num_of_page, max_memory);
	for (i = 0; i < num_of_page; i++)
	{
		fscanf(fp, "%u",&page[i]);
	}
	for (i = 0; i < max_memory; i++)
	{
		mem[i] = -1;
	}
	for (i = 0; i < num_of_page; i++)
	{
		int j;
		int flag = 0;
		for(j = 0;j < max_memory; j++)
		{
			/// if data in mem
			if(page[i] == mem[j])
			{
				flag = 1;
				break;
			}
		}
		/// if data in mem
		if(flag)
		{
			success++;
			swappage3(0,page,mem,i,j,max_memory,num_of_page);
			continue;
		}
		/// if data out mem
		/// still test
		int pos = swappage3(1,page,mem,i,j,max_memory,num_of_page);
		mem[pos] = page[i];
		failed++;
		continue;
	}
	/// compute failed rate
	printf("\n---%u/%u", failed, failed + success);
	return 0;
}
