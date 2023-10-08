# More I2C

How a master can read a byte from a slave
![stuff](resources/i2cfollowup.png)
Sends a start bit right after recieving the last ACK after sending data. Then sends the slave address with the read bit set. Then recieves the data byte from the slave, and receives a NACK instead of an ACK to end the transaction. NACK is sent by nobody since 1 is the default state of the bus.