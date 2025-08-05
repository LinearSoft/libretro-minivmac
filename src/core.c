#include <libretro.h>

#include "logging.h"
#include "options.h"

char retro_system_directory[4096];
char retro_game_path[4096];



/* -------  LibRetro Callback refrences  ------- */
static retro_environment_t environ_cb = NULL;

/**
 * Sets the environment callback.
 *
 * @note Guaranteed to be called before \c retro_init().
 */
void retro_set_environment(retro_environment_t cb)
{
   environ_cb = cb;

   // Prep immediatly incase needed by subsequent operations
   retromac_logger_init(cb);

   bool retro_options_categories_supported;
   retromac_set_core_options(cb, &retro_options_categories_supported);

   // Not really any point but it is possible
   bool support_no_game = true;
   environ_cb(RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME, &support_no_game);
}

/**
 * Sets the video refresh callback.
 *
 * @note Guaranteed to have been called before the first call to \c retro_run() is made.
 */
//void retro_set_video_refresh(retro_video_refresh_t cb);

/**
 * Sets the audio sample callback.
 *
 * @note Guaranteed to have been called before the first call to \c retro_run() is made.
 */
// void retro_set_audio_sample(retro_audio_sample_t cb);

/**
 * Sets the audio sample batch callback.
 *
 * @note Guaranteed to have been called before the first call to \c retro_run() is made.
 */
// void retro_set_audio_sample_batch(retro_audio_sample_batch_t cb);

/**
 * Sets the input poll callback.
 *
 * @note Guaranteed to have been called before the first call to \c retro_run() is made.
 */
// void retro_set_input_poll(retro_input_poll_t cb);

/**
 * Sets the input state callback.
 *
 *@note Guaranteed to have been called before the first call to \c retro_run() is made.
 */
// void retro_set_input_state(retro_input_state_t cb);

/**
 * Called by the frontend when initializing a libretro core.
 *
 * @warning Global defaults must be initialized via code in dynamic libraries.
 */
void retro_init(void)
{
    //frame_buf = (uint8_t*)calloc(SharedCfg_ScreenNumPixels * sizeof(uint32_t));

    // Directories
    const char *dir = NULL;
    if (environ_cb(RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY, &dir) && dir)
    {
        snprintf(retro_system_directory, sizeof(retro_system_directory), "%s", dir);
    }

    //Keyboard CB

    /* Disc interface */
   dc = dc_create();
   unsigned dci_version = 0;
   if (environ_cb(RETRO_ENVIRONMENT_GET_DISK_CONTROL_INTERFACE_VERSION, &dci_version) && (dci_version >= 1))
      environ_cb(RETRO_ENVIRONMENT_SET_DISK_CONTROL_EXT_INTERFACE, &disk_interface_ext);
   else
      environ_cb(RETRO_ENVIRONMENT_SET_DISK_CONTROL_INTERFACE, &disk_interface);
}

/**
 * Called by the frontend when deinitializing a libretro core.
 * The core must release all of its allocated resources before this function returns.
 *
 * @warning Do not assume the core will be unloaded. Reset globals to defaults.
 */
void retro_deinit(void)
{
   free(frame_buf);
   frame_buf = NULL;
}

/**
 * Retrieves which version of the libretro API is being used.
 */
unsigned retro_api_version(void)
{
    return RETRO_API_VERSION;
}

/**
 * Gets statically known system info.
 *
 * @note Can be called at any time, even before retro_init().
 */
// void retro_get_system_info(struct retro_system_info *info);

/**
 * Gets information about system audio/video timings and geometry.
 *
 * @note Can be called only after \c retro_load_game() has successfully completed.
 *
 * @note The implementation of this function might not initialize every variable
 * if needed. For example, \c geom.aspect_ratio might not be initialized if
 * the core doesn't desire a particular aspect ratio.
 *
 */
// void retro_get_system_av_info(struct retro_system_av_info *info);

/**
 * Sets device to be used for player 'port'.
 *
 * By default, \c RETRO_DEVICE_JOYPAD is assumed to be plugged into all
 * available ports.
 *
 * @note Setting a particular device type is not a guarantee that libretro cores
 * will only poll input based on that particular device type. It is only a
 * hint to the libretro core when a core cannot automatically detect the
 * appropriate input device type on its own. It is also relevant when a
 * core can change its behavior depending on device type.
 *
 * @note As part of the core's implementation of retro_set_controller_port_device,
 * the core should call \c RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS to notify the
 * frontend if the descriptions for any controls have changed as a
 * result of changing the device type.
 *
 * @param port Which port to set the device for, usually indicates the player number.
 * @param device Which device the given port is using. By default, \c RETRO_DEVICE_JOYPAD is assumed for all ports.
 *
 * @see RETRO_DEVICE_NONE
 * @see RETRO_DEVICE_JOYPAD
 * @see RETRO_DEVICE_MOUSE
 * @see RETRO_DEVICE_KEYBOARD
 * @see RETRO_DEVICE_LIGHTGUN
 * @see RETRO_DEVICE_ANALOG
 * @see RETRO_DEVICE_POINTER
 * @see RETRO_ENVIRONMENT_SET_CONTROLLER_INFO
 */
// void retro_set_controller_port_device(unsigned port, unsigned device);

/**
 * Resets the currently-loaded game.
 * Cores should treat this as a soft reset (i.e. an emulated reset button) if possible,
 * but hard resets are acceptable.
 */
// void retro_reset(void);

/**
 * Runs the game for one video frame.
 *
 * During \c retro_run(), the \c retro_input_poll_t callback must be called at least once.
 *
 * @note If a frame is not rendered for reasons where a game "dropped" a frame,
 * this still counts as a frame, and \c retro_run() should explicitly dupe
 * a frame if \c RETRO_ENVIRONMENT_GET_CAN_DUPE returns true. In this case,
 * the video callback can take a NULL argument for data.
 *
 * @see retro_input_poll_t
 */
// void retro_run(void);

/**
 * Returns the amount of data the implementation requires to serialize internal state (save states).
 *
 * @note Between calls to \c retro_load_game() and \c retro_unload_game(), the
 * returned size is never allowed to be larger than a previous returned
 * value, to ensure that the frontend can allocate a save state buffer once.
 *
 * @return The amount of data the implementation requires to serialize the internal state.
 *
 * @see retro_serialize()
 */
// size_t retro_serialize_size(void);

/**
 * Serializes the internal state.
 *
 * @param data A pointer to where the serialized data should be saved to.
 * @param size The size of the memory.
 *
 * @return If failed, or size is lower than \c retro_serialize_size(), it
 * should return false. On success, it will return true.
 *
 * @see retro_serialize_size()
 * @see retro_unserialize()
 */
// bool retro_serialize(void *data, size_t len);

/**
 * Unserialize the given state data, and load it into the internal state.
 *
 * @return Returns true if loading the state was successful, false otherwise.
 *
 * @see retro_serialize()
 */
// bool retro_unserialize(const void *data, size_t len);

/**
 * Reset all the active cheats to their default disabled state.
 *
 * @note Not implemented
 */
void retro_cheat_reset(void)
{
}

/**
 * Enable or disable a cheat.
 *
 * @note Not implemented
 */
void retro_cheat_set(unsigned index, bool enabled, const char *code)
{
   (void)index;
   (void)enabled;
   (void)code;
}

/**
 * Loads a game.
 *
 * @param game A pointer to a \c retro_game_info detailing information about the game to load.
 * May be \c NULL if the core is loaded without content.
 *
 * @return Will return true when the game was loaded successfully, or false otherwise.
 *
 * @see retro_game_info
 * @see RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME
 */
// bool retro_load_game(const struct retro_game_info *game);

/**
 * Called when the frontend has loaded one or more "special" content files,
 * typically through subsystems.
 *
 * @note Only necessary for cores that support subsystems.
 * Others may return \c false or delegate to <tt>retro_load_game</tt>.
 *
 * @param game_type The type of game to load,
 * as determined by \c retro_subsystem_info.
 * @param info A pointer to an array of \c retro_game_info objects
 * providing information about the loaded content.
 * @param num_info The number of \c retro_game_info objects passed into the info parameter.
 * @return \c true if loading is successful, false otherwise.
 * If the core returns \c false,
 * the frontend should abort the core
 * and return to its main menu (if applicable).
 *
 * @see RETRO_ENVIRONMENT_GET_GAME_INFO_EXT
 * @see RETRO_ENVIRONMENT_SET_SUBSYSTEM_INFO
 * @see retro_load_game()
 * @see retro_subsystem_info
 */
/* bool retro_load_game_special(
  unsigned game_type,
  const struct retro_game_info *info, size_t num_info
);*/

/**
 * Unloads the currently loaded game.
 *
 * @note This is called before \c retro_deinit(void).
 *
 * @see retro_load_game()
 * @see retro_deinit()
 */
// void retro_unload_game(void);

/**
 * Gets the region of the actively loaded content as either \c RETRO_REGION_NTSC or \c RETRO_REGION_PAL.
 *
 * @note For emulated consoles that don't use either standard the core should return \c RETRO_REGION_NTSC.
 * @return The region of the actively loaded content.
 */
unsigned retro_get_region(void)
{
    return RETRO_REGION_NTSC;
}

/**
 * Get a region of memory.
 *
 * @param id The ID for the memory block that's desired to retrieve. Can be \c RETRO_MEMORY_SAVE_RAM, \c RETRO_MEMORY_RTC, \c RETRO_MEMORY_SYSTEM_RAM, or \c RETRO_MEMORY_VIDEO_RAM.
 *
 * @return A pointer to the desired region of memory, or NULL when not available.
 *
 * @see RETRO_MEMORY_SAVE_RAM
 * @see RETRO_MEMORY_RTC
 * @see RETRO_MEMORY_SYSTEM_RAM
 * @see RETRO_MEMORY_VIDEO_RAM
 */
// void *retro_get_memory_data(unsigned id);

/**
 * Gets the size of the given region of memory.
 *
 * @param id The ID for the memory block to check the size of. Can be RETRO_MEMORY_SAVE_RAM, RETRO_MEMORY_RTC, RETRO_MEMORY_SYSTEM_RAM, or RETRO_MEMORY_VIDEO_RAM.
 *
 * @return The size of the region in memory, or 0 when not available.
 *
 * @see RETRO_MEMORY_SAVE_RAM
 * @see RETRO_MEMORY_RTC
 * @see RETRO_MEMORY_SYSTEM_RAM
 * @see RETRO_MEMORY_VIDEO_RAM
 */
// size_t retro_get_memory_size(unsigned id);