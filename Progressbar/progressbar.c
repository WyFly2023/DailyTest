#include"progressbar.h"

void Progressbar(){

    char bar[length];
    memset(bar,'\0',sizeof(bar));
    int cnt = 0;
    const char *load ="|/-\\";
    int len = strlen(load);
    printf("Loading...\n");
    while(cnt <= 100){

        printf("[%-100s][%3d%%][%c]\r",bar,cnt,load[cnt%len]);
        fflush(stdout);
        usleep(100000);

        bar[cnt++] = '#';
    }

    printf("\n");
}
