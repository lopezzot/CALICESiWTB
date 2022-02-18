##**************************************************
## \file GNUmakefile
## \brief: GNUmakefile of CALICESiWTB project
## \author: Lorenzo Pezzotti (CERN EP-SFT-sim) @lopezzot
## \start date: 17 February 2022
##**************************************************

name := CALICESiWTB
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
    G4INSTALL == ../../..
endif

.PHONY: all
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

visclean:
	rm -f g4*.prim g4*.eps g4*.wrl
	rm -f .DAWN_*

##**************************************************
