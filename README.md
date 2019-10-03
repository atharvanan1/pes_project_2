# PES Project 2
## Readme

Name: Atharva Nandanwar

This repository contains all the required files for PES Project 2.

Recommended compiler for build targets
fb_run fb_debug - use MCUXpresso to build and debug
pc_run pc_debug - use gcc, and bash terminal to execute

Note - makefile included, and these builds can be built using 
```make BV=FB_RUN``` or ```make BV=PC_DEBUG```

Folder Structure:
1. source - contains source files
2. source/fb - contains source files for freedom board targets
3. source/pc - contains source files for pc based targets
4. include - include files only for freedom board targets
5. startup - source file for startup code
6. utilities, CMSIS, drivers, board - files required for Freedom board configuration, and drivers
7. linkerfile.ld - file used by arm-linker
8. makefile - make file for the project
