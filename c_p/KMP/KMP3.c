#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define BASE -99

typedef struct {int length; char content[100]; }myString;

int next[100];


void BuildString(myString *str,char *string)
{
    int i=0;
    while(string[i++])
    {
     str->content[i]=string[i-1];
    }
    str->length=i-1;
}
int Index_KMP(myString* mainstr,myString* substr,int start_pos)
{
	//第0位不放.
	int i=start_pos;//从start_pos开始
	int j=1;//从substring第一位开始
	while(i<=mainstr->length&&j<=substr->length)
	{
		if(j==BASE)
		{
			i++; j=1;
		}
		else
		{
		
		if((mainstr->content[i])==substr->content[j])
		{i++; j++; }
		else
		j=next[j];//寻找指示
			
		}
		
	}
	
	
	
	if(j>(substr)->length)
	return i-(substr)->length;	//success
	else return -1;			//failed
}

void get_next_index(myString* substr,int* next)
{
	
	next[1]=BASE;//假定第一位匹配失败
	//为了不混淆,浪费第0位不放.
	//next[j]表示第j-1位成功
	//同时假定第i位匹配失败
	int i=1;//看做特别的主串
	int j=BASE;//看做真正的子串

	while(i<=(substr)->length)
	{//i<(substr)->length就够了,但此处有另外的用途cabca;i的偏移量为max{next[(substr)->length+1],(substr)->length}
		if(j==BASE)
		{
			++i;	//启程
			j=1;	//置1,从头开始
			next[i]=1;//获得指示,下次如果失陪,直接从头开始
		}
		
		
		else
		{
			if(substr->content[i]==substr->content[j])
			{
			++i;	//假定第j+1位失败//丢弃前一位
			++j;	//积累
			//表示第j位匹配成功
			
			next[i]=j;//获得指示
			
			//此时表示第j-1位成功	
			}
			else 
			{
			//表示第j位匹配失败;
			//next[j]表示第j-1位成功;
			j=next[j];//寻找指示
			}
		}
                			
	}
	
}

void print_index(myString *num)
{
    int i=0;
    
     printf("for index=[");
    for(i=1;i<=(*num).length;i++)
    {
        printf(" %3d",i);
    }   printf("]\n");
    
     printf("all char =[");
    for(i=1;i<=(*num).length;i++)
    {
        printf(" %3c",num->content[i]);
    }   printf("]\n");
    
    
    
    printf("all next =[");
    printf(" %3c",'$');
    for(i=2;i<=(*num).length+1;i++)
    {
        printf(" %3d",next[i]);
    }   printf("]\n");
}
int main()
{
    int last_index=1;
    int index_offset;
	myString *string1=(myString *)malloc(sizeof(myString));
	myString *string2=(myString *)malloc(sizeof(myString));	
	BuildString(string1,"bcabcabcabcabca");
        BuildString(string2,"cabca");
        printf("\nstr1->length=%d",(*string1).length);	
        printf("\nstr2->length=%d",(*string2).length);
    
    get_next_index(string2,next);
    index_offset=1-next[(string2)->length+1];printf("index_offset=%d",index_offset);
        while((last_index!=-1)&&(last_index<=string1->length))
        {
            last_index=Index_KMP(string1,string2,last_index);
            if(last_index!=-1)
            {
                printf("\nindex=%d\n",last_index);
                last_index=last_index+string2->length+index_offset;
                system("pause");system("cls");
            }
            
        }
        //printf("\nindex=%d\n",last_index);
        print_index(string2);
        return 0;
}