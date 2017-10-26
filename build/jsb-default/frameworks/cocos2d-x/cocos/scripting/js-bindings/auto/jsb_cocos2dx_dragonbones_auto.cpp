#include "scripting/js-bindings/auto/jsb_cocos2dx_dragonbones_auto.hpp"
#include "scripting/js-bindings/manual/cocos2d_specifics.hpp"
#include "editor-support/dragonbones/cocos2dx/CCDragonBonesHeaders.h"

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
JSClass  *jsb_dragonBones_BaseObject_class;
JSObject *jsb_dragonBones_BaseObject_prototype;

bool js_cocos2dx_dragonbones_BaseObject_getClassTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseObject* cobj = (dragonBones::BaseObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseObject_getClassTypeIndex : Invalid Native Object");
    if (argc == 0) {
        unsigned long ret = cobj->getClassTypeIndex();
        JS::RootedValue jsret(cx);
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseObject_getClassTypeIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_BaseObject_returnToPool(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseObject* cobj = (dragonBones::BaseObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseObject_returnToPool : Invalid Native Object");
    if (argc == 0) {
        cobj->returnToPool();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseObject_returnToPool : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_BaseObject_clearPool(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        unsigned long arg0 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseObject_clearPool : Error processing arguments");
        dragonBones::BaseObject::clearPool(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseObject_clearPool : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_BaseObject_setMaxCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        unsigned long arg0 = 0;
        unsigned long arg1 = 0;
        ok &= jsval_to_ulong(cx, args.get(0), &arg0);
        ok &= jsval_to_ulong(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseObject_setMaxCount : Error processing arguments");
        dragonBones::BaseObject::setMaxCount(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseObject_setMaxCount : wrong number of arguments");
    return false;
}


void js_register_cocos2dx_dragonbones_BaseObject(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_BaseObject_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_BaseObject_class->name = "BaseObject";
    jsb_dragonBones_BaseObject_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_BaseObject_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_BaseObject_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_BaseObject_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_BaseObject_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_BaseObject_class->resolve = JS_ResolveStub;
    jsb_dragonBones_BaseObject_class->convert = JS_ConvertStub;
    jsb_dragonBones_BaseObject_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getClassTypeIndex", js_cocos2dx_dragonbones_BaseObject_getClassTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("returnToPool", js_cocos2dx_dragonbones_BaseObject_returnToPool, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("clearPool", js_cocos2dx_dragonbones_BaseObject_clearPool, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setMaxCount", js_cocos2dx_dragonbones_BaseObject_setMaxCount, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_dragonBones_BaseObject_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_BaseObject_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_BaseObject_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "BaseObject"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::BaseObject>(cx, jsb_dragonBones_BaseObject_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_Matrix_class;
JSObject *jsb_dragonBones_Matrix_prototype;

bool js_cocos2dx_dragonbones_Matrix_get_a(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_get_a : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->a);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_set_a(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_set_a : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Matrix_set_a : Error processing new value");
    cobj->a = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_get_b(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_get_b : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->b);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_set_b(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_set_b : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Matrix_set_b : Error processing new value");
    cobj->b = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_get_c(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_get_c : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->c);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_set_c(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_set_c : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Matrix_set_c : Error processing new value");
    cobj->c = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_get_d(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_get_d : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->d);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_set_d(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_set_d : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Matrix_set_d : Error processing new value");
    cobj->d = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_get_tx(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_get_tx : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->tx);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_set_tx(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_set_tx : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Matrix_set_tx : Error processing new value");
    cobj->tx = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_get_ty(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_get_ty : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->ty);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_set_ty(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Matrix* cobj = (dragonBones::Matrix *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Matrix_set_ty : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Matrix_set_ty : Error processing new value");
    cobj->ty = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Matrix_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::Matrix* cobj = new (std::nothrow) dragonBones::Matrix();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::Matrix>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::Matrix"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_dragonBones_Matrix_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Matrix)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::Matrix *nobj = static_cast<dragonBones::Matrix *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_Matrix(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_Matrix_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_Matrix_class->name = "Matrix";
    jsb_dragonBones_Matrix_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_Matrix_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_Matrix_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_Matrix_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_Matrix_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_Matrix_class->resolve = JS_ResolveStub;
    jsb_dragonBones_Matrix_class->convert = JS_ConvertStub;
    jsb_dragonBones_Matrix_class->finalize = js_dragonBones_Matrix_finalize;
    jsb_dragonBones_Matrix_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("a", js_cocos2dx_dragonbones_Matrix_get_a, js_cocos2dx_dragonbones_Matrix_set_a, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("b", js_cocos2dx_dragonbones_Matrix_get_b, js_cocos2dx_dragonbones_Matrix_set_b, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("c", js_cocos2dx_dragonbones_Matrix_get_c, js_cocos2dx_dragonbones_Matrix_set_c, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("d", js_cocos2dx_dragonbones_Matrix_get_d, js_cocos2dx_dragonbones_Matrix_set_d, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("tx", js_cocos2dx_dragonbones_Matrix_get_tx, js_cocos2dx_dragonbones_Matrix_set_tx, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("ty", js_cocos2dx_dragonbones_Matrix_get_ty, js_cocos2dx_dragonbones_Matrix_set_ty, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_dragonBones_Matrix_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_Matrix_class,
        js_cocos2dx_dragonbones_Matrix_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_Matrix_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Matrix"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::Matrix>(cx, jsb_dragonBones_Matrix_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_Transform_class;
JSObject *jsb_dragonBones_Transform_prototype;

bool js_cocos2dx_dragonbones_Transform_getRotation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_getRotation : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->getRotation();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Transform_getRotation : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Transform_setRotation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_setRotation : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_setRotation : Error processing arguments");
        cobj->setRotation(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Transform_setRotation : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Transform_normalizeRadian(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_normalizeRadian : Error processing arguments");

        double ret = dragonBones::Transform::normalizeRadian(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_Transform_normalizeRadian : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_Transform_get_x(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_get_x : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->x);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Transform_set_x(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_set_x : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_set_x : Error processing new value");
    cobj->x = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Transform_get_y(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_get_y : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->y);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Transform_set_y(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_set_y : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_set_y : Error processing new value");
    cobj->y = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Transform_get_skewX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_get_skewX : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->skewX);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Transform_set_skewX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_set_skewX : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_set_skewX : Error processing new value");
    cobj->skewX = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Transform_get_skewY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_get_skewY : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->skewY);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Transform_set_skewY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_set_skewY : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_set_skewY : Error processing new value");
    cobj->skewY = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Transform_get_scaleX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_get_scaleX : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->scaleX);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Transform_set_scaleX(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_set_scaleX : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_set_scaleX : Error processing new value");
    cobj->scaleX = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Transform_get_scaleY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_get_scaleY : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->scaleY);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Transform_set_scaleY(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Transform* cobj = (dragonBones::Transform *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Transform_set_scaleY : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Transform_set_scaleY : Error processing new value");
    cobj->scaleY = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Transform_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::Transform* cobj = new (std::nothrow) dragonBones::Transform();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::Transform>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::Transform"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_dragonBones_Transform_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Transform)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::Transform *nobj = static_cast<dragonBones::Transform *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_Transform(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_Transform_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_Transform_class->name = "Transform";
    jsb_dragonBones_Transform_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_Transform_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_Transform_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_Transform_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_Transform_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_Transform_class->resolve = JS_ResolveStub;
    jsb_dragonBones_Transform_class->convert = JS_ConvertStub;
    jsb_dragonBones_Transform_class->finalize = js_dragonBones_Transform_finalize;
    jsb_dragonBones_Transform_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("x", js_cocos2dx_dragonbones_Transform_get_x, js_cocos2dx_dragonbones_Transform_set_x, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("y", js_cocos2dx_dragonbones_Transform_get_y, js_cocos2dx_dragonbones_Transform_set_y, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("skewX", js_cocos2dx_dragonbones_Transform_get_skewX, js_cocos2dx_dragonbones_Transform_set_skewX, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("skewY", js_cocos2dx_dragonbones_Transform_get_skewY, js_cocos2dx_dragonbones_Transform_set_skewY, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("scaleX", js_cocos2dx_dragonbones_Transform_get_scaleX, js_cocos2dx_dragonbones_Transform_set_scaleX, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("scaleY", js_cocos2dx_dragonbones_Transform_get_scaleY, js_cocos2dx_dragonbones_Transform_set_scaleY, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getRotation", js_cocos2dx_dragonbones_Transform_getRotation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setRotation", js_cocos2dx_dragonbones_Transform_setRotation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("normalizeRadian", js_cocos2dx_dragonbones_Transform_normalizeRadian, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_dragonBones_Transform_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_Transform_class,
        js_cocos2dx_dragonbones_Transform_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_Transform_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Transform"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::Transform>(cx, jsb_dragonBones_Transform_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_TextureData_class;
JSObject *jsb_dragonBones_TextureData_prototype;

bool js_cocos2dx_dragonbones_TextureData_generateRectangle(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        dragonBones::Rectangle* ret = dragonBones::TextureData::generateRectangle();
        jsval jsret = JSVAL_NULL;
        if (ret) {
        jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Rectangle>(cx, (dragonBones::Rectangle*)ret));
    } else {
        jsret = JSVAL_NULL;
    };
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_TextureData_generateRectangle : wrong number of arguments");
    return false;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_register_cocos2dx_dragonbones_TextureData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_TextureData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_TextureData_class->name = "TextureData";
    jsb_dragonBones_TextureData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_TextureData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_TextureData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_TextureData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_TextureData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_TextureData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_TextureData_class->convert = JS_ConvertStub;
    jsb_dragonBones_TextureData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("generateRectangle", js_cocos2dx_dragonbones_TextureData_generateRectangle, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_TextureData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_TextureData_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_TextureData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "TextureData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::TextureData>(cx, jsb_dragonBones_TextureData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_TextureAtlasData_class;
JSObject *jsb_dragonBones_TextureAtlasData_prototype;

bool js_cocos2dx_dragonbones_TextureAtlasData_addTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TextureAtlasData_addTexture : Invalid Native Object");
    if (argc == 1) {
        dragonBones::TextureData* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::TextureData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_TextureAtlasData_addTexture : Error processing arguments");
        cobj->addTexture(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TextureAtlasData_addTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_TextureAtlasData_generateTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TextureAtlasData_generateTexture : Invalid Native Object");
    if (argc == 0) {
        dragonBones::TextureData* ret = cobj->generateTexture();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::TextureData>(cx, (dragonBones::TextureData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TextureAtlasData_generateTexture : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_TextureAtlasData_getTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TextureAtlasData* cobj = (dragonBones::TextureAtlasData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TextureAtlasData_getTexture : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_TextureAtlasData_getTexture : Error processing arguments");
        dragonBones::TextureData* ret = cobj->getTexture(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::TextureData>(cx, (dragonBones::TextureData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TextureAtlasData_getTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_register_cocos2dx_dragonbones_TextureAtlasData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_TextureAtlasData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_TextureAtlasData_class->name = "TextureAtlasData";
    jsb_dragonBones_TextureAtlasData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_TextureAtlasData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_TextureAtlasData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_TextureAtlasData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_TextureAtlasData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_TextureAtlasData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_TextureAtlasData_class->convert = JS_ConvertStub;
    jsb_dragonBones_TextureAtlasData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("addTexture", js_cocos2dx_dragonbones_TextureAtlasData_addTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("generateTexture", js_cocos2dx_dragonbones_TextureAtlasData_generateTexture, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTexture", js_cocos2dx_dragonbones_TextureAtlasData_getTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_TextureAtlasData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_TextureAtlasData_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_TextureAtlasData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "TextureAtlasData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::TextureAtlasData>(cx, jsb_dragonBones_TextureAtlasData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_AnimationData_class;
JSObject *jsb_dragonBones_AnimationData_prototype;

bool js_cocos2dx_dragonbones_AnimationData_getClassTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_getClassTypeIndex : Invalid Native Object");
    if (argc == 0) {
        unsigned long ret = cobj->getClassTypeIndex();
        JS::RootedValue jsret(cx);
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationData_getClassTypeIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationData_getBoneTimeline(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_getBoneTimeline : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_getBoneTimeline : Error processing arguments");
        dragonBones::BoneTimelineData* ret = cobj->getBoneTimeline(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::BoneTimelineData>(cx, (dragonBones::BoneTimelineData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationData_getBoneTimeline : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::AnimationData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_AnimationData_get_frameCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_get_frameCount : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = uint32_to_jsval(cx, cobj->frameCount);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_set_frameCount(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_frameCount : Invalid Native Object");

    bool ok = true;
    unsigned int arg0 = 0;
    ok &= jsval_to_uint32(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_frameCount : Error processing new value");
    cobj->frameCount = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_get_playTimes(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_get_playTimes : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = uint32_to_jsval(cx, cobj->playTimes);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_set_playTimes(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_playTimes : Invalid Native Object");

    bool ok = true;
    unsigned int arg0 = 0;
    ok &= jsval_to_uint32(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_playTimes : Error processing new value");
    cobj->playTimes = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_get_position(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_get_position : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->position);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_set_position(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_position : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_position : Error processing new value");
    cobj->position = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_get_duration(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_get_duration : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->duration);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_set_duration(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_duration : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_duration : Error processing new value");
    cobj->duration = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_get_fadeInTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_get_fadeInTime : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->fadeInTime);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_set_fadeInTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_fadeInTime : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_fadeInTime : Error processing new value");
    cobj->fadeInTime = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationData* cobj = (dragonBones::AnimationData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::AnimationData* cobj = new (std::nothrow) dragonBones::AnimationData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::AnimationData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::AnimationData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_dragonBones_AnimationData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (AnimationData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::AnimationData *nobj = static_cast<dragonBones::AnimationData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_AnimationData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_AnimationData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_AnimationData_class->name = "AnimationData";
    jsb_dragonBones_AnimationData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_AnimationData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_AnimationData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_AnimationData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_AnimationData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_AnimationData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_AnimationData_class->convert = JS_ConvertStub;
    jsb_dragonBones_AnimationData_class->finalize = js_dragonBones_AnimationData_finalize;
    jsb_dragonBones_AnimationData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("frameCount", js_cocos2dx_dragonbones_AnimationData_get_frameCount, js_cocos2dx_dragonbones_AnimationData_set_frameCount, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("playTimes", js_cocos2dx_dragonbones_AnimationData_get_playTimes, js_cocos2dx_dragonbones_AnimationData_set_playTimes, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("position", js_cocos2dx_dragonbones_AnimationData_get_position, js_cocos2dx_dragonbones_AnimationData_set_position, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("duration", js_cocos2dx_dragonbones_AnimationData_get_duration, js_cocos2dx_dragonbones_AnimationData_set_duration, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("fadeInTime", js_cocos2dx_dragonbones_AnimationData_get_fadeInTime, js_cocos2dx_dragonbones_AnimationData_set_fadeInTime, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("name", js_cocos2dx_dragonbones_AnimationData_get_name, js_cocos2dx_dragonbones_AnimationData_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getClassTypeIndex", js_cocos2dx_dragonbones_AnimationData_getClassTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getBoneTimeline", js_cocos2dx_dragonbones_AnimationData_getBoneTimeline, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_AnimationData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_dragonBones_AnimationData_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_AnimationData_class,
        js_cocos2dx_dragonbones_AnimationData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_AnimationData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "AnimationData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::AnimationData>(cx, jsb_dragonBones_AnimationData_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_BoneData_class;
JSObject *jsb_dragonBones_BoneData_prototype;

bool js_cocos2dx_dragonbones_BoneData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::BoneData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_BoneData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_BoneData_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::BoneData* cobj = (dragonBones::BoneData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BoneData_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_BoneData_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::BoneData* cobj = (dragonBones::BoneData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BoneData_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BoneData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_BoneData_get_parent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::BoneData* cobj = (dragonBones::BoneData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BoneData_get_parent : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->parent) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::BoneData>(cx, (dragonBones::BoneData*)cobj->parent));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_BoneData_set_parent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::BoneData* cobj = (dragonBones::BoneData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BoneData_set_parent : Invalid Native Object");

    bool ok = true;
    dragonBones::BoneData* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::BoneData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BoneData_set_parent : Error processing new value");
    cobj->parent = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_BoneData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::BoneData* cobj = new (std::nothrow) dragonBones::BoneData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::BoneData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::BoneData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_BoneData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (BoneData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::BoneData *nobj = static_cast<dragonBones::BoneData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_BoneData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_BoneData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_BoneData_class->name = "BoneData";
    jsb_dragonBones_BoneData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_BoneData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_BoneData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_BoneData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_BoneData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_BoneData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_BoneData_class->convert = JS_ConvertStub;
    jsb_dragonBones_BoneData_class->finalize = js_dragonBones_BoneData_finalize;
    jsb_dragonBones_BoneData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("name", js_cocos2dx_dragonbones_BoneData_get_name, js_cocos2dx_dragonbones_BoneData_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("parent", js_cocos2dx_dragonbones_BoneData_get_parent, js_cocos2dx_dragonbones_BoneData_set_parent, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_BoneData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_BoneData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_BoneData_class,
        js_cocos2dx_dragonbones_BoneData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_BoneData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "BoneData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::BoneData>(cx, jsb_dragonBones_BoneData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_SlotData_class;
JSObject *jsb_dragonBones_SlotData_prototype;

bool js_cocos2dx_dragonbones_SlotData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::SlotData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_SlotData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_SlotData_generateColor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        dragonBones::ColorTransform* ret = dragonBones::SlotData::generateColor();
        jsval jsret = JSVAL_NULL;
        if (ret) {
        jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::ColorTransform>(cx, (dragonBones::ColorTransform*)ret));
    } else {
        jsret = JSVAL_NULL;
    };
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_SlotData_generateColor : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_SlotData_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::SlotData* cobj = (dragonBones::SlotData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_SlotData_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_SlotData_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::SlotData* cobj = (dragonBones::SlotData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_SlotData_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_SlotData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_SlotData_get_parent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::SlotData* cobj = (dragonBones::SlotData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_SlotData_get_parent : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->parent) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::BoneData>(cx, (dragonBones::BoneData*)cobj->parent));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_SlotData_set_parent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::SlotData* cobj = (dragonBones::SlotData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_SlotData_set_parent : Invalid Native Object");

    bool ok = true;
    dragonBones::BoneData* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::BoneData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_SlotData_set_parent : Error processing new value");
    cobj->parent = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_SlotData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::SlotData* cobj = new (std::nothrow) dragonBones::SlotData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::SlotData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::SlotData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_SlotData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (SlotData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::SlotData *nobj = static_cast<dragonBones::SlotData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_SlotData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_SlotData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_SlotData_class->name = "SlotData";
    jsb_dragonBones_SlotData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_SlotData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_SlotData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_SlotData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_SlotData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_SlotData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_SlotData_class->convert = JS_ConvertStub;
    jsb_dragonBones_SlotData_class->finalize = js_dragonBones_SlotData_finalize;
    jsb_dragonBones_SlotData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("name", js_cocos2dx_dragonbones_SlotData_get_name, js_cocos2dx_dragonbones_SlotData_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("parent", js_cocos2dx_dragonbones_SlotData_get_parent, js_cocos2dx_dragonbones_SlotData_set_parent, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_SlotData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("generateColor", js_cocos2dx_dragonbones_SlotData_generateColor, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_SlotData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_SlotData_class,
        js_cocos2dx_dragonbones_SlotData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_SlotData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "SlotData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::SlotData>(cx, jsb_dragonBones_SlotData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_SkinData_class;
JSObject *jsb_dragonBones_SkinData_prototype;

bool js_cocos2dx_dragonbones_SkinData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::SkinData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_SkinData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_SkinData_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::SkinData* cobj = (dragonBones::SkinData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_SkinData_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_SkinData_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::SkinData* cobj = (dragonBones::SkinData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_SkinData_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_SkinData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_SkinData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::SkinData* cobj = new (std::nothrow) dragonBones::SkinData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::SkinData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::SkinData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_SkinData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (SkinData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::SkinData *nobj = static_cast<dragonBones::SkinData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_SkinData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_SkinData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_SkinData_class->name = "SkinData";
    jsb_dragonBones_SkinData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_SkinData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_SkinData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_SkinData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_SkinData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_SkinData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_SkinData_class->convert = JS_ConvertStub;
    jsb_dragonBones_SkinData_class->finalize = js_dragonBones_SkinData_finalize;
    jsb_dragonBones_SkinData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("name", js_cocos2dx_dragonbones_SkinData_get_name, js_cocos2dx_dragonbones_SkinData_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_SkinData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_SkinData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_SkinData_class,
        js_cocos2dx_dragonbones_SkinData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_SkinData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "SkinData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::SkinData>(cx, jsb_dragonBones_SkinData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_ArmatureData_class;
JSObject *jsb_dragonBones_ArmatureData_prototype;

bool js_cocos2dx_dragonbones_ArmatureData_getBone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getBone : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getBone : Error processing arguments");
        dragonBones::BoneData* ret = cobj->getBone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::BoneData>(cx, (dragonBones::BoneData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getBone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_ArmatureData_getAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimation : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getAnimation : Error processing arguments");
        dragonBones::AnimationData* ret = cobj->getAnimation(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationData>(cx, (dragonBones::AnimationData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getAnimation : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_ArmatureData_getSlot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getSlot : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getSlot : Error processing arguments");
        dragonBones::SlotData* ret = cobj->getSlot(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::SlotData>(cx, (dragonBones::SlotData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getSlot : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_ArmatureData_getSkin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getSkin : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getSkin : Error processing arguments");
        dragonBones::SkinData* ret = cobj->getSkin(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::SkinData>(cx, (dragonBones::SkinData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getSkin : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin : Invalid Native Object");
    if (argc == 0) {
        dragonBones::SkinData* ret = cobj->getDefaultSkin();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::SkinData>(cx, (dragonBones::SkinData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation : Invalid Native Object");
    if (argc == 0) {
        dragonBones::AnimationData* ret = cobj->getDefaultAnimation();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationData>(cx, (dragonBones::AnimationData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_ArmatureData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::ArmatureData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_ArmatureData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_ArmatureData_get_frameRate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_get_frameRate : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = uint32_to_jsval(cx, cobj->frameRate);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_ArmatureData_set_frameRate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_set_frameRate : Invalid Native Object");

    bool ok = true;
    unsigned int arg0 = 0;
    ok &= jsval_to_uint32(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_ArmatureData_set_frameRate : Error processing new value");
    cobj->frameRate = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_ArmatureData_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_ArmatureData_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::ArmatureData* cobj = (dragonBones::ArmatureData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_ArmatureData_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_ArmatureData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_ArmatureData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::ArmatureData* cobj = new (std::nothrow) dragonBones::ArmatureData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::ArmatureData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::ArmatureData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_ArmatureData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (ArmatureData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::ArmatureData *nobj = static_cast<dragonBones::ArmatureData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_ArmatureData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_ArmatureData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_ArmatureData_class->name = "ArmatureData";
    jsb_dragonBones_ArmatureData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_ArmatureData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_ArmatureData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_ArmatureData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_ArmatureData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_ArmatureData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_ArmatureData_class->convert = JS_ConvertStub;
    jsb_dragonBones_ArmatureData_class->finalize = js_dragonBones_ArmatureData_finalize;
    jsb_dragonBones_ArmatureData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("frameRate", js_cocos2dx_dragonbones_ArmatureData_get_frameRate, js_cocos2dx_dragonbones_ArmatureData_set_frameRate, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("name", js_cocos2dx_dragonbones_ArmatureData_get_name, js_cocos2dx_dragonbones_ArmatureData_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getBone", js_cocos2dx_dragonbones_ArmatureData_getBone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAnimation", js_cocos2dx_dragonbones_ArmatureData_getAnimation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSlot", js_cocos2dx_dragonbones_ArmatureData_getSlot, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSkin", js_cocos2dx_dragonbones_ArmatureData_getSkin, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDefaultSkin", js_cocos2dx_dragonbones_ArmatureData_getDefaultSkin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDefaultAnimation", js_cocos2dx_dragonbones_ArmatureData_getDefaultAnimation, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_ArmatureData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_ArmatureData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_ArmatureData_class,
        js_cocos2dx_dragonbones_ArmatureData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_ArmatureData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "ArmatureData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::ArmatureData>(cx, jsb_dragonBones_ArmatureData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_DragonBonesData_class;
JSObject *jsb_dragonBones_DragonBonesData_prototype;

bool js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames : Invalid Native Object");
    if (argc == 0) {
        const std::vector<std::string>& ret = cobj->getArmatureNames();
        JS::RootedValue jsret(cx);
        jsret = std_vector_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_DragonBonesData_addArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_addArmature : Invalid Native Object");
    if (argc == 1) {
        dragonBones::ArmatureData* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::ArmatureData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_addArmature : Error processing arguments");
        cobj->addArmature(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_DragonBonesData_addArmature : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_DragonBonesData_getArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmature : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_getArmature : Error processing arguments");
        dragonBones::ArmatureData* ret = cobj->getArmature(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::ArmatureData>(cx, (dragonBones::ArmatureData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_DragonBonesData_getArmature : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_DragonBonesData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::DragonBonesData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_DragonBonesData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_DragonBonesData_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_DragonBonesData_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::DragonBonesData* cobj = (dragonBones::DragonBonesData *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_DragonBonesData_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_DragonBonesData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::DragonBonesData* cobj = new (std::nothrow) dragonBones::DragonBonesData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::DragonBonesData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::DragonBonesData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_DragonBonesData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (DragonBonesData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::DragonBonesData *nobj = static_cast<dragonBones::DragonBonesData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_DragonBonesData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_DragonBonesData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_DragonBonesData_class->name = "DragonBonesData";
    jsb_dragonBones_DragonBonesData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_DragonBonesData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_DragonBonesData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_DragonBonesData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_DragonBonesData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_DragonBonesData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_DragonBonesData_class->convert = JS_ConvertStub;
    jsb_dragonBones_DragonBonesData_class->finalize = js_dragonBones_DragonBonesData_finalize;
    jsb_dragonBones_DragonBonesData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("name", js_cocos2dx_dragonbones_DragonBonesData_get_name, js_cocos2dx_dragonbones_DragonBonesData_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getArmatureNames", js_cocos2dx_dragonbones_DragonBonesData_getArmatureNames, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addArmature", js_cocos2dx_dragonbones_DragonBonesData_addArmature, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getArmature", js_cocos2dx_dragonbones_DragonBonesData_getArmature, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_DragonBonesData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_DragonBonesData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_DragonBonesData_class,
        js_cocos2dx_dragonbones_DragonBonesData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_DragonBonesData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "DragonBonesData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::DragonBonesData>(cx, jsb_dragonBones_DragonBonesData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_EventObject_class;
JSObject *jsb_dragonBones_EventObject_prototype;

bool js_cocos2dx_dragonbones_EventObject_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::EventObject::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_EventObject_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_EventObject_get_type(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_get_type : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->type);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_set_type(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_set_type : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_EventObject_set_type : Error processing new value");
    cobj->type = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_EventObject_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_get_armature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_get_armature : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->armature) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)cobj->armature));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_set_armature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_set_armature : Invalid Native Object");

    bool ok = true;
    dragonBones::Armature* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_EventObject_set_armature : Error processing new value");
    cobj->armature = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_get_bone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_get_bone : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->bone) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Bone>(cx, (dragonBones::Bone*)cobj->bone));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_set_bone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_set_bone : Invalid Native Object");

    bool ok = true;
    dragonBones::Bone* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_EventObject_set_bone : Error processing new value");
    cobj->bone = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_get_slot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_get_slot : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->slot) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Slot>(cx, (dragonBones::Slot*)cobj->slot));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_set_slot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_set_slot : Invalid Native Object");

    bool ok = true;
    dragonBones::Slot* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Slot*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_EventObject_set_slot : Error processing new value");
    cobj->slot = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_get_animationState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_get_animationState : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->animationState) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)cobj->animationState));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_set_animationState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::EventObject* cobj = (dragonBones::EventObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_EventObject_set_animationState : Invalid Native Object");

    bool ok = true;
    dragonBones::AnimationState* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::AnimationState*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_EventObject_set_animationState : Error processing new value");
    cobj->animationState = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_EventObject_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::EventObject* cobj = new (std::nothrow) dragonBones::EventObject();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::EventObject>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::EventObject"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_EventObject_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (EventObject)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::EventObject *nobj = static_cast<dragonBones::EventObject *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_EventObject(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_EventObject_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_EventObject_class->name = "EventObject";
    jsb_dragonBones_EventObject_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_EventObject_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_EventObject_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_EventObject_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_EventObject_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_EventObject_class->resolve = JS_ResolveStub;
    jsb_dragonBones_EventObject_class->convert = JS_ConvertStub;
    jsb_dragonBones_EventObject_class->finalize = js_dragonBones_EventObject_finalize;
    jsb_dragonBones_EventObject_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("type", js_cocos2dx_dragonbones_EventObject_get_type, js_cocos2dx_dragonbones_EventObject_set_type, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("name", js_cocos2dx_dragonbones_EventObject_get_name, js_cocos2dx_dragonbones_EventObject_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("armature", js_cocos2dx_dragonbones_EventObject_get_armature, js_cocos2dx_dragonbones_EventObject_set_armature, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("bone", js_cocos2dx_dragonbones_EventObject_get_bone, js_cocos2dx_dragonbones_EventObject_set_bone, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("slot", js_cocos2dx_dragonbones_EventObject_get_slot, js_cocos2dx_dragonbones_EventObject_set_slot, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("animationState", js_cocos2dx_dragonbones_EventObject_get_animationState, js_cocos2dx_dragonbones_EventObject_set_animationState, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_EventObject_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_EventObject_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_EventObject_class,
        js_cocos2dx_dragonbones_EventObject_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_EventObject_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "EventObject"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::EventObject>(cx, jsb_dragonBones_EventObject_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_Armature_class;
JSObject *jsb_dragonBones_Armature_prototype;

bool js_cocos2dx_dragonbones_Armature_getSlot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getSlot : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_getSlot : Error processing arguments");
        dragonBones::Slot* ret = cobj->getSlot(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Slot>(cx, (dragonBones::Slot*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getSlot : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature__bufferAction(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature__bufferAction : Invalid Native Object");
    if (argc == 1) {
        dragonBones::ActionData* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::ActionData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature__bufferAction : Error processing arguments");
        cobj->_bufferAction(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature__bufferAction : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getCacheFrameRate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getCacheFrameRate : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->getCacheFrameRate();
        JS::RootedValue jsret(cx);
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getCacheFrameRate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getName : Invalid Native Object");
    if (argc == 0) {
        const std::string& ret = cobj->getName();
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getName : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_dispose(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_dispose : Invalid Native Object");
    if (argc == 0) {
        cobj->dispose();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_dispose : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_addSlot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_addSlot : Invalid Native Object");
    if (argc == 2) {
        dragonBones::Slot* arg0 = nullptr;
        std::string arg1;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Slot*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_addSlot : Error processing arguments");
        cobj->addSlot(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_addSlot : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_invalidUpdate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_invalidUpdate : Invalid Native Object");
    if (argc == 0) {
        cobj->invalidUpdate();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_invalidUpdate : Error processing arguments");
        cobj->invalidUpdate(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_invalidUpdate : Error processing arguments");
        cobj->invalidUpdate(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_invalidUpdate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getBoneByDisplay(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getBoneByDisplay : Invalid Native Object");
    if (argc == 1) {
        void* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_getBoneByDisplay : Error processing arguments");
        dragonBones::Bone* ret = cobj->getBoneByDisplay(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Bone>(cx, (dragonBones::Bone*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getBoneByDisplay : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_setCacheFrameRate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_setCacheFrameRate : Invalid Native Object");
    if (argc == 1) {
        unsigned int arg0 = 0;
        ok &= jsval_to_uint32(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_setCacheFrameRate : Error processing arguments");
        cobj->setCacheFrameRate(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_setCacheFrameRate : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_removeSlot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_removeSlot : Invalid Native Object");
    if (argc == 1) {
        dragonBones::Slot* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Slot*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_removeSlot : Error processing arguments");
        cobj->removeSlot(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_removeSlot : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_addBone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_addBone : Invalid Native Object");
    if (argc == 1) {
        dragonBones::Bone* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_addBone : Error processing arguments");
        cobj->addBone(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        dragonBones::Bone* arg0 = nullptr;
        std::string arg1;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_addBone : Error processing arguments");
        cobj->addBone(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_addBone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_advanceTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_advanceTime : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_advanceTime : Error processing arguments");
        cobj->advanceTime(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_advanceTime : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getBone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getBone : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_getBone : Error processing arguments");
        dragonBones::Bone* ret = cobj->getBone(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Bone>(cx, (dragonBones::Bone*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getBone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getParent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getParent : Invalid Native Object");
    if (argc == 0) {
        dragonBones::Slot* ret = cobj->getParent();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Slot>(cx, (dragonBones::Slot*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getParent : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getSlotByDisplay(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_getSlotByDisplay : Invalid Native Object");
    if (argc == 1) {
        void* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_getSlotByDisplay : Error processing arguments");
        dragonBones::Slot* ret = cobj->getSlotByDisplay(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Slot>(cx, (dragonBones::Slot*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getSlotByDisplay : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_removeBone(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_removeBone : Invalid Native Object");
    if (argc == 1) {
        dragonBones::Bone* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_removeBone : Error processing arguments");
        cobj->removeBone(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_removeBone : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_replaceTexture(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Armature* cobj = (dragonBones::Armature *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Armature_replaceTexture : Invalid Native Object");
    if (argc == 1) {
        void* arg0 = nullptr;
        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Armature_replaceTexture : Error processing arguments");
        cobj->replaceTexture(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_replaceTexture : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Armature_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::Armature::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_Armature_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_Armature_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::Armature* cobj = new (std::nothrow) dragonBones::Armature();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::Armature>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::Armature"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_Armature_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Armature)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::Armature *nobj = static_cast<dragonBones::Armature *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_Armature(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_Armature_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_Armature_class->name = "Armature";
    jsb_dragonBones_Armature_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_Armature_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_Armature_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_Armature_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_Armature_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_Armature_class->resolve = JS_ResolveStub;
    jsb_dragonBones_Armature_class->convert = JS_ConvertStub;
    jsb_dragonBones_Armature_class->finalize = js_dragonBones_Armature_finalize;
    jsb_dragonBones_Armature_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getSlot", js_cocos2dx_dragonbones_Armature_getSlot, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("_bufferAction", js_cocos2dx_dragonbones_Armature__bufferAction, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCacheFrameRate", js_cocos2dx_dragonbones_Armature_getCacheFrameRate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getName", js_cocos2dx_dragonbones_Armature_getName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispose", js_cocos2dx_dragonbones_Armature_dispose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addSlot", js_cocos2dx_dragonbones_Armature_addSlot, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("invalidUpdate", js_cocos2dx_dragonbones_Armature_invalidUpdate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getBoneByDisplay", js_cocos2dx_dragonbones_Armature_getBoneByDisplay, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setCacheFrameRate", js_cocos2dx_dragonbones_Armature_setCacheFrameRate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeSlot", js_cocos2dx_dragonbones_Armature_removeSlot, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addBone", js_cocos2dx_dragonbones_Armature_addBone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("advanceTime", js_cocos2dx_dragonbones_Armature_advanceTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getBone", js_cocos2dx_dragonbones_Armature_getBone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getParent", js_cocos2dx_dragonbones_Armature_getParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSlotByDisplay", js_cocos2dx_dragonbones_Armature_getSlotByDisplay, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeBone", js_cocos2dx_dragonbones_Armature_removeBone, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("replaceTexture", js_cocos2dx_dragonbones_Armature_replaceTexture, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_Armature_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_Armature_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_Armature_class,
        js_cocos2dx_dragonbones_Armature_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_Armature_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Armature"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::Armature>(cx, jsb_dragonBones_Armature_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_Animation_class;
JSObject *jsb_dragonBones_Animation_prototype;

bool js_cocos2dx_dragonbones_Animation_isPlaying(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_isPlaying : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isPlaying();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_isPlaying : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_getAnimationNames(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_getAnimationNames : Invalid Native Object");
    if (argc == 0) {
        const std::vector<std::string>& ret = cobj->getAnimationNames();
        JS::RootedValue jsret(cx);
        jsret = std_vector_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_getAnimationNames : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_fadeIn(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 5) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 6) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 7) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
        arg6 = JS::ToBoolean(args.get(6));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 8) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        bool arg7;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
        arg6 = JS::ToBoolean(args.get(6));
        arg7 = JS::ToBoolean(args.get(7));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 9) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        bool arg7;
        bool arg8;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
        arg6 = JS::ToBoolean(args.get(6));
        arg7 = JS::ToBoolean(args.get(7));
        arg8 = JS::ToBoolean(args.get(8));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 10) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        int arg3 = 0;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        bool arg7;
        bool arg8;
        bool arg9;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        ok &= jsval_to_int32(cx, args.get(5), (int32_t *)&arg5);
        arg6 = JS::ToBoolean(args.get(6));
        arg7 = JS::ToBoolean(args.get(7));
        arg8 = JS::ToBoolean(args.get(8));
        arg9 = JS::ToBoolean(args.get(9));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_fadeIn : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_fadeIn : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_isCompleted(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_isCompleted : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isCompleted();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_isCompleted : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_reset(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_reset : Invalid Native Object");
    if (argc == 0) {
        cobj->reset();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_reset : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_play(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_play : Invalid Native Object");
    if (argc == 0) {
        dragonBones::AnimationState* ret = cobj->play();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->play(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        int arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_play : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->play(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_play : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_getState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_getState : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_getState : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->getState(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_getState : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_stop(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_stop : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_stop : Error processing arguments");
        cobj->stop(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_stop : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_getLastAnimationName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_getLastAnimationName : Invalid Native Object");
    if (argc == 0) {
        const std::string& ret = cobj->getLastAnimationName();
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_getLastAnimationName : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_getLastAnimationState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_getLastAnimationState : Invalid Native Object");
    if (argc == 0) {
        dragonBones::AnimationState* ret = cobj->getLastAnimationState();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_getLastAnimationState : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByTime(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByTime(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByTime(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByProgress(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByProgress(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        double arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByProgress(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_hasAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_hasAnimation : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_hasAnimation : Error processing arguments");
        bool ret = cobj->hasAnimation(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_hasAnimation : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_gotoAndStopByTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndStopByTime(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndStopByTime(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_gotoAndStopByTime : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndStopByProgress(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        double arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !std::isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndStopByProgress(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByFrame(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_uint32(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByFrame(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        unsigned int arg1 = 0;
        int arg2 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_uint32(cx, args.get(1), &arg1);
        ok &= jsval_to_int32(cx, args.get(2), (int32_t *)&arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByFrame(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndStopByFrame(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        unsigned int arg1 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_uint32(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : Error processing arguments");
        dragonBones::AnimationState* ret = cobj->gotoAndStopByFrame(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::AnimationState>(cx, (dragonBones::AnimationState*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Animation_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::Animation::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_Animation_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_Animation_get_timeScale(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_get_timeScale : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->timeScale);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Animation_set_timeScale(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Animation* cobj = (dragonBones::Animation *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Animation_set_timeScale : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Animation_set_timeScale : Error processing new value");
    cobj->timeScale = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Animation_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::Animation* cobj = new (std::nothrow) dragonBones::Animation();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::Animation>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::Animation"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_Animation_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Animation)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::Animation *nobj = static_cast<dragonBones::Animation *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_Animation(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_Animation_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_Animation_class->name = "Animation";
    jsb_dragonBones_Animation_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_Animation_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_Animation_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_Animation_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_Animation_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_Animation_class->resolve = JS_ResolveStub;
    jsb_dragonBones_Animation_class->convert = JS_ConvertStub;
    jsb_dragonBones_Animation_class->finalize = js_dragonBones_Animation_finalize;
    jsb_dragonBones_Animation_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("timeScale", js_cocos2dx_dragonbones_Animation_get_timeScale, js_cocos2dx_dragonbones_Animation_set_timeScale, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("isPlaying", js_cocos2dx_dragonbones_Animation_isPlaying, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAnimationNames", js_cocos2dx_dragonbones_Animation_getAnimationNames, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fadeIn", js_cocos2dx_dragonbones_Animation_fadeIn, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isCompleted", js_cocos2dx_dragonbones_Animation_isCompleted, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("reset", js_cocos2dx_dragonbones_Animation_reset, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("play", js_cocos2dx_dragonbones_Animation_play, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getState", js_cocos2dx_dragonbones_Animation_getState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stop", js_cocos2dx_dragonbones_Animation_stop, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getLastAnimationName", js_cocos2dx_dragonbones_Animation_getLastAnimationName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getLastAnimationState", js_cocos2dx_dragonbones_Animation_getLastAnimationState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("gotoAndPlayByTime", js_cocos2dx_dragonbones_Animation_gotoAndPlayByTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("gotoAndPlayByProgress", js_cocos2dx_dragonbones_Animation_gotoAndPlayByProgress, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hasAnimation", js_cocos2dx_dragonbones_Animation_hasAnimation, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("gotoAndStopByTime", js_cocos2dx_dragonbones_Animation_gotoAndStopByTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("gotoAndStopByProgress", js_cocos2dx_dragonbones_Animation_gotoAndStopByProgress, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("gotoAndPlayByFrame", js_cocos2dx_dragonbones_Animation_gotoAndPlayByFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("gotoAndStopByFrame", js_cocos2dx_dragonbones_Animation_gotoAndStopByFrame, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_Animation_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_Animation_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_Animation_class,
        js_cocos2dx_dragonbones_Animation_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_Animation_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Animation"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::Animation>(cx, jsb_dragonBones_Animation_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_TransformObject_class;
JSObject *jsb_dragonBones_TransformObject_prototype;

bool js_cocos2dx_dragonbones_TransformObject__setArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject__setArmature : Invalid Native Object");
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_TransformObject__setArmature : Error processing arguments");
        cobj->_setArmature(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TransformObject__setArmature : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_TransformObject__setParent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject__setParent : Invalid Native Object");
    if (argc == 1) {
        dragonBones::Bone* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Bone*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_TransformObject__setParent : Error processing arguments");
        cobj->_setParent(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TransformObject__setParent : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_TransformObject_getParent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject_getParent : Invalid Native Object");
    if (argc == 0) {
        dragonBones::Bone* ret = cobj->getParent();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Bone>(cx, (dragonBones::Bone*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TransformObject_getParent : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_TransformObject_getArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject_getArmature : Invalid Native Object");
    if (argc == 0) {
        dragonBones::Armature* ret = cobj->getArmature();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_TransformObject_getArmature : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_TransformObject_get_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject_get_name : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->name);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_TransformObject_set_name(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject_set_name : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_TransformObject_set_name : Error processing new value");
    cobj->name = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_TransformObject_get_globalTransformMatrix(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject_get_globalTransformMatrix : Invalid Native Object");

    JS::RootedValue jsret(cx);
    if (cobj->globalTransformMatrix) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Matrix>(cx, (dragonBones::Matrix*)cobj->globalTransformMatrix));
        } else {
            jsret = JSVAL_NULL;
        };
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_TransformObject_set_globalTransformMatrix(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::TransformObject* cobj = (dragonBones::TransformObject *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_TransformObject_set_globalTransformMatrix : Invalid Native Object");

    bool ok = true;
    dragonBones::Matrix* arg0 = nullptr;
    do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Matrix*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_TransformObject_set_globalTransformMatrix : Error processing new value");
    cobj->globalTransformMatrix = arg0;
    return true;
}

extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_register_cocos2dx_dragonbones_TransformObject(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_TransformObject_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_TransformObject_class->name = "TransformObject";
    jsb_dragonBones_TransformObject_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_TransformObject_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_TransformObject_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_TransformObject_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_TransformObject_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_TransformObject_class->resolve = JS_ResolveStub;
    jsb_dragonBones_TransformObject_class->convert = JS_ConvertStub;
    jsb_dragonBones_TransformObject_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("name", js_cocos2dx_dragonbones_TransformObject_get_name, js_cocos2dx_dragonbones_TransformObject_set_name, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("globalTransformMatrix", js_cocos2dx_dragonbones_TransformObject_get_globalTransformMatrix, js_cocos2dx_dragonbones_TransformObject_set_globalTransformMatrix, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("_setArmature", js_cocos2dx_dragonbones_TransformObject__setArmature, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("_setParent", js_cocos2dx_dragonbones_TransformObject__setParent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getParent", js_cocos2dx_dragonbones_TransformObject_getParent, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getArmature", js_cocos2dx_dragonbones_TransformObject_getArmature, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_TransformObject_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_TransformObject_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_TransformObject_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "TransformObject"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::TransformObject>(cx, jsb_dragonBones_TransformObject_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_Bone_class;
JSObject *jsb_dragonBones_Bone_prototype;

bool js_cocos2dx_dragonbones_Bone_getIK(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_getIK : Invalid Native Object");
    if (argc == 0) {
        dragonBones::Bone* ret = cobj->getIK();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Bone>(cx, (dragonBones::Bone*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_getIK : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_getIKChainIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_getIKChainIndex : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->getIKChainIndex();
        JS::RootedValue jsret(cx);
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_getIKChainIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_contains(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_contains : Invalid Native Object");
    if (argc == 1) {
        const dragonBones::TransformObject* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (const dragonBones::TransformObject*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Bone_contains : Error processing arguments");
        bool ret = cobj->contains(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_contains : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_getIKChain(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_getIKChain : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->getIKChain();
        JS::RootedValue jsret(cx);
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_getIKChain : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_getVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_getVisible : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->getVisible();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_getVisible : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_setVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_setVisible : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Bone_setVisible : Error processing arguments");
        cobj->setVisible(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_setVisible : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_invalidUpdate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Bone* cobj = (dragonBones::Bone *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Bone_invalidUpdate : Invalid Native Object");
    if (argc == 0) {
        cobj->invalidUpdate();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_invalidUpdate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Bone_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::Bone::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_Bone_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_Bone_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::Bone* cobj = new (std::nothrow) dragonBones::Bone();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::Bone>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::Bone"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_TransformObject_prototype;

void js_dragonBones_Bone_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Bone)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::Bone *nobj = static_cast<dragonBones::Bone *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_Bone(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_Bone_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_Bone_class->name = "Bone";
    jsb_dragonBones_Bone_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_Bone_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_Bone_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_Bone_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_Bone_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_Bone_class->resolve = JS_ResolveStub;
    jsb_dragonBones_Bone_class->convert = JS_ConvertStub;
    jsb_dragonBones_Bone_class->finalize = js_dragonBones_Bone_finalize;
    jsb_dragonBones_Bone_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getIK", js_cocos2dx_dragonbones_Bone_getIK, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getIKChainIndex", js_cocos2dx_dragonbones_Bone_getIKChainIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("contains", js_cocos2dx_dragonbones_Bone_contains, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getIKChain", js_cocos2dx_dragonbones_Bone_getIKChain, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVisible", js_cocos2dx_dragonbones_Bone_getVisible, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setVisible", js_cocos2dx_dragonbones_Bone_setVisible, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("invalidUpdate", js_cocos2dx_dragonbones_Bone_invalidUpdate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_Bone_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_TransformObject_prototype);
    jsb_dragonBones_Bone_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_Bone_class,
        js_cocos2dx_dragonbones_Bone_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_Bone_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Bone"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::Bone>(cx, jsb_dragonBones_Bone_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_Slot_class;
JSObject *jsb_dragonBones_Slot_prototype;

bool js_cocos2dx_dragonbones_Slot_getChildArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_getChildArmature : Invalid Native Object");
    if (argc == 0) {
        dragonBones::Armature* ret = cobj->getChildArmature();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Slot_getChildArmature : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Slot_invalidUpdate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_invalidUpdate : Invalid Native Object");
    if (argc == 0) {
        cobj->invalidUpdate();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Slot_invalidUpdate : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Slot_setDisplayIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_setDisplayIndex : Invalid Native Object");
    if (argc == 1) {
        int arg0 = 0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Slot_setDisplayIndex : Error processing arguments");
        cobj->setDisplayIndex(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Slot_setDisplayIndex : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Slot_setChildArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_setChildArmature : Invalid Native Object");
    if (argc == 1) {
        dragonBones::Armature* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::Armature*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Slot_setChildArmature : Error processing arguments");
        cobj->setChildArmature(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Slot_setChildArmature : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_Slot_getDisplayIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_getDisplayIndex : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->getDisplayIndex();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_Slot_getDisplayIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_Slot_get_inheritAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_get_inheritAnimation : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = BOOLEAN_TO_JSVAL(cobj->inheritAnimation);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Slot_set_inheritAnimation(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_set_inheritAnimation : Invalid Native Object");

    bool ok = true;
    bool arg0;
    arg0 = JS::ToBoolean(args.get(0));
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Slot_set_inheritAnimation : Error processing new value");
    cobj->inheritAnimation = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_Slot_get_displayController(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_get_displayController : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = std_string_to_jsval(cx, cobj->displayController);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_Slot_set_displayController(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::Slot* cobj = (dragonBones::Slot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_Slot_set_displayController : Invalid Native Object");

    bool ok = true;
    std::string arg0;
    ok &= jsval_to_std_string(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_Slot_set_displayController : Error processing new value");
    cobj->displayController = arg0;
    return true;
}

void js_register_cocos2dx_dragonbones_Slot(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_Slot_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_Slot_class->name = "Slot";
    jsb_dragonBones_Slot_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_Slot_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_Slot_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_Slot_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_Slot_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_Slot_class->resolve = JS_ResolveStub;
    jsb_dragonBones_Slot_class->convert = JS_ConvertStub;
    jsb_dragonBones_Slot_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("inheritAnimation", js_cocos2dx_dragonbones_Slot_get_inheritAnimation, js_cocos2dx_dragonbones_Slot_set_inheritAnimation, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("displayController", js_cocos2dx_dragonbones_Slot_get_displayController, js_cocos2dx_dragonbones_Slot_set_displayController, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getChildArmature", js_cocos2dx_dragonbones_Slot_getChildArmature, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("invalidUpdate", js_cocos2dx_dragonbones_Slot_invalidUpdate, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setDisplayIndex", js_cocos2dx_dragonbones_Slot_setDisplayIndex, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setChildArmature", js_cocos2dx_dragonbones_Slot_setChildArmature, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDisplayIndex", js_cocos2dx_dragonbones_Slot_getDisplayIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_dragonBones_Slot_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_Slot_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_Slot_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "Slot"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::Slot>(cx, jsb_dragonBones_Slot_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_BaseFactory_class;
JSObject *jsb_dragonBones_BaseFactory_prototype;

bool js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : Error processing arguments");
        cobj->removeDragonBonesData(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : Error processing arguments");
        cobj->removeDragonBonesData(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : Error processing arguments");
        cobj->removeTextureAtlasData(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : Error processing arguments");
        cobj->removeTextureAtlasData(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Invalid Native Object");
    if (argc == 1) {
        const char* arg0 = nullptr;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* ret = cobj->parseDragonBonesData(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::DragonBonesData>(cx, (dragonBones::DragonBonesData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        const char* arg0 = nullptr;
        std::string arg1;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* ret = cobj->parseDragonBonesData(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::DragonBonesData>(cx, (dragonBones::DragonBonesData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        const char* arg0 = nullptr;
        std::string arg1;
        double arg2 = 0;
        std::string arg0_tmp; ok &= jsval_to_std_string(cx, args.get(0), &arg0_tmp); arg0 = arg0_tmp.c_str();
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !std::isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* ret = cobj->parseDragonBonesData(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::DragonBonesData>(cx, (dragonBones::DragonBonesData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_clear(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_clear : Invalid Native Object");
    if (argc == 0) {
        cobj->clear();
        args.rval().setUndefined();
        return true;
    }
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_clear : Error processing arguments");
        cobj->clear(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_clear : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : Invalid Native Object");
    if (argc == 1) {
        dragonBones::DragonBonesData* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::DragonBonesData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : Error processing arguments");
        cobj->addDragonBonesData(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        dragonBones::DragonBonesData* arg0 = nullptr;
        std::string arg1;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::DragonBonesData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : Error processing arguments");
        cobj->addDragonBonesData(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_buildArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* ret = cobj->buildArmature(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* ret = cobj->buildArmature(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : Error processing arguments");
        dragonBones::Armature* ret = cobj->buildArmature(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_buildArmature : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : Invalid Native Object");
    if (argc == 1) {
        dragonBones::TextureAtlasData* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::TextureAtlasData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : Error processing arguments");
        cobj->addTextureAtlasData(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        dragonBones::TextureAtlasData* arg0 = nullptr;
        std::string arg1;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (dragonBones::TextureAtlasData*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : Error processing arguments");
        cobj->addTextureAtlasData(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::BaseFactory* cobj = (dragonBones::BaseFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData : Error processing arguments");
        dragonBones::DragonBonesData* ret = cobj->getDragonBonesData(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::DragonBonesData>(cx, (dragonBones::DragonBonesData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}

void js_register_cocos2dx_dragonbones_BaseFactory(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_BaseFactory_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_BaseFactory_class->name = "BaseFactory";
    jsb_dragonBones_BaseFactory_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_BaseFactory_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_BaseFactory_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_BaseFactory_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_BaseFactory_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_BaseFactory_class->resolve = JS_ResolveStub;
    jsb_dragonBones_BaseFactory_class->convert = JS_ConvertStub;
    jsb_dragonBones_BaseFactory_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("removeDragonBonesData", js_cocos2dx_dragonbones_BaseFactory_removeDragonBonesData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeTextureAtlasData", js_cocos2dx_dragonbones_BaseFactory_removeTextureAtlasData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("parseDragonBonesData", js_cocos2dx_dragonbones_BaseFactory_parseDragonBonesData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clear", js_cocos2dx_dragonbones_BaseFactory_clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addDragonBonesData", js_cocos2dx_dragonbones_BaseFactory_addDragonBonesData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("buildArmature", js_cocos2dx_dragonbones_BaseFactory_buildArmature, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addTextureAtlasData", js_cocos2dx_dragonbones_BaseFactory_addTextureAtlasData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDragonBonesData", js_cocos2dx_dragonbones_BaseFactory_getDragonBonesData, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_dragonBones_BaseFactory_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_BaseFactory_class,
        empty_constructor, 0,
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_BaseFactory_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "BaseFactory"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::BaseFactory>(cx, jsb_dragonBones_BaseFactory_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_WorldClock_class;
JSObject *jsb_dragonBones_WorldClock_prototype;

bool js_cocos2dx_dragonbones_WorldClock_clear(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_WorldClock_clear : Invalid Native Object");
    if (argc == 0) {
        cobj->clear();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_WorldClock_clear : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_WorldClock_contains(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_WorldClock_contains : Invalid Native Object");
    if (argc == 1) {
        const dragonBones::IAnimateble* arg0 = nullptr;
        do {
            if (args.get(0).isNull()) { arg0 = nullptr; break; }
            if (!args.get(0).isObject()) { ok = false; break; }
            js_proxy_t *jsProxy;
            JS::RootedObject tmpObj(cx, args.get(0).toObjectOrNull());
            jsProxy = jsb_get_js_proxy(tmpObj);
            arg0 = (const dragonBones::IAnimateble*)(jsProxy ? jsProxy->ptr : NULL);
            JSB_PRECONDITION2( arg0, cx, false, "Invalid Native Object");
        } while (0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_WorldClock_contains : Error processing arguments");
        bool ret = cobj->contains(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_WorldClock_contains : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_WorldClock_advanceTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::WorldClock* cobj = (dragonBones::WorldClock *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_WorldClock_advanceTime : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_WorldClock_advanceTime : Error processing arguments");
        cobj->advanceTime(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_WorldClock_advanceTime : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_WorldClock_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::WorldClock* cobj = new (std::nothrow) dragonBones::WorldClock();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::WorldClock>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::WorldClock"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


void js_dragonBones_WorldClock_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (WorldClock)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::WorldClock *nobj = static_cast<dragonBones::WorldClock *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_WorldClock(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_WorldClock_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_WorldClock_class->name = "WorldClock";
    jsb_dragonBones_WorldClock_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_WorldClock_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_WorldClock_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_WorldClock_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_WorldClock_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_WorldClock_class->resolve = JS_ResolveStub;
    jsb_dragonBones_WorldClock_class->convert = JS_ConvertStub;
    jsb_dragonBones_WorldClock_class->finalize = js_dragonBones_WorldClock_finalize;
    jsb_dragonBones_WorldClock_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("clear", js_cocos2dx_dragonbones_WorldClock_clear, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("contains", js_cocos2dx_dragonbones_WorldClock_contains, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("advanceTime", js_cocos2dx_dragonbones_WorldClock_advanceTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    jsb_dragonBones_WorldClock_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(),
        jsb_dragonBones_WorldClock_class,
        js_cocos2dx_dragonbones_WorldClock_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_WorldClock_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "WorldClock"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::WorldClock>(cx, jsb_dragonBones_WorldClock_class, proto, JS::NullPtr());
}

JSClass  *jsb_dragonBones_AnimationState_class;
JSObject *jsb_dragonBones_AnimationState_prototype;

bool js_cocos2dx_dragonbones_AnimationState_setCurrentTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_setCurrentTime : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_setCurrentTime : Error processing arguments");
        cobj->setCurrentTime(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_setCurrentTime : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_removeBoneMask(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : Error processing arguments");
        cobj->removeBoneMask(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : Error processing arguments");
        cobj->removeBoneMask(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_removeBoneMask : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getGroup(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_getGroup : Invalid Native Object");
    if (argc == 0) {
        const std::string& ret = cobj->getGroup();
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getGroup : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes : Invalid Native Object");
    if (argc == 0) {
        unsigned int ret = cobj->getCurrentPlayTimes();
        JS::RootedValue jsret(cx);
        jsret = uint32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_getName : Invalid Native Object");
    if (argc == 0) {
        const std::string& ret = cobj->getName();
        JS::RootedValue jsret(cx);
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getName : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getCurrentTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_getCurrentTime : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->getCurrentTime();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getCurrentTime : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getTotalTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_getTotalTime : Invalid Native Object");
    if (argc == 0) {
        double ret = cobj->getTotalTime();
        JS::RootedValue jsret(cx);
        jsret = DOUBLE_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getTotalTime : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask : Invalid Native Object");
    if (argc == 0) {
        cobj->removeAllBoneMask();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getLayer(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_getLayer : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->getLayer();
        JS::RootedValue jsret(cx);
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getLayer : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_isCompleted(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_isCompleted : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isCompleted();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_isCompleted : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_play(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_play : Invalid Native Object");
    if (argc == 0) {
        cobj->play();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_play : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_fadeOut(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_fadeOut : Invalid Native Object");
    if (argc == 1) {
        double arg0 = 0;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_fadeOut : Error processing arguments");
        cobj->fadeOut(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        double arg0 = 0;
        bool arg1;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_fadeOut : Error processing arguments");
        cobj->fadeOut(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_fadeOut : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_stop(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_stop : Invalid Native Object");
    if (argc == 0) {
        cobj->stop();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_stop : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_isPlaying(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_isPlaying : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isPlaying();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_isPlaying : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_addBoneMask(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : Error processing arguments");
        cobj->addBoneMask(arg0);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        bool arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        arg1 = JS::ToBoolean(args.get(1));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : Error processing arguments");
        cobj->addBoneMask(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_addBoneMask : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_containsBoneMask(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_containsBoneMask : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_containsBoneMask : Error processing arguments");
        bool ret = cobj->containsBoneMask(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_containsBoneMask : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_AnimationState_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::AnimationState::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_AnimationState_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_AnimationState_get_displayControl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_displayControl : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = BOOLEAN_TO_JSVAL(cobj->displayControl);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_displayControl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_displayControl : Invalid Native Object");

    bool ok = true;
    bool arg0;
    arg0 = JS::ToBoolean(args.get(0));
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_displayControl : Error processing new value");
    cobj->displayControl = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_get_additiveBlending(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_additiveBlending : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = BOOLEAN_TO_JSVAL(cobj->additiveBlending);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_additiveBlending(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_additiveBlending : Invalid Native Object");

    bool ok = true;
    bool arg0;
    arg0 = JS::ToBoolean(args.get(0));
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_additiveBlending : Error processing new value");
    cobj->additiveBlending = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_get_playTimes(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_playTimes : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = uint32_to_jsval(cx, cobj->playTimes);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_playTimes(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_playTimes : Invalid Native Object");

    bool ok = true;
    unsigned int arg0 = 0;
    ok &= jsval_to_uint32(cx, args.get(0), &arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_playTimes : Error processing new value");
    cobj->playTimes = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_get_timeScale(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_timeScale : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->timeScale);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_timeScale(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_timeScale : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_timeScale : Error processing new value");
    cobj->timeScale = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_get_weight(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_weight : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->weight);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_weight(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_weight : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_weight : Error processing new value");
    cobj->weight = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->autoFadeOutTime);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime : Error processing new value");
    cobj->autoFadeOutTime = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime : Invalid Native Object");

    JS::RootedValue jsret(cx);
    jsret = DOUBLE_TO_JSVAL(cobj->fadeTotalTime);
    args.rval().set(jsret);
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject jsthis(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(jsthis);
    dragonBones::AnimationState* cobj = (dragonBones::AnimationState *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime : Invalid Native Object");

    bool ok = true;
    double arg0 = 0;
    ok &= JS::ToNumber( cx, args.get(0), &arg0) && !std::isnan(arg0);
    JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime : Error processing new value");
    cobj->fadeTotalTime = arg0;
    return true;
}
bool js_cocos2dx_dragonbones_AnimationState_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::AnimationState* cobj = new (std::nothrow) dragonBones::AnimationState();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::AnimationState>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::AnimationState"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseObject_prototype;

void js_dragonBones_AnimationState_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (AnimationState)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::AnimationState *nobj = static_cast<dragonBones::AnimationState *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_AnimationState(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_AnimationState_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_AnimationState_class->name = "AnimationState";
    jsb_dragonBones_AnimationState_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_AnimationState_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_AnimationState_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_AnimationState_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_AnimationState_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_AnimationState_class->resolve = JS_ResolveStub;
    jsb_dragonBones_AnimationState_class->convert = JS_ConvertStub;
    jsb_dragonBones_AnimationState_class->finalize = js_dragonBones_AnimationState_finalize;
    jsb_dragonBones_AnimationState_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSGS("displayControl", js_cocos2dx_dragonbones_AnimationState_get_displayControl, js_cocos2dx_dragonbones_AnimationState_set_displayControl, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("additiveBlending", js_cocos2dx_dragonbones_AnimationState_get_additiveBlending, js_cocos2dx_dragonbones_AnimationState_set_additiveBlending, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("playTimes", js_cocos2dx_dragonbones_AnimationState_get_playTimes, js_cocos2dx_dragonbones_AnimationState_set_playTimes, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("timeScale", js_cocos2dx_dragonbones_AnimationState_get_timeScale, js_cocos2dx_dragonbones_AnimationState_set_timeScale, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("weight", js_cocos2dx_dragonbones_AnimationState_get_weight, js_cocos2dx_dragonbones_AnimationState_set_weight, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("autoFadeOutTime", js_cocos2dx_dragonbones_AnimationState_get_autoFadeOutTime, js_cocos2dx_dragonbones_AnimationState_set_autoFadeOutTime, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PSGS("fadeTotalTime", js_cocos2dx_dragonbones_AnimationState_get_fadeTotalTime, js_cocos2dx_dragonbones_AnimationState_set_fadeTotalTime, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("setCurrentTime", js_cocos2dx_dragonbones_AnimationState_setCurrentTime, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeBoneMask", js_cocos2dx_dragonbones_AnimationState_removeBoneMask, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getGroup", js_cocos2dx_dragonbones_AnimationState_getGroup, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCurrentPlayTimes", js_cocos2dx_dragonbones_AnimationState_getCurrentPlayTimes, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getName", js_cocos2dx_dragonbones_AnimationState_getName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCurrentTime", js_cocos2dx_dragonbones_AnimationState_getCurrentTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getTotalTime", js_cocos2dx_dragonbones_AnimationState_getTotalTime, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeAllBoneMask", js_cocos2dx_dragonbones_AnimationState_removeAllBoneMask, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getLayer", js_cocos2dx_dragonbones_AnimationState_getLayer, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isCompleted", js_cocos2dx_dragonbones_AnimationState_isCompleted, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("play", js_cocos2dx_dragonbones_AnimationState_play, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fadeOut", js_cocos2dx_dragonbones_AnimationState_fadeOut, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("stop", js_cocos2dx_dragonbones_AnimationState_stop, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isPlaying", js_cocos2dx_dragonbones_AnimationState_isPlaying, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addBoneMask", js_cocos2dx_dragonbones_AnimationState_addBoneMask, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("containsBoneMask", js_cocos2dx_dragonbones_AnimationState_containsBoneMask, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_AnimationState_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseObject_prototype);
    jsb_dragonBones_AnimationState_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_AnimationState_class,
        js_cocos2dx_dragonbones_AnimationState_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_AnimationState_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "AnimationState"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::AnimationState>(cx, jsb_dragonBones_AnimationState_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_CCTextureData_class;
JSObject *jsb_dragonBones_CCTextureData_prototype;

bool js_cocos2dx_dragonbones_CCTextureData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::CCTextureData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCTextureData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_CCTextureData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::CCTextureData* cobj = new (std::nothrow) dragonBones::CCTextureData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::CCTextureData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::CCTextureData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_TextureData_prototype;

void js_dragonBones_CCTextureData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCTextureData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::CCTextureData *nobj = static_cast<dragonBones::CCTextureData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_CCTextureData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_CCTextureData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_CCTextureData_class->name = "CCTextureData";
    jsb_dragonBones_CCTextureData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_CCTextureData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_CCTextureData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_CCTextureData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_CCTextureData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_CCTextureData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_CCTextureData_class->convert = JS_ConvertStub;
    jsb_dragonBones_CCTextureData_class->finalize = js_dragonBones_CCTextureData_finalize;
    jsb_dragonBones_CCTextureData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_CCTextureData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_TextureData_prototype);
    jsb_dragonBones_CCTextureData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_CCTextureData_class,
        js_cocos2dx_dragonbones_CCTextureData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_CCTextureData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "CCTextureData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::CCTextureData>(cx, jsb_dragonBones_CCTextureData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_CCTextureAtlasData_class;
JSObject *jsb_dragonBones_CCTextureAtlasData_prototype;

bool js_cocos2dx_dragonbones_CCTextureAtlasData_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::CCTextureAtlasData::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCTextureAtlasData_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_CCTextureAtlasData_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::CCTextureAtlasData* cobj = new (std::nothrow) dragonBones::CCTextureAtlasData();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::CCTextureAtlasData>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::CCTextureAtlasData"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_TextureAtlasData_prototype;

void js_dragonBones_CCTextureAtlasData_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCTextureAtlasData)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::CCTextureAtlasData *nobj = static_cast<dragonBones::CCTextureAtlasData *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_CCTextureAtlasData(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_CCTextureAtlasData_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_CCTextureAtlasData_class->name = "CCTextureAtlasData";
    jsb_dragonBones_CCTextureAtlasData_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_CCTextureAtlasData_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_CCTextureAtlasData_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_CCTextureAtlasData_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_CCTextureAtlasData_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_CCTextureAtlasData_class->resolve = JS_ResolveStub;
    jsb_dragonBones_CCTextureAtlasData_class->convert = JS_ConvertStub;
    jsb_dragonBones_CCTextureAtlasData_class->finalize = js_dragonBones_CCTextureAtlasData_finalize;
    jsb_dragonBones_CCTextureAtlasData_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_CCTextureAtlasData_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_TextureAtlasData_prototype);
    jsb_dragonBones_CCTextureAtlasData_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_CCTextureAtlasData_class,
        js_cocos2dx_dragonbones_CCTextureAtlasData_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_CCTextureAtlasData_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "CCTextureAtlasData"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::CCTextureAtlasData>(cx, jsb_dragonBones_CCTextureAtlasData_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_CCArmatureDisplay_class;
JSObject *jsb_dragonBones_CCArmatureDisplay_prototype;

bool js_cocos2dx_dragonbones_CCArmatureDisplay_advanceTimeBySelf(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_advanceTimeBySelf : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_advanceTimeBySelf : Error processing arguments");
        cobj->advanceTimeBySelf(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_advanceTimeBySelf : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_removeEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_removeEvent : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_removeEvent : Error processing arguments");
        cobj->removeEvent(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_removeEvent : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_dispose(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_dispose : Invalid Native Object");
    if (argc == 0) {
        cobj->dispose();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_dispose : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_hasEventCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasEventCallback : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->hasEventCallback();
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasEventCallback : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_setEventCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setEventCallback : Invalid Native Object");
    if (argc == 1) {
        std::function<void (dragonBones::EventObject *)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx);
		        if (args.thisv().isObject())
		        {
		            jstarget = args.thisv().toObjectOrNull();
		        }
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(0), args.thisv()));
		        auto lambda = [=](dragonBones::EventObject* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            if (larg0) {
		            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::EventObject>(cx, (dragonBones::EventObject*)larg0));
		        } else {
		            largv[0] = JSVAL_NULL;
		        };
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(JS::HandleValueArray::fromMarkedLocation(1, largv), &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_setEventCallback : Error processing arguments");
        cobj->setEventCallback(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_setEventCallback : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_clearEventCallback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_clearEventCallback : Invalid Native Object");
    if (argc == 0) {
        cobj->clearEventCallback();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_clearEventCallback : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_addEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_addEvent : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::function<void (dragonBones::EventObject *)> arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        JS::RootedObject jstarget(cx);
		        if (args.thisv().isObject())
		        {
		            jstarget = args.thisv().toObjectOrNull();
		        }
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, jstarget, args.get(1), args.thisv()));
		        auto lambda = [=](dragonBones::EventObject* larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            if (larg0) {
		            largv[0] = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::EventObject>(cx, (dragonBones::EventObject*)larg0));
		        } else {
		            largv[0] = JSVAL_NULL;
		        };
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(JS::HandleValueArray::fromMarkedLocation(1, largv), &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_addEvent : Error processing arguments");
        cobj->addEvent(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_addEvent : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_hasEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasEvent : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasEvent : Error processing arguments");
        bool ret = cobj->hasEvent(arg0);
        JS::RootedValue jsret(cx);
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_hasEvent : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCArmatureDisplay* cobj = (dragonBones::CCArmatureDisplay *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature : Invalid Native Object");
    if (argc == 0) {
        dragonBones::Armature* ret = cobj->getArmature();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::Armature>(cx, (dragonBones::Armature*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_CCArmatureDisplay_create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        auto ret = dragonBones::CCArmatureDisplay::create();
        js_type_class_t *typeClass = js_get_type_from_native<dragonBones::CCArmatureDisplay>(ret);
        JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "dragonBones::CCArmatureDisplay"));
        args.rval().set(OBJECT_TO_JSVAL(jsret));
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCArmatureDisplay_create : wrong number of arguments");
    return false;
}


extern JSObject *jsb_cocos2d_Node_prototype;

void js_register_cocos2dx_dragonbones_CCArmatureDisplay(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_CCArmatureDisplay_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_CCArmatureDisplay_class->name = "CCArmatureDisplay";
    jsb_dragonBones_CCArmatureDisplay_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_CCArmatureDisplay_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_CCArmatureDisplay_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_CCArmatureDisplay_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_CCArmatureDisplay_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_CCArmatureDisplay_class->resolve = JS_ResolveStub;
    jsb_dragonBones_CCArmatureDisplay_class->convert = JS_ConvertStub;
    jsb_dragonBones_CCArmatureDisplay_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("advanceTimeBySelf", js_cocos2dx_dragonbones_CCArmatureDisplay_advanceTimeBySelf, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("removeEventListener", js_cocos2dx_dragonbones_CCArmatureDisplay_removeEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("dispose", js_cocos2dx_dragonbones_CCArmatureDisplay_dispose, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hasEventCallback", js_cocos2dx_dragonbones_CCArmatureDisplay_hasEventCallback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setEventCallback", js_cocos2dx_dragonbones_CCArmatureDisplay_setEventCallback, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("clearEventCallback", js_cocos2dx_dragonbones_CCArmatureDisplay_clearEventCallback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("addEventListener", js_cocos2dx_dragonbones_CCArmatureDisplay_addEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hasEvent", js_cocos2dx_dragonbones_CCArmatureDisplay_hasEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("armature", js_cocos2dx_dragonbones_CCArmatureDisplay_getArmature, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_cocos2dx_dragonbones_CCArmatureDisplay_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_cocos2d_Node_prototype);
    jsb_dragonBones_CCArmatureDisplay_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_CCArmatureDisplay_class,
        dummy_constructor<dragonBones::CCArmatureDisplay>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_CCArmatureDisplay_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "CCArmatureDisplay"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::CCArmatureDisplay>(cx, jsb_dragonBones_CCArmatureDisplay_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_DBCCSprite_class;
JSObject *jsb_dragonBones_DBCCSprite_prototype;

bool js_cocos2dx_dragonbones_DBCCSprite_create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        auto ret = dragonBones::DBCCSprite::create();
        js_type_class_t *typeClass = js_get_type_from_native<dragonBones::DBCCSprite>(ret);
        JS::RootedObject jsret(cx, jsb_ref_autoreleased_create_jsobject(cx, ret, typeClass, "dragonBones::DBCCSprite"));
        args.rval().set(OBJECT_TO_JSVAL(jsret));
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_DBCCSprite_create : wrong number of arguments");
    return false;
}


extern JSObject *jsb_cocos2d_Sprite_prototype;

void js_register_cocos2dx_dragonbones_DBCCSprite(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_DBCCSprite_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_DBCCSprite_class->name = "DBCCSprite";
    jsb_dragonBones_DBCCSprite_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_DBCCSprite_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_DBCCSprite_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_DBCCSprite_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_DBCCSprite_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_DBCCSprite_class->resolve = JS_ResolveStub;
    jsb_dragonBones_DBCCSprite_class->convert = JS_ConvertStub;
    jsb_dragonBones_DBCCSprite_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("create", js_cocos2dx_dragonbones_DBCCSprite_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_cocos2d_Sprite_prototype);
    jsb_dragonBones_DBCCSprite_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_DBCCSprite_class,
        dummy_constructor<dragonBones::DBCCSprite>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_DBCCSprite_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "DBCCSprite"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::TrueHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::DBCCSprite>(cx, jsb_dragonBones_DBCCSprite_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_CCSlot_class;
JSObject *jsb_dragonBones_CCSlot_prototype;

bool js_cocos2dx_dragonbones_CCSlot_getClassTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCSlot* cobj = (dragonBones::CCSlot *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCSlot_getClassTypeIndex : Invalid Native Object");
    if (argc == 0) {
        unsigned long ret = cobj->getClassTypeIndex();
        JS::RootedValue jsret(cx);
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCSlot_getClassTypeIndex : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_CCSlot_getTypeIndex(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {

        unsigned long ret = dragonBones::CCSlot::getTypeIndex();
        jsval jsret = JSVAL_NULL;
        jsret = ulong_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCSlot_getTypeIndex : wrong number of arguments");
    return false;
}

bool js_cocos2dx_dragonbones_CCSlot_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::CCSlot* cobj = new (std::nothrow) dragonBones::CCSlot();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::CCSlot>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::CCSlot"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_Slot_prototype;

void js_dragonBones_CCSlot_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCSlot)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::CCSlot *nobj = static_cast<dragonBones::CCSlot *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_CCSlot(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_CCSlot_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_CCSlot_class->name = "CCSlot";
    jsb_dragonBones_CCSlot_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_CCSlot_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_CCSlot_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_CCSlot_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_CCSlot_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_CCSlot_class->resolve = JS_ResolveStub;
    jsb_dragonBones_CCSlot_class->convert = JS_ConvertStub;
    jsb_dragonBones_CCSlot_class->finalize = js_dragonBones_CCSlot_finalize;
    jsb_dragonBones_CCSlot_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getClassTypeIndex", js_cocos2dx_dragonbones_CCSlot_getClassTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getTypeIndex", js_cocos2dx_dragonbones_CCSlot_getTypeIndex, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, jsb_dragonBones_Slot_prototype);
    jsb_dragonBones_CCSlot_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_CCSlot_class,
        js_cocos2dx_dragonbones_CCSlot_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_CCSlot_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "CCSlot"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::CCSlot>(cx, jsb_dragonBones_CCSlot_class, proto, parent_proto);
}

JSClass  *jsb_dragonBones_CCFactory_class;
JSObject *jsb_dragonBones_CCFactory_prototype;

bool js_cocos2dx_dragonbones_CCFactory_getTextureDisplay(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCFactory_getTextureDisplay : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_getTextureDisplay : Error processing arguments");
        cocos2d::Sprite* ret = cobj->getTextureDisplay(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_getTextureDisplay : Error processing arguments");
        cocos2d::Sprite* ret = cobj->getTextureDisplay(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<cocos2d::Sprite>(cx, (cocos2d::Sprite*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCFactory_getTextureDisplay : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_CCFactory_getSoundEventManater(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCFactory_getSoundEventManater : Invalid Native Object");
    if (argc == 0) {
        dragonBones::CCArmatureDisplay* ret = cobj->getSoundEventManater();
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::CCArmatureDisplay>(cx, (dragonBones::CCArmatureDisplay*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCFactory_getSoundEventManater : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* ret = cobj->buildArmatureDisplay(arg0);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::CCArmatureDisplay>(cx, (dragonBones::CCArmatureDisplay*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* ret = cobj->buildArmatureDisplay(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::CCArmatureDisplay>(cx, (dragonBones::CCArmatureDisplay*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : Error processing arguments");
        dragonBones::CCArmatureDisplay* ret = cobj->buildArmatureDisplay(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::CCArmatureDisplay>(cx, (dragonBones::CCArmatureDisplay*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    dragonBones::CCFactory* cobj = (dragonBones::CCFactory *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData : Error processing arguments");
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::TextureAtlasData>(cx, (dragonBones::TextureAtlasData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData : Error processing arguments");
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1, arg2);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::TextureAtlasData>(cx, (dragonBones::TextureAtlasData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }
    if (argc == 4) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        double arg3 = 0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= JS::ToNumber( cx, args.get(3), &arg3) && !std::isnan(arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData : Error processing arguments");
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1, arg2, arg3);
        JS::RootedValue jsret(cx);
        if (ret) {
            jsret = OBJECT_TO_JSVAL(js_get_or_create_jsobject<dragonBones::TextureAtlasData>(cx, (dragonBones::TextureAtlasData*)ret));
        } else {
            jsret = JSVAL_NULL;
        };
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_dragonbones_CCFactory_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    dragonBones::CCFactory* cobj = new (std::nothrow) dragonBones::CCFactory();

    js_type_class_t *typeClass = js_get_type_from_native<dragonBones::CCFactory>(cobj);

    // link the native object with the javascript object
    JS::RootedObject jsobj(cx, jsb_create_weak_jsobject(cx, cobj, typeClass, "dragonBones::CCFactory"));
    args.rval().set(OBJECT_TO_JSVAL(jsobj));
    if (JS_HasProperty(cx, jsobj, "_ctor", &ok) && ok)
        ScriptingCore::getInstance()->executeFunctionWithOwner(OBJECT_TO_JSVAL(jsobj), "_ctor", args);
    return true;
}


extern JSObject *jsb_dragonBones_BaseFactory_prototype;

void js_dragonBones_CCFactory_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (CCFactory)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
    if (jsproxy) {
        dragonBones::CCFactory *nobj = static_cast<dragonBones::CCFactory *>(jsproxy->ptr);
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
void js_register_cocos2dx_dragonbones_CCFactory(JSContext *cx, JS::HandleObject global) {
    jsb_dragonBones_CCFactory_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_dragonBones_CCFactory_class->name = "CCFactory";
    jsb_dragonBones_CCFactory_class->addProperty = JS_PropertyStub;
    jsb_dragonBones_CCFactory_class->delProperty = JS_DeletePropertyStub;
    jsb_dragonBones_CCFactory_class->getProperty = JS_PropertyStub;
    jsb_dragonBones_CCFactory_class->setProperty = JS_StrictPropertyStub;
    jsb_dragonBones_CCFactory_class->enumerate = JS_EnumerateStub;
    jsb_dragonBones_CCFactory_class->resolve = JS_ResolveStub;
    jsb_dragonBones_CCFactory_class->convert = JS_ConvertStub;
    jsb_dragonBones_CCFactory_class->finalize = js_dragonBones_CCFactory_finalize;
    jsb_dragonBones_CCFactory_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getTextureDisplay", js_cocos2dx_dragonbones_CCFactory_getTextureDisplay, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSoundEventManater", js_cocos2dx_dragonbones_CCFactory_getSoundEventManater, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("buildArmatureDisplay", js_cocos2dx_dragonbones_CCFactory_buildArmatureDisplay, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("parseTextureAtlasData", js_cocos2dx_dragonbones_CCFactory_parseTextureAtlasData, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JSFunctionSpec *st_funcs = NULL;

    JS::RootedObject parent_proto(cx, jsb_dragonBones_BaseFactory_prototype);
    jsb_dragonBones_CCFactory_prototype = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_dragonBones_CCFactory_class,
        js_cocos2dx_dragonbones_CCFactory_constructor, 0, // constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, jsb_dragonBones_CCFactory_prototype);
    JS::RootedValue className(cx, std_string_to_jsval(cx, "CCFactory"));
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
    // add the proto and JSClass to the type->js info hash table
    jsb_register_class<dragonBones::CCFactory>(cx, jsb_dragonBones_CCFactory_class, proto, parent_proto);
}

void register_all_cocos2dx_dragonbones(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "dragonBones", &ns);

    js_register_cocos2dx_dragonbones_Slot(cx, ns);
    js_register_cocos2dx_dragonbones_Matrix(cx, ns);
    js_register_cocos2dx_dragonbones_Transform(cx, ns);
    js_register_cocos2dx_dragonbones_BaseObject(cx, ns);
    js_register_cocos2dx_dragonbones_Animation(cx, ns);
    js_register_cocos2dx_dragonbones_TextureData(cx, ns);
    js_register_cocos2dx_dragonbones_CCTextureData(cx, ns);
    js_register_cocos2dx_dragonbones_BaseFactory(cx, ns);
    js_register_cocos2dx_dragonbones_CCFactory(cx, ns);
    js_register_cocos2dx_dragonbones_WorldClock(cx, ns);
    js_register_cocos2dx_dragonbones_DBCCSprite(cx, ns);
    js_register_cocos2dx_dragonbones_TextureAtlasData(cx, ns);
    js_register_cocos2dx_dragonbones_CCArmatureDisplay(cx, ns);
    js_register_cocos2dx_dragonbones_AnimationState(cx, ns);
    js_register_cocos2dx_dragonbones_BoneData(cx, ns);
    js_register_cocos2dx_dragonbones_ArmatureData(cx, ns);
    js_register_cocos2dx_dragonbones_CCTextureAtlasData(cx, ns);
    js_register_cocos2dx_dragonbones_TransformObject(cx, ns);
    js_register_cocos2dx_dragonbones_CCSlot(cx, ns);
    js_register_cocos2dx_dragonbones_Armature(cx, ns);
    js_register_cocos2dx_dragonbones_Bone(cx, ns);
    js_register_cocos2dx_dragonbones_SkinData(cx, ns);
    js_register_cocos2dx_dragonbones_EventObject(cx, ns);
    js_register_cocos2dx_dragonbones_SlotData(cx, ns);
    js_register_cocos2dx_dragonbones_DragonBonesData(cx, ns);
    js_register_cocos2dx_dragonbones_AnimationData(cx, ns);
}

