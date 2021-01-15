
#include <stdio.h>
#include <stdlib.h>

char* solution(int a, int b);

int main(void)
{
	char month, date;
	scanf("%hhd %hhd", &month, &date);

	char *day = solution(month, date);
	printf("%s\n", day);

	return 0;
}

char* solution(int a, int b) {
	char *answer = (char *)malloc(sizeof(char) * 4);
	char daysofMonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	short dayCount = 0;

	for(int i = 0; i < a - 1; ++i) {
		dayCount += daysofMonth[i];
	}
	dayCount += b;
	
	dayCount %= 7;

	switch (dayCount) {
		case 0:
			answer = "THU";
			break;
		case 1:
			answer = "FRI";
			break;
		case 2:
			answer = "SAT";
			break;
		case 3:
			answer = "SUN";
			break;
		case 4:
			answer = "MON";
			break;
		case 5:
			answer = "TUE";
			break;
		case 6:
			answer = "WED";
			break;
		default:
			answer = "ERR";
			break;
	}

	return answer;
}
