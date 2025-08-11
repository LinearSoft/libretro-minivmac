#include "disk.h"
#include <stdbool.h>
#include "minivmac/constants.h"

struct disk_control_t
{
   char* files[RETROMAC_NumDrives];
   unsigned index;
   bool is_ejected;
   char* initial_path;
   unsigned initial_index;
};

static struct disk_control_t disk_control;


static bool retromac_discontrol_set_eject_state(bool ejected);
static bool retromac_discontrol_get_eject_state(void);
static unsigned retromac_discontrol_get_image_index(void);
static bool retromac_discontrol_set_image_index(unsigned index);
static unsigned retromac_discontrol_get_num_images(void);
static bool retromac_discontrol_replace_image_index(unsigned index, const struct retro_game_info *info);
static bool retromac_discontrol_add_image_index(void);
static bool retromac_discontrol_set_initial_image(unsigned index, const char *path);
static bool retromac_discontrol_get_image_path(unsigned index, char *s, size_t len);

static struct retro_disk_control_callback disk_interface = {
   retromac_discontrol_set_eject_state,
   retromac_discontrol_get_eject_state,
   retromac_discontrol_get_image_index,
   retromac_discontrol_set_image_index,
   retromac_discontrol_get_num_images,
   retromac_discontrol_replace_image_index,
   retromac_discontrol_add_image_index
};

static struct retro_disk_control_ext_callback disk_interface_ext = {
   retromac_discontrol_set_eject_state,
   retromac_discontrol_get_eject_state,
   retromac_discontrol_get_image_index,
   retromac_discontrol_set_image_index,
   retromac_discontrol_get_num_images,
   retromac_discontrol_replace_image_index,
   retromac_discontrol_add_image_index,
   retromac_discontrol_set_initial_image,
   retromac_discontrol_get_image_path,
   NULL
};

void retromac_disk_init(retro_environment_t cb)
{
   retromac_diskcontrol_init();

   unsigned dci_version = 0;
   if (environ_cb(RETRO_ENVIRONMENT_GET_DISK_CONTROL_INTERFACE_VERSION, &dci_version) && (dci_version >= 1))
      environ_cb(RETRO_ENVIRONMENT_SET_DISK_CONTROL_EXT_INTERFACE, &disk_interface_ext);
   else
      environ_cb(RETRO_ENVIRONMENT_SET_DISK_CONTROL_INTERFACE, &disk_interface);
}

void retromac_diskcontrol_init()
{
   for(unsigned i = 0; i < RETROMAC_NumDrives; i++)
   {
      if (disk_control.files[i])
      {
         free(disk_control.files[i]);
         disk_control.files[i] = NULL;
      }
   }
   disk_control.index = 0;
   disk_control.is_ejected = false;
   if (disk_control.initial_path)
   {
      free(disk_control.initial_path);
      disk_control.initial_path = NULL;
   }
}


/**
 * Called by the frontend to open or close the emulated console's virtual disk tray.
 *
 * The frontend may only set the disk image index
 * while the emulated tray is opened.
 *
 * If the emulated console's disk tray is already in the state given by \c ejected,
 * then this function should return \c true without doing anything.
 * The core should return \c false if it couldn't change the disk tray's state;
 * this may happen if the console itself limits when the disk tray can be open or closed
 * (e.g. to wait for the disc to stop spinning).
 *
 * @param ejected \c true if the virtual disk tray should be "ejected",
 * \c false if it should be "closed".
 * @return \c true if the virtual disk tray's state has been set to the given state,
 * false if there was an error.
 * @see retro_get_eject_state_t
 */
static bool retromac_discontrol_set_eject_state(bool ejected)
{
   if (ejected && disk_control.is_ejected)
      return true;
   // Handle disk ejections


   // Handle disk insertion
}

/**
 * Gets the current ejected state of the disk drive.
 * The initial state is closed, i.e. \c false.
 *
 * @return \c true if the virtual disk tray is "ejected",
 * i.e. it's open and a disk can be inserted.
 * @see retro_set_eject_state_t
 */
static bool retromac_discontrol_get_eject_state(void)
{
   return disk_control.is_ejected;
}

/**
 * Gets the index of the current disk image,
 * as determined by however the frontend orders disk images
 * (such as m3u-formatted playlists or special directories).
 *
 * @return The index of the current disk image
 * (starting with 0 for the first disk),
 * or a value greater than or equal to \c get_num_images() if no disk is inserted.
 * @see retro_get_num_images_t
 */
static unsigned retromac_discontrol_get_image_index(void)
{
   return disk_control.index;
}

/**
 * Inserts the disk image at the given index into the emulated console's drive.
 * Can only be called while the disk tray is ejected
 * (i.e. \c retro_get_eject_state_t returns \c true).
 *
 * If the emulated disk tray is ejected
 * and already contains the disk image named by \c index,
 * then this function should do nothing and return \c true.
 *
 * @param index The index of the disk image to insert,
 * starting from 0 for the first disk.
 * A value greater than or equal to \c get_num_images()
 * represents the frontend removing the disk without inserting a new one.
 * @return \c true if the disk image was successfully set.
 * \c false if the disk tray isn't ejected or there was another error
 * inserting a new disk image.
 */
static bool retromac_discontrol_set_image_index(unsigned index)
{

}

/**
 * @return The number of disk images which are available to use.
 * These are most likely defined in a playlist file.
 */
static unsigned retromac_discontrol_get_num_images(void)
{

}

/**
 * Replaces the disk image at the given index with a new disk.
 *
 * Replaces the disk image associated with index.
 * Arguments to pass in info have same requirements as retro_load_game().
 * Virtual disk tray must be ejected when calling this.
 *
 * Passing \c NULL to this function indicates
 * that the frontend has removed this disk image from its internal list.
 * As a result, calls to this function can change the number of available disk indexes.
 *
 * For example, calling <tt>replace_image_index(1, NULL)</tt>
 * will remove the disk image at index 1,
 * and the disk image at index 2 (if any)
 * will be moved to the newly-available index 1.
 *
 * @param index The index of the disk image to replace.
 * @param info Details about the new disk image,
 * or \c NULL if the disk image at the given index should be discarded.
 * The semantics of each field are the same as in \c retro_load_game.
 * @return \c true if the disk image was successfully replaced
 * or removed from the playlist,
 * \c false if the tray is not ejected
 * or if there was an error.
 */
static bool retromac_discontrol_replace_image_index(unsigned index, const struct retro_game_info *info)
{

}

/**
 * Adds a new index to the core's internal disk list.
 * This will increment the return value from \c get_num_images() by 1.
 * This image index cannot be used until a disk image has been set
 * with \c replace_image_index.
 *
 * @return \c true if the core has added space for a new disk image
 * and is ready to receive one.
 */
static bool retromac_discontrol_add_image_index(void)
{

}

/**
 * Sets the disk image that will be inserted into the emulated disk drive
 * before \c retro_load_game is called.
 *
 * \c retro_load_game does not provide a way to ensure
 * that a particular disk image in a playlist is inserted into the console;
 * this function makes up for that.
 * Frontends should call it immediately before \c retro_load_game,
 * and the core should use the arguments
 * to validate the disk image in \c retro_load_game.
 *
 * When content is loaded, the core should verify that the
 * disk specified by \c index can be found at \c path.
 * This is to guard against auto-selecting the wrong image
 * if (for example) the user should modify an existing M3U playlist.
 * We have to let the core handle this because
 * \c set_initial_image() must be called before loading content,
 * i.e. the frontend cannot access image paths in advance
 * and thus cannot perform the error check itself.
 * If \c index is invalid (i.e. <tt>index >= get_num_images()</tt>)
 * or the disk image doesn't match the value given in \c path,
 * the core should ignore the arguments
 * and insert the disk at index 0 into the virtual disk tray.
 *
 * @warning If \c RETRO_ENVIRONMENT_SET_DISK_CONTROL_EXT_INTERFACE is called within \c retro_load_game,
 * then this function may not be executed.
 * Set the disk control interface in \c retro_init if possible.
 *
 * @param index The index of the disk image within the playlist to set.
 * @param path The path of the disk image to set as the first.
 * The core should not load this path immediately;
 * instead, it should use it within \c retro_load_game
 * to verify that the correct disk image was loaded.
 * @return \c true if the initial disk index was set,
 * \c false if the arguments are invalid
 * or the core doesn't support this function.
 */
static bool retromac_discontrol_set_initial_image(unsigned index, const char *path)
{

}

/**
 * Returns the path of the disk image at the given index
 * on the host's file system.
 *
 * @param index The index of the disk image to get the path of.
 * @param s A buffer to store the path in.
 * @param len The size of \c s, in bytes.
 * @return \c true if the disk image's location was successfully
 * queried and copied into \c s,
 * \c false if the index is invalid
 * or the core couldn't locate the disk image.
 */
static bool retromac_discontrol_get_image_path(unsigned index, char *s, size_t len)
{

}

/**
 * Returns a friendly label for the given disk image.
 *
 * In the simplest case, this may be the disk image's file name
 * with the extension omitted.
 * For cores or games with more complex content requirements,
 * the label can be used to provide information to help the player
 * select a disk image to insert;
 * for example, a core may label different kinds of disks
 * (save data, level disk, installation disk, bonus content, etc.).
 * with names that correspond to in-game prompts,
 * so that the frontend can provide better guidance to the player.
 *
 * @param index The index of the disk image to return a label for.
 * @param s A buffer to store the resulting label in.
 * @param len The length of \c s, in bytes.
 * @return \c true if the disk image at \c index is valid
 * and a label was copied into \c s.
 */
/*
bool retromac_discontrol_get_image_label(unsigned index, char *s, size_t len)
{

}
*/