#include <stdio.h>
#include <string.h>
#include "server.h"
#include "worker.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Użycie: %s [server|worker]\n", argv[0]);
		return 1;
	}

	if (strcmp(argv[1], "server") == 0) {
		server();
	} else if (strcmp(argv[1], "worker") == 0) {
		worker();
	} else {
		printf("Użyj: server lub worker\n");
		return 1;
	}

	return 0;
}
