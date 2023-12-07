#pragma once

#include <ostream>
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET_COLOR "\033[0m"

#include <fstream>
#include <string>

enum class LogLevel
{
  INFO,
  WARNING,
  ERROR
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

  Logger& operator<<(const std::string&);
  Logger& operator()(LogLevel&&);

 private:
  std::ofstream outputFile;
  LogLevel logLevel;

  void writeToLog(const std::string&);
  std::string getLogLevelString(LogLevel);
};
