#!/bin/bash

set -e

echo "----------- Generate configs"

pushd ./minivmac > /dev/null

# we need to build the setup tool first
if [ ! -x ./setup_t ]; then
	gcc -o setup_t setup/tool.c
fi

rm -rf ./cfg > /dev/null 2>/dev/null
rm -rf ./cfg-plus > /dev/null 2>/dev/null
rm -rf ./cfg-ii > /dev/null 2>/dev/null

OPTS=$(cat <<EOF
-maintainer jason@linearsoft.com
-homepage https://github.com/LinearSoft \
-n minivmac-3.7-retro \
-e bgc \
-magnify 1 -mf 2 \
-sound 1 \
-sony-sum 1 -sony-tag 1 \
-api sd2 -snd-api ddsp \
-svd 0 -iid 0 \
-alc 0 -lcy 485768755 -lcx -883053230 \
-atz 0 -lcz -5 -lcd 1 \
-im 0
EOF
)

patch_cfg() {
  sed -i 's|#define UseControlKeys.*|#define UseControlKeys 0|g' ./cfg/CNFUDOSG.h # No control menu
  sed -i 's|#define EnableDragDrop.*|#define EnableDragDrop 0|g' ./cfg/CNFUDOSG.h # No drag and drop

  sed -i '/#include <SDL2.*/d' ./cfg/CNFUIOSG.h                                   # Remove SDL

  sed -i '1i #include "../../constants.h"' ./cfg/CNFUDALL.h                             # Refrence shared consts
  sed -i 's|#define NumDrives.*|#define NumDrives RETROMAC_NumDrives|g' ./cfg/CNFUDALL.h  # Use shared drive count
  sed -i "s|#define vMacScreenHeight.*|#define vMacScreenHeight RETROMAC_${1}ScreenHeight|g" ./cfg/CNFUDALL.h
  sed -i "s|#define vMacScreenWidth.*|#define vMacScreenWidth RETROMAC_${1}ScreenWidth|g" ./cfg/CNFUDALL.h

}

# Port Configs
for model in Plus II; do
    ./setup_t -m $model -t port $OPTS > ./setup.sh
    ./setup.sh
    mv ./Makefile ./cfg
    patch_cfg "$model"
    mv ./cfg ./cfg-${model,,}
done

# Local configs (used for dev only)
./setup_t -m Plus -t lx64 $OPTS > ./setup.sh
./setup.sh
patch_cfg

rm -rf ./bld > /dev/null 2>/dev/null
popd > /dev/null

echo "----------- Move cfg files"

for model in plus ii; do
    rm -rf ./src/minivmac/$model > /dev/null 2>/dev/null
    mkdir -p ./src/minivmac/$model
    mv ./minivmac/cfg-$model ./src/minivmac/$model/cfg
done

echo "----------- Create shared cfg files"
rm -rf ./src/minivmac/shared > /dev/null 2>/dev/null
mkdir -p ./src/minivmac/shared/cfg
# Keep II with extra defs
mv ./src/minivmac/ii/cfg/CNFUIALL.h ./src/minivmac/shared/cfg/
rm ./src/minivmac/plus/cfg/CNFUIALL.h
# Keep either one
mv ./src/minivmac/ii/cfg/CNFUDOSG.h ./src/minivmac/shared/cfg/
rm ./src/minivmac/plus/cfg/CNFUDOSG.h