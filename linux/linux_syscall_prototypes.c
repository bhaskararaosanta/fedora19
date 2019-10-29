
/* File operational syscalls */
int open(const char *pathname, int flags, mode_t mode);

ssize_t write(int fd, const void *buf, size_t count);

ssize_t read(int fd, void *buf, size_t count);

int fstat(int fd, struct stat *mystat);

int stat(const char *pathname, struct stat *statbuf);

int lstat(const char *pathname, struct stat *statbuf);

int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags);

int close(int fd);

/* exec group system calls */
extern char **environ;

int execl(const char *path, const char *arg, ... /* (char *) NULL */);

int execlp(const char *file, const char *arg, ... /* (char *) NULL */);

int execle(const char *path, const char *arg, ... /* (char *) NULL, char *const envp[] */);

int execv(const char *path, char *const argv[]);

int execvp(const char *file, char *const argv[]);

int execvpe(const char *file, char *const argv[], char *const envp[]);

/* fork and pipe system calls */
pid_t fork(void);

pid_t vfork(void);

int clone(int (*fn), void *child_stack, int flags, void *arg, ...);

int pipe(int pipefd[2]);

/* shared memory system calls */
key_t ftok(const char *pathname, int proj_id);

int shmget(key_t key, int shmsz, int shmflg);

void *shmat(int shmid, const void *shmaddr, int shmflg);

int shmdt(const void *shmaddr);

int shmctl(int shmid, int cmd, struct shmid_ds *buf);

/* message queue system calls */
key_t ftok(const char *pathname, int proj_id);

int msgget(key_t key, int msgflg);

int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg);

ssize_t msgrcv(int msgid, void *msgp, size_t msgsz, long msgtyp, int msgflg);

int msgctl(int msgid, int cmd, struct msqid_ds *buf);

/* semaphore system calls */
key_t ftok(const char *pathname, int proj_id);

int semget(key_t key, int nsems, int semflg);

int semop(int semid, struct sembuf *sops, size_t nsops);

int semctl(int semid, int semnum, int cmd, ...);

/* memory map system call */
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int mprotect(void *addr, size_t len, int prot);

int munmap(void *addr, size_t length);




