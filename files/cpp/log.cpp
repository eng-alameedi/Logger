#include "../include/log.h"

#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

namespace GMIVLS
{
  Logger::Logger()
  {
    try
      {
        open_file();
        log(INFO, "log file opened");
      }
    catch (std::string& ex)
      {
        log(FATAL, ex);
        std::exit;
      }
  }

  Logger::~Logger()
  {
    try
      {
        close_file();
      }
    catch (std::string& ex)
      {
        log(ERROR, "Error, log file not closed");
      }
  }

  void Logger::setLogLevel(LogLevel level) { logLevel = level; }

  void Logger::log(LogLevel level, const std::string& message)
  {
    if (level >= TRACE)
      {
        std::time_t now = std::time(nullptr);
        char timestamp[100];
        std::strftime(
            timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ",
            std::localtime(&now));
        try
          {
            {
              writeToLog(getLogLevelString(level) + timestamp + message);
            }
          }
        catch (std::string& ex)
          {
            log(ERROR, ex);
          }
      }
  }

  void Logger::writeToLog(const std::string& logMessage)
  {
    if (outputFile.is_open())
      {
        outputFile << logMessage << std::endl;
        outputFile.flush();
      }
    else
      {
        throw "Can't Write to File";
      }
    // Output colored logs to the terminal
    if (logMessage.find("[ERROR]") != std::string::npos)
      {
        std::cout << RED << logMessage << RESET_COLOR << std::endl;
      }
    else if (logMessage.find("[EMERGENCY]") != std::string::npos)
      {
        std::cout << RED << logMessage << RESET_COLOR << std::endl;
      }
    else if (logMessage.find("[WARNING]") != std::string::npos)
      {
        std::cout << YELLOW << logMessage << RESET_COLOR << std::endl;
      }
    else if (logMessage.find("[CRITICAL]") != std::string::npos)
      {
        std::cout << YELLOW << logMessage << RESET_COLOR << std::endl;
      }
    else if (logMessage.find("[DEBUG]") != std::string::npos)
      {
        std::cout << GREEN << logMessage << RESET_COLOR << std::endl;
      }
    else if (logMessage.find("[FATAL]") != std::string::npos)
      {
        std::cout << RED << logMessage << RESET_COLOR << std::endl;
      }
    else
      {
        std::cout << logMessage << std::endl;
      }
  }

  std::string Logger::getLogLevelString(LogLevel level)
  {
    switch (level)
      {
      case TRACE:
        return "[TRACE]";
      case DEBUG:
        return "[DEBUG] ";
      case INFO:
        return "[INFO] ";
      case WARNING:
        return "[WARNING] ";
      case ERROR:
        return "[ERROR] ";
      case CRITICAL:
        return "[CRITICAL]";
      case EMERGENCY:
        return "[EMERGENCY]";
      case FATAL:
        return "[FATAL]";
      default:
        return "[UNKNOWN] ";
      }
  }

  void Logger::open_file()
  {
    std::string filename = "/log.txt";
    std::string logDir = "log";
    // std::string cmd = "mkdir -p " + logDir;
    // std::filesystem::create_directory(logDir);
    if (!std::filesystem::is_directory(logDir))
      {
        std::filesystem::create_directory(logDir);
      }
    // std::system(cmd.c_str());

    if (!outputFile.is_open())
      {
        std::string file = logDir + filename;
        outputFile.open(file.c_str(), std::ios::app);
      }
    else
      throw "File Not Opened";
  }

  void Logger::close_file()
  {
    log(INFO, "log file closed");
    outputFile.close();

    if (outputFile.is_open())
      {
        throw "File Not Closed";
      }
  }
}  // namespace GMIVLS
