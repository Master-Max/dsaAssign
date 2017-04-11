#include<stdlib.h>
#include<stdio.h>
#include <string.h>

typedef struct anode {
	char *name;
	struct anode *r, *l, *p;//TODO decide if i want to make a parent pointer in tree node
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
		printf("contains= %d\n", tree);
		return tree;
	}
	contains(&(*tree)->l, q);
	contains(&(*tree)->r, q);
}


delete(tree, q)
node **tree;
char *q;
{
	/*printf("comparing...\n");
	contains(&*tree,q);

	printf("deleting\n");*/

	node **tmp;
	//printf("made node tmp\n");

	tmp = contains(&*tree,q);

	printf("parent= %d\n", (*tmp)->p);
	//printf("tmp= %d\n", tmp);

/*	if(contains(*tree,q)){
		printf("&*tree\n");
	}*/
}


insert(tree, item, parent)
node **tree;
node *item;
node **parent;
{
	if(!(*tree)) {
		*tree = item;
		(*item).p = parent;//TODO Figure out parent nodes
		return;
	}
	if(strcmp(item->name, (*tree)->name) < 0)
		//tree.p = tree;
		insert(&(*tree)->l, item, tree);

	else
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
