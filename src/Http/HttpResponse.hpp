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

      // Informational
      Continue 				= 100,
      Switching_Protocols 		= 101,

      // Success
      OK                           	= 200,
      Created                      	= 201,
      Accepted                     	= 202,
      Non__Authoritative_Information 	= 203,
      No_Content                   	= 204,
      Reset_Content                 	= 205,
      Partial_Content               	= 206,

      // Redirection
      Multiple_Choices			= 300,
      Moved_Permanently 		= 301,
      Found				= 302,
      See_Other				= 303,
      Not_Modified			= 304,
      Use_Proxy                     	= 305,
      Temporary_Redirect            	= 307,

      // Client Error
      Bad_Request                   	= 400,
      Unauthorized                 	= 401,
      Payment_Required             	= 402,
      Forbidden                   	= 403,
      Not_Found                    	= 404,
      Method_Not_Allowed        	= 405,
      Not_Acceptable			= 406,
      Proxy_Authentication_Required	= 407,
      Request_Time__Out			= 408,
      Conflict                     	= 409,
      Gone                        	= 410,
      Length_Required               	= 411,
      Precondition_Failed           	= 412,
      Request_Entity_Too_Large        	= 413,
      Request__URI_Too_Large           	= 414,
      Unsupported_Media_Type         	= 415,
      Requested_Range_Not_Satisfiable 	= 416,
      Expectation_Failed            	= 417,

      // Server Error
      Internal_Server_Error          	= 500,
      Not_Implemented               	= 501,
      Bad_Gateway                   	= 502,
      Service_Unavailable           	= 503,
      Gateway_Time__Out               	= 504,
      HTTP_Version_Not_Supported      	= 505
    };

    virtual const StatusCode getStatusCode(void) const = 0;

    virtual const std::string getReason(void) const = 0;

    virtual std::vector<char> & getData(void) = 0;

    virtual void setStatusCode(StatusCode statusCode) = 0;

    virtual void setReason(std::string reason) = 0;

    virtual void setData(std::vector<char> data) = 0;
  };
}

#endif //NEXUSZIAAPI_HTTPRESPONSE_HPP
