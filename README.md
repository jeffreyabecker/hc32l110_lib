This repo is very much a work-in-progress. 

higher level goals: 

boot code & ddl available as libs
cmake build
cmake project template
visual studio project template


About the DDL:
Eventually I'd like to have a fully-functional DDL which provides meaningful abstractions around all the hardware modules. Currently this is complicated by
the underlying system architecture. Some devices like the low power timer, watchdog timer, and Capture/Compare module (PCA in the docs) are simple enough and I just havent 
gotten around to it. However a number of the devices are unexpectedly limited, very odd or both. 
Specifically the UART modules are a tough one. These modules are incredibly limited their feature-set having 4 hard-wired 'modes' for controling synch/async, 
full/half duplex, parity bits, start/stop bits. They also lack transmit or recieve buffers and have a baud rate setting which is incredibly complex to calculate.
at the same time they have a non-standard multi-party mode which would be fantastic to expose as its own DDL module.

