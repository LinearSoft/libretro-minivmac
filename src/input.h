#ifndef RETROMAC_INPUT_H__
#define RETROMAC_INPUT_H__ 1

#include <libretro.h>

/*
 * Always two ports but defined for consistency
*/
#define RETROMAC_MAPPER_MAX_PORTS 2

#define RETROMAC_MAPPER_DEVICE_AUTO          RETRO_DEVICE_JOYPAD
#define RETROMAC_MAPPER_DEVICE_MOUSELEFT     RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_ANALOG, 0)
#define RETROMAC_MAPPER_DEVICE_MOUSERIGHT    RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_ANALOG, 1)
#define RETROMAC_MAPPER_DEVICE_KEYLEFT       RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_KEYBOARD, 0)
#define RETROMAC_MAPPER_DEVICE_KEYRIGHT      RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_KEYBOARD, 1)
#define RETROMAC_MAPPER_DEVICE_KEYONLY       RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_KEYBOARD, 2)
#define RETROMAC_MAPPER_DEVICE_NONE          RETRO_DEVICE_NONE

void retromac_mapper_init(retro_environment_t cb);

void retromac_keyboard_init(retro_environment_t cb);


extern retro_input_poll_t retro_input_poll_cb;
extern retro_input_state_t retro_input_state_cb;









#endif