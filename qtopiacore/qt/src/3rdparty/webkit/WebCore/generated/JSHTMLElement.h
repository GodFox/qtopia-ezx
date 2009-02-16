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

#ifndef JSHTMLElement_H
#define JSHTMLElement_H

#include "JSElement.h"

namespace WebCore {

class HTMLElement;

class JSHTMLElement : public JSElement {
public:
    JSHTMLElement(KJS::ExecState*, HTMLElement*);
    virtual bool getOwnPropertySlot(KJS::ExecState*, const KJS::Identifier&, KJS::PropertySlot&);
    KJS::JSValue* getValueProperty(KJS::ExecState*, int token) const;
    virtual void put(KJS::ExecState*, const KJS::Identifier&, KJS::JSValue*, int attr = KJS::None);
    void putValueProperty(KJS::ExecState*, int, KJS::JSValue*, int attr);
    virtual const KJS::ClassInfo* classInfo() const { return &info; }
    static const KJS::ClassInfo info;

    virtual void pushEventHandlerScope(KJS::ExecState*, KJS::ScopeChain&) const;

    static KJS::JSValue* getConstructor(KJS::ExecState*);
    enum {
        // Attributes
        IdAttrNum, TitleAttrNum, LangAttrNum, DirAttrNum, 
        ClassNameAttrNum, InnerHTMLAttrNum, InnerTextAttrNum, OuterHTMLAttrNum, 
        OuterTextAttrNum, ChildrenAttrNum, ContentEditableAttrNum, IsContentEditableAttrNum, 

        // The Constructor Attribute
        ConstructorAttrNum
    };
    HTMLElement* impl() const;
};

HTMLElement* toHTMLElement(KJS::JSValue*);

class JSHTMLElementPrototype : public KJS::JSObject {
public:
    static KJS::JSObject* self(KJS::ExecState* exec);
    virtual const KJS::ClassInfo* classInfo() const { return &info; }
    static const KJS::ClassInfo info;
    JSHTMLElementPrototype(KJS::ExecState* exec)
        : KJS::JSObject(JSElementPrototype::self(exec)) { }
};

} // namespace WebCore

#endif
