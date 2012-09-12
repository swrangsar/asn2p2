#ifndef _twoThreeTree_h
#define _twoThreeTree_h

typedef struct key key;
typedef struct item item;
typedef struct twoThreeNode twoThreeNode;
typedef struct twoThreeLeaf twoThreeLeaf;
typedef struct twoThreeTree twoThreeTree;
typedef union twoThreeLink twoThreeLink;

struct key {
	int value;
}

struct item {
	int value;
	void* data;
}

union twoThreeLink {
	twoThreeNode* node;
	twoThreeLeaf* leaf;
}

struct twoThreeNode {
	key *small, *large, *minimum;
	twoThreeLink *left, *middle, *right;
	twoThreeNode *parent;
	enum { INTERNAL, LEAF } linkType;
}

struct twoThreeLeaf {
	item *small, *large;
	twoThreeNode *parent;
}

struct twoThreeTree {
	twoThreeNode* root;
}

twoThreeNode* createTwoThreeNode(enum linkType);
twoThreeTree* createTwoThreeTree();
twoThreeLeaf* createTwoThreeLeaf();
key* createKey(item* Item);

#endif
