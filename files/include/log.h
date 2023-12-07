#pragma once

#include <ostream>
#include <sstream>
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET_COLOR "\033[0m"

#include <fstream>
#include <iostream>
#include <string>
enum class LogLevel
{
  TRACE,
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  CRITICAL,
  EMERGENCY,
  FATAL
};

#define WARN LogLevel::WARNING
#define INFO LogLevel::INFO
#define ERR LogLevel::ERROR

class Logger
{
 public:
  // Logger(const std::string&, LogLevel);
  Logger();
  ~Logger();

  void setLogLevel(LogLevel);
  void log(LogLevel, const std::string&);

  template <typename T>
  Logger& operator<<(const T& value)
  {
    if (this->logLevel <= LogLevel::FATAL)
      {
        std::ostringstream oss;
        oss << value;
        log(this->logLevel, oss.str());
      }
    return *this;
  }

  Logger& operator<<(std::ostream& (*manipulator)(std::ostream&))
  {
    manipulator(std::cout);  // Handle manipulators like std::endl
    // manipulator(oss);
    // log(this->logLevel, oss.str());
    return *this;
  }

  Logger& operator()(LogLevel&&);

 private:
  std::ofstream outputFile;
  // std::ostringstream oss;
  LogLevel logLevel;

  void writeToLog(const std::string&);
  std::string getLogLevelString(LogLevel);
};
