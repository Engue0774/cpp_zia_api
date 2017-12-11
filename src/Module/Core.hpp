/*
** ModuleCore.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/ModuleCore.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Nov 10 14:46:42 2017 Enguerrand Allamel
** Last update Fri Nov 10 14:46:42 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_MODULECORE_HPP
#define CPP_ZIA_API_MODULECORE_HPP

#include <string>
#include <memory>

#include "../Config/Config.hpp"
#include "../Hooks/Hooks.hpp"
#include "APIServer.hpp"

namespace nexusZiaApi {
	class IModuleCore
	{
	 public:
	  /**
	   * State of module loading
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
	   * @details Module is not stop and restart, module is always UP
	   */
	  virtual void	reload(void) = 0;

	  /**
	   * Set name of module
	   * @param name Name of module
	   */
	  virtual void	setName(const std::string & name) = 0;

	  /**
	   * Get config
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

	  //Todo Add trigger function for hooks
	};
}

#endif //CPP_ZIA_API_MODULECORE_HPP
