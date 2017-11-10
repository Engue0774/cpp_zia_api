/*
** ModuleConfigAPI.hpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/ModuleConfigAPI.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Fri Nov 10 13:50:32 2017 Enguerrand Allamel
** Last update Fri Nov 10 13:50:32 2017 Enguerrand Allamel
*/

#ifndef CPP_ZIA_API_MODULECONFIGAPI_HPP
#define CPP_ZIA_API_MODULECONFIGAPI_HPP

namespace nexusAPI {
	class IModuleConfigAPI
	{
	  enum class State
	  {
		UNLOADED 		= 0,
		LOAD_START		= 1,
		LOADED			= 2,
		ERROR			= 3
	  };

	  virtual ~IModuleConfigAPI() = default;

	  virtual load(void) = 0;
	  virtual reload(void) = 0;

	  virtual const ModuleConfigAPI::State & getState(void) = 0;
	};
}

#endif //CPP_ZIA_API_MODULECONFIGAPI_HPP
