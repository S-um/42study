
#include <stdio.h>

int main(void)
{
	int bracket, n, i, j, breaked;
	char s[51] = {0,};
	scanf("%d", &n);
	i = 0;
	while(i<n) {
		scanf("%s", s);
		j = 0;
		bracket = 0;
		breaked = 0;
		while(s[j]) {
			if('(' == s[j])
				++bracket;
			else if(')' == s[j])
				--bracket;
			if(bracket<0) {
				printf("NO\n");
				breaked = 1;
				break;
			}
			++j;
		}
		if(breaked) {
			++i;
			continue;
		}

		if(0 == bracket)
			printf("YES\n");
		else
			printf("NO\n");
		++i;
	}

	return 0;
}
