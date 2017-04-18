/*
 * SamiAddResponse.h
 * 
 * 
 */

#ifndef SamiAddResponse_H_
#define SamiAddResponse_H_

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

class SamiAddResponse: public SamiObject {
public:
    SamiAddResponse();
    SamiAddResponse(String* json);
    virtual ~SamiAddResponse();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiAddResponse* fromJson(String* obj);

    Long* getPResponseTime();
    void setPResponseTime(Long* pResponseTime);
    String* getPResponse();
    void setPResponse(String* pResponse);
    String* getPListItemId();
    void setPListItemId(String* pListItemId);

private:
    Long* pResponseTime;
String* pResponse;
String* pListItemId;
};

} /* namespace Swagger */

#endif /* SamiAddResponse_H_ */
