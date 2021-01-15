
#include <stdio.h>
#include <string.h>

int solution(const char *skill, const char *skill_trees[], size_t skill_trees_len);

int main(void)
{
	char *skill = "CBD";
	char *zero = "KACBE";
	char *one = "CBADF";
	char *two = "AECB";
	char *three = "BDA";
	char *skill_trees[4] = {zero, one, two, three};
	printf("%d\n", solution(skill, (const char **)skill_trees, 4));

	return 0;
}

int solution(const char *skill, const char *skill_trees[], size_t skill_trees_len)
{
	size_t skill_len = strlen(skill), custom_skill_len;
	int skill_set = 0, isPossible = 1, answer = 0;
	for(int i = 0; i < skill_trees_len; ++i) {
		custom_skill_len = strlen(skill_trees[i]);
		for(int j = 0; j < custom_skill_len; ++j) {
			for(int m = skill_set; m < skill_len; ++m) {
				if(skill_trees[i][j] == skill[m]) {
					if(m == skill_set) {
						skill_set++;
					} else {
						isPossible = 0;
					}
					break;
				}
			}
			if(!isPossible) break;
		}
		if(isPossible) answer++;
		isPossible = 1;
		skill_set = 0;
	}

	return answer;
}
