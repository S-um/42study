
#include <stdio.h>

typedef union Vector3{
	struct {
		float x;
		float y;
		float z;
	};
	float v[3];
}Vector3;

typedef struct Vector03 {
	union {
		struct {
			float x;
			float y;
			float z;
		};
		float v[3];
	};
}Vector03;

int main() {
	union Vector3 pos;
	pos.x = 1.0;
	pos.y = 2.0;
	pos.z = 3.0;

	printf("union : %lu\nstruct : %lu\n", sizeof(Vector3), sizeof(Vector03));

	return 0;
}
