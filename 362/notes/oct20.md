# Representing RISC-V Instructions
- All intrs are 32-bits (4 bytes)
- Fields of the instrs are kept as consistent as possible
- Not all instr sets are a consistent bit size, but for RISC-V, they are


Representing simple reg/reg instrs:

$\underset{\text{7 bits}}{\boxed{\text{func7}}} \underset{\text{5 bits}}{\boxed{\text{rs2}}} \underset{\text{5 bits}}{\boxed{\text{rs1}}} \underset{\text{3 bits}}{\boxed{\text{func3}}} \underset{\text{5 bits}}{\boxed{\text{rd}}} \underset{\text{7 bits}}{\boxed{\text{opcode}}} = \text{32 bits}$

Explaining the above: 
- **funct7/funct3:** combined with opcode, these fields help determine the instr 
- **rs2:** 5 bits for the second register (source reg 2)
- **rs1:** 5 bits for the first register (source reg 1)
- **rd:** 5 bits for the destination register (receives result)
- **opcode:** partially specifies the operation to be performed

Could represent something like: $\underset{\text{opcode }}{\text{add}} \underset{\text{rs1}}{\text{x9}}, \underset{\text{rs2}}{\text{x20}}, \underset{\text{rd}}{\text{x21}}$

**Example:** `add x9, x20, x21`

funct7 | rs2 | rs1 | funct3 | rd | opcode
--- | --- | --- | --- | --- | ---
0 | 21 | 20 | 0 | 9 | 51
00000000 | 10101 | 10100 | 000 | 01001 | 0110011


Should be able to convert between these by looking up binary values for opcodes and registers.

### I-Type Instructions
- **Immediate arithmetic/logical instrs**
  - `rs1` is source or base address register number
  - **Immediate:** constant operand, or offset added to base addr **IN BYTES**
    - **Recall `40(a1)` $\rightarrow$ `40 bytes / 4 bytes per int = MEM[10] `**
    - 2's complement, sign-extended to 32 bits

$\underset{\text{12 bits}}{\boxed{\text{immediate}}} \underset{\text{5 bits}}{\boxed{\text{rs1}}} \underset{\text{3 bits}}{\boxed{\text{func3}}} \underset{\text{5 bits}}{\boxed{\text{rd}}} \underset{\text{7 bits}}{\boxed{\text{opcode}}} = \text{32 bits}$

### S-Format Instructions
For store instrs
  
$\underset{\text{7 bits}}{\boxed{\text{immediate[11:5]}}} \underset{\text{5 bits}}{\boxed{\text{rs2}}} \underset{\text{5 bits}}{\boxed{\text{rs1}}} \underset{\text{3 bits}}{\boxed{\text{func3}}} \underset{\text{7 bits}}{\boxed{\text{immediate[4:0]}}} \underset{\text{7 bits}}{\boxed{\text{opcode}}} = \text{32 bits}$

### R-Format Instructions
For register-register arithmetic/logical instrs
  
$\underset{\text{7 bits}}{\boxed{\text{funct7}}} \underset{\text{5 bits}}{\boxed{\text{rs2}}} \underset{\text{5 bits}}{\boxed{\text{rs1}}} \underset{\text{3 bits}}{\boxed{\text{func3}}} \underset{\text{5 bits}}{\boxed{\text{rd}}} \underset{\text{7 bits}}{\boxed{\text{opcode}}} = \text{32 bits}$

### Shift right versus arithmetic shift right
- **Shift right:** `srl` (logical shift right)
  - Shifts in 0s from the left
- **Arithmetic shift right:** `sra`
  - Shifts in copies of the most significant bit from the left

**10101010 >> 2 = 00101010** $\rightarrow \text{versus} \rightarrow$ **10101010 >> 2 (arithmetic) = 11101010**