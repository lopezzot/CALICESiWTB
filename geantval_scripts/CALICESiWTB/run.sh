#!/bin/bash

# Environment variables
export PHYSLIST="%PHYSLIST%"
export ENERGY="%ENERGY"
# Execute
CALICESiWTB CALICESiWTB.mac %PHYSLIST% 4 true
