
#include <stdio.h>

void star();

int main()
{
	star();

	return 0;
}

void star()
{
	scanf("%hhd",&N);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(j < N-i-1) printf(" ");
			else printf("*");
		}
	}
}
