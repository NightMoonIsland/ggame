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
    viewRegister();

    var timeHandler = require("timeHandler");
    cc.tool.timeHandler = new timeHandler();

    var eventManager = require("eventManager");
    cc.tool.eventManager = new eventManager();

    cc.tool.gameVariable = require("gameVariable");
    cc.tool.Lang = require("langZh");

    cc.tool.prefab = {};
    // cc.tool.viewManager.registView("hahaha", "hehehe", "hihihi");

    cc.tool.config = require("config");
}

function viewRegister() {
    cc.tool.viewManager.registView("kmView", "ui/kmView", 2);
    cc.tool.viewManager.registView("kilie5View", "ui/kilie5View", 2);
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
        haha: [],
        count: 0
    },

    // use this for initialization
    onLoad: function onLoad() {
        init();

        // var self = this;
        // cc.loader.loadRes("control/ListView", cc.Prefab, function(err, prefab){
        //     // cc.tool.prefab.listView = prefab;
        //     console.log("type prefab = " + typeof prefab)

        //     var root = cc.instantiate(prefab);
        //     root.setPosition(cc.v2(0, 0));
        //     let listView = root.getChildByName("view").getChildByName("content").getComponent("ListView");
        //     listView.create(cc.tool.config.Direction.HORIZONTAL, 1, 1, 1, 240, 150);
        //     listView.setItemModel("control/Renderer", 160, 60);

        //     var array = require("array1");
        //     var test = new array();
        //     for(i = 0; i < 5; i++){
        //         test.pushBack(i + 100)
        //     }

        //     listView.setDataProvider(test);


        //     self.node.addChild(root);
        // });

        this.schedule(function () {
            this.updateTime();
        }, 1);
    },

    updateTime: function updateTime() {
        console.log("this.count = " + this.count);
        this.count = this.count + 1;
        cc.tool.eventManager.VAR_CHANGE("sec1");
        cc.tool.gameVariable.sec = cc.tool.gameVariable.sec + 1;
    },

    initScene: function initScene() {
        // cc.tool.viewManager.setRoot(this.node);
        // cc.tool.viewManager.changeView("hahhahahaa");
        console.log("test type" + _typeof(this.haha["wocao"]));
    },

    testRemove: function testRemove() {
        cc.tool.viewManager.changeView("kmView");
    },

    btnBack: function btnBack() {
        cc.tool.viewManager.backPreview();
    }

});

cc._RF.pop();
},{"config":"config","eventManager":"eventManager","gameVariable":"gameVariable","langZh":"langZh","timeHandler":"timeHandler","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
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

    back: function back() {
        if (this.size > 0) {
            return this.list[this.size - 1];
        } else {
            return null;
        }
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
    },

    popBack: function popBack() {
        if (this.size > 0) {
            delete this.list[this.size - 1];
            this.size = this.size - 1;
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

var array1 = require("array1");
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
        target.output();
        // console.log()
        if (!target || !func) return;
        if (!this.eventListener[eventType]) {
            this.eventListener[eventType] = new array1();
        }
        this.eventListener[eventType].pushBack({ target: target, func: func });
    },

    testWorkListener: function testWorkListener() {
        console.log("to test listener");
        for (var key in this.eventListener["hahaha"]) {
            var func = this.eventListener["hahaha"][key];
            func("hahaha");
        }
    },

    dispatchEventListener: function dispatchEventListener(eventType) {
        this.eventListener[eventType].excuteWithFunc(function (item, index) {
            var func = item.func;
            var target = item.target;
            func(target, eventType);
        });
        // for(var key in this.eventListener[eventType]){
        //     var func = this.eventListener[eventType][key];
        //     func(key, eventType);
        // }
    },

    VAR_CHANGE: function VAR_CHANGE(varName) {
        this.dispatchEventListener(varName);
    }

});

cc._RF.pop();
},{"array1":"array1","test":"test"}],"gameVariable":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'ccaccZqW9hPeZDHspjTu+DL', 'gameVariable');
// script/variable/gameVariable.js

"use strict";

var gameVar = [];

gameVar.sec = 0;

module.exports = gameVar;

cc._RF.pop();
},{}],"kmView":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'e3999BolkhJpYS2J/xuszfb', 'kmView');
// script/module/kmView.js

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
        eventType: null
    },

    // use this for initialization
    onLoad: function onLoad() {
        this.eventType = new Array("sec1", "sec2", "sec3");

        var self = this;
        for (var i = 0; i < this.eventType.length; i++) {
            cc.tool.eventManager.addEventListener(self.eventType[i], self, self.onVarCallback);
        }
    },

    onVarCallback: function onVarCallback(self, varName) {
        if (varName == "sec1") {
            //self.output();
            self.node.getChildByName("txthaha").getComponent(cc.Label).string = "sec = " + cc.tool.gameVariable.sec;
        } else if (varName == "") {}
    },

    output: function output() {
        console.log("wo cao ni ma ge chou hai");
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    btnTeam: function btnTeam() {

        // cc.tool.viewManager.changeView("kilie5View");
    }
});

cc._RF.pop();
},{}],"langZh":[function(require,module,exports){
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
        count: 0
    },

    // use this for initialization
    onLoad: function onLoad() {},

    ctor: function ctor() {
        console.log("zenm ehuizheyang");
        this.schedule(function () {
            console.log("hahahahahha");
        }, 1);
    },

    dosomething: function dosomething() {
        console.log("dsgfsdagvdga");
        // console.log("this.count = " + this.count);
        // this.count = this.count + 1;
    }
});

cc._RF.pop();
},{}],"viewManager":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'c2b58Q1/V5Ip4c2V3uuBiR6', 'viewManager');
// script/tool/viewManager.js

"use strict";

cc.Class({
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
        view: null,
        viewName: null
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
    },

    changeView: function changeView(viewName) {
        if (!this.viewList.empty() && this.viewList.back() == viewName) {
            console.log("view is same");
            return this.view;
        }

        var viewAbout = this.viewInfo[viewName];
        console.log("wocao 1");
        console.log("wocao 2");

        var idx = this.viewList.find(viewName);
        if (idx != this.viewList.npos) {
            var len = this.viewList.getSize() - idx;
            this.viewList.remove(idx, len);
        } else {
            this.viewList.pushBack(viewName);
        }
        console.log("wocao 3");

        var self = this;
        //通过链接 加载的资源 必须放在resource下
        cc.loader.loadRes(viewAbout.module, function (err, prefab) {
            var root = cc.instantiate(prefab);
            cc.director.getScene().getChildByName("Canvas").addChild(root);
            if (self.view != null) {
                self.view.removeFromParent();
                self.view = null;
            }
            self.view = root;
        });

        this.viewName = viewName;
        return this.view;
    },

    curView: function curView() {
        // this.testAddChild();
        var self = this;
        cc.tool.eventManager.addEventListener("hahaha", self, self.testAddChild);
        cc.tool.eventManager.testWorkListener();
        this.view.removeFromParent(false);
        cc.loader.releaseRes("prefab/Test1Panel");

        return this.view;
    },

    testAddChild: function testAddChild(varName) {
        if (varName == "hahaha") {
            console.log("wocao tamabi");
        } else if (varName = "wocaonima") {
            console.log("??? wodetian");
        }
    },

    curViewName: function curViewName() {
        return this.viewName;
    },

    backPreview: function backPreview() {
        if (this.viewList.getSize() > 0) {
            this.viewList.popBack();

            var viewName = this.viewList.back();
            var viewAbout = this.viewInfo[viewName];
            if (viewAbout == null) {
                if (this.view != null) {
                    this.view.removeFromParent();
                }
                this.viewName = null;
                this.view = null;
                return null;
            }

            var self = this;
            cc.loader.loadRes(viewAbout.module, function (err, prefab) {
                var root = cc.instantiate(prefab);
                cc.director.getScene().getChildByName("Canvas").addChild(root);
                if (self.view != null) {
                    self.view.removeFromParent();
                    self.view = null;
                }
                self.view = root;
            });
            this.viewName = viewName;
            return this.view;
        }
        return null;
    }
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
},{}]},{},["ListView","Renderer","appStart","config","langZh","array1","kmView","timeHandler","testTs","eventManager","test","viewManager","viewRegister","gameVariable"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9MaXN0Vmlldy5qcyIsImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9SZW5kZXJlci5qcyIsImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvY29uZmlnLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL2V2ZW50TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdmFyaWFibGUvZ2FtZVZhcmlhYmxlLmpzIiwiYXNzZXRzL3NjcmlwdC9tb2R1bGUva21WaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvbGFuZ1poLmpzIiwiYXNzZXRzL3NjcmlwdC90ZXN0VHMudHMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdGVzdC5qcyIsImFzc2V0cy9zY3JpcHQvcHJvY2Vzcy90aW1lSGFuZGxlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3UmVnaXN0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6Ijs7Ozs7Ozs7Ozs7QUFBQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDSTtBQUNBO0FBRlE7O0FBTVo7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUE5QlE7O0FBaUNaO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0k7QUFHQTtBQUNIO0FBQ0o7QUFFRztBQUNJO0FBR0E7QUFDSDtBQUNKO0FBQ0o7O0FBekVMO0FBNEVRO0FBQ0g7QUFRRzs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDtBQUdHOztBQUVBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNIO0FBQ0o7QUFHRztBQUNBO0FBQ0g7Ozs7Ozs7Ozs7QUN4SUw7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTtBQWpDSzs7Ozs7Ozs7Ozs7O0FDQVQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTs7QUFHQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWlE7O0FBZVo7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTs7O0FBR0E7QUFDQTs7QUFFQTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQXJFSTs7Ozs7Ozs7OztBQzlCVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFiUTtBQWVaO0FBQ0E7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBRUc7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUNKO0FBQ0o7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNJO0FBRUE7QUFDSTtBQURKO0FBR0k7QUFESjtBQUdIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFFRztBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQURKO0FBR0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBdEhJOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7QUFDQTtBQUNBOztBQUVBOzs7Ozs7Ozs7O0FDTkE7QUFDQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVhROztBQWNaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBQ0E7QUFDQTtBQUNIO0FBQ0Q7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBOURJOzs7Ozs7Ozs7O0FDSFQ7O0FBRUE7O0FBRUE7Ozs7Ozs7Ozs7QUNKQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVhROztBQWNaO0FBQ0E7QUFDSTs7QUFFQTtBQUNBO0FBQ0k7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7QUFJSjs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTs7QUFFQTs7QUFFSTtBQUNIO0FBakRJOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7O0FBRUE7Ozs7Ozs7OztBQ0pNO0FBR047QUFBc0M7QUFEdEM7QUFBQTtBQVNJOztBQU1KO0FBSkk7QUFDSTtBQUVKO0FBQ0o7QUFBQTtBQVhJO0FBREM7QUFDZTtBQUtoQjtBQUhDO0FBQ0c7QUFDSDtBQUNzQjtBQVJOO0FBRHBCO0FBQ29CO0FBQUE7Ozs7Ozs7Ozs7QUNIckI7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBdkJJOzs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBOztBQUdBO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIO0FBaENJOzs7Ozs7Ozs7O0FDRVQ7QUFDSTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFkUTs7QUFpQlo7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUVIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDtBQUNEOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDSDtBQUNEO0FBQ0g7O0FBRUQ7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFFRztBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTs7QUFFQTtBQUNBO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBQ0Q7QUFDSDtBQUNEO0FBQ0E7QUFDSDtBQUNEO0FBQ0g7QUFsSkk7Ozs7Ozs7Ozs7QUNGVDs7QUFHQSIsInNvdXJjZXNDb250ZW50IjpbInZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuXG4gICAgICAgIHNjcm9sbFZpZXc6IHtcbiAgICAgICAgICAgIGRlZmF1bHQ6IG51bGwsXG4gICAgICAgICAgICB0eXBlOiBjYy5TY3JvbGxWaWV3XG4gICAgICAgIH0sXG5cbiAgICAgICAgXG4gICAgICAgIGRpcjogMCwgXG4gICAgICAgIGxpbmVzOiAwLCBcbiAgICAgICAgaGdhcDogMCwgXG4gICAgICAgIHZnYXA6IDAsIFxuICAgICAgICB3aWR0aDogMCwgXG4gICAgICAgIGhlaWdodDogMCxcbiAgICAgICAgXG5cbiAgICAgICAgZHA6IGFycmF5MSxcbiAgICAgICAgaXRlbTogY2MuUHJlZmFiLFxuICAgICAgICBpdGVtUHdkOiBudWxsLFxuICAgICAgICBpdGVtSGVpZ2h0OiAwLFxuICAgICAgICBpdGVtV2lkdGg6IDAsXG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICB0aGlzLnVwZGF0ZVRpbWVyID0gMDtcbiAgICAgICAgZHAgPSBudWxsO1xuICAgIH0sXG5cbiAgICBjcmVhdGU6IGZ1bmN0aW9uKGRpciwgbGluZXMsIGhnYXAsIHZnYXAsIHdpZHRoLCBoZWlnaHQpIHtcbiAgICAgICAgdGhpcy5kaXIgPSBkaXI7XG4gICAgICAgIHRoaXMubGluZXMgPSBsaW5lcztcbiAgICAgICAgdGhpcy5oZ2FwID0gaGdhcDtcbiAgICAgICAgdGhpcy52Z2FwID0gdmdhcDtcbiAgICAgICAgdGhpcy53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLmhlaWdodCA9IGhlaWdodDtcblxuXG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LmhlaWdodCA9IGhlaWdodDtcbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLm5vZGUucGFyZW50LmhlaWdodCA9IGhlaWdodDtcblxuICAgICAgICAvLyB0aGlzLm5vZGUucGFyZW50LnBhcmVudC5zZXRDb250ZW50U2l6ZShjYy5TaXplKHdpZHRoLCBoZWlnaHQpKTtcbiAgICAgICAgLy8gdGhpcy5ub2RlLnBhcmVudC5zZXRDb250ZW50U2l6ZShjYy5TaXplKHdpZHRoLCBoZWlnaHQpKTtcbiAgICAgICAgaWYoZGlyID09IGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMKXtcbiAgICAgICAgICAgIHRoaXMuY2FsY1NlY3Rpb24gPSBmdW5jdGlvbihzZWxmKSB7XG4gICAgICAgICAgICAgICAgaWYoIXNlbGYuZHAgfHwgc2VsZi5kcC5zaXplKCkgPT0gMCl7XG4gICAgICAgICAgICAgICAgICAgIFxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB2YXIgaW50ZXJ2YWwgPSBzZWxmLml0ZW1IZWlnaHQgKyBzZWxmLnZnYXA7XG4gICAgICAgICAgICB9O1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLmNhbGNTZWN0aW9uID0gZnVuY3Rpb24oc2VsZikge1xuICAgICAgICAgICAgICAgIGlmKCFzZWxmLmRwIHx8IHNlbGYuZHAuc2l6ZSgpID09IDApe1xuICAgICAgICAgICAgICAgICAgICBcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgdmFyIGludGVydmFsID0gc2VsZi5pdGVtSGVpZ2h0ICsgc2VsZi52Z2FwO1xuICAgICAgICAgICAgfTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2codGhpcy53aWR0aCArIFwiIHdvY2FvIFwiICsgdGhpcy5oZWlnaHQpO1xuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICBzZXRJdGVtTW9kZWw6IGZ1bmN0aW9uKGl0ZW0sIGl0ZW1XaWR0aCwgaXRlbUhlaWdodCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG5cbiAgICAgICAgdGhpcy5pdGVtUHdkID0gaXRlbTtcbiAgICAgICAgLy8gY2MubG9hZGVyLmxvYWRSZXMoaXRlbSwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgIC8vICAgICAvLyBjYy50b29sLnByZWZhYi5saXN0VmlldyA9IHByZWZhYjtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwidHlwZSBwcmVmYWIgPSBcIiArIHR5cGVvZiBwcmVmYWIpXG4gICAgICAgIC8vICAgICBzZWxmLml0ZW0gPSBwcmVmYWI7XG4gICAgICAgIC8vIH0pO1xuICAgICAgICBjYy5sb2FkZXIubG9hZFJlcyhpdGVtLCBjYy5QcmVmYWIpO1xuICAgICAgICBzZWxmLml0ZW1XaWR0aCA9IGl0ZW1XaWR0aDtcbiAgICAgICAgc2VsZi5pdGVtSGVpZ2h0ID0gaXRlbUhlaWdodDtcbiAgICB9LFxuXG4gICAgc2V0RGF0YVByb3ZpZGVyOiBmdW5jdGlvbihkbCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG5cbiAgICAgICAgaWYodGhpcy5kaXIgPT0gY2MudG9vbC5jb25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwpe1xuICAgICAgICAgICAgdGhpcy5ub2RlLmhlaWdodCA9IGRsLmdldFNpemUoKSAqICh0aGlzLml0ZW1IZWlnaHQgKyB0aGlzLmhnYXApIC0gdGhpcy5oZ2FwO1xuICAgICAgICAgICAgdGhpcy5ub2RlLndpZHRoID0gdGhpcy53aWR0aDtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgdGhpcy5ub2RlLmhlaWdodCA9IHRoaXMuaGVpZ2h0O1xuICAgICAgICB9ICAgIFxuXG4gICAgICAgIGRsLmV4Y3V0ZVdpdGhGdW5jKGZ1bmN0aW9uKGRhdGEsIGluZGV4KXtcbiAgICAgICAgICAgIHZhciBwcmVmYWIgPSBjYy5sb2FkZXIuZ2V0UmVzKHNlbGYuaXRlbVB3ZCwgY2MuUHJlZmFiKTtcblxuICAgICAgICAgICAgbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgaXRlbS5zZXRQb3MoMCwgLXNlbGYuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuXG4gICAgICAgICAgICAvLyBjYy5sb2FkZXIuZ2V0UmVzKHNlbGYuaXRlbVB3ZCwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgICAgICAvLyAgICAgbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vICAgICAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vICAgICBpdGVtLnNldFBvcygwLCAtc2VsZi5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gICAgIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuICAgICAgICAgICAgLy8gfSk7XG5cbiAgICAgICAgICAgIC8vIGxldCBpdGVtID0gY2MuaW5zdGFudGlhdGUoc2VsZi5pdGVtKS5nZXRDb21wb25lbnQoJ1JlbmRlcmVyJyk7XG4gICAgICAgICAgICAvLyAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vIGl0ZW0uc2V0UG9zKDAsIC1zZWxmLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyBzZWxmLm5vZGUuYWRkQ2hpbGQoaXRlbS5ub2RlKTtcbiAgICAgICAgfSk7XG4gICAgfSxcblxuICAgIHVwZGF0ZSAoZHQpIHtcbiAgICAgICAgdGhpcy51cGRhdGVUaW1lciArPSBkdDtcbiAgICAgICAgaWYodGhpcy51cGRhdGVUaW1lciA8IHRoaXMudXBkYXRlSW50ZXJ2YWwpIHJldHVybjtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgc2V0UG9zWTogZnVuY3Rpb24oeSkge1xuICAgICAgICB0aGlzLm5vZGUueSA9IHk7XG4gICAgfSxcblxuICAgIHNldFBvczogZnVuY3Rpb24oeCwgeSkge1xuICAgICAgICB0aGlzLm5vZGUueCA9IHg7XG4gICAgICAgIHRoaXMubm9kZS55ID0geTtcbiAgICB9XG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJmdW5jdGlvbiBpbml0KCl7XG4gICAgY2MudG9vbCA9IHt9XG4gICAgdmFyIHZpZXdNYW5hZ2VyID0gcmVxdWlyZShcInZpZXdNYW5hZ2VyXCIpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIgPSBuZXcgdmlld01hbmFnZXIoKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyLmluaXQoKTtcblxuXG4gICAgcmVxdWlyZShcInZpZXdSZWdpc3RlclwiKTtcbiAgICB2aWV3UmVnaXN0ZXIoKTtcblxuICAgIHZhciB0aW1lSGFuZGxlciA9IHJlcXVpcmUoXCJ0aW1lSGFuZGxlclwiKTtcbiAgICBjYy50b29sLnRpbWVIYW5kbGVyID0gbmV3IHRpbWVIYW5kbGVyKCk7XG5cbiAgICB2YXIgZXZlbnRNYW5hZ2VyID0gcmVxdWlyZShcImV2ZW50TWFuYWdlclwiKTtcbiAgICBjYy50b29sLmV2ZW50TWFuYWdlciA9IG5ldyBldmVudE1hbmFnZXIoKTtcblxuICAgIGNjLnRvb2wuZ2FtZVZhcmlhYmxlID0gcmVxdWlyZShcImdhbWVWYXJpYWJsZVwiKTtcbiAgICBjYy50b29sLkxhbmcgPSByZXF1aXJlKFwibGFuZ1poXCIpO1xuXG4gICAgY2MudG9vbC5wcmVmYWIgPSB7fTtcbiAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJoYWhhaGFcIiwgXCJoZWhlaGVcIiwgXCJoaWhpaGlcIik7XG5cbiAgICBjYy50b29sLmNvbmZpZyA9IHJlcXVpcmUoXCJjb25maWdcIik7XG59XG5cbmZ1bmN0aW9uIHZpZXdSZWdpc3Rlcigpe1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImttVmlld1wiLCBcInVpL2ttVmlld1wiLCAyKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJraWxpZTVWaWV3XCIsIFwidWkva2lsaWU1Vmlld1wiLCAyKTtcbn1cblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgaGFoYTogW10sXG4gICAgICAgIGNvdW50OiAwLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgaW5pdCgpO1xuXG4gICAgICAgIC8vIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgLy8gY2MubG9hZGVyLmxvYWRSZXMoXCJjb250cm9sL0xpc3RWaWV3XCIsIGNjLlByZWZhYiwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAvLyAgICAgLy8gY2MudG9vbC5wcmVmYWIubGlzdFZpZXcgPSBwcmVmYWI7XG4gICAgICAgIC8vICAgICBjb25zb2xlLmxvZyhcInR5cGUgcHJlZmFiID0gXCIgKyB0eXBlb2YgcHJlZmFiKVxuXG4gICAgICAgIC8vICAgICB2YXIgcm9vdCA9IGNjLmluc3RhbnRpYXRlKHByZWZhYik7XG4gICAgICAgIC8vICAgICByb290LnNldFBvc2l0aW9uKGNjLnYyKDAsIDApKTtcbiAgICAgICAgLy8gICAgIGxldCBsaXN0VmlldyA9IHJvb3QuZ2V0Q2hpbGRCeU5hbWUoXCJ2aWV3XCIpLmdldENoaWxkQnlOYW1lKFwiY29udGVudFwiKS5nZXRDb21wb25lbnQoXCJMaXN0Vmlld1wiKTtcbiAgICAgICAgLy8gICAgIGxpc3RWaWV3LmNyZWF0ZShjYy50b29sLmNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCwgMSwgMSwgMSwgMjQwLCAxNTApO1xuICAgICAgICAvLyAgICAgbGlzdFZpZXcuc2V0SXRlbU1vZGVsKFwiY29udHJvbC9SZW5kZXJlclwiLCAxNjAsIDYwKTtcblxuICAgICAgICAvLyAgICAgdmFyIGFycmF5ID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICAgICAgLy8gICAgIHZhciB0ZXN0ID0gbmV3IGFycmF5KCk7XG4gICAgICAgIC8vICAgICBmb3IoaSA9IDA7IGkgPCA1OyBpKyspe1xuICAgICAgICAvLyAgICAgICAgIHRlc3QucHVzaEJhY2soaSArIDEwMClcbiAgICAgICAgLy8gICAgIH1cblxuICAgICAgICAvLyAgICAgbGlzdFZpZXcuc2V0RGF0YVByb3ZpZGVyKHRlc3QpO1xuXG5cbiAgICAgICAgLy8gICAgIHNlbGYubm9kZS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgLy8gfSk7XG5cbiAgICAgICAgdGhpcy5zY2hlZHVsZShmdW5jdGlvbigpe1xuICAgICAgICAgICAgdGhpcy51cGRhdGVUaW1lKCk7XG4gICAgICAgIH0sIDEpO1xuICAgIH0sXG5cbiAgICB1cGRhdGVUaW1lOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0aGlzLmNvdW50ID0gXCIgKyB0aGlzLmNvdW50KTtcbiAgICAgICAgdGhpcy5jb3VudCA9IHRoaXMuY291bnQgKyAxO1xuICAgICAgICBjYy50b29sLmV2ZW50TWFuYWdlci5WQVJfQ0hBTkdFKFwic2VjMVwiKTtcbiAgICAgICAgY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjID0gY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjICsgMTtcbiAgICB9LFxuXG4gICAgaW5pdFNjZW5lOiBmdW5jdGlvbigpIHtcbiAgICAgICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5zZXRSb290KHRoaXMubm9kZSk7XG4gICAgICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImhhaGhhaGFoYWFcIik7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidGVzdCB0eXBlXCIgKyB0eXBlb2YgdGhpcy5oYWhhW1wid29jYW9cIl0pO1xuICAgIH0sXG5cbiAgICB0ZXN0UmVtb3ZlOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwia21WaWV3XCIpO1xuICAgIH0sXG5cbiAgICBidG5CYWNrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5iYWNrUHJldmlldygpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBsaXN0OiBbXSxcbiAgICAgICAgc2l6ZTogMCxcbiAgICAgICAgbnBvczogLTEsXG4gICAgfSxcbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b3JrZWRcIik7XG4gICAgfSxcblxuICAgIGFzZmRmc2RmOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2codHlwZW9mIHRoaXMubGlzdCk7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW9cIik7XG4gICAgfSxcblxuICAgIHN0YXR1czogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwic2VsZi5zaXplMVwiKTtcbiAgICAgICAgY29uc29sZS5sb2codGhpcy5zaXplKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJzZWxmLnNpemUyXCIpO1xuICAgIH0sXG4gICAgLy9cbiAgICBwdXNoQmFjazogZnVuY3Rpb24oZGF0YSkge1xuICAgICAgICB0aGlzLmxpc3RbdGhpcy5zaXplXSA9IGRhdGE7XG4gICAgICAgIHRoaXMuc2l6ZSA9IHRoaXMuc2l6ZSArIDE7XG4gICAgfSxcblxuICAgIGF0OiBmdW5jdGlvbihpZHgpe1xuICAgICAgICByZXR1cm4gdGhpcy5saXN0W2lkeF07XG4gICAgfSxcblxuICAgIGZpbmQ6IGZ1bmN0aW9uKHZhbHVlKXtcbiAgICAgICAgdmFyIGluZGV4ID0gdGhpcy5ucG9zO1xuICAgICAgICBpZiAodHlwZW9mIHZhbHVlID09IFwiZnVuY3Rpb25cIil7XG4gICAgICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKyl7XG4gICAgICAgICAgICAgICAgaWYodmFsdWUoaSkpIHJldHVybiBpO1xuICAgICAgICAgICAgfVxuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKyl7XG4gICAgICAgICAgICAgICAgaWYodGhpcy5saXN0W2ldID09IHZhbHVlKXtcbiAgICAgICAgICAgICAgICAgICAgaW5kZXggPSBpO1xuICAgICAgICAgICAgICAgICAgICBicmVhaztcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICAgICAgcmV0dXJuIGluZGV4O1xuICAgIH0sXG5cbiAgICByZW1vdmU6IGZ1bmN0aW9uKHBvcywgbGVuKXtcbiAgICAgICAgaWYocG9zIDwgMCkgcG9zID0gMDtcbiAgICAgICAgaWYobGVuID09IG51bGwgfHwgbGVuIDw9IDApe1xuICAgICAgICAgICAgbGVuID0gMTtcbiAgICAgICAgfVxuICAgICAgICBpZihwb3MgPCB0aGlzLnNpemUpe1xuICAgICAgICAgICAgaWYocG9zICsgbGVuID4gdGhpcy5zaXplKVxuICAgICAgICAgICAgICAgIGxlbiA9IHRoaXMuc2l6ZSAtIHBvcztcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IGxlbjsgaSsrKVxuICAgICAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbcG9zICsgaV07XG4gICAgICAgICAgICBmb3IoaSA9IHBvcyArIGxlbjsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxuICAgICAgICAgICAgICAgIHRoaXMubGlzdFtpIC0gbGVuXSA9IHRoaXMubGlzdFtpXTtcbiAgICAgICAgICAgIHRoaXMuc2l6ZSA9IHRoaXMuc2l6ZSAtIGxlbjtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBjbGVhcjogZnVuY3Rpb24oKXtcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICBkZWxldGUgdGhpcy5saXN0W2ldO1xuICAgICAgICB0aGlzLnNpemUgPSAwO1xuICAgIH0sXG5cbiAgICBnZXRTaXplOiBmdW5jdGlvbigpIHtcbiAgICAgICAgcmV0dXJuIHRoaXMuc2l6ZTtcbiAgICB9LFxuXG4gICAgYmFjazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGlmKHRoaXMuc2l6ZSA+IDApe1xuICAgICAgICAgICAgcmV0dXJuIHRoaXMubGlzdFt0aGlzLnNpemUgLSAxXTtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgZW1wdHk6IGZ1bmN0aW9uKCkge1xuICAgICAgICByZXR1cm4gdGhpcy5zaXplID09IDA7XG4gICAgfSxcblxuICAgIG91dFB1dDogZnVuY3Rpb24oKSB7XG4gICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxuICAgICAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50XCIgKyBpICsgXCIgPSBcIiArIHRoaXMubGlzdFtpXSk7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiZWxlbWVudCBzaXplID0gXCIgKyB0aGlzLnNpemUpO1xuICAgIH0sXG5cbiAgICBleGN1dGVXaXRoRnVuYzogZnVuY3Rpb24oZnVuYykge1xuICAgICAgICBmb3IodmFyIGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgZnVuYyh0aGlzLmxpc3RbaV0sIGkpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIHBvcEJhY2s6IGZ1bmN0aW9uKCkge1xuICAgICAgICBpZih0aGlzLnNpemUgPiAwKXtcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbdGhpcy5zaXplIC0gMV07XG4gICAgICAgICAgICB0aGlzLnNpemUgPSB0aGlzLnNpemUgLSAxO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsInZhciBDb25maWcgPSB7fTtcblxuQ29uZmlnLkRpcmVjdGlvbiA9IHt9O1xuQ29uZmlnLkRpcmVjdGlvbi5WRVJUSUNBTCA9IDA7XG5Db25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwgPSAxO1xuXG5tb2R1bGUuZXhwb3J0cyA9IENvbmZpZzsiLCJ2YXIgYXJyYXkxID0gcmVxdWlyZShcImFycmF5MVwiKVxudmFyIHRlc3QgPSByZXF1aXJlKFwidGVzdFwiKVxuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogdGVzdCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgZXZlbnRMaXN0ZW5lcjogW10sXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBcbiAgICB9LFxuXG4gICAgaW5pdDogZnVuY3Rpb24oKSB7XG4gICAgICAgIHRoaXMuc3VwZXIudGVzdFdvcmsoKTtcbiAgICB9LFxuXG4gICAgdGVzdFdvcms6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInplbm1lIGh1aSB6aGV5YW5nXCIpO1xuICAgIH0sXG5cbiAgICBhZGRFdmVudExpc3RlbmVyOiBmdW5jdGlvbihldmVudFR5cGUsIHRhcmdldCwgZnVuYykge1xuICAgICAgICB0YXJnZXQub3V0cHV0KCk7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKClcbiAgICAgICAgaWYoIXRhcmdldCB8fCAhZnVuYykgcmV0dXJuO1xuICAgICAgICBpZighdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0pe1xuICAgICAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0gPSBuZXcgYXJyYXkxKCk7XG4gICAgICAgIH1cbiAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0ucHVzaEJhY2soe3RhcmdldDp0YXJnZXQsIGZ1bmM6ZnVuY30pO1xuICAgIH0sXG5cbiAgICB0ZXN0V29ya0xpc3RlbmVyOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0byB0ZXN0IGxpc3RlbmVyXCIpO1xuICAgICAgICBmb3IodmFyIGtleSBpbiB0aGlzLmV2ZW50TGlzdGVuZXJbXCJoYWhhaGFcIl0pe1xuICAgICAgICAgICAgdmFyIGZ1bmMgPSB0aGlzLmV2ZW50TGlzdGVuZXJbXCJoYWhhaGFcIl1ba2V5XTtcbiAgICAgICAgICAgIGZ1bmMoXCJoYWhhaGFcIik7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgZGlzcGF0Y2hFdmVudExpc3RlbmVyOiBmdW5jdGlvbihldmVudFR5cGUpIHtcbiAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0uZXhjdXRlV2l0aEZ1bmMoZnVuY3Rpb24oaXRlbSwgaW5kZXgpe1xuICAgICAgICAgICAgdmFyIGZ1bmMgPSBpdGVtLmZ1bmM7XG4gICAgICAgICAgICB2YXIgdGFyZ2V0ID0gaXRlbS50YXJnZXQ7XG4gICAgICAgICAgICBmdW5jKHRhcmdldCwgZXZlbnRUeXBlKTtcbiAgICAgICAgfSlcbiAgICAgICAgLy8gZm9yKHZhciBrZXkgaW4gdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0pe1xuICAgICAgICAvLyAgICAgdmFyIGZ1bmMgPSB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXVtrZXldO1xuICAgICAgICAvLyAgICAgZnVuYyhrZXksIGV2ZW50VHlwZSk7XG4gICAgICAgIC8vIH1cbiAgICB9LFxuXG4gICAgVkFSX0NIQU5HRTogZnVuY3Rpb24odmFyTmFtZSl7XG4gICAgICAgIHRoaXMuZGlzcGF0Y2hFdmVudExpc3RlbmVyKHZhck5hbWUpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJ2YXIgZ2FtZVZhciA9IFtdO1xuXG5nYW1lVmFyLnNlYyA9IDA7XG5cbm1vZHVsZS5leHBvcnRzID0gZ2FtZVZhcjsiLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBldmVudFR5cGU6IG51bGwsXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICB0aGlzLmV2ZW50VHlwZSA9IG5ldyBBcnJheShcInNlYzFcIiwgXCJzZWMyXCIsIFwic2VjM1wiKTtcbiAgICAgICAgXG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgZm9yKHZhciBpID0gMDsgaSA8IHRoaXMuZXZlbnRUeXBlLmxlbmd0aDsgaSsrKXtcbiAgICAgICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLmFkZEV2ZW50TGlzdGVuZXIoc2VsZi5ldmVudFR5cGVbaV0sIHNlbGYsIHNlbGYub25WYXJDYWxsYmFjayk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgb25WYXJDYWxsYmFjazogZnVuY3Rpb24oc2VsZiwgdmFyTmFtZSkge1xuICAgICAgICBpZih2YXJOYW1lID09IFwic2VjMVwiKXtcbiAgICAgICAgICAgIC8vc2VsZi5vdXRwdXQoKTtcbiAgICAgICAgICAgIHNlbGYubm9kZS5nZXRDaGlsZEJ5TmFtZShcInR4dGhhaGFcIikuZ2V0Q29tcG9uZW50KGNjLkxhYmVsKS5zdHJpbmcgPSBcInNlYyA9IFwiICsgY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjO1xuICAgICAgICB9XG4gICAgICAgIGVsc2UgaWYodmFyTmFtZSA9PSBcIlwiKXtcblxuICAgICAgICB9XG4gICAgfSxcblxuICAgIG91dHB1dDogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3byBjYW8gbmkgbWEgZ2UgY2hvdSBoYWlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBidG5UZWFtOiBmdW5jdGlvbigpIHtcbiAgICAgICAgXG4gICAgICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImtpbGllNVZpZXdcIik7XG4gICAgfSxcbn0pO1xuIiwidmFyIExhbmcgPSBbXTtcblxuTGFuZ1tcIklURU1fVkFMVUVcIl0gPSBcIuWPmOaIkOS4reaWh+eahOaDheWGtVwiO1xuXG5tb2R1bGUuZXhwb3J0cyA9IExhbmc7IiwiY29uc3Qge2NjY2xhc3MsIHByb3BlcnR5fSA9IGNjLl9kZWNvcmF0b3I7XG5cbkBjY2NsYXNzXG5leHBvcnQgZGVmYXVsdCBjbGFzcyBOZXdDbGFzcyBleHRlbmRzIGNjLkNvbXBvbmVudCB7XG5cbiAgICBAcHJvcGVydHkoY2MuTGFiZWwpXG4gICAgbGFiZWw6IGNjLkxhYmVsO1xuXG4gICAgQHByb3BlcnR5KHtcbiAgICAgICAgZGVmYXVsdDogJ2hlbGxvJ1xuICAgIH0pXG4gICAgdGV4dDogc3RyaW5nID0gJ2hlbGxvJztcblxuICAgIG9uTG9hZCgpIHtcbiAgICAgICAgLy8gaW5pdCBsb2dpY1xuICAgICAgICBcbiAgICB9XG59XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICB0ZXN0V29yazogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyBuaW1hYmlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGNvdW50OiAwLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiemVubSBlaHVpemhleWFuZ1wiKTtcbiAgICAgICAgdGhpcy5zY2hlZHVsZShmdW5jdGlvbigpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJoYWhhaGFoYWhoYVwiKTtcbiAgICAgICAgfSwgMSk7XG4gICAgfSxcblxuICAgIGRvc29tZXRoaW5nOiBmdW5jdGlvbigpe1xuICAgICAgICBjb25zb2xlLmxvZyhcImRzZ2ZzZGFndmRnYVwiKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2coXCJ0aGlzLmNvdW50ID0gXCIgKyB0aGlzLmNvdW50KTtcbiAgICAgICAgLy8gdGhpcy5jb3VudCA9IHRoaXMuY291bnQgKyAxO1xuICAgIH0sXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiXG5cbmNjLkNsYXNzKHtcbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIHZpZXdMaXN0OiBudWxsLFxuICAgICAgICB2aWV3SW5mbzogW10sXG4gICAgICAgIHZpZXc6IG51bGwsXG4gICAgICAgIHZpZXdOYW1lOiBudWxsLFxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJoaGhlaGVoZVwiKTtcbiAgICAgICAgdmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3QgPSBuZXcgYXJyYXkxKCk7XG4gICAgICAgIC8vIHRoaXMuYXJyYXkxID0gbmV3IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIHRoaXMudmlld0xpc3QucHVzaEJhY2soe2E6MSwgYjoyfSk7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBzZXRSb290OiBmdW5jdGlvbihub2RlKSB7XG4gICAgICAgIHRoaXMucm9vdCA9IG5vZGU7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICAvLyBjb25zb2xlLmxvZyhcImhhaGFoYWhoYVwiKTtcblxuICAgICAgICAvLyBjYy52YXJpYWJsZS52aWV3SW5mby5hc2ZkZnNkZigpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy52aWV3TmFtZSk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBpbml0OiBmdW5jdGlvbigpe1xuICAgICAgICB0aGlzLnZpZXdJbmZvID0gW107XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGhpcyAxXCIpO1xuICAgICAgICB0aGlzLnZpZXdJbmZvW1wiaGFoYVwiXSA9IHthOjEsIGI6Mn07XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGhpcyAyXCIpO1xuICAgIH0sXG5cbiAgICByZWdpc3RWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSwgbW9kdWxlLCB0aXRsZSl7XG4gICAgICAgIHRoaXMudmlld0luZm9bdmlld05hbWVdID0ge3ZpZXdOYW1lOnZpZXdOYW1lLCBtb2R1bGU6bW9kdWxlLCB0aXRsZTp0aXRsZX07XG4gICAgfSxcblxuICAgIGNoYW5nZVZpZXc6IGZ1bmN0aW9uKHZpZXdOYW1lKXtcbiAgICAgICAgaWYoIXRoaXMudmlld0xpc3QuZW1wdHkoKSAmJiB0aGlzLnZpZXdMaXN0LmJhY2soKSA9PSB2aWV3TmFtZSl7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcInZpZXcgaXMgc2FtZVwiKTtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgICAgIH1cblxuICAgICAgICB2YXIgdmlld0Fib3V0ID0gdGhpcy52aWV3SW5mb1t2aWV3TmFtZV1cbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyAxXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIDJcIik7XG5cbiAgICAgICAgdmFyIGlkeCA9IHRoaXMudmlld0xpc3QuZmluZCh2aWV3TmFtZSk7XG4gICAgICAgIGlmKGlkeCAhPSB0aGlzLnZpZXdMaXN0Lm5wb3Mpe1xuICAgICAgICAgICAgdmFyIGxlbiA9IHRoaXMudmlld0xpc3QuZ2V0U2l6ZSgpIC0gaWR4O1xuICAgICAgICAgICAgdGhpcy52aWV3TGlzdC5yZW1vdmUoaWR4LCBsZW4pO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHZpZXdOYW1lKTtcbiAgICAgICAgfVxuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIDNcIik7XG5cbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICAvL+mAmui/h+mTvuaOpSDliqDovb3nmoTotYTmupAg5b+F6aG75pS+5ZyocmVzb3VyY2XkuItcbiAgICAgICAgY2MubG9hZGVyLmxvYWRSZXModmlld0Fib3V0Lm1vZHVsZSwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgICAgIGlmKHNlbGYudmlldyAhPSBudWxsKXtcbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IG51bGw7XG4gICAgICAgICAgICB9XG4gICAgICAgICAgICBzZWxmLnZpZXcgPSByb290O1xuICAgICAgICB9KTtcbiAgICAgICAgXG4gICAgICAgIHRoaXMudmlld05hbWUgPSB2aWV3TmFtZTtcbiAgICAgICAgcmV0dXJuIHRoaXMudmlldztcbiAgICB9LFxuXG4gICAgY3VyVmlldzogZnVuY3Rpb24oKSB7XG4gICAgICAgIC8vIHRoaXMudGVzdEFkZENoaWxkKCk7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgY2MudG9vbC5ldmVudE1hbmFnZXIuYWRkRXZlbnRMaXN0ZW5lcihcImhhaGFoYVwiLCBzZWxmLCBzZWxmLnRlc3RBZGRDaGlsZCk7XG4gICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLnRlc3RXb3JrTGlzdGVuZXIoKVxuICAgICAgICB0aGlzLnZpZXcucmVtb3ZlRnJvbVBhcmVudChmYWxzZSk7XG4gICAgICAgIGNjLmxvYWRlci5yZWxlYXNlUmVzKFwicHJlZmFiL1Rlc3QxUGFuZWxcIik7XG5cbiAgICAgICAgcmV0dXJuIHRoaXMudmlldztcbiAgICB9LFxuXG4gICAgdGVzdEFkZENoaWxkOiBmdW5jdGlvbih2YXJOYW1lKXtcbiAgICAgICAgaWYodmFyTmFtZSA9PSBcImhhaGFoYVwiKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gdGFtYWJpXCIpO1xuICAgICAgICB9XG4gICAgICAgIGVsc2UgaWYodmFyTmFtZSA9IFwid29jYW9uaW1hXCIpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCI/Pz8gd29kZXRpYW5cIik7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgY3VyVmlld05hbWU6IGZ1bmN0aW9uKCl7XG4gICAgICAgIHJldHVybiB0aGlzLnZpZXdOYW1lO1xuICAgIH0sXG5cbiAgICBiYWNrUHJldmlldzogZnVuY3Rpb24oKXtcbiAgICAgICAgaWYodGhpcy52aWV3TGlzdC5nZXRTaXplKCkgPiAwKXtcbiAgICAgICAgICAgIHRoaXMudmlld0xpc3QucG9wQmFjaygpO1xuXG4gICAgICAgICAgICB2YXIgdmlld05hbWUgPSB0aGlzLnZpZXdMaXN0LmJhY2soKTtcbiAgICAgICAgICAgIHZhciB2aWV3QWJvdXQgPSB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXTtcbiAgICAgICAgICAgIGlmKHZpZXdBYm91dCA9PSBudWxsKXtcbiAgICAgICAgICAgICAgICBpZih0aGlzLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMudmlldy5yZW1vdmVGcm9tUGFyZW50KCk7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHRoaXMudmlld05hbWUgPSBudWxsO1xuICAgICAgICAgICAgICAgIHRoaXMudmlldyA9IG51bGw7XG4gICAgICAgICAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgICAgICAgICB9XG5cbiAgICAgICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKHZpZXdBYm91dC5tb2R1bGUsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgICAgICB2YXIgcm9vdCA9IGNjLmluc3RhbnRpYXRlKHByZWZhYik7XG4gICAgICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgICAgICAgICBpZihzZWxmLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldy5yZW1vdmVGcm9tUGFyZW50KCk7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IG51bGw7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IHJvb3Q7XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgICAgIHRoaXMudmlld05hbWUgPSB2aWV3TmFtZTtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgICAgIH1cbiAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgfSxcbn0pO1xuIiwiY29uc29sZS5sb2coXCJoZWhlYWhoYWhhIOa1i+ivleWFqOWxgOeUqOazlVwiKTtcblxuXG5tb2R1bGUuZXhwb3J0cyA9IG51bGw7Il0sInNvdXJjZVJvb3QiOiIifQ==