#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct anode {
	char *name;
	struct anode *r, *l;
} node;



contains(tree, q) 
node **tree;
char *q;
{
	if(!(*tree)){
		printf("no node\n");
		return;
	}

	if (strcmp((*tree)->name, q) == 0){
		printf("yes\n");
		return(&*tree);
	}
	contains(&(*tree)->l, q);
	contains(&(*tree)->r, q);
}


delete(tree, q)
node **tree;
node *tmp;
char *q;
{
	printf("deleting\n");
	
	contains()
}


insert(tree, item) 
node **tree;
node *item;
{
	if(!(*tree)) {
		*tree = item;
		return;
	}

	if(strcmp(item->name, (*tree)->name) < 0)
		insert(&(*tree)->l, item);

	else 
		if(strcmp(item->name, (*tree)->name) > 0)
			insert(&(*tree)->r, item);
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

	while (gets(buf)) {
		b = &(buf[2]);
		if (buf[0] == 'i') {
			curr = (node *)malloc(sizeof(node));
			curr->l = curr->r = NULL;
			curr->name = strdup(b);
			printf("insert: %s\n", b);
			insert(&root, curr);
		}
		if (buf[0] == 'd') {
			printf("comparing...\n");
			contains(&root,b);
			delete(&root,b);
		}


		printf("tree is now:\n");
		printTree(root,0);
		printf("\n\n");
	}

	/*contains(&root, argv[1]);*/
}
