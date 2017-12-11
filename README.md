# NexusZiaApi
*More informations about us here: [Nexus-Software](https://www.nexus-software.fr)*

![CPP](https://img.shields.io/badge/C++-11-blue.svg)
[![Build Status](https://travis-ci.org/Nexus-Software/NexusZiaApi.svg?branch=master)](https://travis-ci.org/Nexus-Software/NexusZiaApi)
[![Build status](https://ci.appveyor.com/api/projects/status/493qgqfqck1iqeyx/branch/master?svg=true)](https://ci.appveyor.com/project/aenguerrand/nexusziaapi/branch/master)
[![GitHub Issues](https://img.shields.io/github/issues/Nexus-Software/NexusZiaApi.svg)](https://github.com/Nexus-Software/NexusZiaApi/issues)
[![GitHub Pull Request](https://img.shields.io/github/issues-pr/Nexus-Software/NexusZiaApi.svg)](https://github.com/Nexus-Software/NexusZiaApi/issues)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

Welcome to the Github project of Zia API by Nexus-Software.
This repository is provided with documentation intended to describe the operation of the API and its modules for the Zia project.

This API has been developed in C++ and is comptatible on Linux, MacOS and Windows.

## Dependencies

- C++ 11 Compiler
- CMake

## Try to build API

### Linux
```bash
git clone https://github.com/Nexus-Software/NexusZiaApi.git
cd NexusZiaApi
mkdir build
cd build
cmake ..
cmake --build .
cd ..
mkdir examples/modules/LogEmail/build
cd examples/modules/LogEmail/build
cmake ..
cmake --build .
```

### Windows and MacOS
```bash
git clone https://github.com/Nexus-Software/NexusZiaApi.git
cd NexusZiaApi
mkdir build
cd build
cmake ..
cmake --build .
```

## Contributing

We have collected notes on how to contribute to this project in [CONTRIBUTING.md].

[CONTRIBUTING.md]: CONTRIBUTING.md

## License

NexusZiaApi is released under the [MIT License](http://www.opensource.org/licenses/MIT).
