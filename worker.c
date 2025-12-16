#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void worker() {
	char input[256];

	int in = open("/tmp/to_worker", O_RDONLY);
	int out = open("/tmp/to_server", O_WRONLY);

	while (1) {
		read(in, input, 256);
		if (strcmp(input, "exit") == 0) break;

		input[0] = 'X';
		write(out, input, strlen(input) + 1);
	}

	close(in);
	close(out);
}
