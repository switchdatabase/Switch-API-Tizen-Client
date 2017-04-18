/*
 * SamiList_order.h
 * 
 * 
 */

#ifndef SamiList_order_H_
#define SamiList_order_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiList_order: public SamiObject {
public:
    SamiList_order();
    SamiList_order(String* json);
    virtual ~SamiList_order();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiList_order* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    String* getPBy();
    void setPBy(String* pBy);

private:
    String* pType;
String* pBy;
};

} /* namespace Swagger */

#endif /* SamiList_order_H_ */
