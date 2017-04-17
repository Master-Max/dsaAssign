#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct anode {
	char *name;
	struct anode *r, *l, *p;//TODO decide if i want to make a parent pointer in tree node
} node;

node**t = NULL;

contains(tree, q)
node **tree;
char *q;
{
	//node **t = NULL;
	//t = (node *)malloc(sizeof(node));
	if(!(*tree)){
		printf("no node\n");
		return;
	}

	if (strcmp((*tree)->name, q) == 0){
		printf("yes\n");
		printf("contains= %x\n", tree);
		printf("name= %s\n", (*tree)->name);
		*t = tree;
		return;
	}
	contains(&(*tree)->l, q);
	contains(&(*tree)->r, q);
	//return t;
}

/*
find(tree, q)
node **tree;
*/



delete(tree, q)
node **tree;
char *q;
{
	/*printf("comparing...\n");
	contains(&*tree,q);

	printf("deleting\n");*/

	node **tmp;
	node **dad;
	//printf("made node tmp\n");

	contains(&(*tree),q);
	tmp = *t;
	dad = *(&(*tmp)->p);	//To reference pointer in pointer - *(&(*pntr)->o)

	printf("out of contains\n");
	
	if(tmp){	
		printf("tmp.name: %s\n", (*tmp)->name);

		printf("p1= %x\n", ((*tmp)->p));
		printf("p2= %x\n", dad);
		printf("p.name= %s\n", (*dad)->name);
		//printf("p.name: %s\n", *((*tmp)->p)->name);
	}
	
//	if((!(tmp->l))&&(!(tmp->r))){
//		rl(&(*tree), q, (*dad)->name);
//	}	
	/*
	if(!(*tmp)->l && (*tmp)-r){
		((*tmp)->p)->r = 
	}*/
}
/*
rl(tree, q, d)
node **tree;
char *q;
char *d;
{
	if(strcmp(d,(*tree)->name) = 0){
		if(strcmp(*(&(*tree)->r)->name, q) = 0)
			*(&(*tree)->r = 0;
		if(strcmp(*(&(*tree)->l)->name, q) = 0)
			*(&(*tree)->l = 0;
	}
	rl(&(*tree)->l, q, d);
	rl(&(*tree)->r, q, d);
}
*/

insert(tree, item, parent)
node **tree;
node *item;
node *parent;
{
	if(!(*tree)) {
		*tree = item;
		(*item).p = parent;//TODO Figure out parent nodes
		return;
	}
	if(strcmp(item->name, (*tree)->name) < 0)
		insert(&(*tree)->l, item, tree);

	if(strcmp(item->name, (*tree)->name) > 0)
		insert(&(*tree)->r, item, tree);
}



void printTree(tree, lvl)
node *tree;
int lvl;
{
	int i;

	if (! tree) return;
	for (i=0; i<lvl; i++) printf("\t"); printf("%s\n",tree->name);
	printTree(tree->l, lvl+1);
	printTree(tree->r, lvl+1);
}


/*
The loop below reads from stdin until EOF, then searches
to see if the BST contains the word found in argv[1].

Modify the loop to read a series of lines of one of two types:

i value
d value

Lines starting with the ASCII i are to be inserted into the binary search tree.
Those beginning with 'd' are to be deleted if they exist. If they do not exist,
output a line of text  saying so and do nothing else.

Stop your read loop at EOF (like it is now). Instead of
calling contains(), print out the tree; make it a preorder print */



void main(argc, argv, envp)
int argc;
char **argv, **envp;
{
	int i;
	char *b, buf[1024];
	node *curr, *root;

	root = 0;
	t = (node *)malloc(sizeof(node));

	while (gets(buf)) {
		b = &(buf[2]);
		if (buf[0] == 'i') {
			curr = (node *)malloc(sizeof(node));
			curr->l = curr->r = curr->p = NULL;
			curr->name = strdup(b);
			printf("insert: %s\n", b);
			insert(&root, curr, &root);
		}
		if (buf[0] == 'd') {
			//printf("comparing...\n");
			//contains(&root,b);
			delete(&root,b);
		}


		printf("tree is now:\n");
		printTree(root,0);
		printf("\n\n");
	}

	/*contains(&root, argv[1]);*/
}
