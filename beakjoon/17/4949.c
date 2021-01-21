
#include <stdio.h>

int isfin(char *c)
{
	if('.' != c[0])
		return 1;
	if('\n' == c[1] || 0 == c[1])
		return 0;
	return 1;
}

int main(void)
{
	char s[101] = {0,};
	char bracketdata[101] = {0,};
	int i, isbreaked, bracketindex;
	char islastsm;
	
	fgets(s,101,stdin);
	while(isfin(s)) {
		i = 0;
		bracketindex = 0;
		isbreaked = 0;
		while(s[i]) {
			if('(' == s[i]) {
				bracketdata[bracketindex] = '(';
				++bracketindex;
			} else if('[' == s[i]) {
				bracketdata[bracketindex] = '[';
				++bracketindex;
			} else if(')' == s[i]) {
				if(0 == bracketindex) {
					isbreaked = 1;
					break;
				}
				if('(' == bracketdata[bracketindex-1]) {
					--bracketindex;
					bracketdata[bracketindex] = 0;
				} else {
					isbreaked = 1;
					break;
				}
			} else if(']' == s[i]) {
				if(0 == bracketindex) {
					isbreaked = 1;
					break;
				}
				if('[' == bracketdata[bracketindex-1]) {
					--bracketindex;
					bracketdata[bracketindex] = 0;
				} else {
					isbreaked = 1;
					break;
				}
			}

			++i;
		}

		if(isbreaked) {
			printf("no\n");
		} else if(0 == bracketindex) {
			printf("yes\n");
		} else {
			printf("no\n");
		}

		i = 0;
		while(s[i]) s[i++] = 0;
		fgets(s,101,stdin);
	}

	return 0;
}
