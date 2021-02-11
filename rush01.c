
#include <unistd.h>
#include <stdlib.h>

int isAble(char **plate, char **data)
{
	int cntCol, cntRow;
	int isTallestCol, isTallestRow;
	int i, j, m;
	i = 0;
	while(i<4) {
		j = 0;
		cntCol = 0;
		cntRow = 0;
		while(j<4) {
			isTallestCol = 1;
			isTallestRow = 1;
			m = 0;
			while(m<j) {
				if(plate[j][i]<plate[m][i])
					isTallestCol = 0;
				if(plate[i][j]<plate[i][m])
					isTallestRow = 0;
				++m;
			}
			if(isTallestCol)
				++cntCol;
			if(isTallestRow)
				++cntRow;
			++j;
		}
		if(data[0][i] != cntCol)
			return 0;
		if(data[2][i] != cntRow)
			return 0;

		j = 0;
		cntCol = 0;
		cntRow = 0;
		while(j<4) {
			isTallestCol = 1;
			isTallestRow = 1;
			m = 3;
			while(m>j) {
				if(plate[j][i]<plate[m][i])
					isTallestCol = 0;
				if(plate[i][j]<plate[i][m])
					isTallestRow = 0;
				--m;
			}
			if(isTallestCol)
				++cntCol;
			if(isTallestRow)
				++cntRow;
			++j;
		}
		if(data[1][i] != cntCol)
			return 0;
		if(data[3][i] != cntRow)
			return 0;
		++i;
	}
	return 1;
}

int canPut(char **plate, int x, int y)
{
	int i;
	i = 0;
	while(i<y)
		if(plate[y][x] == plate[i++][x])
			return 0;
	i = 0;
	while(i<x)
		if(plate[y][x] == plate[y][i++])
			return 0;
	return 1;
}

int fillPlate(char **plate, char **data, int x, int y)
{
	if(4 == x) {
		x = 0;
		++y;
	}
	if(4 == y) {
		if(isAble(plate,data))
			return 1;
		else
			return 0;
	}

	int isFin = 0;
	int i = 1;
	while(i<5) {
		plate[y][x] = i;
		if(canPut(plate,x,y)) {
			isFin = fillPlate(plate,data,x+1,y);
			if(isFin)
				return 1;
		}
		++i;
	}
	plate[y][x] = 0;
	return 0;
}

int main(int argc, char *argv[])
{
	int i, j;
	if(2 == argc)
		i = 1;
	char colU[4] = {argv[1][0]-'0',argv[1][2]-'0',argv[1][4]-'0',argv[1][6]-'0'};
	char colD[4] = {argv[1][8]-'0',argv[1][10]-'0',argv[1][12]-'0',argv[1][14]-'0'};
	char rowL[4] = {argv[1][16]-'0',argv[1][18]-'0',argv[1][20]-'0',argv[1][22]-'0'};
	char rowR[4] = {argv[1][24]-'0',argv[1][26]-'0',argv[1][28]-'0',argv[1][30]-'0'};
	char **plate = (char**)malloc(4*sizeof(char*));
	i = 0;
	while(i<4)
		plate[i++] = (char*)calloc(4,sizeof(char));
	char **data = (char**)malloc(4*sizeof(char*));
	data[0] = colU;
	data[1] = colD;
	data[2] = rowL;
	data[3] = rowR;
	i = 0;
	while(i<4) {
		j = 0;
		while(j<4)
			plate[i][j++] = 0;
		++i;
	}

	fillPlate(plate,data,0,0);
	{
		i = 0;
		while(i<4) {
			j = 0;
			while(j<4) {
				plate[i][j] += '0';
				write(1,plate[i]+(j++),1);
				write(1," ",1);
			}
			write(1,"\n",1);
			++i;
		}
	}
	i = 0;
	while(i<4)
		free(plate[i++]);
	free(plate);
	free(data);
}
