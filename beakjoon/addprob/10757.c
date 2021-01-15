
#include <stdio.h>
#include <string.h>

void plusone(char num[], char len);

int main(void)
{
	char a[10001], b[10001];
	scanf("%s", a);
	scanf("%s", b);
	char over = 0;
	char temp;

	int alen = strlen(a) - 1;
	int blen = strlen(b) - 1;
	char isalonger;
	if(alen > blen) {
		isalonger = 1;
	}
	else {
		isalonger = 0;
	}
	while(alen+1 && blen+1) {
		temp = a[alen]+ b[blen]- '0';
		

		if(over) temp++;
		if(temp > '9') {
			over = 1;
			temp -= 10;
		} else over = 0;


		if(isalonger) a[alen] = temp;
		else b[blen] = temp;
		alen--;
		blen--;
	}

	if(over) {
		if(alen == blen) printf("1");
		else {
			if(isalonger) {
				plusone(a, alen);
			}
			else {
				plusone(b, blen);
			}
		}
	}
	
	if(isalonger) printf("%s\n", a);
	else printf("%s\n", b);
	return 0;
}

void plusone(char num[], char len)
{
	while((len+1)) {
		if(num[len] == '9') num[len] = '0';
		else {
			num[len]++;
			return;
		}
		len--;
	}

	if('0' == num[0]) printf("1");

	return;
}
