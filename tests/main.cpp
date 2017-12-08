/*
** main.cpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/main.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Wed Nov 15 09:49:27 2017 Enguerrand Allamel
** Last update Wed Nov 15 09:49:27 2017 Enguerrand Allamel
*/

#include <iostream>
#include "../src/NexusZiaAPI.hpp"
#include "../examples/modules/LogEmail/LogEmail.hpp"
#include "zia_fake.hh"

int main(int, char**)
{
  std::cout << "RUN MAIN TEST CPP" << std::endl;

  HttpData_fake httpData_fake;

  LogEmailZia::LogEmail logEmail;


  logEmail.event_REQUEST_RECEIVER(httpData_fake);
  return (0);
}