#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "prod_common_ipc_easylogger.h"

static int sockfd;
/*
*函数功能：
*                                获取unix socket文件描述符并连接到服务器
*入参：
*                                sockfd：文件描述符指针
*                                log：日志信息字符串
*返回值：
*                                反馈代码：
*                                  0——操作成功
*                                -1——获取文件描述符失败
*                                -2——连接服务器失败
*                                  
*/
static int send_log_to_server(const char *log)
{
    int ret = 0;
    struct sockaddr_un addr;

    //创建socket
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        return -1;
    }
    //设置socket服务器地址
    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

    //连接服务器
    ret = connect(sockfd, (const struct sockaddr *) &addr, sizeof(struct sockaddr_un));
    if (ret == -1)
    {
        return -2;
    }

    //发送信息
    write(sockfd, log, strlen(log)); // 注意这里的log是个指针不是数组名，sizeof(log) == 4

    //关闭连接
    close(sockfd);
    return 0;
}

#if defined(NEW_STANDARD)
int send_assert_log_to_server(const char *original_log)
{
    int ret = 0;
    char assert_log[LOG_BUFFER_LEN] = {0};
    memset(assert_log, '\0', LOG_BUFFER_LEN);
    snprintf(assert_log, LOG_BUFFER_LEN-1, "%s,%s", ASSERT_HEAD, original_log);
    ret = send_log_to_server(assert_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }

}

int send_fatal_log_to_server(const char *original_log)
{
    int ret = 0;
    char fatal_log[LOG_BUFFER_LEN] = {0};
    snprintf(fatal_log, LOG_BUFFER_LEN, "%s,%s", FATAL_HEAD, original_log);
    ret = send_log_to_server(fatal_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_error_log_to_server(const char *original_log)
{
    int ret = 0;
    char error_log[LOG_BUFFER_LEN] = {0};
    snprintf(error_log, LOG_BUFFER_LEN, "%s,%s", ERROR_HEAD, original_log);
    ret = send_log_to_server(error_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_warn_log_to_server(const char *original_log)
{
    int ret = 0;
    char warn_log[LOG_BUFFER_LEN] = {0};
    snprintf(warn_log, LOG_BUFFER_LEN, "%s,%s", WARN_HEAD, original_log);
    ret = send_log_to_server(warn_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_info_log_to_server(const char *original_log)
{
    int ret = 0;
    char info_log[LOG_BUFFER_LEN] = {0};
    snprintf(info_log, LOG_BUFFER_LEN, "%s,%s", INFO_HEAD, original_log);
    ret = send_log_to_server(info_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_debug_log_to_server(const char *original_log)
{
    int ret = 0;
    char debug_log[LOG_BUFFER_LEN] = {0};
    snprintf(debug_log, LOG_BUFFER_LEN, "%s,%s", DEBUG_HEAD, original_log);
    ret = send_log_to_server(debug_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

#else
int send_assert_log_to_server(const char *original_log)
{
    int ret = 0;
    char assert_log[LOG_BUFFER_LEN] = {0};
    memset(assert_log, '\0', LOG_BUFFER_LEN);
    snprintf(assert_log, LOG_BUFFER_LEN-1, "%s,%s", ASSERT_HEAD, original_log);
    ret = send_log_to_server(assert_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }

}

int send_error_log_to_server(const char *original_log)
{
    int ret = 0;
    char error_log[LOG_BUFFER_LEN] = {0};
    snprintf(error_log, LOG_BUFFER_LEN, "%s,%s", ERROR_HEAD, original_log);
    ret = send_log_to_server(error_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_warn_log_to_server(const char *original_log)
{
    int ret = 0;
    char warn_log[LOG_BUFFER_LEN] = {0};
    snprintf(warn_log, LOG_BUFFER_LEN, "%s,%s", WARN_HEAD, original_log);
    ret = send_log_to_server(warn_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_info_log_to_server(const char *original_log)
{
    int ret = 0;
    char info_log[LOG_BUFFER_LEN] = {0};
    snprintf(info_log, LOG_BUFFER_LEN, "%s,%s", INFO_HEAD, original_log);
    ret = send_log_to_server(info_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_debug_log_to_server(const char *original_log)
{
    int ret = 0;
    char debug_log[LOG_BUFFER_LEN] = {0};
    snprintf(debug_log, LOG_BUFFER_LEN, "%s,%s", DEBUG_HEAD, original_log);
    ret = send_log_to_server(debug_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

int send_verbose_log_to_server(const char *original_log)
{
    int ret = 0;
    char verbose_log[LOG_BUFFER_LEN] = {0};
    snprintf(verbose_log, LOG_BUFFER_LEN, "%s,%s", VERBOSE_HEAD, original_log);
    ret = send_log_to_server(verbose_log);
    switch (ret)
    {
        case 0:
            //printf("Send log successfully!");
            break;
        case -1:
            //printf("Create socket fail!");
            break;
        case -2:
            //printf("Connet to server fail!");
            break;
        default:
            //printf("Unkown!");
            break;
    }
    return ret;
}

#endif
