#ifndef SamiAuthorizationApi_H_
#define SamiAuthorizationApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

using Tizen::Base::Long;
#include "SamiError.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiAuthorizationApi {
public:
  SamiAuthorizationApi();
  virtual ~SamiAuthorizationApi();

  String* 
  tokenGetWithCompletion(String* aPIKey, String* signature, Long* expire, void (* handler)(String*, SamiError*));
  static String getBasePath() {
    return L"http://tr02.switchapi.com/";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiAuthorizationApi_H_ */
