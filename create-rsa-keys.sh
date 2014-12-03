#! /bin/bash
mkdir ./keys
openssl genrsa -F4 -out keys/dev.key 2048
openssl req -batch -new -x509 -key keys/dev.key -out keys/dev.crt
openssl rsa -in keys/dev.key -pubout
