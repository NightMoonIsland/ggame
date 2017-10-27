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

    cc.tool.protocolInit = require("protocolInit");
    cc.tool.protocolHandler = require("protocolHandler");
    console.log("array's length = " + cc.tool.protocolInit.tmRes.length);
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
},{"config":"config","eventManager":"eventManager","gameVariable":"gameVariable","langZh":"langZh","protocolHandler":"protocolHandler","protocolInit":"protocolInit","timeHandler":"timeHandler","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
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

module.exports = null;

cc._RF.pop();
},{}]},{},["ListView","Renderer","appStart","config","langZh","array1","TopLayer","kmView","protocolHandler","protocolInit","timeHandler","testTs","eventManager","test","urlManager","viewManager","viewRegister","gameVariable"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9MaXN0Vmlldy5qcyIsImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9SZW5kZXJlci5qcyIsImFzc2V0cy9zY3JpcHQvbW9kdWxlL2luaXR1aS9Ub3BMYXllci5qcyIsImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvY29uZmlnLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL2V2ZW50TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdmFyaWFibGUvZ2FtZVZhcmlhYmxlLmpzIiwiYXNzZXRzL3NjcmlwdC9tb2R1bGUva21WaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvbGFuZ1poLmpzIiwiYXNzZXRzL3NjcmlwdC9uZXRwcm90b2NvbC9wcm90b2NvbEhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L25ldHByb3RvY29sL3Byb3RvY29sSW5pdC5qcyIsImFzc2V0cy9zY3JpcHQvdGVzdFRzLnRzIiwiYXNzZXRzL3NjcmlwdC90b29sL3Rlc3QuanMiLCJhc3NldHMvc2NyaXB0L3Byb2Nlc3MvdGltZUhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdXJsTWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3UmVnaXN0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6Ijs7Ozs7Ozs7Ozs7QUFBQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDSTtBQUNBO0FBRlE7O0FBTVo7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUE5QlE7O0FBaUNaO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0k7QUFHQTtBQUNIO0FBQ0o7QUFFRztBQUNJO0FBR0E7QUFDSDtBQUNKO0FBQ0o7O0FBekVMO0FBNEVRO0FBQ0g7QUFRRzs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDtBQUdHOztBQUVBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNIO0FBQ0o7QUFHRztBQUNBO0FBQ0g7Ozs7Ozs7Ozs7QUN4SUw7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTtBQWpDSzs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDSjs7QUFyQkk7Ozs7Ozs7Ozs7OztBQ0FUO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7O0FBR0E7QUFDQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDQTs7QUFFQTtBQUNBOztBQUVBOztBQUVBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFaUTs7QUFlWjtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBOzs7QUFHQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBOztBQUVBOztBQUVBO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNJO0FBQ0g7QUFDRDtBQUNIO0FBaEdJOzs7Ozs7Ozs7O0FDbENUOztBQUVJO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFiUTtBQWVaO0FBQ0E7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBRUc7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUNKO0FBQ0o7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNJO0FBRUE7QUFDSTtBQURKO0FBR0k7QUFESjtBQUdIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFFRztBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQURKO0FBR0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBckhJOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7QUFDQTtBQUNBOztBQUVBOzs7Ozs7Ozs7O0FDTkE7QUFDQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVhROztBQWNaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUEvREk7Ozs7Ozs7Ozs7QUNIVDs7QUFFQTs7QUFFQTs7Ozs7Ozs7OztBQ0pBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWFE7O0FBY1o7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDSTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUlKOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBOztBQUVBOztBQUVBOztBQUVJO0FBQ0g7QUFqREk7Ozs7Ozs7Ozs7QUNBVDs7QUFFQTs7QUFFQTs7Ozs7Ozs7OztBQ0pBO0FBQ0E7O0FBRUE7QUFHQTtBQUdBO0FBQ0k7QUFDSDs7QUFFRDs7Ozs7Ozs7Ozs7Ozs7QUNiQTtBQUNBOztBQUVBO0FBQ0E7O0FBTUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTs7QUFFQTs7Ozs7Ozs7O0FDbEJNO0FBR047QUFBc0M7QUFEdEM7QUFBQTtBQVNJOztBQU1KO0FBSkk7QUFDSTtBQUVKO0FBQ0o7QUFBQTtBQVhJO0FBREM7QUFDZTtBQUtoQjtBQUhDO0FBQ0c7QUFDSDtBQUNzQjtBQVJOO0FBRHBCO0FBQ29CO0FBQUE7Ozs7Ozs7Ozs7QUNIckI7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBdkJJOzs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBOztBQUdBO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIO0FBaENJOzs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFqQks7Ozs7Ozs7Ozs7QUNFVDtBQUNJO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQWRROztBQWlCWjtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBRUg7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0E7QUFDSTs7QUFFQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFFRztBQUNIO0FBQ0Q7O0FBRUE7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUVHO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNEO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0E7QUFDSTtBQUNBO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFDRDtBQUNIO0FBQ0Q7QUFDQTtBQUNIO0FBQ0Q7QUFDSDtBQWxKSTs7Ozs7Ozs7OztBQ0ZUOztBQUdBIiwic291cmNlc0NvbnRlbnQiOlsidmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG5cbmNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG5cbiAgICAgICAgc2Nyb2xsVmlldzoge1xuICAgICAgICAgICAgZGVmYXVsdDogbnVsbCxcbiAgICAgICAgICAgIHR5cGU6IGNjLlNjcm9sbFZpZXdcbiAgICAgICAgfSxcblxuICAgICAgICBcbiAgICAgICAgZGlyOiAwLCBcbiAgICAgICAgbGluZXM6IDAsIFxuICAgICAgICBoZ2FwOiAwLCBcbiAgICAgICAgdmdhcDogMCwgXG4gICAgICAgIHdpZHRoOiAwLCBcbiAgICAgICAgaGVpZ2h0OiAwLFxuICAgICAgICBcblxuICAgICAgICBkcDogbnVsbCxcbiAgICAgICAgaXRlbTogY2MuUHJlZmFiLFxuICAgICAgICBpdGVtUHdkOiBudWxsLFxuICAgICAgICBpdGVtSGVpZ2h0OiAwLFxuICAgICAgICBpdGVtV2lkdGg6IDAsXG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICB0aGlzLnVwZGF0ZVRpbWVyID0gMDtcbiAgICAgICAgZHAgPSBuZXcgYXJyYXkxKCk7XG4gICAgfSxcblxuICAgIGNyZWF0ZTogZnVuY3Rpb24oZGlyLCBsaW5lcywgaGdhcCwgdmdhcCwgd2lkdGgsIGhlaWdodCkge1xuICAgICAgICB0aGlzLmRpciA9IGRpcjtcbiAgICAgICAgdGhpcy5saW5lcyA9IGxpbmVzO1xuICAgICAgICB0aGlzLmhnYXAgPSBoZ2FwO1xuICAgICAgICB0aGlzLnZnYXAgPSB2Z2FwO1xuICAgICAgICB0aGlzLndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMuaGVpZ2h0ID0gaGVpZ2h0O1xuXG5cbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC5wYXJlbnQud2lkdGggPSB3aWR0aDtcbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC5wYXJlbnQuaGVpZ2h0ID0gaGVpZ2h0O1xuICAgICAgICB0aGlzLm5vZGUucGFyZW50LndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQuaGVpZ2h0ID0gaGVpZ2h0O1xuXG4gICAgICAgIC8vIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LnNldENvbnRlbnRTaXplKGNjLlNpemUod2lkdGgsIGhlaWdodCkpO1xuICAgICAgICAvLyB0aGlzLm5vZGUucGFyZW50LnNldENvbnRlbnRTaXplKGNjLlNpemUod2lkdGgsIGhlaWdodCkpO1xuICAgICAgICBpZihkaXIgPT0gY2MudG9vbC5jb25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwpe1xuICAgICAgICAgICAgdGhpcy5jYWxjU2VjdGlvbiA9IGZ1bmN0aW9uKHNlbGYpIHtcbiAgICAgICAgICAgICAgICBpZighc2VsZi5kcCB8fCBzZWxmLmRwLnNpemUoKSA9PSAwKXtcbiAgICAgICAgICAgICAgICAgICAgXG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHZhciBpbnRlcnZhbCA9IHNlbGYuaXRlbUhlaWdodCArIHNlbGYudmdhcDtcbiAgICAgICAgICAgIH07XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIHRoaXMuY2FsY1NlY3Rpb24gPSBmdW5jdGlvbihzZWxmKSB7XG4gICAgICAgICAgICAgICAgaWYoIXNlbGYuZHAgfHwgc2VsZi5kcC5zaXplKCkgPT0gMCl7XG4gICAgICAgICAgICAgICAgICAgIFxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB2YXIgaW50ZXJ2YWwgPSBzZWxmLml0ZW1IZWlnaHQgKyBzZWxmLnZnYXA7XG4gICAgICAgICAgICB9O1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLndpZHRoICsgXCIgd29jYW8gXCIgKyB0aGlzLmhlaWdodCk7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIHNldEl0ZW1Nb2RlbDogZnVuY3Rpb24oaXRlbSwgaXRlbVdpZHRoLCBpdGVtSGVpZ2h0KSB7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcblxuICAgICAgICB0aGlzLml0ZW1Qd2QgPSBpdGVtO1xuICAgICAgICAvLyBjYy5sb2FkZXIubG9hZFJlcyhpdGVtLCBjYy5QcmVmYWIsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgLy8gICAgIC8vIGNjLnRvb2wucHJlZmFiLmxpc3RWaWV3ID0gcHJlZmFiO1xuICAgICAgICAvLyAgICAgY29uc29sZS5sb2coXCJ0eXBlIHByZWZhYiA9IFwiICsgdHlwZW9mIHByZWZhYilcbiAgICAgICAgLy8gICAgIHNlbGYuaXRlbSA9IHByZWZhYjtcbiAgICAgICAgLy8gfSk7XG4gICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKGl0ZW0sIGNjLlByZWZhYik7XG4gICAgICAgIHNlbGYuaXRlbVdpZHRoID0gaXRlbVdpZHRoO1xuICAgICAgICBzZWxmLml0ZW1IZWlnaHQgPSBpdGVtSGVpZ2h0O1xuICAgIH0sXG5cbiAgICBzZXREYXRhUHJvdmlkZXI6IGZ1bmN0aW9uKGRsKSB7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcblxuICAgICAgICBpZih0aGlzLmRpciA9PSBjYy50b29sLmNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCl7XG4gICAgICAgICAgICB0aGlzLm5vZGUuaGVpZ2h0ID0gZGwuZ2V0U2l6ZSgpICogKHRoaXMuaXRlbUhlaWdodCArIHRoaXMuaGdhcCkgLSB0aGlzLmhnYXA7XG4gICAgICAgICAgICB0aGlzLm5vZGUud2lkdGggPSB0aGlzLndpZHRoO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLm5vZGUuaGVpZ2h0ID0gdGhpcy5oZWlnaHQ7XG4gICAgICAgIH0gICAgXG5cbiAgICAgICAgZGwuZXhjdXRlV2l0aEZ1bmMoZnVuY3Rpb24oZGF0YSwgaW5kZXgpe1xuICAgICAgICAgICAgdmFyIHByZWZhYiA9IGNjLmxvYWRlci5nZXRSZXMoc2VsZi5pdGVtUHdkLCBjYy5QcmVmYWIpO1xuXG4gICAgICAgICAgICBsZXQgaXRlbSA9IGNjLmluc3RhbnRpYXRlKHByZWZhYikuZ2V0Q29tcG9uZW50KCdSZW5kZXJlcicpO1xuICAgICAgICAgICAgLy8gaXRlbS5zZXRQb3NZKC10aGlzLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICBpdGVtLnNldFBvcygwLCAtc2VsZi5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgc2VsZi5ub2RlLmFkZENoaWxkKGl0ZW0ubm9kZSk7XG5cbiAgICAgICAgICAgIC8vIGNjLmxvYWRlci5nZXRSZXMoc2VsZi5pdGVtUHdkLCBjYy5QcmVmYWIsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgIC8vICAgICBsZXQgaXRlbSA9IGNjLmluc3RhbnRpYXRlKHByZWZhYikuZ2V0Q29tcG9uZW50KCdSZW5kZXJlcicpO1xuICAgICAgICAgICAgLy8gICAgIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gICAgIGl0ZW0uc2V0UG9zKDAsIC1zZWxmLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyAgICAgc2VsZi5ub2RlLmFkZENoaWxkKGl0ZW0ubm9kZSk7XG4gICAgICAgICAgICAvLyB9KTtcblxuICAgICAgICAgICAgLy8gbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShzZWxmLml0ZW0pLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gaXRlbS5zZXRQb3MoMCwgLXNlbGYuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuICAgICAgICB9KTtcbiAgICB9LFxuXG4gICAgdXBkYXRlIChkdCkge1xuICAgICAgICB0aGlzLnVwZGF0ZVRpbWVyICs9IGR0O1xuICAgICAgICBpZih0aGlzLnVwZGF0ZVRpbWVyIDwgdGhpcy51cGRhdGVJbnRlcnZhbCkgcmV0dXJuO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICBzZXRQb3NZOiBmdW5jdGlvbih5KSB7XG4gICAgICAgIHRoaXMubm9kZS55ID0geTtcbiAgICB9LFxuXG4gICAgc2V0UG9zOiBmdW5jdGlvbih4LCB5KSB7XG4gICAgICAgIHRoaXMubm9kZS54ID0geDtcbiAgICAgICAgdGhpcy5ub2RlLnkgPSB5O1xuICAgIH1cblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICB0aGlzLm5vZGUub24oJ21vdXNlZG93bicsIGZ1bmN0aW9uIChldmVudCkge1xuICAgICAgICAgICAgY29uc29sZS5sb2coJ01vdXNlIGRvd24nKTtcbiAgICAgICAgfSwgdGhpcyk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImZ1bmN0aW9uIGluaXQoKXtcbiAgICBjYy50b29sID0ge31cbiAgICB2YXIgdmlld01hbmFnZXIgPSByZXF1aXJlKFwidmlld01hbmFnZXJcIik7XG4gICAgY2MudG9vbC52aWV3TWFuYWdlciA9IG5ldyB2aWV3TWFuYWdlcigpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIuaW5pdCgpO1xuXG5cbiAgICByZXF1aXJlKFwidmlld1JlZ2lzdGVyXCIpO1xuICAgIHZpZXdSZWdpc3RlcigpO1xuXG4gICAgdmFyIHRpbWVIYW5kbGVyID0gcmVxdWlyZShcInRpbWVIYW5kbGVyXCIpO1xuICAgIGNjLnRvb2wudGltZUhhbmRsZXIgPSBuZXcgdGltZUhhbmRsZXIoKTtcblxuICAgIHZhciBldmVudE1hbmFnZXIgPSByZXF1aXJlKFwiZXZlbnRNYW5hZ2VyXCIpO1xuICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyID0gbmV3IGV2ZW50TWFuYWdlcigpO1xuXG4gICAgY2MudG9vbC5nYW1lVmFyaWFibGUgPSByZXF1aXJlKFwiZ2FtZVZhcmlhYmxlXCIpO1xuICAgIGNjLnRvb2wuTGFuZyA9IHJlcXVpcmUoXCJsYW5nWmhcIik7XG5cbiAgICBjYy50b29sLnByZWZhYiA9IHt9O1xuICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImhhaGFoYVwiLCBcImhlaGVoZVwiLCBcImhpaGloaVwiKTtcblxuICAgIGNjLnRvb2wuY29uZmlnID0gcmVxdWlyZShcImNvbmZpZ1wiKTtcblxuICAgIGNjLnRvb2wucHJvdG9jb2xJbml0ID0gcmVxdWlyZShcInByb3RvY29sSW5pdFwiKTtcbiAgICBjYy50b29sLnByb3RvY29sSGFuZGxlciA9IHJlcXVpcmUoXCJwcm90b2NvbEhhbmRsZXJcIik7XG4gICAgY29uc29sZS5sb2coXCJhcnJheSdzIGxlbmd0aCA9IFwiICsgY2MudG9vbC5wcm90b2NvbEluaXQudG1SZXMubGVuZ3RoKTtcbn1cblxuZnVuY3Rpb24gdmlld1JlZ2lzdGVyKCl7XG4gICAgY2MudG9vbC52aWV3TWFuYWdlci5yZWdpc3RWaWV3KFwia21WaWV3XCIsIFwidWkva21WaWV3XCIsIDIpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImtpbGllNVZpZXdcIiwgXCJ1aS9raWxpZTVWaWV3XCIsIDIpO1xufVxuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBoYWhhOiBbXSxcbiAgICAgICAgY291bnQ6IDAsXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBpbml0KCk7XG5cbiAgICAgICAgLy8gdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICAvLyBjYy5sb2FkZXIubG9hZFJlcyhcImNvbnRyb2wvTGlzdFZpZXdcIiwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgIC8vICAgICAvLyBjYy50b29sLnByZWZhYi5saXN0VmlldyA9IHByZWZhYjtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwidHlwZSBwcmVmYWIgPSBcIiArIHR5cGVvZiBwcmVmYWIpXG5cbiAgICAgICAgLy8gICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcbiAgICAgICAgLy8gICAgIHJvb3Quc2V0UG9zaXRpb24oY2MudjIoMCwgMCkpO1xuICAgICAgICAvLyAgICAgbGV0IGxpc3RWaWV3ID0gcm9vdC5nZXRDaGlsZEJ5TmFtZShcInZpZXdcIikuZ2V0Q2hpbGRCeU5hbWUoXCJjb250ZW50XCIpLmdldENvbXBvbmVudChcIkxpc3RWaWV3XCIpO1xuICAgICAgICAvLyAgICAgbGlzdFZpZXcuY3JlYXRlKGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMLCAxLCAxLCAxLCAyNDAsIDE1MCk7XG4gICAgICAgIC8vICAgICBsaXN0Vmlldy5zZXRJdGVtTW9kZWwoXCJjb250cm9sL1JlbmRlcmVyXCIsIDE2MCwgNjApO1xuXG4gICAgICAgIC8vICAgICB2YXIgYXJyYXkgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICAvLyAgICAgdmFyIHRlc3QgPSBuZXcgYXJyYXkoKTtcbiAgICAgICAgLy8gICAgIGZvcihpID0gMDsgaSA8IDU7IGkrKyl7XG4gICAgICAgIC8vICAgICAgICAgdGVzdC5wdXNoQmFjayhpICsgMTAwKVxuICAgICAgICAvLyAgICAgfVxuXG4gICAgICAgIC8vICAgICBsaXN0Vmlldy5zZXREYXRhUHJvdmlkZXIodGVzdCk7XG5cblxuICAgICAgICAvLyAgICAgc2VsZi5ub2RlLmFkZENoaWxkKHJvb3QpO1xuICAgICAgICAvLyB9KTtcblxuICAgICAgICAvL+aaguaXtuS4jeeUqOWumuaXtuWZqFxuICAgICAgICAvLyB0aGlzLnNjaGVkdWxlKGZ1bmN0aW9uKCl7XG4gICAgICAgIC8vICAgICB0aGlzLnVwZGF0ZVRpbWUoKTtcbiAgICAgICAgLy8gfSwgMSk7XG5cbiAgICAgICAgdGhpcy50ZXN0RnVuYygpO1xuICAgIH0sXG5cbiAgICB1cGRhdGVUaW1lOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0aGlzLmNvdW50ID0gXCIgKyB0aGlzLmNvdW50KTtcbiAgICAgICAgdGhpcy5jb3VudCA9IHRoaXMuY291bnQgKyAxO1xuICAgICAgICAvLyBjYy50b29sLmV2ZW50TWFuYWdlci5WQVJfQ0hBTkdFKFwic2VjMVwiKTtcbiAgICAgICAgY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjID0gY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjICsgMTtcbiAgICB9LFxuXG4gICAgdGVzdEZ1bmM6IGZ1bmN0aW9uKCkge1xuICAgICAgICB2YXIgc3RyMSA9IFwiaGVsbG93b3JkXCI7XG4gICAgICAgIHRoaXMuaGVsbG93b3JkID0gZnVuY3Rpb24oKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwid290ZWZ1bmNrXCIpO1xuICAgICAgICB9XG4gICAgICAgIHRoaXNbc3RyMV0oKTtcbiAgICB9LFxuXG4gICAgaW5pdFNjZW5lOiBmdW5jdGlvbigpIHtcbiAgICAgICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5zZXRSb290KHRoaXMubm9kZSk7XG4gICAgICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImhhaGhhaGFoYWFcIik7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidGVzdCB0eXBlXCIgKyB0eXBlb2YgdGhpcy5oYWhhW1wid29jYW9cIl0pO1xuICAgIH0sXG5cbiAgICB0ZXN0UmVtb3ZlOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwia21WaWV3XCIpO1xuICAgIH0sXG5cbiAgICBidG5CYWNrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5iYWNrUHJldmlldygpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxuXG4gICAgY29ubmVjdFRlc3Q6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvcmsgY29ubmVjdFwiKTtcbiAgICAgICAgdmFyIHNvY2tldCA9IGlvLmNvbm5lY3QoJzEwLjEwLjMwLjIzNDoxMjM0NScsIGZ1bmN0aW9uKG1zZyl7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhtc2cpO1xuICAgICAgICB9KTtcbiAgICAgICAgZm9yKHZhciBpID0gMDsgaSA8IGNjLnRvb2wucHJvdG9jb2xJbml0LnRtUmVzLmxlbmd0aDsgaSsrKXtcbiAgICAgICAgICAgIHNvY2tldC5vbihjYy50b29sLnByb3RvY29sSW5pdC50bVJlc1tpXSwgY2MudG9vbC5wcm90b2NvbEhhbmRsZXJbY2MudG9vbC5wcm90b2NvbEluaXQudG1SZXNbaV1dKTtcbiAgICAgICAgfVxuICAgICAgICBzb2NrZXQuZW1pdCgnaGVoZWhhaGEnLCB7YWJjOlwid296aGVuZGVyaWxlZ291bGVcIn0pO1xuICAgIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgbGlzdDogW10sXG4gICAgICAgIHNpemU6IDAsXG4gICAgICAgIG5wb3M6IC0xLFxuICAgIH0sXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29ya2VkXCIpO1xuICAgIH0sXG5cbiAgICBhc2ZkZnNkZjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW9cIik7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKHR5cGVvZiB0aGlzLmxpc3QpO1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xuICAgIH0sXG5cbiAgICBzdGF0dXM6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTFcIik7XG4gICAgICAgIGNvbnNvbGUubG9nKHRoaXMuc2l6ZSk7XG4gICAgICAgIGNvbnNvbGUubG9nKFwic2VsZi5zaXplMlwiKTtcbiAgICB9LFxuICAgIC8vXG4gICAgcHVzaEJhY2s6IGZ1bmN0aW9uKGRhdGEpIHtcbiAgICAgICAgdGhpcy5saXN0W3RoaXMuc2l6ZV0gPSBkYXRhO1xuICAgICAgICB0aGlzLnNpemUgPSB0aGlzLnNpemUgKyAxO1xuICAgIH0sXG5cbiAgICBhdDogZnVuY3Rpb24oaWR4KXtcbiAgICAgICAgcmV0dXJuIHRoaXMubGlzdFtpZHhdO1xuICAgIH0sXG5cbiAgICBmaW5kOiBmdW5jdGlvbih2YWx1ZSl7XG4gICAgICAgIHZhciBpbmRleCA9IHRoaXMubnBvcztcbiAgICAgICAgaWYgKHR5cGVvZiB2YWx1ZSA9PSBcImZ1bmN0aW9uXCIpe1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgICAgIGlmKHZhbHVlKGkpKSByZXR1cm4gaTtcbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgICAgIGlmKHRoaXMubGlzdFtpXSA9PSB2YWx1ZSl7XG4gICAgICAgICAgICAgICAgICAgIGluZGV4ID0gaTtcbiAgICAgICAgICAgICAgICAgICAgYnJlYWs7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfVxuICAgICAgICB9XG4gICAgICAgIHJldHVybiBpbmRleDtcbiAgICB9LFxuXG4gICAgcmVtb3ZlOiBmdW5jdGlvbihwb3MsIGxlbil7XG4gICAgICAgIGlmKHBvcyA8IDApIHBvcyA9IDA7XG4gICAgICAgIGlmKGxlbiA9PSBudWxsIHx8IGxlbiA8PSAwKXtcbiAgICAgICAgICAgIGxlbiA9IDE7XG4gICAgICAgIH1cbiAgICAgICAgaWYocG9zIDwgdGhpcy5zaXplKXtcbiAgICAgICAgICAgIGlmKHBvcyArIGxlbiA+IHRoaXMuc2l6ZSlcbiAgICAgICAgICAgICAgICBsZW4gPSB0aGlzLnNpemUgLSBwb3M7XG4gICAgICAgICAgICBmb3IoaSA9IDA7IGkgPCBsZW47IGkrKylcbiAgICAgICAgICAgICAgICBkZWxldGUgdGhpcy5saXN0W3BvcyArIGldO1xuICAgICAgICAgICAgZm9yKGkgPSBwb3MgKyBsZW47IGkgPCB0aGlzLnNpemU7IGkrKylcbiAgICAgICAgICAgICAgICB0aGlzLmxpc3RbaSAtIGxlbl0gPSB0aGlzLmxpc3RbaV07XG4gICAgICAgICAgICB0aGlzLnNpemUgPSB0aGlzLnNpemUgLSBsZW47XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgY2xlYXI6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxuICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtpXTtcbiAgICAgICAgdGhpcy5zaXplID0gMDtcbiAgICB9LFxuXG4gICAgZ2V0U2l6ZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIHJldHVybiB0aGlzLnNpemU7XG4gICAgfSxcblxuICAgIGJhY2s6IGZ1bmN0aW9uKCkge1xuICAgICAgICBpZih0aGlzLnNpemUgPiAwKXtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLmxpc3RbdGhpcy5zaXplIC0gMV07XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIHJldHVybiBudWxsO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGVtcHR5OiBmdW5jdGlvbigpIHtcbiAgICAgICAgcmV0dXJuIHRoaXMuc2l6ZSA9PSAwO1xuICAgIH0sXG5cbiAgICBvdXRQdXQ6IGZ1bmN0aW9uKCkge1xuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiZWxlbWVudFwiICsgaSArIFwiID0gXCIgKyB0aGlzLmxpc3RbaV0pO1xuICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnQgc2l6ZSA9IFwiICsgdGhpcy5zaXplKTtcbiAgICB9LFxuXG4gICAgZXhjdXRlV2l0aEZ1bmM6IGZ1bmN0aW9uKGZ1bmMpIHtcbiAgICAgICAgZm9yKHZhciBpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgIGZ1bmModGhpcy5saXN0W2ldLCBpKTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBwb3BCYWNrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgaWYodGhpcy5zaXplID4gMCl7XG4gICAgICAgICAgICBkZWxldGUgdGhpcy5saXN0W3RoaXMuc2l6ZSAtIDFdO1xuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gMTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJ2YXIgQ29uZmlnID0ge307XG5cbkNvbmZpZy5EaXJlY3Rpb24gPSB7fTtcbkNvbmZpZy5EaXJlY3Rpb24uVkVSVElDQUwgPSAwO1xuQ29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMID0gMTtcblxubW9kdWxlLmV4cG9ydHMgPSBDb25maWc7IiwidmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIilcbnZhciB0ZXN0ID0gcmVxdWlyZShcInRlc3RcIilcblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IHRlc3QsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGV2ZW50TGlzdGVuZXI6IFtdLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgXG4gICAgfSxcblxuICAgIGluaXQ6IGZ1bmN0aW9uKCkge1xuICAgICAgICB0aGlzLnN1cGVyLnRlc3RXb3JrKCk7XG4gICAgfSxcblxuICAgIHRlc3RXb3JrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ6ZW5tZSBodWkgemhleWFuZ1wiKTtcbiAgICB9LFxuXG4gICAgYWRkRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlLCB0YXJnZXQsIGZ1bmMpIHtcbiAgICAgICAgdGFyZ2V0Lm91dHB1dCgpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZygpXG4gICAgICAgIGlmKCF0YXJnZXQgfHwgIWZ1bmMpIHJldHVybjtcbiAgICAgICAgaWYoIXRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdKXtcbiAgICAgICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdID0gbmV3IGFycmF5MSgpO1xuICAgICAgICB9XG4gICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdLnB1c2hCYWNrKHt0YXJnZXQ6dGFyZ2V0LCBmdW5jOmZ1bmN9KTtcbiAgICB9LFxuXG4gICAgdGVzdFdvcmtMaXN0ZW5lcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGVzdCBsaXN0ZW5lclwiKTtcbiAgICAgICAgZm9yKHZhciBrZXkgaW4gdGhpcy5ldmVudExpc3RlbmVyW1wiaGFoYWhhXCJdKXtcbiAgICAgICAgICAgIHZhciBmdW5jID0gdGhpcy5ldmVudExpc3RlbmVyW1wiaGFoYWhhXCJdW2tleV07XG4gICAgICAgICAgICBmdW5jKFwiaGFoYWhhXCIpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGRpc3BhdGNoRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiZXZlbnRUeXBlXCIpO1xuICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXS5leGN1dGVXaXRoRnVuYyhmdW5jdGlvbihpdGVtLCBpbmRleCl7XG4gICAgICAgICAgICB2YXIgZnVuYyA9IGl0ZW0uZnVuYztcbiAgICAgICAgICAgIHZhciB0YXJnZXQgPSBpdGVtLnRhcmdldDtcbiAgICAgICAgICAgIGZ1bmModGFyZ2V0LCBldmVudFR5cGUpO1xuICAgICAgICB9KVxuICAgICAgICAvLyBmb3IodmFyIGtleSBpbiB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSl7XG4gICAgICAgIC8vICAgICB2YXIgZnVuYyA9IHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdW2tleV07XG4gICAgICAgIC8vICAgICBmdW5jKGtleSwgZXZlbnRUeXBlKTtcbiAgICAgICAgLy8gfVxuICAgIH0sXG5cbiAgICBWQVJfQ0hBTkdFOiBmdW5jdGlvbih2YXJOYW1lKXtcbiAgICAgICAgdGhpcy5kaXNwYXRjaEV2ZW50TGlzdGVuZXIodmFyTmFtZSk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsInZhciBnYW1lVmFyID0gW107XG5cbmdhbWVWYXIuc2VjID0gMDtcblxubW9kdWxlLmV4cG9ydHMgPSBnYW1lVmFyOyIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGV2ZW50VHlwZTogbnVsbCxcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIHRoaXMuZXZlbnRUeXBlID0gbmV3IEFycmF5KFwic2VjMVwiLCBcInNlYzJcIiwgXCJzZWMzXCIpO1xuICAgICAgICBcbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICBmb3IodmFyIGkgPSAwOyBpIDwgdGhpcy5ldmVudFR5cGUubGVuZ3RoOyBpKyspe1xuICAgICAgICAgICAgY2MudG9vbC5ldmVudE1hbmFnZXIuYWRkRXZlbnRMaXN0ZW5lcihzZWxmLmV2ZW50VHlwZVtpXSwgc2VsZiwgc2VsZi5vblZhckNhbGxiYWNrKTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBvblZhckNhbGxiYWNrOiBmdW5jdGlvbihzZWxmLCB2YXJOYW1lKSB7XG4gICAgICAgIGlmKHZhck5hbWUgPT0gXCJzZWMxXCIpe1xuICAgICAgICAgICAgLy9zZWxmLm91dHB1dCgpO1xuICAgICAgICAgICAgc2VsZi5ub2RlLmdldENoaWxkQnlOYW1lKFwidHh0aGFoYVwiKS5nZXRDb21wb25lbnQoY2MuTGFiZWwpLnN0cmluZyA9IFwic2VjID0gXCIgKyBjYy50b29sLmdhbWVWYXJpYWJsZS5zZWM7XG4gICAgICAgIH1cbiAgICAgICAgZWxzZSBpZih2YXJOYW1lID09IFwiXCIpe1xuXG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgb3V0cHV0OiBmdW5jdGlvbigpe1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvIGNhbyBuaSBtYSBnZSBjaG91IGhhaVwiKTtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcblxuICAgIGJ0blRlYW06IGZ1bmN0aW9uKCkge1xuICAgICAgICBcbiAgICAgICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwia2lsaWU1Vmlld1wiKTtcbiAgICB9LFxufSk7XG4iLCJ2YXIgTGFuZyA9IFtdO1xuXG5MYW5nW1wiSVRFTV9WQUxVRVwiXSA9IFwi5Y+Y5oiQ5Lit5paH55qE5oOF5Ya1XCI7XG5cbm1vZHVsZS5leHBvcnRzID0gTGFuZzsiLCIvL+WwseWDj2x1YemHjOeahENhc2VmdW5jXG52YXIgXyA9IFtdO1xuXG5fLm1zZ19idXlfcmVzID0gZnVuY3Rpb24ocmVzKXtcblxufVxuXy5tc2dfbG9naW5fcmVzID0gZnVuY3Rpb24ocmVzKXtcblxufVxuXy5tc2dfcHZwX3JlcyA9IGZ1bmN0aW9uKHJlcyl7XG4gICAgY29uc29sZS5sb2coXCJyZXMncyB0ZXh0ID0gXCIgKyByZXMudGV4dCk7XG59XG5cbm1vZHVsZS5leHBvcnRzID0gXzsiLCIvL+WwseWDj2x1YemCo+i+ueeahG5ldHByb3RvY29sL2luaXQubHVhXG52YXIgcHJvdG9jb2wgPSBbXTtcblxucHJvdG9jb2wudG1SZXEgPSBbXTtcbnByb3RvY29sLnRtUmVxID0ge1xuICAgIFswXTpcIm1zZ19idXlfcmVxXCIsXG4gICAgWzFdOlwibXNnX2xvZ2luX3JlcVwiLFxuICAgIFsyXTpcIm1zZ19sb2dpbl9yZXFcIixcbn07XG5cbnByb3RvY29sLnRtUmVzID0gW107XG52YXIgdG1SZXMgPSBwcm90b2NvbC50bVJlcztcbnRtUmVzWzBdID0gXCJtc2dfYnV5X3Jlc1wiO1xudG1SZXNbMV0gPSBcIm1zZ19sb2dpbl9yZXNcIjtcbnRtUmVzWzJdID0gXCJtc2dfcHZwX3Jlc1wiO1xuXG5jb25zb2xlLmxvZyhcImxlbmd0aCBcIiArIHByb3RvY29sLnRtUmVzLmxlbmd0aCk7XG5cbm1vZHVsZS5leHBvcnRzID0gcHJvdG9jb2w7IiwiY29uc3Qge2NjY2xhc3MsIHByb3BlcnR5fSA9IGNjLl9kZWNvcmF0b3I7XG5cbkBjY2NsYXNzXG5leHBvcnQgZGVmYXVsdCBjbGFzcyBOZXdDbGFzcyBleHRlbmRzIGNjLkNvbXBvbmVudCB7XG5cbiAgICBAcHJvcGVydHkoY2MuTGFiZWwpXG4gICAgbGFiZWw6IGNjLkxhYmVsO1xuXG4gICAgQHByb3BlcnR5KHtcbiAgICAgICAgZGVmYXVsdDogJ2hlbGxvJ1xuICAgIH0pXG4gICAgdGV4dDogc3RyaW5nID0gJ2hlbGxvJztcblxuICAgIG9uTG9hZCgpIHtcbiAgICAgICAgLy8gaW5pdCBsb2dpY1xuICAgICAgICBcbiAgICB9XG59XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICB0ZXN0V29yazogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyBuaW1hYmlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGNvdW50OiAwLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiemVubSBlaHVpemhleWFuZ1wiKTtcbiAgICAgICAgdGhpcy5zY2hlZHVsZShmdW5jdGlvbigpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJoYWhhaGFoYWhoYVwiKTtcbiAgICAgICAgfSwgMSk7XG4gICAgfSxcblxuICAgIGRvc29tZXRoaW5nOiBmdW5jdGlvbigpe1xuICAgICAgICBjb25zb2xlLmxvZyhcImRzZ2ZzZGFndmRnYVwiKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2coXCJ0aGlzLmNvdW50ID0gXCIgKyB0aGlzLmNvdW50KTtcbiAgICAgICAgLy8gdGhpcy5jb3VudCA9IHRoaXMuY291bnQgKyAxO1xuICAgIH0sXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiXG5cbmNjLkNsYXNzKHtcbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIHZpZXdMaXN0OiBudWxsLFxuICAgICAgICB2aWV3SW5mbzogW10sXG4gICAgICAgIHZpZXc6IG51bGwsXG4gICAgICAgIHZpZXdOYW1lOiBudWxsLFxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJoaGhlaGVoZVwiKTtcbiAgICAgICAgdmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3QgPSBuZXcgYXJyYXkxKCk7XG4gICAgICAgIC8vIHRoaXMuYXJyYXkxID0gbmV3IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIHRoaXMudmlld0xpc3QucHVzaEJhY2soe2E6MSwgYjoyfSk7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBzZXRSb290OiBmdW5jdGlvbihub2RlKSB7XG4gICAgICAgIHRoaXMucm9vdCA9IG5vZGU7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICAvLyBjb25zb2xlLmxvZyhcImhhaGFoYWhoYVwiKTtcblxuICAgICAgICAvLyBjYy52YXJpYWJsZS52aWV3SW5mby5hc2ZkZnNkZigpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy52aWV3TmFtZSk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBpbml0OiBmdW5jdGlvbigpe1xuICAgICAgICB0aGlzLnZpZXdJbmZvID0gW107XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGhpcyAxXCIpO1xuICAgICAgICB0aGlzLnZpZXdJbmZvW1wiaGFoYVwiXSA9IHthOjEsIGI6Mn07XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGhpcyAyXCIpO1xuICAgIH0sXG5cbiAgICByZWdpc3RWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSwgbW9kdWxlLCB0aXRsZSl7XG4gICAgICAgIHRoaXMudmlld0luZm9bdmlld05hbWVdID0ge3ZpZXdOYW1lOnZpZXdOYW1lLCBtb2R1bGU6bW9kdWxlLCB0aXRsZTp0aXRsZX07XG4gICAgfSxcblxuICAgIGNoYW5nZVZpZXc6IGZ1bmN0aW9uKHZpZXdOYW1lKXtcbiAgICAgICAgaWYoIXRoaXMudmlld0xpc3QuZW1wdHkoKSAmJiB0aGlzLnZpZXdMaXN0LmJhY2soKSA9PSB2aWV3TmFtZSl7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcInZpZXcgaXMgc2FtZVwiKTtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgICAgIH1cblxuICAgICAgICB2YXIgdmlld0Fib3V0ID0gdGhpcy52aWV3SW5mb1t2aWV3TmFtZV1cbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyAxXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIDJcIik7XG5cbiAgICAgICAgdmFyIGlkeCA9IHRoaXMudmlld0xpc3QuZmluZCh2aWV3TmFtZSk7XG4gICAgICAgIGlmKGlkeCAhPSB0aGlzLnZpZXdMaXN0Lm5wb3Mpe1xuICAgICAgICAgICAgdmFyIGxlbiA9IHRoaXMudmlld0xpc3QuZ2V0U2l6ZSgpIC0gaWR4O1xuICAgICAgICAgICAgdGhpcy52aWV3TGlzdC5yZW1vdmUoaWR4LCBsZW4pO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHZpZXdOYW1lKTtcbiAgICAgICAgfVxuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIDNcIik7XG5cbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICAvL+mAmui/h+mTvuaOpSDliqDovb3nmoTotYTmupAg5b+F6aG75pS+5ZyocmVzb3VyY2XkuItcbiAgICAgICAgY2MubG9hZGVyLmxvYWRSZXModmlld0Fib3V0Lm1vZHVsZSwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgICAgIGlmKHNlbGYudmlldyAhPSBudWxsKXtcbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IG51bGw7XG4gICAgICAgICAgICB9XG4gICAgICAgICAgICBzZWxmLnZpZXcgPSByb290O1xuICAgICAgICB9KTtcbiAgICAgICAgXG4gICAgICAgIHRoaXMudmlld05hbWUgPSB2aWV3TmFtZTtcbiAgICAgICAgcmV0dXJuIHRoaXMudmlldztcbiAgICB9LFxuXG4gICAgY3VyVmlldzogZnVuY3Rpb24oKSB7XG4gICAgICAgIC8vIHRoaXMudGVzdEFkZENoaWxkKCk7XG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgY2MudG9vbC5ldmVudE1hbmFnZXIuYWRkRXZlbnRMaXN0ZW5lcihcImhhaGFoYVwiLCBzZWxmLCBzZWxmLnRlc3RBZGRDaGlsZCk7XG4gICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLnRlc3RXb3JrTGlzdGVuZXIoKVxuICAgICAgICB0aGlzLnZpZXcucmVtb3ZlRnJvbVBhcmVudChmYWxzZSk7XG4gICAgICAgIGNjLmxvYWRlci5yZWxlYXNlUmVzKFwicHJlZmFiL1Rlc3QxUGFuZWxcIik7XG5cbiAgICAgICAgcmV0dXJuIHRoaXMudmlldztcbiAgICB9LFxuXG4gICAgdGVzdEFkZENoaWxkOiBmdW5jdGlvbih2YXJOYW1lKXtcbiAgICAgICAgaWYodmFyTmFtZSA9PSBcImhhaGFoYVwiKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gdGFtYWJpXCIpO1xuICAgICAgICB9XG4gICAgICAgIGVsc2UgaWYodmFyTmFtZSA9IFwid29jYW9uaW1hXCIpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCI/Pz8gd29kZXRpYW5cIik7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgY3VyVmlld05hbWU6IGZ1bmN0aW9uKCl7XG4gICAgICAgIHJldHVybiB0aGlzLnZpZXdOYW1lO1xuICAgIH0sXG5cbiAgICBiYWNrUHJldmlldzogZnVuY3Rpb24oKXtcbiAgICAgICAgaWYodGhpcy52aWV3TGlzdC5nZXRTaXplKCkgPiAwKXtcbiAgICAgICAgICAgIHRoaXMudmlld0xpc3QucG9wQmFjaygpO1xuXG4gICAgICAgICAgICB2YXIgdmlld05hbWUgPSB0aGlzLnZpZXdMaXN0LmJhY2soKTtcbiAgICAgICAgICAgIHZhciB2aWV3QWJvdXQgPSB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXTtcbiAgICAgICAgICAgIGlmKHZpZXdBYm91dCA9PSBudWxsKXtcbiAgICAgICAgICAgICAgICBpZih0aGlzLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgICAgIHRoaXMudmlldy5yZW1vdmVGcm9tUGFyZW50KCk7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHRoaXMudmlld05hbWUgPSBudWxsO1xuICAgICAgICAgICAgICAgIHRoaXMudmlldyA9IG51bGw7XG4gICAgICAgICAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgICAgICAgICB9XG5cbiAgICAgICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKHZpZXdBYm91dC5tb2R1bGUsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgICAgICB2YXIgcm9vdCA9IGNjLmluc3RhbnRpYXRlKHByZWZhYik7XG4gICAgICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgICAgICAgICBpZihzZWxmLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldy5yZW1vdmVGcm9tUGFyZW50KCk7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IG51bGw7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IHJvb3Q7XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgICAgIHRoaXMudmlld05hbWUgPSB2aWV3TmFtZTtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgICAgIH1cbiAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgfSxcbn0pO1xuIiwiY29uc29sZS5sb2coXCJoZWhlYWhoYWhhIOa1i+ivleWFqOWxgOeUqOazlVwiKTtcblxuXG5tb2R1bGUuZXhwb3J0cyA9IG51bGw7Il0sInNvdXJjZVJvb3QiOiIifQ==