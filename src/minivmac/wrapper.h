#ifndef RETROMAC_MINIVMAC_WRAPPER_H__
#define RETROMAC_MINIVMAC_WRAPPER_H__ 1

#include <stdbool.h>

/* MiniVMac Glue Common Libs */
#include "shared/cfg/CNFUDOSG.h"
#include "shared/cfg/CNFUIALL.h"
#include <DFCNFCMP.h>
#include <ENDIANAC.h>
#include <OSGLUAAA.h>
#include <STRCNENG.h>


typedef struct {
   void (*Keyboard_UpdateKeyMap)(ui3r key, blnr down);
} MiniVmacWrap_t;

extern MiniVmacWrap_t minivmac_wrapper;

void retromac_minivmac_wrapper_init(bool isPlus);

#endif