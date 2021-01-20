
#include <stdio.h>
#include <stdlib.h>

int lcs(char *s1, char *s2);
int bigger(int a, int b);

int main(void)
{
	char s1[1001];
	char s2[1001];
	scanf("%s %s", s1, s2);
	printf("%d\n", lcs(s1,s2));

	return 0;
}

int lcs(char *s1, char *s2)
{
	int len1 = 0, len2 = 0;
	int i, j, answer;
	while(s1[len1]) ++len1;
	while(s2[len2]) ++len2;

	int **plate = (int**)malloc((len1+1) * sizeof(int*));
	i = 0;
	while(i<=len1) {
		plate[i] = (int*)calloc(len2+1,sizeof(int));
		++i;
	}
	i = 1;
	while(i<=len1) {
		j = 1;
		while(j<=len2) {
			if(s1[i-1] == s2[j-1]) {
				plate[i][j] = plate[i-1][j-1] + 1;
			} else
				plate[i][j] = bigger(plate[i-1][j],plate[i][j-1]);
			printf("%d ", plate[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}

	answer = plate[len1][len2];
	i = 0;
	while(i<=len1)
		free(plate[i++]);
	free(plate);

	return answer;
}

int bigger(int a, int b)
{
	if(a>=b) return a;
	else return b;
}
