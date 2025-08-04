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
-t port \
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

for model in Plus II; do
    ./setup_t -m $model $OPTS > ./setup.sh
    ./setup.sh
    mv ./Makefile ./cfg
    mv ./cfg ./cfg-${model,,}
done
rm -rf ./bld > /dev/null 2>/dev/null
popd > /dev/null

echo "----------- Copying files"

for model in plus ii; do
    rm -rf ./src/minivmac/$model > /dev/null 2>/dev/null
    mkdir -p ./src/minivmac/$model
    mv ./minivmac/cfg-$model ./src/minivmac/$model/cfg
done
