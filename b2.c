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
	*t = NULL;
	//node **t = NULL;
	//t = (node *)malloc(sizeof(node));
	if(!(*tree)){
		//printf("no node\n");
		return;
	}

	if (strcmp((*tree)->name, q) == 0){
		printf("yes\n");
		//printf("contains= %x\n", tree);
		//printf("name= %s\n", (*tree)->name);
		*t = tree;
		return;
	}
	contains(&(*tree)->l, q);
	contains(&(*tree)->r, q);
	//return t;
}

examine(tree, q)
node **tree;
char *q;
{
	node **tmp;
	contains(&(*tree),q);
	tmp = *t;
	if(tmp){
		printf("M\n name: %s\n addr: %x\n",(*tmp)->name,tmp);
		if(((*tmp)->p)){
			printf("P\n name: %s\n addr: %x\n",((*tmp)->p)->name,(*tmp)->p);
		}
		if(((*tmp)->l)){
			printf("L\n name: %s\n addr: %x\n",((*tmp)->l)->name,(*tmp)->l);
		}
		if(((*tmp)->r)){
			printf("R\n name: %s\n addr: %x\n",((*tmp)->r)->name,(*tmp)->r);
		}
	}
}


delete(tree, q)
node **tree;
char *q;
{
	node **tmp;
	node **dad;
	node **dub;
	node **mom;

	contains(&(*tree),q);
	tmp = *t;
	dad = *(&(*tmp)->p);	//To reference pointer in pointer - *(&(*pntr)->o)
	//printf("out of contains\n");

	if(tmp){//Checks what the tmp and parent are
		printf("tmp.name: %s\n", (*tmp)->name);
		//printf("p1= %x\n", ((*tmp)->p));
		//printf("p2= %x\n", dad);
		printf("p.name= %s\n", (*dad)->name);
	}

	if((!((*tmp)->l))&&(!((*tmp)->r))){//No LEFT, No RIGHT: Case 1
		printf("L:N | R:N\n");
		(*tmp = NULL);
	}
	else if(((*tmp)->l)&&(!((*tmp)->r))){//Yes LEFT, No RIGHT: Case 2
		printf("L:Y | R:N\n");
		printf("dad.l: %s\ndad.r: %s\n", (((*dad)->l)->name),(((*dad)->r)->name));
		printf("dad.name: %s\ntmp.name: %s\n", ((*dad)->name),((*tmp)->name));
		if(strcmp(((*tmp)->name), ((*dad)->name)) < 0){
			printf("replacing dad.l\n");
			(*dad)->l = (*tmp)->l;
		}
		if(strcmp(((*tmp)->name), ((*dad)->name)) > 0){
			printf("replacing dad.r\n");
			(*dad)->r = (*tmp)->l;
		}
	}
	else if((!((*tmp)->l))&&((*tmp)->r)){//No LEFT, Yes RIGHT: Case 3
		printf("L:N | R:Y\n");
		printf("dad.l:%s\ndad.r:%s\n", (((*dad)->l)->name),(((*dad)->r)->name));
		printf("dad.name: %s\ntmp.name: %s\n", ((*dad)->name),((*tmp)->name));
		if(strcmp(((*tmp)->name), ((*dad)->name)) < 0){//Left
			printf("replacing dad.l\n");
			(*dad)->l = (*tmp)->r;
		}
		if(strcmp(((*tmp)->name), ((*dad)->name)) > 0){//Right
			printf("replacing dad.r\n");
			(*dad)->r = (*tmp)->r;
		}
	}
	else if(((*tmp)->l)&&((*tmp)->r)){//Yes LEFT, Yes RIGHT: Case 4
		printf("L:Y | R:Y\n");
		findKid(&(*tmp),0);
		dub = *t;
		mom = *(&(*dub)->p);
		printf("\nmom: %s\ndub: %s\n", (*mom)->name, (*dub)->name);
		if(strcmp(((*mom)->name), ((*tmp)->name)) == 0){
			printf("mom name\n");
			(*dub)->r = (*tmp)->r;
			if(strcmp(((*tmp)->name), ((*dad)->name)) < 0){//Left
				printf("replacing dad.l\n");
				(*dad)->l = (*dub);
			}
			else if(strcmp(((*tmp)->name), ((*dad)->name)) > 0){//Right
				printf("replacing dad.r\n");
				(*dad)->r = (*dub);
			}
		}
		else{
			if((*dub)->l)
				(*mom)->r = (*dub)->l;

			if(strcmp(((*tmp)->name), ((*dad)->name)) < 0){//Left
				printf("replacing dad.l\n");
				(*dad)->l = (*dub);
			}
			else if(strcmp(((*tmp)->name), ((*dad)->name)) > 0){//Right
				printf("replacing dad.r\n");
				(*dad)->r = (*dub);
			}
			(*dub)->r = (*tmp)->r;
			(*dub)->l = (*tmp)->l;
		}
	}
	/*
	else if(((*tmp)->l)&&((*tmp)->r)){//Yes LEFT, Yes RIGHT: Case 4
		printf("L:Y | R:Y\n");
		printf("tmp.name: %s\n", ((*tmp)->name));

		findKid(&(*tmp),0);

		dub = *t;
		mom = *(&(*dub)->p);

		printf("\nmom: %s\ndub: %s\n", (*mom)->name, (*dub)->name);

		if((*dub)->name != (*tmp->l))
			(*dub)->l = (*tmp)->l;
		if((*dub)->name != (*tmp->r))
			(*dub)->r = (*tmp)->r;

		if(strcmp(((*tmp)->name), ((*dad)->name)) < 0){//L
				(*dad)->l = (*dub);
			}
			else if(strcmp(((*tmp)->name), ((*dad)->name)) > 0){//R
				(*dad)->r = (*dub);
			}

			(*mom)->l = 0;
		}
		else if(strcmp(((*dub)->name), ((*mom)->name)) > 0){//R
			if(strcmp(((*tmp)->name), ((*dad)->name)) < 0){//L
				(*dad)->l = (*dub);
			}
			else if(strcmp(((*tmp)->name), ((*dad)->name)) > 0){//R
				(*dad)->r = (*dub);
			}

			(*mom)->r = 0;
		}
		*/
	printf("out of ifs\n");
}

findKid(tree, n)
node **tree;
int n;
{
	if(*tree){
		printf("Finding Kid...\nN: %s\n", (*tree)->name);
		*t = tree;
		if(((*tree)->l)&&(n==0)){//One Left then Right
			findKid(&(*tree)->l, 1);
		}
		else if(((*tree)->r)&&(n==0)){//One Right then Left
			findKid(&(*tree)->r, 2);
		}
		if(n==1){//Keep Right
			findKid(&(*tree)->r, 1);
		}
		if(n==2){//Keep Left
			findKid(&(*tree)->l, 2);
		}
	}
	printf("Found Kid\n");
}

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
			delete(&root,b);
		}
		if (buf[0] == 'e'){
			examine(&root,b);
		}


		printf("tree is now:\n");
		printTree(root,0);
		printf("\n\n");
	}

	/*contains(&root, argv[1]);*/
}
