[![Build Status](https://travis-ci.org/azriel91/sl_ax_engine.svg?branch=master)](https://travis-ci.org/azriel91/sl_ax_engine) [![Build Status](https://webapi.biicode.com/v1/badges/azriel/azriel/sl_ax_engine/master)](https://www.biicode.com/azriel/sl_ax_engine)

## sl\_ax\_engine

Top level block for the Autexousious engine.

## Development

This is implemented as a [CppMicroServices](https://github.com/saschazelzer/CppMicroServices) module, and is built using
[biicode](https://www.biicode.com/).

### Requirements

* [biicode](https://www.biicode.com/downloads)
* [CMake](http://www.cmake.org/install/)
* [g++ 4.8](https://gcc.gnu.org/)

### Building

After cloning, in the repository directory run the following to initialize this as a biicode block:

	bii init -l

Depending on whether you wish to build the block as a static or dynamic CppMicroServices module, run configure with the `BUILD_SHARED_LIBS` flag set to `OFF` or `ON`. If you leave the flag out, it defaults to `OFF`.

	bii configure -DBUILD_SHARED_LIBS=ON

Finally to build the library and test executable, run:

	bii build

The test executable will be output as `bin/azriel_sl_core_application_test_main`.

## License

Copyright (c) Azriel Hoh. Licensed under the [Apache License v2.0](http://www.apache.org/licenses/LICENSE-2.0).
