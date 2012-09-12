#ifndef _twoThreeTree_h
#define _twoThreeTree_h

typedef struct key {
	int value;
} key;

typedef struct item {
	int value;
	void* data;
} item;

typedef enum linkType {
	LEAF,
	INTERNAL
} linkType;

struct twoThreeNode;
typedef union twoThreeLink {
	struct twoThreeNode* node;
	item* leaf;
} twoThreeLink;

typedef struct twoThreeNode {
	key *small, *large, *minimum;
	twoThreeLink *left, *middle, *right, *parent;
	linkType LinkType;
} twoThreeNode;

typedef struct twoThreeTree {
	twoThreeNode* root;
} twoThreeTree;

twoThreeNode* createTwoThreeNode(linkType LinkType);
twoThreeTree* createTwoThreeTree();

#endif
