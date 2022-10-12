/*
程序功能：将其设为开机自启动，使电脑晚10点自动关机，且晚10点至次日早5点无法开机。
适用平台：Windows
作者：段树泉
作者单位：华北电力大学
编写时间：2022/10/11 18：59
*/
#include<time.h> 
#include<stdio.h>
#include<stdlib.h>

int main()
{
    time_t timer;
    struct tm *now;
    int h, m, s, left;
    char comman[200] = "shutdown -s -t %d -c \"To prevent you from staying up late, Windows will shut down at 10 pm and won't be able to boot up again after 10 pm until 5 am tomorrow.\"";
    char command[200];


    //得到当前的时、分、秒
    timer = time(NULL);
    now = localtime(&timer);
    h = now->tm_hour;
    m = now->tm_min;
    s = now->tm_sec;
    
    //调试
    //printf("%d:%d:%d\n", h, m, s);

    //根据当前的时、分、秒，计算出距离关机的秒数left
    left = h<5 || h>=22 ? 0: 22*3600-3600*h-60*m-s;

    //根据距离关机的秒数left，生成命令command并执行
    sprintf(command,comman,left); 
    system(command);
    return 0;
}