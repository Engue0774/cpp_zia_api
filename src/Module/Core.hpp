/*
** ModuleCore.hpp for nexusZiaAPI in /home/enguerrand/delivery/nexusZiaAPI/ModuleCore.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Nov 10 14:46:42 2017 Enguerrand Allamel
** Last update Fri Nov 10 14:46:42 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_MODULECORE_HPP
#define NEXUSZIAAPI_MODULECORE_HPP

#include <string>
#include <memory>

#include "../Config/Config.hpp"
#include "../Hooks/Hooks.hpp"
#include "APIServer.hpp"

namespace nx {
	class IModuleCore
	{
	 public:
	  /**
	   * State for a module loading
	   * 0: OFF / 1: UP
	   */
	  enum class State
	  {
		OFF	= 0,
		UP	= 1
	  };

	  /**
	   * Start module
	   */
	  virtual void	start(void) = 0;

	  /**
	   * Stop module
	   */
	  virtual void	stop(void) = 0;

	  /**
	   * Reload module
	   * @details A module is not stop then restart, it's always UP
	   */
	  virtual void	reload(void) = 0;

	  /**
	   * Set the name of the module
	   * @param name Name of the module
	   */
	  virtual void	setName(const std::string & name) = 0;

	  /**
	   * Get the config
	   * @return const IModuleConfig
	   */
	  virtual IModuleConfig & getModuleConfig(void) = 0;

	  /**
	   * Set API Server
	   */
	  virtual void setAPIServer(std::shared_ptr<IAPIServer> apiServer) = 0;

	  /**
	   * Get API Server
	   * @return const IModuleConfig
	   */
	  virtual IAPIServer & getAPIServer(void) = 0;


	  /**
	   * Callback for registered and triggered events
	   * @param type Type of the event
	   * @param data Data of the event
	   * @return
	   */
	  virtual IHooks::ReturnEvent triggerEvent(IHooks::Types type, void *data) = 0;
	};
}

#endif //NEXUSZIAAPI_MODULECORE_HPP
