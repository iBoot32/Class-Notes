## ASM Functions

Recall `jal x1, foo` instr will jump to `foo()` and save returns to x1.

### Stack growth for spill and fill
- Stack actually **GROWS DOWN**, so we subtract from the stack pointer to grow the stack. SP always points to the top of the stack (the last item pushed onto the stack) which is actually the lowest address in the stack.

```asm
addi sp, sp, -12  // move sp down, make room for 3 more regs (4 bytes each)
sw x5, 8(sp)      // make x5 (12 - 4*1) bytes up from sp
sw x6, 4(sp)      // make x6 (12 - 4*2) bytes up from sp
sw x7, 0(sp)      // make x7 (12 - 4*3) bytes up from sp
```

### Stack visualized:
```
...
...
...                               stack grows down
+--------------------+                   |
|                    |                   |
+--------------------+                  \_/
|  reg x5 (4 bytes)  |            
+--------------------+  <- x5 start   
|  reg x6 (4 bytes)  |
+--------------------+  <- x6 start
|  reg x7 (4 bytes)  |
+--------------------+  <- x7 start (sp after first `addi`)
...
...
...
```

### Conventions with regs
- x5-x7 and x28-x31 are temp registers, so they can be overwritten by functions. Alias to t0-a6
- x8-x9 and x18-x27: saved regs, must be preserved by callee. Alias to s0-s11
  - must save to stack before using


# Factorial in ASM
```asm
fact:
  addi sp, sp, -8      // alloc 2 items to stack
  sw x1, 4(sp)         // save x1 (ret addr) to stack
  sw x2, 0(sp)         // save x2 (n) to stack

  addi x5, x10, -1     // x5 = n - 1
  bge x5, x0, L1       // if n - 1 >= 0, goto L1

  addi x10, x0, 1      // else return 1 (x10 = a0 = ret)
  addi sp, sp, 8       // deallocate stack
  jalr x0, 0(x1)       // jump to x1 (ret addr) and link to x0

L1: addi x10, x10, -1  // argument x10 (n) becomes n-1
  jal x1, fact         // jump to fact() with (n-1) and save ret addr to x1
  addi x6, x10, 0      // return from jal: mov results of fact(n-1) to x6
  lw x10, 0(sp)        // restore x10 (n) from stack
  lw x1, 4(sp)         // restore x1 (ret addr) from stack
  addi sp, sp, 8       // deallocate stack
  mul x10, x10, x6     // a0 = x10 = n * fact(n-1) 
  jalr x0, 0(x1)       // go back to fact

```

### How does this work dynamically?

| x10 | sp | x1 | 
| --- | -- | -- |
| 2   | nul  | pointer to main  |
| 1   | x1(=*main), x10(=2)    | pointer to jal+4  |
| 0   | x1(=*main), x10(=2), x1(=*jal+4), x10(=1)    | pointer to jal+4  |

then pop back up the stack

### Frame Pointer
Where did the stack begin when I called this function? We need to know this to access the stack. We can use a frame pointer to keep track of this.
- Functions may have local data that also goes on the stack (local arrays... etc.)
- Useful to know where the stack begins

### Memory space division
- 32-bit address space
- Specific addrs are not a part of the RISC-V spec, but a software convention
- Stack / Heap share same region
  - Stack grows down
  - Heap grows up
- Text segment is read-only and contains the program instructions