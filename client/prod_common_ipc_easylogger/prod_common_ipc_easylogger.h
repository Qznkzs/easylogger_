#ifndef __PROD_COMMON_IPC_EASYLOGGER_H__
#define __PROD_COMMON_IPC_EASYLOGGER_H__

#define LOG_BUFFER_LEN    700
#define SOCKET_NAME        "/home/thd/test/elog/tmp/server" // 定义 socket 文件路径

#if defined(NEW_STANDARD)
#define ASSERT_HEAD         "A"
#define FATAL_HEAD          "F"
#define ERROR_HEAD          "E"
#define WARN_HEAD           "W"
#define INFO_HEAD           "I"
#define DEBUG_HEAD          "D"

#define log_a send_assert_log_to_server
#define log_f send_fatal_log_to_server
#define log_e send_error_log_to_server
#define log_w send_warn_log_to_server
#define log_i send_info_log_to_server
#define log_d send_debug_log_to_server

int send_assert_log_to_server(const char *original_log);
int send_fatal_log_to_server(const char *original_log);
int send_error_log_to_server(const char *original_log);
int send_warn_log_to_server(const char *original_log);
int send_info_log_to_server(const char *original_log);
int send_debug_log_to_server(const char *original_log);

#else
#define ASSERT_HEAD         "A"
#define ERROR_HEAD          "E"
#define WARN_HEAD           "W"
#define INFO_HEAD           "I"
#define DEBUG_HEAD          "D"
#define VERBOSE_HEAD        "V"

#define log_a send_assert_log_to_server
#define log_e send_error_log_to_server
#define log_w send_warn_log_to_server
#define log_i send_info_log_to_server
#define log_d send_debug_log_to_server
#define log_v send_verbose_log_to_server

int send_assert_log_to_server(const char *original_log);
int send_error_log_to_server(const char *original_log);
int send_warn_log_to_server(const char *original_log);
int send_info_log_to_server(const char *original_log);
int send_debug_log_to_server(const char *original_log);
int send_verbose_log_to_server(const char *original_log);
#endif

#endif