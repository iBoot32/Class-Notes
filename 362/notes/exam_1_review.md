# Intro to GPIO
- GPIO stands for General Purpose Input/Output
- Can see if external voltage applied, can drive a voltage, etc.

GPIO pin physical structure
- GPIO output bit -> Controller -> P/NMOS (PMOS VCC, NMOS ground) -> Output Pin
  - Controller will invert the bit before sending it to the PMOS/NMOS
    - Aka to drive a 1, we need the PMOS to be on and the NMOS to be off
    - To drive a 0, controller drives NMOS on, resulting in draining external current to ground

### Know what each element of the GPIO pin actually does
![gpio](resources/gpio.png)

### BSRR
- 16 bits for setting
- 16 bits for resetting
  
### BRR
- lower 16 bits for resetting

***

- Open-Drain
  - If in open-drain and writing a 1, the NMOS is not on so output floats
  - If in open-drain and writing a 0, the NMOS is on and output is grounded
  - PMOS is always off

- Slew Rate
  - Max rate of change of output voltage: $\text{Slew Rate} = \text{Max}(\frac{\triangle V}{\triangle t})$
  - Aka the ramp up/down rate of the output voltage

Pull Up/Down Resistors
- If external circuit only pulls low, we need a pull up resistor to pull high
- If external circuit only pulls high, we need a pull down resistor to pull low and drain off excess current
- Very high resistance so that it doesn't interfere with the external circuit until we want it to

Port-mapped versus memory-mapped I/O
- Port-mapped I/O: Every peripheral has a unique address
- Memory-mapped I/O: Every peripheral has a unique address, but it is in the same address space as the memory

# Interrupts
*Instead of polling, we can use interrupts to handle events*

Program Counter
- Holds the address of the next instruction to be executed

Interrupts
- Stored in the interrupt vector table
- Each interrupt has a set **priority**, **enable**, and **pending** bit
- Interrupt flow:
    1. Peripheral raises interrupt
    2. Enabled?
    3. Pending gets asserted
    4. Priority is checked
    5. if higher priority than current interrupt, then interrupt is taken and CPU state is pushed to stack
    6. Interrupt handler is executed via writing to the PC

### Nested Interrupt flow:
- Since ISR 1 finishes / has higher priority before ISR2 is raised, CPU state is only saved during Main Program Execution.
![nested interrupt](resources/nested_interrupts.png)

# Timers
Systick timer has a LOAD register, which is the value that the timer counts down from. When it reaches 0, it will reset to the value in the LOAD reg. 

**TIME PERIOD FOR SYSTICK**: $T = \frac{LOAD + 1}{f_{clk}}$ since we need a cycle to reset the timer on interrupt

![systick](resources/systick.png)

Calculating things about systick:
- **CALCULATE RELOAD FOR A SPECIFIC INTERVAL**: $\text{RELOAD} = \frac{Goal Time}{Period_{clk}} - 1$
- **IF HAVE PRESCALER**: $\text{RELOAD} = \frac{Goal Time}{Period_{clk} * \text{(Prescalar + 1)}} - 1$

# Debouncing
- Hardware: RC filter
- Software: Delay or prior state tracking using binary
- if 10ms bound, and we scan one of four rows every 1ms, worst possible byte history is: 00000101. 

# Multiplexing Seven Segment Display
![7seg](resources/muxssd.png)

Top FETs determine which digit is being displayed, bottom sink registers determine which segments are on

# DAC - Digital to Analog Converter
### Formula for Conversion from Digital to Analog
$$ \boxed{DAC_{out} = V_{ref} * \frac{\text{Digital Value}}{2^n - 1}} $$

Fixed Point Representation of Numbers

$$ \overset{\boxed{128}}{\boxed{0}} \overset{\boxed{64}}{\boxed{1}} \overset{\boxed{32}}{\boxed{0}} \overset{\boxed{16}}{\boxed{1}} \overset{\boxed{8}}{\boxed{1}} \overset{\boxed{4}}{\boxed{1}} \overset{\boxed{2}}{\boxed{0}} \overset{\boxed{1}}{\boxed{1}} \text{ . } \overset{\boxed{1/2}}{\boxed{1}} \overset{\boxed{1/4}}{\boxed{0}} \overset{\boxed{1/8}}{\boxed{1}} \overset{\boxed{1/16}}{\boxed{0}} \overset{\boxed{1/32}}{\boxed{0}} \overset{\boxed{1/64}}{\boxed{0}} \overset{\boxed{1/128}}{\boxed{0}} \overset{\boxed{1/256}}{\boxed{0}}  = \text{93.525}$$

*Note: Standard binary addition and subtraction works for fixed point numbers, but multiplication needs a corrective shift. Fixed-point is also INEXACT.*

### Physical DAC Structure
![dac](resources/dac.png)

X_n is the digital input, which is fed from a NMOS/PMOS switch. The switch is controlled by the digital input. The output is the voltage at V_out.

**Calculate acceptable error in DAC resistors:** $\text{Error} = \frac{1}{2^n - 1}$

**Frequency of DAC:** $f_{DAC} = \frac{samples/sec}{\text{samples per cycle}}$

### What can we use DAC for?
- Slow things
  - process control, etc.
- DAC can be updated very quickly (100k+/sec)
  - Audio, video, etc.

# ADC: CT to DT Conversion

### ADC Resolution:
$$ \boxed{\text{ADC Out} = \text{round(}(2^{n} - 1) * \frac{V_{input}}{V_{REF}} \text{)}} $$

### Example for 10-bit ADC, V_in = 1V, V_REF = 5V: 

$\text{ADC Out} = \text{round(}(2^{10} - 1) * \frac{1}{5} \text{)} = \text{round(204.6) = 205 = 0xCD}$

**Least significant bit voltage:** $\frac{V_{REF}}{2^n - 1}$
- This is the smallest voltage change that the ADC can detect

**Max quantization error:** $\frac{1}{2} * \frac{V_{REF}}{2^n - 1} = \frac{1}{2} * \text{LSB}$

![quantization](resources/quant.png)

### ADC Sampling Rate
- **Nyquist Sampling Theorem:** Sampling rate must be at least twice the highest frequency component of the signal

### ADC Structure
- Successive Approximation Register (SAR) ADC
![sar](resources/sar.png)

Will start at MSB and work its way down to LSB, comparing the output of the DAC to the input voltage. If the DAC output is greater than the input voltage, then the bit is set to 0. If the DAC output is less than the input voltage, then the bit is set to 1.

### Determine Minimum Sampling Time
Want to settle to within 1/2 LSB (one max quantization error) of the input voltage.

Has a sampling period, and then will repeatedly check if V_sample is higher/lower than V_dac, and adjust V_dac via setting bits accordingly.
![converge](resources/converge.png)

### Jitter
- Jitter is the variation in the sampling period
- Can be caused by noise, etc.
- Can be reduced by averaging multiple samples via boxcar averaging