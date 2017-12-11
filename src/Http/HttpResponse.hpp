/*
** HttpResponse.hpp for nexusZiaApi in /home/enguerrand/delivery/nexusZiaApi/Response.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  Sat Dec 09 19:40:08 2017 Enguerrand Allamel
** Last update Sat Dec 09 19:40:08 2017 Enguerrand Allamel
*/

#ifndef NEXUSZIAAPI_HTTPRESPONSE_HPP
#define NEXUSZIAAPI_HTTPRESPONSE_HPP

#include <vector>
#include "HttpHeader.hpp"

namespace nexusZiaApi {
  class IHttpResponse : public IHttpHeader {
   public:
    enum class StatusCode {
      UNDEFINED		= 0,

      // INFORMATIONAL
      CONTINUE 				= 100,
      SWITCHING_PROTOCOLS 		= 101,

      // SUCCESS
      OK                           	= 200,
      CREATED                      	= 201,
      ACCEPTED                     	= 202,
      NON_AUTHORITATIVE_INFORMATION 	= 203,
      NO_CONTENT                   	= 204,
      RESET_CONTENT                 	= 205,
      PARTIAL_CONTENT               	= 206,

      // REDIRECTION
      MULTIPLE_CHOICES			= 300,
      MOVED_PERMANENTLY 		= 301,
      FOUND				= 302,
      SEE_OTHER				= 303,
      NOT_MODIFIED			= 304,
      USE_PROXY                     	= 305,
      TEMPORARY_REDIRECT            	= 307,

      // CLIENT ERROR
      BAD_REQUEST                   	= 400,
      UNAUTHORIZED                 	= 401,
      PAYMENT_REQUIRED             	= 402,
      FORBIDDEN                   	= 403,
      NOT_FOUND                    	= 404,
      METHOD_NOT_ALLOWED        	= 405,
      NOT_ACCEPTABLE			= 406,
      PROXY_AUTHENTICATION_REQUIRED	= 407,
      REQUEST_TIME_OUT			= 408,
      CONFLICT                     	= 409,
      GONE                        	= 410,
      LENGTH_REQUIRED               	= 411,
      PRECONDITION_FAILED           	= 412,
      REQUEST_ENTITY_TOO_LARGE        	= 413,
      REQUEST_URI_TOO_LARGE           	= 414,
      UNSUPPORTED_MEDIA_TYPE         	= 415,
      REQUESTED_RANGE_NOT_SATISFIABLE 	= 416,
      EXPECTATION_FAILED            	= 417,

      // SERVER ERROR
      INTERNAL_SERVER_ERROR          	= 500,
      NOT_IMPLEMENTED               	= 501,
      BAD_GATEWAY                   	= 502,
      SERVICE_UNAVAILABLE           	= 503,
      GATEWAY_TIME_OUT               	= 504,
      HTTP_VERSION_NOT_SUPPORTED      	= 505
    };

    virtual StatusCode getStatusCode(void) const = 0;

    virtual const std::string &getReason(void) const = 0;

    virtual const std::vector<char> & getData(void) = 0;

    virtual void setStatusCode(StatusCode statusCode) = 0;

    virtual void setReason(const std::string &reason) = 0;

    virtual void setData(const std::vector<char> &data) = 0;
  };
}

#endif //NEXUSZIAAPI_HTTPRESPONSE_HPP
