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

void HttpData_fake::setHeader(std::shared_ptr<nexusZiaApi::IHttpHeader> header)
{
  this->_header = header;
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

  this->_hooks = std::make_shared<hook_fake>();

  this->_apiServer = std::make_shared<apiServer_fake>(this->_logger, this->_hooks);
}

zia_fake::~zia_fake()
{
}

std::shared_ptr<nexusZiaApi::IAPIServer> & zia_fake::getAPIServer(void)
{
  return this->_apiServer;
}

void zia_fake::loadMyFakeModule()
{
  auto &logEmail = LogEmailZia::LogEmail::Instance();

  logEmail.setAPIServer(this->_apiServer);
  this->_modulesLists.insert({"LogEmail",logEmail});
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

// APIServer
apiServer_fake::apiServer_fake(std::shared_ptr<nexusZiaApi::ILogger> logger, std::shared_ptr<nexusZiaApi::IHooks> hooks)
{
  this->_logger = logger;
  this->_hooks = hooks;
}

apiServer_fake::~apiServer_fake()
{

}

nexusZiaApi::IHooks &apiServer_fake::getHooks(void)
{
  return *this->_hooks;
}

const nexusZiaApi::IHooks &apiServer_fake::getHooks(void) const
{
  return *this->_hooks;
}

nexusZiaApi::ILogger &apiServer_fake::getLogger(void)
{
  return *this->_logger;
}

const nexusZiaApi::ILogger &apiServer_fake::getLogger(void) const
{
  return *this->_logger;
}

// Hooks

hook_fake::hook_fake():
	_types({nexusZiaApi::IHooks::Types::REQUEST_RECEIVER})
{
}

hook_fake::~hook_fake()
{

}

const std::list<nexusZiaApi::IHooks::Types> &hook_fake::getAllHooks(void) const
{
  return this->_types;
}

const std::list<nexusZiaApi::IHooks::Types> &hook_fake::getHooksForModule(const std::string &name) const
{
  return this->_types;
}

void hook_fake::subscribe(const nexusZiaApi::IHooks::Types &type, const std::string &name)
{
}

void hook_fake::unSubscribe(const nexusZiaApi::IHooks::Types &type, const std::string &name)
{
}
