#!/bin/bash

# sudo apt install mingw-w64 build-essential clang

set -e

pushd ./minivmac > /dev/null

# we need to build the setup tool first
if [ ! -x ./setup_t ]; then
	gcc -o setup_t setup/tool.c
fi

rm -rf ./cfg > /dev/null 2>/dev/null

OPTS=$(cat <<EOF
-maintainer jason@linearsoft.com
-homepage https://github.com/LinearSoft \
-n minivmac-3.7-test \
-e mgw \
-t wx64 \
-magnify 1 -mf 2 \
-sound 1 \
-sony-sum 1 -sony-tag 1 \
-snd-api ddsp \
-svd 0 -iid 0 \
-alc 0 -lcy 485768755 -lcx -883053230 \
-atz 0 -lcz -5 -lcd 1 \
-im 0
EOF
)

./setup_t -m Plus $OPTS > ./setup.sh
./setup.sh

sed -i '1 a\CC=x86_64-w64-mingw32-gcc\
STRIP=x86_64-w64-mingw32-strip\
WINDRES=x86_64-w64-mingw32-windres ' ./Makefile

sed -i 's|gcc.exe|\$(CC)|g' ./Makefile
sed -i 's|windres.exe|\$(WINDRES)|g' ./Makefile
sed -i 's|strip.exe|\$(STRIP)|g' ./Makefile

#sed -i 's|"ICONAPPW.ico"|"src/ICONAPPW.ico"|g' cfg/main.rc

make clean
make -j $(nproc)

popdq