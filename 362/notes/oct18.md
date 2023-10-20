# number representation

Recall one's complement and two's complement:
- one's complement: flip all bits
- two's complement: flip all bits and add 1
  - top bit is the sign bit, but still keeps the same value. so 1000 = -8, 0111 = 7
  - key realization is that the complement of a bit b is 1-b. so if we have a 4-bit number 1010, the complement is 0101. then we add 1 to get 0110. so 1010 is -6.


Sign extension
- sign extension is when we take a number and extend it to a larger number of bits
- if the number is positive, we add 0s to the left


Addressing modes:
- register addressing: read value from a register
- immediate addressing: read value from a constant burned into the instruction
- offset addressing: read value from a memory location computed by adding a constant offset to a register value

Big vs little endian:
- big endian: most significant byte first
- little endian: least significant byte first