
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, m, i, card;
	int *arr = (int*)calloc(20000001,sizeof(int));
	int *cardData = arr+10000000;
	scanf("%d",&n);
	
	i = 0;
	while(i<n) {
		scanf("%d", &card);
		++cardData[card];
		++i;
	}

	scanf("%d",&m);
	i= 0;
	while(i<m) {
		scanf("%d", &card);
		printf("%d ",cardData[card]);
		++i;
	}
	printf("\n");
	free(arr);
}
