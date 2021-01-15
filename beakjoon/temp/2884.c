
#include <stdio.h>

int main(void)
{
	unsigned char h, m;
	scanf("%d %d", &h, &m);

	m -= 45;
	if(m < 60) {
		m += 60;
		if(h) h--;
		else h = 23;
	}
	printf("%d %d\n", h, m);
	return 0;
}
