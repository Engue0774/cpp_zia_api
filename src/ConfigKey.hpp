/*
** ConfigKey.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/ConfigKey.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Nov 14 18:20:51 2017 Enguerrand Allamel
** Last update Tue Nov 14 18:20:51 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_CONFIGKEY_HPP
#define CPP_ZIA_API_CONFIGKEY_HPP

#include <string>

namespace ziaAPINexus {
	class IConfigKey {
	  enum class Type {
		VALUE	= 0,
		SCOPE	= 1
	  };

	  virtual ~IConfigKey() = default;

	  /**
	   * Set type of config key
	   * @param type
	   */
	  virtual void setType(const Type & type) = 0;

	  /**
	   * Get type of config key
	   * @return
	   */
	  virtual const Type & getType(void) const = 0;

	  /**
	   * Set name of config key
	   * @param type
	   */
	  virtual void setName(const std::string & name) = 0;

	  /**
	   * Get name of config key
	   * @return
	   */
	  virtual const std::string & getName(void) const = 0;

	  /**
	   * Set value of config key
	   * @attention Not for scope type
	   * @param type
	   */
	  virtual void setValue(const std::string & value) = 0;

	  /**
	   * Get value of config key
	   * @attention Return "" for scope
	   * @return
	   */
	  virtual const std::string & getValue(void) const = 0;
	};
}

#endif //CPP_ZIA_API_CONFIGKEY_HPP
