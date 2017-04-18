
#include "SamiBody.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiBody::SamiBody() {
    init();
}

SamiBody::~SamiBody() {
    this->cleanup();
}

void
SamiBody::init() {
    pList = null;
pCount = null;
pPage = null;
pWhereType = null;
pWhere = null;
pOrder = null;
}

void
SamiBody::cleanup() {
    if(pList != null) {
        
        delete pList;
        pList = null;
    }
if(pCount != null) {
        
        delete pCount;
        pCount = null;
    }
if(pPage != null) {
        
        delete pPage;
        pPage = null;
    }
if(pWhereType != null) {
        
        delete pWhereType;
        pWhereType = null;
    }
if(pWhere != null) {
        pWhere->RemoveAll(true);
        delete pWhere;
        pWhere = null;
    }
if(pOrder != null) {
        
        delete pOrder;
        pOrder = null;
    }
}


SamiBody*
SamiBody::fromJson(String* json) {
    this->cleanup();
    String str(json->GetPointer());
    int length = str.GetLength();

    ByteBuffer buffer;
    buffer.Construct(length);

    for (int i = 0; i < length; ++i) {
       byte b = str[i];
       buffer.SetByte(b);
    }

    IJsonValue* pJson = JsonParser::ParseN(buffer);
    fromJsonObject(pJson);
    if (pJson->GetType() == JSON_TYPE_OBJECT) {
       JsonObject* pObject = static_cast< JsonObject* >(pJson);
       pObject->RemoveAll(true);
    }
    else if (pJson->GetType() == JSON_TYPE_ARRAY) {
       JsonArray* pArray = static_cast< JsonArray* >(pJson);
       pArray->RemoveAll(true);
    }
    delete pJson;
    return this;
}


void
SamiBody::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pListKey = new JsonString(L"list");
        IJsonValue* pListVal = null;
        pJsonObject->GetValue(pListKey, pListVal);
        if(pListVal != null) {
            
            pList = new String();
            jsonToValue(pList, pListVal, L"String", L"String");
        }
        delete pListKey;
JsonString* pCountKey = new JsonString(L"count");
        IJsonValue* pCountVal = null;
        pJsonObject->GetValue(pCountKey, pCountVal);
        if(pCountVal != null) {
            
            pCount = new Integer();
            jsonToValue(pCount, pCountVal, L"Integer", L"Integer");
        }
        delete pCountKey;
JsonString* pPageKey = new JsonString(L"page");
        IJsonValue* pPageVal = null;
        pJsonObject->GetValue(pPageKey, pPageVal);
        if(pPageVal != null) {
            
            pPage = new Integer();
            jsonToValue(pPage, pPageVal, L"Integer", L"Integer");
        }
        delete pPageKey;
JsonString* pWhereTypeKey = new JsonString(L"whereType");
        IJsonValue* pWhereTypeVal = null;
        pJsonObject->GetValue(pWhereTypeKey, pWhereTypeVal);
        if(pWhereTypeVal != null) {
            
            pWhereType = new String();
            jsonToValue(pWhereType, pWhereTypeVal, L"String", L"String");
        }
        delete pWhereTypeKey;
JsonString* pWhereKey = new JsonString(L"where");
        IJsonValue* pWhereVal = null;
        pJsonObject->GetValue(pWhereKey, pWhereVal);
        if(pWhereVal != null) {
            pWhere = new ArrayList();
            
            jsonToValue(pWhere, pWhereVal, L"IList", L"SamiWhereItem");
        }
        delete pWhereKey;
JsonString* pOrderKey = new JsonString(L"order");
        IJsonValue* pOrderVal = null;
        pJsonObject->GetValue(pOrderKey, pOrderVal);
        if(pOrderVal != null) {
            
            pOrder = new SamiList_order();
            jsonToValue(pOrder, pOrderVal, L"SamiList_order", L"SamiList_order");
        }
        delete pOrderKey;
    }
}

SamiBody::SamiBody(String* json) {
    init();
    String str(json->GetPointer());
    int length = str.GetLength();

    ByteBuffer buffer;
    buffer.Construct(length);

    for (int i = 0; i < length; ++i) {
       byte b = str[i];
       buffer.SetByte(b);
    }

    IJsonValue* pJson = JsonParser::ParseN(buffer);
    fromJsonObject(pJson);
    if (pJson->GetType() == JSON_TYPE_OBJECT) {
       JsonObject* pObject = static_cast< JsonObject* >(pJson);
       pObject->RemoveAll(true);
    }
    else if (pJson->GetType() == JSON_TYPE_ARRAY) {
       JsonArray* pArray = static_cast< JsonArray* >(pJson);
       pArray->RemoveAll(true);
    }
    delete pJson;
}

String
SamiBody::asJson ()
{
    JsonObject* pJsonObject = asJsonObject();

    char *pComposeBuf = new char[256];
    JsonWriter::Compose(pJsonObject, pComposeBuf, 256);
    String s = String(pComposeBuf);

    delete pComposeBuf;
    pJsonObject->RemoveAll(true);
    delete pJsonObject;

    return s;
}

JsonObject*
SamiBody::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pListKey = new JsonString(L"list");
    pJsonObject->Add(pListKey, toJson(getPList(), "String", ""));

    JsonString *pCountKey = new JsonString(L"count");
    pJsonObject->Add(pCountKey, toJson(getPCount(), "Integer", ""));

    JsonString *pPageKey = new JsonString(L"page");
    pJsonObject->Add(pPageKey, toJson(getPPage(), "Integer", ""));

    JsonString *pWhereTypeKey = new JsonString(L"whereType");
    pJsonObject->Add(pWhereTypeKey, toJson(getPWhereType(), "String", ""));

    JsonString *pWhereKey = new JsonString(L"where");
    pJsonObject->Add(pWhereKey, toJson(getPWhere(), "SamiWhereItem", "array"));

    JsonString *pOrderKey = new JsonString(L"order");
    pJsonObject->Add(pOrderKey, toJson(getPOrder(), "SamiList_order", ""));

    return pJsonObject;
}

String*
SamiBody::getPList() {
    return pList;
}
void
SamiBody::setPList(String* pList) {
    this->pList = pList;
}

Integer*
SamiBody::getPCount() {
    return pCount;
}
void
SamiBody::setPCount(Integer* pCount) {
    this->pCount = pCount;
}

Integer*
SamiBody::getPPage() {
    return pPage;
}
void
SamiBody::setPPage(Integer* pPage) {
    this->pPage = pPage;
}

String*
SamiBody::getPWhereType() {
    return pWhereType;
}
void
SamiBody::setPWhereType(String* pWhereType) {
    this->pWhereType = pWhereType;
}

IList*
SamiBody::getPWhere() {
    return pWhere;
}
void
SamiBody::setPWhere(IList* pWhere) {
    this->pWhere = pWhere;
}

SamiList_order*
SamiBody::getPOrder() {
    return pOrder;
}
void
SamiBody::setPOrder(SamiList_order* pOrder) {
    this->pOrder = pOrder;
}



} /* namespace Swagger */

