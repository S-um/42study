
#include <unistd.h>

int main(void)
{
	int a;
	
	a = '1'*256*256*256 + '2'*256*256 + '3'*256 + '4';

	write(1,&a,4);
	
	return 0;
}
