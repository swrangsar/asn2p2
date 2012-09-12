#include <stdio.h>
#include <stdlib.h>
#include "twoThreeTree.h"

twoThreeNode* createTwoThreeNode(enum linkType)
{
	twoThreeNode* new = malloc(sizeof(twoThreeNode));
	new->small = new->large = new->minimum = NULL;
	if (linkType) {
		new->left->leaf = new->middle->leaf = new->right->leaf = NULL;
	} else {
		new->left->node = new->middle->node = new->right->node = NULL;
	}
	new->parent->node = NULL;
	new->linkType = linkType;

	return new;
}

twoThreeTree* createTwoThreeTree()
{
	twoThreeTree* new = malloc(sizeof(twoThreeTree));
	new->root = NULL;
	return new;
}

twoThreeLeaf* createTwoThreeLeaf()
{
	twoThreeLeaf* new = malloc(sizeof(twoThreeLeaf));
	new->small = new->large = NULL;
	new->parent = NULL;
	return new;
}

key* createKey(item* Item)
{
	if (Item) {
		key* new = malloc(sizeof(key));
		new->value = Item->value;
		return new;
	} else {
		perror("Trying to create key from null item!\n");
		exit(1);
	}
}

void insertAtNode(twoThreeNode* node, item* input)
{
	if (!node) {
		perror("We cannot insert anything at a NULL node!\n");
		exit(1);
	}
	/* if input's value already exist then we do not need to insert again */

	if (node->linkType) {
		/* node has leaf link */
		if (!node->left->leaf) {
			twoThreeLeaf* new = createTwoThreeLeaf();
			new->parent = node;
			node->left->leaf = new;
		}
		if (!node->minimum) {
			node->minimum = createKey(input);
		}					

		if (!node->large) {
			if (!node->small || input->value < node->small->value) {
				insertAtLeaf(node->left->leaf, input);
			} else {
				insertAtLeaf(node->middle->leaf, input);
			}
		} else {
			if (input->value < node->small->value) {
				insertAtLeaf(node->left->leaf, input);
			} else if (input->value > node->small->value && input->value < node->large->value) {
				insertAtLeaf(node->middle->leaf, input);
			} else {
				insertAtLeaf(node->right->leaf, input);
			}
		}
	} else {
		/* node has no leaf link */
		if (!node->large) {
			if (input->value < node->small->value) {
				insertAtNode(node->left->node, input);
			} else {
				insertAtNode(node->middle->node, input);
			}
		} else {
			if (input->value < node->small->value) {
				insertAtNode(node->left->node, input);
			} else if (input->value > node->small->value && input->value < node->large->value) {
				insertAtNode(node->middle->node, input);
			} else {
				insertAtNode(node->right->node, input);
			}
		}
	}
}

key* insertAtLeaf(twoThreeLeaf* leaf, item* input)
{
	key* new = NULL;
	if (!leaf->small) {
		leaf->small = input;
		new = createKey(leaf->small);
		return new;
	}
	if (!leaf->large) {
		if (input->value < leaf->small->value) {
			leaf->large = leaf->small;
			leaf->small = input;
		}
		new = createKey(leaf->small);
		return new;
	}
	if (input->value < leaf->small->value) {
		pushToParent(leaf->parent, leaf->large);
		leaf->large = leaf->small;
		leaf->small = input;
		new = createKey(leaf->small);
		return new;
	}
	if (input->value > leaf->small->value && input->value < leaf->large->value) {
		pushToParent(leaf->parent, leaf->large);
		leaf->large = input;
		new = createKey(leaf->small);
		return new;
	}
	if (input->value > leaf->large->value) {
		pushToParent(leaf->parent, input);
		new = createKey(leaf->small);
		return new;
	}
}
	
void pushToParent(twoThreeNode* node, key* Key)
{
	/*** for nodes with internal link ***/
	if (!node->linkType) {
		if (!node->large) {
			if (Key->value < node->small->value) {
				node->right = node->middle;
				node->large = node->small;
				twoThreeNode* new = createTwoThreeNode(INTERNAL);
				new->
				node->middle = node->left->right;
				node->small = 
			
	
