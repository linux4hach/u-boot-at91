#! /bin/bash
set ARCH=arm
make distclean
make at91sam9x5ek_dataflash_config
make CROSS_COMPILE=/opt/Programs/buildroot-at91/output/host/usr/bin/arm-linux- all env
