This repo is very much a work-in-progress. 

== How to Use this SDK
======================
1) Clone the repo 
2) Run `cmake && make` in the `./sdk` folder
3) copy the template folder to start your project
4) alter the CMakeLists.txt file according to the comments

== Future features

visual studio project template
C++ support
C++ DLL 
Documentation
eliminating CMSIS
boot-only library -- the core library currently incldes more than just booting. mayebe people would want to skip that all together
have cmake update the vscode `c_cpp_properties.json` file with the 


== About the DDL
Eventually I'd like to have a fully-functional DDL which provides meaningful abstractions around all the hardware modules. Currently this is complicated by
the underlying system architecture. Some devices like the low power timer, watchdog timer, and Capture/Compare module (PCA in the docs) are simple enough and I just havent 
gotten around to it. However a number of the devices are unexpectedly limited, very odd or both. 
Specifically the UART modules are a tough one. These modules are incredibly limited their feature-set having 4 hard-wired 'modes' for controling synch/async, 
full/half duplex, parity bits, start/stop bits. They also lack transmit or recieve buffers and have a baud rate setting which is incredibly complex to calculate.
at the same time they have a non-standard multi-party mode which would be fantastic to expose as its own DDL module.

Why C++
To put it bluntly -- I prefer C++. It would be especially helpful to have templates and classes for dealing with buffers in the uart, multi-party-uart, i2c and spi modules 
