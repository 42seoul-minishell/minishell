# Minishell

---

42 서울의 과제중 하나인 Minishell을 공부하며 정리한 글.

목표는 zsh와 같은 간단한 쉘을 만드는 것.

file descriptor에 대한 지식을 많이 배우게 된다. 

---

## Readline Library

minishell 과제에서는 readline 라이브러리의 사용을 허가한다. 

### readline

```c
char	*readline(const char *);
```

입력받은 문자열을 저장하고 그 메모리 주소를 반환한다.

`EOF`를 만나면 `NULL`을 반환한다.

---

### add_history

```c
int	add_history(const char *);
```

param으로 들어온 문자열을 history로 저장한다.

프롬프트가 열린 상태에서 키보드 방향키 위 아래를 통해 이제껏 프롬프트에 입력한 문자열을 불러올 수 있다.

> Example
```c
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	while (1)
	{
		// 무한루프로 readline 함수 호출, 라인을 계속해서 입력받는다.
		str = readline("prompt : ");
		if (!str)
			break ;
		printf("str = %s\n", str);
		// history에 문자열을 저장
		add_history(str);
		// 할당된 메모리 해제
		free(str);
	}
	return (0);
}
```

스택처럼 가장 마지막 문자열부터 불러오는 방식.

---

### rl_on_new_line

```c
int	rl_on_new_line(void);
```

라인을 출력한 후 새 라인(빈 라인)으로 이동했다고 업데이트 기능에 알린다.

개행문자 출력 이후에 이용되며, 정상 수행시 0, 그렇지 않은 경우 -1을 반환한다.

---

### rl_replace_line

```c
void	rl_replace_line(const char *text, int clear_undo);
```

rl_line_buffer의 내용을 text라는 문자열로 바꾼다. 가능한 경우 포인트와 마크가 유지된다.

clear_undo는 내부적으로 유지중인 undo_list를 초기화할 지의 여부를 결정한다.

0이면 초기화하지 않고, 이외의 값이라면 초기화한다.

---

### rl_redisplay

```c
void	rl_redisplay(void);
```

현재 rl_line_buffer의 컨텐츠를 반영하여 현재 화면에 표시되는 내용을 변경한다.

사용자가 입력하지 유지중인 rl_line_buffer의 값을 프롬프트와 함께 출력한다. 

이 때 프롬프트 값은 readline 함수에 프롬프트로 준 문자열로 이동한다.

시그널을 받았을 때의 상황에서 rl_redisplay를 이용하게 된다.


> Simple example readline library

```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("prompt : ");
		if (!str)
			break ;
		rl_on_new_line();
		rl_replace_line("replace line\n", 1);
		rl_redisplay();
		printf("\n");
		add_history(str);
		free(str);
	}
	system("leaks a.out; rm -rf a.out");
	return (0);
}


>> 항상 "replace readline"을 반환
```

---

### wait

```c
#include <sys/wait.h>

pid_t	wait(int *statloc);
```

자식 process가 정상적으로 종료된 경우 pid, 실패한 경우 -1을 반환한다.

statloc의 주소를 인자로 넣어 자식 프로세스의 상태를 받을 수 있다.

---

## 기타 허용 함수

`printf`, `malloc`, `free`, `write`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `errno`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`

### waitpid

```c
#include <sys/wait.h>

pid_t	waitpid(pid_t pid, int *statloc, int options);
```

wait과 같지만 옵션과 pid를 지정하여 사용자가 원하는 대로 제어가 가능하다.

| pid value | 동작                                                              |
| --------- | ----------------------------------------------------------------- |
| pid == -1 | 임의의 child process를 기다림                                     |
| pid > 0   | process id와 일치하는 process를 기다림                            |
| pid < -1  | process group id가 pid의 절대값과 같은 child process를 기다림     |
| pid == 0  | 호출한 process의 group id와 같은 group id를 가진 process를 기다림 |

| statloc              | description                                                                                                                    |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| WIFEXITED(statloc)   | child process가 정상 종료 시 true 반환                                                                                         |
| WEXITSTATUS(statloc) | WIFEXITED가 true를 반환한 경우에만 사용 가능, 하위 8비트를 참조하여 child process가 exit, _exit, _Exit에 넘겨준 인자 값을 받음 |
| WIFSIGNALED(statloc) | signal에 의해 종료된 경우 true를 반환                                                                                          |
| WTERMSIG(statloc)    | child process를 종료시킨 signal의 숫자를  반환하며 WIFSIGNALED가 true를 반환했을 경우 사용                                     |
| ECHILD               | 호출자의 child process가 없는 경우를 나타냄                                                                                    |
| EINTR                | 시스템 콜이 인터럽트 되었을 때 사용                                                                                            |

| options    | description                                                                                                     |
| ---------- | --------------------------------------------------------------------------------------------------------------- |
| WCONTINUED | 중단되었다가 재개된 child process의 상태를 받는다                                                               |
| WNOHANG    | 기다리는 pid가 종료되지 않아 즉시 종료 상태를 회수할 수 없는 경우 호출자는 반환값으로 0을 받으며, 종료되지 않음 |
| WUNTRACED  | 중단된 자식 프로세스의 상태를 받는다                                                                            |

---

### wait3

```c
#include <sys/wait.h>

pid_t wait3(int *statloc, int options, struct rusage *rusage);
```

자식 프로세스가 종료되는 것을 기다리며, 종료된 프로세스의 상태와 자원 사용량을 알려주는 함수.

---

### wait4

```c
pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage);
```

#### rusage

child process의 리소스 사용량에 대한 정보가 담긴다. 

---

### signal

```c
#include <signal.h>

void	(*signal(int sig, void (*handler)(int)))(int);
```

특정 시그널에 대해 수행할 동작을 정의하는데 사용된다. 

시그널 함수를 통해 SIGKILL, SIGSTOP, SIGCONT 등을 제외한 특정 시그널의 처리 동작을 정의할 수 있다. 

시그널 타입에 맞는 핸들러를 설치하고 성공 시 이전 핸들러를 반환하고 실패시 SIG_ERR을 반환한다. 

설정할 수 있는 옵션은 3가지가 있다.

| 유형    | 동작                                     |
| ------- | ---------------------------------------- |
| SIG_DFL | 기존 방법을 따른다                       |
| SIG_IGN | 시그널을 무시한다                        |
| 함수    | 시그널이 발생하면 지정된 함수를 호출한다 |


| Parameter       | Description            |
| --------------- | ---------------------- |
| int sig         | 시그널 번호            |
| (*handler)(int) | 시그널을 처리할 핸들러 |
| void *()(int)   | 이전에 설정된 핸들러   |


### Example

```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	(*old_fun)( int);

void	sigint_handler( int signo)
{
	printf( "You just pressed Ctrl-C\n");
	printf( "If you press again, process will be destroyed.\n");
	signal( SIGINT, old_fun);   // 또는 signal( SIGINT, SIG_DFL);
}

int	main( void)
{
	old_fun = signal(SIGINT, sigint_handler);
	while(1)
	{
		printf("signal check...\n");
		sleep(1);
	}
}

>> signal check...
>> signal check...
>> ^CYou just pressed Ctrl-C
>> If you press again, process will be destroyed.
>> signal check...
>> signal check...
>> ^C
```

---

### unlink

```c
#include <unistd.h>

int	unlink(const char *path);
```

하드링크를 끊는데 이용한다. 하드링크의 이름을 삭제하면 `inode`를 참조하고 있는 하나의 하드링크를 끊어 링크의 개수를 하나 줄인다. 

path에 명시된 하드링크는 삭제가 되지만 해당 `inode`를 참조하고 있는 모든 하드 링크가 지워지는 것은 아니기 때문에 그 파일의 하드링크가 여러 개라면 여전히 그 파일은 존재하게 된다. 

정상적으로 하드링크를 끊으면 0, 그렇지 않으면 -1을 반환한다. 

하드링크의 참조 개수가 0이 되면 실제 파일의 내용이 저장되어 있는 disk space를 free하여 OS가 다른 파일을 위해서 사용할 수 있도록 한다. 

---

### execve

```c
#include <unistd.h>

int	execve(const char *file, char const *args, char const *envp[]);
```

인자로 받은 파일에 대해서 실행하고 정상 동작할 경우 0, 문제가 발생할 경우 -1을 반환한다. 

---

### dup

```c
#include <unistd.h>

int	dup(int fd);
```

fd를 받아서 복제한다. 정상적으로 복제할 경우 fd값, 그렇지 않은 경우 -1 반환.

---

### dup2

```c
#include <unistd.h>

int dup2(int fd, int fd2);
```

dup2와 dup은 동작하는 방식이 동일하다. 다만 반환값을 사용자가 사용하는 fd2라는 값이 나올 수 있도록 fd라는 인자를 사용하여 복제를 수행한다.

정상 동작의 경우 fd2가 fd가 가리키는 `file descriptor를` 가리키게 된다. 문제가 발생할 경우 -1 반환.

---

### pipe

```c
#include <unistd.h>

int	pipe(int fd[2]);
```

서로 독립된 프로세스들이 데이터를 주고받을 수 있도록 한다. 

하나의 파이프 및 파이프에 대한 두 개의 fd가 생성되며, 하나의 파이프를 프로세스끼리 공유한다. 

파이프 자체는 `fork()`를 하더라도 복사되지 않으며, 방향성이 없다. 

#### fd[2]

크기가 2인 int형 배열. fd[0]은 데이터를 입력받을 수 있는 fd가 담긴다. fd[1]에는 데이터를 출력할 수 있는 fd가 담긴다.

> fd[0] = read, fd[1] = write

---

### opendir

```c
#include <dirent.h>

DIR	*opendir(const char *name);
```

지정한 디렉토리 스트림을 연다. 

특정 디렉토리 안에 있는 파일과 디렉토리를 검색하기 위해 사용. 

정상적으로 리턴된 DIR 포인터를 가지고 `readdir()`과 `closedir()`을 사용.

디렉토리 열기에 성공하면 디렉토리 정보 구조체 포인터를 반환하고 실패하면 NULL을 반환.

---

### readdir

```c
#include <dirent.h>

struct dirent *readdir(DIR *dirp);
```

`opendir()`로 얻은 디렉토리 포인터를 통해서 정보를 차례대로 읽는다. 

연속된 `readdir()`을 호출할 때는 그 리턴 포인터를 반드시 확인해야 한다.

---

### closedir

DIR 포인터를 통해 디렉토리 스트림을 닫는다.

```c
#include <dirent.h>

int closedir (DIR *dirstream);
```

정상적으로 종료될 경우 0을 그렇지 않은 경우 -1을 반환.

---

### strerror

```c
#include <string.h>

char* strerror(int errnum);
```

오류 메시지 문자열을 가리키는 포인터를 얻는다.

errnum 값을 통해 발생했던 오류에 맞는 오류 메시지를 가리키는 포인터를 반환한다. 

출력되는 오류 메시지의 경우 컴파일러나 플랫폼에 따라 달라질 수 있다.

---

### errno

```c
#include <errno.h>

extern int errno;
```

에러 발생시 값을 바꾸어 해당 에러 메시지를 가진다.

---

### isatty

```c
#include <unistd.h>

int isatty(int desc);
```

파일 지정자가 터미널을 사용하는지 검사한다. 

터미널에 연결되어 있으면 1, 그렇지 않으면 0을 반환한다. 

---

### ttyname

```c
#include <unistd.h>

char *ttyname(int desc);
```

터미널 이름을 반환한다. 

desc가 터미널을 참조하고 있다면 해당 터미널의 경로를 문자열로 반환하며, 그렇지 않을 경우 NULL을 반환한다. 

static 형태로 할당되어 있어 덮어쓰기가 가능하며, 별도의 free()가 필요없다.

---

### ttyslot

```c
#include <unistd.h>

int	ttyslot(void);
```

터미널에 대한 DB의 entry index를 반환한다. 

문제가 생길 경우 이용하고 있는 시스템에 따라 0 또는 -1이 반환된다.

---

### ioctl

```c
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ... );
```

전형적인 운영체제는 2계층으로 나뉜다. User Space(사용자 모드)와 Kernel Space(커널 모드).

User Space에 상주하는 Application이 Kernel Space에 존재하는 자원을 사용하고자 할 땐 시스템 콜을 이용한다. 

> System Call Function은 내부적으로 System Call Vector와 대응된다. 
> 예를 들면, `exit()` 함수는 System Call Vector Number : 1, `write()`함수는 System Call Vector Number 4 와 같다. 

전형적인 운영체제의 커널은 수 백개의 System Call Vector를 제공한다. 

`ioctl()` 시스템 콜은 device driver와 통신하기 위한 함수이다. 

> What is `device driver`? 
> 하드웨어 주변 장치는 커널 안에 직접적으로 주소 지정을 할 수 있다. 
> 응용 프로그램이 장치와 통신하길 원할 수 있다. (하드웨어 장치의 기능을 사용하고 싶을 때)
> 그런데 커널 개발자는 어떤 장치가 커널 안에 주소를 할당받을지, 그 장치에는 어떤 기능이 있는지 알 수가 없다. 
> 따라서 확장가능한 모듈식으로 커널을 유연하게 설계할 필요가 있었고, 그렇게 해서 나온게 device driver이다. 
> 즉, 어떠한 장치가 연결될 지 모르는 상황에서 device driver라는 하나의 중간 계층을 둠으로써 문제를 해결할 수 있다. 

`ioctl()`함수는 장치에게 요청을 보낼 때 사용되는 함수이며, 시스템 콜이다. 

`int fd`는 장치를 참조하는 fd로써, open을 통해 얻는 fd가 된다. (O_NONBLOCK flag 이용 권장)

`unsigned long request`는 fd에 해당하는 장치에게 보낼 명령이다. 이 명령에 따라서 디바이스를 컨트롤 할 수 있다. 

사용자 정의하에 이용되는 경우에는 ioctl 함수의 반환값을 이용할 수도 있다. 

일반적으로 함수 호출 시 마지막 인자에는 `char *`타입을 이용한다. 

정상 작동시 0, 그렇지 않을 경우 -1을 반환한다. 

---

### getenv

```c
#include <stdib.h>

char	*getenv(const char *name);
```

`name`에 해당하는 환경 변수의 값에 대한 문자열을 반환한다. 

환경 변수에 해당하는 값을 찾지 못하거나 문제가 생겼을 경우 NULL을 반환한다. 

---

### tcsetattr

```c
#inlcude <termios.h>

int tcsetattr(int fd, int action, const struct termios *t);
```

file descriptor를 인자로 받는다. 

함수 수행에 성공하면 0, 그렇지 않으면 -1을 반환한다. 

---

### tcgetattr

```c
#include <termios.h>

int tcgetattr(int fildes, struct termios *termios_p);
```

기록할 termios 구조체를 포인터 타입으로 할당한다. 함수 수행에 성공하면 0, 그렇지 않으면 -1을 반환한다. 

---

### tgetent

```c
#include <termios.h>

int tgetent(char *bp, const char *name);
```

`TermCap`의 쿼리를 수행할 수 있도록 만드는 루틴이다. 일반적으로 name에 할당하는 값은 TERM 환경변수로 할당된 터미널 타입을 이용한다. 

함수 수행에 성공하면 1, DB가 발견되었지만 TERM을 위한 개체가 없는 경우 0, 그 외에는 -1을 반환.

> What is `TermCap` ?  
> Termcap은 Unix 계열 컴퓨터에서 사용되는 소프트웨어 라이브러리 및 데이터베이스이다.
> minishell에서 반드시 한 번쯤은 공부하고 넘어가야 하는 개념!

---

### tgetflag

```c
#include <termios.h>

int tgetflag(char *id);
```

쿼리로 사용할 이름을 인자로 받는다. 플래그를 얻을 수 있는 쿼리의 경우 1, 그렇지 않은 경우 0을 반환한다. 

---

### tgetnum

```c
#include <termios.h>

int tgetnum(char *id);
```

쿼리로 사용할 이름을 인자로 받는다. 

함수 수행에 성공하면 그 값을 반환하고 그렇지 않으면 -1을 반환한다. 

---

### tgetstr

```c
#include <termios.h>

char *tgetstr(char *id, char **area);
```

쿼리로 사용할 이름을 인자로 받는다. 

쿼리에 해당하는 `Escape Sequence`를 얻을 수 있다면 그 값을 반환하고 그렇지 않은 경우 NULL을 반환한다. 

---

### tgoto

```c
#include <termios.h>

char *tgoto(const char *cap, int col, int row);
```

매개변수를 지정된 기능으로 인스턴스화한다. 출력은 `tputs`로 전달된다. 

`col`과 `row`를 고려한 `Cursor Motion`의 `Escape Sequence`를 반환한다. 함수 수행에 실패하면 NULL을 반환한다.

---

### tputs

```c
#include <termios.h>

int tputs(const char *str, int affcnt, int (*putc)(int));
```


`Escape Sequence`에 대한 터미널 출력 결과를 내는 루틴이다. 

`tgetstr` 또는 `tgoto`를 통해 얻은 값을 `str`인자로 받는다. 

`affcnt`의 경우 영향을 끼칠 줄의 수를 나타나는데, 1로 주는 것이 일반적. 

`putc`는 ASCII 문자 값을 인자로 받아 표준 출력의 쓰기 작업으로 터미널에 ASCII 문자 값을 출력해주는 함수.

---

### getcwd

```c
#include <unistd.h>

char	*getcwd(char *buf, size_t size);
```

현재 작업 디렉토리 경로를 문자열로 가져온다. 

경로가 저장되는 buf를 인자로 받고, buf는 NULL문자를 포함하며 기록이 성공적이면 buf의 주소를 반환한다.

buf에 NULL을 인자로 할 경우 size만큼의 크기로 malloc 후 해당 공간의 주소를 반환한다. 

이 경우 동적 할당 받은 공간에 대해서 사용자가 직접 free를 호출해야 한다.

문제가 발생할 경우 NULL이 반환되며 errno에 상세 오류 내용이 저장된다.

---

### chdir

```c
#include <unistd.h>

int chdir(const char * path);
```

현재 작업 디렉토리를 변경한다.

---

### stat

```c
#include <sys/stat.h>

int	stat(const char *path, struct stat *buf);
```

파일의 크기, 파일의 권한, 파일의 생성일시, 파일의 최종 변경일 등, 파일의 상태나 파일의 정보를 얻는 함수.

한 마디로 파일의 상태를 가져온다. 절대 경로 path를 인자로 받으며, path가 가리키는 파일을 통계하고 buf를 채운다. 

함수 실행 성공 시 0, 그렇지 않은 경우 -1 반환.

> Example

```c
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct stat sb;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        return 1;
    }

    printf("File type:                ");

    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");            break;
        case S_IFCHR:  printf("character device\n");        break;
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFIFO:  printf("FIFO/pipe\n");               break;
        case S_IFLNK:  printf("symlink\n");                 break;
        case S_IFREG:  printf("regular file\n");            break;
        case S_IFSOCK: printf("socket\n");                  break;
        default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", (long) sb.st_ino);
    printf("Mode:                     %lo (octal)\n", (unsigned long) sb.st_mode);
    printf("Link count:               %ld\n", (long) sb.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n", (long) sb.st_uid, (long) sb.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",         (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",        (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",              (long long) sb.st_blocks);
    printf("Last status change:       %s", ctime(&sb.st_ctime));
    printf("Last file access:         %s", ctime(&sb.st_atime));
    printf("Last file modification:   %s", ctime(&sb.st_mtime));

    return 0;
}

>> File type:                regular file
>> I-node number:            4579628
>> Mode:                     100644 (octal)
>> Link count:               1
>> Ownership:                UID=103967   GID=4222
>> Preferred I/O block size: 4096 bytes
>> File size:                2660 bytes
>> Blocks allocated:         8
>> Last status change:       Tue Oct  4 16:52:32 2022
>> Last file access:         Tue Oct  4 16:52:38 2022
>> Last file modification:   Tue Oct  4 16:52:32 2022
```

---

### lstat

```c
#include <sys/stat.h>

int	lstat(const char * path, struct stat *buf);
```

파일 상태(정보)를 가져온다. 절대 경로 path를 인자로 넘겨주며, 경로가 심볼릭 링크인 경우 링크가 참조하는 파일이 아닌 링크 파일에 대한 정보로 buf를 채운다.

함수 실행 성공 시 0, 그렇지 않은 경우 -1을 반환.

---

### fstat

```c
#include <sys/stat.h>

int	fstat(int fd, struct stat *buf);
```

파일 상태(정보)를 가져온다. fd가 가리키는 파일을 통계하고 buf를 채운다.

함수 실행 성공 시 0, 그렇지 않은 경우 -1을 반환.


