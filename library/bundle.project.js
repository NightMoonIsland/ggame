require=(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({"NewScript":[function(require,module,exports){
"use strict";
cc._RF.push(module, '66ecczZ5uZBOKLErqXnkGfn', 'NewScript');
// resources/modules/NewScript.js

"use strict";

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
    },

    // use this for initialization
    onLoad: function onLoad() {}

});

cc._RF.pop();
},{}],"appStart":[function(require,module,exports){
"use strict";
cc._RF.push(module, '03b75uMHVBKJaVXnZ7kKcue', 'appStart');
// script/appStart.js

"use strict";

var _typeof = typeof Symbol === "function" && typeof Symbol.iterator === "symbol" ? function (obj) { return typeof obj; } : function (obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; };

function init() {
    cc.tool = {};
    var viewManager = require("viewManager");
    cc.tool.viewManager = new viewManager();
    cc.tool.viewManager.init();

    require("viewRegister");

    var eventManager = require("eventManager");
    cc.tool.eventManager = new eventManager();

    cc.tool.Lang = require("langZh");
    console.log(cc.tool.Lang["ITEM_VALUE"]);
    // cc.tool.viewManager.registView("hahaha", "hehehe", "hihihi");

    var haha = [];
    for (i = 0; i < 5; i++) {
        haha[i] = i;
    }
    console.log(haha.length);
    delete haha[2];
    for (i = 0; i < 5; i++) {
        console.log(_typeof(haha[i]));
    }

    var array = require("array1");
    var test = new array();
    test.outPut();
    for (i = 0; i < 5; i++) {
        test.pushBack(i + 100);
    }
    test.outPut();
    test.remove(2);
    test.outPut();

    // cc.variable = {};
    // var array1 = require("array1");
    // cc.variable.viewList = new array1();
}

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
        haha: []
    },

    // use this for initialization
    onLoad: function onLoad() {
        console.log("hahahahhsfassaga");
        init();
        this.initScene();
    },

    initScene: function initScene() {
        // cc.tool.viewManager.setRoot(this.node);
        // cc.tool.viewManager.changeView("hahhahahaa");
        console.log("test type" + _typeof(this.haha["wocao"]));
    },

    testRemove: function testRemove() {
        var test = require("eventManager");
        var haha = new test();
        haha.init();
        cc.tool.viewManager.curView();
        // var test = require("eventManager")
        // var haha = new test();
    }

});

cc._RF.pop();
},{"array1":"array1","eventManager":"eventManager","langZh":"langZh","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'fb6a6Ja9dNOP5bnlzovehME', 'array1');
// script/library/array1.js

"use strict";

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
        list: [],
        size: 0,
        npos: -1
    },
    // use this for initialization
    onLoad: function onLoad() {
        console.log("worked");
    },

    asfdfsdf: function asfdfsdf() {
        console.log("wocao");
        // console.log(typeof this.list);
        console.log("wocao");
    },

    status: function status() {
        console.log("self.size1");
        console.log(this.size);
        console.log("self.size2");
    },
    //
    pushBack: function pushBack(data) {
        this.list[this.size] = data;
        this.size = this.size + 1;
    },

    at: function at(idx) {
        return this.list[idx];
    },

    find: function find(value) {
        var index = this.npos;
        if (typeof value == "function") {
            for (i = 0; i < this.size; i++) {
                if (value(i)) return i;
            }
        } else {
            for (i = 0; i < this.size; i++) {
                if (this.list[i] == value) {
                    index = i;
                    break;
                }
            }
        }
        return index;
    },

    remove: function remove(pos, len) {
        if (pos < 0) pos = 0;
        if (len == null || len <= 0) {
            len = 1;
        }
        if (pos < this.size) {
            if (pos + len > this.size) len = this.size - pos;
            for (i = 0; i < len; i++) {
                delete this.list[pos + i];
            }for (i = pos + len; i < this.size; i++) {
                this.list[i - len] = this.list[i];
            }this.size = this.size - len;
        }
    },

    clear: function clear() {
        for (i = 0; i < this.size; i++) {
            delete this.list[i];
        }this.size = 0;
    },

    getSize: function getSize() {
        return this.size;
    },

    empty: function empty() {
        return this.size == 0;
    },

    outPut: function outPut() {
        for (i = 0; i < this.size; i++) {
            console.log("element" + i + " = " + this.list[i]);
        }console.log("element size = " + this.size);
    }

});

cc._RF.pop();
},{}],"eventManager":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'd1f6dFgNUNJ2qEv4IU6z1q+', 'eventManager');
// script/tool/eventManager.js

"use strict";

var test = require("test");

cc.Class({
    extends: test,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
        eventListener: []
    },

    // use this for initialization
    onLoad: function onLoad() {},

    init: function init() {
        this.super.testWork();
    },

    testWork: function testWork() {
        console.log("zenme hui zheyang");
    },

    addEventListener: function addEventListener(eventType, target, func) {
        // console.log()
        if (!target || !func) return;
        if (!this.eventListener[eventType]) {
            this.eventListener[eventType] = [];
        }
        this.eventListener[eventType][target] = func;
    },

    testWorkListener: function testWorkListener() {
        console.log("to test listener");
        for (var key in this.eventListener["hahaha"]) {
            var func = this.eventListener["hahaha"][key];
            func("hahaha");
        }
    },

    dispatchEventListener: function dispatchEventListener(eventType) {
        for (var key in this.eventListener[eventType]) {
            var func = this.eventListener[eventType][key];
            func(eventType);
        }
    }

});

cc._RF.pop();
},{"test":"test"}],"langZh":[function(require,module,exports){
"use strict";
cc._RF.push(module, '269e1Js5atI95Fh+ZKOp1kb', 'langZh');
// script/config/langZh.js

"use strict";

var Lang = [];
Lang["ITEM_VALUE"] = "变成中文的情况";

module.exports = Lang;

cc._RF.pop();
},{}],"listView":[function(require,module,exports){
"use strict";
cc._RF.push(module, '1ec29WNfkpI+78K3dmtU6fy', 'listView');
// script/control/listView.js

"use strict";

cc.Class({
    extends: cc.Layout,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
    },

    create: function create() {},

    ctor: function ctor() {
        console.log(this.width + " wocao " + this.height);
    },

    // use this for initialization
    onLoad: function onLoad() {}

});

cc._RF.pop();
},{}],"test":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'e33a41uOXlOfJsTpPUw9HAm', 'test');
// script/tool/test.js

"use strict";

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
    },

    // use this for initialization
    onLoad: function onLoad() {},

    testWork: function testWork() {
        console.log("wocao nimabi");
    }

});

cc._RF.pop();
},{}],"timeHandler":[function(require,module,exports){
"use strict";
cc._RF.push(module, '977ccDhLh1BToFB9khDpdNi', 'timeHandler');
// script/process/timeHandler.js

"use strict";

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
    },

    // use this for initialization
    onLoad: function onLoad() {}

});

cc._RF.pop();
},{}],"viewManager":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'c2b58Q1/V5Ip4c2V3uuBiR6', 'viewManager');
// script/tool/viewManager.js

"use strict";

cc.Class({
    // extends: cc.Component,

    properties: {
        // foo: {
        //    default: null,      // The default value will be used only when the component attaching
        //                           to a node for the first time
        //    url: cc.Texture2D,  // optional, default is typeof default
        //    serializable: true, // optional, default is true
        //    visible: true,      // optional, default is true
        //    displayName: 'Foo', // optional
        //    readonly: false,    // optional, default is false
        // },
        // ...
        viewList: null,
        viewInfo: [],
        view: null
    },

    ctor: function ctor() {
        console.log("hhhehehe");
        var array1 = require("array1");
        this.viewList = new array1();
        // this.array1 = new require("array1");
        this.viewList.status();
        this.viewList.pushBack({ a: 1, b: 2 });
        this.viewList.status();
    },

    setRoot: function setRoot(node) {
        this.root = node;
    },

    // use this for initialization
    onLoad: function onLoad() {
        // console.log("hahahahha");

        // cc.variable.viewInfo.asfdfsdf();
        // console.log(typeof this.viewName);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    init: function init() {
        this.viewInfo = [];
        console.log("to this 1");
        this.viewInfo["haha"] = { a: 1, b: 2 };
        console.log("to this 2");
    },

    registView: function registView(viewName, module, title) {
        this.viewInfo[viewName] = { viewName: viewName, module: module, title: title };

        var viewInfo = this.viewInfo[viewName];
        this.viewInfo[0] = "hahah";
        this.viewInfo[1] = "wocao";
        console.log(viewInfo);
        console.log(this.viewInfo.length);
    },


    changeView: function changeView(viewName) {
        if (!this.viewList.empty() && this.viewList.back() == viewName) {
            console.log("view is same");
            return this.view;
        }

        var viewInfo = this.viewInfo[viewName];

        if (this.view != null) {
            this.view.removeFromParent();
        }

        var idx = this.viewList.find(viewName);
        if (idx != this.viewList.npos) {
            var len = this.viewList.getSize() - idx;
            this.viewList.remove(idx, len);
        } else {
            this.viewList.pushBack(viewName);
        }
        var self = this;
        //通过链接 加载的资源 必须放在resource下
        cc.loader.loadRes("prefab/Test1Panel", function (err, prefab) {
            var root = cc.instantiate(prefab);
            self.view = root;
            cc.director.getScene().getChildByName("Canvas").addChild(root);
        });

        return this.view;
    },

    curView: function curView() {
        // this.testAddChild();
        var self = this;
        cc.tool.eventManager.addEventListener("hahaha", self, self.testAddChild);
        cc.tool.eventManager.testWorkListener();
        this.view.removeFromParent(false);
        cc.loader.releaseRes("prefab/Test1Panel");
    },

    testAddChild: function testAddChild(varName) {
        if (varName == "hahaha") {
            console.log("wocao tamabi");
        } else if (varName = "wocaonima") {
            console.log("??? wodetian");
        }
    },

    backPreview: function backPreview() {}
});

cc._RF.pop();
},{"array1":"array1"}],"viewRegister":[function(require,module,exports){
"use strict";
cc._RF.push(module, '8f625ZW1F9O2ZNLWZmuFA5B', 'viewRegister');
// script/tool/viewRegister.js

"use strict";

console.log("heheahhaha 测试全局用法");

module.exports = null;

cc._RF.pop();
},{}]},{},["NewScript","appStart","langZh","listView","array1","timeHandler","eventManager","test","viewManager","viewRegister"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9yZXNvdXJjZXMvbW9kdWxlcy9OZXdTY3JpcHQuanMiLCJhc3NldHMvc2NyaXB0L2FwcFN0YXJ0LmpzIiwiYXNzZXRzL3NjcmlwdC9saWJyYXJ5L2FycmF5MS5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC9ldmVudE1hbmFnZXIuanMiLCJhc3NldHMvc2NyaXB0L2NvbmZpZy9sYW5nWmguanMiLCJhc3NldHMvc2NyaXB0L2NvbnRyb2wvbGlzdFZpZXcuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdGVzdC5qcyIsImFzc2V0cy9zY3JpcHQvcHJvY2Vzcy90aW1lSGFuZGxlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3UmVnaXN0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6Ijs7Ozs7OztBQUFBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBakJLOzs7Ozs7Ozs7Ozs7QUNBVDtBQUNJO0FBQ0E7QUFDQTtBQUNBOztBQUVBOztBQUVBO0FBQ0E7O0FBR0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDQTtBQUNBO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0E7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQXJDSTs7Ozs7Ozs7OztBQ3pDVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFiUTtBQWVaO0FBQ0E7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBRUc7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUNKO0FBQ0o7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNJO0FBRUE7QUFDSTtBQURKO0FBR0k7QUFESjtBQUdIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQURKO0FBR0g7O0FBaEdJOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBOztBQUlBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBcERJOzs7Ozs7Ozs7O0FDRlQ7QUFDQTs7QUFFQTs7Ozs7Ozs7OztBQ0hBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaOztBQUlBO0FBQ0k7QUFDSDs7QUFFRDtBQUNBOztBQXpCSzs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQXZCSTs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBakJLOzs7Ozs7Ozs7O0FDRVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBYlE7O0FBZ0JaO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFFSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDSDs7QUFFRDtBQUNBOztBQUVBOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7O0FBRUQ7QUFDSTtBQUNJO0FBQ0E7QUFDSDs7QUFFRDs7QUFFQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTtBQUNJO0FBQ0E7QUFDSDtBQUVHO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7QUFDSTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFFRztBQUNIO0FBRUo7O0FBRUQ7QUFsSEs7Ozs7Ozs7Ozs7QUNGVDs7QUFFQSIsInNvdXJjZXNDb250ZW50IjpbImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImZ1bmN0aW9uIGluaXQoKXtcbiAgICBjYy50b29sID0ge31cbiAgICB2YXIgdmlld01hbmFnZXIgPSByZXF1aXJlKFwidmlld01hbmFnZXJcIik7XG4gICAgY2MudG9vbC52aWV3TWFuYWdlciA9IG5ldyB2aWV3TWFuYWdlcigpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIuaW5pdCgpO1xuXG4gICAgcmVxdWlyZShcInZpZXdSZWdpc3RlclwiKTtcblxuICAgIHZhciBldmVudE1hbmFnZXIgPSByZXF1aXJlKFwiZXZlbnRNYW5hZ2VyXCIpO1xuICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyID0gbmV3IGV2ZW50TWFuYWdlcigpO1xuXG5cbiAgICBjYy50b29sLkxhbmcgPSByZXF1aXJlKFwibGFuZ1poXCIpO1xuICAgIGNvbnNvbGUubG9nKGNjLnRvb2wuTGFuZ1tcIklURU1fVkFMVUVcIl0pO1xuICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImhhaGFoYVwiLCBcImhlaGVoZVwiLCBcImhpaGloaVwiKTtcblxuICAgIHZhciBoYWhhID0gW107XG4gICAgZm9yKGk9MDtpIDwgNTtpKyspe1xuICAgICAgICBoYWhhW2ldID0gaTtcbiAgICB9XG4gICAgY29uc29sZS5sb2coaGFoYS5sZW5ndGgpXG4gICAgZGVsZXRlIGhhaGFbMl07XG4gICAgZm9yKGk9MDtpIDwgNTtpKyspe1xuICAgICAgICBjb25zb2xlLmxvZyh0eXBlb2YgaGFoYVtpXSk7XG4gICAgfVxuXG4gICAgdmFyIGFycmF5ID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICB2YXIgdGVzdCA9IG5ldyBhcnJheSgpO1xuICAgIHRlc3Qub3V0UHV0KCk7XG4gICAgZm9yKGkgPSAwOyBpIDwgNTsgaSsrKXtcbiAgICAgICAgdGVzdC5wdXNoQmFjayhpICsgMTAwKVxuICAgIH1cbiAgICB0ZXN0Lm91dFB1dCgpO1xuICAgIHRlc3QucmVtb3ZlKDIpO1xuICAgIHRlc3Qub3V0UHV0KCk7XG5cbiAgICAvLyBjYy52YXJpYWJsZSA9IHt9O1xuICAgIC8vIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgIC8vIGNjLnZhcmlhYmxlLnZpZXdMaXN0ID0gbmV3IGFycmF5MSgpO1xufVxuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBoYWhhOiBbXSxcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiaGFoYWhhaGhzZmFzc2FnYVwiKTtcbiAgICAgICAgaW5pdCgpO1xuICAgICAgICB0aGlzLmluaXRTY2VuZSgpO1xuICAgIH0sXG5cbiAgICBpbml0U2NlbmU6IGZ1bmN0aW9uKCkge1xuICAgICAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnNldFJvb3QodGhpcy5ub2RlKTtcbiAgICAgICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwiaGFoaGFoYWhhYVwiKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0ZXN0IHR5cGVcIiArIHR5cGVvZiB0aGlzLmhhaGFbXCJ3b2Nhb1wiXSk7XG4gICAgfSxcblxuICAgIHRlc3RSZW1vdmU6IGZ1bmN0aW9uKCkge1xuICAgICAgICB2YXIgdGVzdCA9IHJlcXVpcmUoXCJldmVudE1hbmFnZXJcIilcbiAgICAgICAgdmFyIGhhaGEgPSBuZXcgdGVzdCgpO1xuICAgICAgICBoYWhhLmluaXQoKTtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jdXJWaWV3KCk7XG4gICAgICAgIC8vIHZhciB0ZXN0ID0gcmVxdWlyZShcImV2ZW50TWFuYWdlclwiKVxuICAgICAgICAvLyB2YXIgaGFoYSA9IG5ldyB0ZXN0KCk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGxpc3Q6IFtdLFxuICAgICAgICBzaXplOiAwLFxuICAgICAgICBucG9zOiAtMSxcbiAgICB9LFxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvcmtlZFwiKTtcbiAgICB9LFxuXG4gICAgYXNmZGZzZGY6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy5saXN0KTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcbiAgICB9LFxuXG4gICAgc3RhdHVzOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJzZWxmLnNpemUxXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLnNpemUpO1xuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTJcIik7XG4gICAgfSxcbiAgICAvL1xuICAgIHB1c2hCYWNrOiBmdW5jdGlvbihkYXRhKSB7XG4gICAgICAgIHRoaXMubGlzdFt0aGlzLnNpemVdID0gZGF0YTtcbiAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplICsgMTtcbiAgICB9LFxuXG4gICAgYXQ6IGZ1bmN0aW9uKGlkeCl7XG4gICAgICAgIHJldHVybiB0aGlzLmxpc3RbaWR4XTtcbiAgICB9LFxuXG4gICAgZmluZDogZnVuY3Rpb24odmFsdWUpe1xuICAgICAgICB2YXIgaW5kZXggPSB0aGlzLm5wb3M7XG4gICAgICAgIGlmICh0eXBlb2YgdmFsdWUgPT0gXCJmdW5jdGlvblwiKXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih2YWx1ZShpKSkgcmV0dXJuIGk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih0aGlzLmxpc3RbaV0gPT0gdmFsdWUpe1xuICAgICAgICAgICAgICAgICAgICBpbmRleCA9IGk7XG4gICAgICAgICAgICAgICAgICAgIGJyZWFrO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICByZXR1cm4gaW5kZXg7XG4gICAgfSxcblxuICAgIHJlbW92ZTogZnVuY3Rpb24ocG9zLCBsZW4pe1xuICAgICAgICBpZihwb3MgPCAwKSBwb3MgPSAwO1xuICAgICAgICBpZihsZW4gPT0gbnVsbCB8fCBsZW4gPD0gMCl7XG4gICAgICAgICAgICBsZW4gPSAxO1xuICAgICAgICB9XG4gICAgICAgIGlmKHBvcyA8IHRoaXMuc2l6ZSl7XG4gICAgICAgICAgICBpZihwb3MgKyBsZW4gPiB0aGlzLnNpemUpXG4gICAgICAgICAgICAgICAgbGVuID0gdGhpcy5zaXplIC0gcG9zO1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgbGVuOyBpKyspXG4gICAgICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtwb3MgKyBpXTtcbiAgICAgICAgICAgIGZvcihpID0gcG9zICsgbGVuOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICAgICAgdGhpcy5saXN0W2kgLSBsZW5dID0gdGhpcy5saXN0W2ldO1xuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gbGVuO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGNsZWFyOiBmdW5jdGlvbigpe1xuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbaV07XG4gICAgICAgIHRoaXMuc2l6ZSA9IDA7XG4gICAgfSxcblxuICAgIGdldFNpemU6IGZ1bmN0aW9uKCkge1xuICAgICAgICByZXR1cm4gdGhpcy5zaXplO1xuICAgIH0sXG5cbiAgICBlbXB0eTogZnVuY3Rpb24oKSB7XG4gICAgICAgIHJldHVybiB0aGlzLnNpemUgPT0gMDtcbiAgICB9LFxuXG4gICAgb3V0UHV0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnRcIiArIGkgKyBcIiA9IFwiICsgdGhpcy5saXN0W2ldKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50IHNpemUgPSBcIiArIHRoaXMuc2l6ZSk7XG4gICAgfSxcblxuXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJ2YXIgdGVzdCA9IHJlcXVpcmUoXCJ0ZXN0XCIpXG5cbmNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiB0ZXN0LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBldmVudExpc3RlbmVyOiBbXSxcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBpbml0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgdGhpcy5zdXBlci50ZXN0V29yaygpO1xuICAgIH0sXG5cbiAgICB0ZXN0V29yazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiemVubWUgaHVpIHpoZXlhbmdcIik7XG4gICAgfSxcblxuICAgIGFkZEV2ZW50TGlzdGVuZXI6IGZ1bmN0aW9uKGV2ZW50VHlwZSwgdGFyZ2V0LCBmdW5jKSB7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKClcbiAgICAgICAgaWYoIXRhcmdldCB8fCAhZnVuYykgcmV0dXJuO1xuICAgICAgICBpZighdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0pe1xuICAgICAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0gPSBbXTtcbiAgICAgICAgfVxuICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXVt0YXJnZXRdID0gZnVuYztcbiAgICB9LFxuXG4gICAgdGVzdFdvcmtMaXN0ZW5lcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGVzdCBsaXN0ZW5lclwiKTtcbiAgICAgICAgZm9yKHZhciBrZXkgaW4gdGhpcy5ldmVudExpc3RlbmVyW1wiaGFoYWhhXCJdKXtcbiAgICAgICAgICAgIHZhciBmdW5jID0gdGhpcy5ldmVudExpc3RlbmVyW1wiaGFoYWhhXCJdW2tleV07XG4gICAgICAgICAgICBmdW5jKFwiaGFoYWhhXCIpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGRpc3BhdGNoRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlKSB7XG4gICAgICAgIGZvcih2YXIga2V5IGluIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdKXtcbiAgICAgICAgICAgIHZhciBmdW5jID0gdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV1ba2V5XTtcbiAgICAgICAgICAgIGZ1bmMoZXZlbnRUeXBlKTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJ2YXIgTGFuZyA9IFtdO1xuTGFuZ1tcIklURU1fVkFMVUVcIl0gPSBcIuWPmOaIkOS4reaWh+eahOaDheWGtVwiO1xuXG5tb2R1bGUuZXhwb3J0cyA9IExhbmc7IiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkxheW91dCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgY3JlYXRlOiBmdW5jdGlvbigpIHtcbiAgICAgICAgXG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLndpZHRoICsgXCIgd29jYW8gXCIgKyB0aGlzLmhlaWdodCk7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICB0ZXN0V29yazogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyBuaW1hYmlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsIlxuXG5jYy5DbGFzcyh7XG4gICAgLy8gZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICB2aWV3TGlzdDogbnVsbCxcbiAgICAgICAgdmlld0luZm86IFtdLFxuICAgICAgICB2aWV3OiBudWxsLFxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJoaGhlaGVoZVwiKTtcbiAgICAgICAgdmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3QgPSBuZXcgYXJyYXkxKCk7XG4gICAgICAgIC8vIHRoaXMuYXJyYXkxID0gbmV3IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIHRoaXMudmlld0xpc3QucHVzaEJhY2soe2E6MSwgYjoyfSk7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBzZXRSb290OiBmdW5jdGlvbihub2RlKSB7XG4gICAgICAgIHRoaXMucm9vdCA9IG5vZGU7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICAvLyBjb25zb2xlLmxvZyhcImhhaGFoYWhoYVwiKTtcblxuICAgICAgICAvLyBjYy52YXJpYWJsZS52aWV3SW5mby5hc2ZkZnNkZigpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy52aWV3TmFtZSk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBpbml0OiBmdW5jdGlvbigpe1xuICAgICAgICB0aGlzLnZpZXdJbmZvID0gW107XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGhpcyAxXCIpO1xuICAgICAgICB0aGlzLnZpZXdJbmZvW1wiaGFoYVwiXSA9IHthOjEsIGI6Mn07XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGhpcyAyXCIpO1xuICAgIH0sXG5cbiAgICByZWdpc3RWaWV3KHZpZXdOYW1lLCBtb2R1bGUsIHRpdGxlKXtcbiAgICAgICAgdGhpcy52aWV3SW5mb1t2aWV3TmFtZV0gPSB7dmlld05hbWU6dmlld05hbWUsIG1vZHVsZTptb2R1bGUsIHRpdGxlOnRpdGxlfTtcblxuICAgICAgICB2YXIgdmlld0luZm8gPSB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXTtcbiAgICAgICAgdGhpcy52aWV3SW5mb1swXSA9IFwiaGFoYWhcIjtcbiAgICAgICAgdGhpcy52aWV3SW5mb1sxXSA9IFwid29jYW9cIjtcbiAgICAgICAgY29uc29sZS5sb2codmlld0luZm8pO1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLnZpZXdJbmZvLmxlbmd0aCk7XG4gICAgfSxcblxuICAgIGNoYW5nZVZpZXc6IGZ1bmN0aW9uKHZpZXdOYW1lKXtcbiAgICAgICAgaWYoIXRoaXMudmlld0xpc3QuZW1wdHkoKSAmJiB0aGlzLnZpZXdMaXN0LmJhY2soKSA9PSB2aWV3TmFtZSl7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcInZpZXcgaXMgc2FtZVwiKTtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgICAgIH1cblxuICAgICAgICB2YXIgdmlld0luZm8gPSB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXVxuXG4gICAgICAgIGlmKHRoaXMudmlldyAhPSBudWxsKXtcbiAgICAgICAgICAgIHRoaXMudmlldy5yZW1vdmVGcm9tUGFyZW50KCk7XG4gICAgICAgIH1cblxuICAgICAgICB2YXIgaWR4ID0gdGhpcy52aWV3TGlzdC5maW5kKHZpZXdOYW1lKTtcbiAgICAgICAgaWYoaWR4ICE9IHRoaXMudmlld0xpc3QubnBvcyl7XG4gICAgICAgICAgICB2YXIgbGVuID0gdGhpcy52aWV3TGlzdC5nZXRTaXplKCkgLSBpZHg7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnJlbW92ZShpZHgsIGxlbik7XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIHRoaXMudmlld0xpc3QucHVzaEJhY2sodmlld05hbWUpO1xuICAgICAgICB9XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgLy/pgJrov4fpk77mjqUg5Yqg6L2955qE6LWE5rqQIOW/hemhu+aUvuWcqHJlc291cmNl5LiLXG4gICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKFwicHJlZmFiL1Rlc3QxUGFuZWxcIiwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgc2VsZi52aWV3ID0gcm9vdDtcbiAgICAgICAgICAgIGNjLmRpcmVjdG9yLmdldFNjZW5lKCkuZ2V0Q2hpbGRCeU5hbWUoXCJDYW52YXNcIikuYWRkQ2hpbGQocm9vdCk7XG4gICAgICAgIH0pO1xuICAgICAgICBcbiAgICAgICAgcmV0dXJuIHRoaXMudmlldztcbiAgICB9LFxuXG4gICAgY3VyVmlldzogZnVuY3Rpb24oKSB7XG4gICAgICAgIC8vIHRoaXMudGVzdEFkZENoaWxkKCk7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgY2MudG9vbC5ldmVudE1hbmFnZXIuYWRkRXZlbnRMaXN0ZW5lcihcImhhaGFoYVwiLCBzZWxmLCBzZWxmLnRlc3RBZGRDaGlsZCk7XG4gICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLnRlc3RXb3JrTGlzdGVuZXIoKVxuICAgICAgICB0aGlzLnZpZXcucmVtb3ZlRnJvbVBhcmVudChmYWxzZSk7XG4gICAgICAgIGNjLmxvYWRlci5yZWxlYXNlUmVzKFwicHJlZmFiL1Rlc3QxUGFuZWxcIik7XG4gICAgfSxcblxuICAgIHRlc3RBZGRDaGlsZDogZnVuY3Rpb24odmFyTmFtZSl7XG4gICAgICAgIGlmKHZhck5hbWUgPT0gXCJoYWhhaGFcIil7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIHRhbWFiaVwiKTtcbiAgICAgICAgfVxuICAgICAgICBlbHNlIGlmKHZhck5hbWUgPSBcIndvY2FvbmltYVwiKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiPz8/IHdvZGV0aWFuXCIpO1xuICAgICAgICB9XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBiYWNrUHJldmlldzogZnVuY3Rpb24oKXtcblxuICAgIH0sXG59KTtcbiIsImNvbnNvbGUubG9nKFwiaGVoZWFoaGFoYSDmtYvor5XlhajlsYDnlKjms5VcIik7XG5cbm1vZHVsZS5leHBvcnRzID0gbnVsbDsiXSwic291cmNlUm9vdCI6IiJ9