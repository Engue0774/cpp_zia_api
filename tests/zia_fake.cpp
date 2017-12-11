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

// Zia Fake
zia_fake::zia_fake()
  #ifdef __linux__
:
  _loader("ModuleCore Loader", true)
  #endif
{
  this->_logger = std::make_shared<logger_fake>();
  this->_logger->logSuccess("Server is run");

  this->_hooks = std::make_shared<hook_fake>();


  this->_apiServer = std::make_shared<apiServer_fake>(this->_logger, this->_hooks);
}

zia_fake::~zia_fake()
{
  this->_logger->logInfo("Server stoping ...");
  for (auto it : this->_modulesLists) {
    it.second->stop();
  }
  this->_logger->logInfo("Goodbye");
}

std::shared_ptr<nexusZiaApi::IAPIServer> & zia_fake::getAPIServer(void)
{
  return this->_apiServer;
}

void zia_fake::loadMyFakeModule()
{
	#ifdef __linux__
  std::string logEmailLibPath = "../examples/modules/LogEmail/lib/libLogEmail.so";
  this->_loader.addLib(logEmailLibPath);
  this->_loader.dump(); 

  auto logEmail = _loader.getInstance(logEmailLibPath);
  
  logEmail->setAPIServer(this->_apiServer);
  this->_modulesLists.insert({"LogEmail", logEmail});
  this->_modulesLists.at("LogEmail")->start();
	#else
  this->_logger->logWarning("Not loader for module on Windows / MacOs in this example.");
	#endif
}

void zia_fake::triggerFakeEventHttp(nexusZiaApi::IHooks::Types type)
{

  for (auto moduleIt : this->_hooks->getModuleRegisterForType(type)) {
      HttpSession httpSession;
      httpSession.setIP("10.101.10.10");
      this->_modulesLists.at(moduleIt)->triggerEvent(nexusZiaApi::IHooks::Types::CONNECTION, static_cast<void *>(&httpSession));
  }
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

hook_fake::hook_fake()
{
  this->_modulesRegister.insert(std::pair<nexusZiaApi::IHooks::Types, std::vector<std::string>>(nexusZiaApi::IHooks::Types::CONNECTION, {}));
}

hook_fake::~hook_fake()
{

}

const std::unordered_map<nexusZiaApi::IHooks::Types, std::vector<std::string>, nexusZiaApi::EnumClassHash> & hook_fake::getAllHooksRegister(void) const
{
  return this->_modulesRegister;
}


const std::vector<std::string> &hook_fake::getModuleRegisterForType(const nexusZiaApi::IHooks::Types type) const
{
  return this->_modulesRegister.at(type);
}

void hook_fake::subscribe(const nexusZiaApi::IHooks::Types &type, const std::string &name)
{
  this->_modulesRegister.find(type)->second.emplace_back(name);
}

void hook_fake::unSubscribe(const nexusZiaApi::IHooks::Types &type, const std::string &name)
{
  for (auto typeIt : this->_modulesRegister) {
      if (typeIt.first == type) {
	  size_t i = 0;
	  for (auto moduleIt : typeIt.second) {
	      if (moduleIt == name)
		typeIt.second.erase(typeIt.second.begin() + i);
	      i++;
	    }
	}
    }
}

//

HttpSession::HttpSession()
{}

HttpSession::~HttpSession()
{}

const std::string& HttpSession::getIP() const
{
  return this->_ip;
}

void HttpSession::setIP(std::string ip)
{
  this->_ip = ip;
}