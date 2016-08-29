#ifndef    LSW07_H
#define	LSW07_H

typedef struct
{
	char char_type;
	int int_data;
	int left;
	int right;
}
vextnode;

typedef struct atree
{
	char char_type;
	int int_data;
	struct atree *left;
	struct atree *right;
}
mytree;

mytree* list_create(FILE *fp)
;
int tree_calculate(mytree *tree0)
;
#endif	/* LSW07_H */