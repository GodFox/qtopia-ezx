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

#include "JSHTMLMenuElement.h"

#include <wtf/GetPtr.h>

#include "HTMLMenuElement.h"

using namespace KJS;

namespace WebCore {

/* Hash table */

static const HashEntry JSHTMLMenuElementTableEntries[] =
{
    { 0, 0, 0, 0, 0 },
    { "compact", JSHTMLMenuElement::CompactAttrNum, DontDelete, 0, &JSHTMLMenuElementTableEntries[2] },
    { "constructor", JSHTMLMenuElement::ConstructorAttrNum, DontDelete|DontEnum|ReadOnly, 0, 0 }
};

static const HashTable JSHTMLMenuElementTable = 
{
    2, 3, JSHTMLMenuElementTableEntries, 2
};

/* Hash table for constructor */

static const HashEntry JSHTMLMenuElementConstructorTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLMenuElementConstructorTable = 
{
    2, 1, JSHTMLMenuElementConstructorTableEntries, 1
};

class JSHTMLMenuElementConstructor : public DOMObject {
public:
    JSHTMLMenuElementConstructor(ExecState* exec)
    {
        setPrototype(exec->lexicalInterpreter()->builtinObjectPrototype());
        putDirect(exec->propertyNames().prototype, JSHTMLMenuElementPrototype::self(exec), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;

    virtual bool implementsHasInstance() const { return true; }
};

const ClassInfo JSHTMLMenuElementConstructor::info = { "HTMLMenuElementConstructor", 0, &JSHTMLMenuElementConstructorTable, 0 };

bool JSHTMLMenuElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLMenuElementConstructor, DOMObject>(exec, &JSHTMLMenuElementConstructorTable, this, propertyName, slot);
}

JSValue* JSHTMLMenuElementConstructor::getValueProperty(ExecState*, int token) const
{
    // The token is the numeric value of its associated constant
    return jsNumber(token);
}

/* Hash table for prototype */

static const HashEntry JSHTMLMenuElementPrototypeTableEntries[] =
{
    { 0, 0, 0, 0, 0 }
};

static const HashTable JSHTMLMenuElementPrototypeTable = 
{
    2, 1, JSHTMLMenuElementPrototypeTableEntries, 1
};

const ClassInfo JSHTMLMenuElementPrototype::info = { "HTMLMenuElementPrototype", 0, &JSHTMLMenuElementPrototypeTable, 0 };

JSObject* JSHTMLMenuElementPrototype::self(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLMenuElementPrototype>(exec, "[[JSHTMLMenuElement.prototype]]");
}

const ClassInfo JSHTMLMenuElement::info = { "HTMLMenuElement", &JSHTMLElement::info, &JSHTMLMenuElementTable, 0 };

JSHTMLMenuElement::JSHTMLMenuElement(ExecState* exec, HTMLMenuElement* impl)
    : JSHTMLElement(exec, impl)
{
    setPrototype(JSHTMLMenuElementPrototype::self(exec));
}

bool JSHTMLMenuElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLMenuElement, JSHTMLElement>(exec, &JSHTMLMenuElementTable, this, propertyName, slot);
}

JSValue* JSHTMLMenuElement::getValueProperty(ExecState* exec, int token) const
{
    switch (token) {
    case CompactAttrNum: {
        HTMLMenuElement* imp = static_cast<HTMLMenuElement*>(impl());

        return jsBoolean(imp->compact());
    }
    case ConstructorAttrNum:
        return getConstructor(exec);
    }
    return 0;
}

void JSHTMLMenuElement::put(ExecState* exec, const Identifier& propertyName, JSValue* value, int attr)
{
    lookupPut<JSHTMLMenuElement, JSHTMLElement>(exec, propertyName, value, attr, &JSHTMLMenuElementTable, this);
}

void JSHTMLMenuElement::putValueProperty(ExecState* exec, int token, JSValue* value, int /*attr*/)
{
    switch (token) {
    case CompactAttrNum: {
        HTMLMenuElement* imp = static_cast<HTMLMenuElement*>(impl());

        imp->setCompact(value->toBoolean(exec));
        break;
    }
    }
}

JSValue* JSHTMLMenuElement::getConstructor(ExecState* exec)
{
    return KJS::cacheGlobalObject<JSHTMLMenuElementConstructor>(exec, "[[HTMLMenuElement.constructor]]");
}

}
