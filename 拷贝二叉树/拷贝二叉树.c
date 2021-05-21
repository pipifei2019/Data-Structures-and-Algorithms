#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c", root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);

}

BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryNode* lchild = CopyBinaryTree(root->lchild);
	BinaryNode* rchild = CopyBinaryTree(root->rchild);
	BinaryNode* newnode = (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch = root->ch;
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	return newnode;
}

void FreeSpaceBinaryTree(BinaryNode* root)
{
	if (root == NULL)
	{
		return;
	}
	FreeSpaceBinaryTree(root->lchild);
	FreeSpaceBinaryTree(root->rchild);
	free(root);
}

void CreateBinaryTree()
{
	BinaryNode node1 = { 'A',NULL,NULL };
	BinaryNode node2 = { 'B',NULL,NULL };
	BinaryNode node3 = { 'C',NULL,NULL };
	BinaryNode node4 = { 'D',NULL,NULL };
	BinaryNode node5 = { 'E',NULL,NULL };
	BinaryNode node6 = { 'F',NULL,NULL };
	BinaryNode node7 = { 'G',NULL,NULL };
	BinaryNode node8 = { 'H',NULL,NULL };

	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	BinaryNode* root = CopyBinaryTree(&node1);
	Recursion(root);
	//FreeSpaceBinaryTree(root);
}

int main()
{
	CreateBinaryTree();
	
	printf("\n");
	printf("hello world\n");
	return 0;
}