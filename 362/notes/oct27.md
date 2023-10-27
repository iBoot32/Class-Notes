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