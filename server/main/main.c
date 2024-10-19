/*
 * This file is part of the EasyLogger Library.
 *
 * Copyright (c) 2015-2017, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: linux demo.
 * Created on: 2015-07-30
 */

#define LOG_TAG    "main"

#include <elog.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_NAME        "/home/thd/test/elog/tmp/server" // 定义 socket 文件路径

static void init_easylogger(void);
static int init_socket(void);
static int parse_msg(char *buf, const char *src);
static void test_elog(void);
int isContinue = 1;

int main(void)
{
    int ret;
    int sockfd;
    int connect_sockfd;
    char recv_buffer[800];
    char msg_buffer[700];
    init_easylogger();
    sockfd = init_socket();
    if (sockfd < 0)
    {
        return -1;
    }
    while(isContinue)
    {
	    printf("server waiting for connection...\n");
        // 接收客户端连接
        connect_sockfd = accept(sockfd, NULL, NULL);
        if (connect_sockfd == -1)
        {
            continue;
        }
        memset(recv_buffer, '\0', 800);
        memset(msg_buffer, '\0', 700);
        ret = read(connect_sockfd, recv_buffer, 800);
        if (ret < 1)
        {
            close(connect_sockfd);
            continue;
        }
        parse_msg(msg_buffer, recv_buffer);
        switch (recv_buffer[0])
        {
            case 'A':
                log_a(msg_buffer);
                break;
            case 'E':
                log_e(msg_buffer);
                break;
            case 'W':
                log_w(msg_buffer);
                break;
            case 'I':
                log_i(msg_buffer);
                break;
            case 'D':
                log_d(msg_buffer);
                break;
            case 'V':
                log_v(msg_buffer);
        }
        close(connect_sockfd);
    }
    close(sockfd);
    return EXIT_SUCCESS;
}

void init_easylogger(void)
{
    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();

    /* dynamic set enable or disable for output logs (true or false) */
//    elog_set_output_enabled(false);
    /* dynamic set output logs's level (from ELOG_LVL_ASSERT to ELOG_LVL_VERBOSE) */
//    elog_set_filter_lvl(ELOG_LVL_WARN);
    /* dynamic set output logs's filter for tag */
//    elog_set_filter_tag("main");
    /* dynamic set output logs's filter for keyword */
//    elog_set_filter_kw("Hello");
    /* dynamic set output logs's tag filter */
//    elog_set_filter_tag_lvl("main", ELOG_LVL_WARN);

    /* test logger output */
}

int init_socket(void)
{
    struct sockaddr_un name;
    int ret;
    // 创建 socket
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd == -1) 
    {
        return -1;
    }

    // 删除 socket 文件，以防止程序异常退出导致文件未删除
    unlink(SOCKET_NAME);

    // 设置 socket 地址
    memset(&name, 0, sizeof(struct sockaddr_un));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);

    // 绑定 socket
    ret = bind(sockfd, (const struct sockaddr *) &name, sizeof(struct sockaddr_un));
    if (ret == -1) 
    {
        return -2;
    }

    // 监听 socket
    ret = listen(sockfd, 20);
    if (ret == -1)
    {
        return -3;
    }
    
    return sockfd;
}

int parse_msg(char *buf, const char *src)
{
    int ret = 0;
    if (NULL == src || NULL == buf)
    {
        return -1;
    }
    strncpy(buf, src + 2, 700 - 1);
    return ret;
}

/**
 * EasyLogger demo
 */
void test_elog(void) {
    uint8_t buf[256]= {0};
    int i = 0;

    for (i = 0; i < sizeof(buf); i++)
    {
        buf[i] = i;
    }
    while(true) {
        /* test log output for all level */
        log_a("Hello EasyLogger!");
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");
//        elog_raw("Hello EasyLogger!");
        elog_hexdump("test", 16, buf, sizeof(buf));
        sleep(5);
    }
}
