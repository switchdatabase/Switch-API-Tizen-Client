#ifndef ModelFactory_H_
#define ModelFactory_H_

#include "SamiObject.h"

#include "SamiAddResponse.h"
#include "SamiBody.h"
#include "SamiError.h"
#include "SamiList_order.h"
#include "SamiSetResponse.h"
#include "SamiWhereItem.h"

namespace Swagger {
  void*
  create(String type) {
    if(type.Equals(L"SamiAddResponse", true)) {
      return new SamiAddResponse();
    }
    if(type.Equals(L"SamiBody", true)) {
      return new SamiBody();
    }
    if(type.Equals(L"SamiError", true)) {
      return new SamiError();
    }
    if(type.Equals(L"SamiList_order", true)) {
      return new SamiList_order();
    }
    if(type.Equals(L"SamiSetResponse", true)) {
      return new SamiSetResponse();
    }
    if(type.Equals(L"SamiWhereItem", true)) {
      return new SamiWhereItem();
    }
    
    if(type.Equals(L"String", true)) {
      return new String();
    }
    if(type.Equals(L"Integer", true)) {
      return new Integer();
    }
    if(type.Equals(L"Long", true)) {
      return new Long();
    }
    if(type.Equals(L"DateTime", true)) {
      return new DateTime();
    }
    return null;
  }
} /* namespace Swagger */

#endif /* ModelFactory_H_ */
