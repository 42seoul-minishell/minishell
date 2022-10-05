#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signal)
{
    if (signal == SIGINT)
        printf("minishell$ \n");
    if (rl_on_new_line() == -1) // 개행 출력 후 새(빈) 줄로 이동, 오류 발생 시 -1 반환하므로 이때 exit(1)
        exit(1);
    rl_replace_line("", 1); // 프롬프트에 이미 입력한 문자열을 삭제
    rl_redisplay();         // readline 함수의 인자로 넣은 문자열을 다시 출력
}

void setting_signal()
{
    signal(SIGINT, sig_handler);  // CTRL + C
    signal(SIGQUIT, sig_handler); // CTRL + /
}

int main(int argc, char **argv, char **envp)
{
    int     i;
    char *str;

    printf("%d %s\n", argc, argv[0]);
    i = 0;
    while (envp[i])
    {
        printf("%s\n", envp[i]);
        i++;
    }
    setting_signal();
    while (1)
    {
        str = readline("minishell$ ");
        if (!str) // CTRL + D(EOF)
        {
            printf("\033[1A"); // 커서를 위로 한 줄 이동
            printf("\033[10C"); // 커서를 10만큼 앞으로 전진
            printf(" exit\n");
            exit(-1);
        }
        add_history(str);
        printf("str : %s\n", str);
        free(str);
    }
    return (0);
}