#include<stdio.h>
#include<stdlib.h>
#define GAP 5
typedef struct cnode
{
	unsigned int size;
	unsigned int begin;
	unsigned int finish;
	struct cnode * next;
} charnode;
unsigned int currenttime = 0;
charnode *ProcessList;
charnode *CycleFirstFit;
charnode *allocate(charnode *List, int runtime, int memsize)
{
	charnode *q, *p, *r, *last;
	p = List->next;
	if (NULL == p)
	{
		return NULL;
	}
	last = List;
	while (NULL != p)
	{
		if (p->size < memsize)
		{
			//	unsigned int a = 5,b = 6;
			//	printf("\n%d",a>b);
			//	printf("\n%d",a-b>0);
			last = p;
			p = p->next;
			continue;
		}
		else if (p->size - memsize <= GAP)
		{
			//////////////////////////////////
			/////////////////////////////////
			last->next = p->next;
			//////////////////////////////
			p->finish = currenttime + runtime;
			r = ProcessList->next;
			ProcessList->next = p;
			p->next = r;
			return p;
		}
		else
		{
			///////////////////////
			q = (charnode *) malloc(sizeof(charnode));
			q->begin = p->begin;
			q->size = memsize;
			q->finish = currenttime + runtime;
			///////////////////////
			r = ProcessList->next;
			ProcessList->next = q;
			q->next = r;
			///////////////////////
			p->begin = p->begin + memsize;
			p->size = p->size - memsize;
			return q;
		}
	}			//;
	return NULL;
}

void deallocate(charnode *List, charnode *node)
{
	//////////////////////////////////////////
	charnode *p = List->next, *q, *r, *last;
	if (NULL == p)
	{
		///////////////////////
		List->next = node;
		node->next = p;
		return;
	}
	last = List;
	while (NULL != p)
	{
		q = p->next;
		if (p->begin + p->size == node->begin)
		{
			if (NULL == q)
			{
				//////////   node insert after p    /////////////
				p->size += node->size;
				return;
			}
			if (node->begin + node->size == q->begin)
			{
				//////////   node insert after p    /////////////
				r = q->next;
				p->next = r;
				p->size += (node->size + q->size);
				return;
			}
			else
			{
				//////////   node insert after p    /////////////
				p->size += node->size;
				return;
			}
		}
		else if (p->begin < node->begin)
		{
			last = p;
			p = p->next;
			continue;
		}
		else
		{
			//////////   node insert before p    /////////////
			if (node->begin + node->size == p->begin)
			{
				last->next = node;
				node->next = q;
				node->size += p->size;
				return;
			}
			else
			{
				last->next = node;
				node->next = p;
				return;
			}
		}
	}			// node insert at the end of the list
	last->next = node;
	node->next = p;
	return;
}
int main(int argc, char** argv)
{
	unsigned int i;
	unsigned int num_of_wait;
	unsigned int max_memory;
	unsigned int num_of_line;
	FILE *fp;
	if (2 != argc)
		printf("\nTips: a.exe data.txt");
	fp = fopen(argv[1], "rt");
	fscanf(fp, "%u", &num_of_line);
	fscanf(fp, "%u", &max_memory);
	unsigned int cursor = 0;
	unsigned int triggercursor = 0;
	unsigned int trigger[num_of_line];
	unsigned int visited[num_of_line];
	unsigned int arraive[num_of_line];
	unsigned int runtime[num_of_line];
	unsigned int memsize[num_of_line];
	printf("\n line of data : %u\n limit of memory : %u", num_of_line, max_memory);
//	unsigned int a = 5,b = 6;
//	printf("\n%d",a>b);
//	printf("\n%d",a-b>0);
//	return 0;
	trigger[triggercursor] = 0;
	for (i = 0; i < num_of_line; i++)
	{
		fscanf(fp, "%u%u%u", &arraive[i], &runtime[i], &memsize[i]);
		visited[i] = 0;
		if (trigger[triggercursor] != arraive[i])
		{
			trigger[++triggercursor] = arraive[i];
		}
	}
	trigger[++triggercursor] = 100000;
	printf("\n_____wait for a minute ...");
	charnode *FreeList, *node;
	ProcessList = (charnode *) malloc(sizeof(charnode));
	ProcessList->next = NULL;
	FreeList = (charnode *) malloc(sizeof(charnode));
	FreeList->next = NULL;
	///////////////////////
	node = (charnode *) malloc(sizeof(charnode));
	node->begin = 0;
	node->size = max_memory;
	node->finish = 0;
	deallocate(FreeList, node);
	CycleFirstFit = FreeList;
	//////////////////////////

	while (1)
	{
		//////// Time Machine Real Trigger : when process arraived
		//////// Time Machine Trigger : when process finished
		num_of_wait = 0;
		for (i = 0; i < num_of_line && arraive[i] <= currenttime; i++)
		{
			if (!visited[i])
			{
				num_of_wait++;
			}
		}
		if (!num_of_wait)
		{
			if (num_of_line - 1 <= i)
			{
				charnode *p = ProcessList->next;
				int maxtime = 0;
				if (NULL == p)
				{
					printf("\n_____well done !_____");
					printf("\n the answer : %u", currenttime);
					return 0;
				}
				while (NULL != p)
				{
					if (maxtime < p->finish)
					{
						maxtime = p->finish;
					}
					p = p->next;
				}
				printf("\n_____well done !_____");
				printf("\n the answer : -> %u", maxtime);
				return 0;
			}
			else
			{
				currenttime = arraive[i + 1];
			}
		}
		//////////////////////////
		for (i = 0; i < num_of_line && arraive[i] <= currenttime; i++)
		{
			if (!visited[i])
			{
				if (NULL != allocate(FreeList, runtime[i], memsize[i]))
					visited[i] = 1;
			}
		}
		/////////////////////////
		charnode *p = ProcessList->next;
		charnode *last = ProcessList;
		charnode *r, *s;
		int mintime = 1000000;
		while (NULL != p)
		{
			if (mintime > p->finish)
			{
				mintime = p->finish;
				node = last;
			}
			{
				last = p;
				p = p->next;
			}
		}
		//////////////////////////////////////////
		if (NULL != ProcessList->next)
		{
			// |------------>
			// |   --->
			// |---------->
			r = node->next;
			s = r->next;
//			printf("\n%u", r->finish);
			if (trigger[cursor] < r->finish && currenttime <= trigger[cursor])
			{
				currenttime = trigger[cursor++];
				continue;
			}
			// confirm to recycle
			node->next = s;
			deallocate(FreeList, r);
			currenttime = r->finish;
			cursor = 0;
			while(trigger[cursor] < currenttime && cursor < triggercursor)
			{
				cursor++;
			}
		}
		///////////////////////////////////
	}
}
