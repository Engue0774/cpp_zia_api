/*
** LogEmail.cpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/LogEmail.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Dec 07 15:42:48 2017 Enguerrand Allamel
** Last update Thu Dec 07 15:42:48 2017 Enguerrand Allamel
*/

#include "LogEmail.hpp"

LogEmailZia::LogEmail::~LogEmail()
{
  std::cout << "LogEmail CTOR" << std::endl;
}

LogEmailZia::LogEmail::LogEmail()
{
  std::cout << "LogEmail DTOR" << std::endl;
}

nexusZiaApi::IHooks::ReturnEvent LogEmailZia::LogEmail::event_REQUEST_RECEIVER(nexusZiaApi::IHttpData & data)
{
  std::cout << "Event REQUEST_RECEIVER" << std::endl;
  return nexusZiaApi::IHooks::ReturnEvent::SUCCESS;
}