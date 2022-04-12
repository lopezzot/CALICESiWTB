#!/bin/bash

# Environment variables
export PHYSLIST="%PHYSLIST%"
export ENERGY="%ENERGY"
# Execute
CALICESiWTB run_pi-_%ENERGY%GeV.mac %PHYSLIST% 4 true
