/*
** Hooks.hpp for nexusZiaApi in /home/enguerrand/delivery/nexusZiaAPI/Hooks.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Nov 14 17:39:09 2017 Enguerrand Allamel
** Last update Tue Nov 14 17:39:09 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_HOOKS_HPP
#define NEXUSZIAAPI_HOOKS_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include "../Utils.hpp"


namespace nx {
class IHooks {
 public:
  /**
   * Defines the hook's type
   */
  enum class Types {
    DEFAULT			= 0,
    CONNECTION			= 1,
    REQUEST_BEFORE_PARSING	= 2,
    REQUEST_PARSING		= 4,
    REQUEST_AFTER_PARSING	= 5,
    RESPONSE_BEFORE_BUILD	= 6,
    RESPONSE_BUILD		= 7,
    RESPONSE_AFTER_BUILD	= 8,
    RESPONSE_SEND		= 9
  };

  enum class ReturnEvent {
	  SUCCESS	= 0,
	  ERROR 	= 1
  };

  /**
   * Get a list of registered hooks
   * @return
   */
  virtual const std::unordered_map<nx::IHooks::Types, std::vector<std::string>, EnumClassHash> & getAllHooksRegister(void) const = 0;

  /**
   * Get registered module by type
   * @param name Module's name
   * @return
   */
  virtual const std::vector<std::string> & getModuleRegisterForType(const nx::IHooks::Types type) const = 0;

  /**
   * Add hook registration
   * @param type Hook's type
   * @param name Module's name
   */
  virtual void subscribe(const Types & type, const std::string & name) = 0;

  /**
   * Remove hook registration
   * @param type Hook's type
   * @param name Module's name
   */
  virtual void unSubscribe(const Types & type, const std::string & name) = 0;
};
}

#endif //NEXUSZIAAPI_HOOKS_HPP
