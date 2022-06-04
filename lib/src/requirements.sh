#!/usr/bin/env bash

cat requirements.txt | grep $1: | cut -d':' -f2
