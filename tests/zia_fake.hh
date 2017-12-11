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

#ifdef __linux__
#include "DLLoader.hpp"
#endif

class HttpHeader_fake : public nx::IHttpHeader {
 private:
  std::unordered_map<std::string, std::string>	_data;
 public:
  HttpHeader_fake();

  virtual ~HttpHeader_fake();

  virtual void setKey(const std::string & key, const std::string & value);

  virtual const std::string & getKey(const std::string & key);
};

class logger_fake : public nx::ILogger
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

//

class zia_fake
{
 private:
  std::shared_ptr<nx::ILogger>		_logger;
  std::shared_ptr<nx::IHooks>		_hooks;
  std::shared_ptr<nx::IAPIServer>	_apiServer;
	#ifdef __linux__
  DLLoader                   _loader;
  	#endif

  std::unordered_map<std::string, nx::IModuleCore*>	_modulesLists;
 public:
  zia_fake();
  virtual ~zia_fake();

  std::shared_ptr<nx::IAPIServer> & getAPIServer();

  void	loadMyFakeModule();
  void  triggerFakeEventHttp(nx::IHooks::Types type);
};

//

class apiServer_fake : public nx::IAPIServer
{
 private:
  std::shared_ptr<nx::ILogger>	_logger;
  std::shared_ptr<nx::IHooks>	_hooks;
 public:
  apiServer_fake(std::shared_ptr<nx::ILogger>, std::shared_ptr<nx::IHooks>);
  virtual ~apiServer_fake();

  virtual nx::IHooks &getHooks(void);

  virtual const nx::IHooks &getHooks(void) const;

  virtual nx::ILogger &getLogger(void);

  virtual const nx::ILogger &getLogger(void) const;
};

//

class hook_fake : public nx::IHooks {
 private:
  std::unordered_map<nx::IHooks::Types, std::vector<std::string>, nx::EnumClassHash>	_modulesRegister;
 public:
  hook_fake();

  virtual ~hook_fake();

  virtual const std::unordered_map<nx::IHooks::Types, std::vector<std::string>, nx::EnumClassHash> & getAllHooksRegister(void) const;

  virtual const std::vector<std::string> & getModuleRegisterForType(const nx::IHooks::Types type) const;

  virtual void subscribe(const Types &type, const std::string &name);

  virtual void unSubscribe(const Types &type, const std::string &name);
};

//

class HttpSession : public nx::IHttpSession {
 private:
  std::string _ip;
 public:
  HttpSession();

  virtual ~HttpSession();

  virtual const std::string & getIP(void) const;

  virtual void setIP(std::string ip);
};


#endif //CPP_ZIA_API_ZIA_FAKE_HH
