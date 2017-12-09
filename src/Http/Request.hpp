/*
** Request.hpp for nexusZiaApi in /home/enguerrand/delivery/nexusZiaApi/Request.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sat Dec 09 19:09:47 2017 Enguerrand Allamel
** Last update Sat Dec 09 19:09:47 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_REQUEST_HPP
#define NEXUSZIAAPI_REQUEST_HPP

#include "HttpHeader.hpp"

namespace nexusZiaApi {
  class IRequest : public IHttpHeader {
   public:
    enum class Method {
      UNDEFINED		= 0,
      OPTIONS		= 1,
      GET,
      HEAD,
      POST,
      PUT,
      DELETE,
      TRACE,
      CONNECT,
      PATCH
    };

    virtual const Method getMethod(void) const = 0;

    virtual const getURI(void) const = 0;

    virtual void setMethod(Method method) = 0;

    virtual void setURI(std::string uri) = 0;
  };
}

#endif //NEXUSZIAAPI_REQUEST_HPP
