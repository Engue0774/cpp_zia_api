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

#include "Config.hpp"

namespace ziaAPINexus {
	class IModuleCore
	{
	  virtual ~IModuleCore() = default;

	  /**
	   * Set name of module
	   * @param name
	   */
	  virtual void setName(const std::string & name) = 0;

	  /**
	   * Get module config
	   * @return const IModuleConfig
	   */
	  virtual const IModuleConfig & getModuleConfig(void) = 0;
	};
}

#endif //CPP_ZIA_API_MODULECORE_HPP
