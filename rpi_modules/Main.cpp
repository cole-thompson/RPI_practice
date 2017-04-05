#include <stdio.h>
#include "hbridge.h"

int main(int argc, char*argv[]) {
	initHbridge();

	rotate(0, 1);
	setSpeed(0, 10);
	for (int i = 0; i < 100000; i++) {}
	stop(0);

}
