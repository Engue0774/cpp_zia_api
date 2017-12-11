/*
** ModuleConfigAPI.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/ModuleConfigAPI.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Nov 10 13:50:32 2017 Enguerrand Allamel
** Last update Fri Nov 10 13:50:32 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_MODULECONFIG_HPP
#define CPP_ZIA_API_MODULECONFIG_HPP

#include <string>
#include <list>

#include "ConfigKey.hpp"

namespace nexusZiaApi {
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
	   * @return std::list<IConfigkey>
	   */
	  virtual const std::list<IConfigKey> & getKey(const std::string & key) const = 0;
	};
}

#endif //CPP_ZIA_API_MODULECONFIGAPI_HPP
