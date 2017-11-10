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

namespace nexusApi {
	class ILogger
	{
	  enum class Level
	  {
		DEFAULT 		= 0,
		INFO 			= 1,
		SUCCESS			= 2,
		WARNING 		= 3,
		ERROR			= 4,
		FATAL_ERROR 	= 5
	  };

	  virtual ~ILogger() = default;

	  virtual log(const ILogger::Level &, const std::string &) = 0;

	  virtual logDefault(const std::string &) = 0;
	  virtual logInfo(const std::string &) = 0;
	  virtual logSuccess(const std::string &) = 0;
	  virtual logWarning(const std::string &) = 0;
	  virtual logError(const std::string &) = 0;
	  virtual logFatalError(const std::string &) = 0;
	};
}

#endif //CPP_ZIA_API_LOGGER_HPP
