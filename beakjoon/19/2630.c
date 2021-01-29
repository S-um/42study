
#include <stdio.h>
#include <stdlib.h>

void printPicture(int **picArr, int len);
void scanPicture_i(int **picArr, int scanlen, int startX, int startY, int *cnt);

int main(void)
{
	int len, i, j;
	scanf("%d", &len);
	int **picArr = (int**)malloc(len * sizeof(int*));
	
	i = 0;
	while(i<len) {
		picArr[i] = (int*)malloc(len * sizeof(int));
		j = 0;
		while(j<len) {
			scanf("%d", picArr[i]+j);
			++j;
		}
		++i;
	}

	printPicture(picArr,len);

	i = 0;
	while(i<len)
		free(picArr[i++]);
	free(picArr);

	return 0;
}

void printPicture(int **picArr, int len)
{
	int cnt[2] = {0,};

	scanPicture_i(picArr,len,0,0,cnt);
	printf("%d\n%d\n",cnt[0],cnt[1]);
}

void scanPicture_i(int **picArr, int scanlen, int startX, int startY, int *cnt)
{
	int firstNum = picArr[startY][startX];
	int x = startX;
	int y = startY;
	int isSame = 1;

	while(y<startY+scanlen) {
		x = startX;
		while(x<startX+scanlen) {
			if(firstNum != picArr[y][x]) {
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
		*(cnt+firstNum) += 1;
	} else {
		scanPicture_i(picArr,scanlen/2,startX,startY,cnt);
		scanPicture_i(picArr,scanlen/2,startX+scanlen/2,startY,cnt);
		scanPicture_i(picArr,scanlen/2,startX,startY+scanlen/2,cnt);
		scanPicture_i(picArr,scanlen/2,startX+scanlen/2,startY+scanlen/2,cnt);
	}
}
