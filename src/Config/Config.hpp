/*
** ModuleConfigAPI.hpp for nexusZiaAPI in /home/enguerrand/delivery/nexusZiaAPI/ModuleConfigAPI.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Nov 10 13:50:32 2017 Enguerrand Allamel
** Last update Fri Nov 10 13:50:32 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_MODULECONFIG_HPP
#define NEXUSZIAAPI_MODULECONFIG_HPP

#include <string>
#include <vector>

#include "ConfigKey.hpp"

namespace nx {
	class IModuleConfig
	{
	 public:
	  /**
	   * State of config for loading
	   */
	  enum class State
	  {
		UNLOADED 		= 0,
		LOAD_START		= 1,
		LOADED			= 2,
		ERROR			= 3
	  };

	  /**
	   * Init module's configuration
	   * Default value of each key, etc
	   */
	  virtual void	init(void) = 0;

	  /**
	   * Load module's configuration
	   */
	  virtual void 	load(void) = 0;

	  /**
	   * Reload module's configuration
	   */
	  virtual void 	reload(void) = 0;

	  /**
	   * Get state module's configuration
	   * "In loading", "is loaded", "error in config", etc
	   * @return
	   */
	  virtual const State & getState(void) const = 0;

	  /**
	   *
	   * @param key
	   * @param configKey
	   * @return
	   */
	  virtual void setKey(const std::string & key, const IConfigKey & configKey) = 0;

	  /**
	   * Get unique key in module's configuration
	   * @param key
	   * @return const IConfigKey &
	   */
	  virtual const IConfigKey & getKeyOne(const std::string & key) const = 0;

	  /**
	   * Get list of keys in module's configuration
	   * @param key
	   * @return const std::vector<IConfigkey> &
	   */
	  virtual const std::vector<IConfigKey> & getKey(const std::string & key) const = 0;
	};
}

#endif //NEXUSZIAAPI_MODULECONFIGAPI_HPP
