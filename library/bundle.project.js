require=(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({"ListView":[function(require,module,exports){
"use strict";
cc._RF.push(module, '1ec29WNfkpI+78K3dmtU6fy', 'ListView');
// resources/control/ListView.js

"use strict";

var _cc$Class;

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }

var array1 = require("array1");

cc.Class((_cc$Class = {
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

        scrollView: {
            default: null,
            type: cc.ScrollView
        },

        dir: 0,
        lines: 0,
        hgap: 0,
        vgap: 0,
        width: 0,
        height: 0,

        dp: array1,
        item: cc.Prefab,
        itemPwd: null,
        itemHeight: 0,
        itemWidth: 0
    },

    ctor: function ctor() {
        this.updateTimer = 0;
        dp = null;
    },

    create: function create(dir, lines, hgap, vgap, width, height) {
        this.dir = dir;
        this.lines = lines;
        this.hgap = hgap;
        this.vgap = vgap;
        this.width = width;
        this.height = height;

        this.node.parent.parent.width = width;
        this.node.parent.parent.height = height;
        this.node.parent.width = width;
        this.node.parent.height = height;

        // this.node.parent.parent.setContentSize(cc.Size(width, height));
        // this.node.parent.setContentSize(cc.Size(width, height));
        if (dir == cc.tool.config.Direction.HORIZONTAL) {
            this.calcSection = function (self) {
                if (!self.dp || self.dp.size() == 0) {}
                var interval = self.itemHeight + self.vgap;
            };
        } else {
            this.calcSection = function (self) {
                if (!self.dp || self.dp.size() == 0) {}
                var interval = self.itemHeight + self.vgap;
            };
        }
    }

}, _defineProperty(_cc$Class, "ctor", function ctor() {
    console.log(this.width + " wocao " + this.height);
}), _defineProperty(_cc$Class, "onLoad", function onLoad() {}), _defineProperty(_cc$Class, "setItemModel", function setItemModel(item, itemWidth, itemHeight) {
    var self = this;

    this.itemPwd = item;
    // cc.loader.loadRes(item, cc.Prefab, function(err, prefab){
    //     // cc.tool.prefab.listView = prefab;
    //     console.log("type prefab = " + typeof prefab)
    //     self.item = prefab;
    // });
    cc.loader.loadRes(item, cc.Prefab);
    self.itemWidth = itemWidth;
    self.itemHeight = itemHeight;
}), _defineProperty(_cc$Class, "setDataProvider", function setDataProvider(dl) {
    var self = this;

    if (this.dir == cc.tool.config.Direction.HORIZONTAL) {
        this.node.height = dl.getSize() * (this.itemHeight + this.hgap) - this.hgap;
        this.node.width = this.width;
    } else {
        this.node.height = this.height;
    }

    dl.excuteWithFunc(function (data, index) {
        var prefab = cc.loader.getRes(self.itemPwd, cc.Prefab);

        var item = cc.instantiate(prefab).getComponent('Renderer');
        // item.setPosY(-this.itemHeight * (index + 1));
        item.setPos(0, -self.itemHeight * (index + 1));
        self.node.addChild(item.node);

        // cc.loader.getRes(self.itemPwd, cc.Prefab, function(err, prefab){
        //     let item = cc.instantiate(prefab).getComponent('Renderer');
        //     // item.setPosY(-this.itemHeight * (index + 1));
        //     item.setPos(0, -self.itemHeight * (index + 1));
        //     self.node.addChild(item.node);
        // });

        // let item = cc.instantiate(self.item).getComponent('Renderer');
        // // item.setPosY(-this.itemHeight * (index + 1));
        // item.setPos(0, -self.itemHeight * (index + 1));
        // self.node.addChild(item.node);
    });
}), _defineProperty(_cc$Class, "update", function update(dt) {
    this.updateTimer += dt;
    if (this.updateTimer < this.updateInterval) return;
}), _cc$Class));

cc._RF.pop();
},{"array1":"array1"}],"Renderer":[function(require,module,exports){
"use strict";
cc._RF.push(module, '1746aqmNPRADLdykcF/Z3ML', 'Renderer');
// resources/control/Renderer.js

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

    setPosY: function setPosY(y) {
        this.node.y = y;
    },

    setPos: function setPos(x, y) {
        this.node.x = x;
        this.node.y = y;
    }

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
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

    cc.tool.prefab = {};
    // cc.tool.viewManager.registView("hahaha", "hehehe", "hihihi");

    cc.tool.config = require("config");
    console.log("config = " + cc.tool.config.Direction.HORIZONTAL);

    console.log("wo de fak");

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

        var self = this;
        cc.loader.loadRes("control/ListView", cc.Prefab, function (err, prefab) {
            // cc.tool.prefab.listView = prefab;
            console.log("type prefab = " + (typeof prefab === "undefined" ? "undefined" : _typeof(prefab)));

            var root = cc.instantiate(prefab);
            root.setPosition(cc.v2(0, 0));
            var listView = root.getChildByName("view").getChildByName("content").getComponent("ListView");
            listView.create(cc.tool.config.Direction.HORIZONTAL, 1, 1, 1, 240, 150);
            listView.setItemModel("control/Renderer", 160, 60);

            var array = require("array1");
            var test = new array();
            for (i = 0; i < 5; i++) {
                test.pushBack(i + 100);
            }

            listView.setDataProvider(test);

            self.node.addChild(root);
        });
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
},{"array1":"array1","config":"config","eventManager":"eventManager","langZh":"langZh","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
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
    },

    excuteWithFunc: function excuteWithFunc(func) {
        for (var i = 0; i < this.size; i++) {
            func(this.list[i], i);
        }
    }

});

cc._RF.pop();
},{}],"config":[function(require,module,exports){
"use strict";
cc._RF.push(module, '1de31LmpaZJDrhNm68n+UdI', 'config');
// script/config/config.js

"use strict";

var Config = {};

Config.Direction = {};
Config.Direction.VERTICAL = 0;
Config.Direction.HORIZONTAL = 1;

module.exports = Config;

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
},{}],"testTs":[function(require,module,exports){
"use strict";
cc._RF.push(module, '2e1f31+3ftKNLCWdZOwiywS', 'testTs');
// script/testTs.ts

Object.defineProperty(exports, "__esModule", { value: true });
var _a = cc._decorator, ccclass = _a.ccclass, property = _a.property;
var NewClass = (function (_super) {
    __extends(NewClass, _super);
    function NewClass() {
        var _this = _super !== null && _super.apply(this, arguments) || this;
        _this.text = 'hello';
        return _this;
    }
    NewClass.prototype.onLoad = function () {
        // init logic
    };
    return NewClass;
}(cc.Component));
__decorate([
    property(cc.Label)
], NewClass.prototype, "label", void 0);
__decorate([
    property({
        default: 'hello'
    })
], NewClass.prototype, "text", void 0);
NewClass = __decorate([
    ccclass
], NewClass);
exports.default = NewClass;

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
},{}]},{},["ListView","Renderer","appStart","config","langZh","array1","timeHandler","testTs","eventManager","test","viewManager","viewRegister"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9MaXN0Vmlldy5qcyIsImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9SZW5kZXJlci5qcyIsImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvY29uZmlnLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL2V2ZW50TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvY29uZmlnL2xhbmdaaC5qcyIsImFzc2V0cy9zY3JpcHQvdGVzdFRzLnRzIiwiYXNzZXRzL3NjcmlwdC90b29sL3Rlc3QuanMiLCJhc3NldHMvc2NyaXB0L3Byb2Nlc3MvdGltZUhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdmlld01hbmFnZXIuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdmlld1JlZ2lzdGVyLmpzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiI7Ozs7Ozs7Ozs7O0FBQUE7O0FBRUE7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0k7QUFDQTtBQUZROztBQU1aO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFHQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBOUJROztBQWlDWjtBQUNJO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFHQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDSTtBQUNJO0FBR0E7QUFDSDtBQUNKO0FBRUc7QUFDSTtBQUdBO0FBQ0g7QUFDSjtBQUNKOztBQXpFTDtBQTRFUTtBQUNIO0FBUUc7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7QUFHRzs7QUFFQTtBQUNJO0FBQ0E7QUFDSDtBQUVHO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDSDtBQUNKO0FBR0c7QUFDQTtBQUNIOzs7Ozs7Ozs7O0FDeElMO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7QUFqQ0s7Ozs7Ozs7Ozs7OztBQ0FUO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7O0FBRUE7QUFDQTs7QUFHQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDQTs7QUFFQTs7QUFFQTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0E7QUFDQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTtBQUNBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWFE7O0FBY1o7QUFDQTtBQUNJO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0k7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0g7O0FBRUQ7O0FBR0E7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUE1REk7Ozs7Ozs7Ozs7QUNqRFQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBYlE7QUFlWjtBQUNBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNBO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDSjtBQUVHO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7QUFDSjtBQUNKO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSTtBQUVBO0FBQ0k7QUFESjtBQUdJO0FBREo7QUFHSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQURKO0FBR0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFESjtBQUdIOztBQUVEO0FBQ0k7QUFDSTtBQUNIO0FBQ0o7O0FBdEdJOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7QUFDQTtBQUNBOztBQUVBOzs7Ozs7Ozs7O0FDTkE7O0FBRUE7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBOztBQUlBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBcERJOzs7Ozs7Ozs7O0FDRlQ7O0FBRUE7O0FBRUE7Ozs7Ozs7OztBQ0pNO0FBR047QUFBc0M7QUFEdEM7QUFBQTtBQVNJOztBQU1KO0FBSkk7QUFDSTtBQUVKO0FBQ0o7QUFBQTtBQVhJO0FBREM7QUFDZTtBQUtoQjtBQUhDO0FBQ0c7QUFDSDtBQUNzQjtBQVJOO0FBRHBCO0FBQ29CO0FBQUE7Ozs7Ozs7Ozs7QUNIckI7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBdkJJOzs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFqQks7Ozs7Ozs7Ozs7QUNFVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFiUTs7QUFnQlo7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUVIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNIOzs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIOztBQUVEOztBQUVBO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDtBQUNEO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUVHO0FBQ0g7QUFFSjs7QUFFRDtBQWxISzs7Ozs7Ozs7OztBQ0ZUOztBQUlBIiwic291cmNlc0NvbnRlbnQiOlsidmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG5cbmNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG5cbiAgICAgICAgc2Nyb2xsVmlldzoge1xuICAgICAgICAgICAgZGVmYXVsdDogbnVsbCxcbiAgICAgICAgICAgIHR5cGU6IGNjLlNjcm9sbFZpZXdcbiAgICAgICAgfSxcblxuICAgICAgICBcbiAgICAgICAgZGlyOiAwLCBcbiAgICAgICAgbGluZXM6IDAsIFxuICAgICAgICBoZ2FwOiAwLCBcbiAgICAgICAgdmdhcDogMCwgXG4gICAgICAgIHdpZHRoOiAwLCBcbiAgICAgICAgaGVpZ2h0OiAwLFxuICAgICAgICBcblxuICAgICAgICBkcDogYXJyYXkxLFxuICAgICAgICBpdGVtOiBjYy5QcmVmYWIsXG4gICAgICAgIGl0ZW1Qd2Q6IG51bGwsXG4gICAgICAgIGl0ZW1IZWlnaHQ6IDAsXG4gICAgICAgIGl0ZW1XaWR0aDogMCxcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIHRoaXMudXBkYXRlVGltZXIgPSAwO1xuICAgICAgICBkcCA9IG51bGw7XG4gICAgfSxcblxuICAgIGNyZWF0ZTogZnVuY3Rpb24oZGlyLCBsaW5lcywgaGdhcCwgdmdhcCwgd2lkdGgsIGhlaWdodCkge1xuICAgICAgICB0aGlzLmRpciA9IGRpcjtcbiAgICAgICAgdGhpcy5saW5lcyA9IGxpbmVzO1xuICAgICAgICB0aGlzLmhnYXAgPSBoZ2FwO1xuICAgICAgICB0aGlzLnZnYXAgPSB2Z2FwO1xuICAgICAgICB0aGlzLndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMuaGVpZ2h0ID0gaGVpZ2h0O1xuXG5cbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC5wYXJlbnQud2lkdGggPSB3aWR0aDtcbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC5wYXJlbnQuaGVpZ2h0ID0gaGVpZ2h0O1xuICAgICAgICB0aGlzLm5vZGUucGFyZW50LndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQuaGVpZ2h0ID0gaGVpZ2h0O1xuXG4gICAgICAgIC8vIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LnNldENvbnRlbnRTaXplKGNjLlNpemUod2lkdGgsIGhlaWdodCkpO1xuICAgICAgICAvLyB0aGlzLm5vZGUucGFyZW50LnNldENvbnRlbnRTaXplKGNjLlNpemUod2lkdGgsIGhlaWdodCkpO1xuICAgICAgICBpZihkaXIgPT0gY2MudG9vbC5jb25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwpe1xuICAgICAgICAgICAgdGhpcy5jYWxjU2VjdGlvbiA9IGZ1bmN0aW9uKHNlbGYpIHtcbiAgICAgICAgICAgICAgICBpZighc2VsZi5kcCB8fCBzZWxmLmRwLnNpemUoKSA9PSAwKXtcbiAgICAgICAgICAgICAgICAgICAgXG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHZhciBpbnRlcnZhbCA9IHNlbGYuaXRlbUhlaWdodCArIHNlbGYudmdhcDtcbiAgICAgICAgICAgIH07XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIHRoaXMuY2FsY1NlY3Rpb24gPSBmdW5jdGlvbihzZWxmKSB7XG4gICAgICAgICAgICAgICAgaWYoIXNlbGYuZHAgfHwgc2VsZi5kcC5zaXplKCkgPT0gMCl7XG4gICAgICAgICAgICAgICAgICAgIFxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB2YXIgaW50ZXJ2YWwgPSBzZWxmLml0ZW1IZWlnaHQgKyBzZWxmLnZnYXA7XG4gICAgICAgICAgICB9O1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLndpZHRoICsgXCIgd29jYW8gXCIgKyB0aGlzLmhlaWdodCk7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIHNldEl0ZW1Nb2RlbDogZnVuY3Rpb24oaXRlbSwgaXRlbVdpZHRoLCBpdGVtSGVpZ2h0KSB7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcblxuICAgICAgICB0aGlzLml0ZW1Qd2QgPSBpdGVtO1xuICAgICAgICAvLyBjYy5sb2FkZXIubG9hZFJlcyhpdGVtLCBjYy5QcmVmYWIsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgLy8gICAgIC8vIGNjLnRvb2wucHJlZmFiLmxpc3RWaWV3ID0gcHJlZmFiO1xuICAgICAgICAvLyAgICAgY29uc29sZS5sb2coXCJ0eXBlIHByZWZhYiA9IFwiICsgdHlwZW9mIHByZWZhYilcbiAgICAgICAgLy8gICAgIHNlbGYuaXRlbSA9IHByZWZhYjtcbiAgICAgICAgLy8gfSk7XG4gICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKGl0ZW0sIGNjLlByZWZhYik7XG4gICAgICAgIHNlbGYuaXRlbVdpZHRoID0gaXRlbVdpZHRoO1xuICAgICAgICBzZWxmLml0ZW1IZWlnaHQgPSBpdGVtSGVpZ2h0O1xuICAgIH0sXG5cbiAgICBzZXREYXRhUHJvdmlkZXI6IGZ1bmN0aW9uKGRsKSB7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcblxuICAgICAgICBpZih0aGlzLmRpciA9PSBjYy50b29sLmNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCl7XG4gICAgICAgICAgICB0aGlzLm5vZGUuaGVpZ2h0ID0gZGwuZ2V0U2l6ZSgpICogKHRoaXMuaXRlbUhlaWdodCArIHRoaXMuaGdhcCkgLSB0aGlzLmhnYXA7XG4gICAgICAgICAgICB0aGlzLm5vZGUud2lkdGggPSB0aGlzLndpZHRoO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLm5vZGUuaGVpZ2h0ID0gdGhpcy5oZWlnaHQ7XG4gICAgICAgIH0gICAgXG5cbiAgICAgICAgZGwuZXhjdXRlV2l0aEZ1bmMoZnVuY3Rpb24oZGF0YSwgaW5kZXgpe1xuICAgICAgICAgICAgdmFyIHByZWZhYiA9IGNjLmxvYWRlci5nZXRSZXMoc2VsZi5pdGVtUHdkLCBjYy5QcmVmYWIpO1xuXG4gICAgICAgICAgICBsZXQgaXRlbSA9IGNjLmluc3RhbnRpYXRlKHByZWZhYikuZ2V0Q29tcG9uZW50KCdSZW5kZXJlcicpO1xuICAgICAgICAgICAgLy8gaXRlbS5zZXRQb3NZKC10aGlzLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICBpdGVtLnNldFBvcygwLCAtc2VsZi5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgc2VsZi5ub2RlLmFkZENoaWxkKGl0ZW0ubm9kZSk7XG5cbiAgICAgICAgICAgIC8vIGNjLmxvYWRlci5nZXRSZXMoc2VsZi5pdGVtUHdkLCBjYy5QcmVmYWIsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgIC8vICAgICBsZXQgaXRlbSA9IGNjLmluc3RhbnRpYXRlKHByZWZhYikuZ2V0Q29tcG9uZW50KCdSZW5kZXJlcicpO1xuICAgICAgICAgICAgLy8gICAgIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gICAgIGl0ZW0uc2V0UG9zKDAsIC1zZWxmLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyAgICAgc2VsZi5ub2RlLmFkZENoaWxkKGl0ZW0ubm9kZSk7XG4gICAgICAgICAgICAvLyB9KTtcblxuICAgICAgICAgICAgLy8gbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShzZWxmLml0ZW0pLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gaXRlbS5zZXRQb3MoMCwgLXNlbGYuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuICAgICAgICB9KTtcbiAgICB9LFxuXG4gICAgdXBkYXRlIChkdCkge1xuICAgICAgICB0aGlzLnVwZGF0ZVRpbWVyICs9IGR0O1xuICAgICAgICBpZih0aGlzLnVwZGF0ZVRpbWVyIDwgdGhpcy51cGRhdGVJbnRlcnZhbCkgcmV0dXJuO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICBzZXRQb3NZOiBmdW5jdGlvbih5KSB7XG4gICAgICAgIHRoaXMubm9kZS55ID0geTtcbiAgICB9LFxuXG4gICAgc2V0UG9zOiBmdW5jdGlvbih4LCB5KSB7XG4gICAgICAgIHRoaXMubm9kZS54ID0geDtcbiAgICAgICAgdGhpcy5ub2RlLnkgPSB5O1xuICAgIH1cblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImZ1bmN0aW9uIGluaXQoKXtcbiAgICBjYy50b29sID0ge31cbiAgICB2YXIgdmlld01hbmFnZXIgPSByZXF1aXJlKFwidmlld01hbmFnZXJcIik7XG4gICAgY2MudG9vbC52aWV3TWFuYWdlciA9IG5ldyB2aWV3TWFuYWdlcigpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIuaW5pdCgpO1xuXG4gICAgcmVxdWlyZShcInZpZXdSZWdpc3RlclwiKTtcblxuICAgIHZhciBldmVudE1hbmFnZXIgPSByZXF1aXJlKFwiZXZlbnRNYW5hZ2VyXCIpO1xuICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyID0gbmV3IGV2ZW50TWFuYWdlcigpO1xuXG5cbiAgICBjYy50b29sLkxhbmcgPSByZXF1aXJlKFwibGFuZ1poXCIpO1xuICAgIGNvbnNvbGUubG9nKGNjLnRvb2wuTGFuZ1tcIklURU1fVkFMVUVcIl0pO1xuXG4gICAgY2MudG9vbC5wcmVmYWIgPSB7fTtcbiAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJoYWhhaGFcIiwgXCJoZWhlaGVcIiwgXCJoaWhpaGlcIik7XG5cbiAgICBjYy50b29sLmNvbmZpZyA9IHJlcXVpcmUoXCJjb25maWdcIik7XG4gICAgY29uc29sZS5sb2coXCJjb25maWcgPSBcIiArIGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMKTtcblxuICAgIGNvbnNvbGUubG9nKFwid28gZGUgZmFrXCIpO1xuXG4gICAgdmFyIGhhaGEgPSBbXTtcbiAgICBmb3IoaT0wO2kgPCA1O2krKyl7XG4gICAgICAgIGhhaGFbaV0gPSBpO1xuICAgIH1cbiAgICBjb25zb2xlLmxvZyhoYWhhLmxlbmd0aClcbiAgICBkZWxldGUgaGFoYVsyXTtcbiAgICBmb3IoaT0wO2kgPCA1O2krKyl7XG4gICAgICAgIGNvbnNvbGUubG9nKHR5cGVvZiBoYWhhW2ldKTtcbiAgICB9XG5cbiAgICB2YXIgYXJyYXkgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgIHZhciB0ZXN0ID0gbmV3IGFycmF5KCk7XG4gICAgdGVzdC5vdXRQdXQoKTtcbiAgICBmb3IoaSA9IDA7IGkgPCA1OyBpKyspe1xuICAgICAgICB0ZXN0LnB1c2hCYWNrKGkgKyAxMDApXG4gICAgfVxuICAgIHRlc3Qub3V0UHV0KCk7XG4gICAgdGVzdC5yZW1vdmUoMik7XG4gICAgdGVzdC5vdXRQdXQoKTtcblxuXG4gICAgLy8gY2MudmFyaWFibGUgPSB7fTtcbiAgICAvLyB2YXIgYXJyYXkxID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICAvLyBjYy52YXJpYWJsZS52aWV3TGlzdCA9IG5ldyBhcnJheTEoKTtcbn1cblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgaGFoYTogW10sXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcImhhaGFoYWhoc2Zhc3NhZ2FcIik7XG4gICAgICAgIGluaXQoKTtcbiAgICAgICAgdGhpcy5pbml0U2NlbmUoKTtcblxuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKFwiY29udHJvbC9MaXN0Vmlld1wiLCBjYy5QcmVmYWIsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgIC8vIGNjLnRvb2wucHJlZmFiLmxpc3RWaWV3ID0gcHJlZmFiO1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ0eXBlIHByZWZhYiA9IFwiICsgdHlwZW9mIHByZWZhYilcblxuICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgcm9vdC5zZXRQb3NpdGlvbihjYy52MigwLCAwKSk7XG4gICAgICAgICAgICBsZXQgbGlzdFZpZXcgPSByb290LmdldENoaWxkQnlOYW1lKFwidmlld1wiKS5nZXRDaGlsZEJ5TmFtZShcImNvbnRlbnRcIikuZ2V0Q29tcG9uZW50KFwiTGlzdFZpZXdcIik7XG4gICAgICAgICAgICBsaXN0Vmlldy5jcmVhdGUoY2MudG9vbC5jb25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwsIDEsIDEsIDEsIDI0MCwgMTUwKTtcbiAgICAgICAgICAgIGxpc3RWaWV3LnNldEl0ZW1Nb2RlbChcImNvbnRyb2wvUmVuZGVyZXJcIiwgMTYwLCA2MCk7XG5cbiAgICAgICAgICAgIHZhciBhcnJheSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgICAgICB2YXIgdGVzdCA9IG5ldyBhcnJheSgpO1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgNTsgaSsrKXtcbiAgICAgICAgICAgICAgICB0ZXN0LnB1c2hCYWNrKGkgKyAxMDApXG4gICAgICAgICAgICB9XG5cbiAgICAgICAgICAgIGxpc3RWaWV3LnNldERhdGFQcm92aWRlcih0ZXN0KTtcblxuXG4gICAgICAgICAgICBzZWxmLm5vZGUuYWRkQ2hpbGQocm9vdCk7XG4gICAgICAgIH0pO1xuICAgIH0sXG5cbiAgICBpbml0U2NlbmU6IGZ1bmN0aW9uKCkge1xuICAgICAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnNldFJvb3QodGhpcy5ub2RlKTtcbiAgICAgICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwiaGFoaGFoYWhhYVwiKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0ZXN0IHR5cGVcIiArIHR5cGVvZiB0aGlzLmhhaGFbXCJ3b2Nhb1wiXSk7XG4gICAgfSxcblxuICAgIHRlc3RSZW1vdmU6IGZ1bmN0aW9uKCkge1xuICAgICAgICB2YXIgdGVzdCA9IHJlcXVpcmUoXCJldmVudE1hbmFnZXJcIilcbiAgICAgICAgdmFyIGhhaGEgPSBuZXcgdGVzdCgpO1xuICAgICAgICBoYWhhLmluaXQoKTtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jdXJWaWV3KCk7XG4gICAgICAgIC8vIHZhciB0ZXN0ID0gcmVxdWlyZShcImV2ZW50TWFuYWdlclwiKVxuICAgICAgICAvLyB2YXIgaGFoYSA9IG5ldyB0ZXN0KCk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGxpc3Q6IFtdLFxuICAgICAgICBzaXplOiAwLFxuICAgICAgICBucG9zOiAtMSxcbiAgICB9LFxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvcmtlZFwiKTtcbiAgICB9LFxuXG4gICAgYXNmZGZzZGY6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy5saXN0KTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcbiAgICB9LFxuXG4gICAgc3RhdHVzOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJzZWxmLnNpemUxXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLnNpemUpO1xuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTJcIik7XG4gICAgfSxcbiAgICAvL1xuICAgIHB1c2hCYWNrOiBmdW5jdGlvbihkYXRhKSB7XG4gICAgICAgIHRoaXMubGlzdFt0aGlzLnNpemVdID0gZGF0YTtcbiAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplICsgMTtcbiAgICB9LFxuXG4gICAgYXQ6IGZ1bmN0aW9uKGlkeCl7XG4gICAgICAgIHJldHVybiB0aGlzLmxpc3RbaWR4XTtcbiAgICB9LFxuXG4gICAgZmluZDogZnVuY3Rpb24odmFsdWUpe1xuICAgICAgICB2YXIgaW5kZXggPSB0aGlzLm5wb3M7XG4gICAgICAgIGlmICh0eXBlb2YgdmFsdWUgPT0gXCJmdW5jdGlvblwiKXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih2YWx1ZShpKSkgcmV0dXJuIGk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih0aGlzLmxpc3RbaV0gPT0gdmFsdWUpe1xuICAgICAgICAgICAgICAgICAgICBpbmRleCA9IGk7XG4gICAgICAgICAgICAgICAgICAgIGJyZWFrO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICByZXR1cm4gaW5kZXg7XG4gICAgfSxcblxuICAgIHJlbW92ZTogZnVuY3Rpb24ocG9zLCBsZW4pe1xuICAgICAgICBpZihwb3MgPCAwKSBwb3MgPSAwO1xuICAgICAgICBpZihsZW4gPT0gbnVsbCB8fCBsZW4gPD0gMCl7XG4gICAgICAgICAgICBsZW4gPSAxO1xuICAgICAgICB9XG4gICAgICAgIGlmKHBvcyA8IHRoaXMuc2l6ZSl7XG4gICAgICAgICAgICBpZihwb3MgKyBsZW4gPiB0aGlzLnNpemUpXG4gICAgICAgICAgICAgICAgbGVuID0gdGhpcy5zaXplIC0gcG9zO1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgbGVuOyBpKyspXG4gICAgICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtwb3MgKyBpXTtcbiAgICAgICAgICAgIGZvcihpID0gcG9zICsgbGVuOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICAgICAgdGhpcy5saXN0W2kgLSBsZW5dID0gdGhpcy5saXN0W2ldO1xuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gbGVuO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGNsZWFyOiBmdW5jdGlvbigpe1xuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbaV07XG4gICAgICAgIHRoaXMuc2l6ZSA9IDA7XG4gICAgfSxcblxuICAgIGdldFNpemU6IGZ1bmN0aW9uKCkge1xuICAgICAgICByZXR1cm4gdGhpcy5zaXplO1xuICAgIH0sXG5cbiAgICBlbXB0eTogZnVuY3Rpb24oKSB7XG4gICAgICAgIHJldHVybiB0aGlzLnNpemUgPT0gMDtcbiAgICB9LFxuXG4gICAgb3V0UHV0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnRcIiArIGkgKyBcIiA9IFwiICsgdGhpcy5saXN0W2ldKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50IHNpemUgPSBcIiArIHRoaXMuc2l6ZSk7XG4gICAgfSxcblxuICAgIGV4Y3V0ZVdpdGhGdW5jOiBmdW5jdGlvbihmdW5jKSB7XG4gICAgICAgIGZvcih2YXIgaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKyl7XG4gICAgICAgICAgICBmdW5jKHRoaXMubGlzdFtpXSwgaSk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwidmFyIENvbmZpZyA9IHt9O1xuXG5Db25maWcuRGlyZWN0aW9uID0ge307XG5Db25maWcuRGlyZWN0aW9uLlZFUlRJQ0FMID0gMDtcbkNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCA9IDE7XG5cbm1vZHVsZS5leHBvcnRzID0gQ29uZmlnOyIsInZhciB0ZXN0ID0gcmVxdWlyZShcInRlc3RcIilcblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IHRlc3QsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGV2ZW50TGlzdGVuZXI6IFtdLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgXG4gICAgfSxcblxuICAgIGluaXQ6IGZ1bmN0aW9uKCkge1xuICAgICAgICB0aGlzLnN1cGVyLnRlc3RXb3JrKCk7XG4gICAgfSxcblxuICAgIHRlc3RXb3JrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ6ZW5tZSBodWkgemhleWFuZ1wiKTtcbiAgICB9LFxuXG4gICAgYWRkRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlLCB0YXJnZXQsIGZ1bmMpIHtcbiAgICAgICAgLy8gY29uc29sZS5sb2coKVxuICAgICAgICBpZighdGFyZ2V0IHx8ICFmdW5jKSByZXR1cm47XG4gICAgICAgIGlmKCF0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSl7XG4gICAgICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSA9IFtdO1xuICAgICAgICB9XG4gICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdW3RhcmdldF0gPSBmdW5jO1xuICAgIH0sXG5cbiAgICB0ZXN0V29ya0xpc3RlbmVyOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0byB0ZXN0IGxpc3RlbmVyXCIpO1xuICAgICAgICBmb3IodmFyIGtleSBpbiB0aGlzLmV2ZW50TGlzdGVuZXJbXCJoYWhhaGFcIl0pe1xuICAgICAgICAgICAgdmFyIGZ1bmMgPSB0aGlzLmV2ZW50TGlzdGVuZXJbXCJoYWhhaGFcIl1ba2V5XTtcbiAgICAgICAgICAgIGZ1bmMoXCJoYWhhaGFcIik7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgZGlzcGF0Y2hFdmVudExpc3RlbmVyOiBmdW5jdGlvbihldmVudFR5cGUpIHtcbiAgICAgICAgZm9yKHZhciBrZXkgaW4gdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0pe1xuICAgICAgICAgICAgdmFyIGZ1bmMgPSB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXVtrZXldO1xuICAgICAgICAgICAgZnVuYyhldmVudFR5cGUpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsInZhciBMYW5nID0gW107XG5cbkxhbmdbXCJJVEVNX1ZBTFVFXCJdID0gXCLlj5jmiJDkuK3mlofnmoTmg4XlhrVcIjtcblxubW9kdWxlLmV4cG9ydHMgPSBMYW5nOyIsImNvbnN0IHtjY2NsYXNzLCBwcm9wZXJ0eX0gPSBjYy5fZGVjb3JhdG9yO1xuXG5AY2NjbGFzc1xuZXhwb3J0IGRlZmF1bHQgY2xhc3MgTmV3Q2xhc3MgZXh0ZW5kcyBjYy5Db21wb25lbnQge1xuXG4gICAgQHByb3BlcnR5KGNjLkxhYmVsKVxuICAgIGxhYmVsOiBjYy5MYWJlbDtcblxuICAgIEBwcm9wZXJ0eSh7XG4gICAgICAgIGRlZmF1bHQ6ICdoZWxsbydcbiAgICB9KVxuICAgIHRleHQ6IHN0cmluZyA9ICdoZWxsbyc7XG5cbiAgICBvbkxvYWQoKSB7XG4gICAgICAgIC8vIGluaXQgbG9naWNcbiAgICAgICAgXG4gICAgfVxufVxuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgdGVzdFdvcms6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gbmltYWJpXCIpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJcblxuY2MuQ2xhc3Moe1xuICAgIC8vIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgdmlld0xpc3Q6IG51bGwsXG4gICAgICAgIHZpZXdJbmZvOiBbXSxcbiAgICAgICAgdmlldzogbnVsbCxcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiaGhoZWhlaGVcIik7XG4gICAgICAgIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0ID0gbmV3IGFycmF5MSgpO1xuICAgICAgICAvLyB0aGlzLmFycmF5MSA9IG5ldyByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnN0YXR1cygpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHthOjEsIGI6Mn0pO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnN0YXR1cygpO1xuICAgICAgICBcbiAgICB9LFxuXG4gICAgc2V0Um9vdDogZnVuY3Rpb24obm9kZSkge1xuICAgICAgICB0aGlzLnJvb3QgPSBub2RlO1xuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgLy8gY29uc29sZS5sb2coXCJoYWhhaGFoaGFcIik7XG5cbiAgICAgICAgLy8gY2MudmFyaWFibGUudmlld0luZm8uYXNmZGZzZGYoKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2codHlwZW9mIHRoaXMudmlld05hbWUpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxuXG4gICAgaW5pdDogZnVuY3Rpb24oKXtcbiAgICAgICAgdGhpcy52aWV3SW5mbyA9IFtdO1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMVwiKTtcbiAgICAgICAgdGhpcy52aWV3SW5mb1tcImhhaGFcIl0gPSB7YToxLCBiOjJ9O1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMlwiKTtcbiAgICB9LFxuXG4gICAgcmVnaXN0Vmlldyh2aWV3TmFtZSwgbW9kdWxlLCB0aXRsZSl7XG4gICAgICAgIHRoaXMudmlld0luZm9bdmlld05hbWVdID0ge3ZpZXdOYW1lOnZpZXdOYW1lLCBtb2R1bGU6bW9kdWxlLCB0aXRsZTp0aXRsZX07XG5cbiAgICAgICAgdmFyIHZpZXdJbmZvID0gdGhpcy52aWV3SW5mb1t2aWV3TmFtZV07XG4gICAgICAgIHRoaXMudmlld0luZm9bMF0gPSBcImhhaGFoXCI7XG4gICAgICAgIHRoaXMudmlld0luZm9bMV0gPSBcIndvY2FvXCI7XG4gICAgICAgIGNvbnNvbGUubG9nKHZpZXdJbmZvKTtcbiAgICAgICAgY29uc29sZS5sb2codGhpcy52aWV3SW5mby5sZW5ndGgpO1xuICAgIH0sXG5cbiAgICBjaGFuZ2VWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSl7XG4gICAgICAgIGlmKCF0aGlzLnZpZXdMaXN0LmVtcHR5KCkgJiYgdGhpcy52aWV3TGlzdC5iYWNrKCkgPT0gdmlld05hbWUpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ2aWV3IGlzIHNhbWVcIik7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgICAgICB9XG5cbiAgICAgICAgdmFyIHZpZXdJbmZvID0gdGhpcy52aWV3SW5mb1t2aWV3TmFtZV1cblxuICAgICAgICBpZih0aGlzLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICB0aGlzLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICB9XG5cbiAgICAgICAgdmFyIGlkeCA9IHRoaXMudmlld0xpc3QuZmluZCh2aWV3TmFtZSk7XG4gICAgICAgIGlmKGlkeCAhPSB0aGlzLnZpZXdMaXN0Lm5wb3Mpe1xuICAgICAgICAgICAgdmFyIGxlbiA9IHRoaXMudmlld0xpc3QuZ2V0U2l6ZSgpIC0gaWR4O1xuICAgICAgICAgICAgdGhpcy52aWV3TGlzdC5yZW1vdmUoaWR4LCBsZW4pO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHZpZXdOYW1lKTtcbiAgICAgICAgfVxuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIC8v6YCa6L+H6ZO+5o6lIOWKoOi9veeahOi1hOa6kCDlv4XpobvmlL7lnKhyZXNvdXJjZeS4i1xuICAgICAgICBjYy5sb2FkZXIubG9hZFJlcyhcInByZWZhYi9UZXN0MVBhbmVsXCIsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcbiAgICAgICAgICAgIHNlbGYudmlldyA9IHJvb3Q7XG4gICAgICAgICAgICBjYy5kaXJlY3Rvci5nZXRTY2VuZSgpLmdldENoaWxkQnlOYW1lKFwiQ2FudmFzXCIpLmFkZENoaWxkKHJvb3QpO1xuICAgICAgICB9KTtcbiAgICAgICAgXG4gICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgfSxcblxuICAgIGN1clZpZXc6IGZ1bmN0aW9uKCkge1xuICAgICAgICAvLyB0aGlzLnRlc3RBZGRDaGlsZCgpO1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLmFkZEV2ZW50TGlzdGVuZXIoXCJoYWhhaGFcIiwgc2VsZiwgc2VsZi50ZXN0QWRkQ2hpbGQpO1xuICAgICAgICBjYy50b29sLmV2ZW50TWFuYWdlci50ZXN0V29ya0xpc3RlbmVyKClcbiAgICAgICAgdGhpcy52aWV3LnJlbW92ZUZyb21QYXJlbnQoZmFsc2UpO1xuICAgICAgICBjYy5sb2FkZXIucmVsZWFzZVJlcyhcInByZWZhYi9UZXN0MVBhbmVsXCIpO1xuICAgIH0sXG5cbiAgICB0ZXN0QWRkQ2hpbGQ6IGZ1bmN0aW9uKHZhck5hbWUpe1xuICAgICAgICBpZih2YXJOYW1lID09IFwiaGFoYWhhXCIpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyB0YW1hYmlcIik7XG4gICAgICAgIH1cbiAgICAgICAgZWxzZSBpZih2YXJOYW1lID0gXCJ3b2Nhb25pbWFcIil7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIj8/PyB3b2RldGlhblwiKTtcbiAgICAgICAgfVxuICAgICAgICBcbiAgICB9LFxuXG4gICAgYmFja1ByZXZpZXc6IGZ1bmN0aW9uKCl7XG5cbiAgICB9LFxufSk7XG4iLCJjb25zb2xlLmxvZyhcImhlaGVhaGhhaGEg5rWL6K+V5YWo5bGA55So5rOVXCIpO1xuXG5cblxubW9kdWxlLmV4cG9ydHMgPSBudWxsOyJdLCJzb3VyY2VSb290IjoiIn0=