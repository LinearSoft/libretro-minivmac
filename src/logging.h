#ifndef RETROMAC_LOGGING_H
#define RETROMAC_LOGGING_H 1

#include <libretro.h>

void retromac_logger_init(retro_environment_t cb);
void retromac_logger(enum retro_log_level level, const char *fmt, ...);

#endif