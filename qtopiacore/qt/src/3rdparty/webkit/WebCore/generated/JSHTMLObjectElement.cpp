/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#include "JSHTMLObjectElement.h"

#include <wtf/GetPtr.h>

#include "AtomicString.h"
#include "Document.h"
#include "HTMLFormElement.h"
#include "HTMLObjectElement.h"
#include "JSDocument.h"
#include "JSHTMLFormElement.h"
#include "JSSVGDocument.h"
#include "PlatformString.h"
#include "SVGDocument.h"
#include "kjs_dom.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashEntry JSHTMLObjectElementTableEntries[] =
{
    { "contentDocument", JSHTMLObjectElement::ContentDocumentAttrNum, DontDelete|ReadOnly, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { "declare", JSHTMLObjectElement::DeclareAttrNum, DontDelete, 0, 0 },
    { "type", JSHTMLObjectElement::TypeAttrNum, DontDelete, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { "form", JSHTMLObjectElement::FormAttrNum, DontDelete|ReadOnly, 0, &JSHTMLObjectElementTableEntries[20] },
    { 0, 0, 0, 0, 0 },
    { "codeType", JSHTMLObjectElement::CodeTypeAttrNum, DontDelete, 0, 0 },
    { "vspace", JSHTMLObjectElement::VspaceAttrNum, DontDelete, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { "width", JSHTMLObjectElement::WidthAttrNum, DontDelete, 0, 0 },
    { "border", JSHTMLObjectElement::BorderAttrNum, DontDelete, 0, 0 },
    { "tabIndex", JSHTMLObjectElement::TabIndexAttrNum, DontDelete, 0, 0 },
    { 0, 0, 0, 0, 0 },
    { "standby", JSHTMLObjectElement::StandbyAttrNum, DontDelete, 0, 0 },
    { "hspace", JSHTMLObjectElement::HspaceAttrNum, DontDelete, 0, 0 },
    { "height", JSHTMLObjectElement::HeightAttrNum, DontDelete, 0, &JSHTMLObjectElementTableEntries[25] },
    { "codeBase", JSHTMLObjectElement::CodeBaseAttrNum, DontDelete, 0, 0 },
    { "archive", JSHTMLObjectElement::ArchiveAttrNum, DontDelete, 0, &JSHTMLObjectElementTableEntries[22] },
    { "code", JSHTMLObjectElement::CodeAttrNum, DontDelete, 0, &JSHTMLObjectElementTableEntries[21] },
    { "align", JSHTMLObjectElement::AlignAttrNum, DontDelete, 0, &JSHTMLObjectElementTableEntries[23] },
    { "data", JSHTMLObjectElement::DataAttrNum, DontDelete, 0, 0 },
    { "name", JSHTMLObjectElement::NameAttrNum, DontDelete, 0, &JSHTMLObjectElementTableEntries[24] },
    { "useMap", JSHTMLObjectElement::UseMapAttrNum, DontDelete, 0, 0 },
    { "constructor", JSHTMLObjectElement::ConstructorAttrNum, DontDelete|DontEnum|ReadOnly, 0, 0 }
};

static const HashTable JSHTMLObjectElementTable = 
{
    2, 26, JSHTMLObjectElementTableEntries, 20
};

/* Hash table for constructor */

static const HashEntry JSHTMLObjectElementConstructorTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLObjectElementConstructorTable = 
{
    2, 1, JSHTMLObjectElementConstructorTableEntries, 1
};

class JSHTMLObjectElementConstructor : public DOMObject {
public:
    JSHTMLObjectElementConstructor(ExecState* exec)
    {
        setPrototype(exec->lexicalInterpreter()->builtinObjectPrototype());
        putDirect(exec->propertyNames().prototype, JSHTMLObjectElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLObjectElementConstructor::info = { "HTMLObjectElementConstructor", 0, &JSHTMLObjectElementConstructorTable, 0 };

bool JSHTMLObjectElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLObjectElementConstructor, DOMObject>(exec, &JSHTMLObjectElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLObjectElementConstructor::getValueProperty(ExecState*, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(token);
}

/* Hash table for prototype */

static const HashEntry JSHTMLObjectElementPrototypeTableEntries[] =
{
    { "getSVGDocument", JSHTMLObjectElement::GetSVGDocumentFuncNum, DontDelete|Function, 0, 0 }
};

static const HashTable JSHTMLObjectElementPrototypeTable = 
{
    2, 1, JSHTMLObjectElementPrototypeTableEntries, 1
};

const ClassInfo JSHTMLObjectElementPrototype::info = { "HTMLObjectElementPrototype", 0, &JSHTMLObjectElementPrototypeTable, 0 };

JSObject* JSHTMLObjectElementPrototype::self(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLObjectElementPrototype>(exec, "[[JSHTMLObjectElement.prototype]]");
}

bool JSHTMLObjectElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSHTMLObjectElementPrototypeFunction, JSObject>(exec, &JSHTMLObjectElementPrototypeTable, this, propertyName, slot);
}

const ClassInfo JSHTMLObjectElement::info = { "HTMLObjectElement", &JSHTMLElement::info, &JSHTMLObjectElementTable, 0 };

JSHTMLObjectElement::JSHTMLObjectElement(ExecState* exec, HTMLObjectElement* impl)
    : JSHTMLElement(exec, impl)
{
    setPrototype(JSHTMLObjectElementPrototype::self(exec));
}

bool JSHTMLObjectElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    if (canGetItemsForName(exec, static_cast<HTMLObjectElement*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    if (customGetOwnPropertySlot(exec, propertyName, slot))
        return true;
    return getStaticValueSlot<JSHTMLObjectElement, JSHTMLElement>(exec, &JSHTMLObjectElementTable, this, propertyName, slot);
}

JSValue* JSHTMLObjectElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case FormAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return toJS(exec, WTF::getPtr(imp->form()));
    }
    case CodeAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->code());
    }
    case AlignAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->align());
    }
    case ArchiveAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->archive());
    }
    case BorderAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->border());
    }
    case CodeBaseAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->codeBase());
    }
    case CodeTypeAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->codeType());
    }
    case DataAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->data());
    }
    case DeclareAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsBoolean(imp->declare());
    }
    case HeightAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->height());
    }
    case HspaceAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsNumber(imp->hspace());
    }
    case NameAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->name());
    }
    case StandbyAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->standby());
    }
    case TabIndexAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsNumber(imp->tabIndex());
    }
    case TypeAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->type());
    }
    case UseMapAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->useMap());
    }
    case VspaceAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsNumber(imp->vspace());
    }
    case WidthAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return jsString(imp->width());
    }
    case ContentDocumentAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        return checkNodeSecurity(exec, imp->contentDocument()) ? toJS(exec, WTF::getPtr(imp->contentDocument())) : jsUndefined();
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLObjectElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value, int attr)
{
    if (customPut(exec, propertyName, value, attr))
        return;
    lookupPut<JSHTMLObjectElement, JSHTMLElement>(exec, propertyName, value, attr, &JSHTMLObjectElementTable, this);
}

void JSHTMLObjectElement::putValueProperty(ExecState* exec, int token, JSValue* value, int /*attr*/)
{
    switch (token) {
    case CodeAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setCode(valueToStringWithNullCheck(exec, value));
        break;
    }
    case AlignAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setAlign(valueToStringWithNullCheck(exec, value));
        break;
    }
    case ArchiveAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setArchive(valueToStringWithNullCheck(exec, value));
        break;
    }
    case BorderAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setBorder(valueToStringWithNullCheck(exec, value));
        break;
    }
    case CodeBaseAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setCodeBase(valueToStringWithNullCheck(exec, value));
        break;
    }
    case CodeTypeAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setCodeType(valueToStringWithNullCheck(exec, value));
        break;
    }
    case DataAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setData(valueToStringWithNullCheck(exec, value));
        break;
    }
    case DeclareAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setDeclare(value->toBoolean(exec));
        break;
    }
    case HeightAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setHeight(valueToStringWithNullCheck(exec, value));
        break;
    }
    case HspaceAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setHspace(value->toInt32(exec));
        break;
    }
    case NameAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setName(valueToStringWithNullCheck(exec, value));
        break;
    }
    case StandbyAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setStandby(valueToStringWithNullCheck(exec, value));
        break;
    }
    case TabIndexAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setTabIndex(value->toInt32(exec));
        break;
    }
    case TypeAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setType(valueToStringWithNullCheck(exec, value));
        break;
    }
    case UseMapAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setUseMap(valueToStringWithNullCheck(exec, value));
        break;
    }
    case VspaceAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setVspace(value->toInt32(exec));
        break;
    }
    case WidthAttrNum: {
        HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(impl());

        imp->setWidth(valueToStringWithNullCheck(exec, value));
        break;
    }
    }
}

JSValue* JSHTMLObjectElement::getConstructor(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLObjectElementConstructor>(exec, "[[HTMLObjectElement.constructor]]");
}
JSValue* JSHTMLObjectElementPrototypeFunction::callAsFunction(ExecState* exec, JSObject* thisObj, const List& args)
{
    if (!thisObj->inherits(&JSHTMLObjectElement::info))
      return throwError(exec, TypeError);

    HTMLObjectElement* imp = static_cast<HTMLObjectElement*>(static_cast<JSHTMLObjectElement*>(thisObj)->impl());

    switch (id) {
    case JSHTMLObjectElement::GetSVGDocumentFuncNum: {
        ExceptionCode ec = 0;
        if (!checkNodeSecurity(exec, imp->getSVGDocument(ec)))
            return jsUndefined();


        KJS::JSValue* result = toJS(exec, WTF::getPtr(imp->getSVGDocument(ec)));
        setDOMException(exec, ec);
        return result;
    }
    }
    return 0;
}

}
