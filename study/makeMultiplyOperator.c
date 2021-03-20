
#include <stdio.h>

int sum(int a, int b);
char get_bit(int a, char bit_index);
int input_bit(int a, char bit, char bit_index);
int sum_by_bit(int sum, int a, int b, char *is_over, char bit_index);
int add_bit_by_bit_index(int sum, char bit, char bit_index, char *is_over);

int multi(int a,int b);
int multi_by_bit(int a, int b, char bit_index);

int main(void)
{
	int a, b;
	scanf("%d %d",&a,&b);
	printf("multi : %d\n",multi(a,b));
}

int multi(int a,int b)
{
	int ret = 0;
	ret = multi_by_bit(a,b,0);
	ret = sum(ret, multi_by_bit(a,b,1));
	ret = sum(ret, multi_by_bit(a,b,2));
	ret = sum(ret, multi_by_bit(a,b,3));
	ret = sum(ret, multi_by_bit(a,b,4));
	ret = sum(ret, multi_by_bit(a,b,5));
	ret = sum(ret, multi_by_bit(a,b,6));
	ret = sum(ret, multi_by_bit(a,b,7));
	ret = sum(ret, multi_by_bit(a,b,8));
	ret = sum(ret, multi_by_bit(a,b,9));
	ret = sum(ret, multi_by_bit(a,b,10));
	ret = sum(ret, multi_by_bit(a,b,11));
	ret = sum(ret, multi_by_bit(a,b,12));
	ret = sum(ret, multi_by_bit(a,b,13));
	ret = sum(ret, multi_by_bit(a,b,14));
	ret = sum(ret, multi_by_bit(a,b,15));
	ret = sum(ret, multi_by_bit(a,b,16));
	ret = sum(ret, multi_by_bit(a,b,17));
	ret = sum(ret, multi_by_bit(a,b,18));
	ret = sum(ret, multi_by_bit(a,b,19));
	ret = sum(ret, multi_by_bit(a,b,20));
	ret = sum(ret, multi_by_bit(a,b,21));
	ret = sum(ret, multi_by_bit(a,b,22));
	ret = sum(ret, multi_by_bit(a,b,23));
	ret = sum(ret, multi_by_bit(a,b,24));
	ret = sum(ret, multi_by_bit(a,b,25));
	ret = sum(ret, multi_by_bit(a,b,26));
	ret = sum(ret, multi_by_bit(a,b,27));
	ret = sum(ret, multi_by_bit(a,b,28));
	ret = sum(ret, multi_by_bit(a,b,29));
	ret = sum(ret, multi_by_bit(a,b,30));
	ret = sum(ret, multi_by_bit(a,b,31));
	return ret;
}

int multi_by_bit(int a, int b, char bit_index)
{
	if(get_bit(b,bit_index))
		return a << bit_index;
	return 0;
}


int sum(int a, int b)
{
	int ret = 0;
	char is_over = 0;
	ret = sum_by_bit(ret,a,b,&is_over,0);
	ret = sum_by_bit(ret,a,b,&is_over,1);
	ret = sum_by_bit(ret,a,b,&is_over,2);
	ret = sum_by_bit(ret,a,b,&is_over,3);
	ret = sum_by_bit(ret,a,b,&is_over,4);
	ret = sum_by_bit(ret,a,b,&is_over,5);
	ret = sum_by_bit(ret,a,b,&is_over,6);
	ret = sum_by_bit(ret,a,b,&is_over,7);
	ret = sum_by_bit(ret,a,b,&is_over,8);
	ret = sum_by_bit(ret,a,b,&is_over,9);
	ret = sum_by_bit(ret,a,b,&is_over,10);
	ret = sum_by_bit(ret,a,b,&is_over,11);
	ret = sum_by_bit(ret,a,b,&is_over,12);
	ret = sum_by_bit(ret,a,b,&is_over,13);
	ret = sum_by_bit(ret,a,b,&is_over,14);
	ret = sum_by_bit(ret,a,b,&is_over,15);
	ret = sum_by_bit(ret,a,b,&is_over,16);
	ret = sum_by_bit(ret,a,b,&is_over,17);
	ret = sum_by_bit(ret,a,b,&is_over,18);
	ret = sum_by_bit(ret,a,b,&is_over,19);
	ret = sum_by_bit(ret,a,b,&is_over,20);
	ret = sum_by_bit(ret,a,b,&is_over,21);
	ret = sum_by_bit(ret,a,b,&is_over,22);
	ret = sum_by_bit(ret,a,b,&is_over,23);
	ret = sum_by_bit(ret,a,b,&is_over,24);
	ret = sum_by_bit(ret,a,b,&is_over,25);
	ret = sum_by_bit(ret,a,b,&is_over,26);
	ret = sum_by_bit(ret,a,b,&is_over,27);
	ret = sum_by_bit(ret,a,b,&is_over,28);
	ret = sum_by_bit(ret,a,b,&is_over,29);
	ret = sum_by_bit(ret,a,b,&is_over,30);
	ret = sum_by_bit(ret,a,b,&is_over,31);
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

int add_bit_by_bit_index(int sum, char bit, char bit_index, char *is_over)
{
	if(get_bit(sum,bit_index) && bit)
	{
		*is_over = 1;
	}
	sum = input_bit(sum,bit,bit_index);
	return sum;
}

int sum_by_bit(int sum, int a, int b, char *is_over, char bit_index)
{
	char a_bit = get_bit(a,bit_index);
	char b_bit = get_bit(b,bit_index);

	sum = input_bit(sum,*is_over,bit_index);
	*is_over = 0;
	sum = add_bit_by_bit_index(sum,a_bit,bit_index,is_over);
	sum = add_bit_by_bit_index(sum,b_bit,bit_index,is_over);
	return sum;
}
