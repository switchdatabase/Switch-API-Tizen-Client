
#include "SamiWhereItem.h"
#include <FLocales.h>

using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Web::Json;
using namespace Tizen::Locales;


namespace Swagger {

SamiWhereItem::SamiWhereItem() {
    init();
}

SamiWhereItem::~SamiWhereItem() {
    this->cleanup();
}

void
SamiWhereItem::init() {
    pType = null;
pColumn = null;
pValue = null;
}

void
SamiWhereItem::cleanup() {
    if(pType != null) {
        
        delete pType;
        pType = null;
    }
if(pColumn != null) {
        
        delete pColumn;
        pColumn = null;
    }
if(pValue != null) {
        
        delete pValue;
        pValue = null;
    }
}


SamiWhereItem*
SamiWhereItem::fromJson(String* json) {
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
SamiWhereItem::fromJsonObject(IJsonValue* pJson) {
    JsonObject* pJsonObject = static_cast< JsonObject* >(pJson);

    if(pJsonObject != null) {
        JsonString* pTypeKey = new JsonString(L"type");
        IJsonValue* pTypeVal = null;
        pJsonObject->GetValue(pTypeKey, pTypeVal);
        if(pTypeVal != null) {
            
            pType = new String();
            jsonToValue(pType, pTypeVal, L"String", L"String");
        }
        delete pTypeKey;
JsonString* pColumnKey = new JsonString(L"column");
        IJsonValue* pColumnVal = null;
        pJsonObject->GetValue(pColumnKey, pColumnVal);
        if(pColumnVal != null) {
            
            pColumn = new String();
            jsonToValue(pColumn, pColumnVal, L"String", L"String");
        }
        delete pColumnKey;
JsonString* pValueKey = new JsonString(L"value");
        IJsonValue* pValueVal = null;
        pJsonObject->GetValue(pValueKey, pValueVal);
        if(pValueVal != null) {
            
            pValue = new String();
            jsonToValue(pValue, pValueVal, L"String", L"String");
        }
        delete pValueKey;
    }
}

SamiWhereItem::SamiWhereItem(String* json) {
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
SamiWhereItem::asJson ()
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
SamiWhereItem::asJsonObject() {
    JsonObject *pJsonObject = new JsonObject();
    pJsonObject->Construct();

    JsonString *pTypeKey = new JsonString(L"type");
    pJsonObject->Add(pTypeKey, toJson(getPType(), "String", ""));

    JsonString *pColumnKey = new JsonString(L"column");
    pJsonObject->Add(pColumnKey, toJson(getPColumn(), "String", ""));

    JsonString *pValueKey = new JsonString(L"value");
    pJsonObject->Add(pValueKey, toJson(getPValue(), "String", ""));

    return pJsonObject;
}

String*
SamiWhereItem::getPType() {
    return pType;
}
void
SamiWhereItem::setPType(String* pType) {
    this->pType = pType;
}

String*
SamiWhereItem::getPColumn() {
    return pColumn;
}
void
SamiWhereItem::setPColumn(String* pColumn) {
    this->pColumn = pColumn;
}

String*
SamiWhereItem::getPValue() {
    return pValue;
}
void
SamiWhereItem::setPValue(String* pValue) {
    this->pValue = pValue;
}



} /* namespace Swagger */

