VERSION="11.1.p01"
PLATFORM="x86_64-centos7-gcc8-optdeb"


# Geant4 libraries
source /cvmfs/geant4.cern.ch/geant4/$VERSION/${PLATFORM}/bin/geant4.sh
[ -e /cvmfs/geant4.cern.ch/geant4/$VERSION/setup_g4datasets.sh ] && source /cvmfs/geant4.cern.ch/geant4/$VERSION/setup_g4datasets.sh

# Test path
export PATH="/cvmfs/geant4.cern.ch/opt-geant-val/$VERSION/$PLATFORM/bin:/cvmfs/geant4.cern.ch/opt/$VERSION/$PLATFORM/bin:$PATH:/afs/cern.ch/work/l/lopezzot/Fellow/CALICESiWTB/build1111/"

# Compiler
source /cvmfs/sft.cern.ch/lcg/contrib/gcc/8/x86_64-centos7/setup.sh
