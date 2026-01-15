#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
	char input[256];
	int fd[2];
	char input2[256];
	pipe(fd);
	pid_t id = fork();
	
	if (id > 0) {
		close(fd[0]);
		scanf("%s", input);
		write(fd[1], input, strlen(input)+1);
		close(fd[1]);
		wait(NULL);
	}
	
	if (id == 0) {
		close(fd[1]);
		read(fd[0], input2, 256);
		close(fd[0]);

		input2[0] = 'X';

		printf("%s", input2);
	}

	return 0;
}
