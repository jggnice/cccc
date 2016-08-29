#include<stdio.h>
#include<stdlib.h>
int next = 0;
unsigned int swappage(unsigned int max_memory)
{
	int pos = next;
	next = (next + 1) % max_memory;
	return pos;
}
unsigned int swappage2(unsigned int start,unsigned int max_memory)
{
	int pos = -1;
	int i,j;
	int findflag = 0;
	for(i = 0; i < max_memory; i++)
	{
		for(j = 0;j < num_of_page; j++)
		{
			if(page[j] == mem[i])
				if(j > pos)
					pos = i;
			break;
		}
		/// if mem[i] end of page
		if(j > pos)
			pos = i;
	}
	return pos;
}
int main(int argc,char** argv)
{
	unsigned int i;
	unsigned int max_memory;
	unsigned int num_of_page;
	unsigned int success = 0;
	unsigned int failed = 0;
	FILE *fp;
	if (2 != argc)
		printf("\nTips: a.exe data.txt");
	fp = fopen(argv[1], "rt");
	fscanf(fp, "%u", &num_of_page);
	fscanf(fp, "%u", &max_memory);
	unsigned int page[num_of_page];
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
			continue;
		}
		/// if data out mem
		int pos = swappage(i,max_memory);
		mem[pos] = page[i];
		failed++;
		continue;
	}
	/// compute failed rate
	printf("\n---%u/%u", failed, failed + success);
	return 0;
}