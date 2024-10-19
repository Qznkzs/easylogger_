#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "prod_common_ipc_easylogger.h"

int main(void)
{
    int count=0;
    char log[100] = {};
    while (1)
    {
        count++;
        memset(log, '\0', 100);
        snprintf(log, 100, "%s:%d", "client1", count);
        log_a(log);
        sleep(1);
        log_e(log);
        sleep(1);
        log_w(log);
        sleep(1);
        log_i(log);
        sleep(1);
        log_d(log);
        sleep(1);
        log_v(log);
        sleep(1);
    }
    return 0;
}
