
#include <stdio.h>
#include <stdlib.h>

typedef struct s_docuOrder {
	int importance;
	char isIwant;
	struct s_docuOrder *next;
}t_docuOrder;

void pushQueue(t_docuOrder **docuManager, int importance, int isIwant)
{
	t_docuOrder *newDocument = (t_docuOrder*)malloc(sizeof(t_docuOrder));
	t_docuOrder *temp = *docuManager;
	newDocument->importance = importance;
	newDocument->isIwant = isIwant;
	newDocument->next = NULL;
	if(NULL == *docuManager) {
		*docuManager = newDocument;
		return;
	}
	while(NULL != temp->next) {
		temp = temp->next;
	}
	temp->next = newDocument;
	return;
}

void freeQueue(t_docuOrder *docuManager)
{
	if(NULL != docuManager->next) {
		freeQueue(docuManager->next);
	}
	free(docuManager);
}

void printQ(t_docuOrder *docuManager)
{
	while(docuManager != NULL) {
		printf("%d ",docuManager->importance);
		docuManager = docuManager->next;
	}
	printf("\n");
}

int main(void)
{
	int testcase, i, docuCnt, targetIndex, j, importance, answer, ablePrint;
	scanf("%d", &testcase);
	i = 0;
	t_docuOrder *docuManager = NULL;
	t_docuOrder *temp;
	while(i<testcase) {
		scanf("%d %d", &docuCnt, &targetIndex);
		answer = 1;
		j = 0;
		while(j<docuCnt) {
			scanf("%d", &importance);
			pushQueue(&docuManager,importance,j==targetIndex);
			++j;
		}

		while(1) {
			//printQ(docuManager);
			temp = docuManager;
			ablePrint = 1;
			while(temp->next != NULL) {
				if(temp->importance > docuManager->importance) {
					ablePrint = 0;
				}
				temp = temp->next;
			}

			if(temp->importance > docuManager->importance) {
				ablePrint = 0;
			}
			if(ablePrint) {
				if(docuManager->isIwant)
					break;
				++answer;
				temp = docuManager;
				docuManager = docuManager->next;
				free(temp);
			} else {
				temp->next = docuManager;
				docuManager = docuManager->next;
				temp->next->next = NULL;
			}
		}

		freeQueue(docuManager);
		docuManager = NULL;

		printf("%d\n", answer);
		++i;
	}

	return 0;
}
