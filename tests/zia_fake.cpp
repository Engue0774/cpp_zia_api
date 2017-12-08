/*
** zia_fake.cpp for cpp_zia_api in /home/enguerrand/delivery/cpp_zia_api/zia_fake.cpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Thu Dec 07 16:57:47 2017 Enguerrand Allamel
** Last update Thu Dec 07 16:57:47 2017 Enguerrand Allamel
*/

#include "zia_fake.hh"

// HttpHeader

HttpHeader_fake::HttpHeader_fake()
{}

HttpHeader_fake::~HttpHeader_fake()
{

}

void HttpHeader_fake::setKey(const std::string &key, const std::string &value)
{
  this->_data.insert({key, value});
}

const std::string &HttpHeader_fake::getKey(const std::string &key)
{
  return this->_data.at(key);
}

// HttpData

HttpData_fake::HttpData_fake()
{
}

HttpData_fake::~HttpData_fake()
{

}

void HttpData_fake::setHeader(nexusZiaApi::IHttpHeader header)
{
  *this->_header = header;
}

nexusZiaApi::IHttpHeader &HttpData_fake::getHeader(void)
{
  return *this->_header;
}

const nexusZiaApi::IHttpHeader &HttpData_fake::getHeader(void) const
{
  return *this->_header;
}

void HttpData_fake::setBody(const std::string &data)
{
  this->_data = data;
}

const std::string &HttpData_fake::getBody(void) const
{
  return this->_data;
}
