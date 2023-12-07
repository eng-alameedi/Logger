#include "../include/log.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

// Logger::Logger(const std::string& filename, LogLevel level) : logLevel(level)
Logger::Logger()
{
  std::string filename = "/log.txt";
  std::string logDir = "log";
  std::string cmd = "mkdir -p " + logDir;
  std::system(cmd.c_str());

  if (!outputFile.is_open())
    {
      std::string file = logDir + filename;
      // std::cout << file << std::endl;
      outputFile.open(file.c_str(), std::ios::app);
    }
  else
    std::cout << "Error: Can't open file";
}

Logger::~Logger()
{
  if (outputFile.is_open())
    {
      outputFile.close();
    }
  else
    std::cout << "Files Closed...!" << std::endl;
}

void Logger::setLogLevel(LogLevel level) { logLevel = level; }

void Logger::log(LogLevel level, const std::string& message)
{
  if (level >= logLevel)
    {
      std::time_t now = std::time(nullptr);
      char timestamp[100];
      std::strftime(
          timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S] ",
          std::localtime(&now));

      writeToLog(getLogLevelString(level) + timestamp + message);
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
      std::cout << "Can't Find the File" << std::endl;
    }
  // Output colored logs to the terminal
  if (logMessage.find("[ERROR]") != std::string::npos)
    {
      std::cout << RED << logMessage << RESET_COLOR << std::endl;
    }
  else if (logMessage.find("[WARNING]") != std::string::npos)
    {
      std::cout << YELLOW << logMessage << RESET_COLOR << std::endl;
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
    case INFO:
      return "[INFO] ";
    case WARN:
      return "[WARNING] ";
    case ERR:
      return "[ERROR] ";
    default:
      return "[UNKNOWN] ";
    }
}

Logger& Logger::operator<<(const std::string& message)
{
  log(this->logLevel, message);
  return (*this);
}

Logger& Logger::operator()(LogLevel&& lev_el)
{
  this->setLogLevel(lev_el);
  return (*this);
}
