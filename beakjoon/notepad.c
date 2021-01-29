
#include <stdio.h>

int main()
{
	long long A,B,C;
	scanf("%lld %lld %lld", &A, &B, &C);

	long long in, out, BEP;
	BEP = 0;
	in = BEP * C;
	out = A + B * BEP;

	if(C>B)
		while(out >= in)
		{
			BEP++;
			in = BEP * C;
			out = A + (B * BEP);
		}
	else BEP = -1;

	printf("%lld\n", BEP);

	return 0;
}
