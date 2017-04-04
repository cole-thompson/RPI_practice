#include <stdio.h>
#include "hbridge.h"

int main(int argc, char*argv[]) {
	initHbridge();

	rotate(0, 10, 1);
	for (int i = 0; i < 100000; i++) {}
	stop(0);

}
