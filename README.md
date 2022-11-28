# qpc-msp430
## QP/C examples running on low end MSP430 microcontrollers

### Prerequisite
Install Code Composer Studio 12 with msp430 support.

### Dining Philosopher Problem
**Installation:**<br>
1- Import the project from the qpc_dpp directory.<br>
2- Download and execute the code on a MSP-EXP430G2 or MSP-EXP430G2ET board.<br>

**Rebuild:**<br>
1- Adjust include directory for **&lt;qpc&gt;**/include<br>
2- Adjust link for **&lt;qpc&gt;**/src/qf directory<br>
3- Adjust link for **&lt;qpc&gt;**/src/qv/qv.c<br>
4- Perform full rebuild of Debug and Release targets<br>
<br>
where **&lt;qpc&gt;** is the location of the installed QP/C framework
