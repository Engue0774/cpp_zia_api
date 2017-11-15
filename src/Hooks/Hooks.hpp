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

#include <list>
#include <string>

namespace nexusZiaApi {
class IHooks {
 public:
  /**
   * Define type of hook define
   */
  enum class Types {
	DEFAULT					= 0,
	REQUEST_BEFORE_PARSING	= 1,
	REQUEST_AFTER_PARSING	= 2,
	REQUEST_DONE			= 3,
	RESPONSE_BEFORE_BUILD	= 4,
	RESPONSE_POST_BUILD		= 5,
	RESPONSE_SEND			= 6
  };

  virtual ~IHooks() = default;

  /**
   * Get list of hooks
   * @return
   */
  virtual const std::list<Types> & getAllHooks(void) const = 0;

  /**
   * Get hooks register for module (by name)
   * @param name Module name
   * @return
   */
  virtual const std::list<Types> & getHooksForModule(const std::string & name) const = 0;

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
