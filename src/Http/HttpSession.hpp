/*
** HttpSession.hpp for nexusZiaApi in /home/enguerrand/delivery/nexusZiaApi/HttpSession.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Dec 11 00:58:49 2017 Enguerrand Allamel
** Last update Mon Dec 11 00:58:49 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_HTTPSESSION_HPP
#define NEXUSZIAAPI_HTTPSESSION_HPP

namespace nexusZiaApi {
  class IHttpSession{
   public:
    virtual const std::string getIP(void) const = 0;

    virtual void setIP(std::string ip) = 0;
  };
}

#endif //NEXUSZIAAPI_HTTPSESSION_HPP
