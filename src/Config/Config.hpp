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
	   * State of config loading
	   */
	  enum class State
	  {
		UNLOADED 		= 0,
		LOAD_START		= 1,
		LOADED			= 2,
		ERROR			= 3
	  };

	  /**
	   * Init config of module
	   * Default value of each key, etc
	   */
	  virtual void	init(void) = 0;

	  /**
	   * Load config of module
	   */
	  virtual void 	load(void) = 0;

	  /**
	   * Reload config of module
	   */
	  virtual void 	reload(void) = 0;

	  /**
	   * Get state of module config
	   * In loading, is load, error in config, etc
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
	   * Get key unique in config of module
	   * @param key
	   * @return const IConfigKey &
	   */
	  virtual const IConfigKey & getKeyOne(const std::string & key) const = 0;

	  /**
	   * Get list of key in config of module
	   * @param key
	   * @return const std::vector<IConfigkey> &
	   */
	  virtual const std::vector<IConfigKey> & getKey(const std::string & key) const = 0;
	};
}

#endif //NEXUSZIAAPI_MODULECONFIGAPI_HPP
