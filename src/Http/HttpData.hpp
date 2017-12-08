/*
** HttpData.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/HttpData.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Nov 15 00:01:41 2017 Enguerrand Allamel
** Last update Wed Nov 15 00:01:41 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_HTTPDATA_HPP
#define CPP_ZIA_API_HTTPDATA_HPP

#include <vector>
#include <string>

#include "HttpHeader.hpp"

namespace nexusZiaApi {
class IHttpData {
 public:
  /**
   * Define header of HTTP data (or message)
   * @param header
   */
  virtual void setHeader(IHttpHeader header) = 0;

  /**
   * Get HTTP Header
   * @attention This functions allow edit of reference
   * @return
   */
  virtual IHttpHeader & getHeader(void) = 0;

  /**
   * Get HTTP Header
   * @return
   */
  virtual const IHttpHeader & getHeader(void) const = 0;

  /**
   * Set the body of HTTP Data
   * @param data
   */
  virtual void	setBody(const std::string & data) = 0;

  /**
   * Get body of HTTP Data
   * @return
   */
  virtual const std::string & getBody(void) const = 0;
};
}

#endif //CPP_ZIA_API_HTTPDATA_HPP
