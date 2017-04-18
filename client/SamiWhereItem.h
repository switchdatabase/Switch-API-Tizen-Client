/*
 * SamiWhereItem.h
 * 
 * 
 */

#ifndef SamiWhereItem_H_
#define SamiWhereItem_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


using Tizen::Base::String;


namespace Swagger {

class SamiWhereItem: public SamiObject {
public:
    SamiWhereItem();
    SamiWhereItem(String* json);
    virtual ~SamiWhereItem();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiWhereItem* fromJson(String* obj);

    String* getPType();
    void setPType(String* pType);
    String* getPColumn();
    void setPColumn(String* pColumn);
    String* getPValue();
    void setPValue(String* pValue);

private:
    String* pType;
String* pColumn;
String* pValue;
};

} /* namespace Swagger */

#endif /* SamiWhereItem_H_ */
