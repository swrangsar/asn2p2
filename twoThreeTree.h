#ifndef _twoThreeTree_h
#define _twoThreeTree_h

typedef struct key {
	int value;
} key;

typedef struct twoThreeNode {
	key* small;
	key* large;
	struct twoThreeNode* left;
	struct twoThreeNode* middle;
	struct twoThreeNode* right;
	struct twoThreeNode* parent;
	int leaf;
	key* minimum;
} twoThreeNode;

typedef struct twoThreeTree {
	twoThreeNode* root;
} twoThreeTree;

twoThreeNode* createTwoThreeNode(int leaf);
twoThreeTree* createTwoThreeTree();

#endif
