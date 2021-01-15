
#include <stdio.h>

int scoring(char *litmus);

int main()
{
	int count, score;
	scanf("%d", &count);
	char test[80];
	for(int i = 0; i < count; i++) {
		scanf("%s", test);
		score = scoring(test);
		printf("%d\n", score);
	}
	return 0;
}

int scoring(char *litmus)
{
	int i = 0, conti = 1, score = 0;
	while(litmus[i]) {
		if(litmus[i] == 'O') {
			score += conti++;
		} else conti = 1;
		i++;
	}

	return score;
}
