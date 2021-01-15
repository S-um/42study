
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	int index;
}n;

int solution(int *a, size_t a_len);
int compare(const void* a, const void* b);
int longest(int *a, size_t a_len, n *arr, size_t arr_len);

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
	if(1 == a_len) return 0;
	int answer = 0, i, temp, len, pivotindex, flag = 1;
	n *num = (n *)malloc(sizeof(n) * a_len);
	temp = a[0];
	for(i = 0; i < a_len; ++i) {
		num[i].num = a[i];
		num[i].index = i;
		if(temp != a[i]) flag = 0;
	}
	if(flag) return 0;
	qsort(num,a_len,sizeof(n),compare);

	i = 0;
	while(i < a_len) {
		printf("in solution %d in index %d\n",num[i].num, i);
		len = 0;
		pivotindex = i;
		temp = num[i].num;
		while(temp == num[i].num) {
			++len;
			++i;
		}
		if(answer >= len) continue;
		temp = longest(a,a_len,num+pivotindex,len);
		if(temp > answer) answer = temp;
		//printf("len : %d\n", len);
	}

	return answer * 2;
}

int compare(const void* a, const void* b)
{
	n a1 = *(n *)a;
	n b1 = *(n *)b;
	if(a1.num>b1.num) return 1;
	if(a1.num<b1.num) return -1;
	return 0;
}

int longest(int *a, size_t a_len, n *arr, size_t arr_len)
{
	int i, index, answer = 0, leftflag, rightflag, j, searchleft;
	int *usedindex = (int*)malloc(arr_len * sizeof(int));
	for(i = 0;i<arr_len;++i) usedindex[i] = -1;
	printf("start searching %d\n\n", arr[0].num);
	printf("start index %d\n", (*arr).index);

	i = 0;
	if((*arr).index == 0) {
		if(a[1] != a[0]) {
			++answer;
			usedindex[0] = 1;
		}
		++i;
	}
	while(i<arr_len) {
		//if(i==0) printf("%d\n",arr[i].num);
		index = arr[i].index;
		printf("searching index %d\n", index);
		if(index == a_len-1) {
			if(usedindex[i-1] != index -1 && a[index-1] != a[index]) {
				++answer;
			}
	printf("end searching %d\n\n--------------------------------\n\n", arr[0].num);
			return answer;
		}
		leftflag = 0;
		searchleft = 1;
		rightflag = 1;
		printf("searching left %d\n",a[index-1]);
		if(a[index-1] == a[index]) searchleft = 0;
		printf("searching right %d\n", a[index+1]);
		if(a[index+1] == a[index]) rightflag = 0;
		if(searchleft) {
			if(i == 0) {
				++answer;
				++i;
				usedindex[i] = index-1;
			//printf("index %d, num %d set with left\n",index, a[index]);
				continue;
			}
			if(index-1 == usedindex[i-1]) {
				leftflag = 0;
				if(!rightflag) break;
			}else {
				leftflag = 1;
			}
		}
		if(leftflag) {
			usedindex[i] = index-1;
			++answer;
			++i;
			//printf("index %d, num %d set with left\n", index,a[index]);
			continue;
		}
		if(rightflag) {
			usedindex[i] = index+1;
			++answer;
		//printf("index %d, num %d set with right\n",index, a[index]);
		}
		++i;

	}

	printf("end searching %d\n\n--------------------------------\n\n", arr[0].num);
	return answer;
}
