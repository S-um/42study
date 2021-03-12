
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	long i;
	i = 42;

	long *ptr1;
	long fake_ptr;

	ptr1 = &i;
	fake_ptr = (long)ptr1;

	printf("fake_ptr : %ld\n",fake_ptr);
	printf("*(int*)fake_ptr : %ld\n",*(long*)fake_ptr);
}
