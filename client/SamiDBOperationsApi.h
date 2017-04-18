#ifndef SamiDBOperationsApi_H_
#define SamiDBOperationsApi_H_

#include <FNet.h>
#include "SamiApiClient.h"
#include "SamiError.h"

#include "SamiAddResponse.h"
#include "SamiBody.h"
#include "SamiError.h"
#include "SamiSetResponse.h"
using Tizen::Base::String;

using namespace Tizen::Net::Http;

namespace Swagger {

class SamiDBOperationsApi {
public:
  SamiDBOperationsApi();
  virtual ~SamiDBOperationsApi();

  SamiAddResponse* 
  addPostWithCompletion(String* aPIKey, String* accessToken, String* list, String* body, void (* handler)(SamiAddResponse*, SamiError*));
  void 
  listPostWithCompletion(String* aPIKey, String* accessToken, String* list, SamiBody* body, void(* handler)(SamiError*));
  SamiSetResponse* 
  setDeleteWithCompletion(String* aPIKey, String* accessToken, String* list, String* listItemId, void (* handler)(SamiSetResponse*, SamiError*));
  SamiSetResponse* 
  setPostWithCompletion(String* aPIKey, String* accessToken, String* list, String* listItemId, String* body, void (* handler)(SamiSetResponse*, SamiError*));
  static String getBasePath() {
    return L"http://tr02.switchapi.com/";
  }

private:
  SamiApiClient* client;
};


} /* namespace Swagger */

#endif /* SamiDBOperationsApi_H_ */
