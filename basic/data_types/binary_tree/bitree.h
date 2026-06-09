#ifndef BITREE_H
#define BITREE_H


struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* parent; 
};

typedef struct TreeNode Tnode;

extern int tree_size;
int Get_Node_Quantity();

Tnode* CreateHead(int value);
void FreeList(Tnode** Head);
Tnode* PushBack(Tnode* startPos, int value);
int check(Tnode* now); // 0: ALL NULL ; -1 LEFT-TRUE,RIGHT-NULL ; 1 LEFT-NULL,RIGHT-TRUE

/*void Swap(Tnode* node1, Tnode* node2); // swap only data
Tnode* Find(Tnode* start, int value);
int Compare(Tnode* node1, Tnode* node2);
void SortList(Tnode* head);
*/

#endif