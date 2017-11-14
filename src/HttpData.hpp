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
#include <cstddef>

#include "HttpHeader.hpp"

namespace nexusZiaApi {
class IHttpData {
  virtual ~IHttpData() = default;

  /**
   * Define header of HTTP data (or message)
   * @param header
   */
  virtual void setHeader(const IHttpHeader & header) const;

  /**
   * Get HTTP Header
   * @attention This functions allow edit of reference
   * @return
   */
  virtual IHttpHeader & getHeader(void);

  /**
   * Get HTTP Header
   * @return
   */
  virtual const IHttpHeader & getHeader(void) const;

  /**
   * Set the body of HTTP Data
   * @param data
   */
  virtual void	setBody(const std::vector<std::byte> & data) = 0;

  /**
   * Get body of HTTP Data
   * @return
   */
  virtual const std::vector<std::byte> & getBody(void) const = 0;
};
}

#endif //CPP_ZIA_API_HTTPDATA_HPP
