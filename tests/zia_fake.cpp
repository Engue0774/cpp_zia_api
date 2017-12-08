/*
** zia_fake.cpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/zia_fake.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Dec 07 16:57:47 2017 Enguerrand Allamel
** Last update Thu Dec 07 16:57:47 2017 Enguerrand Allamel
*/

#include "zia_fake.hh"

// HttpHeader

HttpHeader_fake::HttpHeader_fake()
{}

HttpHeader_fake::~HttpHeader_fake()
{

}

void HttpHeader_fake::setKey(const std::string &key, const std::string &value)
{
  this->_data.insert({key, value});
}

const std::string &HttpHeader_fake::getKey(const std::string &key)
{
  return this->_data.at(key);
}

// HttpData

HttpData_fake::HttpData_fake()
{
}

HttpData_fake::~HttpData_fake()
{

}

void HttpData_fake::setHeader(nexusZiaApi::IHttpHeader header)
{
  *this->_header = header;
}

nexusZiaApi::IHttpHeader &HttpData_fake::getHeader(void)
{
  return *this->_header;
}

const nexusZiaApi::IHttpHeader &HttpData_fake::getHeader(void) const
{
  return *this->_header;
}

void HttpData_fake::setBody(const std::string &data)
{
  this->_data = data;
}

const std::string &HttpData_fake::getBody(void) const
{
  return this->_data;
}

// Zia Fake
zia_fake::zia_fake()
{
  this->_logger = std::make_shared<logger_fake>();
  this->_logger->logSuccess("Server is run");
}

zia_fake::~zia_fake()
{
}

//Logger

logger_fake::logger_fake()
{}

logger_fake::~logger_fake()
{

}

void logger_fake::log(const nexusZiaApi::ILogger::Level &level, const std::string &msg)
{
  if (level == nexusZiaApi::ILogger::Level::INFO) {
      this->logInfo(msg);
    }
  else if (level == nexusZiaApi::ILogger::Level::SUCCESS) {
      this->logSuccess(msg);
    }
  else if (level == nexusZiaApi::ILogger::Level::WARNING) {
      this->logWarning(msg);
    }
  else if (level == nexusZiaApi::ILogger::Level::ERROR) {
      this->logError(msg);
    }
  else if (level == nexusZiaApi::ILogger::Level::FATAL_ERROR) {
      this->logFatalError(msg);
    }
  else {
      this->logDefault(msg);
    }
}

void logger_fake::logDefault(const std::string &msg)
{
  std::cout << "[ZIA] ";
  std::cout << msg;
  std::cout << std::endl;
}

void logger_fake::logInfo(const std::string &msg)
{
  std::cout << "[ZIA] ";
  std::cout << "[INFO] ";
  std::cout << msg;
  std::cout << std::endl;
}

void logger_fake::logSuccess(const std::string &msg)
{
  std::cout << "[ZIA] ";
  std::cout << "[SUCCESS] ";
  std::cout << msg;
  std::cout << std::endl;
}

void logger_fake::logWarning(const std::string &msg)
{
  std::cout << "[ZIA] ";
  std::cout << "[WARNING] ";
  std::cout << msg;
  std::cout << std::endl;
}

void logger_fake::logError(const std::string &msg)
{
  std::cout << "[ZIA] ";
  std::cout << "[ERROR] ";
  std::cout << msg;
  std::cout << std::endl;
}

void logger_fake::logFatalError(const std::string &msg)
{
  std::cout << "[ZIA] ";
  std::cout << "[FATAL ERROR] ";
  std::cout << msg;
  std::cout << std::endl;
}
