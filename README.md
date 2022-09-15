# qpc-msp430
## QP/C examples running on low end MSP430 microcontrollers

### Prerequisite
Install Code Composer Studio 12 with msp430 support.

### Dining Philosopher Problem
**Installation:**
1- Import the project from the qpc_dpp directory.
2- Download and execute the code on a MSP-EXP430G2 or MSP-EXP430G2ET board.<br>

**Rebuild:**
1- Adjust include directory for &lt;qpc&gt;/include
2- Adjust link for &lt;qpc&gt;/src/qf directory
3- Adjust link for &lt;qpc&gt;/src/qv/qv.c
where &lt;qpc&gt; is the location of the installed QP/C framework
4- Perform full rebuild of Debug and Release targets
