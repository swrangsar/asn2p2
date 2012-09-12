#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "twoThreeTree.h"

void printTwoThreeTreeLevelOrder(twoThreeTree* tree)
{
	if (tree && tree->root) {
		printTwoThreeNodeLevelOrder(tree->root);
	}
}

void printTwoThreeNodeLevelOrder(twoThreeNode* node)
{
	queue* nodeQueue = createQueue();
	if (!node) {
		perror("The node to be printed doesn't exist.\n");
		exit(1);
	}
	enqueue(nodeQueue, node);
	int count = 0, power2 = 2, level = 0;
	while (nodeQueue->tail) {
		twoThreeNode* temp = dequeue(nodeQueue);
		printTwoThreeNode(temp);
		if (temp->left && !temp->linkType) enqueue(nodeQueue, temp->left);
		if (temp->middle && !temp->linkType) enqueue(nodeQueue, temp->middle);
		if (temp->right && !temp->linkType) enqueue(nodeQueue, temp->right);
		if (count == power2) {
			printf("\n*** Level %d ***\n", level++);
			count = 0; power2 *= 2;
		}
		count++;
	}
}

void printTwoThreeNode(twoThreeNode* node)
{
	int a, b;
	a = b = -1;
	if (node->small) a = node->small->value;
	if (node->large) b = node->large->value;
	printf("small: %d large: %d\n", a, b);
}
