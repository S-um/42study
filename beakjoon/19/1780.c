
#include <stdio.h>
#include <stdlib.h>

void printPaperCnt(int **paperArr, int len);
void printPaperCnt_i(int **paperArr, int scanlen, int startX, int startY, int *ans);

int main(void)
{
	int len, i, j;
	scanf("%d", &len);
	int **paperArr = (int**)malloc(len * sizeof(int*));
	i = 0;
	while(i<len) {
		paperArr[i] = (int*)malloc(len *sizeof(int));
		j = 0;
		while(j<len)
			scanf("%d", paperArr[i]+(j++));
		++i;
	}

	printPaperCnt(paperArr,len);

	return 0;
}

void printPaperCnt(int **paperArr, int len)
{
	int ans[3] = {0,};
	printPaperCnt_i(paperArr,len,0,0,ans);
	printf("%d\n%d\n%d\n",ans[0],ans[1],ans[2]);
}

void printPaperCnt_i(int **paperArr, int scanlen, int startX, int startY, int *ans)
{
	int firstNum = paperArr[startY][startX];
	int x = startX;
	int y = startY;
	int isSame = 1;

	while(y<startY+scanlen) {
		x = startX;
		while(x<startX+scanlen) {
			if(firstNum != paperArr[y][x]) {
				isSame = 0;
				break;
			}
			++x;
		}
		if(!isSame)
			break;
		++y;
	}

	if(isSame) {
		ans[firstNum+1] += 1;
	} else {
		y = startY;
		while(y<startY+scanlen) {
			x = startX;
			while(x<startX+scanlen) {
				printPaperCnt_i(paperArr,scanlen/3,x,y,ans);
				x+=scanlen/3;
			}
			y+=scanlen/3;
		}
	}
}
