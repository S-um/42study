
#include <stdio.h>
#include <string.h>

void plus(const char *a,const char *b, char *result);

int main(void)
{
	char a[10001];
	char b[10001];
	scanf("%s", a);
	scanf("%s", b);
	char result[10002];
	plus(a, b, result);
	printf("%s\n", result);
	return 0;
}

void plus(const char *a,const char *b, char *result)
{
	int apt = strlen(a) - 1;
	int bpt = strlen(b) - 1;
	char temp, over = 0;
	
	int rpt;
	if(apt>bpt) rpt = apt;
	else rpt = bpt;
	*(result + rpt + 1) = 0;
	
	while((apt + 1) && (bpt + 1)) {
		temp = a[apt] + b[bpt] - '0';
		if(over) temp++;
		if(temp > '9') {
			temp -= 10;
			over = 1;
		}else over = 0;
		*(result + rpt) = temp;
		rpt--;
		apt--;
		bpt--;
	}

	if(over) {
		while(apt+1) {
			if('9' == a[apt]) {
				result[rpt] = '0';
				apt--;
				rpt--;
			}else{
				result[rpt--] = a[apt--] + 1;
				over = 0;
				break;
			}
		}

		while(bpt+1) {
			if('9' == b[bpt]) {
				result[rpt] = '0';
				bpt--;
				rpt--;
			}else {
				result[rpt--] = b[bpt--] + 1;
				over = 0;
				break;
			}
		}
	}

	while(apt+1) result[rpt--] = a[apt--];
	while(bpt+1) result[rpt--] = b[bpt--];

	if(over) {
		int rsize = strlen(result);
		result[rsize + 1] = 0;
		for(int i = rsize; i > 0; --i) {
			result[i] = result[i-1];
		}
		*result = '1';
	}
	return;
}
