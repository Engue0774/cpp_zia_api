/*
** LogEmail.cpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/LogEmail.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Dec 07 15:42:48 2017 Enguerrand Allamel
** Last update Thu Dec 07 15:42:48 2017 Enguerrand Allamel
*/

#include "LogEmail.hpp"

LogEmailZia::LogEmail LogEmailZia::LogEmail::_instance = LogEmailZia::LogEmail();

LogEmailZia::LogEmail&  LogEmailZia::LogEmail::Instance()
{
  return LogEmailZia::LogEmail::_instance;
}

LogEmailZia::LogEmail::~LogEmail()
{
  std::cout << "LogEmail CTOR" << std::endl;
}

LogEmailZia::LogEmail::LogEmail()
{
  std::cout << "LogEmail DTOR" << std::endl;
}

nexusZiaApi::IHooks::ReturnEvent LogEmailZia::LogEmail::event_REQUEST_RECEIVER(nexusZiaApi::IHttpData & data)
{
  auto& logEmail = LogEmailZia::LogEmail::Instance();

  logEmail._apiServer.get()->getLogger().logInfo("Event REQUEST_RECEIVER");
  return nexusZiaApi::IHooks::ReturnEvent::SUCCESS;
}

void LogEmailZia::LogEmail::start(void)
{
}

void LogEmailZia::LogEmail::stop(void)
{
}

void LogEmailZia::LogEmail::reload(void)
{
}

void LogEmailZia::LogEmail::setName(const std::string &name)
{

}

nexusZiaApi::IModuleConfig &LogEmailZia::LogEmail::getModuleConfig(void)
{
  return *this->_moduleConfig;
}

void LogEmailZia::LogEmail::setAPIServer(std::shared_ptr<nexusZiaApi::IAPIServer> apiServer)
{
  this->_apiServer = apiServer;
}

nexusZiaApi::IAPIServer &LogEmailZia::LogEmail::getAPIServer(void)
{
  return *this->_apiServer;
}


