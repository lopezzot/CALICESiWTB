# CALICESiWTB
**A Geant4 simulation of the CALICE SiW calorimeter beam tests.**

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
      <a href="#how-to">How to</a>
      <ul>
        <li><a href="#build-compile-and-execute-on-maclinux">Build, compile and execute on Mac/Linux</a></li>
      </ul>
    </li>
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

<!--How to:-->
## How to

### Build, compile and execute on Mac/Linux
Dependencies: CALICESiWTB requires ROOT built with CMake and sourced.
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
   mkdir ATLHECTB-build; cd ATLHECTB-build/
   cmake -DGeant4_DIR=/absolute_path_to/geant4.10.07_p01-install/lib/Geant4-10.7.1/ relative_path_to/CALICESiWTB/
   make
   ```
4. execute (example with ```run_pi-_2GeV.mac``` macro card and FTFP_BERT physics list)
   ```sh
   ./CALICESiWTB run_pi-_2GeV.mac FTFP_BERT
   ```
Parser options: argv[1]: a Geant4 macro card, argv[2]: the physics list (optional, default FTFP_BERT)
