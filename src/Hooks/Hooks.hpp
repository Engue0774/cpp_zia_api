/*
** Hooks.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/Hooks.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Nov 14 17:39:09 2017 Enguerrand Allamel
** Last update Tue Nov 14 17:39:09 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_HOOKS_HPP
#define CPP_ZIA_API_HOOKS_HPP

#include <vector>
#include <unordered_map>
#include <functional>
#include "../Utils.hpp"

namespace nexusZiaApi {
class IHooks {
 public:
  /**
   * Define type of hook define
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
   * Get list of hooks Register
   * @return
   */
  virtual const std::unordered_map<nexusZiaApi::IHooks::Types, std::vector<std::string>, EnumClassHash> & getAllHooksRegister(void) const = 0;

  /**
   * Get module register for type
   * @param name Module name
   * @return
   */
  virtual const std::vector<std::string> & getModuleRegisterForType(const nexusZiaApi::IHooks::Types type) const = 0;

  /**
   * Add hook register
   * @param type Type hooks
   * @param name Name of module
   */
  virtual void subscribe(const Types & type, const std::string & name) = 0;

  /**
   * Remove hook register
   * @param type Type hooks
   * @param name Name of module
   */
  virtual void unSubscribe(const Types & type, const std::string & name) = 0;
};
}

#endif //CPP_ZIA_API_HOOKS_HPP
