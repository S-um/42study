
#include <stdio.h>

long long solution(int w, int h);

int main(void)
{
	int w, h;
	//scanf("%d %d", &w, &h);
	for(int i = 999990; i<1000000; ++i) {
		w = i;
		for(int j = 999990; j<1000000; ++j) {
			h = j;
			printf("%lld\n", solution(w,h));
		}
	}
}

long long solution(int w, int h)
{
	long long answer = 0;

	for(int i = 1; i < w; ++i) {
		answer += ((long long)h * (long long)i)/(long long)w;
	}
	answer *= 2;
	return answer;
}
