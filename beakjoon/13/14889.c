
#include <stdio.h>
#include <stdlib.h>

int fairTeam(int **synergy, int num);
void fairTeam_i(int **synergy, int *teamA, int *teamB, int maxnum, int curindex, int *answer);

int main(void)
{
	int n;
	scanf("%d",&n);
	int **synergy = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i < n; ++i) {
		synergy[i] = (int*)malloc(sizeof(int)*n);
		for(int j = 0; j < n; ++j) {
			scanf("%d", synergy[i]+j);
		}
	}
	printf("%d\n", fairTeam(synergy, n));
	free(synergy);
	return 0;
}

int fairTeam(int **synergy, int num)
{
	int *teamA = (int*)malloc(sizeof(int) * (num/2));
	int *teamB = (int*)malloc(sizeof(int) * (num/2));
	teamA[0] = 0;
	int answer = 10000000;
	fairTeam_i(synergy, teamA, teamB, num/2, 1, &answer);
	free(teamA);

	return answer;
}

void fairTeam_i(int **synergy, int *teamA, int *teamB, int maxnum, int curindex, int *answer)
{
	if(curindex == maxnum) {
		int teamBindex = 0;
		int teamAindex = 0;
		for(int i = 0; i < maxnum * 2; ++i) {
			if(i != teamA[teamAindex]) teamB[teamBindex++] = i;
			else teamAindex++;
		}
		int synergyA = 0, synergyB = 0;
		for(int i = 0; i < maxnum-1; ++i) {
			for(int j = i+1; j < maxnum; ++j) {
				synergyA += synergy[teamA[i]][teamA[j]] + synergy[teamA[j]][teamA[i]];
				synergyB += synergy[teamB[i]][teamB[j]] + synergy[teamB[j]][teamB[i]];
			}
		}
		if(synergyA>synergyB && synergyA-synergyB < *answer) *answer = synergyA-synergyB;
		if(synergyA<synergyB && synergyB-synergyA < *answer) *answer = synergyB-synergyA;
		if(synergyA==synergyB) *answer = 0;
		return;
	}
	for(int i = teamA[curindex-1]+1; i <= maxnum + curindex; ++i) {
		teamA[curindex] = i;
		fairTeam_i(synergy, teamA, teamB, maxnum, curindex+1,answer);
	}
	return;
}
