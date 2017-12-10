/*
** LogEmail.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/LogEmail.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Dec 07 15:42:48 2017 Enguerrand Allamel
** Last update Thu Dec 07 15:42:48 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_LOGEMAIL_HPP
#define CPP_ZIA_API_LOGEMAIL_HPP

#include <iostream>
#include <memory>

#include "NexusZiaAPI.hpp"

namespace LogEmailZia {
  class LogEmail : public nexusZiaApi::IModuleCore
  {
   private:
    static std::shared_ptr<LogEmailZia::LogEmail>						_instance;

   public:
    static std::shared_ptr<LogEmailZia::LogEmail> 						Instance();
    static void resetInstance();

  private:
    std::shared_ptr<nexusZiaApi::IModuleConfig>	_moduleConfig;
    std::shared_ptr<nexusZiaApi::IAPIServer>	_apiServer;

  private:
    LogEmail();
  public:
    virtual ~LogEmail();

   public:

    // Event
    static nexusZiaApi::IHooks::ReturnEvent event_REQUEST_RECEIVER(nexusZiaApi::IHttpData &);

    // IModuleCore
    virtual void start(void);

    virtual void stop(void);

    virtual void reload(void);

    virtual void setName(const std::string &name);

    virtual nexusZiaApi::IModuleConfig &getModuleConfig(void);

    virtual void setAPIServer(std::shared_ptr<nexusZiaApi::IAPIServer> apiServer);

    virtual nexusZiaApi::IAPIServer &getAPIServer(void);
  };
}

#endif //CPP_ZIA_API_LOGEMAIL_HPP
