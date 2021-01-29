
#include <stdio.h>
#include <stdlib.h>

void zipPicture(int **picArr, int len);
void zipPicture_i(int **picArr, int scanlen, int startX, int startY);

int main(void)
{
	int len, i, j;
	scanf("%d", &len);
	int **picArr = (int**)malloc(len * sizeof(int*));
	char *s = (char*)malloc((len+1)*sizeof(char));
	i = 0;
	while(i<len) {
		picArr[i] = (int*)malloc(len * sizeof(int));
		j = 0;
		scanf("%s",s);
		while(j<len) {
			picArr[i][j] = s[j]-'0';
			++j;
		}
		++i;
	}

	zipPicture(picArr,len);

	free(s);
	i = 0;
	while(i<len)
		free(picArr[i++]);
	free(picArr);
}

void zipPicture(int **picArr, int len)
{
	zipPicture_i(picArr,len,0,0);
}

void zipPicture_i(int **picArr, int scanlen, int startX, int startY)
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
		printf("%d",firstNum);
	} else {
		printf("(");
		zipPicture_i(picArr,scanlen/2,startX,startY);
		zipPicture_i(picArr,scanlen/2,startX+scanlen/2,startY);
		zipPicture_i(picArr,scanlen/2,startX,startY+scanlen/2);
		zipPicture_i(picArr,scanlen/2,startX+scanlen/2,startY+scanlen/2);
		printf(")");
	}
}
