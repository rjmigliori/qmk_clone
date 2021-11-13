#!/bin/bash

dfu-programmer atmega32u2 erase 
dfu-programmer atmega32u2 flash $1 
dfu-programmer atmega32u2 reset 