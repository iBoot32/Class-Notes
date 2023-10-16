# assembly

### Register conventions
- We can specify register names that are different than x0-x31... for example a0-a7 or t0-t6. Those are just aliases for the same registers.

All add/subtract/etc. operations are operations on REGISTERS. So how do we put values into registers? Recall "add immediate" from the previous lecture. We can use that to put values into registers along with "load immediate". 

### Immediates
` li x10, 10` $\rightarrow$ `x10 = 10`

Example:
```asm
main:
    li x10, 10
    li x11, 20
    add x12, x10, x11
```
Now, `x12 = 30`

Basically this `li` instruction is just a shortcut for `addi x10, x0, 10`.

### Addressing Mode
An addressing mode basically defines how an instruction gets operand values. We have seen two: **Register addressing**: read value from a reg, and **Immediate addressing**: read value from a constant burned into the instruction. ISAs have separate instructions for accessing memory to keep the instruction set simple.


### Some common architectures
How to compute `z = x + y`?

**Accumulator (from memory):**
```asm
    loadA x
    addA y
    storeA z
```

**Reg/reg:**
```asm
    load r1, x
    load r2, y
    add r3, r1, r2
    store r3, z
```

# Basic Memory Instructions
| Operation type | Example | Equivalence | Description |
|:--------:|:--------:|:--------:|:--------:|
| Load word | `lw x5, 40(x6)` | `x5 = MEM[x6 + 40]` | Word from memory to register |
| Load word, unsigned | `lwu x5, 40(x6)` | `x5 = MEM[x6 + 40]` | Word from memory to register UNSIGNED|
| Store word | `sw x5, 40(x6)` | `MEM[x6 + 40] = x5` | Word from register to memory |

To remember:
```asm
    // C statement: g = h + A[8]
    // Assume g in h3, h in h2
    lw a0, 32(a1) // get a[8] since (sizeof(int))= 4 -> 8 * 4 = 32
    add a3, a0, a2
```

There are also unsigned, halfword, load byte, load word left, etc. instructions.

If we have a 16-bit val and want to sign extend it, we take the most significant bit and copy it to the left. If we want to zero extend it, we just add 0s to the left.