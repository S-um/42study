#include <stdio.h>
#include <stdlib.h>

int w(int a,int b,int c);

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", w(a, b, c));		

	return 0;
}

int w(int a,int b,int c)
{
	if(a<=0 || b<=0 || c<= 0) return 1;
	if(a>20 || b>20 || c>20) return w(20,20,20);
	if(a<b && b<c) return w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
	return w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
}
