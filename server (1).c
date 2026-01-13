#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>

typedef struct {
	char data[256];
	sem_t sem_server;
	sem_t sem_worker;
} mem_t;

void server() {
	char input[256];
	
	shm_unlink("/shm");
	int fd = shm_open("/shm", O_CREAT | O_RDWR, 0666);
	ftruncate(fd, sizeof(mem_t));
	mem_t *m = mmap(0, sizeof(mem_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	
	sem_init(&m->sem_server, 1, 1);
	sem_init(&m->sem_worker, 1, 0);

	while (1) {
		scanf("%s", input);
		
		sem_wait(&m->sem_server);
		strcpy(m->data, input);
		sem_post(&m->sem_worker);

		if (strcmp(input, "exit") == 0) break;

		sem_wait(&m->sem_server);
		printf("%s\n", m->data);
		sem_post(&m->sem_worker);
	}

	sem_destroy(&m->sem_server);
	sem_destroy(&m->sem_worker);
	munmap(m, sizeof(mem_t));
	close(fd);
	shm_unlink("/shm");
}
