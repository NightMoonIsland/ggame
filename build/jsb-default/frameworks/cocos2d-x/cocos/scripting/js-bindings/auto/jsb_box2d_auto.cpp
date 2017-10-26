#include "scripting/js-bindings/auto/jsb_box2d_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "Box2D/Box2D.h"
#include "scripting/js-bindings/manual/box2d/js_bindings_box2d_manual.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
JSClass  *jsb_b2Draw_class;
JSObject *jsb_b2Draw_prototype;

bool js_box2dclasses_b2Draw_AppendFlags(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_AppendFlags : Invalid Native Object");
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= jsval_to_uint32(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_AppendFlags : Error processing arguments");
        cobj->AppendFlags(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_AppendFlags : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Draw_DrawTransform(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_DrawTransform : Invalid Native Object");
    if (argc == 1) {
        b2Transform arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_DrawTransform : Error processing arguments");
        cobj->DrawTransform(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_DrawTransform : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Draw_ClearFlags(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_ClearFlags : Invalid Native Object");
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= jsval_to_uint32(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_ClearFlags : Error processing arguments");
        cobj->ClearFlags(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_ClearFlags : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Draw_DrawPolygon(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_DrawPolygon : Invalid Native Object");
    if (argc == 3) {
        const b2Vec2* arg0 = nullptr;
        int arg1 = 0;
        b2Color arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Vec2*
		ok = false;
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR b2Color
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_DrawPolygon : Error processing arguments");
        cobj->DrawPolygon(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_DrawPolygon : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Draw_ClearDraw(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_ClearDraw : Invalid Native Object");
    if (argc == 0) {
        cobj->ClearDraw();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_ClearDraw : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Draw_DrawSolidPolygon(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_DrawSolidPolygon : Invalid Native Object");
    if (argc == 3) {
        const b2Vec2* arg0 = nullptr;
        int arg1 = 0;
        b2Color arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Vec2*
		ok = false;
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR b2Color
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_DrawSolidPolygon : Error processing arguments");
        cobj->DrawSolidPolygon(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_DrawSolidPolygon : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Draw_DrawCircle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_DrawCircle : Invalid Native Object");
    if (argc == 3) {
        b2Vec2 arg0;
        double arg1 = 0;
        b2Color arg2;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR b2Color
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_DrawCircle : Error processing arguments");
        cobj->DrawCircle(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_DrawCircle : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Draw_SetFlags(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_SetFlags : Invalid Native Object");
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= jsval_to_uint32(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_SetFlags : Error processing arguments");
        cobj->SetFlags(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_SetFlags : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Draw_DrawSegment(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_DrawSegment : Invalid Native Object");
    if (argc == 3) {
        b2Vec2 arg0;
        b2Vec2 arg1;
        b2Color arg2;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        #pragma warning NO CONVERSION TO NATIVE FOR b2Color
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_DrawSegment : Error processing arguments");
        cobj->DrawSegment(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_DrawSegment : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Draw_DrawSolidCircle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_DrawSolidCircle : Invalid Native Object");
    if (argc == 4) {
        b2Vec2 arg0;
        double arg1 = 0;
        b2Vec2 arg2;
        b2Color arg3;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_b2Vec2(cx, args.get(2), &arg2);
        #pragma warning NO CONVERSION TO NATIVE FOR b2Color
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Draw_DrawSolidCircle : Error processing arguments");
        cobj->DrawSolidCircle(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_DrawSolidCircle : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_box2dclasses_b2Draw_GetFlags(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Draw* cobj = (b2Draw *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Draw_GetFlags : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->GetFlags();
        JS::RootedValue jsret(cx);
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Draw_GetFlags : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_box2dclasses_b2Draw(JSContext *cx, JS::HandleObject global) {
    jsb_b2Draw_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2Draw_class->name = "Draw";
    jsb_b2Draw_class->addProperty = JS_PropertyStub;
    jsb_b2Draw_class->delProperty = JS_DeletePropertyStub;
    jsb_b2Draw_class->getProperty = JS_PropertyStub;
    jsb_b2Draw_class->setProperty = JS_StrictPropertyStub;
    jsb_b2Draw_class->enumerate = JS_EnumerateStub;
    jsb_b2Draw_class->resolve = JS_ResolveStub;
    jsb_b2Draw_class->convert = JS_ConvertStub;
    jsb_b2Draw_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("AppendFlags", js_box2dclasses_b2Draw_AppendFlags, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawTransform", js_box2dclasses_b2Draw_DrawTransform, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ClearFlags", js_box2dclasses_b2Draw_ClearFlags, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawPolygon", js_box2dclasses_b2Draw_DrawPolygon, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ClearDraw", js_box2dclasses_b2Draw_ClearDraw, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawSolidPolygon", js_box2dclasses_b2Draw_DrawSolidPolygon, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawCircle", js_box2dclasses_b2Draw_DrawCircle, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFlags", js_box2dclasses_b2Draw_SetFlags, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawSegment", js_box2dclasses_b2Draw_DrawSegment, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawSolidCircle", js_box2dclasses_b2Draw_DrawSolidCircle, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFlags", js_box2dclasses_b2Draw_GetFlags, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2Draw_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2Draw_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2Draw_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2Draw"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2Draw>(cx, jsb_b2Draw_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2Shape_class;
JSObject *jsb_b2Shape_prototype;

bool js_box2dclasses_b2Shape_ComputeMass(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_ComputeMass : Invalid Native Object");
    if (argc == 2) {
        b2MassData* arg0 = nullptr;
        double arg1 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Shape_ComputeMass : Error processing arguments");
        cobj->ComputeMass(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_ComputeMass : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2Shape_Clone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_Clone : Invalid Native Object");
    if (argc == 1) {
        b2BlockAllocator* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2BlockAllocator*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Shape_Clone : Error processing arguments");
        b2Shape* ret = cobj->Clone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_Clone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Shape_GetType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_GetType : Invalid Native Object");
    if (argc == 0) {
        int ret = (int)cobj->GetType();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_GetType : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Shape_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_RayCast : Invalid Native Object");
    if (argc == 4) {
        b2RayCastOutput* arg0 = nullptr;
        b2RayCastInput arg1;
        b2Transform arg2;
        int arg3 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastOutput*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastInput
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Shape_RayCast : Error processing arguments");
        bool ret = cobj->RayCast(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_RayCast : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_box2dclasses_b2Shape_ComputeAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_ComputeAABB : Invalid Native Object");
    if (argc == 3) {
        b2AABB* arg0 = nullptr;
        b2Transform arg1;
        int arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2AABB*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Shape_ComputeAABB : Error processing arguments");
        cobj->ComputeAABB(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_ComputeAABB : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Shape_GetChildCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_GetChildCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_GetChildCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Shape_TestPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Shape* cobj = (b2Shape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Shape_TestPoint : Invalid Native Object");
    if (argc == 2) {
        b2Transform arg0;
        b2Vec2 arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Shape_TestPoint : Error processing arguments");
        bool ret = cobj->TestPoint(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Shape_TestPoint : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}

void js_register_box2dclasses_b2Shape(JSContext *cx, JS::HandleObject global) {
    jsb_b2Shape_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2Shape_class->name = "Shape";
    jsb_b2Shape_class->addProperty = JS_PropertyStub;
    jsb_b2Shape_class->delProperty = JS_DeletePropertyStub;
    jsb_b2Shape_class->getProperty = JS_PropertyStub;
    jsb_b2Shape_class->setProperty = JS_StrictPropertyStub;
    jsb_b2Shape_class->enumerate = JS_EnumerateStub;
    jsb_b2Shape_class->resolve = JS_ResolveStub;
    jsb_b2Shape_class->convert = JS_ConvertStub;
    jsb_b2Shape_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ComputeMass", js_box2dclasses_b2Shape_ComputeMass, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Clone", js_box2dclasses_b2Shape_Clone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetType", js_box2dclasses_b2Shape_GetType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2Shape_RayCast, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ComputeAABB", js_box2dclasses_b2Shape_ComputeAABB, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildCount", js_box2dclasses_b2Shape_GetChildCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("TestPoint", js_box2dclasses_b2Shape_TestPoint, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2Shape_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2Shape_class,
        dummy_constructor<b2Shape>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2Shape_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2Shape"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2Shape>(cx, jsb_b2Shape_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2CircleShape_class;
JSObject *jsb_b2CircleShape_prototype;

bool js_box2dclasses_b2CircleShape_ComputeMass(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_ComputeMass : Invalid Native Object");
    if (argc == 2) {
        b2MassData* arg0 = nullptr;
        double arg1 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_ComputeMass : Error processing arguments");
        cobj->ComputeMass(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_ComputeMass : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2CircleShape_GetVertex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_GetVertex : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_GetVertex : Error processing arguments");
        const b2Vec2& ret = cobj->GetVertex(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_GetVertex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2CircleShape_Clone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_Clone : Invalid Native Object");
    if (argc == 1) {
        b2BlockAllocator* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2BlockAllocator*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_Clone : Error processing arguments");
        b2Shape* ret = cobj->Clone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_Clone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2CircleShape_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_RayCast : Invalid Native Object");
    if (argc == 4) {
        b2RayCastOutput* arg0 = nullptr;
        b2RayCastInput arg1;
        b2Transform arg2;
        int arg3 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastOutput*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastInput
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_RayCast : Error processing arguments");
        bool ret = cobj->RayCast(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_RayCast : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_box2dclasses_b2CircleShape_ComputeAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_ComputeAABB : Invalid Native Object");
    if (argc == 3) {
        b2AABB* arg0 = nullptr;
        b2Transform arg1;
        int arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2AABB*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_ComputeAABB : Error processing arguments");
        cobj->ComputeAABB(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_ComputeAABB : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2CircleShape_GetVertexCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_GetVertexCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetVertexCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_GetVertexCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2CircleShape_GetChildCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_GetChildCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_GetChildCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2CircleShape_TestPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_TestPoint : Invalid Native Object");
    if (argc == 2) {
        b2Transform arg0;
        b2Vec2 arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_TestPoint : Error processing arguments");
        bool ret = cobj->TestPoint(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_TestPoint : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2CircleShape_GetSupportVertex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_GetSupportVertex : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_GetSupportVertex : Error processing arguments");
        const b2Vec2& ret = cobj->GetSupportVertex(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_GetSupportVertex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2CircleShape_GetSupport(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2CircleShape* cobj = (b2CircleShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2CircleShape_GetSupport : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2CircleShape_GetSupport : Error processing arguments");
        int ret = cobj->GetSupport(arg0);
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2CircleShape_GetSupport : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2CircleShape_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    b2CircleShape* cobj = new (std::nothrow) b2CircleShape();

    js_type_class_t *typeClass = js_get_type_from_native<b2CircleShape>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "b2CircleShape"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_b2Shape_prototype;

void js_b2CircleShape_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (b2CircleShape)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        b2CircleShape *nobj = static_cast<b2CircleShape *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            JS::RootedValue flagValue(cx);
            JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
            if (flagValue.isNullOrUndefined()){
                delete nobj;
            }
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_box2dclasses_b2CircleShape(JSContext *cx, JS::HandleObject global) {
    jsb_b2CircleShape_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2CircleShape_class->name = "CircleShape";
    jsb_b2CircleShape_class->addProperty = JS_PropertyStub;
    jsb_b2CircleShape_class->delProperty = JS_DeletePropertyStub;
    jsb_b2CircleShape_class->getProperty = JS_PropertyStub;
    jsb_b2CircleShape_class->setProperty = JS_StrictPropertyStub;
    jsb_b2CircleShape_class->enumerate = JS_EnumerateStub;
    jsb_b2CircleShape_class->resolve = JS_ResolveStub;
    jsb_b2CircleShape_class->convert = JS_ConvertStub;
    jsb_b2CircleShape_class->finalize = js_b2CircleShape_finalize;
    jsb_b2CircleShape_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ComputeMass", js_box2dclasses_b2CircleShape_ComputeMass, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetVertex", js_box2dclasses_b2CircleShape_GetVertex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Clone", js_box2dclasses_b2CircleShape_Clone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2CircleShape_RayCast, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ComputeAABB", js_box2dclasses_b2CircleShape_ComputeAABB, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetVertexCount", js_box2dclasses_b2CircleShape_GetVertexCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildCount", js_box2dclasses_b2CircleShape_GetChildCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("TestPoint", js_box2dclasses_b2CircleShape_TestPoint, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetSupportVertex", js_box2dclasses_b2CircleShape_GetSupportVertex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetSupport", js_box2dclasses_b2CircleShape_GetSupport, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Shape_prototype);
    jsb_b2CircleShape_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2CircleShape_class,
        js_box2dclasses_b2CircleShape_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2CircleShape_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2CircleShape"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2CircleShape>(cx, jsb_b2CircleShape_class, proto, parent_proto);
}

JSClass  *jsb_b2EdgeShape_class;
JSObject *jsb_b2EdgeShape_prototype;

bool js_box2dclasses_b2EdgeShape_Set(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_Set : Invalid Native Object");
    if (argc == 2) {
        b2Vec2 arg0;
        b2Vec2 arg1;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2EdgeShape_Set : Error processing arguments");
        cobj->Set(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_Set : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2EdgeShape_ComputeMass(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_ComputeMass : Invalid Native Object");
    if (argc == 2) {
        b2MassData* arg0 = nullptr;
        double arg1 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2EdgeShape_ComputeMass : Error processing arguments");
        cobj->ComputeMass(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_ComputeMass : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2EdgeShape_Clone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_Clone : Invalid Native Object");
    if (argc == 1) {
        b2BlockAllocator* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2BlockAllocator*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2EdgeShape_Clone : Error processing arguments");
        b2Shape* ret = cobj->Clone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_Clone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2EdgeShape_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_RayCast : Invalid Native Object");
    if (argc == 4) {
        b2RayCastOutput* arg0 = nullptr;
        b2RayCastInput arg1;
        b2Transform arg2;
        int arg3 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastOutput*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastInput
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2EdgeShape_RayCast : Error processing arguments");
        bool ret = cobj->RayCast(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_RayCast : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_box2dclasses_b2EdgeShape_ComputeAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_ComputeAABB : Invalid Native Object");
    if (argc == 3) {
        b2AABB* arg0 = nullptr;
        b2Transform arg1;
        int arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2AABB*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2EdgeShape_ComputeAABB : Error processing arguments");
        cobj->ComputeAABB(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_ComputeAABB : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2EdgeShape_GetChildCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_GetChildCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_GetChildCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2EdgeShape_TestPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2EdgeShape* cobj = (b2EdgeShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2EdgeShape_TestPoint : Invalid Native Object");
    if (argc == 2) {
        b2Transform arg0;
        b2Vec2 arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2EdgeShape_TestPoint : Error processing arguments");
        bool ret = cobj->TestPoint(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2EdgeShape_TestPoint : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2EdgeShape_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    b2EdgeShape* cobj = new (std::nothrow) b2EdgeShape();

    js_type_class_t *typeClass = js_get_type_from_native<b2EdgeShape>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "b2EdgeShape"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_b2Shape_prototype;

void js_b2EdgeShape_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (b2EdgeShape)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        b2EdgeShape *nobj = static_cast<b2EdgeShape *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            JS::RootedValue flagValue(cx);
            JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
            if (flagValue.isNullOrUndefined()){
                delete nobj;
            }
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_box2dclasses_b2EdgeShape(JSContext *cx, JS::HandleObject global) {
    jsb_b2EdgeShape_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2EdgeShape_class->name = "EdgeShape";
    jsb_b2EdgeShape_class->addProperty = JS_PropertyStub;
    jsb_b2EdgeShape_class->delProperty = JS_DeletePropertyStub;
    jsb_b2EdgeShape_class->getProperty = JS_PropertyStub;
    jsb_b2EdgeShape_class->setProperty = JS_StrictPropertyStub;
    jsb_b2EdgeShape_class->enumerate = JS_EnumerateStub;
    jsb_b2EdgeShape_class->resolve = JS_ResolveStub;
    jsb_b2EdgeShape_class->convert = JS_ConvertStub;
    jsb_b2EdgeShape_class->finalize = js_b2EdgeShape_finalize;
    jsb_b2EdgeShape_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("Set", js_box2dclasses_b2EdgeShape_Set, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ComputeMass", js_box2dclasses_b2EdgeShape_ComputeMass, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Clone", js_box2dclasses_b2EdgeShape_Clone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2EdgeShape_RayCast, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ComputeAABB", js_box2dclasses_b2EdgeShape_ComputeAABB, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildCount", js_box2dclasses_b2EdgeShape_GetChildCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("TestPoint", js_box2dclasses_b2EdgeShape_TestPoint, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Shape_prototype);
    jsb_b2EdgeShape_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2EdgeShape_class,
        js_box2dclasses_b2EdgeShape_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2EdgeShape_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2EdgeShape"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2EdgeShape>(cx, jsb_b2EdgeShape_class, proto, parent_proto);
}

JSClass  *jsb_b2ChainShape_class;
JSObject *jsb_b2ChainShape_prototype;

bool js_box2dclasses_b2ChainShape_ComputeMass(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_ComputeMass : Invalid Native Object");
    if (argc == 2) {
        b2MassData* arg0 = nullptr;
        double arg1 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_ComputeMass : Error processing arguments");
        cobj->ComputeMass(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_ComputeMass : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2ChainShape_Clear(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_Clear : Invalid Native Object");
    if (argc == 0) {
        cobj->Clear();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_Clear : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2ChainShape_TestPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_TestPoint : Invalid Native Object");
    if (argc == 2) {
        b2Transform arg0;
        b2Vec2 arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_TestPoint : Error processing arguments");
        bool ret = cobj->TestPoint(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_TestPoint : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2ChainShape_GetChildEdge(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_GetChildEdge : Invalid Native Object");
    if (argc == 2) {
        b2EdgeShape* arg0 = nullptr;
        int arg1 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2EdgeShape*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_GetChildEdge : Error processing arguments");
        cobj->GetChildEdge(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_GetChildEdge : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2ChainShape_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_RayCast : Invalid Native Object");
    if (argc == 4) {
        b2RayCastOutput* arg0 = nullptr;
        b2RayCastInput arg1;
        b2Transform arg2;
        int arg3 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastOutput*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastInput
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_RayCast : Error processing arguments");
        bool ret = cobj->RayCast(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_RayCast : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_box2dclasses_b2ChainShape_ComputeAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_ComputeAABB : Invalid Native Object");
    if (argc == 3) {
        b2AABB* arg0 = nullptr;
        b2Transform arg1;
        int arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2AABB*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_ComputeAABB : Error processing arguments");
        cobj->ComputeAABB(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_ComputeAABB : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2ChainShape_GetChildCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_GetChildCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_GetChildCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2ChainShape_SetPrevVertex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_SetPrevVertex : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_SetPrevVertex : Error processing arguments");
        cobj->SetPrevVertex(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_SetPrevVertex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2ChainShape_SetNextVertex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_SetNextVertex : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_SetNextVertex : Error processing arguments");
        cobj->SetNextVertex(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_SetNextVertex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2ChainShape_Clone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ChainShape* cobj = (b2ChainShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ChainShape_Clone : Invalid Native Object");
    if (argc == 1) {
        b2BlockAllocator* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2BlockAllocator*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ChainShape_Clone : Error processing arguments");
        b2Shape* ret = cobj->Clone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ChainShape_Clone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2ChainShape_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    b2ChainShape* cobj = new (std::nothrow) b2ChainShape();

    js_type_class_t *typeClass = js_get_type_from_native<b2ChainShape>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "b2ChainShape"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_b2Shape_prototype;

void js_b2ChainShape_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (b2ChainShape)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        b2ChainShape *nobj = static_cast<b2ChainShape *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            JS::RootedValue flagValue(cx);
            JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
            if (flagValue.isNullOrUndefined()){
                delete nobj;
            }
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_box2dclasses_b2ChainShape(JSContext *cx, JS::HandleObject global) {
    jsb_b2ChainShape_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2ChainShape_class->name = "ChainShape";
    jsb_b2ChainShape_class->addProperty = JS_PropertyStub;
    jsb_b2ChainShape_class->delProperty = JS_DeletePropertyStub;
    jsb_b2ChainShape_class->getProperty = JS_PropertyStub;
    jsb_b2ChainShape_class->setProperty = JS_StrictPropertyStub;
    jsb_b2ChainShape_class->enumerate = JS_EnumerateStub;
    jsb_b2ChainShape_class->resolve = JS_ResolveStub;
    jsb_b2ChainShape_class->convert = JS_ConvertStub;
    jsb_b2ChainShape_class->finalize = js_b2ChainShape_finalize;
    jsb_b2ChainShape_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ComputeMass", js_box2dclasses_b2ChainShape_ComputeMass, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Clear", js_box2dclasses_b2ChainShape_Clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("TestPoint", js_box2dclasses_b2ChainShape_TestPoint, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildEdge", js_box2dclasses_b2ChainShape_GetChildEdge, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2ChainShape_RayCast, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ComputeAABB", js_box2dclasses_b2ChainShape_ComputeAABB, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildCount", js_box2dclasses_b2ChainShape_GetChildCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetPrevVertex", js_box2dclasses_b2ChainShape_SetPrevVertex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetNextVertex", js_box2dclasses_b2ChainShape_SetNextVertex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Clone", js_box2dclasses_b2ChainShape_Clone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Shape_prototype);
    jsb_b2ChainShape_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2ChainShape_class,
        js_box2dclasses_b2ChainShape_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2ChainShape_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2ChainShape"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2ChainShape>(cx, jsb_b2ChainShape_class, proto, parent_proto);
}

JSClass  *jsb_b2PolygonShape_class;
JSObject *jsb_b2PolygonShape_prototype;

bool js_box2dclasses_b2PolygonShape_ComputeMass(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_ComputeMass : Invalid Native Object");
    if (argc == 2) {
        b2MassData* arg0 = nullptr;
        double arg1 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PolygonShape_ComputeMass : Error processing arguments");
        cobj->ComputeMass(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_ComputeMass : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2PolygonShape_GetVertex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_GetVertex : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PolygonShape_GetVertex : Error processing arguments");
        const b2Vec2& ret = cobj->GetVertex(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_GetVertex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PolygonShape_Clone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_Clone : Invalid Native Object");
    if (argc == 1) {
        b2BlockAllocator* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2BlockAllocator*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PolygonShape_Clone : Error processing arguments");
        b2Shape* ret = cobj->Clone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_Clone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PolygonShape_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_RayCast : Invalid Native Object");
    if (argc == 4) {
        b2RayCastOutput* arg0 = nullptr;
        b2RayCastInput arg1;
        b2Transform arg2;
        int arg3 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastOutput*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastInput
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PolygonShape_RayCast : Error processing arguments");
        bool ret = cobj->RayCast(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_RayCast : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_box2dclasses_b2PolygonShape_ComputeAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_ComputeAABB : Invalid Native Object");
    if (argc == 3) {
        b2AABB* arg0 = nullptr;
        b2Transform arg1;
        int arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2AABB*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PolygonShape_ComputeAABB : Error processing arguments");
        cobj->ComputeAABB(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_ComputeAABB : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2PolygonShape_GetVertexCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_GetVertexCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetVertexCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_GetVertexCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PolygonShape_GetChildCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_GetChildCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_GetChildCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PolygonShape_TestPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_TestPoint : Invalid Native Object");
    if (argc == 2) {
        b2Transform arg0;
        b2Vec2 arg1;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PolygonShape_TestPoint : Error processing arguments");
        bool ret = cobj->TestPoint(arg0, arg1);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_TestPoint : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2PolygonShape_Validate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PolygonShape* cobj = (b2PolygonShape *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PolygonShape_Validate : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->Validate();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PolygonShape_Validate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PolygonShape_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    b2PolygonShape* cobj = new (std::nothrow) b2PolygonShape();

    js_type_class_t *typeClass = js_get_type_from_native<b2PolygonShape>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "b2PolygonShape"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_b2Shape_prototype;

void js_b2PolygonShape_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (b2PolygonShape)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        b2PolygonShape *nobj = static_cast<b2PolygonShape *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            JS::RootedValue flagValue(cx);
            JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
            if (flagValue.isNullOrUndefined()){
                delete nobj;
            }
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_box2dclasses_b2PolygonShape(JSContext *cx, JS::HandleObject global) {
    jsb_b2PolygonShape_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2PolygonShape_class->name = "PolygonShape";
    jsb_b2PolygonShape_class->addProperty = JS_PropertyStub;
    jsb_b2PolygonShape_class->delProperty = JS_DeletePropertyStub;
    jsb_b2PolygonShape_class->getProperty = JS_PropertyStub;
    jsb_b2PolygonShape_class->setProperty = JS_StrictPropertyStub;
    jsb_b2PolygonShape_class->enumerate = JS_EnumerateStub;
    jsb_b2PolygonShape_class->resolve = JS_ResolveStub;
    jsb_b2PolygonShape_class->convert = JS_ConvertStub;
    jsb_b2PolygonShape_class->finalize = js_b2PolygonShape_finalize;
    jsb_b2PolygonShape_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ComputeMass", js_box2dclasses_b2PolygonShape_ComputeMass, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetVertex", js_box2dclasses_b2PolygonShape_GetVertex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Clone", js_box2dclasses_b2PolygonShape_Clone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2PolygonShape_RayCast, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ComputeAABB", js_box2dclasses_b2PolygonShape_ComputeAABB, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetVertexCount", js_box2dclasses_b2PolygonShape_GetVertexCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildCount", js_box2dclasses_b2PolygonShape_GetChildCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("TestPoint", js_box2dclasses_b2PolygonShape_TestPoint, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Validate", js_box2dclasses_b2PolygonShape_Validate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Shape_prototype);
    jsb_b2PolygonShape_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2PolygonShape_class,
        js_box2dclasses_b2PolygonShape_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2PolygonShape_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2PolygonShape"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2PolygonShape>(cx, jsb_b2PolygonShape_class, proto, parent_proto);
}

JSClass  *jsb_b2Body_class;
JSObject *jsb_b2Body_prototype;

bool js_box2dclasses_b2Body_GetAngle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetAngle : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetAngle();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetAngle : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_IsSleepingAllowed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_IsSleepingAllowed : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsSleepingAllowed();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_IsSleepingAllowed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_SetAngularDamping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetAngularDamping : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetAngularDamping : Error processing arguments");
        cobj->SetAngularDamping(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetAngularDamping : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetActive(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetActive : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetActive : Error processing arguments");
        cobj->SetActive(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetActive : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetGravityScale(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetGravityScale : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetGravityScale : Error processing arguments");
        cobj->SetGravityScale(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetGravityScale : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetAngularVelocity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetAngularVelocity : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetAngularVelocity();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetAngularVelocity : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetFixtureList(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Body* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Body *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetFixtureList : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Fixture* ret = cobj->GetFixtureList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Fixture* ret = cobj->GetFixtureList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetFixtureList : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Body_ApplyForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_ApplyForce : Invalid Native Object");
    if (argc == 3) {
        b2Vec2 arg0;
        b2Vec2 arg1;
        bool arg2;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        arg2 = JS::ToBoolean(args.get(2));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_ApplyForce : Error processing arguments");
        cobj->ApplyForce(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_ApplyForce : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Body_GetLocalPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLocalPoint : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetLocalPoint : Error processing arguments");
        b2Vec2 ret = cobj->GetLocalPoint(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLocalPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetLinearVelocity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetLinearVelocity : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetLinearVelocity : Error processing arguments");
        cobj->SetLinearVelocity(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetLinearVelocity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetLinearVelocity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLinearVelocity : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLinearVelocity();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLinearVelocity : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetNext(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Body* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Body *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetNext : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Body* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Body* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetNext : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Body_SetSleepingAllowed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetSleepingAllowed : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetSleepingAllowed : Error processing arguments");
        cobj->SetSleepingAllowed(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetSleepingAllowed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetTransform(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetTransform : Invalid Native Object");
    if (argc == 2) {
        b2Vec2 arg0;
        double arg1 = 0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetTransform : Error processing arguments");
        cobj->SetTransform(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetTransform : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2Body_GetMass(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetMass : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMass();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetMass : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_SetAngularVelocity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetAngularVelocity : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetAngularVelocity : Error processing arguments");
        cobj->SetAngularVelocity(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetAngularVelocity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetMassData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetMassData : Invalid Native Object");
    if (argc == 1) {
        b2MassData* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetMassData : Error processing arguments");
        cobj->GetMassData(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetMassData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetLinearVelocityFromWorldPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLinearVelocityFromWorldPoint : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetLinearVelocityFromWorldPoint : Error processing arguments");
        b2Vec2 ret = cobj->GetLinearVelocityFromWorldPoint(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLinearVelocityFromWorldPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_ResetMassData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_ResetMassData : Invalid Native Object");
    if (argc == 0) {
        cobj->ResetMassData();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_ResetMassData : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_ApplyForceToCenter(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_ApplyForceToCenter : Invalid Native Object");
    if (argc == 2) {
        b2Vec2 arg0;
        bool arg1;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_ApplyForceToCenter : Error processing arguments");
        cobj->ApplyForceToCenter(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_ApplyForceToCenter : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2Body_ApplyTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_ApplyTorque : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        bool arg1;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_ApplyTorque : Error processing arguments");
        cobj->ApplyTorque(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_ApplyTorque : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2Body_IsAwake(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_IsAwake : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsAwake();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_IsAwake : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_SetType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetType : Invalid Native Object");
    if (argc == 1) {
        b2BodyType arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetType : Error processing arguments");
        cobj->SetType(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetType : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetMassData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetMassData : Invalid Native Object");
    if (argc == 1) {
        const b2MassData* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetMassData : Error processing arguments");
        cobj->SetMassData(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetMassData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetTransform(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetTransform : Invalid Native Object");
    if (argc == 0) {
        const b2Transform& ret = cobj->GetTransform();
        JS::RootedValue jsret(cx);
        #pragma warning NO CONVERSION FROM NATIVE FOR b2Transform;
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetTransform : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetWorldCenter(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetWorldCenter : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetWorldCenter();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetWorldCenter : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetAngularDamping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetAngularDamping : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetAngularDamping();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetAngularDamping : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_ApplyLinearImpulse(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_ApplyLinearImpulse : Invalid Native Object");
    if (argc == 3) {
        b2Vec2 arg0;
        b2Vec2 arg1;
        bool arg2;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        arg2 = JS::ToBoolean(args.get(2));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_ApplyLinearImpulse : Error processing arguments");
        cobj->ApplyLinearImpulse(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_ApplyLinearImpulse : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Body_IsFixedRotation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_IsFixedRotation : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsFixedRotation();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_IsFixedRotation : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetLocalCenter(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLocalCenter : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalCenter();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLocalCenter : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetWorldVector(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetWorldVector : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetWorldVector : Error processing arguments");
        b2Vec2 ret = cobj->GetWorldVector(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetWorldVector : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetLinearVelocityFromLocalPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLinearVelocityFromLocalPoint : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetLinearVelocityFromLocalPoint : Error processing arguments");
        b2Vec2 ret = cobj->GetLinearVelocityFromLocalPoint(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLinearVelocityFromLocalPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetContactList(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Body* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Body *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetContactList : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2ContactEdge* ret = cobj->GetContactList();
            jsval jsret = JSVAL_NULL;
            #pragma warning NO CONVERSION FROM NATIVE FOR b2ContactEdge*;
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2ContactEdge* ret = cobj->GetContactList();
            jsval jsret = JSVAL_NULL;
            #pragma warning NO CONVERSION FROM NATIVE FOR b2ContactEdge*;
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetContactList : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Body_GetWorldPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetWorldPoint : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetWorldPoint : Error processing arguments");
        b2Vec2 ret = cobj->GetWorldPoint(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetWorldPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetAwake(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetAwake : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetAwake : Error processing arguments");
        cobj->SetAwake(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetAwake : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetLinearDamping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLinearDamping : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetLinearDamping();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLinearDamping : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_IsBullet(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_IsBullet : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsBullet();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_IsBullet : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetWorld(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Body* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Body *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetWorld : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2World* ret = cobj->GetWorld();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2World>(cx, (b2World*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2World* ret = cobj->GetWorld();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2World>(cx, (b2World*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetWorld : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Body_GetLocalVector(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetLocalVector : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_GetLocalVector : Error processing arguments");
        b2Vec2 ret = cobj->GetLocalVector(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetLocalVector : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_SetLinearDamping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetLinearDamping : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetLinearDamping : Error processing arguments");
        cobj->SetLinearDamping(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetLinearDamping : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_SetBullet(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetBullet : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetBullet : Error processing arguments");
        cobj->SetBullet(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetBullet : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetType : Invalid Native Object");
    if (argc == 0) {
        int ret = (int)cobj->GetType();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetType : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_GetGravityScale(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetGravityScale : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetGravityScale();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetGravityScale : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_DestroyFixture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_DestroyFixture : Invalid Native Object");
    if (argc == 1) {
        b2Fixture* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Fixture*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_DestroyFixture : Error processing arguments");
        cobj->DestroyFixture(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_DestroyFixture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_GetInertia(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetInertia : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetInertia();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetInertia : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_IsActive(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_IsActive : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsActive();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_IsActive : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Body_SetFixedRotation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_SetFixedRotation : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_SetFixedRotation : Error processing arguments");
        cobj->SetFixedRotation(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_SetFixedRotation : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Body_ApplyAngularImpulse(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_ApplyAngularImpulse : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        bool arg1;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Body_ApplyAngularImpulse : Error processing arguments");
        cobj->ApplyAngularImpulse(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_ApplyAngularImpulse : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2Body_GetPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Body* cobj = (b2Body *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Body_GetPosition : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetPosition();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Body_GetPosition : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_box2dclasses_b2Body(JSContext *cx, JS::HandleObject global) {
    jsb_b2Body_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2Body_class->name = "Body";
    jsb_b2Body_class->addProperty = JS_PropertyStub;
    jsb_b2Body_class->delProperty = JS_DeletePropertyStub;
    jsb_b2Body_class->getProperty = JS_PropertyStub;
    jsb_b2Body_class->setProperty = JS_StrictPropertyStub;
    jsb_b2Body_class->enumerate = JS_EnumerateStub;
    jsb_b2Body_class->resolve = JS_ResolveStub;
    jsb_b2Body_class->convert = JS_ConvertStub;
    jsb_b2Body_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetAngle", js_box2dclasses_b2Body_GetAngle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsSleepingAllowed", js_box2dclasses_b2Body_IsSleepingAllowed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAngularDamping", js_box2dclasses_b2Body_SetAngularDamping, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetActive", js_box2dclasses_b2Body_SetActive, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetGravityScale", js_box2dclasses_b2Body_SetGravityScale, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAngularVelocity", js_box2dclasses_b2Body_GetAngularVelocity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFixtureList", js_box2dclasses_b2Body_GetFixtureList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ApplyForce", js_box2dclasses_b2Body_ApplyForce, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalPoint", js_box2dclasses_b2Body_GetLocalPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetLinearVelocity", js_box2dclasses_b2Body_SetLinearVelocity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLinearVelocity", js_box2dclasses_b2Body_GetLinearVelocity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetNext", js_box2dclasses_b2Body_GetNext, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetSleepingAllowed", js_box2dclasses_b2Body_SetSleepingAllowed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTransform", js_box2dclasses_b2Body_SetTransform, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMass", js_box2dclasses_b2Body_GetMass, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAngularVelocity", js_box2dclasses_b2Body_SetAngularVelocity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMassData", js_box2dclasses_b2Body_GetMassData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLinearVelocityFromWorldPoint", js_box2dclasses_b2Body_GetLinearVelocityFromWorldPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ResetMassData", js_box2dclasses_b2Body_ResetMassData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ApplyForceToCenter", js_box2dclasses_b2Body_ApplyForceToCenter, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ApplyTorque", js_box2dclasses_b2Body_ApplyTorque, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsAwake", js_box2dclasses_b2Body_IsAwake, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetType", js_box2dclasses_b2Body_SetType, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMassData", js_box2dclasses_b2Body_SetMassData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetTransform", js_box2dclasses_b2Body_GetTransform, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWorldCenter", js_box2dclasses_b2Body_GetWorldCenter, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAngularDamping", js_box2dclasses_b2Body_GetAngularDamping, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ApplyLinearImpulse", js_box2dclasses_b2Body_ApplyLinearImpulse, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsFixedRotation", js_box2dclasses_b2Body_IsFixedRotation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalCenter", js_box2dclasses_b2Body_GetLocalCenter, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWorldVector", js_box2dclasses_b2Body_GetWorldVector, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLinearVelocityFromLocalPoint", js_box2dclasses_b2Body_GetLinearVelocityFromLocalPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetContactList", js_box2dclasses_b2Body_GetContactList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWorldPoint", js_box2dclasses_b2Body_GetWorldPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAwake", js_box2dclasses_b2Body_SetAwake, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLinearDamping", js_box2dclasses_b2Body_GetLinearDamping, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsBullet", js_box2dclasses_b2Body_IsBullet, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWorld", js_box2dclasses_b2Body_GetWorld, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalVector", js_box2dclasses_b2Body_GetLocalVector, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetLinearDamping", js_box2dclasses_b2Body_SetLinearDamping, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2Body_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetBullet", js_box2dclasses_b2Body_SetBullet, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetType", js_box2dclasses_b2Body_GetType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetGravityScale", js_box2dclasses_b2Body_GetGravityScale, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DestroyFixture", js_box2dclasses_b2Body_DestroyFixture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetInertia", js_box2dclasses_b2Body_GetInertia, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsActive", js_box2dclasses_b2Body_IsActive, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFixedRotation", js_box2dclasses_b2Body_SetFixedRotation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ApplyAngularImpulse", js_box2dclasses_b2Body_ApplyAngularImpulse, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetPosition", js_box2dclasses_b2Body_GetPosition, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2Body_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2Body_class,
        dummy_constructor<b2Body>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2Body_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2Body"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2Body>(cx, jsb_b2Body_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2Fixture_class;
JSObject *jsb_b2Fixture_prototype;

bool js_box2dclasses_b2Fixture_GetRestitution(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetRestitution : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetRestitution();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetRestitution : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Fixture_SetFilterData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_SetFilterData : Invalid Native Object");
    if (argc == 1) {
        b2Filter arg0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Filter
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_SetFilterData : Error processing arguments");
        cobj->SetFilterData(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_SetFilterData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_SetFriction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_SetFriction : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_SetFriction : Error processing arguments");
        cobj->SetFriction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_SetFriction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_GetShape(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Fixture* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Fixture *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetShape : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Shape* ret = cobj->GetShape();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Shape* ret = cobj->GetShape();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Shape>(cx, (b2Shape*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetShape : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Fixture_SetRestitution(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_SetRestitution : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_SetRestitution : Error processing arguments");
        cobj->SetRestitution(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_SetRestitution : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_GetBody(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Fixture* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Fixture *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetBody : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Body* ret = cobj->GetBody();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Body* ret = cobj->GetBody();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetBody : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Fixture_GetNext(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Fixture* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Fixture *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetNext : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Fixture* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Fixture* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetNext : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Fixture_GetFriction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetFriction : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetFriction();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetFriction : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Fixture_SetDensity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_SetDensity : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_SetDensity : Error processing arguments");
        cobj->SetDensity(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_SetDensity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_GetMassData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetMassData : Invalid Native Object");
    if (argc == 1) {
        b2MassData* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR b2MassData*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_GetMassData : Error processing arguments");
        cobj->GetMassData(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetMassData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_SetSensor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_SetSensor : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_SetSensor : Error processing arguments");
        cobj->SetSensor(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_SetSensor : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_GetAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetAABB : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_GetAABB : Error processing arguments");
        const b2AABB& ret = cobj->GetAABB(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2AABB_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetAABB : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_TestPoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_TestPoint : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_TestPoint : Error processing arguments");
        bool ret = cobj->TestPoint(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_TestPoint : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_RayCast : Invalid Native Object");
    if (argc == 3) {
        b2RayCastOutput* arg0 = nullptr;
        b2RayCastInput arg1;
        int arg2 = 0;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastOutput*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2RayCastInput
		ok = false;
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_RayCast : Error processing arguments");
        bool ret = cobj->RayCast(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_RayCast : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Fixture_Refilter(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_Refilter : Invalid Native Object");
    if (argc == 0) {
        cobj->Refilter();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_Refilter : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Fixture_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_Dump : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Fixture_Dump : Error processing arguments");
        cobj->Dump(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_Dump : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Fixture_GetFilterData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetFilterData : Invalid Native Object");
    if (argc == 0) {
        const b2Filter& ret = cobj->GetFilterData();
        JS::RootedValue jsret(cx);
        #pragma warning NO CONVERSION FROM NATIVE FOR b2Filter;
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetFilterData : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Fixture_IsSensor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_IsSensor : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsSensor();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_IsSensor : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Fixture_GetType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetType : Invalid Native Object");
    if (argc == 0) {
        int ret = (int)cobj->GetType();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetType : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Fixture_GetDensity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Fixture* cobj = (b2Fixture *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Fixture_GetDensity : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetDensity();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Fixture_GetDensity : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_box2dclasses_b2Fixture(JSContext *cx, JS::HandleObject global) {
    jsb_b2Fixture_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2Fixture_class->name = "Fixture";
    jsb_b2Fixture_class->addProperty = JS_PropertyStub;
    jsb_b2Fixture_class->delProperty = JS_DeletePropertyStub;
    jsb_b2Fixture_class->getProperty = JS_PropertyStub;
    jsb_b2Fixture_class->setProperty = JS_StrictPropertyStub;
    jsb_b2Fixture_class->enumerate = JS_EnumerateStub;
    jsb_b2Fixture_class->resolve = JS_ResolveStub;
    jsb_b2Fixture_class->convert = JS_ConvertStub;
    jsb_b2Fixture_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetRestitution", js_box2dclasses_b2Fixture_GetRestitution, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFilterData", js_box2dclasses_b2Fixture_SetFilterData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFriction", js_box2dclasses_b2Fixture_SetFriction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetShape", js_box2dclasses_b2Fixture_GetShape, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetRestitution", js_box2dclasses_b2Fixture_SetRestitution, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetBody", js_box2dclasses_b2Fixture_GetBody, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetNext", js_box2dclasses_b2Fixture_GetNext, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFriction", js_box2dclasses_b2Fixture_GetFriction, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetDensity", js_box2dclasses_b2Fixture_SetDensity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMassData", js_box2dclasses_b2Fixture_GetMassData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetSensor", js_box2dclasses_b2Fixture_SetSensor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAABB", js_box2dclasses_b2Fixture_GetAABB, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("TestPoint", js_box2dclasses_b2Fixture_TestPoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2Fixture_RayCast, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Refilter", js_box2dclasses_b2Fixture_Refilter, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2Fixture_Dump, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFilterData", js_box2dclasses_b2Fixture_GetFilterData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsSensor", js_box2dclasses_b2Fixture_IsSensor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetType", js_box2dclasses_b2Fixture_GetType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetDensity", js_box2dclasses_b2Fixture_GetDensity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2Fixture_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2Fixture_class,
        dummy_constructor<b2Fixture>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2Fixture_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2Fixture"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2Fixture>(cx, jsb_b2Fixture_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2ContactListener_class;
JSObject *jsb_b2ContactListener_prototype;

bool js_box2dclasses_b2ContactListener_EndContact(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ContactListener* cobj = (b2ContactListener *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ContactListener_EndContact : Invalid Native Object");
    if (argc == 1) {
        b2Contact* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Contact*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ContactListener_EndContact : Error processing arguments");
        cobj->EndContact(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ContactListener_EndContact : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2ContactListener_PreSolve(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ContactListener* cobj = (b2ContactListener *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ContactListener_PreSolve : Invalid Native Object");
    if (argc == 2) {
        b2Contact* arg0 = nullptr;
        const b2Manifold* arg1 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Contact*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        #pragma warning NO CONVERSION TO NATIVE FOR b2Manifold*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ContactListener_PreSolve : Error processing arguments");
        cobj->PreSolve(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ContactListener_PreSolve : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2ContactListener_BeginContact(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ContactListener* cobj = (b2ContactListener *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ContactListener_BeginContact : Invalid Native Object");
    if (argc == 1) {
        b2Contact* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Contact*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ContactListener_BeginContact : Error processing arguments");
        cobj->BeginContact(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ContactListener_BeginContact : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2ContactListener_PostSolve(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2ContactListener* cobj = (b2ContactListener *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2ContactListener_PostSolve : Invalid Native Object");
    if (argc == 2) {
        b2Contact* arg0 = nullptr;
        const b2ContactImpulse* arg1 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Contact*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        #pragma warning NO CONVERSION TO NATIVE FOR b2ContactImpulse*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2ContactListener_PostSolve : Error processing arguments");
        cobj->PostSolve(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2ContactListener_PostSolve : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}

void js_register_box2dclasses_b2ContactListener(JSContext *cx, JS::HandleObject global) {
    jsb_b2ContactListener_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2ContactListener_class->name = "b2ContactListener";
    jsb_b2ContactListener_class->addProperty = JS_PropertyStub;
    jsb_b2ContactListener_class->delProperty = JS_DeletePropertyStub;
    jsb_b2ContactListener_class->getProperty = JS_PropertyStub;
    jsb_b2ContactListener_class->setProperty = JS_StrictPropertyStub;
    jsb_b2ContactListener_class->enumerate = JS_EnumerateStub;
    jsb_b2ContactListener_class->resolve = JS_ResolveStub;
    jsb_b2ContactListener_class->convert = JS_ConvertStub;
    jsb_b2ContactListener_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("EndContact", js_box2dclasses_b2ContactListener_EndContact, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("PreSolve", js_box2dclasses_b2ContactListener_PreSolve, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("BeginContact", js_box2dclasses_b2ContactListener_BeginContact, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("PostSolve", js_box2dclasses_b2ContactListener_PostSolve, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2ContactListener_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2ContactListener_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2ContactListener_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2ContactListener"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2ContactListener>(cx, jsb_b2ContactListener_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2QueryCallback_class;
JSObject *jsb_b2QueryCallback_prototype;

bool js_box2dclasses_b2QueryCallback_ReportFixture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2QueryCallback* cobj = (b2QueryCallback *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2QueryCallback_ReportFixture : Invalid Native Object");
    if (argc == 1) {
        b2Fixture* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Fixture*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2QueryCallback_ReportFixture : Error processing arguments");
        bool ret = cobj->ReportFixture(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2QueryCallback_ReportFixture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

void js_register_box2dclasses_b2QueryCallback(JSContext *cx, JS::HandleObject global) {
    jsb_b2QueryCallback_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2QueryCallback_class->name = "b2QueryCallback";
    jsb_b2QueryCallback_class->addProperty = JS_PropertyStub;
    jsb_b2QueryCallback_class->delProperty = JS_DeletePropertyStub;
    jsb_b2QueryCallback_class->getProperty = JS_PropertyStub;
    jsb_b2QueryCallback_class->setProperty = JS_StrictPropertyStub;
    jsb_b2QueryCallback_class->enumerate = JS_EnumerateStub;
    jsb_b2QueryCallback_class->resolve = JS_ResolveStub;
    jsb_b2QueryCallback_class->convert = JS_ConvertStub;
    jsb_b2QueryCallback_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ReportFixture", js_box2dclasses_b2QueryCallback_ReportFixture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2QueryCallback_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2QueryCallback_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2QueryCallback_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2QueryCallback"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2QueryCallback>(cx, jsb_b2QueryCallback_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2RayCastCallback_class;
JSObject *jsb_b2RayCastCallback_prototype;

bool js_box2dclasses_b2RayCastCallback_ReportFixture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RayCastCallback* cobj = (b2RayCastCallback *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RayCastCallback_ReportFixture : Invalid Native Object");
    if (argc == 4) {
        b2Fixture* arg0 = nullptr;
        b2Vec2 arg1;
        b2Vec2 arg2;
        double arg3 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Fixture*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        ok &= jsval_to_b2Vec2(cx, args.get(2), &arg2);
        ok &= JS::ToNumber( cx, args.get(3), &arg3) && !std::isnan(arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RayCastCallback_ReportFixture : Error processing arguments");
        double ret = cobj->ReportFixture(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RayCastCallback_ReportFixture : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}

void js_register_box2dclasses_b2RayCastCallback(JSContext *cx, JS::HandleObject global) {
    jsb_b2RayCastCallback_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2RayCastCallback_class->name = "b2RayCastCallback";
    jsb_b2RayCastCallback_class->addProperty = JS_PropertyStub;
    jsb_b2RayCastCallback_class->delProperty = JS_DeletePropertyStub;
    jsb_b2RayCastCallback_class->getProperty = JS_PropertyStub;
    jsb_b2RayCastCallback_class->setProperty = JS_StrictPropertyStub;
    jsb_b2RayCastCallback_class->enumerate = JS_EnumerateStub;
    jsb_b2RayCastCallback_class->resolve = JS_ResolveStub;
    jsb_b2RayCastCallback_class->convert = JS_ConvertStub;
    jsb_b2RayCastCallback_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ReportFixture", js_box2dclasses_b2RayCastCallback_ReportFixture, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2RayCastCallback_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2RayCastCallback_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2RayCastCallback_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2RayCastCallback"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2RayCastCallback>(cx, jsb_b2RayCastCallback_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2World_class;
JSObject *jsb_b2World_prototype;

bool js_box2dclasses_b2World_ShiftOrigin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_ShiftOrigin : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_ShiftOrigin : Error processing arguments");
        cobj->ShiftOrigin(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_ShiftOrigin : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_QueryAABB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_QueryAABB : Invalid Native Object");
    if (argc == 2) {
        b2QueryCallback* arg0 = nullptr;
        b2AABB arg1;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2QueryCallback*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_b2AABB(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_QueryAABB : Error processing arguments");
        cobj->QueryAABB(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_QueryAABB : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2World_SetSubStepping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetSubStepping : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetSubStepping : Error processing arguments");
        cobj->SetSubStepping(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetSubStepping : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_GetTreeQuality(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetTreeQuality : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetTreeQuality();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetTreeQuality : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetTreeHeight(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetTreeHeight : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetTreeHeight();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetTreeHeight : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetProfile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetProfile : Invalid Native Object");
    if (argc == 0) {
        const b2Profile& ret = cobj->GetProfile();
        JS::RootedValue jsret(cx);
        #pragma warning NO CONVERSION FROM NATIVE FOR b2Profile;
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetProfile : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetTreeBalance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetTreeBalance : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetTreeBalance();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetTreeBalance : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetSubStepping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetSubStepping : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->GetSubStepping();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetSubStepping : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_SetContactListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetContactListener : Invalid Native Object");
    if (argc == 1) {
        b2ContactListener* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2ContactListener*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetContactListener : Error processing arguments");
        cobj->SetContactListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetContactListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_DrawDebugData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_DrawDebugData : Invalid Native Object");
    if (argc == 0) {
        cobj->DrawDebugData();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_DrawDebugData : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_SetContinuousPhysics(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetContinuousPhysics : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetContinuousPhysics : Error processing arguments");
        cobj->SetContinuousPhysics(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetContinuousPhysics : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_SetGravity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetGravity : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetGravity : Error processing arguments");
        cobj->SetGravity(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetGravity : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_GetBodyCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetBodyCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetBodyCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetBodyCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetAutoClearForces(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetAutoClearForces : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->GetAutoClearForces();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetAutoClearForces : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetContinuousPhysics(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetContinuousPhysics : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->GetContinuousPhysics();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetContinuousPhysics : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetJointList(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2World* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2World *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetJointList : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Joint* ret = cobj->GetJointList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Joint>(cx, (b2Joint*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Joint* ret = cobj->GetJointList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Joint>(cx, (b2Joint*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2World_GetJointList : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2World_GetBodyList(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2World* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2World *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetBodyList : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Body* ret = cobj->GetBodyList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Body* ret = cobj->GetBodyList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2World_GetBodyList : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2World_SetDestructionListener(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetDestructionListener : Invalid Native Object");
    if (argc == 1) {
        b2DestructionListener* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2DestructionListener*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetDestructionListener : Error processing arguments");
        cobj->SetDestructionListener(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetDestructionListener : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_DestroyJoint(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_DestroyJoint : Invalid Native Object");
    if (argc == 1) {
        b2Joint* arg0 = 0;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Joint*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_DestroyJoint : Error processing arguments");
        cobj->DestroyJoint(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_DestroyJoint : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_GetJointCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetJointCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetJointCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetJointCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_Step(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_Step : Invalid Native Object");
    if (argc == 3) {
        double arg0 = 0;
        int arg1 = 0;
        int arg2 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_Step : Error processing arguments");
        cobj->Step(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_Step : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2World_ClearForces(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_ClearForces : Invalid Native Object");
    if (argc == 0) {
        cobj->ClearForces();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_ClearForces : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetWarmStarting(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetWarmStarting : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->GetWarmStarting();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetWarmStarting : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_SetAllowSleeping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetAllowSleeping : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetAllowSleeping : Error processing arguments");
        cobj->SetAllowSleeping(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetAllowSleeping : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_DestroyBody(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_DestroyBody : Invalid Native Object");
    if (argc == 1) {
        b2Body* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Body*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_DestroyBody : Error processing arguments");
        cobj->DestroyBody(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_DestroyBody : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_GetAllowSleeping(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetAllowSleeping : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->GetAllowSleeping();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetAllowSleeping : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetProxyCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetProxyCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetProxyCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetProxyCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_RayCast(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_RayCast : Invalid Native Object");
    if (argc == 3) {
        b2RayCastCallback* arg0 = nullptr;
        b2Vec2 arg1;
        b2Vec2 arg2;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2RayCastCallback*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_b2Vec2(cx, args.get(1), &arg1);
        ok &= jsval_to_b2Vec2(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_RayCast : Error processing arguments");
        cobj->RayCast(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_RayCast : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2World_IsLocked(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_IsLocked : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsLocked();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_IsLocked : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetContactList(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2World* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2World *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetContactList : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Contact* ret = cobj->GetContactList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Contact>(cx, (b2Contact*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Contact* ret = cobj->GetContactList();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Contact>(cx, (b2Contact*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2World_GetContactList : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2World_SetDebugDraw(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetDebugDraw : Invalid Native Object");
    if (argc == 1) {
        b2Draw* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2Draw*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetDebugDraw : Error processing arguments");
        cobj->SetDebugDraw(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetDebugDraw : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_SetAutoClearForces(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetAutoClearForces : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetAutoClearForces : Error processing arguments");
        cobj->SetAutoClearForces(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetAutoClearForces : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_GetGravity(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetGravity : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetGravity();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetGravity : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_GetContactCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_GetContactCount : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetContactCount();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_GetContactCount : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2World_SetWarmStarting(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetWarmStarting : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetWarmStarting : Error processing arguments");
        cobj->SetWarmStarting(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetWarmStarting : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_SetContactFilter(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2World* cobj = (b2World *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2World_SetContactFilter : Invalid Native Object");
    if (argc == 1) {
        b2ContactFilter* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (b2ContactFilter*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_SetContactFilter : Error processing arguments");
        cobj->SetContactFilter(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2World_SetContactFilter : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2World_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    b2Vec2 arg0;
    ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2World_constructor : Error processing arguments");
    b2World* cobj = new (std::nothrow) b2World(arg0);

    js_type_class_t *typeClass = js_get_type_from_native<b2World>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "b2World"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_b2World_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (b2World)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        b2World *nobj = static_cast<b2World *>(jsproxy->ptr);
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        if (nobj) {
            jsb_remove_proxy(nproxy, jsproxy);
            JS::RootedValue flagValue(cx);
            JS_GetProperty(cx, jsobj, "__cppCreated", &flagValue);
            if (flagValue.isNullOrUndefined()){
                delete nobj;
            }
        }
        else
            jsb_remove_proxy(nullptr, jsproxy);
    }
}
void js_register_box2dclasses_b2World(JSContext *cx, JS::HandleObject global) {
    jsb_b2World_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2World_class->name = "World";
    jsb_b2World_class->addProperty = JS_PropertyStub;
    jsb_b2World_class->delProperty = JS_DeletePropertyStub;
    jsb_b2World_class->getProperty = JS_PropertyStub;
    jsb_b2World_class->setProperty = JS_StrictPropertyStub;
    jsb_b2World_class->enumerate = JS_EnumerateStub;
    jsb_b2World_class->resolve = JS_ResolveStub;
    jsb_b2World_class->convert = JS_ConvertStub;
    jsb_b2World_class->finalize = js_b2World_finalize;
    jsb_b2World_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("ShiftOrigin", js_box2dclasses_b2World_ShiftOrigin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("QueryAABB", js_box2dclasses_b2World_QueryAABB, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetSubStepping", js_box2dclasses_b2World_SetSubStepping, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetTreeQuality", js_box2dclasses_b2World_GetTreeQuality, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetTreeHeight", js_box2dclasses_b2World_GetTreeHeight, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetProfile", js_box2dclasses_b2World_GetProfile, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetTreeBalance", js_box2dclasses_b2World_GetTreeBalance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetSubStepping", js_box2dclasses_b2World_GetSubStepping, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetContactListener", js_box2dclasses_b2World_SetContactListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DrawDebugData", js_box2dclasses_b2World_DrawDebugData, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetContinuousPhysics", js_box2dclasses_b2World_SetContinuousPhysics, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetGravity", js_box2dclasses_b2World_SetGravity, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetBodyCount", js_box2dclasses_b2World_GetBodyCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAutoClearForces", js_box2dclasses_b2World_GetAutoClearForces, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetContinuousPhysics", js_box2dclasses_b2World_GetContinuousPhysics, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointList", js_box2dclasses_b2World_GetJointList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetBodyList", js_box2dclasses_b2World_GetBodyList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetDestructionListener", js_box2dclasses_b2World_SetDestructionListener, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DestroyJoint", js_box2dclasses_b2World_DestroyJoint, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointCount", js_box2dclasses_b2World_GetJointCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Step", js_box2dclasses_b2World_Step, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ClearForces", js_box2dclasses_b2World_ClearForces, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWarmStarting", js_box2dclasses_b2World_GetWarmStarting, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAllowSleeping", js_box2dclasses_b2World_SetAllowSleeping, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("DestroyBody", js_box2dclasses_b2World_DestroyBody, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAllowSleeping", js_box2dclasses_b2World_GetAllowSleeping, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetProxyCount", js_box2dclasses_b2World_GetProxyCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("RayCast", js_box2dclasses_b2World_RayCast, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsLocked", js_box2dclasses_b2World_IsLocked, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetContactList", js_box2dclasses_b2World_GetContactList, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetDebugDraw", js_box2dclasses_b2World_SetDebugDraw, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2World_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAutoClearForces", js_box2dclasses_b2World_SetAutoClearForces, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetGravity", js_box2dclasses_b2World_GetGravity, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetContactCount", js_box2dclasses_b2World_GetContactCount, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetWarmStarting", js_box2dclasses_b2World_SetWarmStarting, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetContactFilter", js_box2dclasses_b2World_SetContactFilter, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2World_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2World_class,
        js_box2dclasses_b2World_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2World_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2World"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2World>(cx, jsb_b2World_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2Contact_class;
JSObject *jsb_b2Contact_prototype;

bool js_box2dclasses_b2Contact_GetNext(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Contact* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Contact *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetNext : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Contact* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Contact>(cx, (b2Contact*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Contact* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Contact>(cx, (b2Contact*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetNext : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Contact_SetEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_SetEnabled : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Contact_SetEnabled : Error processing arguments");
        cobj->SetEnabled(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_SetEnabled : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Contact_GetWorldManifold(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetWorldManifold : Invalid Native Object");
    if (argc == 1) {
        b2WorldManifold* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR b2WorldManifold*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Contact_GetWorldManifold : Error processing arguments");
        cobj->GetWorldManifold(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetWorldManifold : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Contact_GetRestitution(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetRestitution : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetRestitution();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetRestitution : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_ResetFriction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_ResetFriction : Invalid Native Object");
    if (argc == 0) {
        cobj->ResetFriction();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_ResetFriction : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_GetFriction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetFriction : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetFriction();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetFriction : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_IsTouching(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_IsTouching : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsTouching();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_IsTouching : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_IsEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_IsEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsEnabled();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_IsEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_GetFixtureB(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Contact* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Contact *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetFixtureB : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Fixture* ret = cobj->GetFixtureB();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Fixture* ret = cobj->GetFixtureB();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetFixtureB : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Contact_SetFriction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_SetFriction : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Contact_SetFriction : Error processing arguments");
        cobj->SetFriction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_SetFriction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Contact_GetFixtureA(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Contact* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Contact *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetFixtureA : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Fixture* ret = cobj->GetFixtureA();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Fixture* ret = cobj->GetFixtureA();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Fixture>(cx, (b2Fixture*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetFixtureA : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Contact_GetChildIndexA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetChildIndexA : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildIndexA();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetChildIndexA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_GetChildIndexB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetChildIndexB : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->GetChildIndexB();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetChildIndexB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_SetTangentSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_SetTangentSpeed : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Contact_SetTangentSpeed : Error processing arguments");
        cobj->SetTangentSpeed(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_SetTangentSpeed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Contact_GetTangentSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetTangentSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetTangentSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetTangentSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Contact_SetRestitution(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_SetRestitution : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Contact_SetRestitution : Error processing arguments");
        cobj->SetRestitution(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_SetRestitution : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Contact_GetManifold(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Contact* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Contact *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_GetManifold : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Manifold* ret = cobj->GetManifold();
            jsval jsret = JSVAL_NULL;
            jsret = b2Manifold_to_jsval(cx, ret);
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Manifold* ret = cobj->GetManifold();
            jsval jsret = JSVAL_NULL;
            jsret = b2Manifold_to_jsval(cx, ret);
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Contact_GetManifold : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Contact_Evaluate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_Evaluate : Invalid Native Object");
    if (argc == 3) {
        b2Manifold* arg0 = nullptr;
        b2Transform arg1;
        b2Transform arg2;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Manifold*
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        #pragma warning NO CONVERSION TO NATIVE FOR b2Transform
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Contact_Evaluate : Error processing arguments");
        cobj->Evaluate(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_Evaluate : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_box2dclasses_b2Contact_ResetRestitution(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Contact* cobj = (b2Contact *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Contact_ResetRestitution : Invalid Native Object");
    if (argc == 0) {
        cobj->ResetRestitution();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Contact_ResetRestitution : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_box2dclasses_b2Contact(JSContext *cx, JS::HandleObject global) {
    jsb_b2Contact_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2Contact_class->name = "Contact";
    jsb_b2Contact_class->addProperty = JS_PropertyStub;
    jsb_b2Contact_class->delProperty = JS_DeletePropertyStub;
    jsb_b2Contact_class->getProperty = JS_PropertyStub;
    jsb_b2Contact_class->setProperty = JS_StrictPropertyStub;
    jsb_b2Contact_class->enumerate = JS_EnumerateStub;
    jsb_b2Contact_class->resolve = JS_ResolveStub;
    jsb_b2Contact_class->convert = JS_ConvertStub;
    jsb_b2Contact_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetNext", js_box2dclasses_b2Contact_GetNext, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetEnabled", js_box2dclasses_b2Contact_SetEnabled, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetWorldManifold", js_box2dclasses_b2Contact_GetWorldManifold, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetRestitution", js_box2dclasses_b2Contact_GetRestitution, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ResetFriction", js_box2dclasses_b2Contact_ResetFriction, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFriction", js_box2dclasses_b2Contact_GetFriction, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsTouching", js_box2dclasses_b2Contact_IsTouching, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsEnabled", js_box2dclasses_b2Contact_IsEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFixtureB", js_box2dclasses_b2Contact_GetFixtureB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFriction", js_box2dclasses_b2Contact_SetFriction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFixtureA", js_box2dclasses_b2Contact_GetFixtureA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildIndexA", js_box2dclasses_b2Contact_GetChildIndexA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetChildIndexB", js_box2dclasses_b2Contact_GetChildIndexB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTangentSpeed", js_box2dclasses_b2Contact_SetTangentSpeed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetTangentSpeed", js_box2dclasses_b2Contact_GetTangentSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetRestitution", js_box2dclasses_b2Contact_SetRestitution, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetManifold", js_box2dclasses_b2Contact_GetManifold, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Evaluate", js_box2dclasses_b2Contact_Evaluate, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ResetRestitution", js_box2dclasses_b2Contact_ResetRestitution, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2Contact_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2Contact_class,
        dummy_constructor<b2Contact>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2Contact_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2Contact"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2Contact>(cx, jsb_b2Contact_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2Joint_class;
JSObject *jsb_b2Joint_prototype;

bool js_box2dclasses_b2Joint_GetNext(JSContext *cx, uint32_t argc, jsval *vp)
{
    b2Joint* cobj = nullptr;

    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx);
    obj.set(args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (b2Joint *)(proxy ? proxy->ptr : nullptr);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetNext : Invalid Native Object");
    do {
        if (argc == 0) {
            const b2Joint* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Joint>(cx, (b2Joint*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    do {
        if (argc == 0) {
            b2Joint* ret = cobj->GetNext();
            jsval jsret = JSVAL_NULL;
            if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Joint>(cx, (b2Joint*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
            args.rval().set(jsret);
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetNext : wrong number of arguments");
    return false;
}
bool js_box2dclasses_b2Joint_GetBodyA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetBodyA : Invalid Native Object");
    if (argc == 0) {
        b2Body* ret = cobj->GetBodyA();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetBodyA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_GetBodyB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetBodyB : Invalid Native Object");
    if (argc == 0) {
        b2Body* ret = cobj->GetBodyB();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Body>(cx, (b2Body*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetBodyB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Joint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Joint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_ShiftOrigin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_ShiftOrigin : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Joint_ShiftOrigin : Error processing arguments");
        cobj->ShiftOrigin(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_ShiftOrigin : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Joint_GetType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetType : Invalid Native Object");
    if (argc == 0) {
        int ret = (int)cobj->GetType();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetType : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_GetCollideConnected(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetCollideConnected : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->GetCollideConnected();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetCollideConnected : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2Joint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2Joint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2Joint_IsActive(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2Joint* cobj = (b2Joint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2Joint_IsActive : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsActive();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2Joint_IsActive : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

void js_register_box2dclasses_b2Joint(JSContext *cx, JS::HandleObject global) {
    jsb_b2Joint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2Joint_class->name = "Joint";
    jsb_b2Joint_class->addProperty = JS_PropertyStub;
    jsb_b2Joint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2Joint_class->getProperty = JS_PropertyStub;
    jsb_b2Joint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2Joint_class->enumerate = JS_EnumerateStub;
    jsb_b2Joint_class->resolve = JS_ResolveStub;
    jsb_b2Joint_class->convert = JS_ConvertStub;
    jsb_b2Joint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetNext", js_box2dclasses_b2Joint_GetNext, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetBodyA", js_box2dclasses_b2Joint_GetBodyA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetBodyB", js_box2dclasses_b2Joint_GetBodyB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2Joint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2Joint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ShiftOrigin", js_box2dclasses_b2Joint_ShiftOrigin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetType", js_box2dclasses_b2Joint_GetType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetCollideConnected", js_box2dclasses_b2Joint_GetCollideConnected, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2Joint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2Joint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2Joint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsActive", js_box2dclasses_b2Joint_IsActive, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_b2Joint_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_b2Joint_class,
        dummy_constructor<b2Joint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2Joint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2Joint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2Joint>(cx, jsb_b2Joint_class, proto, JS::NullPtr());
}

JSClass  *jsb_b2DistanceJoint_class;
JSObject *jsb_b2DistanceJoint_prototype;

bool js_box2dclasses_b2DistanceJoint_SetDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_SetDampingRatio : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2DistanceJoint_SetDampingRatio : Error processing arguments");
        cobj->SetDampingRatio(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_SetDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2DistanceJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_SetFrequency(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_SetFrequency : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2DistanceJoint_SetFrequency : Error processing arguments");
        cobj->SetFrequency(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_SetFrequency : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetLength(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetLength : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetLength();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetLength : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetDampingRatio : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetDampingRatio();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetFrequency(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetFrequency : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetFrequency();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetFrequency : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2DistanceJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2DistanceJoint_SetLength(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2DistanceJoint* cobj = (b2DistanceJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2DistanceJoint_SetLength : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2DistanceJoint_SetLength : Error processing arguments");
        cobj->SetLength(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2DistanceJoint_SetLength : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2DistanceJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2DistanceJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2DistanceJoint_class->name = "b2DistanceJoint";
    jsb_b2DistanceJoint_class->addProperty = JS_PropertyStub;
    jsb_b2DistanceJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2DistanceJoint_class->getProperty = JS_PropertyStub;
    jsb_b2DistanceJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2DistanceJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2DistanceJoint_class->resolve = JS_ResolveStub;
    jsb_b2DistanceJoint_class->convert = JS_ConvertStub;
    jsb_b2DistanceJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SetDampingRatio", js_box2dclasses_b2DistanceJoint_SetDampingRatio, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2DistanceJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2DistanceJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2DistanceJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFrequency", js_box2dclasses_b2DistanceJoint_SetFrequency, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLength", js_box2dclasses_b2DistanceJoint_GetLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetDampingRatio", js_box2dclasses_b2DistanceJoint_GetDampingRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFrequency", js_box2dclasses_b2DistanceJoint_GetFrequency, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2DistanceJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2DistanceJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2DistanceJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2DistanceJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetLength", js_box2dclasses_b2DistanceJoint_SetLength, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2DistanceJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2DistanceJoint_class,
        dummy_constructor<b2DistanceJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2DistanceJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2DistanceJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2DistanceJoint>(cx, jsb_b2DistanceJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2FrictionJoint_class;
JSObject *jsb_b2FrictionJoint_prototype;

bool js_box2dclasses_b2FrictionJoint_SetMaxTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_SetMaxTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2FrictionJoint_SetMaxTorque : Error processing arguments");
        cobj->SetMaxTorque(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_SetMaxTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetMaxForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetMaxForce : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxForce();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetMaxForce : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2FrictionJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_SetMaxForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_SetMaxForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2FrictionJoint_SetMaxForce : Error processing arguments");
        cobj->SetMaxForce(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_SetMaxForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2FrictionJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2FrictionJoint_GetMaxTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2FrictionJoint* cobj = (b2FrictionJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2FrictionJoint_GetMaxTorque : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxTorque();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2FrictionJoint_GetMaxTorque : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2FrictionJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2FrictionJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2FrictionJoint_class->name = "b2FrictionJoint";
    jsb_b2FrictionJoint_class->addProperty = JS_PropertyStub;
    jsb_b2FrictionJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2FrictionJoint_class->getProperty = JS_PropertyStub;
    jsb_b2FrictionJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2FrictionJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2FrictionJoint_class->resolve = JS_ResolveStub;
    jsb_b2FrictionJoint_class->convert = JS_ConvertStub;
    jsb_b2FrictionJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SetMaxTorque", js_box2dclasses_b2FrictionJoint_SetMaxTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxForce", js_box2dclasses_b2FrictionJoint_GetMaxForce, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2FrictionJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2FrictionJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2FrictionJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxForce", js_box2dclasses_b2FrictionJoint_SetMaxForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2FrictionJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2FrictionJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2FrictionJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2FrictionJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxTorque", js_box2dclasses_b2FrictionJoint_GetMaxTorque, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2FrictionJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2FrictionJoint_class,
        dummy_constructor<b2FrictionJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2FrictionJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2FrictionJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2FrictionJoint>(cx, jsb_b2FrictionJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2GearJoint_class;
JSObject *jsb_b2GearJoint_prototype;

bool js_box2dclasses_b2GearJoint_GetJoint1(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetJoint1 : Invalid Native Object");
    if (argc == 0) {
        b2Joint* ret = cobj->GetJoint1();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Joint>(cx, (b2Joint*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetJoint1 : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2GearJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2GearJoint_GetJoint2(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetJoint2 : Invalid Native Object");
    if (argc == 0) {
        b2Joint* ret = cobj->GetJoint2();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<b2Joint>(cx, (b2Joint*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetJoint2 : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2GearJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2GearJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2GearJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2GearJoint_SetRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_SetRatio : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2GearJoint_SetRatio : Error processing arguments");
        cobj->SetRatio(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_SetRatio : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2GearJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2GearJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2GearJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2GearJoint_GetRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2GearJoint* cobj = (b2GearJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2GearJoint_GetRatio : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetRatio();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2GearJoint_GetRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2GearJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2GearJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2GearJoint_class->name = "b2GearJoint";
    jsb_b2GearJoint_class->addProperty = JS_PropertyStub;
    jsb_b2GearJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2GearJoint_class->getProperty = JS_PropertyStub;
    jsb_b2GearJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2GearJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2GearJoint_class->resolve = JS_ResolveStub;
    jsb_b2GearJoint_class->convert = JS_ConvertStub;
    jsb_b2GearJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetJoint1", js_box2dclasses_b2GearJoint_GetJoint1, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2GearJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJoint2", js_box2dclasses_b2GearJoint_GetJoint2, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2GearJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2GearJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetRatio", js_box2dclasses_b2GearJoint_SetRatio, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2GearJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2GearJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetRatio", js_box2dclasses_b2GearJoint_GetRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2GearJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2GearJoint_class,
        dummy_constructor<b2GearJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2GearJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2GearJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2GearJoint>(cx, jsb_b2GearJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2MotorJoint_class;
JSObject *jsb_b2MotorJoint_prototype;

bool js_box2dclasses_b2MotorJoint_SetMaxTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_SetMaxTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_SetMaxTorque : Error processing arguments");
        cobj->SetMaxTorque(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_SetMaxTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetCorrectionFactor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetCorrectionFactor : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetCorrectionFactor();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetCorrectionFactor : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_SetMaxForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_SetMaxForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_SetMaxForce : Error processing arguments");
        cobj->SetMaxForce(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_SetMaxForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MotorJoint_SetLinearOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_SetLinearOffset : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_SetLinearOffset : Error processing arguments");
        cobj->SetLinearOffset(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_SetLinearOffset : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetMaxForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetMaxForce : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxForce();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetMaxForce : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_SetAngularOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_SetAngularOffset : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_SetAngularOffset : Error processing arguments");
        cobj->SetAngularOffset(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_SetAngularOffset : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetAngularOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetAngularOffset : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetAngularOffset();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetAngularOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetLinearOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetLinearOffset : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLinearOffset();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetLinearOffset : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_GetMaxTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_GetMaxTorque : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxTorque();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_GetMaxTorque : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MotorJoint_SetCorrectionFactor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MotorJoint* cobj = (b2MotorJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MotorJoint_SetCorrectionFactor : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MotorJoint_SetCorrectionFactor : Error processing arguments");
        cobj->SetCorrectionFactor(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MotorJoint_SetCorrectionFactor : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2MotorJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2MotorJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2MotorJoint_class->name = "b2MotorJoint";
    jsb_b2MotorJoint_class->addProperty = JS_PropertyStub;
    jsb_b2MotorJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2MotorJoint_class->getProperty = JS_PropertyStub;
    jsb_b2MotorJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2MotorJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2MotorJoint_class->resolve = JS_ResolveStub;
    jsb_b2MotorJoint_class->convert = JS_ConvertStub;
    jsb_b2MotorJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SetMaxTorque", js_box2dclasses_b2MotorJoint_SetMaxTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2MotorJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2MotorJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetCorrectionFactor", js_box2dclasses_b2MotorJoint_GetCorrectionFactor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxForce", js_box2dclasses_b2MotorJoint_SetMaxForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetLinearOffset", js_box2dclasses_b2MotorJoint_SetLinearOffset, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxForce", js_box2dclasses_b2MotorJoint_GetMaxForce, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2MotorJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetAngularOffset", js_box2dclasses_b2MotorJoint_SetAngularOffset, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2MotorJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2MotorJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAngularOffset", js_box2dclasses_b2MotorJoint_GetAngularOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLinearOffset", js_box2dclasses_b2MotorJoint_GetLinearOffset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxTorque", js_box2dclasses_b2MotorJoint_GetMaxTorque, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetCorrectionFactor", js_box2dclasses_b2MotorJoint_SetCorrectionFactor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2MotorJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2MotorJoint_class,
        dummy_constructor<b2MotorJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2MotorJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2MotorJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2MotorJoint>(cx, jsb_b2MotorJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2MouseJoint_class;
JSObject *jsb_b2MouseJoint_prototype;

bool js_box2dclasses_b2MouseJoint_SetDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_SetDampingRatio : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_SetDampingRatio : Error processing arguments");
        cobj->SetDampingRatio(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_SetDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MouseJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_SetFrequency(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_SetFrequency : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_SetFrequency : Error processing arguments");
        cobj->SetFrequency(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_SetFrequency : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetDampingRatio : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetDampingRatio();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_SetTarget(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_SetTarget : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_SetTarget : Error processing arguments");
        cobj->SetTarget(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_SetTarget : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MouseJoint_SetMaxForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_SetMaxForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_SetMaxForce : Error processing arguments");
        cobj->SetMaxForce(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_SetMaxForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetFrequency(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetFrequency : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetFrequency();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetFrequency : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetTarget(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetTarget : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetTarget();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetTarget : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetMaxForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetMaxForce : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxForce();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetMaxForce : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2MouseJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2MouseJoint_ShiftOrigin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2MouseJoint* cobj = (b2MouseJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2MouseJoint_ShiftOrigin : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2MouseJoint_ShiftOrigin : Error processing arguments");
        cobj->ShiftOrigin(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2MouseJoint_ShiftOrigin : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2MouseJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2MouseJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2MouseJoint_class->name = "b2MouseJoint";
    jsb_b2MouseJoint_class->addProperty = JS_PropertyStub;
    jsb_b2MouseJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2MouseJoint_class->getProperty = JS_PropertyStub;
    jsb_b2MouseJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2MouseJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2MouseJoint_class->resolve = JS_ResolveStub;
    jsb_b2MouseJoint_class->convert = JS_ConvertStub;
    jsb_b2MouseJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SetDampingRatio", js_box2dclasses_b2MouseJoint_SetDampingRatio, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2MouseJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2MouseJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2MouseJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFrequency", js_box2dclasses_b2MouseJoint_SetFrequency, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetDampingRatio", js_box2dclasses_b2MouseJoint_GetDampingRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetTarget", js_box2dclasses_b2MouseJoint_SetTarget, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxForce", js_box2dclasses_b2MouseJoint_SetMaxForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFrequency", js_box2dclasses_b2MouseJoint_GetFrequency, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetTarget", js_box2dclasses_b2MouseJoint_GetTarget, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxForce", js_box2dclasses_b2MouseJoint_GetMaxForce, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2MouseJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2MouseJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ShiftOrigin", js_box2dclasses_b2MouseJoint_ShiftOrigin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2MouseJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2MouseJoint_class,
        dummy_constructor<b2MouseJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2MouseJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2MouseJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2MouseJoint>(cx, jsb_b2MouseJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2PrismaticJoint_class;
JSObject *jsb_b2PrismaticJoint_prototype;

bool js_box2dclasses_b2PrismaticJoint_GetLocalAxisA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetLocalAxisA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAxisA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetLocalAxisA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetLowerLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetLowerLimit : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetLowerLimit();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetLowerLimit : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_SetMotorSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_SetMotorSpeed : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_SetMotorSpeed : Error processing arguments");
        cobj->SetMotorSpeed(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_SetMotorSpeed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetMotorSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetMotorSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMotorSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetMotorSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_SetMaxMotorForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_SetMaxMotorForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_SetMaxMotorForce : Error processing arguments");
        cobj->SetMaxMotorForce(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_SetMaxMotorForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_EnableLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_EnableLimit : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_EnableLimit : Error processing arguments");
        cobj->EnableLimit(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_EnableLimit : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_IsMotorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_IsMotorEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsMotorEnabled();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_IsMotorEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetMaxMotorForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetMaxMotorForce : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxMotorForce();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetMaxMotorForce : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetJointSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetJointSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetJointSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetJointSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_EnableMotor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_EnableMotor : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_EnableMotor : Error processing arguments");
        cobj->EnableMotor(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_EnableMotor : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetReferenceAngle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetReferenceAngle : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetReferenceAngle();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetReferenceAngle : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetMotorForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetMotorForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_GetMotorForce : Error processing arguments");
        double ret = cobj->GetMotorForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetMotorForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetJointTranslation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetJointTranslation : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetJointTranslation();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetJointTranslation : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_IsLimitEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_IsLimitEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsLimitEnabled();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_IsLimitEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_SetLimits(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_SetLimits : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PrismaticJoint_SetLimits : Error processing arguments");
        cobj->SetLimits(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_SetLimits : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetUpperLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetUpperLimit : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetUpperLimit();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetUpperLimit : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PrismaticJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PrismaticJoint* cobj = (b2PrismaticJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PrismaticJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PrismaticJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2PrismaticJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2PrismaticJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2PrismaticJoint_class->name = "b2PrismaticJoint";
    jsb_b2PrismaticJoint_class->addProperty = JS_PropertyStub;
    jsb_b2PrismaticJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2PrismaticJoint_class->getProperty = JS_PropertyStub;
    jsb_b2PrismaticJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2PrismaticJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2PrismaticJoint_class->resolve = JS_ResolveStub;
    jsb_b2PrismaticJoint_class->convert = JS_ConvertStub;
    jsb_b2PrismaticJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetLocalAxisA", js_box2dclasses_b2PrismaticJoint_GetLocalAxisA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLowerLimit", js_box2dclasses_b2PrismaticJoint_GetLowerLimit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2PrismaticJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2PrismaticJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMotorSpeed", js_box2dclasses_b2PrismaticJoint_SetMotorSpeed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2PrismaticJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMotorSpeed", js_box2dclasses_b2PrismaticJoint_GetMotorSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxMotorForce", js_box2dclasses_b2PrismaticJoint_SetMaxMotorForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("EnableLimit", js_box2dclasses_b2PrismaticJoint_EnableLimit, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsMotorEnabled", js_box2dclasses_b2PrismaticJoint_IsMotorEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2PrismaticJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxMotorForce", js_box2dclasses_b2PrismaticJoint_GetMaxMotorForce, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointSpeed", js_box2dclasses_b2PrismaticJoint_GetJointSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("EnableMotor", js_box2dclasses_b2PrismaticJoint_EnableMotor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReferenceAngle", js_box2dclasses_b2PrismaticJoint_GetReferenceAngle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2PrismaticJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMotorForce", js_box2dclasses_b2PrismaticJoint_GetMotorForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointTranslation", js_box2dclasses_b2PrismaticJoint_GetJointTranslation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsLimitEnabled", js_box2dclasses_b2PrismaticJoint_IsLimitEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2PrismaticJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetLimits", js_box2dclasses_b2PrismaticJoint_SetLimits, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetUpperLimit", js_box2dclasses_b2PrismaticJoint_GetUpperLimit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2PrismaticJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2PrismaticJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2PrismaticJoint_class,
        dummy_constructor<b2PrismaticJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2PrismaticJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2PrismaticJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2PrismaticJoint>(cx, jsb_b2PrismaticJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2PulleyJoint_class;
JSObject *jsb_b2PulleyJoint_prototype;

bool js_box2dclasses_b2PulleyJoint_GetCurrentLengthA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetCurrentLengthA : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetCurrentLengthA();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetCurrentLengthA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetGroundAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetGroundAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetGroundAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetGroundAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PulleyJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetGroundAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetGroundAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetGroundAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetGroundAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetLengthB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetLengthB : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetLengthB();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetLengthB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetLengthA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetLengthA : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetLengthA();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetLengthA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetCurrentLengthB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetCurrentLengthB : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetCurrentLengthB();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetCurrentLengthB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PulleyJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_ShiftOrigin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_ShiftOrigin : Invalid Native Object");
    if (argc == 1) {
        b2Vec2 arg0;
        ok &= jsval_to_b2Vec2(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2PulleyJoint_ShiftOrigin : Error processing arguments");
        cobj->ShiftOrigin(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_ShiftOrigin : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2PulleyJoint_GetRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2PulleyJoint* cobj = (b2PulleyJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2PulleyJoint_GetRatio : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetRatio();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2PulleyJoint_GetRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2PulleyJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2PulleyJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2PulleyJoint_class->name = "b2PulleyJoint";
    jsb_b2PulleyJoint_class->addProperty = JS_PropertyStub;
    jsb_b2PulleyJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2PulleyJoint_class->getProperty = JS_PropertyStub;
    jsb_b2PulleyJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2PulleyJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2PulleyJoint_class->resolve = JS_ResolveStub;
    jsb_b2PulleyJoint_class->convert = JS_ConvertStub;
    jsb_b2PulleyJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetCurrentLengthA", js_box2dclasses_b2PulleyJoint_GetCurrentLengthA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2PulleyJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetGroundAnchorB", js_box2dclasses_b2PulleyJoint_GetGroundAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2PulleyJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2PulleyJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetGroundAnchorA", js_box2dclasses_b2PulleyJoint_GetGroundAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLengthB", js_box2dclasses_b2PulleyJoint_GetLengthB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLengthA", js_box2dclasses_b2PulleyJoint_GetLengthA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetCurrentLengthB", js_box2dclasses_b2PulleyJoint_GetCurrentLengthB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2PulleyJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2PulleyJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("ShiftOrigin", js_box2dclasses_b2PulleyJoint_ShiftOrigin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetRatio", js_box2dclasses_b2PulleyJoint_GetRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2PulleyJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2PulleyJoint_class,
        dummy_constructor<b2PulleyJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2PulleyJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2PulleyJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2PulleyJoint>(cx, jsb_b2PulleyJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2RevoluteJoint_class;
JSObject *jsb_b2RevoluteJoint_prototype;

bool js_box2dclasses_b2RevoluteJoint_GetLowerLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetLowerLimit : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetLowerLimit();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetLowerLimit : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_SetMotorSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_SetMotorSpeed : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_SetMotorSpeed : Error processing arguments");
        cobj->SetMotorSpeed(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_SetMotorSpeed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetJointAngle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetJointAngle : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetJointAngle();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetJointAngle : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetMotorSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetMotorSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMotorSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetMotorSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetMotorTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetMotorTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_GetMotorTorque : Error processing arguments");
        double ret = cobj->GetMotorTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetMotorTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_IsLimitEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_IsLimitEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsLimitEnabled();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_IsLimitEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_EnableLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_EnableLimit : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_EnableLimit : Error processing arguments");
        cobj->EnableLimit(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_EnableLimit : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_IsMotorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_IsMotorEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsMotorEnabled();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_IsMotorEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_SetMaxMotorTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_SetMaxMotorTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_SetMaxMotorTorque : Error processing arguments");
        cobj->SetMaxMotorTorque(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_SetMaxMotorTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetJointSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetJointSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetJointSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetJointSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_EnableMotor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_EnableMotor : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_EnableMotor : Error processing arguments");
        cobj->EnableMotor(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_EnableMotor : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetReferenceAngle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetReferenceAngle : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetReferenceAngle();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetReferenceAngle : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_SetLimits(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_SetLimits : Invalid Native Object");
    if (argc == 2) {
        double arg0 = 0;
        double arg1 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_SetLimits : Error processing arguments");
        cobj->SetLimits(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_SetLimits : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetMaxMotorTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetMaxMotorTorque : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxMotorTorque();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetMaxMotorTorque : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RevoluteJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetUpperLimit(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetUpperLimit : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetUpperLimit();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetUpperLimit : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RevoluteJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RevoluteJoint* cobj = (b2RevoluteJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RevoluteJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RevoluteJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2RevoluteJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2RevoluteJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2RevoluteJoint_class->name = "b2RevoluteJoint";
    jsb_b2RevoluteJoint_class->addProperty = JS_PropertyStub;
    jsb_b2RevoluteJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2RevoluteJoint_class->getProperty = JS_PropertyStub;
    jsb_b2RevoluteJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2RevoluteJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2RevoluteJoint_class->resolve = JS_ResolveStub;
    jsb_b2RevoluteJoint_class->convert = JS_ConvertStub;
    jsb_b2RevoluteJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetLowerLimit", js_box2dclasses_b2RevoluteJoint_GetLowerLimit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2RevoluteJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2RevoluteJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMotorSpeed", js_box2dclasses_b2RevoluteJoint_SetMotorSpeed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2RevoluteJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointAngle", js_box2dclasses_b2RevoluteJoint_GetJointAngle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMotorSpeed", js_box2dclasses_b2RevoluteJoint_GetMotorSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMotorTorque", js_box2dclasses_b2RevoluteJoint_GetMotorTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsLimitEnabled", js_box2dclasses_b2RevoluteJoint_IsLimitEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("EnableLimit", js_box2dclasses_b2RevoluteJoint_EnableLimit, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("IsMotorEnabled", js_box2dclasses_b2RevoluteJoint_IsMotorEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2RevoluteJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxMotorTorque", js_box2dclasses_b2RevoluteJoint_SetMaxMotorTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointSpeed", js_box2dclasses_b2RevoluteJoint_GetJointSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("EnableMotor", js_box2dclasses_b2RevoluteJoint_EnableMotor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReferenceAngle", js_box2dclasses_b2RevoluteJoint_GetReferenceAngle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2RevoluteJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetLimits", js_box2dclasses_b2RevoluteJoint_SetLimits, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxMotorTorque", js_box2dclasses_b2RevoluteJoint_GetMaxMotorTorque, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2RevoluteJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetUpperLimit", js_box2dclasses_b2RevoluteJoint_GetUpperLimit, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2RevoluteJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2RevoluteJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2RevoluteJoint_class,
        dummy_constructor<b2RevoluteJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2RevoluteJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2RevoluteJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2RevoluteJoint>(cx, jsb_b2RevoluteJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2RopeJoint_class;
JSObject *jsb_b2RopeJoint_prototype;

bool js_box2dclasses_b2RopeJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RopeJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetMaxLength : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxLength();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetMaxLength : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RopeJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RopeJoint_SetMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_SetMaxLength : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RopeJoint_SetMaxLength : Error processing arguments");
        cobj->SetMaxLength(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_SetMaxLength : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2RopeJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2RopeJoint_GetLimitState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2RopeJoint* cobj = (b2RopeJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2RopeJoint_GetLimitState : Invalid Native Object");
    if (argc == 0) {
        int ret = (int)cobj->GetLimitState();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2RopeJoint_GetLimitState : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2RopeJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2RopeJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2RopeJoint_class->name = "b2RopeJoint";
    jsb_b2RopeJoint_class->addProperty = JS_PropertyStub;
    jsb_b2RopeJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2RopeJoint_class->getProperty = JS_PropertyStub;
    jsb_b2RopeJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2RopeJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2RopeJoint_class->resolve = JS_ResolveStub;
    jsb_b2RopeJoint_class->convert = JS_ConvertStub;
    jsb_b2RopeJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("GetAnchorA", js_box2dclasses_b2RopeJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2RopeJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxLength", js_box2dclasses_b2RopeJoint_GetMaxLength, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2RopeJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2RopeJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxLength", js_box2dclasses_b2RopeJoint_SetMaxLength, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2RopeJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2RopeJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2RopeJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLimitState", js_box2dclasses_b2RopeJoint_GetLimitState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2RopeJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2RopeJoint_class,
        dummy_constructor<b2RopeJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2RopeJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2RopeJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2RopeJoint>(cx, jsb_b2RopeJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2WeldJoint_class;
JSObject *jsb_b2WeldJoint_prototype;

bool js_box2dclasses_b2WeldJoint_SetDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_SetDampingRatio : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WeldJoint_SetDampingRatio : Error processing arguments");
        cobj->SetDampingRatio(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_SetDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WeldJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WeldJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_SetFrequency(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_SetFrequency : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WeldJoint_SetFrequency : Error processing arguments");
        cobj->SetFrequency(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_SetFrequency : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetDampingRatio : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetDampingRatio();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetFrequency(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetFrequency : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetFrequency();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetFrequency : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WeldJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WeldJoint_GetReferenceAngle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WeldJoint* cobj = (b2WeldJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WeldJoint_GetReferenceAngle : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetReferenceAngle();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WeldJoint_GetReferenceAngle : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2WeldJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2WeldJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2WeldJoint_class->name = "b2WeldJoint";
    jsb_b2WeldJoint_class->addProperty = JS_PropertyStub;
    jsb_b2WeldJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2WeldJoint_class->getProperty = JS_PropertyStub;
    jsb_b2WeldJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2WeldJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2WeldJoint_class->resolve = JS_ResolveStub;
    jsb_b2WeldJoint_class->convert = JS_ConvertStub;
    jsb_b2WeldJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("SetDampingRatio", js_box2dclasses_b2WeldJoint_SetDampingRatio, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2WeldJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2WeldJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2WeldJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetFrequency", js_box2dclasses_b2WeldJoint_SetFrequency, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetDampingRatio", js_box2dclasses_b2WeldJoint_GetDampingRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetFrequency", js_box2dclasses_b2WeldJoint_GetFrequency, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2WeldJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2WeldJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2WeldJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2WeldJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReferenceAngle", js_box2dclasses_b2WeldJoint_GetReferenceAngle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2WeldJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2WeldJoint_class,
        dummy_constructor<b2WeldJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2WeldJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2WeldJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2WeldJoint>(cx, jsb_b2WeldJoint_class, proto, parent_proto);
}

JSClass  *jsb_b2WheelJoint_class;
JSObject *jsb_b2WheelJoint_prototype;

bool js_box2dclasses_b2WheelJoint_IsMotorEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_IsMotorEnabled : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->IsMotorEnabled();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_IsMotorEnabled : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetMotorSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetMotorSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMotorSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetMotorSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetAnchorA : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetReactionTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetReactionTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_GetReactionTorque : Error processing arguments");
        double ret = cobj->GetReactionTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetReactionTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_Dump(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_Dump : Invalid Native Object");
    if (argc == 0) {
        cobj->Dump();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_Dump : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_SetSpringDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_SetSpringDampingRatio : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_SetSpringDampingRatio : Error processing arguments");
        cobj->SetSpringDampingRatio(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_SetSpringDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetSpringFrequencyHz(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetSpringFrequencyHz : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetSpringFrequencyHz();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetSpringFrequencyHz : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetJointTranslation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetJointTranslation : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetJointTranslation();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetJointTranslation : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetSpringDampingRatio(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetSpringDampingRatio : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetSpringDampingRatio();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetSpringDampingRatio : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetLocalAxisA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetLocalAxisA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAxisA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetLocalAxisA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_SetSpringFrequencyHz(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_SetSpringFrequencyHz : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_SetSpringFrequencyHz : Error processing arguments");
        cobj->SetSpringFrequencyHz(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_SetSpringFrequencyHz : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetLocalAnchorA(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetLocalAnchorA : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorA();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetLocalAnchorA : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_SetMotorSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_SetMotorSpeed : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_SetMotorSpeed : Error processing arguments");
        cobj->SetMotorSpeed(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_SetMotorSpeed : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetLocalAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetLocalAnchorB : Invalid Native Object");
    if (argc == 0) {
        const b2Vec2& ret = cobj->GetLocalAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetLocalAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_SetMaxMotorTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_SetMaxMotorTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_SetMaxMotorTorque : Error processing arguments");
        cobj->SetMaxMotorTorque(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_SetMaxMotorTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetAnchorB(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetAnchorB : Invalid Native Object");
    if (argc == 0) {
        b2Vec2 ret = cobj->GetAnchorB();
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetAnchorB : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetReactionForce(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetReactionForce : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_GetReactionForce : Error processing arguments");
        b2Vec2 ret = cobj->GetReactionForce(arg0);
        JS::RootedValue jsret(cx);
        jsret = b2Vec2_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetReactionForce : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetMotorTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetMotorTorque : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_GetMotorTorque : Error processing arguments");
        double ret = cobj->GetMotorTorque(arg0);
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetMotorTorque : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetJointSpeed(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetJointSpeed : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetJointSpeed();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetJointSpeed : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_GetMaxMotorTorque(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_GetMaxMotorTorque : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->GetMaxMotorTorque();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_GetMaxMotorTorque : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_box2dclasses_b2WheelJoint_EnableMotor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    b2WheelJoint* cobj = (b2WheelJoint *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_box2dclasses_b2WheelJoint_EnableMotor : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_box2dclasses_b2WheelJoint_EnableMotor : Error processing arguments");
        cobj->EnableMotor(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_box2dclasses_b2WheelJoint_EnableMotor : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_b2Joint_prototype;

void js_register_box2dclasses_b2WheelJoint(JSContext *cx, JS::HandleObject global) {
    jsb_b2WheelJoint_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_b2WheelJoint_class->name = "b2WheelJoint";
    jsb_b2WheelJoint_class->addProperty = JS_PropertyStub;
    jsb_b2WheelJoint_class->delProperty = JS_DeletePropertyStub;
    jsb_b2WheelJoint_class->getProperty = JS_PropertyStub;
    jsb_b2WheelJoint_class->setProperty = JS_StrictPropertyStub;
    jsb_b2WheelJoint_class->enumerate = JS_EnumerateStub;
    jsb_b2WheelJoint_class->resolve = JS_ResolveStub;
    jsb_b2WheelJoint_class->convert = JS_ConvertStub;
    jsb_b2WheelJoint_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("IsMotorEnabled", js_box2dclasses_b2WheelJoint_IsMotorEnabled, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMotorSpeed", js_box2dclasses_b2WheelJoint_GetMotorSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorA", js_box2dclasses_b2WheelJoint_GetAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionTorque", js_box2dclasses_b2WheelJoint_GetReactionTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("Dump", js_box2dclasses_b2WheelJoint_Dump, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetSpringDampingRatio", js_box2dclasses_b2WheelJoint_SetSpringDampingRatio, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetSpringFrequencyHz", js_box2dclasses_b2WheelJoint_GetSpringFrequencyHz, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointTranslation", js_box2dclasses_b2WheelJoint_GetJointTranslation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetSpringDampingRatio", js_box2dclasses_b2WheelJoint_GetSpringDampingRatio, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAxisA", js_box2dclasses_b2WheelJoint_GetLocalAxisA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetSpringFrequencyHz", js_box2dclasses_b2WheelJoint_SetSpringFrequencyHz, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorA", js_box2dclasses_b2WheelJoint_GetLocalAnchorA, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMotorSpeed", js_box2dclasses_b2WheelJoint_SetMotorSpeed, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetLocalAnchorB", js_box2dclasses_b2WheelJoint_GetLocalAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("SetMaxMotorTorque", js_box2dclasses_b2WheelJoint_SetMaxMotorTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetAnchorB", js_box2dclasses_b2WheelJoint_GetAnchorB, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetReactionForce", js_box2dclasses_b2WheelJoint_GetReactionForce, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMotorTorque", js_box2dclasses_b2WheelJoint_GetMotorTorque, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetJointSpeed", js_box2dclasses_b2WheelJoint_GetJointSpeed, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("GetMaxMotorTorque", js_box2dclasses_b2WheelJoint_GetMaxMotorTorque, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("EnableMotor", js_box2dclasses_b2WheelJoint_EnableMotor, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_b2Joint_prototype);
    jsb_b2WheelJoint_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_b2WheelJoint_class,
        dummy_constructor<b2WheelJoint>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_b2WheelJoint_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "b2WheelJoint"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<b2WheelJoint>(cx, jsb_b2WheelJoint_class, proto, parent_proto);
}

void register_all_box2dclasses(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "b2", &ns);

    js_register_box2dclasses_b2Joint(cx, ns);
    js_register_box2dclasses_b2DistanceJoint(cx, ns);
    js_register_box2dclasses_b2Fixture(cx, ns);
    js_register_box2dclasses_b2MouseJoint(cx, ns);
    js_register_box2dclasses_b2MotorJoint(cx, ns);
    js_register_box2dclasses_b2PulleyJoint(cx, ns);
    js_register_box2dclasses_b2World(cx, ns);
    js_register_box2dclasses_b2PrismaticJoint(cx, ns);
    js_register_box2dclasses_b2Shape(cx, ns);
    js_register_box2dclasses_b2CircleShape(cx, ns);
    js_register_box2dclasses_b2WheelJoint(cx, ns);
    js_register_box2dclasses_b2Draw(cx, ns);
    js_register_box2dclasses_b2GearJoint(cx, ns);
    js_register_box2dclasses_b2RayCastCallback(cx, ns);
    js_register_box2dclasses_b2WeldJoint(cx, ns);
    js_register_box2dclasses_b2RevoluteJoint(cx, ns);
    js_register_box2dclasses_b2ContactListener(cx, ns);
    js_register_box2dclasses_b2ChainShape(cx, ns);
    js_register_box2dclasses_b2QueryCallback(cx, ns);
    js_register_box2dclasses_b2RopeJoint(cx, ns);
    js_register_box2dclasses_b2PolygonShape(cx, ns);
    js_register_box2dclasses_b2EdgeShape(cx, ns);
    js_register_box2dclasses_b2Contact(cx, ns);
    js_register_box2dclasses_b2Body(cx, ns);
    js_register_box2dclasses_b2FrictionJoint(cx, ns);
}

