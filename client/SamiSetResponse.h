/*
 * SamiSetResponse.h
 * 
 * 
 */

#ifndef SamiSetResponse_H_
#define SamiSetResponse_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::Long;
using Tizen::Base::String;


namespace Swagger {

class SamiSetResponse: public SamiObject {
public:
    SamiSetResponse();
    SamiSetResponse(String* json);
    virtual ~SamiSetResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiSetResponse* fromJson(String* obj);

    Long* getPResponseTime();
    void setPResponseTime(Long* pResponseTime);
    String* getPResponse();
    void setPResponse(String* pResponse);

private:
    Long* pResponseTime;
String* pResponse;
};

} /* namespace Swagger */

#endif /* SamiSetResponse_H_ */
