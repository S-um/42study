
#include <stdio.h>

int findBro(int loc1, int loc2);

int main(void)
{
	int loc1, loc2;
	scanf("%d %d", &loc1, &loc2);
	printf("%d\n",findBro(loc1,loc2));
}

int findBro(int loc1, int loc2)
{
	int loc, time;
	int sp, ep;
	int i;
	int visited[100001];
	int que[100001];

	i = 0;
	while(i<100001)
		visited[i++] = -1;

	sp = 0;
	ep = 0;

	visited[loc1] = 0;
	que[ep] = loc1;

	while(1) {
		loc = que[sp++];
		if(loc == loc2) {
			time = visited[loc];
			break;
		}

		if(loc<100000 && -1 == visited[loc+1]) {
			visited[loc+1] = visited[loc]+1;
			++ep;
			que[ep] = loc+1;
		}
		if(loc>0 && -1 == visited[loc-1]) {
			visited[loc-1] = visited[loc]+1;
			++ep;
			que[ep] = loc-1;
		}
		if(loc*2<=100000 && -1 == visited[loc*2]) {
			visited[loc*2] = visited[loc]+1;
			++ep;
			que[ep] = loc*2;
		}
	}

	return time;
}
