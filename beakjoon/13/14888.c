
#include <stdio.h>
#include <stdlib.h>

int *insertOp(char *num, char num_len, char *opCnt);
void insertOp_i(char *num, char lastindex, char Curindex, char *opCnt, int calnum, int *answer);

int main(void)
{
	int i;
	char N;
	scanf("%hhd", &N);
	char *num = (char *)malloc(sizeof(int) * N);
	i = 0;
	while(i<N) scanf("%hhd", num+(i++));
	char opCnt[4] = {0,};
	i = 0;
	while(i<4) scanf("%hhd", opCnt+(i++));

	int *answer = insertOp(num,N,opCnt);
	printf("%d\n%d\n", answer[0], answer[1]);
	free(answer);

	return 0;
}

int *insertOp(char *num, char num_len, char *opCnt)
{
	int i = 0;
	int *answer = (int*)malloc(sizeof(int)*2);
	answer[0] = -1000000000;
	answer[1] = 1000000000;
	insertOp_i(num, num_len-1, 1, opCnt, num[0], answer);

	return answer;
}


void insertOp_i(char *num, char lastindex, char Curindex, char *opCnt, int calnum, int *answer)
{
	int i = 0;
	if(lastindex + 1 == Curindex) {
		if(calnum > answer[0]) answer[0] = calnum;
		if(calnum < answer[1]) answer[1] = calnum;
		return;
	}
	while(i<4) {
		if(0 == opCnt[i]) {
			++i;
			continue;
		}
		--(opCnt[i]);
		switch(i) {
			case 0:
				insertOp_i(num,lastindex,Curindex+1,opCnt,calnum+num[Curindex],answer);
				break;
			case 1:
				insertOp_i(num,lastindex,Curindex+1,opCnt,calnum-num[Curindex],answer);
				break;
			case 2:
				insertOp_i(num,lastindex,Curindex+1,opCnt,calnum*num[Curindex],answer);
				break;
			case 3:
				insertOp_i(num,lastindex,Curindex+1,opCnt,calnum/num[Curindex],answer);
				break;

		}
		++(opCnt[i]);
		++i;
	}
	return;
}
