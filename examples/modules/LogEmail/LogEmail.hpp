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

#include "HttpSession.hpp"

namespace LogEmailZia {
  class LogEmail : public nx::IModuleCore
  {
   private:
    static std::shared_ptr<LogEmailZia::LogEmail>						_instance;

   public:
    static std::shared_ptr<LogEmailZia::LogEmail> 						Instance();
    static void resetInstance();

  private:
    std::shared_ptr<nx::IModuleConfig>	_moduleConfig;
    std::shared_ptr<nx::IAPIServer>	_apiServer;

  private:
    LogEmail();
  public:
    virtual ~LogEmail();

   public:

    // Event
    static nx::IHooks::ReturnEvent event_CONNECTION();

    // IModuleCore
    virtual void start(void);

    virtual void stop(void);

    virtual void reload(void);

    virtual void setName(const std::string &name);

    virtual nx::IModuleConfig &getModuleConfig(void);

    virtual void setAPIServer(std::shared_ptr<nx::IAPIServer> apiServer);

    virtual nx::IAPIServer &getAPIServer(void);

    virtual nx::IHooks::ReturnEvent triggerEvent(nx::IHooks::Types type, void *data);
  };
}

#endif //CPP_ZIA_API_LOGEMAIL_HPP
