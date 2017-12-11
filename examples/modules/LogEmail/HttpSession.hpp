/*
** HttpSession.hpp for nexusZiaApi in /home/enguerrand/delivery/nexusZiaApi/HttpSession.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Dec 11 15:08:32 2017 Enguerrand Allamel
** Last update Mon Dec 11 15:08:32 2017 Enguerrand Allamel
*/

#ifndef LOGEMAIL_HTTPSESSION_HPP
#define LOGEMAI_HTTPSESSION_HPP

#include "NexusZiaAPI.hpp"

namespace LogEmailZia
{
  class HttpSession : public nx::IHttpSession {
   private:
    std::string _ip;
   public:
    HttpSession() {};
    virtual ~HttpSession() {};

    virtual const std::string & getIP(void) const {
      return this->_ip;
    }

    virtual void setIP(std::string ip) {
      this->_ip = ip;
    }
  };
}

#endif //LOGEMAI_HTTPSESSION_HPP
