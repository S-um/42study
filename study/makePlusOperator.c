
#include <stdio.h>

int sum(int a, int b);
char get_bit(int a, char bit_index);
int input_bit(int a, char bit, char bit_index);
int sum_by_bit(int sum, int a, int b, char *carry, char bit_index);
int add_bit_by_bit_index(int sum, char bit, char bit_index, char *carry);

int main(void)
{
	int a, b;
	scanf("%d %d",&a,&b);
	printf("sum : %d\n",sum(a,b));
}

int sum(int a, int b)
{
	int ret = 0;
	char carry = 0;
	ret = sum_by_bit(ret,a,b,&carry,0);
	ret = sum_by_bit(ret,a,b,&carry,1);
	ret = sum_by_bit(ret,a,b,&carry,2);
	ret = sum_by_bit(ret,a,b,&carry,3);
	ret = sum_by_bit(ret,a,b,&carry,4);
	ret = sum_by_bit(ret,a,b,&carry,5);
	ret = sum_by_bit(ret,a,b,&carry,6);
	ret = sum_by_bit(ret,a,b,&carry,7);
	ret = sum_by_bit(ret,a,b,&carry,8);
	ret = sum_by_bit(ret,a,b,&carry,9);
	ret = sum_by_bit(ret,a,b,&carry,10);
	ret = sum_by_bit(ret,a,b,&carry,11);
	ret = sum_by_bit(ret,a,b,&carry,12);
	ret = sum_by_bit(ret,a,b,&carry,13);
	ret = sum_by_bit(ret,a,b,&carry,14);
	ret = sum_by_bit(ret,a,b,&carry,15);
	ret = sum_by_bit(ret,a,b,&carry,16);
	ret = sum_by_bit(ret,a,b,&carry,17);
	ret = sum_by_bit(ret,a,b,&carry,18);
	ret = sum_by_bit(ret,a,b,&carry,19);
	ret = sum_by_bit(ret,a,b,&carry,20);
	ret = sum_by_bit(ret,a,b,&carry,21);
	ret = sum_by_bit(ret,a,b,&carry,22);
	ret = sum_by_bit(ret,a,b,&carry,23);
	ret = sum_by_bit(ret,a,b,&carry,24);
	ret = sum_by_bit(ret,a,b,&carry,25);
	ret = sum_by_bit(ret,a,b,&carry,26);
	ret = sum_by_bit(ret,a,b,&carry,27);
	ret = sum_by_bit(ret,a,b,&carry,28);
	ret = sum_by_bit(ret,a,b,&carry,29);
	ret = sum_by_bit(ret,a,b,&carry,30);
	ret = sum_by_bit(ret,a,b,&carry,31);
	return ret;
}

char get_bit(int a, char bit_index)
{
	a = a >> bit_index;
	a = a & 1;
	return (char)a;
}

int input_bit(int a, char bit, char bit_index)
{
	int input_temp = bit;
	input_temp = input_temp << bit_index;
	a ^= input_temp;
	return a;
}

int add_bit_by_bit_index(int sum, char bit, char bit_index, char *carry)
{
	if(get_bit(sum,bit_index) && bit)
	{
		*carry = 1;
	}
	sum = input_bit(sum,bit,bit_index);
	return sum;
}

int sum_by_bit(int sum, int a, int b, char *carry, char bit_index)
{
	char a_bit = get_bit(a,bit_index);
	char b_bit = get_bit(b,bit_index);

	sum = input_bit(sum,*carry,bit_index);
	*carry = 0;
	sum = add_bit_by_bit_index(sum,a_bit,bit_index,carry);
	sum = add_bit_by_bit_index(sum,b_bit,bit_index,carry);
	return sum;
}
