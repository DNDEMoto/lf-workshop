#!/bin/bash
# usage: ./build-ROS-node name-of-lf-file-without-.lf name-of-ROS-package
lfc $1.lf # -r オプション外し。いつのこれ
cp -R src-gen/$1/* $2/src/
mv $2/src/$1.c $2/src/$1.cpp
#mv $2/src/core/platform/lf_linux_support.c $2/src/core/platform/lf_linux_support.cpp
mv $2/src/low_level_platform/impl/src/lf_linux_support.c $2/src/low_level_platform/impl/src/lf_linux_support.cpp
pushd $2
colcon build --packages-select $2
popd

