#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parent.h"

void parent_process(int fd1[2], int fd2[2]) {
	char input[256];
	char result[256];

	close(fd1[0]);
	close(fd2[1]);

	while (1) {
		scanf("%s", input);

		write(fd1[1], input, strlen(input) + 1);

		if (strcmp(input, "exit") == 0) {
			break;
		}

		read(fd2[0], result, 256);
		printf("%s\n", result);
	}

	close(fd1[1]);
	close(fd2[0]);
	wait(NULL);
}

