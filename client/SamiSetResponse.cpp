
#include "SamiSetResponse.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiSetResponse::SamiSetResponse() {
    init();
}

SamiSetResponse::~SamiSetResponse() {
    this->cleanup();
}

void
SamiSetResponse::init() {
    pResponseTime = null;
pResponse = null;
}

void
SamiSetResponse::cleanup() {
    if(pResponseTime != null) {
        
        delete pResponseTime;
        pResponseTime = null;
    }
if(pResponse != null) {
        
        delete pResponse;
        pResponse = null;
    }
}


SamiSetResponse*
SamiSetResponse::fromJson(String* json) {
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
SamiSetResponse::fromJsonObject(IJsonValue* pJson) {
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
    }
}

SamiSetResponse::SamiSetResponse(String* json) {
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
SamiSetResponse::asJson ()
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
SamiSetResponse::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pResponseTimeKey = new JsonString(L"ResponseTime");
    pJsonObject->Add(pResponseTimeKey, toJson(getPResponseTime(), "Long", ""));

    JsonString *pResponseKey = new JsonString(L"Response");
    pJsonObject->Add(pResponseKey, toJson(getPResponse(), "String", ""));

    return pJsonObject;
}

Long*
SamiSetResponse::getPResponseTime() {
    return pResponseTime;
}
void
SamiSetResponse::setPResponseTime(Long* pResponseTime) {
    this->pResponseTime = pResponseTime;
}

String*
SamiSetResponse::getPResponse() {
    return pResponse;
}
void
SamiSetResponse::setPResponse(String* pResponse) {
    this->pResponse = pResponse;
}



} /* namespace Swagger */

