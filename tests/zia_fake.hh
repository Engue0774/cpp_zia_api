/*
** zia_fake.hh for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/zia_fake.hh
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Dec 07 16:57:47 2017 Enguerrand Allamel
** Last update Thu Dec 07 16:57:47 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_ZIA_FAKE_HH
#define CPP_ZIA_API_ZIA_FAKE_HH

#include <unordered_map>
#include <string>
#include <memory>
#include <iostream>
#include "NexusZiaAPI.hpp"

class HttpHeader_fake : public nexusZiaApi::IHttpHeader {
 private:
  std::unordered_map<std::string, std::string>	_data;
 public:
  HttpHeader_fake();

  virtual ~HttpHeader_fake();

  virtual void setKey(const std::string & key, const std::string & value);

  virtual const std::string & getKey(const std::string & key);
};

class HttpData_fake : public nexusZiaApi::IHttpData {
 private:
  std::shared_ptr<nexusZiaApi::IHttpHeader>	_header;
  std::string					_data;
 public:
  HttpData_fake();

  virtual ~HttpData_fake();

  virtual void setHeader(nexusZiaApi::IHttpHeader header);

  virtual nexusZiaApi::IHttpHeader &getHeader(void);

  virtual const nexusZiaApi::IHttpHeader &getHeader(void) const;

  virtual void setBody(const std::string &data);

  virtual const std::string &getBody(void) const;
};

class logger_fake : public nexusZiaApi::ILogger
{
 public:
  logger_fake();

  virtual ~logger_fake();

  virtual void log(const ILogger::Level &level, const std::string &msg);

  virtual void logDefault(const std::string &msg);

  virtual void logInfo(const std::string &msg);

  virtual void logSuccess(const std::string &msg);

  virtual void logWarning(const std::string &msg);

  virtual void logError(const std::string &msg);

  virtual void logFatalError(const std::string &msg);
};

class zia_fake
{
 private:
  std::shared_ptr<nexusZiaApi::ILogger>	_logger;
 public:
  zia_fake();
  virtual ~zia_fake();
};


#endif //CPP_ZIA_API_ZIA_FAKE_HH
