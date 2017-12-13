/*
** ConfigKey.hpp for nexusZiaAPI in /home/enguerrand/delivery/nexusZiaAPI/ConfigKey.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Tue Nov 14 18:20:51 2017 Enguerrand Allamel
** Last update Tue Nov 14 18:20:51 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_CONFIGKEY_HPP
#define NEXUSZIAAPI_CONFIGKEY_HPP

#include <string>

namespace nx {
	class IConfigKey {
	 public:
	  enum class Type {
		VALUE	= 0,
		SCOPE	= 1
	  };

	  /**
	   * Set the type of the configuration's key
	   * @param type
	   */
	  virtual void setType(const Type & type) = 0;

	  /**
	   * Get the type of the configuration's key
	   * @return
	   */
	  virtual const Type & getType(void) const = 0;

	  /**
	   * Set name of the configuration's key
	   * @param type
	   */
	  virtual void setName(const std::string & name) = 0;

	  /**
	   * Get name of the configuration's key
	   * @return
	   */
	  virtual const std::string & getName(void) const = 0;

	  /**
	   * Set value of the configuration's key
	   * @attention Not for "scope" type
	   * @param type
	   */
	  virtual void setValue(const std::string & value) = 0;

	  /**
	   * Get value of the configuration's key
	   * @attention Return "" for scope
	   * @return
	   */
	  virtual const std::string & getValue(void) const = 0;

	  /**
	   * Get value of the configuration's key
	   * @attention Return IConfigKey empty for value
	   * @return
	   */
	  virtual const IConfigKey & getScope(void) const = 0;
	};
}

#endif //NEXUSZIAAPI_CONFIGKEY_HPP
