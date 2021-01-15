
#include <stdio.h>
#include <stdlib.h>

int solution(int a[], size_t a_len);

int main(void)
{
	int n;
	scanf("%d",&n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; ++i) scanf("%d", arr+i);

	printf("%d\n", solution(arr,n));

	return 0;
}

int solution(int a[], size_t a_len)
{
	int answer = 2;
	int l = a[0], r = a[a_len-1];

	for(int i = 1; i < a_len-1; ++i) {
		if(l>a[i]) {
			l = a[i];
			answer++;
		}
		if(r>a[a_len-i-1]) {
			r = a[a_len-i-1];
			answer++;
		}
	}
	printf("%d %d\n", l, r);
	if(l == r) answer--;

	return answer;
}
