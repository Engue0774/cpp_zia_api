/*
** Utils.hpp for nexusZiaApi in /home/enguerrand/delivery/nexusZiaApi/Utils.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Mon Dec 11 17:47:47 2017 Enguerrand Allamel
** Last update Mon Dec 11 17:47:47 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_UTILS_HPP
#define NEXUSZIAAPI_UTILS_HPP

namespace nx {
  struct EnumClassHash
  {
    template <typename T>
    std::size_t operator()(T t) const
    {
      return static_cast<std::size_t>(t);
    }
  };
}

#endif //NEXUSZIAAPI_UTILS_HPP
