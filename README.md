# CALICESiWTB
**A Geant4 simulation of the CALICE SiW calorimeter beam tests.**\
[![Website](https://img.shields.io/website?down_color=red&down_message=docs%20down&label=Docs&logo=Github&up_color=green&up_message=Always%20read%20the%20docs&url=https%3A%2F%2Flopezzot.github.io%2FCALICESiWTB%2F)](https://lopezzot.github.io/CALICESiWTB/)

<figure>
<img src="./images/CALICESiWTB_10GeVpi_1.png" alt="Trulli" style="width:100%">
<figcaption align="center"><b>Fig. - 10 GeV charged pion passing through the CALICE SiW calorimeter.</b></figcaption>
</figure>

<br/><br/>

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#project-description">Project description</a></li>
    <li><a href="#authors-and-contacts">Authors and contacts</a></li>
    <li>
      <a href="#documentation-and-results">Documentation and results</a>
      <ul>
        <li><a href="#selected-presentations">Selected presentations</a></li>
      </ul>
    </li>
    <li><a href="#available-datasets-and-analyses">Available datasets and analyses</a></li>
    <li>
      <a href="#how-to">How to</a>
      <ul>
        <li><a href="#build-compile-and-execute-on-maclinux">Build, compile and execute on Mac/Linux</a></li>
        <li><a href="#build-compile-and-execute-on-lxplus">Build, compile and execute on lxplus</a></li>
      </ul>
    </li>
    </li><li><a href="#my-quick-geant4-installation">My quick Geant4 installation</a></li>
    <li><a href="#selected-calice-siw-references">Selected CALICE SiW references</a>
  </ol>                                       
</details>

<!--Project desription-->
## Project description
The project targets a standalone Geant4 simulation of the CALICE SiW calorimeter beam tests to perform Geant4 regression testing, physics lists comparison and validation against test-beam data.
- ⏰ Start date: 17 February 2022 
- 📌 Status: under development
- ❕ DO NOTE: A first implementation was provided by Katalin Nikolics around 2018, the code is available in GitLab ( restricted link [![Website shields.io](https://img.shields.io/website-up-down-green-red/http/shields.io.svg)](https://gitlab.cern.ch/ep-sft/calice-siw-ecal-tb/) ). This repo is an adaptation of it aiming to produce results with the same level of accuracy while reducing the code to a Geant4 advanced example.

<!--Authors and contacts-->
## Authors and contacts
- 👨‍🔬 Lorenzo Pezzotti (CERN EP-SFT) - lorenzo.pezzotti@cern.ch 
- 👨‍🔬 Supervisor: Alberto Ribon (CERN EP-SFT)
- 👩‍🔬 Katalin Nikolics (CERN EP-SFT)

<!--Documentation and results-->
## Documentation and results

### Selected presentations
- 🗣️ CERN EP-SFT Simulation Group Meeting 22/3/2022, **Validation on the CALICE SiW calorimeter beam test (first test, first results)** [![Website shields.io](https://img.shields.io/website-up-down-green-red/http/shields.io.svg)](https://indico.cern.ch/event/1141927/contributions/4792467/attachments/2411878/4127542/G4_lopezzot_22_3_2022.pdf)

<!--Available datasets and analyses-->
## Available datasets and analyses
We provide datasets and ROOT analyses, as well as instructions for their reproducibility. Ask authors for access to datasets.

| CALICESiWTB      | Reproduce data | Reproduce analysis | Comments     |
| -------------    | ----------     | -----------        | -----------  |
| v0p4 <br /> Dataset #1 <br /> tag 0p4_1 | Geant4.10.07.p03 <br /> CALICESiWTB v0p4 <br /> ```./CALICESiWTB run_pi-_x_GeV.mac FTFP_BERT #nThreads``` <br /> x = 2, 4, 6, 8, 10 <br /> using FTFP_BERT physics list | ```root -l MyLongitudinalPlots.C```  | Analysis reproducable with analysis/v0.4/MyLongitudinalPlots.C macro <br /> assuming Data0p4_1/ is alongside root macro. <br /> New results on pion energy and hit longitudinal distributions. Prepared for the CALICE Collaboration Meeting April 2022. |
| v0p3 <br /> Dataset #1 <br /> tag 0p3_1 | Geant4.10.07.p03 <br /> CALICESiWTB v0p3 <br /> ```./CALICESiWTB run_pi-_x_GeV.mac``` <br /> x = 2, 4, 6, 8, 10 <br /> FTFP_BERT implicit physics list | ```root -l MyLongitudinalPlots.C```  | Analysis reproducable with analysis/v0.3/MyLongitudinalPlots.C macro <br /> assuming Data0p3_1/ is alongside root macro. <br /> First results on pion energy longitudinal distributions, shown at presentation on 22/03/2022. |

<!--How to:-->
## How to

### Build, compile and execute on Mac/Linux
1. git clone the repo
   ```sh
   git clone https://github.com/lopezzot/CALICESiWTB.git
   ```
2. source Geant4 env
   ```sh
   source /relative_path_to/geant4.10.07_p01-install/bin/geant4.sh
   ```
3. cmake build directory and make (using geant4.10.07_p01)
   ```sh
   mkdir CALICESiWTB-build; cd CALICESiWTB-build/
   cmake -DGeant4_DIR=/absolute_path_to/geant4.10.07_p01-install/lib/Geant4-10.7.1/ relative_path_to/CALICESiWTB/
   make
   ```
4. execute (example with ```run_pi-_2GeV.mac``` macro card, FTFP_BERT physics list and 2 threads)
   ```sh
   ./CALICESiWTB run_pi-_2GeV.mac FTFP_BERT 2
   ```
Parser options: argv[1] a Geant4 macro card, argv[2] the physics list (optional, default FTFP_BERT), argv[3] number of threads

### Build, compile and execute on lxplus
1. git clone the repo
   ```sh
   git clone https://github.com/lopezzot/CALICESiWTB.git
   ```
2. cmake build directory and make (using geant4.10.07_p03, check for gcc and cmake dependencies for other versions)
   ```sh
   mkdir CALICESiWTB-build; cd CALICESiWTB-build/
   source /cvmfs/sft.cern.ch/lcg/contrib/gcc/8.3.0/x86_64-centos7/setup.sh 
   source /cvmfs/geant4.cern.ch/geant4/10.7.p03/x86_64-centos7-gcc8-optdeb-MT/CMake-setup.sh 
   export CXX=`which g++`
   export CC=`which gcc`
   cmake3 -DGeant4_DIR= /cvmfs/geant4.cern.ch/geant4/10.7.p03/x86_64-centos7-gcc8-optdeb-MT/lib64/Geant4-10.7.3 ../CALICESiWTB/
   make
   ```
   Hint: cp and source the scripts/CALICESiWTB_lxplus_10.7.p03.sh file in the build directory.
3. execute (example 2 GeV pi- macro card, FTFP_BERT physics list and 2 threads)
   ```sh
   ./CALICESiWTB run_pi-_2GeV.mac FTFP_BERT 2
   ```

<!--My quick Geant4 installation-->
## My quick Geant4 installation
Here is my standard Geant4 installation (example with Geant4.10.7.p01) starting from the unpacked geant4.10.07.tar.gz file under the example path "path/to".

1. create build directory alongside source files
      ```sh
   cd /path/to
   mkdir geant4.10.07-build
   cd geant4.10.07-build
   ```
2. link libraries with CMAKE (example with my favourite libraries)
   ```sh
   cmake -DCMAKE_INSTALL_PREFIX=/Users/lorenzo/myG4/geant4.10.07_p01-install \
   -DGEANT4_INSTALL_DATA=ON -DGEANT4_USE_QT=ON -DGEANT4_BUILD_MULTITHREADED=ON \
   -DGEANT4_USE_GDML=ON ../geant4.10.07.p01
   ```
3. make it
   ```sh
   make -jN
   make install
   ```

<!--Selected CALICE SiW references-->
## Selected CALICE SiW references
- 📄 <em>Testing hadronic interaction models using a highly granular silicon–tungsten calorimeter</em>, NIM A794 (2015): [![Website shields.io](https://img.shields.io/website-up-down-green-red/http/shields.io.svg)](https://www.sciencedirect.com/science/article/pii/S0168900215006191?via%3Dihub)
