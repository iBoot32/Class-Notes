Encoding logical operations

`srl a1, a0, a3` $\rightarrow$ Shift a0 by a3 bits to the right

Pseudo instructions:
- `li a0, 0xdead0007` is a pseudo instruction for `lui a0, 0xdead` and `addi a0, a0, 7` since it accomplishes the same thing as the two instructions

Branching
- `beq` and `bne` are the only branching instructions (branch if equal and branch if not equal)
- `beq rs1, rs2, label` $\rightarrow$ if rs1 == rs2, branch to label

# Branching Equivalence between C and ASM

```c
while (save[i] == k)
    i += 1;
```
1. load some value into a register from array
2. compare that value to k
3. if equal, branch to the beginning of the loop
4. if not equal, continue to the next instruction

```assembly
// a0 = i, a1 = k, s1 = base addr of "save"
// t0 starts at 0, a0 starts at 0

loop: slli  t0, a0, 2       // t0 = "i" * 4 to get to next element
      add   t0, t0, s1      // t0 = addr of save[i]
      lw    t2, 0(t0)       // temp t2 = save[i]
      bne   t2, a1, exit    // if save[i] != k, branch to done
      addi  a0, a0, 1       // i += 1 for next iteration
      beq   x0, x0 loop
exit:
```

### Definition of a Basic Block
A basic block is a sequence of instructions with no branches in except at the beginning and no branches out except at the end.
```assembly
-------------------------------------------------------------------------
loop: slli  t0, a0, 2       // t0 = "i" * 4 to get to next element
      add   t0, t0, s1      // t0 = addr of save[i]
      lw    t2, 0(t0)       // temp t2 = save[i]
      bne   t2, a1, exit    // if save[i] != k, branch to done
-------------------------------------------------------------------------
      addi  a0, a0, 1       // i += 1 for next iteration
      beq   x0, x0 loop
-------------------------------------------------------------------------
exit:
-------------------------------------------------------------------------
```
***

### Testing for equality
Be aware we could be comparing signed or unsigned numbers. We need to use different instructions for each case.

| Instruction  | Meaning                                  |
|--------------|------------------------------------------|
| `beq`        | SB Branch Equal                          |
| `bge`        | SB Branch Greater than or Equal          |
| `bgeu`       | SB Branch Greater than or Equal Unsigned |
| `blt`        | SB Branch Less Than                      |
| `bltu`       | SB Branch Less Than Unsigned             |
| `bne`        | SB Branch Not Equal                      |

### Dynamic Branch Targets
Sometimes you don't know where you're going to branch to until you execute the instruction! SO we can use an instr uses the value inside a reg to determine where to branch to.

## So far we have covered:
1. Basic math
2. Basic logic
3. Basic control flow (branching)

But real programs need support for higher level constructs like: **function calls** (pass arguments, jumping to callers, put result somewhere caller can see it), **return** (dynamic branching)

And some not-so-obvious things like **Spilling/Filling** registers 

### Examples:

```c
int main() {
    int x = foo(5, 7);
    return x;
}

int foo(int x, int y) {
    return x + y;
}
```

```asm
li x10, 5               // pass 5 as arg 1
li a1, 7                // pass 7 as arg 2
jal x1, foo             // jump and link to foo, x1 is ret addr

foo:
    add a0, x10, a1

jalr x0, 0(x1)          // return to caller

```