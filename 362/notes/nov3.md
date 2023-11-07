### What happens upon an interrupt?

- NVIC decides whether to run the ISR (recall that)
- **SOME** regs are dumped to stack to save the CPU state, but not all due to time and mem constraints
- Every processor has a way to come back from the ISR

