
#include <stdio.h>

void strangeFunc();
void strangeFuc_i(int a, int b, int c, int data[51][51][51]);

int main(void)
{
	strangeFunc();
	return 0;
}

void strangeFunc()
{
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	int data[51][51][51] = {0,};

	while(a != -1 || b != -1 || c != -1) {
		if(a<=0 || b<=0 || c<= 0) {
			printf("w(%d, %d, %d) = 1\n", a, b, c);
			scanf("%d %d %d", &a, &b, &c);
			continue;
		}
		for(int i = 0; i < 51; ++i) {
			for(int j = 0; j < 51; ++j) {
				for(int k = 0; k < 51; ++k) {
					data[i][j][k] = 0;
				}
			}
		}
		data[20][20][20] = 1048576;
		strangeFuc_i(a,b,c,data);
		printf("w(%d, %d, %d) = %d\n", a, b, c, data[a][b][c]);
		scanf("%d %d %d", &a, &b, &c);
	}
}

void strangeFuc_i(int a, int b, int c, int data[51][51][51])
{
	if(!data[a][b][c]) {
		if(a<=0 || b<=0 || c<=0) {
			data[a][b][c] = 1;
			return;
		}
		if(a>20 || b>20 || c>20) {
			data[a][b][c] = data[20][20][20];
			return;
		}
		if(a<b && b<c) {
			if(!data[a][b][c-1]) strangeFuc_i(a,b,c-1,data);
			if(!data[a][b-1][c-1]) strangeFuc_i(a,b-1,c-1,data);
			if(!data[a][b-1][c]) strangeFuc_i(a,b-1,c,data);
			data[a][b][c] = data[a][b][c-1] + data[a][b-1][c-1] - data[a][b-1][c];
			return;
		}
		if(!data[a-1][b][c]) strangeFuc_i(a-1,b,c,data);
		if(!data[a-1][b-1][c]) strangeFuc_i(a-1,b-1,c,data);
		if(!data[a-1][b][c-1]) strangeFuc_i(a-1,b,c-1,data);
		if(!data[a-1][b-1][c-1]) strangeFuc_i(a-1,b-1,c-1,data);
		data[a][b][c] = data[a-1][b][c] + data[a-1][b-1][c] + data[a-1][b][c-1] - data[a-1][b-1][c-1];
	}
	return;
}
