#include <stdio.h>
#include <stdarg.h>

#include <libretro.h>


static retro_log_printf_t logging_cb;

static void retromac_logger_init(retro_environment_t cb)
{
   struct retro_log_callback logging;

   if (cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &logging))
      logging_cb = logging.log;
   else
      logging_cb = retromac_fallback_logger;
}

void retromac_logger(enum retro_log_level level, const char *fmt, ...)
{
   logging_cb(level,fmt);
}


void retromac_fallback_logger(enum retro_log_level level, const char *fmt, ...)
{
   (void)level;
   va_list va;
   va_start(va, fmt);
   vfprintf(stderr, fmt, va);
   va_end(va);
}