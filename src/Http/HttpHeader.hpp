/*
** HttpHeader.hpp for nexusZiaAPI in /home/enguerrand/delivery/nexusZiaAPI/HttpHeader.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Nov 15 00:09:39 2017 Enguerrand Allamel
** Last update Wed Nov 15 00:09:39 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_HTTPHEADER_HPP
#define NEXUSZIAAPI_HTTPHEADER_HPP

#include <string>

namespace nx {
class IHttpHeader {
 public:
  /**
   * Set the key for the HTTP's header
   * @param key
   * @param value
   * @return
   */
  virtual void setKey(const std::string & key, const std::string & value) = 0;

  /**
   * Get the key for the HTTP's header
   * @param key
   * @return
   */
  virtual const std::string & getKey(const std::string & key) const = 0;
};
}

#endif //NEXUSZIAAPI_HTTPHEADER_HPP
