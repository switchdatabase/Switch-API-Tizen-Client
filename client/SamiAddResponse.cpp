
#include "SamiAddResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiAddResponse::SamiAddResponse() {
    init();
}

SamiAddResponse::~SamiAddResponse() {
    this->cleanup();
}

void
SamiAddResponse::init() {
    pResponseTime = null;
pResponse = null;
pListItemId = null;
}

void
SamiAddResponse::cleanup() {
    if(pResponseTime != null) {
        
        delete pResponseTime;
        pResponseTime = null;
    }
if(pResponse != null) {
        
        delete pResponse;
        pResponse = null;
    }
if(pListItemId != null) {
        
        delete pListItemId;
        pListItemId = null;
    }
}


SamiAddResponse*
SamiAddResponse::fromJson(String* json) {
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
SamiAddResponse::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pResponseTimeKey = new JsonString(L"ResponseTime");
        IJsonValue* pResponseTimeVal = null;
        pJsonObject->GetValue(pResponseTimeKey, pResponseTimeVal);
        if(pResponseTimeVal != null) {
            
            pResponseTime = new Long();
            jsonToValue(pResponseTime, pResponseTimeVal, L"Long", L"Long");
        }
        delete pResponseTimeKey;
JsonString* pResponseKey = new JsonString(L"Response");
        IJsonValue* pResponseVal = null;
        pJsonObject->GetValue(pResponseKey, pResponseVal);
        if(pResponseVal != null) {
            
            pResponse = new String();
            jsonToValue(pResponse, pResponseVal, L"String", L"String");
        }
        delete pResponseKey;
JsonString* pListItemIdKey = new JsonString(L"ListItemId");
        IJsonValue* pListItemIdVal = null;
        pJsonObject->GetValue(pListItemIdKey, pListItemIdVal);
        if(pListItemIdVal != null) {
            
            pListItemId = new String();
            jsonToValue(pListItemId, pListItemIdVal, L"String", L"String");
        }
        delete pListItemIdKey;
    }
}

SamiAddResponse::SamiAddResponse(String* json) {
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
SamiAddResponse::asJson ()
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
SamiAddResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pResponseTimeKey = new JsonString(L"ResponseTime");
    pJsonObject->Add(pResponseTimeKey, toJson(getPResponseTime(), "Long", ""));

    JsonString *pResponseKey = new JsonString(L"Response");
    pJsonObject->Add(pResponseKey, toJson(getPResponse(), "String", ""));

    JsonString *pListItemIdKey = new JsonString(L"ListItemId");
    pJsonObject->Add(pListItemIdKey, toJson(getPListItemId(), "String", ""));

    return pJsonObject;
}

Long*
SamiAddResponse::getPResponseTime() {
    return pResponseTime;
}
void
SamiAddResponse::setPResponseTime(Long* pResponseTime) {
    this->pResponseTime = pResponseTime;
}

String*
SamiAddResponse::getPResponse() {
    return pResponse;
}
void
SamiAddResponse::setPResponse(String* pResponse) {
    this->pResponse = pResponse;
}

String*
SamiAddResponse::getPListItemId() {
    return pListItemId;
}
void
SamiAddResponse::setPListItemId(String* pListItemId) {
    this->pListItemId = pListItemId;
}



} /* namespace Swagger */

