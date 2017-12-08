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
#include "NexusZiaAPI.hpp"

namespace LogEmailZia {
  class LogEmail
  {
   public:
    LogEmail();
    virtual ~LogEmail();

    static nexusZiaApi::IHooks::ReturnEvent event_REQUEST_RECEIVER(nexusZiaApi::IHttpData &);
  };
}

#endif //CPP_ZIA_API_LOGEMAIL_HPP
