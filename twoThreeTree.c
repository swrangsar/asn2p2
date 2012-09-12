#include <stdio.h>
#include <stdlib.h>
#include "twoThreeTree.h"

twoThreeNode* createTwoThreeNode(linkType LinkType)
{
	twoThreeNode* new = malloc(sizeof(twoThreeNode));
	new->small = new->large = new->minimum = NULL;
	if (LinkType) {
		new->left->node = new->middle->node = new->right->node = NULL;
	} else {
		new->left->leaf = new->middle->leaf = new->right->leaf = NULL;
	}
	new->parent->node = NULL;
	new->LinkType = LinkType;

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
	
