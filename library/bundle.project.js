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

        dp: null,
        item: cc.Prefab,
        itemPwd: null,
        itemHeight: 0,
        itemWidth: 0
    },

    ctor: function ctor() {
        this.updateTimer = 0;
        dp = new array1();
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
},{}],"TopLayer":[function(require,module,exports){
"use strict";
cc._RF.push(module, '3892cts2ihB7qRjVzAWGZ9A', 'TopLayer');
// script/module/initui/TopLayer.js

'use strict';

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
    onLoad: function onLoad() {
        this.node.on('mousedown', function (event) {
            console.log('Mouse down');
        }, this);
    }

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

    require("viewRegister")();

    var timeHandler = require("timeHandler");
    cc.tool.timeHandler = new timeHandler();

    var eventManager = require("eventManager");
    cc.tool.eventManager = new eventManager();

    cc.tool.gameVariable = require("gameVariable");
    cc.tool.Lang = require("langZh");

    cc.tool.prefab = {};
    // cc.tool.viewManager.registView("hahaha", "hehehe", "hihihi");

    cc.tool.config = require("config");

    cc.tool.protocolInit = require("protocolInit");
    cc.tool.protocolHandler = require("protocolHandler");
    console.log("array's length = " + cc.tool.protocolInit.tmRes.length);

    var array = require("array1");
    var test = new array();
    for (var i = 10; i < 30; i++) {
        test.pushBack(i);
    }
    test.printInt();
    test.removeWithFunc(function (data) {
        return data < 20 && data > 15;
    });
    test.printInt();
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

        //暂时不用定时器
        // this.schedule(function(){
        //     this.updateTime();
        // }, 1);

        this.testFunc();
    },

    updateTime: function updateTime() {
        console.log("this.count = " + this.count);
        this.count = this.count + 1;
        // cc.tool.eventManager.VAR_CHANGE("sec1");
        cc.tool.gameVariable.sec = cc.tool.gameVariable.sec + 1;
    },

    testFunc: function testFunc() {
        var str1 = "helloword";
        this.helloword = function () {
            console.log("wotefunck");
        };
        this[str1]();
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
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    connectTest: function connectTest() {
        console.log("work connect");
        var socket = io.connect('10.10.30.234:12345', function (msg) {
            console.log(msg);
        });
        for (var i = 0; i < cc.tool.protocolInit.tmRes.length; i++) {
            socket.on(cc.tool.protocolInit.tmRes[i], cc.tool.protocolHandler[cc.tool.protocolInit.tmRes[i]]);
        }
        socket.emit('hehehaha', { abc: "wozhenderilegoule" });
    }
});

cc._RF.pop();
},{"array1":"array1","config":"config","eventManager":"eventManager","gameVariable":"gameVariable","langZh":"langZh","protocolHandler":"protocolHandler","protocolInit":"protocolInit","timeHandler":"timeHandler","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'fb6a6Ja9dNOP5bnlzovehME', 'array1');
// script/library/array1.js

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

    removeWithFunc: function removeWithFunc(func) {
        for (var i = this.size - 1; i >= 0; i--) {
            if (func(this.list[i])) {
                this.remove(i);
            }
        }
    },

    popBack: function popBack() {
        if (this.size > 0) {
            delete this.list[this.size - 1];
            this.size = this.size - 1;
        }
    },

    printInt: function printInt() {
        for (var i = 0; i < this.size; i++) {
            console.log("index " + i + " = " + this.list[i]);
        }
    }

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});

cc._RF.pop();
},{}],"baseView":[function(require,module,exports){
"use strict";
cc._RF.push(module, '33263IBzTJGgLoLm1sFU5mx', 'baseView');
// script/tool/baseView.js

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

    removeEventListener: function removeEventListener(eventType, target, func) {
        if (this.eventListener[eventType]) {
            this.eventListener[eventType].removeWithFunc(function (data) {
                return data.target == target;
            });
        }
    },

    testWorkListener: function testWorkListener() {
        console.log("to test listener");
        for (var key in this.eventListener["hahaha"]) {
            var func = this.eventListener["hahaha"][key];
            func("hahaha");
        }
    },

    dispatchEventListener: function dispatchEventListener(eventType) {
        console.log("eventType");
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
        cc.tool.viewManager.changeView("kilie5View");
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
},{}],"protocolHandler":[function(require,module,exports){
"use strict";
cc._RF.push(module, '50760Js5zVEuZ6lMcI/LAXJ', 'protocolHandler');
// script/netprotocol/protocolHandler.js

"use strict";

//就像lua里的Casefunc
var _ = [];

_.msg_buy_res = function (res) {};
_.msg_login_res = function (res) {};
_.msg_pvp_res = function (res) {
    console.log("res's text = " + res.text);
};

module.exports = _;

cc._RF.pop();
},{}],"protocolInit":[function(require,module,exports){
"use strict";
cc._RF.push(module, '28590V+IBZHjKbwC7JY9Daj', 'protocolInit');
// script/netprotocol/protocolInit.js

"use strict";

var _protocol$tmReq;

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }

//就像lua那边的netprotocol/init.lua
var protocol = [];

protocol.tmReq = [];
protocol.tmReq = (_protocol$tmReq = {}, _defineProperty(_protocol$tmReq, 0, "msg_buy_req"), _defineProperty(_protocol$tmReq, 1, "msg_login_req"), _defineProperty(_protocol$tmReq, 2, "msg_login_req"), _protocol$tmReq);

protocol.tmRes = [];
var tmRes = protocol.tmRes;
tmRes[0] = "msg_buy_res";
tmRes[1] = "msg_login_res";
tmRes[2] = "msg_pvp_res";

console.log("length " + protocol.tmRes.length);

module.exports = protocol;

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
},{}],"urlManager":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'a508dhHOy5JFp35fQ/Vb2Gw', 'urlManager');
// script/tool/urlManager.js

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

module.exports = function () {
    cc.tool.viewManager.registView("kmView", "ui/kmView", 2);
    cc.tool.viewManager.registView("kilie5View", "ui/kilie5View", 2);
};

cc._RF.pop();
},{}]},{},["ListView","Renderer","appStart","config","langZh","array1","TopLayer","kmView","protocolHandler","protocolInit","timeHandler","testTs","baseView","eventManager","test","urlManager","viewManager","viewRegister","gameVariable"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9MaXN0Vmlldy5qcyIsImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9SZW5kZXJlci5qcyIsImFzc2V0cy9zY3JpcHQvbW9kdWxlL2luaXR1aS9Ub3BMYXllci5qcyIsImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL2Jhc2VWaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvY29uZmlnLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL2V2ZW50TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdmFyaWFibGUvZ2FtZVZhcmlhYmxlLmpzIiwiYXNzZXRzL3NjcmlwdC9tb2R1bGUva21WaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvbGFuZ1poLmpzIiwiYXNzZXRzL3NjcmlwdC9uZXRwcm90b2NvbC9wcm90b2NvbEhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L25ldHByb3RvY29sL3Byb3RvY29sSW5pdC5qcyIsImFzc2V0cy9zY3JpcHQvdGVzdFRzLnRzIiwiYXNzZXRzL3NjcmlwdC90b29sL3Rlc3QuanMiLCJhc3NldHMvc2NyaXB0L3Byb2Nlc3MvdGltZUhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdXJsTWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3UmVnaXN0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6Ijs7Ozs7Ozs7Ozs7QUFBQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDSTtBQUNBO0FBRlE7O0FBTVo7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUE5QlE7O0FBaUNaO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0k7QUFHQTtBQUNIO0FBQ0o7QUFFRztBQUNJO0FBR0E7QUFDSDtBQUNKO0FBQ0o7O0FBekVMO0FBNEVRO0FBQ0g7QUFRRzs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDtBQUdHOztBQUVBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNIO0FBQ0o7QUFHRztBQUNBO0FBQ0g7Ozs7Ozs7Ozs7QUN4SUw7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTtBQWpDSzs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDSjs7QUFyQkk7Ozs7Ozs7Ozs7OztBQ0FUO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7O0FBRUE7QUFDQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDQTs7QUFFQTs7QUFFQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWlE7O0FBZVo7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTs7O0FBR0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTs7QUFFQTtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSTtBQUNIO0FBQ0Q7QUFDSDtBQWhHSTs7Ozs7Ozs7OztBQzNDVDs7QUFFSTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBYlE7QUFlWjtBQUNBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNBO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDSjtBQUVHO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7QUFDSjtBQUNKO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSTtBQUVBO0FBQ0k7QUFESjtBQUdJO0FBREo7QUFHSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQURKO0FBR0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQUNIO0FBRUc7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFESjtBQUdIOztBQUVEO0FBQ0k7QUFDSTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQUNIO0FBQ0o7O0FBRUQ7QUFDQTs7QUFFQTtBQXhJSzs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBakJLOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7QUFDQTtBQUNBOztBQUVBOzs7Ozs7Ozs7O0FDTkE7QUFDQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVhROztBQWNaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBQ0o7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUF2RUk7Ozs7Ozs7Ozs7QUNIVDs7QUFFQTs7QUFFQTs7Ozs7Ozs7OztBQ0pBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWFE7O0FBY1o7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDSTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUlKOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBOztBQUVBOztBQUVBO0FBQ0k7QUFDSDtBQWhESTs7Ozs7Ozs7OztBQ0FUOztBQUVBOztBQUVBOzs7Ozs7Ozs7O0FDSkE7QUFDQTs7QUFFQTtBQUdBO0FBR0E7QUFDSTtBQUNIOztBQUVEOzs7Ozs7Ozs7Ozs7OztBQ2JBO0FBQ0E7O0FBRUE7QUFDQTs7QUFNQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBOztBQUVBOzs7Ozs7Ozs7QUNsQk07QUFHTjtBQUFzQztBQUR0QztBQUFBO0FBU0k7O0FBTUo7QUFKSTtBQUNJO0FBRUo7QUFDSjtBQUFBO0FBWEk7QUFEQztBQUNlO0FBS2hCO0FBSEM7QUFDRztBQUNIO0FBQ3NCO0FBUk47QUFEcEI7QUFDb0I7QUFBQTs7Ozs7Ozs7OztBQ0hyQjtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFWUTs7QUFhWjtBQUNBOztBQUlBO0FBQ0k7QUFDSDs7QUF2Qkk7Ozs7Ozs7Ozs7QUNBVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVhROztBQWNaO0FBQ0E7O0FBR0E7QUFDSTtBQUNBO0FBQ0k7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFoQ0k7Ozs7Ozs7Ozs7QUNBVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFWUTs7QUFhWjtBQUNBOztBQWpCSzs7Ozs7Ozs7OztBQ0VUO0FBQ0k7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBZFE7O0FBaUJaO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFFSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDSDs7QUFFRDtBQUNBOztBQUVBOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0E7QUFDSDs7QUFFRDtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNJO0FBQ0E7QUFDSDtBQUVHO0FBQ0g7QUFDRDs7QUFFQTtBQUNBO0FBQ0E7QUFDSTtBQUNBO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFDRDtBQUNIOztBQUVEO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQUNIO0FBRUc7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7O0FBRUE7QUFDQTtBQUNBO0FBQ0k7QUFDSTtBQUNIO0FBQ0Q7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDSDtBQUNEO0FBQ0g7QUFDRDtBQUNBO0FBQ0g7QUFDRDtBQUNIO0FBbEpJOzs7Ozs7Ozs7O0FDRlQ7O0FBR0E7QUFDSTtBQUNBO0FBQ0giLCJzb3VyY2VzQ29udGVudCI6WyJ2YXIgYXJyYXkxID0gcmVxdWlyZShcImFycmF5MVwiKTtcblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cblxuICAgICAgICBzY3JvbGxWaWV3OiB7XG4gICAgICAgICAgICBkZWZhdWx0OiBudWxsLFxuICAgICAgICAgICAgdHlwZTogY2MuU2Nyb2xsVmlld1xuICAgICAgICB9LFxuXG4gICAgICAgIFxuICAgICAgICBkaXI6IDAsIFxuICAgICAgICBsaW5lczogMCwgXG4gICAgICAgIGhnYXA6IDAsIFxuICAgICAgICB2Z2FwOiAwLCBcbiAgICAgICAgd2lkdGg6IDAsIFxuICAgICAgICBoZWlnaHQ6IDAsXG4gICAgICAgIFxuXG4gICAgICAgIGRwOiBudWxsLFxuICAgICAgICBpdGVtOiBjYy5QcmVmYWIsXG4gICAgICAgIGl0ZW1Qd2Q6IG51bGwsXG4gICAgICAgIGl0ZW1IZWlnaHQ6IDAsXG4gICAgICAgIGl0ZW1XaWR0aDogMCxcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIHRoaXMudXBkYXRlVGltZXIgPSAwO1xuICAgICAgICBkcCA9IG5ldyBhcnJheTEoKTtcbiAgICB9LFxuXG4gICAgY3JlYXRlOiBmdW5jdGlvbihkaXIsIGxpbmVzLCBoZ2FwLCB2Z2FwLCB3aWR0aCwgaGVpZ2h0KSB7XG4gICAgICAgIHRoaXMuZGlyID0gZGlyO1xuICAgICAgICB0aGlzLmxpbmVzID0gbGluZXM7XG4gICAgICAgIHRoaXMuaGdhcCA9IGhnYXA7XG4gICAgICAgIHRoaXMudmdhcCA9IHZnYXA7XG4gICAgICAgIHRoaXMud2lkdGggPSB3aWR0aDtcbiAgICAgICAgdGhpcy5oZWlnaHQgPSBoZWlnaHQ7XG5cblxuICAgICAgICB0aGlzLm5vZGUucGFyZW50LnBhcmVudC53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLm5vZGUucGFyZW50LnBhcmVudC5oZWlnaHQgPSBoZWlnaHQ7XG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQud2lkdGggPSB3aWR0aDtcbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC5oZWlnaHQgPSBoZWlnaHQ7XG5cbiAgICAgICAgLy8gdGhpcy5ub2RlLnBhcmVudC5wYXJlbnQuc2V0Q29udGVudFNpemUoY2MuU2l6ZSh3aWR0aCwgaGVpZ2h0KSk7XG4gICAgICAgIC8vIHRoaXMubm9kZS5wYXJlbnQuc2V0Q29udGVudFNpemUoY2MuU2l6ZSh3aWR0aCwgaGVpZ2h0KSk7XG4gICAgICAgIGlmKGRpciA9PSBjYy50b29sLmNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCl7XG4gICAgICAgICAgICB0aGlzLmNhbGNTZWN0aW9uID0gZnVuY3Rpb24oc2VsZikge1xuICAgICAgICAgICAgICAgIGlmKCFzZWxmLmRwIHx8IHNlbGYuZHAuc2l6ZSgpID09IDApe1xuICAgICAgICAgICAgICAgICAgICBcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgdmFyIGludGVydmFsID0gc2VsZi5pdGVtSGVpZ2h0ICsgc2VsZi52Z2FwO1xuICAgICAgICAgICAgfTtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgdGhpcy5jYWxjU2VjdGlvbiA9IGZ1bmN0aW9uKHNlbGYpIHtcbiAgICAgICAgICAgICAgICBpZighc2VsZi5kcCB8fCBzZWxmLmRwLnNpemUoKSA9PSAwKXtcbiAgICAgICAgICAgICAgICAgICAgXG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHZhciBpbnRlcnZhbCA9IHNlbGYuaXRlbUhlaWdodCArIHNlbGYudmdhcDtcbiAgICAgICAgICAgIH07XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKHRoaXMud2lkdGggKyBcIiB3b2NhbyBcIiArIHRoaXMuaGVpZ2h0KTtcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgc2V0SXRlbU1vZGVsOiBmdW5jdGlvbihpdGVtLCBpdGVtV2lkdGgsIGl0ZW1IZWlnaHQpIHtcbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuXG4gICAgICAgIHRoaXMuaXRlbVB3ZCA9IGl0ZW07XG4gICAgICAgIC8vIGNjLmxvYWRlci5sb2FkUmVzKGl0ZW0sIGNjLlByZWZhYiwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAvLyAgICAgLy8gY2MudG9vbC5wcmVmYWIubGlzdFZpZXcgPSBwcmVmYWI7XG4gICAgICAgIC8vICAgICBjb25zb2xlLmxvZyhcInR5cGUgcHJlZmFiID0gXCIgKyB0eXBlb2YgcHJlZmFiKVxuICAgICAgICAvLyAgICAgc2VsZi5pdGVtID0gcHJlZmFiO1xuICAgICAgICAvLyB9KTtcbiAgICAgICAgY2MubG9hZGVyLmxvYWRSZXMoaXRlbSwgY2MuUHJlZmFiKTtcbiAgICAgICAgc2VsZi5pdGVtV2lkdGggPSBpdGVtV2lkdGg7XG4gICAgICAgIHNlbGYuaXRlbUhlaWdodCA9IGl0ZW1IZWlnaHQ7XG4gICAgfSxcblxuICAgIHNldERhdGFQcm92aWRlcjogZnVuY3Rpb24oZGwpIHtcbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuXG4gICAgICAgIGlmKHRoaXMuZGlyID09IGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMKXtcbiAgICAgICAgICAgIHRoaXMubm9kZS5oZWlnaHQgPSBkbC5nZXRTaXplKCkgKiAodGhpcy5pdGVtSGVpZ2h0ICsgdGhpcy5oZ2FwKSAtIHRoaXMuaGdhcDtcbiAgICAgICAgICAgIHRoaXMubm9kZS53aWR0aCA9IHRoaXMud2lkdGg7XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIHRoaXMubm9kZS5oZWlnaHQgPSB0aGlzLmhlaWdodDtcbiAgICAgICAgfSAgICBcblxuICAgICAgICBkbC5leGN1dGVXaXRoRnVuYyhmdW5jdGlvbihkYXRhLCBpbmRleCl7XG4gICAgICAgICAgICB2YXIgcHJlZmFiID0gY2MubG9hZGVyLmdldFJlcyhzZWxmLml0ZW1Qd2QsIGNjLlByZWZhYik7XG5cbiAgICAgICAgICAgIGxldCBpdGVtID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKS5nZXRDb21wb25lbnQoJ1JlbmRlcmVyJyk7XG4gICAgICAgICAgICAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIGl0ZW0uc2V0UG9zKDAsIC1zZWxmLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICBzZWxmLm5vZGUuYWRkQ2hpbGQoaXRlbS5ub2RlKTtcblxuICAgICAgICAgICAgLy8gY2MubG9hZGVyLmdldFJlcyhzZWxmLml0ZW1Qd2QsIGNjLlByZWZhYiwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAgICAgLy8gICAgIGxldCBpdGVtID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKS5nZXRDb21wb25lbnQoJ1JlbmRlcmVyJyk7XG4gICAgICAgICAgICAvLyAgICAgLy8gaXRlbS5zZXRQb3NZKC10aGlzLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyAgICAgaXRlbS5zZXRQb3MoMCwgLXNlbGYuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vICAgICBzZWxmLm5vZGUuYWRkQ2hpbGQoaXRlbS5ub2RlKTtcbiAgICAgICAgICAgIC8vIH0pO1xuXG4gICAgICAgICAgICAvLyBsZXQgaXRlbSA9IGNjLmluc3RhbnRpYXRlKHNlbGYuaXRlbSkuZ2V0Q29tcG9uZW50KCdSZW5kZXJlcicpO1xuICAgICAgICAgICAgLy8gLy8gaXRlbS5zZXRQb3NZKC10aGlzLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyBpdGVtLnNldFBvcygwLCAtc2VsZi5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gc2VsZi5ub2RlLmFkZENoaWxkKGl0ZW0ubm9kZSk7XG4gICAgICAgIH0pO1xuICAgIH0sXG5cbiAgICB1cGRhdGUgKGR0KSB7XG4gICAgICAgIHRoaXMudXBkYXRlVGltZXIgKz0gZHQ7XG4gICAgICAgIGlmKHRoaXMudXBkYXRlVGltZXIgPCB0aGlzLnVwZGF0ZUludGVydmFsKSByZXR1cm47XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIHNldFBvc1k6IGZ1bmN0aW9uKHkpIHtcbiAgICAgICAgdGhpcy5ub2RlLnkgPSB5O1xuICAgIH0sXG5cbiAgICBzZXRQb3M6IGZ1bmN0aW9uKHgsIHkpIHtcbiAgICAgICAgdGhpcy5ub2RlLnggPSB4O1xuICAgICAgICB0aGlzLm5vZGUueSA9IHk7XG4gICAgfVxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIHRoaXMubm9kZS5vbignbW91c2Vkb3duJywgZnVuY3Rpb24gKGV2ZW50KSB7XG4gICAgICAgICAgICBjb25zb2xlLmxvZygnTW91c2UgZG93bicpO1xuICAgICAgICB9LCB0aGlzKTtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiZnVuY3Rpb24gaW5pdCgpe1xuICAgIGNjLnRvb2wgPSB7fVxuICAgIHZhciB2aWV3TWFuYWdlciA9IHJlcXVpcmUoXCJ2aWV3TWFuYWdlclwiKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyID0gbmV3IHZpZXdNYW5hZ2VyKCk7XG4gICAgY2MudG9vbC52aWV3TWFuYWdlci5pbml0KCk7XG5cbiAgICByZXF1aXJlKFwidmlld1JlZ2lzdGVyXCIpKCk7XG5cbiAgICB2YXIgdGltZUhhbmRsZXIgPSByZXF1aXJlKFwidGltZUhhbmRsZXJcIik7XG4gICAgY2MudG9vbC50aW1lSGFuZGxlciA9IG5ldyB0aW1lSGFuZGxlcigpO1xuXG4gICAgdmFyIGV2ZW50TWFuYWdlciA9IHJlcXVpcmUoXCJldmVudE1hbmFnZXJcIik7XG4gICAgY2MudG9vbC5ldmVudE1hbmFnZXIgPSBuZXcgZXZlbnRNYW5hZ2VyKCk7XG5cbiAgICBjYy50b29sLmdhbWVWYXJpYWJsZSA9IHJlcXVpcmUoXCJnYW1lVmFyaWFibGVcIik7XG4gICAgY2MudG9vbC5MYW5nID0gcmVxdWlyZShcImxhbmdaaFwiKTtcblxuICAgIGNjLnRvb2wucHJlZmFiID0ge307XG4gICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5yZWdpc3RWaWV3KFwiaGFoYWhhXCIsIFwiaGVoZWhlXCIsIFwiaGloaWhpXCIpO1xuXG4gICAgY2MudG9vbC5jb25maWcgPSByZXF1aXJlKFwiY29uZmlnXCIpO1xuXG4gICAgY2MudG9vbC5wcm90b2NvbEluaXQgPSByZXF1aXJlKFwicHJvdG9jb2xJbml0XCIpO1xuICAgIGNjLnRvb2wucHJvdG9jb2xIYW5kbGVyID0gcmVxdWlyZShcInByb3RvY29sSGFuZGxlclwiKTtcbiAgICBjb25zb2xlLmxvZyhcImFycmF5J3MgbGVuZ3RoID0gXCIgKyBjYy50b29sLnByb3RvY29sSW5pdC50bVJlcy5sZW5ndGgpO1xuXG4gICAgdmFyIGFycmF5ID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICB2YXIgdGVzdCA9IG5ldyBhcnJheSgpO1xuICAgIGZvcih2YXIgaSA9IDEwOyBpIDwgMzA7IGkrKyl7XG4gICAgICAgIHRlc3QucHVzaEJhY2soaSk7XG4gICAgfVxuICAgIHRlc3QucHJpbnRJbnQoKTtcbiAgICB0ZXN0LnJlbW92ZVdpdGhGdW5jKGZ1bmN0aW9uKGRhdGEpe1xuICAgICAgICByZXR1cm4gZGF0YSA8IDIwICYmIGRhdGEgPiAxNTtcbiAgICB9KTtcbiAgICB0ZXN0LnByaW50SW50KCk7XG59XG5cbmZ1bmN0aW9uIHZpZXdSZWdpc3Rlcigpe1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImttVmlld1wiLCBcInVpL2ttVmlld1wiLCAyKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJraWxpZTVWaWV3XCIsIFwidWkva2lsaWU1Vmlld1wiLCAyKTtcbn1cblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgaGFoYTogW10sXG4gICAgICAgIGNvdW50OiAwLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgaW5pdCgpO1xuXG4gICAgICAgIC8vIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgLy8gY2MubG9hZGVyLmxvYWRSZXMoXCJjb250cm9sL0xpc3RWaWV3XCIsIGNjLlByZWZhYiwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAvLyAgICAgLy8gY2MudG9vbC5wcmVmYWIubGlzdFZpZXcgPSBwcmVmYWI7XG4gICAgICAgIC8vICAgICBjb25zb2xlLmxvZyhcInR5cGUgcHJlZmFiID0gXCIgKyB0eXBlb2YgcHJlZmFiKVxuXG4gICAgICAgIC8vICAgICB2YXIgcm9vdCA9IGNjLmluc3RhbnRpYXRlKHByZWZhYik7XG4gICAgICAgIC8vICAgICByb290LnNldFBvc2l0aW9uKGNjLnYyKDAsIDApKTtcbiAgICAgICAgLy8gICAgIGxldCBsaXN0VmlldyA9IHJvb3QuZ2V0Q2hpbGRCeU5hbWUoXCJ2aWV3XCIpLmdldENoaWxkQnlOYW1lKFwiY29udGVudFwiKS5nZXRDb21wb25lbnQoXCJMaXN0Vmlld1wiKTtcbiAgICAgICAgLy8gICAgIGxpc3RWaWV3LmNyZWF0ZShjYy50b29sLmNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCwgMSwgMSwgMSwgMjQwLCAxNTApO1xuICAgICAgICAvLyAgICAgbGlzdFZpZXcuc2V0SXRlbU1vZGVsKFwiY29udHJvbC9SZW5kZXJlclwiLCAxNjAsIDYwKTtcblxuICAgICAgICAvLyAgICAgdmFyIGFycmF5ID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICAgICAgLy8gICAgIHZhciB0ZXN0ID0gbmV3IGFycmF5KCk7XG4gICAgICAgIC8vICAgICBmb3IoaSA9IDA7IGkgPCA1OyBpKyspe1xuICAgICAgICAvLyAgICAgICAgIHRlc3QucHVzaEJhY2soaSArIDEwMClcbiAgICAgICAgLy8gICAgIH1cblxuICAgICAgICAvLyAgICAgbGlzdFZpZXcuc2V0RGF0YVByb3ZpZGVyKHRlc3QpO1xuXG5cbiAgICAgICAgLy8gICAgIHNlbGYubm9kZS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgLy8gfSk7XG5cbiAgICAgICAgLy/mmoLml7bkuI3nlKjlrprml7blmahcbiAgICAgICAgLy8gdGhpcy5zY2hlZHVsZShmdW5jdGlvbigpe1xuICAgICAgICAvLyAgICAgdGhpcy51cGRhdGVUaW1lKCk7XG4gICAgICAgIC8vIH0sIDEpO1xuXG4gICAgICAgIHRoaXMudGVzdEZ1bmMoKTtcbiAgICB9LFxuXG4gICAgdXBkYXRlVGltZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidGhpcy5jb3VudCA9IFwiICsgdGhpcy5jb3VudCk7XG4gICAgICAgIHRoaXMuY291bnQgPSB0aGlzLmNvdW50ICsgMTtcbiAgICAgICAgLy8gY2MudG9vbC5ldmVudE1hbmFnZXIuVkFSX0NIQU5HRShcInNlYzFcIik7XG4gICAgICAgIGNjLnRvb2wuZ2FtZVZhcmlhYmxlLnNlYyA9IGNjLnRvb2wuZ2FtZVZhcmlhYmxlLnNlYyArIDE7XG4gICAgfSxcblxuICAgIHRlc3RGdW5jOiBmdW5jdGlvbigpIHtcbiAgICAgICAgdmFyIHN0cjEgPSBcImhlbGxvd29yZFwiO1xuICAgICAgICB0aGlzLmhlbGxvd29yZCA9IGZ1bmN0aW9uKCl7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIndvdGVmdW5ja1wiKTtcbiAgICAgICAgfVxuICAgICAgICB0aGlzW3N0cjFdKCk7XG4gICAgfSxcblxuICAgIGluaXRTY2VuZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIuc2V0Um9vdCh0aGlzLm5vZGUpO1xuICAgICAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLmNoYW5nZVZpZXcoXCJoYWhoYWhhaGFhXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyhcInRlc3QgdHlwZVwiICsgdHlwZW9mIHRoaXMuaGFoYVtcIndvY2FvXCJdKTtcbiAgICB9LFxuXG4gICAgdGVzdFJlbW92ZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImttVmlld1wiKTtcbiAgICB9LFxuXG4gICAgYnRuQmFjazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNjLnRvb2wudmlld01hbmFnZXIuYmFja1ByZXZpZXcoKTtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcblxuICAgIGNvbm5lY3RUZXN0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b3JrIGNvbm5lY3RcIik7XG4gICAgICAgIHZhciBzb2NrZXQgPSBpby5jb25uZWN0KCcxMC4xMC4zMC4yMzQ6MTIzNDUnLCBmdW5jdGlvbihtc2cpe1xuICAgICAgICAgICAgY29uc29sZS5sb2cobXNnKTtcbiAgICAgICAgfSk7XG4gICAgICAgIGZvcih2YXIgaSA9IDA7IGkgPCBjYy50b29sLnByb3RvY29sSW5pdC50bVJlcy5sZW5ndGg7IGkrKyl7XG4gICAgICAgICAgICBzb2NrZXQub24oY2MudG9vbC5wcm90b2NvbEluaXQudG1SZXNbaV0sIGNjLnRvb2wucHJvdG9jb2xIYW5kbGVyW2NjLnRvb2wucHJvdG9jb2xJbml0LnRtUmVzW2ldXSk7XG4gICAgICAgIH1cbiAgICAgICAgc29ja2V0LmVtaXQoJ2hlaGVoYWhhJywge2FiYzpcIndvemhlbmRlcmlsZWdvdWxlXCJ9KTtcbiAgICB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGxpc3Q6IFtdLFxuICAgICAgICBzaXplOiAwLFxuICAgICAgICBucG9zOiAtMSxcbiAgICB9LFxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvcmtlZFwiKTtcbiAgICB9LFxuXG4gICAgYXNmZGZzZGY6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy5saXN0KTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcbiAgICB9LFxuXG4gICAgc3RhdHVzOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJzZWxmLnNpemUxXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLnNpemUpO1xuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTJcIik7XG4gICAgfSxcbiAgICAvL1xuICAgIHB1c2hCYWNrOiBmdW5jdGlvbihkYXRhKSB7XG4gICAgICAgIHRoaXMubGlzdFt0aGlzLnNpemVdID0gZGF0YTtcbiAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplICsgMTtcbiAgICB9LFxuXG4gICAgYXQ6IGZ1bmN0aW9uKGlkeCl7XG4gICAgICAgIHJldHVybiB0aGlzLmxpc3RbaWR4XTtcbiAgICB9LFxuXG4gICAgZmluZDogZnVuY3Rpb24odmFsdWUpe1xuICAgICAgICB2YXIgaW5kZXggPSB0aGlzLm5wb3M7XG4gICAgICAgIGlmICh0eXBlb2YgdmFsdWUgPT0gXCJmdW5jdGlvblwiKXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih2YWx1ZShpKSkgcmV0dXJuIGk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih0aGlzLmxpc3RbaV0gPT0gdmFsdWUpe1xuICAgICAgICAgICAgICAgICAgICBpbmRleCA9IGk7XG4gICAgICAgICAgICAgICAgICAgIGJyZWFrO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICByZXR1cm4gaW5kZXg7XG4gICAgfSxcblxuICAgIHJlbW92ZTogZnVuY3Rpb24ocG9zLCBsZW4pe1xuICAgICAgICBpZihwb3MgPCAwKSBwb3MgPSAwO1xuICAgICAgICBpZihsZW4gPT0gbnVsbCB8fCBsZW4gPD0gMCl7XG4gICAgICAgICAgICBsZW4gPSAxO1xuICAgICAgICB9XG4gICAgICAgIGlmKHBvcyA8IHRoaXMuc2l6ZSl7XG4gICAgICAgICAgICBpZihwb3MgKyBsZW4gPiB0aGlzLnNpemUpXG4gICAgICAgICAgICAgICAgbGVuID0gdGhpcy5zaXplIC0gcG9zO1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgbGVuOyBpKyspXG4gICAgICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtwb3MgKyBpXTtcbiAgICAgICAgICAgIGZvcihpID0gcG9zICsgbGVuOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICAgICAgdGhpcy5saXN0W2kgLSBsZW5dID0gdGhpcy5saXN0W2ldO1xuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gbGVuO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGNsZWFyOiBmdW5jdGlvbigpe1xuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbaV07XG4gICAgICAgIHRoaXMuc2l6ZSA9IDA7XG4gICAgfSxcblxuICAgIGdldFNpemU6IGZ1bmN0aW9uKCkge1xuICAgICAgICByZXR1cm4gdGhpcy5zaXplO1xuICAgIH0sXG5cbiAgICBiYWNrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgaWYodGhpcy5zaXplID4gMCl7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy5saXN0W3RoaXMuc2l6ZSAtIDFdO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICByZXR1cm4gbnVsbDtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBlbXB0eTogZnVuY3Rpb24oKSB7XG4gICAgICAgIHJldHVybiB0aGlzLnNpemUgPT0gMDtcbiAgICB9LFxuXG4gICAgb3V0UHV0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnRcIiArIGkgKyBcIiA9IFwiICsgdGhpcy5saXN0W2ldKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50IHNpemUgPSBcIiArIHRoaXMuc2l6ZSk7XG4gICAgfSxcblxuICAgIGV4Y3V0ZVdpdGhGdW5jOiBmdW5jdGlvbihmdW5jKSB7XG4gICAgICAgIGZvcih2YXIgaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKyl7XG4gICAgICAgICAgICBmdW5jKHRoaXMubGlzdFtpXSwgaSk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgcmVtb3ZlV2l0aEZ1bmM6IGZ1bmN0aW9uKGZ1bmMpe1xuICAgICAgICBmb3IodmFyIGkgPSB0aGlzLnNpemUgLSAxOyBpID49IDA7IGktLSl7XG4gICAgICAgICAgICBpZihmdW5jKHRoaXMubGlzdFtpXSkpe1xuICAgICAgICAgICAgICAgIHRoaXMucmVtb3ZlKGkpO1xuICAgICAgICAgICAgfVxuICAgICAgICB9XG4gICAgfSxcblxuICAgIHBvcEJhY2s6IGZ1bmN0aW9uKCkge1xuICAgICAgICBpZih0aGlzLnNpemUgPiAwKXtcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbdGhpcy5zaXplIC0gMV07XG4gICAgICAgICAgICB0aGlzLnNpemUgPSB0aGlzLnNpemUgLSAxO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIHByaW50SW50OiBmdW5jdGlvbigpe1xuICAgICAgICBmb3IodmFyIGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJpbmRleCBcIiArIGkgKyBcIiA9IFwiICsgdGhpcy5saXN0W2ldKTtcbiAgICAgICAgfVxuICAgIH1cblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsInZhciBDb25maWcgPSB7fTtcblxuQ29uZmlnLkRpcmVjdGlvbiA9IHt9O1xuQ29uZmlnLkRpcmVjdGlvbi5WRVJUSUNBTCA9IDA7XG5Db25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwgPSAxO1xuXG5tb2R1bGUuZXhwb3J0cyA9IENvbmZpZzsiLCJ2YXIgYXJyYXkxID0gcmVxdWlyZShcImFycmF5MVwiKVxudmFyIHRlc3QgPSByZXF1aXJlKFwidGVzdFwiKVxuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogdGVzdCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgZXZlbnRMaXN0ZW5lcjogW10sXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBcbiAgICB9LFxuXG4gICAgaW5pdDogZnVuY3Rpb24oKSB7XG4gICAgICAgIHRoaXMuc3VwZXIudGVzdFdvcmsoKTtcbiAgICB9LFxuXG4gICAgdGVzdFdvcms6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInplbm1lIGh1aSB6aGV5YW5nXCIpO1xuICAgIH0sXG5cbiAgICBhZGRFdmVudExpc3RlbmVyOiBmdW5jdGlvbihldmVudFR5cGUsIHRhcmdldCwgZnVuYykge1xuICAgICAgICB0YXJnZXQub3V0cHV0KCk7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKClcbiAgICAgICAgaWYoIXRhcmdldCB8fCAhZnVuYykgcmV0dXJuO1xuICAgICAgICBpZighdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0pe1xuICAgICAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0gPSBuZXcgYXJyYXkxKCk7XG4gICAgICAgIH1cbiAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0ucHVzaEJhY2soe3RhcmdldDp0YXJnZXQsIGZ1bmM6ZnVuY30pO1xuICAgIH0sXG5cbiAgICByZW1vdmVFdmVudExpc3RlbmVyOiBmdW5jdGlvbihldmVudFR5cGUsIHRhcmdldCwgZnVuYyl7XG4gICAgICAgIGlmKHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdKXtcbiAgICAgICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdLnJlbW92ZVdpdGhGdW5jKGZ1bmN0aW9uKGRhdGEpe1xuICAgICAgICAgICAgICAgIHJldHVybiBkYXRhLnRhcmdldCA9PSB0YXJnZXQ7XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICB0ZXN0V29ya0xpc3RlbmVyOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0byB0ZXN0IGxpc3RlbmVyXCIpO1xuICAgICAgICBmb3IodmFyIGtleSBpbiB0aGlzLmV2ZW50TGlzdGVuZXJbXCJoYWhhaGFcIl0pe1xuICAgICAgICAgICAgdmFyIGZ1bmMgPSB0aGlzLmV2ZW50TGlzdGVuZXJbXCJoYWhhaGFcIl1ba2V5XTtcbiAgICAgICAgICAgIGZ1bmMoXCJoYWhhaGFcIik7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgZGlzcGF0Y2hFdmVudExpc3RlbmVyOiBmdW5jdGlvbihldmVudFR5cGUpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJldmVudFR5cGVcIik7XG4gICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdLmV4Y3V0ZVdpdGhGdW5jKGZ1bmN0aW9uKGl0ZW0sIGluZGV4KXtcbiAgICAgICAgICAgIHZhciBmdW5jID0gaXRlbS5mdW5jO1xuICAgICAgICAgICAgdmFyIHRhcmdldCA9IGl0ZW0udGFyZ2V0O1xuICAgICAgICAgICAgZnVuYyh0YXJnZXQsIGV2ZW50VHlwZSk7XG4gICAgICAgIH0pXG4gICAgICAgIC8vIGZvcih2YXIga2V5IGluIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdKXtcbiAgICAgICAgLy8gICAgIHZhciBmdW5jID0gdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV1ba2V5XTtcbiAgICAgICAgLy8gICAgIGZ1bmMoa2V5LCBldmVudFR5cGUpO1xuICAgICAgICAvLyB9XG4gICAgfSxcblxuICAgIFZBUl9DSEFOR0U6IGZ1bmN0aW9uKHZhck5hbWUpe1xuICAgICAgICB0aGlzLmRpc3BhdGNoRXZlbnRMaXN0ZW5lcih2YXJOYW1lKTtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwidmFyIGdhbWVWYXIgPSBbXTtcblxuZ2FtZVZhci5zZWMgPSAwO1xuXG5tb2R1bGUuZXhwb3J0cyA9IGdhbWVWYXI7IiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgZXZlbnRUeXBlOiBudWxsLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgdGhpcy5ldmVudFR5cGUgPSBuZXcgQXJyYXkoXCJzZWMxXCIsIFwic2VjMlwiLCBcInNlYzNcIik7XG4gICAgICAgIFxuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIGZvcih2YXIgaSA9IDA7IGkgPCB0aGlzLmV2ZW50VHlwZS5sZW5ndGg7IGkrKyl7XG4gICAgICAgICAgICBjYy50b29sLmV2ZW50TWFuYWdlci5hZGRFdmVudExpc3RlbmVyKHNlbGYuZXZlbnRUeXBlW2ldLCBzZWxmLCBzZWxmLm9uVmFyQ2FsbGJhY2spO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIG9uVmFyQ2FsbGJhY2s6IGZ1bmN0aW9uKHNlbGYsIHZhck5hbWUpIHtcbiAgICAgICAgaWYodmFyTmFtZSA9PSBcInNlYzFcIil7XG4gICAgICAgICAgICAvL3NlbGYub3V0cHV0KCk7XG4gICAgICAgICAgICBzZWxmLm5vZGUuZ2V0Q2hpbGRCeU5hbWUoXCJ0eHRoYWhhXCIpLmdldENvbXBvbmVudChjYy5MYWJlbCkuc3RyaW5nID0gXCJzZWMgPSBcIiArIGNjLnRvb2wuZ2FtZVZhcmlhYmxlLnNlYztcbiAgICAgICAgfVxuICAgICAgICBlbHNlIGlmKHZhck5hbWUgPT0gXCJcIil7XG5cbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBvdXRwdXQ6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid28gY2FvIG5pIG1hIGdlIGNob3UgaGFpXCIpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxuXG4gICAgYnRuVGVhbTogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImtpbGllNVZpZXdcIik7XG4gICAgfSxcbn0pO1xuIiwidmFyIExhbmcgPSBbXTtcblxuTGFuZ1tcIklURU1fVkFMVUVcIl0gPSBcIuWPmOaIkOS4reaWh+eahOaDheWGtVwiO1xuXG5tb2R1bGUuZXhwb3J0cyA9IExhbmc7IiwiLy/lsLHlg49sdWHph4znmoRDYXNlZnVuY1xudmFyIF8gPSBbXTtcblxuXy5tc2dfYnV5X3JlcyA9IGZ1bmN0aW9uKHJlcyl7XG5cbn1cbl8ubXNnX2xvZ2luX3JlcyA9IGZ1bmN0aW9uKHJlcyl7XG5cbn1cbl8ubXNnX3B2cF9yZXMgPSBmdW5jdGlvbihyZXMpe1xuICAgIGNvbnNvbGUubG9nKFwicmVzJ3MgdGV4dCA9IFwiICsgcmVzLnRleHQpO1xufVxuXG5tb2R1bGUuZXhwb3J0cyA9IF87IiwiLy/lsLHlg49sdWHpgqPovrnnmoRuZXRwcm90b2NvbC9pbml0Lmx1YVxudmFyIHByb3RvY29sID0gW107XG5cbnByb3RvY29sLnRtUmVxID0gW107XG5wcm90b2NvbC50bVJlcSA9IHtcbiAgICBbMF06XCJtc2dfYnV5X3JlcVwiLFxuICAgIFsxXTpcIm1zZ19sb2dpbl9yZXFcIixcbiAgICBbMl06XCJtc2dfbG9naW5fcmVxXCIsXG59O1xuXG5wcm90b2NvbC50bVJlcyA9IFtdO1xudmFyIHRtUmVzID0gcHJvdG9jb2wudG1SZXM7XG50bVJlc1swXSA9IFwibXNnX2J1eV9yZXNcIjtcbnRtUmVzWzFdID0gXCJtc2dfbG9naW5fcmVzXCI7XG50bVJlc1syXSA9IFwibXNnX3B2cF9yZXNcIjtcblxuY29uc29sZS5sb2coXCJsZW5ndGggXCIgKyBwcm90b2NvbC50bVJlcy5sZW5ndGgpO1xuXG5tb2R1bGUuZXhwb3J0cyA9IHByb3RvY29sOyIsImNvbnN0IHtjY2NsYXNzLCBwcm9wZXJ0eX0gPSBjYy5fZGVjb3JhdG9yO1xuXG5AY2NjbGFzc1xuZXhwb3J0IGRlZmF1bHQgY2xhc3MgTmV3Q2xhc3MgZXh0ZW5kcyBjYy5Db21wb25lbnQge1xuXG4gICAgQHByb3BlcnR5KGNjLkxhYmVsKVxuICAgIGxhYmVsOiBjYy5MYWJlbDtcblxuICAgIEBwcm9wZXJ0eSh7XG4gICAgICAgIGRlZmF1bHQ6ICdoZWxsbydcbiAgICB9KVxuICAgIHRleHQ6IHN0cmluZyA9ICdoZWxsbyc7XG5cbiAgICBvbkxvYWQoKSB7XG4gICAgICAgIC8vIGluaXQgbG9naWNcbiAgICAgICAgXG4gICAgfVxufVxuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgdGVzdFdvcms6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gbmltYWJpXCIpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBjb3VudDogMCxcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInplbm0gZWh1aXpoZXlhbmdcIik7XG4gICAgICAgIHRoaXMuc2NoZWR1bGUoZnVuY3Rpb24oKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiaGFoYWhhaGFoaGFcIik7XG4gICAgICAgIH0sIDEpO1xuICAgIH0sXG5cbiAgICBkb3NvbWV0aGluZzogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJkc2dmc2RhZ3ZkZ2FcIik7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKFwidGhpcy5jb3VudCA9IFwiICsgdGhpcy5jb3VudCk7XG4gICAgICAgIC8vIHRoaXMuY291bnQgPSB0aGlzLmNvdW50ICsgMTtcbiAgICB9LFxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsIlxuXG5jYy5DbGFzcyh7XG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICB2aWV3TGlzdDogbnVsbCxcbiAgICAgICAgdmlld0luZm86IFtdLFxuICAgICAgICB2aWV3OiBudWxsLFxuICAgICAgICB2aWV3TmFtZTogbnVsbCxcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiaGhoZWhlaGVcIik7XG4gICAgICAgIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0ID0gbmV3IGFycmF5MSgpO1xuICAgICAgICAvLyB0aGlzLmFycmF5MSA9IG5ldyByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnN0YXR1cygpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHthOjEsIGI6Mn0pO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnN0YXR1cygpO1xuICAgICAgICBcbiAgICB9LFxuXG4gICAgc2V0Um9vdDogZnVuY3Rpb24obm9kZSkge1xuICAgICAgICB0aGlzLnJvb3QgPSBub2RlO1xuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgLy8gY29uc29sZS5sb2coXCJoYWhhaGFoaGFcIik7XG5cbiAgICAgICAgLy8gY2MudmFyaWFibGUudmlld0luZm8uYXNmZGZzZGYoKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2codHlwZW9mIHRoaXMudmlld05hbWUpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxuXG4gICAgaW5pdDogZnVuY3Rpb24oKXtcbiAgICAgICAgdGhpcy52aWV3SW5mbyA9IFtdO1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMVwiKTtcbiAgICAgICAgdGhpcy52aWV3SW5mb1tcImhhaGFcIl0gPSB7YToxLCBiOjJ9O1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMlwiKTtcbiAgICB9LFxuXG4gICAgcmVnaXN0VmlldzogZnVuY3Rpb24odmlld05hbWUsIG1vZHVsZSwgdGl0bGUpe1xuICAgICAgICB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXSA9IHt2aWV3TmFtZTp2aWV3TmFtZSwgbW9kdWxlOm1vZHVsZSwgdGl0bGU6dGl0bGV9O1xuICAgIH0sXG5cbiAgICBjaGFuZ2VWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSl7XG4gICAgICAgIGlmKCF0aGlzLnZpZXdMaXN0LmVtcHR5KCkgJiYgdGhpcy52aWV3TGlzdC5iYWNrKCkgPT0gdmlld05hbWUpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ2aWV3IGlzIHNhbWVcIik7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgICAgICB9XG5cbiAgICAgICAgdmFyIHZpZXdBYm91dCA9IHRoaXMudmlld0luZm9bdmlld05hbWVdXG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gMVwiKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyAyXCIpO1xuXG4gICAgICAgIHZhciBpZHggPSB0aGlzLnZpZXdMaXN0LmZpbmQodmlld05hbWUpO1xuICAgICAgICBpZihpZHggIT0gdGhpcy52aWV3TGlzdC5ucG9zKXtcbiAgICAgICAgICAgIHZhciBsZW4gPSB0aGlzLnZpZXdMaXN0LmdldFNpemUoKSAtIGlkeDtcbiAgICAgICAgICAgIHRoaXMudmlld0xpc3QucmVtb3ZlKGlkeCwgbGVuKTtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgdGhpcy52aWV3TGlzdC5wdXNoQmFjayh2aWV3TmFtZSk7XG4gICAgICAgIH1cbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyAzXCIpO1xuXG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgLy/pgJrov4fpk77mjqUg5Yqg6L2955qE6LWE5rqQIOW/hemhu+aUvuWcqHJlc291cmNl5LiLXG4gICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKHZpZXdBYm91dC5tb2R1bGUsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcbiAgICAgICAgICAgIGNjLmRpcmVjdG9yLmdldFNjZW5lKCkuZ2V0Q2hpbGRCeU5hbWUoXCJDYW52YXNcIikuYWRkQ2hpbGQocm9vdCk7XG4gICAgICAgICAgICBpZihzZWxmLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgc2VsZi52aWV3LnJlbW92ZUZyb21QYXJlbnQoKTtcbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcgPSBudWxsO1xuICAgICAgICAgICAgfVxuICAgICAgICAgICAgc2VsZi52aWV3ID0gcm9vdDtcbiAgICAgICAgfSk7XG4gICAgICAgIFxuICAgICAgICB0aGlzLnZpZXdOYW1lID0gdmlld05hbWU7XG4gICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgfSxcblxuICAgIGN1clZpZXc6IGZ1bmN0aW9uKCkge1xuICAgICAgICAvLyB0aGlzLnRlc3RBZGRDaGlsZCgpO1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLmFkZEV2ZW50TGlzdGVuZXIoXCJoYWhhaGFcIiwgc2VsZiwgc2VsZi50ZXN0QWRkQ2hpbGQpO1xuICAgICAgICBjYy50b29sLmV2ZW50TWFuYWdlci50ZXN0V29ya0xpc3RlbmVyKClcbiAgICAgICAgdGhpcy52aWV3LnJlbW92ZUZyb21QYXJlbnQoZmFsc2UpO1xuICAgICAgICBjYy5sb2FkZXIucmVsZWFzZVJlcyhcInByZWZhYi9UZXN0MVBhbmVsXCIpO1xuXG4gICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgfSxcblxuICAgIHRlc3RBZGRDaGlsZDogZnVuY3Rpb24odmFyTmFtZSl7XG4gICAgICAgIGlmKHZhck5hbWUgPT0gXCJoYWhhaGFcIil7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIHRhbWFiaVwiKTtcbiAgICAgICAgfVxuICAgICAgICBlbHNlIGlmKHZhck5hbWUgPSBcIndvY2FvbmltYVwiKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiPz8/IHdvZGV0aWFuXCIpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGN1clZpZXdOYW1lOiBmdW5jdGlvbigpe1xuICAgICAgICByZXR1cm4gdGhpcy52aWV3TmFtZTtcbiAgICB9LFxuXG4gICAgYmFja1ByZXZpZXc6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGlmKHRoaXMudmlld0xpc3QuZ2V0U2l6ZSgpID4gMCl7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnBvcEJhY2soKTtcblxuICAgICAgICAgICAgdmFyIHZpZXdOYW1lID0gdGhpcy52aWV3TGlzdC5iYWNrKCk7XG4gICAgICAgICAgICB2YXIgdmlld0Fib3V0ID0gdGhpcy52aWV3SW5mb1t2aWV3TmFtZV07XG4gICAgICAgICAgICBpZih2aWV3QWJvdXQgPT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgaWYodGhpcy52aWV3ICE9IG51bGwpe1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB0aGlzLnZpZXdOYW1lID0gbnVsbDtcbiAgICAgICAgICAgICAgICB0aGlzLnZpZXcgPSBudWxsO1xuICAgICAgICAgICAgICAgIHJldHVybiBudWxsO1xuICAgICAgICAgICAgfVxuXG4gICAgICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgICAgICBjYy5sb2FkZXIubG9hZFJlcyh2aWV3QWJvdXQubW9kdWxlLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgICAgIGNjLmRpcmVjdG9yLmdldFNjZW5lKCkuZ2V0Q2hpbGRCeU5hbWUoXCJDYW52YXNcIikuYWRkQ2hpbGQocm9vdCk7XG4gICAgICAgICAgICAgICAgaWYoc2VsZi52aWV3ICE9IG51bGwpe1xuICAgICAgICAgICAgICAgICAgICBzZWxmLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgICAgICBzZWxmLnZpZXcgPSBudWxsO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcgPSByb290O1xuICAgICAgICAgICAgfSk7XG4gICAgICAgICAgICB0aGlzLnZpZXdOYW1lID0gdmlld05hbWU7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgICAgICB9XG4gICAgICAgIHJldHVybiBudWxsO1xuICAgIH0sXG59KTtcbiIsImNvbnNvbGUubG9nKFwiaGVoZWFoaGFoYSDmtYvor5XlhajlsYDnlKjms5VcIik7XG5cblxubW9kdWxlLmV4cG9ydHMgPSBmdW5jdGlvbigpe1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImttVmlld1wiLCBcInVpL2ttVmlld1wiLCAyKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJraWxpZTVWaWV3XCIsIFwidWkva2lsaWU1Vmlld1wiLCAyKTtcbn07Il0sInNvdXJjZVJvb3QiOiIifQ==