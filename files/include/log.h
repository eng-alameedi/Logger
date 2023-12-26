/* @log.h file is the header
 * file for the logger project
 * which contain a logger file
 * that implement an output
 * method as a log with logLevel
 * and the log message out on
 * console and on txt file
 * */

#ifndef _LOG_H_
#define _LOG_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

//! definition of colors for log severity
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET_COLOR "\033[0m"
#define GREEN "\033[1;32m"

//! an enum for the log level.
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

//! define the variables, so the enum can called without the name LogLevel
#define TRACE LogLevel::TRACE
#define DEBUG LogLevel::DEBUG
#define INFO LogLevel::INFO
#define WARNING LogLevel::WARNING
#define ERROR LogLevel::ERROR
#define CRITICAL LogLevel::CRITICAL
#define EMERGENCY LogLevel::EMERGENCY
#define FATAL LogLevel::FATAL

namespace GMIVLS
{
  //! the logger class definition
  class Logger
  {
   public:
    Logger();
    ~Logger();
    //! this is the public methods definition
    void setLogLevel(LogLevel);
    void log(LogLevel, const std::string&);

#include "operator.tpp"

   private:
    std::ofstream outputFile;
    LogLevel logLevel;
    std::ostringstream oss;
    //! this is the private methods definition
    void open_file();
    void close_file();
    void writeToLog(const std::string&);
    std::string getLogLevelString(LogLevel);
  };

}  // namespace GMIVLS
#endif  // _LOG_H_
