# Compiling and using libpcap on Haiku

Haiku R1/beta4 and earlier versions do not support packet capture on the
loopback interface.  In the master branch this works since hrev57585 and
is expected to work in R1/beta5 when it becomes available.  Packet timestamping
and filtering always occur in userland.  Wireless monitor mode is not
supported.
[**pcap_set_buffer_size**](https://www.tcpdump.org/manpages/pcap_set_buffer_size.3pcap.html)(3PCAP)
has no effect.
[**pcap_setdirection**](https://www.tcpdump.org/manpages/pcap_setdirection.3pcap.html)(3PCAP)
is not supported.
[**pcap_inject**](https://www.tcpdump.org/manpages/pcap_inject.3pcap.html)(3PCAP)
is not supported.

## 64-bit x86 R1/beta4

* Autoconf 2.71 works.
* CMake 3.28.3 works.
* GCC 13.2.0 works.
* Clang 12.0.1 works with the latest llvm12_clang-12.0.1-5 version.
* flex 2.6.4 works.
* bison 3.8.2 works.

The following command will install respective non-default packages:
```
pkgman install cmake llvm12_clang
```

For reference, the tests were done using a system installed from
`haiku-r1beta4-x86_64-anyboot.iso`.

## 32-bit x86 R1/beta4

* Autoconf 2.71 works.
* CMake 3.24.2 works.
* GCC 11.2.0 works.
* Clang does not work.
* flex 2.6.4 works.
* bison 3.0.5 works.

The following command will install respective non-default packages:
```
pkgman install cmake_x86
```

For reference, the tests were done using a system installed from
`haiku-r1beta4-x86_gcc2h-anyboot.iso`.
