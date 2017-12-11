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

std::shared_ptr<LogEmailZia::LogEmail> LogEmailZia::LogEmail::_instance = std::make_shared<LogEmailZia::LogEmail>(LogEmailZia::LogEmail());

std::shared_ptr<LogEmailZia::LogEmail>  LogEmailZia::LogEmail::Instance()
{
  return LogEmailZia::LogEmail::_instance;
}

LogEmailZia::LogEmail::LogEmail()
{
}

LogEmailZia::LogEmail::~LogEmail()
{
}

void LogEmailZia::LogEmail::start(void)
{
  // Subscribe Hooks
  this->_apiServer->getHooks().subscribe(nexusZiaApi::IHooks::Types::CONNECTION, "LogEmail");

  this->_apiServer->getLogger().logSuccess("[LOG EMAIL] Module is start");
}

void LogEmailZia::LogEmail::stop(void)
{
  // UnSubscibe Hooks
  this->_apiServer->getHooks().unSubscribe(nexusZiaApi::IHooks::Types::CONNECTION, "LogEmail");

  this->_apiServer->getLogger().logInfo("[LOG EMAIL] Module is stop");
}

void LogEmailZia::LogEmail::reload(void)
{
  this->_apiServer->getLogger().logSuccess("[LOG EMAIL] Module is reload");
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

nexusZiaApi::IHooks::ReturnEvent LogEmailZia::LogEmail::triggerEvent(nexusZiaApi::IHooks::Types type, void *data)
{
  this->getAPIServer().getLogger().logInfo("[LOG EMAIL] Event func trigger");
  if (type == nexusZiaApi::IHooks::Types::CONNECTION) {
      HttpSession * httpSession = static_cast<HttpSession *>(data);
      this->getAPIServer().getLogger().logInfo("[LOG EMAIL] New connection of " + httpSession->getIP());

    }
  return nexusZiaApi::IHooks::ReturnEvent::SUCCESS;
}

extern "C"
{
	LogEmailZia::LogEmail* CObject()
	{
		return (LogEmailZia::LogEmail::Instance().get());
	}

	void DObject(LogEmailZia::LogEmail* obj)
	{
    LogEmailZia::LogEmail::resetInstance();
	}
}