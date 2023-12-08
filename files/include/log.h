#ifndef _LOG_H_
#define _LOG_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET_COLOR "\033[0m"
#define GREEN "\033[1;32m"

enum LogLevel
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

#define DEB LogLevel::DEBUG
#define INFO LogLevel::INFO
#define WARN LogLevel::WARNING
#define ERR LogLevel::ERROR

namespace GMIVLS
{

  class Logger
  {
   public:
    Logger();
    ~Logger();

    void setLogLevel(LogLevel);
    void log(LogLevel, const std::string&);

    // Logger& operator()(LogLevel&&);
    // template <typename T>
    // Logger& operator<<(const T&);
#include "operator.tpp"
   private:
    std::ofstream outputFile;
    LogLevel logLevel;
    std::ostringstream oss;
    void open_file();
    void close_file();
    void writeToLog(const std::string&);
    std::string getLogLevelString(LogLevel);
  };

}  // namespace GMIVLS
#endif  // _LOG_H_