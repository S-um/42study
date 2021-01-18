
#include <stdio.h>
#include <stdlib.h>

int gethighscore(int *stair, int floor);

int main(void)
{
	int floor;
	scanf("%d", &floor);
	int*stair = (int*)malloc(sizeof(int)*floor);
	for(int i = 0; i < floor; ++i) scanf("%d", stair+i);
	printf("%d\n", gethighscore(stair, floor));

	free(stair);
	return 0;
}

int gethighscore(int *stair, int floor)
{
	int answer;

	int *score = (int*)malloc(sizeof(int)*floor);

	if(0 == floor) return stair[0];
	if(1 == floor) return stair[0]+stair[1];

	score[0] = stair[0];
	score[1] = stair[0]+stair[1];
	if(score[0]>stair[1])
		score[2] = score[0]+stair[2];
	else
		score[2] = stair[1]+stair[2];

	for(int i = 3; i < floor; ++i) {
		if(score[i-2]>score[i-3]+stair[i-1])
			score[i] = score[i-2]+stair[i];
		else
			score[i] = score[i-3]+stair[i-1]+stair[i];
	}

	return score[floor-1];
}
