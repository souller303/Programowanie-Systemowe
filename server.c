#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void server() {
	char input[256];
	char result[256];

	mkfifo("/tmp/to_worker", 0666);
	mkfifo("/tmp/to_server", 0666);

	int out = open("/tmp/to_worker", O_WRONLY);
	int in = open("/tmp/to_server", O_RDONLY);

	while (1) {
		scanf("%s", input);
		write(out, input, strlen(input) + 1);

		if (strcmp(input, "exit") == 0) break;

		read(in, result, 256);
		printf("%s\n", result);
	}

	close(out);
	close(in);
	unlink("/tmp/to_worker");
	unlink("/tmp/to_server");
}
