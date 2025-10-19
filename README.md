# libjdk - Java RMI Library

![License](https://img.shields.io/badge/license-GPL%20v2%20with%20Classpath%20Exception-green.svg)
![Platforms](https://img.shields.io/badge/platforms-Windows%20|%20Linux%20|%20macOS-lightgrey.svg)

[**libjdk**](https://github.com/libjdk/libjdk) is a comprehensive C++ implementation of the Java Development Kit (JDK), providing native C++ libraries that mirror the functionality of Java's core libraries and modules. While it provides Java-like APIs, it runs as native C++ code without requiring a Java Virtual Machine.

## Overview

This project provides a complete C++ implementation of Java's RMI functionality, including:

- **Remote Objects**: Remote object implementation and management
- **RMI Registry**: Service registry for remote object lookup
- **Serialization**: Object serialization for network transmission
- **Dynamic Proxy**: Dynamic proxy generation for remote interfaces
- **Security**: RMI security and authentication
- **Performance**: High-performance distributed computing with minimal latency

## Features

- ✅ **Cross-platform Support**: Windows, Linux, and macOS
- ✅ **CMake Build System**: Modern, portable build configuration
- ✅ **Comprehensive Testing**: Extensive test suite included
- ✅ **OpenJDK Compatible**: Based on OpenJDK 17.35
- ✅ **GPL Licensed**: Free software with Classpath exception

## Dependencies

- **java.base**: Core Java functionality (required)
- **java.logging**: Logging framework (required)

## Project Structure

```
java.rmi/
├── main/                   # Main source code
│   ├── share/              # Platform-independent code
│   │   ├── classes/         # Java class implementations
│   │   ├── include/         # Header files
│   │   └── native/          # Native implementations
│   ├── windows/             # Windows-specific code
│   ├── linux/               # Linux-specific code
│   └── macos/               # macOS-specific code
├── test/                    # Test suite
├── legal/                   # Legal notices and licenses
└── CMakeLists.txt           # Build configuration
```

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new functionality
5. Ensure all tests pass
6. Submit a pull request

## License

This project is licensed under the GNU General Public License v2 with the Classpath exception, allowing linking with proprietary software. See the [LICENSE](LICENSE) file for details.

## Legal Notices

This project includes code from various open source projects. See the [legal/](legal/) directory for detailed licensing information for each component.