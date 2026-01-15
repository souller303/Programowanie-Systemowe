#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "child.h"

void child_process(int fd1[2], int fd2[2]) {
	char input2[256];

	close(fd1[1]);
	close(fd2[0]);

	while (1) {
		read(fd1[0], input2, 256);

		if (strcmp(input2, "exit") == 0) {
			break;
		}

		input2[0] = 'X';
		write(fd2[1], input2, strlen(input2) + 1);
	}

	close(fd1[0]);
	close(fd2[1]);
}

