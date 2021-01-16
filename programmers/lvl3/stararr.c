
#include <stdio.h>
#include <stdlib.h>

int solution(int *a, size_t a_len);

int main(void)
{
	int n;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", arr+i);
	}
	printf("%d\n", solution(arr, n));
}

int solution(int *a, size_t a_len)
{
	int answer = -1, i;
	int *stararr = (int*)malloc(sizeof(int)*a_len);
	int *lastused = (int*)malloc(sizeof(int)*a_len);
	i = 0;
	while(i<a_len) {
		stararr[i] = 0;
		lastused[i] = -1;
		++i;
	}

	i = 0;
	while(i<a_len) {
		if(a[i] != a[i-1] && i-1 != lastused[a[i]]) stararr[a[i]] += 2;
		else if(i < a_len-1 && a[i] != a[i+1]) {
			stararr[a[i]] += 2;
			lastused[a[i]] = i+1;
		}
		++i;
	}

	i = 0;
	while(i<a_len) {
		if(stararr[i] > answer) answer = stararr[i];
		++i;
	}

	return answer;
}
