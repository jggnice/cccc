#include <stdlib.h>
#include <time.h>
#include <conio.h>
/************************************************************************/
/*          地图状态约定                                                */
/*          0  : 周围9个格子都没有雷                                    */
/*          1~8: 周围9个格子有1~8个雷                                   */
/*          -1 : 有雷的格子                                             */
/*          -2 : 被翻开的有雷的格子                                     */
/*          -3 : 地图边界                                               */
/************************************************************************/
int Map[12][12]={0};    /* 当前在玩的雷图 */ 
int MapShow[12][12]={0};  /* 当前用户选择过的地方，即“已翻开”的格子 */
int nSpaceLeft = 100;    /* 剩余的空白数，如果为0，则任务成功！ */
int lastX,lastY;            /* 失败时，记录挖到雷的位置 */

int AllMaps[5][12][12]={0}; /* 供用户选择的五张雷图 */
/* 显示雷区（每次用户操作之后都要重新显示） */
void DrawMap();
/* 初始化雷区 */ 
void InitMap();
/* 游戏开始时，加载用户选择的一幅雷图 */
void LoadMap(int index);
/* 玩扫雷游戏 */
int Play();
/* 绘制主菜单 */
void DrawMainMenu();
/* 显示结果 */
void ShowResult(int result);
/* 主函数 */
int main(int argc, char* argv[])
{
 char ch;
 int result;
 srand(time(NULL)); /* 按当前时间初始化随机数，这样每次启动的时候，雷的位置的不一样 */
 InitMap();     /* 初始化5张雷图，供用户选择 */
 while(1) /* 用while循环，保证只有在用户选择退出时，才退出游戏 */
 {
  DrawMainMenu();  /* 绘制主菜单 */
  flushall();    /* 清空所有输入输出缓冲区，主要是清空输入缓冲区，防止前面的输入对getch()的干扰 */
  ch = getch();   /* 读取输入 */
  switch(ch)
  {
  case '1':     /* 用户选择1 */
   printf("\n\t请输入雷图编号(1-5):");
   while (1) /* 循环输入，如果输入错误就一直要求输入 */
   {
    flushall();
    ch = getch(); /* 读取用户输入的雷图编号 */
    if (ch >= '1' && ch <= '5') /* 只有在1-5之间有效 */
    {
     LoadMap(ch-'1'); /* ch -'1'，将用户输入转换为雷图下标（下标从0开始，所以是-'1'）*/
     break;  /* 如果输入正确，就退出循环输入 */
    }
    else
    {
     /* 输入错误，则提示重新输入 */
     printf("\n\t输入无效！请重新输入雷图编号(1-5):");
     flushall();
    }
   }
   result = Play();  /* 开始玩扫雷游戏 */
   ShowResult(result); /* 显示游戏结果 */
   break;
  case '2':  /* 用户选择2 */
   exit(0);  /* 直接退出 */
   break;
  default:  /* 无效输入 */
   /* 不做任何操作，重新显示主菜单 */
   break;
  }
 }
 return 0;
}
void LoadMap(int index)
{
 int i,j;
 nSpaceLeft = 90;
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
  {
   Map[i][j] = AllMaps[index][i][j]; /* 将5张雷图中的下标为index的那一张载入到Map数组 */
   MapShow[i][j] = 0;        /* 重新开始游戏，所以所有格子都是“未翻开”状态 */
  }
}
void InitMap()
{
 int i,j,k;
 int m,n;
 /* 要初始化5张地图 */
 for(k=0;k<5;k++)
 {
  /* 初始化地图的边界 */
  for(i=0;i<12;i++)
  {
   /* 下标为0和11的位置都是“边界”，这些位置不属于雷区，仅在程序内部使用 */
   AllMaps[k][0][i] = -3; 
   AllMaps[k][11][i] = -3;
   AllMaps[k][i][0] = -3;
   AllMaps[k][i][11] = -3;
  }
  /* 先初始化10个雷的位置 */
  for(i=0;i<10;i++)
  {
   m = rand()%10 + 1; /* 随机选一个X坐标 */
   n = rand()%10 + 1; /* 随机选一个Y坐标 */
   if(AllMaps[k][m][n] == 0) /* 如果随机产生的位置之前没有被安排放置雷 */
   {
    AllMaps[k][m][n] = -1; /* 放置一个雷 */
   }
   else /* 随机产生的位置在之前已经放置了雷了 */
   {
    i--; /* 这个位置无效，重新产生一个 */
   }
  }
  /* 计算每个格子周围雷的个数 */
  for(i=1; i<11; i++)
   for(j=1; j<11;j++)
   {
    if(AllMaps[k][i][j] != -1)
    {
     AllMaps[k][i][j] = 0;
     /* 周围的8个位置，有一个雷就加一 */
     /************************************************************************/
     /*   坐标[i][j]周围的8个坐标位置：                                      */
     /*           [i-1][j-1]   [i-1][j]  [i-1][j+1]                          */
     /*             [i][j-1]     [i][j]    [i][j+1]                          */
     /*           [i+1][j-1]   [i+1][j]  [i+1][j+1]                          */
     /************************************************************************/
     if(AllMaps[k][i-1][j-1] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i-1][j] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i-1][j+1] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i][j-1] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i][j+1] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i+1][j-1] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i+1][j] == -1)
      AllMaps[k][i][j]++;
     if(AllMaps[k][i+1][j+1] == -1)
      AllMaps[k][i][j]++;
    }
   }
 }
}
void DrawMap()
{
 int i,j;
 system("cls");  /* 清屏 */
 /* 绘制坐标和边框 */
 printf("\n\n\n");
 printf("\t Y ");
 for(i=1; i<11; i++) printf("%-02d",i-1);
 printf("\n\tX |###################|\n");
 /* 每一行按规则绘制雷区 */
 for(i=1; i<11; i++)
 {
  printf("\t%-02d|",i-1); /* 显示X坐标 */
  for(j=1; j<11; j++)
  {
   if(MapShow[i][j])   /* 如果该位置被用户“挖开”了，就照实显示 */
   {
    if (Map[i][j] >= 0)  /* 非雷，显示周围雷的个数 */
    {
     printf("%d|",Map[i][j]);
    }
    /*else if(Map[i][j] == 0)
    {
     printf("0|");
    }*/
    else if (Map[i][j] == -1)  /* 雷，显示* */
    {
     printf("*|");
    }
    else if (Map[i][j] == -2)  /* 用户挖到的雷，显示@ */
    {
     printf("@|");
    }
    else /* 其他情况（目前不会出现，方便以后扩展） */
    {
     printf(" |");
    }
   }
   else /* 如果该位置没有被用户“挖开”，则显示空格 */
   {
    printf(" |");
   }
  }
  printf("\n");
 }
 printf("\t  |###################|\n");
}
void DrawMainMenu()
{
 system("cls");
 printf("\n\n\n\n\n\n");
 printf("\t|###################|\n");
 printf("\t|      请选择！     |\n");
 printf("\t|    1. 开始扫雷    |\n");
 printf("\t|    2. 退出        |\n");
 printf("\t|###################|\n");
}
int Play()
{
 char chX,chY; /* 用户输入 */
 int X,Y; /* 用户输入转换为整数下标 */
 int i,j;
 while (1)
 {
  DrawMap();  /* 重新绘制雷区图 */
  /* 输入X坐标 */
  printf("\n\t请输入X:");
  flushall();
  while(1)
  {
   chX = getch();
   if (chX >= '0' && chX <= '9')
   {
    X = chX - '0' + 1;
    break;
   }
   else
   {
    printf("\n\t输入无效！请重新输入X:");
    flushall();
   }
  }
  /* 输入Y坐标 */
  printf("\n\t请输入Y:");
  flushall();
  while(1)
  {
   chY = getch();
   if (chY >= '0' && chY <= '9')
   {
    Y = chY - '0' + 1;
    break;
   }
   else
   {
    printf("\n\t输入无效！请重新输入Y:");
    flushall();
   }
  }
  if(MapShow[X][Y] == 0) /* 输入的是未翻开的位置 */
  {
   MapShow[X][Y] = 1;   /* 将该位置标记为“已翻开” */
   if(Map[X][Y] == -1)  /* 如果挖到的是雷 */
   {
    Map[X][Y] = -2;   /* 标记为-2，表示这是被用户挖到的雷 */
    for(i=1;i<11;i++)
     for(j=1;j<11;j++)
      MapShow[i][j]=1; /* 游戏结束，自动将所有位置“翻开” */
    /* 记录用户挖到雷的位置坐标 */
    lastX = X-1;
    lastY = Y-1;
    return 0; /* 游戏失败！ */
   }
   else  /* 如果挖到的不是雷 */
   {
    nSpaceLeft--;  /* 剩余空白数减一 */
    if(nSpaceLeft==0)  /* 剩余空白数为0，则表示游戏成功 */
    {
     return 1; /* 游戏胜利！ */
    }
   }
  }
  else /* 输入的是已翻开的位置 */
  {
   printf("\n\t你输入的位置是[%d,%d]\n\t这个位置已经翻开！请重新输入！\n\t按任意键继续...\n",X-1,Y-1);
   flushall();
   getch();
  }
 }
}
void ShowResult( int result )
{
 DrawMap();
 if(result == 1) /* 游戏成功 */
 {
  printf("\n\t恭喜！您完成的扫雷任务！\n\t按任意键继续...");
  flushall();
  getch();
 }
 else /* 游戏失败 */
 {
  printf("\n\t哈哈！您在位置[%d,%d]挖到雷了，任务失败！\n\t按任意键继续...",lastX, lastY);
  flushall();
  getch();
 }
}
