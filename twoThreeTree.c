#include <stdio.h>
#include <stdlib.h>
#include "twoThreeTree.h"

twoThreeNode* createTwoThreeNode(int leaf)
{
	twoThreeNode* new = malloc(sizeof(twoThreeNode));
	new->small = new->large = NULL;
	new->left = new->middle = new->right = new->parent = NULL;
	new->leaf = leaf;
	new->minimum = NULL;
	return new;
}

twoThreeTree* createTwoThreeTree()
{
	twoThreeTree* new = malloc(sizeof(twoThreeTree));
	new->root = NULL;
	return new;
}

void insertAtNode(twoThreeNode* node, key* inputKey)
{
	if (!node) {
		perror("We cannot insert anything at a NULL node!\n");
		exit(1);
	}
	if (node->leaf) {
		/* hand over to some other function */
	}
	if (inputKey->value <  && node->large) {
		/* split the node */
	}
	
