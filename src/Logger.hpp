/*
** Logger.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/Logger.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Nov 10 13:28:22 2017 Enguerrand Allamel
** Last update Fri Nov 10 13:28:22 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_LOGGER_HPP
#define CPP_ZIA_API_LOGGER_HPP

#include <string>

namespace ziaAPINexus {
class ILogger {
  enum class Level {
	DEFAULT = 0,
	INFO = 1,
	SUCCESS = 2,
	WARNING = 3,
	ERROR = 4,
	FATAL_ERROR = 5
  };

  virtual ~ILogger() = default;

  /**
   * Log message
   * @param level Type of log
   * @param msg Message
   */
  virtual void log(const ILogger::Level & level, const std::string & msg) = 0;

  /**
   * Log default message
   * @param msg
   */
  virtual void logDefault(const std::string & msg) = 0;
  /**
   * Log info message
   * @param msg
   */
  virtual void logInfo(const std::string & msg) = 0;
  /**
   * Log success message
   * @param msg
   */
  virtual void logSuccess(const std::string & msg) = 0;
  /**
   * Log warning message
   * @param msg
   */
  virtual void logWarning(const std::string & msg) = 0;
  /**
   * Log error message
   * @param msg
   */
  virtual void logError(const std::string & msg) = 0;
  /**
   * Log fatal error message
   * @param msg
   */
  virtual void logFatalError(const std::string & msg) = 0;
};
}

#endif //CPP_ZIA_API_LOGGER_HPP
