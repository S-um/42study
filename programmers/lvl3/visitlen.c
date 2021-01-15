
#include <stdio.h>

int solution(const char* dirs);
void mvright(char *x, char *y,int*answer,int checkroad[][10]);
void mvup(char *x, char *y, int*answer,int checkroad[][11]);
void mvleft(char *x, char *y,int*answer,int checkroad[][10]);
void mvdown(char *x, char *y, int*answer,int checkroad[][11]);

char x = 5, y = 5;
	int ver[11][10] = {0,};
	int hor[10][11] = {0,};

int main(void)
{
	char command[2] = {0,};

	while(1) {
		scanf("%c", command);
		if('e' == command[0]) break;
		solution(command);
		getchar();
	}
	printf("thanks for playing\n");

	return 0;
}

int solution(const char* dirs)
{
	int answer = 0;
	int i = 0;
	while(dirs[i]) {
		switch(dirs[i]) {
			case 'U':
				mvup(&x,&y,&answer,hor);
				break;
			case 'D':
				mvdown(&x,&y,&answer,hor);
				break;
			case 'R':
				mvright(&x,&y,&answer,ver);
				break;
			case 'L':
				mvleft(&x,&y,&answer,ver);
				break;
		}
		++i;
	}

	printf("(%d,%d)\n", x, y);
	return answer;
}

void mvright(char *x, char *y, int*answer,int checkroad[][10])
{
	if(10 == (*x)) return;
	printf("checking road[%d][%d]\n", *y, *x);
	if(!checkroad[*y][*x]) {
		printf("new road! add answer : %d --- ", (*answer)+1);
		(*answer)++;
		checkroad[*y][*x] = 1;
	}
	(*x)++;
	return;
}

void mvup(char *x, char *y, int*answer,int checkroad[][11])
{
	if(10 == (*y)) return;
	printf("checking road[%d][%d]\n", *y, *x);
	if(!checkroad[*y][*x]) {
		printf("new road! add answer : %d --- ", (*answer)+1);
		(*answer)++;
		checkroad[*y][*x] = 1;
	}
	(*y)++;
	return;
}

void mvleft(char *x, char *y, int*answer,int checkroad[][10])
{
	if(0 == (*x)) return;
	printf("checking road[%d][%d]\n", *y, (*x)-1);
	if(!checkroad[*y][(*x)-1]) {
		printf("new road! add answer : %d --- ", (*answer)+1);
		(*answer)++;
		checkroad[*y][(*x)-1] = 1;
	}
	(*x)--;
	return;
	
}

void mvdown(char *x, char *y, int*answer,int checkroad[][11])
{
	if(0 == (*y)) return;
	printf("checking road[%d][%d]\n", (*y)-1, *x);
	if(!checkroad[(*y)-1][*x]) {
		printf("new road! add answer : %d --- ", (*answer)+1);
		(*answer)++;
		checkroad[(*y)-1][*x] = 1;
	}
	(*y)--;
	return;
	
}
