/*2.����DOS�򱳾���ɫ
����system("color ab");
����Ĭ�ϵĿ���̨ǰ���ͱ�����ɫ��
COLOR [attr]attr ָ������̨�������ɫ����
��ɫ����������ʮ����������ָ�� -- ��һ��Ϊ�������ڶ�����Ϊǰ����
ÿ�����ֿ���Ϊ�����κ�ֵ֮һ:
0 = ��ɫ 8 = ��ɫ
1 = ��ɫ 9 = ����ɫ
2 = ��ɫ A = ����ɫ
3 = ǳ��** = ��ǳ��ɫ
4 = ��ɫ C = ����ɫ
5 = ��ɫ D = ����ɫ
6 = ��ɫ E = ����ɫ
7 = ��ɫ F = ����ɫ
���û�и����κβ�����������Ὣ��ɫ��ԭ�� CMD.EXE ����ʱ����ɫ

#include <stdio.h>
int main(){ 
system("color 64"); 
printf("hello color :)\n"); 
return 0;
}*/

#include <stdio.h>
#include "color.h"
int main()
{
    BLACK_RED;     printf("      ����");
    BLACK_YELLOW;  printf("һ��");
    BLACK_GREEN;   printf("����");
    BLACK_BLUE;    printf("color");
    BLACK_PURPLE;  printf(".h��"); 
    BLACK_WHITE;   printf("�⺯��\n");
    
    WHITE_BLUE;    printf("    ���ܼ򵥵ĸı�������ɫ�Լ�������ɫ��\n");
    YELLOW_RED;    printf("����������ǰ������ BLACK_PURPLE; ���У� \n");
    GREEN_WHITE;   printf("��˼�ǡ���ɫ����+��ɫ���壬�����ɫǰ�� \n");
    CYAN_BLUE;     printf("��D���ǽ���ɰ�ɫ������Ĭ��Ϊ��ɫ������ \n");
    DYELLOW_RED;   printf("�����Ʊ���+��ɫ������ DYELLOW_RED������ \n");
    PURPLE_WHITE;  printf("ô�򵥡�                                \n");
    
    BLACK_WHITE;
    printf("    ʹ�ú�ǵ�������ԭ������ԭ������ֻ�\n������֮ǰ����ɫ\n\n");
    
    printf("�����������ʹ�õ���ɫ�У�\n"); 
    RED_BLACK;   printf("RED    ");DRED_BLACK;    printf("DRED   ");WHITE_BLACK; printf("WHITE  ");printf("\n");
    BLUE_BLACK;  printf("BLUE   ");DBLUE_BLACK;   printf("DBLUE  ");BLACK_WHITE; printf("BLACK  ");printf("\n");
    GREEN_BLACK; printf("GREEN  ");DGREEN_BLACK;  printf("DGREEN ");GRAY_BLACK;  printf("GRAY   \n");
    YELLOW_BLACK;printf("YELLOW ");DYELLOW_BLACK; printf("DYELLOW");printf("\n");
    PURPLE_BLACK;printf("PURPLE ");DPURPLE_BLACK; printf("DPURPLE");printf("\n");
    CYAN_BLACK;  printf("CYAN   ");DCYAN_BLACK;   printf("DCYAN  ");printf("\n");

    BLACK_RED; printf("�ڰ׻�ǰ�治׼��D�ġ�");\
    
    getchar(); 
}