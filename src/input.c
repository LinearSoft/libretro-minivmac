#include <libretro.h>

#include "input.h"
#include "minivmac/osglue_keyboard.h"

// Faster than allocating and freeing membory
static char automatic_desc[128];


static struct retro_controller_description primary_controller[] =
{
   { automatic_desc, RETROMAC_MAPPER_DEVICE_AUTO },
   { "Mouse w/ Left Analog", RETROMAC_MAPPER_DEVICE_MOUSELEFT },
   { "Mouse w/ Right Analog", RETROMAC_MAPPER_DEVICE_MOUSERIGHT },
   { "Custom Keyboard + Mouse w/ Left Analog", RETROMAC_MAPPER_DEVICE_KEYLEFT },
   { "Custom Keyboard + Mouse w/ Right Analog", RETROMAC_MAPPER_DEVICE_KEYRIGHT },
   { "None", RETROMAC_MAPPER_DEVICE_NONE },
   { NULL, 0 }
};

static struct retro_controller_description secondary_controller[] =
{
   { automatic_desc, RETROMAC_MAPPER_DEVICE_AUTO },
   { "Keyboard Only", RETROMAC_MAPPER_DEVICE_KEYONLY },
   { "None", RETROMAC_MAPPER_DEVICE_NONE },
   { NULL, 0 }
};


// Load custom mappings
void retromac_mapper_init(retro_environment_t cb)
{
   // To be safe initialized first entry back to Automatic
   strcopy(automatic_desc, "Automatic");


}

// Check auto mappings
void retromac_mapper_load_game()
{

}



void retromac_keyboard_init(retro_environment_t cb)
{
   static struct retro_keyboard_callback keyboard_callback = { retromac_keyboard_event };
   environ_cb(RETRO_ENVIRONMENT_SET_KEYBOARD_CALLBACK, &keyboard_callback);
}

void retromac_keyboard_event(bool down, unsigned code, uint32_t character, uint16_t mod)
{
   // TODO: Handle swaping of ctrl (also may need to pass modifier to catch stuck keydowns)
   OSGlue_KeyEvent(down, code);

}

// No mouse init (RETRO_DEVICE_MOUSE just poll the device)





