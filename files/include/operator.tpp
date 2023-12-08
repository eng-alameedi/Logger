    template <typename T>
    Logger& operator<<(const T& value)
    {
      if (this->logLevel <= LogLevel::FATAL)
        {
          //std::ostringstream oss;
          oss << value;

          log(this->logLevel, oss.str());
        }
      return *this;
    }
    /*
    Logger& Logger::operator<<(std::ostream& (*manipulator)(std::ostream&))
    {
      if (manipulator == std::endl<char, std::char_traits<char> >)
        std::cout << std::endl;  // Handle manipulators like std::endl
      return *this;
    }
    */

    Logger& operator()(LogLevel&& lev)
    {
      this->setLogLevel(lev);
      return(*this);
    }
