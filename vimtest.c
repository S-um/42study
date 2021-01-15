
#include<stdio.h>
int median(int a, int b, int c);
int main(){
	int a,b,c;

	printf("세 정수의 중앙 값을 구합니다.\n");
	printf("a의 값: "); scanf("%d", &a);
	printf("b의 값: "); scanf("%d", &b);
	printf("c의 값: "); scanf("%d", &c);

	printf("중앙 값은 %d입니다.\n", median(a,b,c));

	return 0;
}
int median(int a, int b, int c){
	if(b <= a)
		if(a <= c)
			printf("2times\n");
}
