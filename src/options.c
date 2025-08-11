#include <stdlib.h>
#include <string.h>

#include <libretro.h>
#include <retro_inline.h>

#include "options.h"
#ifndef HAVE_NO_LANGEXTRA
#include "options_intl.h"
#endif

struct retro_core_option_v2_category option_cats_us[] = {
   {
      RETROMAC_OPTIONCAT_SYSTEM,
      "System",
      "Configure system options."
   },
   {
      RETROMAC_OPTIONCAT_INPUT,
      "Input",
      "Keyboard and mouse settings."
   },
   {
      RETROMAC_OPTIONCAT_PRAM,
      "PRAM",
      "Configure Parameter RAM options."
   },
   { NULL, NULL, NULL },
};

// !!!!!!!!!!!!!  DoControlModeKey(key); code for switches

struct retro_core_option_v2_definition option_defs_us[] = {
   {
      "retromac_system_model",                    /* key (option name) */
      "System > Model",                           /* description: here a 'System >' prefix is used to
                                                   * signify a category on frontends without explicit
                                                   * category support */
      "Model",                                    /* 'categorised' description (used instead of
                                                   * 'description' if frontend has category
                                                   * support; if NULL or empty, regular
                                                   * description is always used */
                                                  /* sublabel */
      "'Mac Plus' provide a B&W screen at 512x384 & 4MiB of memory.\n"
      "'Mac II' provides a 8-bit color screen at 640x480 & 8MiB of memory.\n"
      "Core restart required.",
      NULL,                                       /* 'categorised' sublabel (used instead of
                                                   * 'sublabel' if frontend has category
                                                   * support; if NULL or empty, regular
                                                   * sublabel is always used */
      RETROMAC_OPTIONCAT_SYSTEM,                                   /* category key (must match an entry in
                                                   * option_cats_us; if NULL or empty,
                                                   * option is uncategorised */
      {
         { "plus", "Mac Plus" },                  /* value_1, value_1_label */
         { "ii",   "Mac II" },                    /* value_2, value_2_label */
         { NULL, NULL },
      },
      "plus"                                      /* default_value */
   },
   {
      "retromac_system_cpuspeed",
      "System > CPU Speed",
      "CPU Speed",
      "'Plus' default speed is 8x. 'II' default speed is 4x.",
      NULL,
      "system",
      {
         { "x", "Default" },
         { "0", "1x" },
         { "1", "2x" },
         { "3", "4x" },
         { "4", "16x" },
         { "5", "23x" },
         { "a", "All out" },
         { NULL, NULL },
      },
      "0"
   },
   {
      "retromac_system_autoslow",
      "System > Auto Slow",
      "Auto slow",
      "'Plus' default is enabled. 'II' default is disabled.",
      NULL,
      RETROMAC_OPTIONCAT_SYSTEM,
      {
         { "x", "Default" },
         { "1", "Enabled" },
         { "0", "Disabled" },
         { NULL, NULL },
      },
      "x"
   },
   {
      "retromac_system_happymac",
      "System > Happy Mac Icon",
      "Happy Mac Icon",
      "Change the default ROM happy Mac icon with an icon from Mac ROM-inator.",
      NULL,
      RETROMAC_OPTIONCAT_SYSTEM,
      {
         { "standard", "Standard" },
         { "happy", "Happy" },
         { "nerdy", "Nerdy" },
         { "zombie", "Zombie" },
         { "tongue", "Tongue" },
         { "pirate", "Pirate" },
         { NULL, NULL },
      },
      "standard"
   },
   {
      "retromac_input_automap",
      "Input > Automatic Game Pad Mappings",
      "Automatic Game Pad Mappings",
      "Automatically map gamepad control based upon loaded disk",
      NULL,
      RETROMAC_OPTIONCAT_INPUT,
      {
         { "true", "Enabled" },
         { "notify", "Enable with notification on game detection" },
         { "false", "Off" },
         { NULL, NULL },
      },
      "x"
   },
   {
      "retromac_pram_doubleclick",
      "PRAM > Double Click Speed",
      "Double Click Time",
      "'Plus' default is Fast. 'II' default is Medium.",
      NULL,
      RETROMAC_OPTIONCAT_PRAM,
      {
         { "x", "Default" },
         { "3", "Very Fast" },
         { "5", "Fast" },
         { "10", "Medium" },
         { "15", "Slowe" },
         { NULL, NULL },
      },
      "x"
   },
   { NULL, NULL, NULL, NULL, NULL, NULL, {{0}}, NULL },
};

struct retro_core_options_v2 options_us = {
   option_cats_us,
   option_defs_us
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_options_v2 *options_intl[RETRO_LANGUAGE_LAST] = {
   &options_us,      /* RETRO_LANGUAGE_ENGLISH */
   NULL,             /* RETRO_LANGUAGE_JAPANESE */
   NULL,             /* RETRO_LANGUAGE_FRENCH */
   NULL,             /* RETRO_LANGUAGE_SPANISH */
   NULL,             /* RETRO_LANGUAGE_GERMAN */
   NULL,             /* RETRO_LANGUAGE_ITALIAN */
   NULL,             /* RETRO_LANGUAGE_DUTCH */
   NULL,             /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   NULL,             /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   NULL,             /* RETRO_LANGUAGE_RUSSIAN */
   NULL,             /* RETRO_LANGUAGE_KOREAN */
   NULL,             /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   NULL,             /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   NULL,             /* RETRO_LANGUAGE_ESPERANTO */
   NULL,             /* RETRO_LANGUAGE_POLISH */
   NULL,             /* RETRO_LANGUAGE_VIETNAMESE */
   NULL,             /* RETRO_LANGUAGE_ARABIC */
   NULL,             /* RETRO_LANGUAGE_GREEK */
   NULL,             /* RETRO_LANGUAGE_TURKISH */
   NULL,             /* RETRO_LANGUAGE_SLOVAK */
   NULL,             /* RETRO_LANGUAGE_PERSIAN */
   NULL,             /* RETRO_LANGUAGE_HEBREW */
   NULL,             /* RETRO_LANGUAGE_ASTURIAN */
   NULL,             /* RETRO_LANGUAGE_FINNISH */
   NULL,             /* RETRO_LANGUAGE_INDONESIAN */
   NULL,             /* RETRO_LANGUAGE_SWEDISH */
   NULL,             /* RETRO_LANGUAGE_UKRAINIAN */
   NULL,             /* RETRO_LANGUAGE_CZECH */
   NULL,             /* RETRO_LANGUAGE_CATALAN_VALENCIA */
   NULL,             /* RETRO_LANGUAGE_CATALAN */
   NULL,             /* RETRO_LANGUAGE_BRITISH_ENGLISH */
   NULL,             /* RETRO_LANGUAGE_HUNGARIAN */
   NULL,             /* RETRO_LANGUAGE_BELARUSIAN */
   NULL,             /* RETRO_LANGUAGE_GALICIAN */
   NULL,             /* RETRO_LANGUAGE_NORWEGIAN */
   NULL,             /* RETRO_LANGUAGE_IRISH */
};
#endif


/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

void retromac_set_core_options(retro_environment_t environ_cb, bool *categories_supported)
{
   unsigned version  = 0;
#ifndef HAVE_NO_LANGEXTRA
   unsigned language = 0;
#endif

   if (!environ_cb || !categories_supported)
      return;

   *categories_supported = false;

   if (!environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version))
      version = 0;

   if (version >= 2)
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_v2_intl core_options_intl;

      core_options_intl.us    = &options_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = options_intl[language];

      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL,
            &core_options_intl);
#else
      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2,
            &options_us);
#endif
   }
   else
   {
      size_t i, j;
      size_t option_index              = 0;
      size_t num_options               = 0;
      struct retro_core_option_definition
            *option_v1_defs_us         = NULL;
#ifndef HAVE_NO_LANGEXTRA
      size_t num_options_intl          = 0;
      struct retro_core_option_v2_definition
            *option_defs_intl          = NULL;
      struct retro_core_option_definition
            *option_v1_defs_intl       = NULL;
      struct retro_core_options_intl
            core_options_v1_intl;
#endif
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine total number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      if (version >= 1)
      {
         /* Allocate US array */
         option_v1_defs_us = (struct retro_core_option_definition *)
               calloc(num_options + 1, sizeof(struct retro_core_option_definition));

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            struct retro_core_option_v2_definition *option_def_us = &option_defs_us[i];
            struct retro_core_option_value *option_values         = option_def_us->values;
            struct retro_core_option_definition *option_v1_def_us = &option_v1_defs_us[i];
            struct retro_core_option_value *option_v1_values      = option_v1_def_us->values;

            option_v1_def_us->key           = option_def_us->key;
            option_v1_def_us->desc          = option_def_us->desc;
            option_v1_def_us->info          = option_def_us->info;
            option_v1_def_us->default_value = option_def_us->default_value;

            /* Values must be copied individually... */
            while (option_values->value)
            {
               option_v1_values->value = option_values->value;
               option_v1_values->label = option_values->label;

               option_values++;
               option_v1_values++;
            }
         }

#ifndef HAVE_NO_LANGEXTRA
         if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
             (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH) &&
             options_intl[language])
            option_defs_intl = options_intl[language]->definitions;

         if (option_defs_intl)
         {
            /* Determine number of intl options */
            while (true)
            {
               if (option_defs_intl[num_options_intl].key)
                  num_options_intl++;
               else
                  break;
            }

            /* Allocate intl array */
            option_v1_defs_intl = (struct retro_core_option_definition *)
                  calloc(num_options_intl + 1, sizeof(struct retro_core_option_definition));

            /* Copy parameters from option_defs_intl array */
            for (i = 0; i < num_options_intl; i++)
            {
               struct retro_core_option_v2_definition *option_def_intl = &option_defs_intl[i];
               struct retro_core_option_value *option_values           = option_def_intl->values;
               struct retro_core_option_definition *option_v1_def_intl = &option_v1_defs_intl[i];
               struct retro_core_option_value *option_v1_values        = option_v1_def_intl->values;

               option_v1_def_intl->key           = option_def_intl->key;
               option_v1_def_intl->desc          = option_def_intl->desc;
               option_v1_def_intl->info          = option_def_intl->info;
               option_v1_def_intl->default_value = option_def_intl->default_value;

               /* Values must be copied individually... */
               while (option_values->value)
               {
                  option_v1_values->value = option_values->value;
                  option_v1_values->label = option_values->label;

                  option_values++;
                  option_v1_values++;
               }
            }
         }

         core_options_v1_intl.us    = option_v1_defs_us;
         core_options_v1_intl.local = option_v1_defs_intl;

         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_v1_intl);
#else
         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, option_v1_defs_us);
#endif
      }
      else
      {
         /* Allocate arrays */
         variables  = (struct retro_variable *)calloc(num_options + 1,
               sizeof(struct retro_variable));
         values_buf = (char **)calloc(num_options, sizeof(char *));

         if (!variables || !values_buf)
            goto error;

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            const char *key                        = option_defs_us[i].key;
            const char *desc                       = option_defs_us[i].desc;
            const char *default_value              = option_defs_us[i].default_value;
            struct retro_core_option_value *values = option_defs_us[i].values;
            size_t buf_len                         = 3;
            size_t default_index                   = 0;

            values_buf[i] = NULL;

            if (desc)
            {
               size_t num_values = 0;

               /* Determine number of values */
               while (true)
               {
                  if (values[num_values].value)
                  {
                     /* Check if this is the default value */
                     if (default_value)
                        if (strcmp(values[num_values].value, default_value) == 0)
                           default_index = num_values;

                     buf_len += strlen(values[num_values].value);
                     num_values++;
                  }
                  else
                     break;
               }

               /* Build values string */
               if (num_values > 0)
               {
                  buf_len += num_values - 1;
                  buf_len += strlen(desc);

                  values_buf[i] = (char *)calloc(buf_len, sizeof(char));
                  if (!values_buf[i])
                     goto error;

                  strcpy(values_buf[i], desc);
                  strcat(values_buf[i], "; ");

                  /* Default value goes first */
                  strcat(values_buf[i], values[default_index].value);

                  /* Add remaining values */
                  for (j = 0; j < num_values; j++)
                  {
                     if (j != default_index)
                     {
                        strcat(values_buf[i], "|");
                        strcat(values_buf[i], values[j].value);
                     }
                  }
               }
            }

            variables[option_index].key   = key;
            variables[option_index].value = values_buf[i];
            option_index++;
         }

         /* Set variables */
         environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);
      }

error:
      /* Clean up */

      if (option_v1_defs_us)
      {
         free(option_v1_defs_us);
         option_v1_defs_us = NULL;
      }

#ifndef HAVE_NO_LANGEXTRA
      if (option_v1_defs_intl)
      {
         free(option_v1_defs_intl);
         option_v1_defs_intl = NULL;
      }
#endif

      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}













/*

      {
         "puae_vkbd_theme",
         "OSD > Virtual KBD Theme",
         "Virtual KBD Theme",
         "The keyboard comes up with RetroPad Select by default.",
         NULL,
         "osd",
         {
            { "auto", "Automatic (shadow)" },
            { "auto_outline", "Automatic (outline)" },
            { "beige", "Beige (shadow)" },
            { "beige_outline", "Beige (outline)" },
            { "cd32", "CD32 (shadow)" },
            { "cd32_outline", "CD32 (outline)" },
            { "light", "Light (shadow)" },
            { "light_outline", "Light (outline)" },
            { "dark", "Dark (shadow)" },
            { "dark_outline", "Dark (outline)" },
            { NULL, NULL },
         },
         "auto"
      },
      {
         "puae_vkbd_transparency",
         "OSD > Virtual KBD Transparency",
         "Virtual KBD Transparency",
         "Keyboard transparency can be toggled with RetroPad A.",
         NULL,
         "osd",
         {
            { "0%",   NULL },
            { "25%",  NULL },
            { "50%",  NULL },
            { "75%",  NULL },
            { "100%", NULL },
            { NULL, NULL },
         },
         "25%"
      },
      {
         "puae_vkbd_dimming",
         "OSD > Virtual KBD Dimming",
         "Virtual KBD Dimming",
         "Dimming level of the surrounding area.",
         NULL,
         "osd",
         {
            { "0%",   NULL },
            { "25%",  NULL },
            { "50%",  NULL },
            { "75%",  NULL },
            { "100%", NULL },
            { NULL, NULL },
         },
         "25%"
      },
      {
         "puae_statusbar",
         "OSD > Statusbar Mode",
         "Statusbar Mode",
         "- 'Full': Joyports + Messages + LEDs\n- 'Basic': Messages + LEDs\n- 'Minimal': LED colors only",
         NULL,
         "osd",
         {
            { "bottom", "Bottom Full" },
            { "bottom_minimal", "Bottom Full Minimal" },
            { "bottom_basic", "Bottom Basic" },
            { "bottom_basic_minimal", "Bottom Basic Minimal" },
            { "top", "Top Full" },
            { "top_minimal", "Top Full Minimal" },
            { "top_basic", "Top Basic" },
            { "top_basic_minimal", "Top Basic Minimal" },
            { NULL, NULL },
         },
         "bottom"
      },
      {
         "puae_statusbar_startup",
         "OSD > Statusbar Startup",
         "Statusbar Startup",
         "Show statusbar on startup.",
         NULL,
         "osd",
         {
            { "disabled", NULL },
            { "enabled", NULL },
            { NULL, NULL },
         },
         "disabled"
      },
      {
         "puae_statusbar_messages",
         "OSD > Statusbar Messages",
         "Statusbar Messages",
         "Show messages when statusbar is hidden.",
         NULL,
         "osd",
         {
            { "disabled", NULL },
            { "enabled", NULL },
            { NULL, NULL },
         },
         "disabled"
      },
      {
         "puae_audio_options_display",
         "Show Audio Options",
         NULL,
         "",
         NULL,
         NULL,
         {
            { "disabled", NULL },
            { "enabled", NULL },
            { NULL, NULL },
         },
         "disabled"
      },


      {
         "puae_analogmouse",
         "Input > Analog Stick Mouse",
         "Analog Stick Mouse",
         "Default mouse control stick when remappings are empty.",
         NULL,
         "input",
         {
            { "disabled", NULL },
            { "left", "Left Analog" },
            { "right", "Right Analog" },
            { "both", "Both Analogs" },
            { NULL, NULL },
         },
         "both"
      },
      {
         "puae_analogmouse_deadzone",
         "Input > Analog Stick Mouse Deadzone",
         "Analog Stick Mouse Deadzone",
         "Required distance from stick center to register input.",
         NULL,
         "input",
         {
            { "0", "0%" },
            { "5", "5%" },
            { "10", "10%" },
            { "15", "15%" },
            { "20", "20%" },
            { "25", "25%" },
            { "30", "30%" },
            { "35", "35%" },
            { "40", "40%" },
            { "45", "45%" },
            { "50", "50%" },
            { NULL, NULL },
         },
         "20"
      },
      {
         "puae_analogmouse_speed",
         "Input > Left Analog Stick Mouse Speed",
         "Left Analog Stick Mouse Speed",
         "Mouse speed for left analog stick.",
         NULL,
         "input",
         ANALOG_STICK_SPEED_OPTIONS,
         "1.0"
      },
	  {
         "puae_analogmouse_speed_right",
         "Input > Right Analog Stick Mouse Speed",
         "Right Analog Stick Mouse Speed",
         "Mouse speed for right analog stick.",
         NULL,
         "input",
         ANALOG_STICK_SPEED_OPTIONS,
         "1.0"
      },
      {
         "puae_dpadmouse_speed",
         "Input > D-Pad Mouse Speed",
         "D-Pad Mouse Speed",
         "Mouse speed for directional pad.",
         NULL,
         "input",
         {
            { "0", "disabled" },
            { "1", "16%" },
            { "2", "33%" },
            { "3", "50%" },
            { "4", "66%" },
            { "5", "83%" },
            { "6", "100%" },
            { "7", "116%" },
            { "8", "133%" },
            { "9", "150%" },
            { "10", "166%" },
            { "11", "183%" },
            { "12", "200%" },
            { "13", "216%" },
            { "14", "233%" },
            { "15", "250%" },
            { "16", "266%" },
            { "17", "283%" },
            { "18", "300%" },
            { NULL, NULL },
         },
         "6"
      },
      {
         "puae_mouse_speed",
         "Input > Mouse Speed",
         "Mouse Speed",
         "Global mouse speed.",
         NULL,
         "input",
         {
            { "10", "10%" },
            { "20", "20%" },
            { "30", "30%" },
            { "40", "40%" },
            { "50", "50%" },
            { "60", "60%" },
            { "70", "70%" },
            { "80", "80%" },
            { "90", "90%" },
            { "100", "100%" },
            { "110", "110%" },
            { "120", "120%" },
            { "130", "130%" },
            { "140", "140%" },
            { "150", "150%" },
            { "160", "160%" },
            { "170", "170%" },
            { "180", "180%" },
            { "190", "190%" },
            { "200", "200%" },
            { "210", "210%" },
            { "220", "220%" },
            { "230", "230%" },
            { "240", "240%" },
            { "250", "250%" },
            { "260", "260%" },
            { "270", "270%" },
            { "280", "280%" },
            { "290", "290%" },
            { "300", "300%" },
            { NULL, NULL },
         },
         "100"
      },
      {
         "puae_physicalmouse",
         "Input > Physical Mouse",
         "Physical Mouse",
         "'Double' requirements: raw/udev input driver and proper mouse index per port.\nDoes not affect RetroPad emulated mice.",
         NULL,
         "input",
         {
            { "disabled", "disabled" },
            { "enabled", "enabled" },
            { "double", "Double" },
            { NULL, NULL },
         },
         "enabled"
      },
      {
         "puae_physical_keyboard_pass_through",
         "Input > Keyboard Pass-through",
         "Keyboard Pass-through",
         "'ON' passes all physical keyboard events to the core. 'OFF' prevents RetroPad keys from generating keyboard events.\nNOTE: This is a legacy option for old frontends that do not block keyboard events when using RetroPad, so it does nothing with current RetroArch.",
         NULL,
         "input",
         {
            { "disabled", NULL },
            { "enabled", NULL },
            { NULL, NULL },
         },
         "disabled"
      },
      {
         "puae_keyrah_keypad_mappings",
         "Input > Keyrah Keypad Mappings",
         "Keyrah Keypad Mappings",
         "Hardcoded keypad to joyport mappings for Keyrah hardware.",
         NULL,
         "input",
         {
            { "disabled", NULL },
            { "enabled", NULL },
            { NULL, NULL },
         },
         "disabled"
      },
      {
         "puae_mapping_options_display",
         "Show Mapping Options",
         NULL,
         "",
         NULL,
         NULL,
         {
            { "disabled", NULL },
            { "enabled", NULL },
            { NULL, NULL },
         },
         "enabled"
      },

*/

