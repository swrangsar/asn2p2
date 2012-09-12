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


