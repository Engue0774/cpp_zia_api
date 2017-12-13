/*
** APIServer.hpp for nexusZiaAPI in /home/enguerrand/delivery/nexusZiaAPI/APIServer.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Nov 15 10:33:39 2017 Enguerrand Allamel
** Last update Wed Nov 15 10:33:39 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_APISERVER_HPP
#define NEXUSZIAAPI_APISERVER_HPP

#include "../Hooks/Hooks.hpp"
#include "../Logger/Logger.hpp"

namespace nx {
class IAPIServer {
 public:
  /**
   * Get hooks from server's API
   * @attention This function allows edition of references
   * @return
   */
  virtual IHooks & getHooks(void) = 0;

  /**
   * Get hooks from server's API
   * @return
   */
  virtual const IHooks & getHooks(void) const = 0;

  /**
  * Get logger from server's API
  * @attention This function allows edit of reference
  * @return
  */
  virtual ILogger & getLogger(void) = 0;

  /**
  * Get logger from server's API
  * @return
  */
  virtual const ILogger & getLogger(void) const = 0;
};
}

#endif //NEXUSZIAAPI_APISERVER_HPP
