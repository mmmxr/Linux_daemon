#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
void mydaemon()
{
    int i=0;
    pid_t id;
    //1.屏蔽字设为0
    umask(0);
    //2.调用fork，父进程退出
    id=fork();
    if(id>0)
    {
        exit(0);
    }
    //3.调用 setsid函数创建新会话
    setsid();
    //4.忽略SIGCHLD信号
    signal(SIGCHLD,SIG_IGN);
    //5.更改工作目录
    chdir("/");
    //6.关闭文件描述符
    close(0);
    close(1);
    close(2);
}
int main()
{
    mydaemon();
    while(1)
    {
        sleep(1);
    }
}

