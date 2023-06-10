<div align=center>

<img src="assets/projectoLogo.png" alt="logo" width="300">

<br>

[![codecov](https://codecov.io/github/zeshan-ops/projecto/branch/main/graph/badge.svg?token=7LSFDVM1F6)](https://codecov.io/github/zeshan-ops/project-management-cli-tool)

***WORK IN PROGRESS***

</div>


---

Projecto is a command line interface tool for managing coding projects; like a very simple and stripped back [Taskwarrior](https://github.com/GothenburgBitFactory/taskwarrior). Each project consists of tasks and logs. Tasks can be added, edited and deleted, logs can be added and deleted and there are different views that can be output to the terminal.

This application is written in C++ and makes use of the following libraries:
- [Nlohmann JSON](https://github.com/nlohmann/json) - for data storage
- [Doctest](https://github.com/doctest/doctest) - for unit testing
- [Howard Hinnant Date](https://github.com/HowardHinnant/date) - for date-type capabilities. (This is now integrated with C++20, but Apple Clang does not have full support for all of its features yet, so this library is included for greater compatability with compilers).

## Installation
T.B.A

## Documentation
**Usage**:
- [Command list](docs/usage/projectoCommandList.md)

**Design**:
- [Software Design Document](docs/design/softwareDesignDocument.md)

## License
This software is distributed under the MIT license. See [license](LICENSE) for details.






