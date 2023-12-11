# Log Class Overview

The `Log` class is designed to provide logging functionality by displaying messages on the console and writing them to a `log.txt` file along with timestamps.

```lua
+------------------------------------------------+
|                 GMIVLS::Logger                 |
+------------------------------------------------+
| - outputFile : std::ofstream                   |
| - oss : std::ostringstream                     |
| - loglevel : LogLevel(enum)                    |
| - open_file : void                             |
| - close_file : void                            |
| - writeToLog(std::string&) : void              |
| - getLogLevelString(LogLevel) : std::string    |
+------------------------------------------------+
| + Logger() : constructor                       |
| + ~Logger() : destructor                       |
+------------------------------------------------+
| + setLogLevel(LogLevel) : void                 |
| + log(LogLevel, std::string&) : void           |
+------------------------------------------------+
| + operator()(LogLevel) : Logger                |
| + operator<<(std::string&) : Logger            |
+------------------------------------------------+
```

## Features

### Console Logging

The `Log` class includes methods to output log messages directly to the console for real-time monitoring. The log class has three level of logging message, **[INFO] message will written to console with white color**, **[WARN] message will written to console with orange color**, and **[ERR] message will written to consolewith red color**.

### File Logging

Upon instantiation, the `Log` class creates a `log.txt` file if it does not exist in the log directory. When logging a message, the `Log` class appends the message along with a timestamp to the `log.txt` file.

### Operator Overloading

The `<<`, and '()' operators is overloaded to facilitate convenient logging by allowing users to write log messages directly to the log file and console.

## Usage

### Initialization

To use the `Log` class, instantiate an object as follows:

```cpp
#include "Log.h" // Include necessary headers

int main() {
    GMIVLS::Logger LOG; // Instantiate a Log object
    LOG(INFO) << "Logging with operator overload.";           //the message with timestamp will written to console (colored with white) and log.txt
    LOG(WARNING) << "Warn Memory Address, Still Used by Ptr";    // the warning message will written to console (colored orange) and to log.txt file.
    LOG(ERROR) << "Fatal Error, Program Execution Stopped";     // the error message will written to console (coloored red) and to log.txt file

    return 0;
}
```
## Dependencies
- No external dependencies are required beyond standard C++ libraries.

## Contributions and Issues
- Contributions and bug reports are welcome! Please open an issue or pull request on the repository for any improvements or fixes.
-----
## License
- This class is provided under the **[MIT License]** License. Refer to the LICENSE file for more details.
