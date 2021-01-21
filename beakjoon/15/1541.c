
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char s[51] = {0,};
	scanf("%s", s);
	int i = 0, numindex = 0, flag = 0, answer = 0;
	int num[26] = {0,};
	while(s[i]) {	//입력된 문장 반복
		while(s[i] && '0'<=s[i] && s[i]<='9') {  //부호가 나오기 전까지 반복
			num[numindex] *= 10;
			num[numindex] += s[i]-'0';
			++i;
		}
		if(flag) { //만약 이전에 -가 나왔다면 무조건 음수로 만들어주기
			num[numindex] *= -1;
			++numindex;
			++i;
			continue;
		}
		if(s[i] == '-') { //-가 처음 나왔다는건 그직전까지는 양수라는 의미
			flag = 1;
		}
		++i; //다음 숫자로 넘어가기
		++numindex;
	}

	i = 0;
	while(i<numindex) {
		answer += num[i];
		++i;
	}
	printf("%d\n", answer);

	return 0;
}
