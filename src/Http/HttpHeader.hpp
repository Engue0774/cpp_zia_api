/*
** HttpHeader.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/HttpHeader.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Nov 15 00:09:39 2017 Enguerrand Allamel
** Last update Wed Nov 15 00:09:39 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_HTTPHEADER_HPP
#define CPP_ZIA_API_HTTPHEADER_HPP

#include <string>

namespace nexusZiaApi {
class IHttpHeader {
 public:
  /**
   * Set key of header HTTP
   * @param key
   * @param value
   * @return
   */
  virtual void setKey(const std::string & key, const std::string & value) = 0;

  /**
   * Get key of header HTTP
   * @param key
   * @return
   */
  virtual const std::string & getKey(const std::string & key) const = 0;
};
}

#endif //CPP_ZIA_API_HTTPHEADER_HPP
