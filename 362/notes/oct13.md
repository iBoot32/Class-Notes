# Assembly Language

### High Level Languages get compiled down into Assembly Language into binary code
High Level Language -> Assembly Language -> Machine Language

### Basic Division of Hardware
- **In space:** Control Unit, ALU, Memory
- **In time:** Fetch the instruction, Decode the instruction, Read the operands, Execute the instruction, Store the result. Then determine the next instruction to fetch.
  
    `add r1, r2, r3` $\rightarrow$ `r1 = r2 + r3`

All machines will fetch the instruction from addr in PC, execute, and then increment the PC.

### ISA: Instruction Set Architecture
- Set of operations visible to the software (compiler)
- ISA is the interface between the hardware and the software
- types:
  - CISC (Complex Instruction Set Computer)
  - RISC (Reduced Instruction Set Computer)
  - DSP (Digital Signal Processor)