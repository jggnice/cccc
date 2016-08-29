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
	//��0λ����.
	int i=start_pos;//��start_pos��ʼ
	int j=1;//��substring��һλ��ʼ
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
		j=next[j];//Ѱ��ָʾ
			
		}
		
	}
	
	
	
	if(j>(substr)->length)
	return i-(substr)->length;	//success
	else return -1;			//failed
}

void get_next_index(myString* substr,int* next)
{
	
	next[1]=BASE;//�ٶ���һλƥ��ʧ��
	//Ϊ�˲�����,�˷ѵ�0λ����.
	//next[j]��ʾ��j-1λ�ɹ�
	//ͬʱ�ٶ���iλƥ��ʧ��
	int i=1;//�����ر������
	int j=BASE;//�����������Ӵ�

	while(i<=(substr)->length)
	{//i<(substr)->length�͹���,���˴����������;cabca;i��ƫ����Ϊmax{next[(substr)->length+1],(substr)->length}
		if(j==BASE)
		{
			++i;	//����
			j=1;	//��1,��ͷ��ʼ
			next[i]=1;//���ָʾ,�´����ʧ��,ֱ�Ӵ�ͷ��ʼ
		}
		
		
		else
		{
			if(substr->content[i]==substr->content[j])
			{
			++i;	//�ٶ���j+1λʧ��//����ǰһλ
			++j;	//����
			//��ʾ��jλƥ��ɹ�
			
			next[i]=j;//���ָʾ
			
			//��ʱ��ʾ��j-1λ�ɹ�	
			}
			else 
			{
			//��ʾ��jλƥ��ʧ��;
			//next[j]��ʾ��j-1λ�ɹ�;
			j=next[j];//Ѱ��ָʾ
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