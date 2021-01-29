
#include <stdio.h>
#include <stdlib.h>

enum command {
	PRINT = 1,
	LEFT = 2,
	RIGHT = 3
};

typedef struct s_list {
	int num;
	struct s_list *left;
	struct s_list *right;
}list;

list *makeList(int Len);
void endList(list *listPtr);
int takeNum(list **listPtr, int targetNum);

int main(void)
{
	int listLen, targetNumCnt, targetNum, i, answer = 0;
	scanf("%d %d", &listLen, &targetNumCnt);
	list *listPtr = makeList(listLen);
	i = 0;
	while(i<targetNumCnt) {
		scanf("%d", &targetNum);
		answer += takeNum(&listPtr,targetNum);
		++i;
	}
	endList(listPtr);

	printf("%d\n", answer);

	return 0;
}

list *makeList(int Len)
{
	list *listSP = (list*)malloc(sizeof(list));
	listSP->num = 1;
	list *listPtr = listSP;
	
	int i = 2;
	while(i<=Len) {
		listPtr->right = (list*)malloc(sizeof(list));
		listPtr->right->left = listPtr;
		listPtr->right->num = i;
		listPtr = listPtr->right;
		++i;
	}
	listPtr->right = listSP;
	listSP->left = listPtr;

	return listSP;
}

void endList(list *listPtr)
{
	if(NULL == listPtr)
		return;
	if(listPtr->left != NULL) {
		listPtr->left->right = NULL;
	}
	if(listPtr->right != NULL) {
		listPtr->right->left = NULL;
		endList(listPtr->right);
	}
	free(listPtr);
}

int takeNum(list **listPtr, int targetNum)
{
	list *moveLeft = (*listPtr);
	int moveLeftCnt = 0, moveRightCnt = 0;
	while(targetNum != moveLeft->num) {
		moveLeft = moveLeft->left;
		++moveLeftCnt;
	}
	while(targetNum != (*listPtr)->num) {
		(*listPtr) = (*listPtr)->right;
		++moveRightCnt;
	}

	if((*listPtr) == (*listPtr)->right) {
		*(listPtr) = NULL;
	} else {
		(*listPtr) = (*listPtr)->right;
		moveLeft->left->right = moveLeft->right;
		moveLeft->right->left = moveLeft->left;
	}
	free(moveLeft);

	if(moveLeftCnt>=moveRightCnt)
		return moveRightCnt;
	else
		return moveLeftCnt;
}
