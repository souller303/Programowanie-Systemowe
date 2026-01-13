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

void worker() {
	int fd = shm_open("/shm", O_RDWR, 0666);
	mem_t *m = mmap(0, sizeof(mem_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	while (1) {
		sem_wait(&m->sem_worker);
		
		if (strcmp(m->data, "exit") == 0) {
			sem_post(&m->sem_server);
			break;
		}

		m->data[0] = 'X';
		sem_post(&m->sem_server);
	}

	munmap(m, sizeof(mem_t));
	close(fd);
}
