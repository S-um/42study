
#include <stdio.h>
#include <stdlib.h>

long long getNumByIndex(long long N, long long k);

int main(void)
{
	long long N,k;
	scanf("%lld %lld",&N,&k);
	printf("%lld\n",getNumByIndex(N,k));
	return 0;
}

long long getNumByIndex(long long N, long long k)
{
	long long min, max, mid, cnt, i;
	min = 1;
	max = k+1;
	mid = (min+max)/2;

	while(min<=max) {
		i = 1;
		cnt = 0;
		while(i<=N) {
			if(mid<N*i)
				cnt += mid/i;
			else
				cnt += N;
			++i;
		}
		if(cnt>=k) {
			max = mid-1;
			mid = (min+max)/2;
		}else{
			min = mid+1;
			mid = (min+max)/2;
		}
	}
	return min;
}
