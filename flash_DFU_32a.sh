#!/bin/bash

dfu-programmer atmega32a erase 
dfu-programmer atmega32a flash $1 
dfu-programmer atmega32a reset 
