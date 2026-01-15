#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include "parent.h"
#include "child.h"

int main() {
	int fd1[2];
	int fd2[2];

	pipe(fd1);
	pipe(fd2);

	pid_t id = fork();

	if (id > 0) {
		parent_process(fd1, fd2);
	} else {
		child_process(fd1, fd2);
	}

	return 0;
}
