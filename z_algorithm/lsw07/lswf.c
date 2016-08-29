#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"lsw07.h"


mytree* list_create(FILE *fp)
{

	int i;
	int table_length;
	int index0,index1,index2;
	char str[]="hkh";
	fscanf(fp,"%d", &table_length);
	vextnode vext_tree[table_length];
	//printf("table_length=%d",table_length);
	//**************setVextTree********************
	for(i=0; i<table_length; i++)
	{
		fscanf(fp, "%d", &index0);	//useless
		
		fscanf(fp, "%s", str);
		if(str[0] == 'n')
		{
			fscanf(fp, "%d", &(vext_tree[i].int_data));
			vext_tree[i].left = -1;
			vext_tree[i].right = -1;
		}
		else
		{
			fscanf(fp, "%d", &index1);
			fscanf(fp, "%d", &index2);
			vext_tree[i].left = index1;
			vext_tree[i].right = index2;
			vext_tree[i].int_data = 0;
		}
		vext_tree[i].char_type = str[0];
		//printf("\ntable=%c %d %d %d", vext_tree[i].char_type, vext_tree[i].int_data, vext_tree[i].left, vext_tree[i].right);

	}
	
	//***********VextTreeFinished***********
	//printf("\n**************setTree******************\n");
	//**************setTree******************
	
	mytree *	treenode[table_length];	
	mytree *newnode;
	
	for(i=0; i<table_length; i++)
	{
		newnode = (mytree *)malloc(sizeof(mytree));		
		newnode->char_type = vext_tree[i].char_type;
		newnode->int_data = vext_tree[i].int_data;
		
		treenode[i] = newnode;
	}
	for(i=0; i<table_length; i++)
	{
		if(treenode[i]->char_type == 'n')
		{
			treenode[i]->left = NULL;
			treenode[i]->right = NULL;
		}
		else
		{
			treenode[i]->left = treenode[vext_tree[i].left];
			treenode[i]->right = treenode[vext_tree[i].right];
		}
		//printf("\ntable=%c %d", treenode[i]->char_type, treenode[i]->int_data);

	}
	return treenode[0];
}

int tree_calculate(mytree *tree0)
{
	//static int iii = 0;
	switch (tree0->char_type)
	{
	case '+':
		return tree_calculate(tree0->left)  +  tree_calculate(tree0->right);break;
	case '-' :
		return tree_calculate(tree0->left)  -  tree_calculate(tree0->right);break;
	case 'n' :
		return tree0->int_data;break;
	default :
		printf("\nwrong at tree0->char_type = ((%c))", tree0->char_type);return -2222;
		//iii++; 
	}
}