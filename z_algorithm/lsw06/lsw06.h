#ifndef    LSW06_H
#define	LSW06_H

typedef struct alink
{
	int data;
	struct	alink * next;
	struct	alink * pre;
} link;
void link_print(link * temp,FILE *fp);
link* link_find(link *L,int data);
void link_move_R(link *L,int aa,int bb);
void link_move_L(link *L,int aa,int bb);
link * link_create(FILE *fp);
void link_move_file(link *L,FILE *fp, int cmd_length);

#endif	/* LSW06_H */