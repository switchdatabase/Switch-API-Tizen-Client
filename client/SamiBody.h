/*
 * SamiBody.h
 * 
 * 
 */

#ifndef SamiBody_H_
#define SamiBody_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiList_order.h"
#include "SamiWhereItem.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Integer;
using Tizen::Base::String;


namespace Swagger {

class SamiBody: public SamiObject {
public:
    SamiBody();
    SamiBody(String* json);
    virtual ~SamiBody();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiBody* fromJson(String* obj);

    String* getPList();
    void setPList(String* pList);
    Integer* getPCount();
    void setPCount(Integer* pCount);
    Integer* getPPage();
    void setPPage(Integer* pPage);
    String* getPWhereType();
    void setPWhereType(String* pWhereType);
    IList* getPWhere();
    void setPWhere(IList* pWhere);
    SamiList_order* getPOrder();
    void setPOrder(SamiList_order* pOrder);

private:
    String* pList;
Integer* pCount;
Integer* pPage;
String* pWhereType;
IList* pWhere;
SamiList_order* pOrder;
};

} /* namespace Swagger */

#endif /* SamiBody_H_ */
