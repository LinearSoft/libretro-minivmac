#ifndef RETROMAC_OPTIONS_H__
#define RETROMAC_OPTIONS_H__ 1

#include <libretro.h>

#define RETROMAC_OPTIONCAT_SYSTEM   "system"
#define RETROMAC_OPTIONCAT_INPUT    "input"
#define RETROMAC_OPTIONCAT_PRAM     "pram"

enum RetroMac_Option_Index
{
   //System
   model,
   cpuspeed,
   autoslow,
   happymac,
   // Input
   automap,
   // PRAM
   doubleclick
};

void retromac_set_core_options(retro_environment_t environ_cb, bool *categories_supported);

#endif