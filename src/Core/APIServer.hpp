/*
** APIServer.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/APIServer.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Nov 15 10:33:39 2017 Enguerrand Allamel
** Last update Wed Nov 15 10:33:39 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_APISERVER_HPP
#define CPP_ZIA_API_APISERVER_HPP

#include "../Hooks/Hooks.hpp"
#include "../Logger/Logger.hpp"

namespace  nexusZiaApi {
class IAPIServer {
 public:
  virtual ~IAPIServer() = default;

  /**
   * Get hooks API server
   * @attention This functions allow edit of reference
   * @return
   */
  virtual IHooks & getHooks(void) = 0;

  /**
   * Get hooks API server
   * @return
   */
  virtual const IHooks & getHooks(void) const = 0;

  /**
  * Get logger API server
  * @attention This functions allow edit of reference
  * @return
  */
  virtual ILogger & getLogger(void) = 0;

  /**
  * Get logger API server
  * @return
  */
  virtual const ILogger & getLogger(void) const = 0;
};
}

#endif //CPP_ZIA_API_APISERVER_HPP
