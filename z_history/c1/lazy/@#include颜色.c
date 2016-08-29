/*2.设置DOS框背景颜色
调用system("color ab");
设置默认的控制台前景和背景颜色。
COLOR [attr]attr 指定控制台输出的颜色属性
颜色属性由两个十六进制数字指定 -- 第一个为背景，第二个则为前景。
每个数字可以为以下任何值之一:
0 = 黑色 8 = 灰色
1 = 蓝色 9 = 淡蓝色
2 = 绿色 A = 淡绿色
3 = 浅绿** = 淡浅绿色
4 = 红色 C = 淡红色
5 = 紫色 D = 淡紫色
6 = 黄色 E = 淡黄色
7 = 白色 F = 亮白色
如果没有给定任何参数，该命令会将颜色还原到 CMD.EXE 启动时的颜色

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
    BLACK_RED;     printf("      这是");
    BLACK_YELLOW;  printf("一个");
    BLACK_GREEN;   printf("名叫");
    BLACK_BLUE;    printf("color");
    BLACK_PURPLE;  printf(".h的"); 
    BLACK_WHITE;   printf("库函数\n");
    
    WHITE_BLUE;    printf("    它能简单的改变字体颜色以及背景颜色，\n");
    YELLOW_RED;    printf("像这样，在前面输入 BLACK_PURPLE; 就行， \n");
    GREEN_WHITE;   printf("意思是“黑色背景+紫色字体，如果颜色前面 \n");
    CYAN_BLUE;     printf("“D”那将变成暗色，否则默认为亮色，比如 \n");
    DYELLOW_RED;   printf("“暗黄背景+红色”就是 DYELLOW_RED。就这 \n");
    PURPLE_WHITE;  printf("么简单。                                \n");
    
    BLACK_WHITE;
    printf("    使用后记得主动还原，不还原后面的字还\n是延续之前的颜色\n\n");
    
    printf("背景与字体可使用的颜色有：\n"); 
    RED_BLACK;   printf("RED    ");DRED_BLACK;    printf("DRED   ");WHITE_BLACK; printf("WHITE  ");printf("\n");
    BLUE_BLACK;  printf("BLUE   ");DBLUE_BLACK;   printf("DBLUE  ");BLACK_WHITE; printf("BLACK  ");printf("\n");
    GREEN_BLACK; printf("GREEN  ");DGREEN_BLACK;  printf("DGREEN ");GRAY_BLACK;  printf("GRAY   \n");
    YELLOW_BLACK;printf("YELLOW ");DYELLOW_BLACK; printf("DYELLOW");printf("\n");
    PURPLE_BLACK;printf("PURPLE ");DPURPLE_BLACK; printf("DPURPLE");printf("\n");
    CYAN_BLACK;  printf("CYAN   ");DCYAN_BLACK;   printf("DCYAN  ");printf("\n");

    BLACK_RED; printf("黑白灰前面不准加D的。");\
    
    getchar(); 
}