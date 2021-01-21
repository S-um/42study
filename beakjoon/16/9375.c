
#include <stdio.h>
#include <stdlib.h>

typedef struct cloth {
	char category[21];
	int cnt;
	struct cloth *next;
}cloth;

int daycount();
void addcloth(cloth *start, char *category);
int compare(char *a, char *b);
void input(char *object, char *origin);
void freecloth(cloth *ptr);

int main(void)
{
	int n, i;
	scanf("%d", &n);
	i = 0;
	while(i<n) {
		printf("%d\n", daycount());
		++i;
	}

	return 0;
}

int daycount()
{
	char temp[21];
	char category[21];
	cloth *clothptr;
	int totalClothCount, i, answer = 1;
	scanf("%d", &totalClothCount);
	if(0 == totalClothCount)
		return 0;

	scanf("%s %s", temp, category);

	cloth *start = (cloth*)malloc(sizeof(cloth));
	input(start->category, category);
	start->cnt = 1;
	start->next = NULL;

	i = 1;
	while(i<totalClothCount) {
		scanf("%s %s", temp, category);
		addcloth(start, category);
		++i;
	}

	clothptr = start;
	while(clothptr->next != NULL) {
		answer *= clothptr->cnt + 1;
		clothptr = clothptr->next;
	}
	answer *= clothptr->cnt + 1;
	--answer;

	freecloth(start);

	return answer;
}

void addcloth(cloth *start, char *category)
{
	while(start->next != NULL) {
		if(compare(start->category,category)) {
			start->cnt += 1;
			return;
		}
		start = start->next;
	}
	if(compare(start->category,category)) {
		start->cnt += 1;
		return;
	}


	start->next = (cloth*)malloc(sizeof(cloth));
	start = start->next;
	input(start->category,category);
	start->cnt = 1;
	start->next = NULL;

	return;
}

int compare(char *a, char *b)
{
	int i = 0;
	while(a[i]!=0) {
		if(a[i] != b[i]) {
			return 0;
		}
		++i;
	}
	if(b[i] == 0) {
		return 1;
	}

	return 0;
}

void input(char *object, char *origin)
{
	int i = 0;
	while(origin[i]) {
		object[i] = origin[i];
		++i;
	}
	object[i] = 0;

	return;
}

void freecloth(cloth *ptr)
{
	if(ptr->next != NULL) {
		freecloth(ptr->next);
	}
	free(ptr);

	return;
}
