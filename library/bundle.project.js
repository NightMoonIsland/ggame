require=(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({"HomeView":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'a34deLm6dVESYXpleTE+NqY', 'HomeView');
// script/module/HomeView.js

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
    onLoad: function onLoad() {
        console.log("is Loaded");
        // this.node.on('touchstart', function(event){
        //     console.log("mouse down");
        //     event.stopPropagation();
        // }, this);

        // this.node.on('touchend', function(event){
        //     console.log("mouse up");
        //     event.stopPropagation();
        // }, this);

        // this.node.on('mousemove', function(event){
        //     console.log("move");
        //     event.stopPropagation();
        // }, this);

        // this.node.on('mouseleave', function(event){
        //     console.log("leave");
        //     event.stopPropagation();
        // }, this);
    },

    ctor: function ctor() {
        console.log("is ctor");
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    onDestroy: function onDestroy() {
        console.log("is Destory");
    }
});

cc._RF.pop();
},{}],"ListView":[function(require,module,exports){
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

function init(self) {
    cc.tool = {};

    cc.tool.viewManager = new (require("viewManager"))();
    cc.tool.viewManager.init();
    require("viewRegister")();

    cc.tool.eventManager = new (require("eventManager"))();

    cc.tool.gameVariable = require("gameVariable");
    cc.tool.Lang = require("langZh");

    cc.tool.config = require("config");

    cc.tool.protocolInit = require("protocolInit");
    cc.tool.protocolHandler = require("protocolHandler");

    cc.tool.timeHandler = new (require("timeHandler"))();
    cc.tool.timeHandler.init(self);

    // var array = require("array1");
    // var test = new array();

    // var test = new (require("array1"))();

    // for(var i = 10; i < 30; i++){
    //     test.pushBack(i);
    // }
    // test.printInt();
    // test.removeWithFunc(function(data){
    //     return data < 20 && data > 15;
    // });
    // test.printInt();
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
        var self = this;
        init(self);

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
    },

    startT: function startT() {
        cc.tool.timeHandler.startTimer();
    },

    stopT: function stopT() {
        cc.tool.timeHandler.stopTimer();
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
        if (len == 0) return;
        if (len == null || len < 0) {
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
},{}],"kilie5View":[function(require,module,exports){
"use strict";
cc._RF.push(module, '0c476B5LZlAvIz6kZgg4jIi', 'kilie5View');
// script/module/kilie5View.js

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

    btnHome: function btnHome() {
        cc.tool.viewManager.changeView("HomeView");
    }

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});

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

var timerCount = 0;

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
        self: cc.Component },

    // use this for initialization

    ctor: function ctor() {},

    init: function init(self) {
        this.self = self;
    },

    updateTimer: function updateTimer() {
        timerCount = timerCount + 1;
        console.log("wo ca");
        console.log("test Work = " + timerCount);
    },

    startTimer: function startTimer() {
        timerCount = 0;
        this.self.schedule(this.updateTimer, 1);
    },

    stopTimer: function stopTimer() {
        timerCount = 0;
        console.log("停下!!");
        this.self.unschedule(this.updateTimer);
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

        var idx = this.viewList.find(viewName);
        if (idx != this.viewList.npos) {
            var len = this.viewList.getSize() - idx;
            this.viewList.remove(idx + 1, len - 1);
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
                self.view.destroy();
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
                    this.view.destroy();
                    this.view = null;
                }
                this.viewName = null;
                return null;
            }

            var self = this;
            cc.loader.loadRes(viewAbout.module, function (err, prefab) {
                var root = cc.instantiate(prefab);
                cc.director.getScene().getChildByName("Canvas").addChild(root);
                if (self.view != null) {
                    self.view.removeFromParent();
                    self.view.destroy();
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
    cc.tool.viewManager.registView("HomeView", "ui/HomeView", 2);
};

cc._RF.pop();
},{}]},{},["ListView","Renderer","appStart","config","langZh","array1","HomeView","TopLayer","kilie5View","kmView","protocolHandler","protocolInit","timeHandler","testTs","baseView","eventManager","test","urlManager","viewManager","viewRegister","gameVariable"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9zY3JpcHQvbW9kdWxlL0hvbWVWaWV3LmpzIiwiYXNzZXRzL3Jlc291cmNlcy9jb250cm9sL0xpc3RWaWV3LmpzIiwiYXNzZXRzL3Jlc291cmNlcy9jb250cm9sL1JlbmRlcmVyLmpzIiwiYXNzZXRzL3NjcmlwdC9tb2R1bGUvaW5pdHVpL1RvcExheWVyLmpzIiwiYXNzZXRzL3NjcmlwdC9hcHBTdGFydC5qcyIsImFzc2V0cy9zY3JpcHQvbGlicmFyeS9hcnJheTEuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvYmFzZVZpZXcuanMiLCJhc3NldHMvc2NyaXB0L2NvbmZpZy9jb25maWcuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvZXZlbnRNYW5hZ2VyLmpzIiwiYXNzZXRzL3NjcmlwdC92YXJpYWJsZS9nYW1lVmFyaWFibGUuanMiLCJhc3NldHMvc2NyaXB0L21vZHVsZS9raWxpZTVWaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9tb2R1bGUva21WaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvbGFuZ1poLmpzIiwiYXNzZXRzL3NjcmlwdC9uZXRwcm90b2NvbC9wcm90b2NvbEhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L25ldHByb3RvY29sL3Byb3RvY29sSW5pdC5qcyIsImFzc2V0cy9zY3JpcHQvdGVzdFRzLnRzIiwiYXNzZXRzL3NjcmlwdC90b29sL3Rlc3QuanMiLCJhc3NldHMvc2NyaXB0L3Byb2Nlc3MvdGltZUhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdXJsTWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3UmVnaXN0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6Ijs7Ozs7OztBQUFBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBRUg7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNIO0FBcERJOzs7Ozs7Ozs7Ozs7OztBQ0FUOztBQUVBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNJO0FBQ0E7QUFGUTs7QUFNWjtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBR0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQTlCUTs7QUFpQ1o7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBR0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0k7QUFDSTtBQUdBO0FBQ0g7QUFDSjtBQUVHO0FBQ0k7QUFHQTtBQUNIO0FBQ0o7QUFDSjs7QUF6RUw7QUE0RVE7QUFDSDtBQVFHOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNIO0FBR0c7O0FBRUE7QUFDSTtBQUNBO0FBQ0g7QUFFRztBQUNIOztBQUVEO0FBQ0k7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7QUFDSjtBQUdHO0FBQ0E7QUFDSDs7Ozs7Ozs7OztBQ3hJTDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFWUTs7QUFhWjtBQUNBOztBQUlBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSDs7QUFFRDtBQUNBOztBQUVBO0FBakNLOzs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNKOztBQXJCSTs7Ozs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNBO0FBQ0E7O0FBRUE7O0FBRUE7QUFDQTs7QUFFQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7O0FBR0E7QUFDQTs7QUFFQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVpROztBQWVaO0FBQ0E7QUFDSTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTs7O0FBR0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTs7QUFFQTtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIO0FBdkdJOzs7Ozs7Ozs7O0FDcENUOztBQUVJO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFiUTtBQWVaO0FBQ0E7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBRUc7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUNKO0FBQ0o7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0k7QUFFQTtBQUNJO0FBREo7QUFHSTtBQURKO0FBR0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFESjtBQUdIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUVHO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQUNJO0FBQ0g7QUFDSjtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUNKOztBQUVEO0FBQ0E7O0FBRUE7QUF6SUs7Ozs7Ozs7Ozs7QUNBVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFWUTs7QUFhWjtBQUNBOztBQWpCSzs7Ozs7Ozs7OztBQ0FUOztBQUVBO0FBQ0E7QUFDQTs7QUFFQTs7Ozs7Ozs7OztBQ05BO0FBQ0E7O0FBRUE7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBOztBQUlBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQUNJO0FBQ0g7QUFDSjtBQUNKOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0E7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNIO0FBQ0Q7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBdkVJOzs7Ozs7Ozs7O0FDSFQ7O0FBRUE7O0FBRUE7Ozs7Ozs7Ozs7QUNKQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFWUTs7QUFhWjtBQUNBOztBQUlBO0FBQ0k7QUFDSDs7QUFFRDtBQUNBOztBQUVBO0FBNUJLOzs7Ozs7Ozs7O0FDQVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBSUo7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNIO0FBaERJOzs7Ozs7Ozs7O0FDQVQ7O0FBRUE7O0FBRUE7Ozs7Ozs7Ozs7QUNKQTtBQUNBOztBQUVBO0FBR0E7QUFHQTtBQUNJO0FBQ0g7O0FBRUQ7Ozs7Ozs7Ozs7Ozs7O0FDYkE7QUFDQTs7QUFFQTtBQUNBOztBQU1BO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7O0FBRUE7Ozs7Ozs7OztBQ2xCTTtBQUdOO0FBQXNDO0FBRHRDO0FBQUE7QUFTSTs7QUFNSjtBQUpJO0FBQ0k7QUFFSjtBQUNKO0FBQUE7QUFYSTtBQURDO0FBQ2U7QUFLaEI7QUFIQztBQUNHO0FBQ0g7QUFDc0I7QUFSTjtBQURwQjtBQUNvQjtBQUFBOzs7Ozs7Ozs7O0FDSHJCO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQXZCSTs7Ozs7Ozs7OztBQ0FUOztBQUVBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdKOztBQUVBOztBQUdBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQS9DSTs7Ozs7Ozs7OztBQ0ZUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBakJLOzs7Ozs7Ozs7O0FDRVQ7QUFDSTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFkUTs7QUFpQlo7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUVIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIOztBQUVEOztBQUVBO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFFRztBQUNIO0FBQ0Q7O0FBRUE7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNIOztBQUVEO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNIOztBQUVEO0FBQ0k7QUFDSTtBQUNIO0FBRUc7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7O0FBRUE7QUFDQTtBQUNBO0FBQ0k7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNIO0FBQ0Q7QUFDQTtBQUNIO0FBQ0Q7QUFDSDtBQWhKSTs7Ozs7Ozs7OztBQ0ZUOztBQUdBO0FBQ0k7QUFDQTtBQUNBO0FBQ0giLCJzb3VyY2VzQ29udGVudCI6WyJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJpcyBMb2FkZWRcIik7XG4gICAgICAgIC8vIHRoaXMubm9kZS5vbigndG91Y2hzdGFydCcsIGZ1bmN0aW9uKGV2ZW50KXtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwibW91c2UgZG93blwiKTtcbiAgICAgICAgLy8gICAgIGV2ZW50LnN0b3BQcm9wYWdhdGlvbigpO1xuICAgICAgICAvLyB9LCB0aGlzKTtcblxuICAgICAgICAvLyB0aGlzLm5vZGUub24oJ3RvdWNoZW5kJywgZnVuY3Rpb24oZXZlbnQpe1xuICAgICAgICAvLyAgICAgY29uc29sZS5sb2coXCJtb3VzZSB1cFwiKTtcbiAgICAgICAgLy8gICAgIGV2ZW50LnN0b3BQcm9wYWdhdGlvbigpO1xuICAgICAgICAvLyB9LCB0aGlzKTtcblxuICAgICAgICAvLyB0aGlzLm5vZGUub24oJ21vdXNlbW92ZScsIGZ1bmN0aW9uKGV2ZW50KXtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwibW92ZVwiKTtcbiAgICAgICAgLy8gICAgIGV2ZW50LnN0b3BQcm9wYWdhdGlvbigpO1xuICAgICAgICAvLyB9LCB0aGlzKTtcblxuICAgICAgICAvLyB0aGlzLm5vZGUub24oJ21vdXNlbGVhdmUnLCBmdW5jdGlvbihldmVudCl7XG4gICAgICAgIC8vICAgICBjb25zb2xlLmxvZyhcImxlYXZlXCIpO1xuICAgICAgICAvLyAgICAgZXZlbnQuc3RvcFByb3BhZ2F0aW9uKCk7XG4gICAgICAgIC8vIH0sIHRoaXMpO1xuXG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiaXMgY3RvclwiKTtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcblxuICAgIG9uRGVzdHJveTogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiaXMgRGVzdG9yeVwiKTtcbiAgICB9XG59KTtcbiIsInZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuXG4gICAgICAgIHNjcm9sbFZpZXc6IHtcbiAgICAgICAgICAgIGRlZmF1bHQ6IG51bGwsXG4gICAgICAgICAgICB0eXBlOiBjYy5TY3JvbGxWaWV3XG4gICAgICAgIH0sXG5cbiAgICAgICAgXG4gICAgICAgIGRpcjogMCwgXG4gICAgICAgIGxpbmVzOiAwLCBcbiAgICAgICAgaGdhcDogMCwgXG4gICAgICAgIHZnYXA6IDAsIFxuICAgICAgICB3aWR0aDogMCwgXG4gICAgICAgIGhlaWdodDogMCxcbiAgICAgICAgXG5cbiAgICAgICAgZHA6IG51bGwsXG4gICAgICAgIGl0ZW06IGNjLlByZWZhYixcbiAgICAgICAgaXRlbVB3ZDogbnVsbCxcbiAgICAgICAgaXRlbUhlaWdodDogMCxcbiAgICAgICAgaXRlbVdpZHRoOiAwLFxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgdGhpcy51cGRhdGVUaW1lciA9IDA7XG4gICAgICAgIGRwID0gbmV3IGFycmF5MSgpO1xuICAgIH0sXG5cbiAgICBjcmVhdGU6IGZ1bmN0aW9uKGRpciwgbGluZXMsIGhnYXAsIHZnYXAsIHdpZHRoLCBoZWlnaHQpIHtcbiAgICAgICAgdGhpcy5kaXIgPSBkaXI7XG4gICAgICAgIHRoaXMubGluZXMgPSBsaW5lcztcbiAgICAgICAgdGhpcy5oZ2FwID0gaGdhcDtcbiAgICAgICAgdGhpcy52Z2FwID0gdmdhcDtcbiAgICAgICAgdGhpcy53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLmhlaWdodCA9IGhlaWdodDtcblxuXG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LmhlaWdodCA9IGhlaWdodDtcbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLm5vZGUucGFyZW50LmhlaWdodCA9IGhlaWdodDtcblxuICAgICAgICAvLyB0aGlzLm5vZGUucGFyZW50LnBhcmVudC5zZXRDb250ZW50U2l6ZShjYy5TaXplKHdpZHRoLCBoZWlnaHQpKTtcbiAgICAgICAgLy8gdGhpcy5ub2RlLnBhcmVudC5zZXRDb250ZW50U2l6ZShjYy5TaXplKHdpZHRoLCBoZWlnaHQpKTtcbiAgICAgICAgaWYoZGlyID09IGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMKXtcbiAgICAgICAgICAgIHRoaXMuY2FsY1NlY3Rpb24gPSBmdW5jdGlvbihzZWxmKSB7XG4gICAgICAgICAgICAgICAgaWYoIXNlbGYuZHAgfHwgc2VsZi5kcC5zaXplKCkgPT0gMCl7XG4gICAgICAgICAgICAgICAgICAgIFxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB2YXIgaW50ZXJ2YWwgPSBzZWxmLml0ZW1IZWlnaHQgKyBzZWxmLnZnYXA7XG4gICAgICAgICAgICB9O1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLmNhbGNTZWN0aW9uID0gZnVuY3Rpb24oc2VsZikge1xuICAgICAgICAgICAgICAgIGlmKCFzZWxmLmRwIHx8IHNlbGYuZHAuc2l6ZSgpID09IDApe1xuICAgICAgICAgICAgICAgICAgICBcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgdmFyIGludGVydmFsID0gc2VsZi5pdGVtSGVpZ2h0ICsgc2VsZi52Z2FwO1xuICAgICAgICAgICAgfTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2codGhpcy53aWR0aCArIFwiIHdvY2FvIFwiICsgdGhpcy5oZWlnaHQpO1xuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICBzZXRJdGVtTW9kZWw6IGZ1bmN0aW9uKGl0ZW0sIGl0ZW1XaWR0aCwgaXRlbUhlaWdodCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG5cbiAgICAgICAgdGhpcy5pdGVtUHdkID0gaXRlbTtcbiAgICAgICAgLy8gY2MubG9hZGVyLmxvYWRSZXMoaXRlbSwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgIC8vICAgICAvLyBjYy50b29sLnByZWZhYi5saXN0VmlldyA9IHByZWZhYjtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwidHlwZSBwcmVmYWIgPSBcIiArIHR5cGVvZiBwcmVmYWIpXG4gICAgICAgIC8vICAgICBzZWxmLml0ZW0gPSBwcmVmYWI7XG4gICAgICAgIC8vIH0pO1xuICAgICAgICBjYy5sb2FkZXIubG9hZFJlcyhpdGVtLCBjYy5QcmVmYWIpO1xuICAgICAgICBzZWxmLml0ZW1XaWR0aCA9IGl0ZW1XaWR0aDtcbiAgICAgICAgc2VsZi5pdGVtSGVpZ2h0ID0gaXRlbUhlaWdodDtcbiAgICB9LFxuXG4gICAgc2V0RGF0YVByb3ZpZGVyOiBmdW5jdGlvbihkbCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG5cbiAgICAgICAgaWYodGhpcy5kaXIgPT0gY2MudG9vbC5jb25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwpe1xuICAgICAgICAgICAgdGhpcy5ub2RlLmhlaWdodCA9IGRsLmdldFNpemUoKSAqICh0aGlzLml0ZW1IZWlnaHQgKyB0aGlzLmhnYXApIC0gdGhpcy5oZ2FwO1xuICAgICAgICAgICAgdGhpcy5ub2RlLndpZHRoID0gdGhpcy53aWR0aDtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgdGhpcy5ub2RlLmhlaWdodCA9IHRoaXMuaGVpZ2h0O1xuICAgICAgICB9ICAgIFxuXG4gICAgICAgIGRsLmV4Y3V0ZVdpdGhGdW5jKGZ1bmN0aW9uKGRhdGEsIGluZGV4KXtcbiAgICAgICAgICAgIHZhciBwcmVmYWIgPSBjYy5sb2FkZXIuZ2V0UmVzKHNlbGYuaXRlbVB3ZCwgY2MuUHJlZmFiKTtcblxuICAgICAgICAgICAgbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgaXRlbS5zZXRQb3MoMCwgLXNlbGYuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuXG4gICAgICAgICAgICAvLyBjYy5sb2FkZXIuZ2V0UmVzKHNlbGYuaXRlbVB3ZCwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgICAgICAvLyAgICAgbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vICAgICAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vICAgICBpdGVtLnNldFBvcygwLCAtc2VsZi5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gICAgIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuICAgICAgICAgICAgLy8gfSk7XG5cbiAgICAgICAgICAgIC8vIGxldCBpdGVtID0gY2MuaW5zdGFudGlhdGUoc2VsZi5pdGVtKS5nZXRDb21wb25lbnQoJ1JlbmRlcmVyJyk7XG4gICAgICAgICAgICAvLyAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vIGl0ZW0uc2V0UG9zKDAsIC1zZWxmLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyBzZWxmLm5vZGUuYWRkQ2hpbGQoaXRlbS5ub2RlKTtcbiAgICAgICAgfSk7XG4gICAgfSxcblxuICAgIHVwZGF0ZSAoZHQpIHtcbiAgICAgICAgdGhpcy51cGRhdGVUaW1lciArPSBkdDtcbiAgICAgICAgaWYodGhpcy51cGRhdGVUaW1lciA8IHRoaXMudXBkYXRlSW50ZXJ2YWwpIHJldHVybjtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgc2V0UG9zWTogZnVuY3Rpb24oeSkge1xuICAgICAgICB0aGlzLm5vZGUueSA9IHk7XG4gICAgfSxcblxuICAgIHNldFBvczogZnVuY3Rpb24oeCwgeSkge1xuICAgICAgICB0aGlzLm5vZGUueCA9IHg7XG4gICAgICAgIHRoaXMubm9kZS55ID0geTtcbiAgICB9XG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgdGhpcy5ub2RlLm9uKCdtb3VzZWRvd24nLCBmdW5jdGlvbiAoZXZlbnQpIHtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKCdNb3VzZSBkb3duJyk7XG4gICAgICAgIH0sIHRoaXMpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJmdW5jdGlvbiBpbml0KHNlbGYpe1xuICAgIGNjLnRvb2wgPSB7fVxuXG4gICAgY2MudG9vbC52aWV3TWFuYWdlciA9IG5ldyAocmVxdWlyZShcInZpZXdNYW5hZ2VyXCIpKSgpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIuaW5pdCgpO1xuICAgIHJlcXVpcmUoXCJ2aWV3UmVnaXN0ZXJcIikoKTtcblxuICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyID0gbmV3IChyZXF1aXJlKFwiZXZlbnRNYW5hZ2VyXCIpKSgpO1xuXG4gICAgY2MudG9vbC5nYW1lVmFyaWFibGUgPSByZXF1aXJlKFwiZ2FtZVZhcmlhYmxlXCIpO1xuICAgIGNjLnRvb2wuTGFuZyA9IHJlcXVpcmUoXCJsYW5nWmhcIik7XG5cbiAgICBjYy50b29sLmNvbmZpZyA9IHJlcXVpcmUoXCJjb25maWdcIik7XG5cbiAgICBjYy50b29sLnByb3RvY29sSW5pdCA9IHJlcXVpcmUoXCJwcm90b2NvbEluaXRcIik7XG4gICAgY2MudG9vbC5wcm90b2NvbEhhbmRsZXIgPSByZXF1aXJlKFwicHJvdG9jb2xIYW5kbGVyXCIpO1xuXG4gICAgY2MudG9vbC50aW1lSGFuZGxlciA9IG5ldyAocmVxdWlyZShcInRpbWVIYW5kbGVyXCIpKSgpO1xuICAgIGNjLnRvb2wudGltZUhhbmRsZXIuaW5pdChzZWxmKTtcblxuXG4gICAgLy8gdmFyIGFycmF5ID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICAvLyB2YXIgdGVzdCA9IG5ldyBhcnJheSgpO1xuXG4gICAgLy8gdmFyIHRlc3QgPSBuZXcgKHJlcXVpcmUoXCJhcnJheTFcIikpKCk7XG5cbiAgICAvLyBmb3IodmFyIGkgPSAxMDsgaSA8IDMwOyBpKyspe1xuICAgIC8vICAgICB0ZXN0LnB1c2hCYWNrKGkpO1xuICAgIC8vIH1cbiAgICAvLyB0ZXN0LnByaW50SW50KCk7XG4gICAgLy8gdGVzdC5yZW1vdmVXaXRoRnVuYyhmdW5jdGlvbihkYXRhKXtcbiAgICAvLyAgICAgcmV0dXJuIGRhdGEgPCAyMCAmJiBkYXRhID4gMTU7XG4gICAgLy8gfSk7XG4gICAgLy8gdGVzdC5wcmludEludCgpO1xufVxuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBoYWhhOiBbXSxcbiAgICAgICAgY291bnQ6IDAsXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIGluaXQoc2VsZik7XG5cbiAgICAgICAgLy8gdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICAvLyBjYy5sb2FkZXIubG9hZFJlcyhcImNvbnRyb2wvTGlzdFZpZXdcIiwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgIC8vICAgICAvLyBjYy50b29sLnByZWZhYi5saXN0VmlldyA9IHByZWZhYjtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwidHlwZSBwcmVmYWIgPSBcIiArIHR5cGVvZiBwcmVmYWIpXG5cbiAgICAgICAgLy8gICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcbiAgICAgICAgLy8gICAgIHJvb3Quc2V0UG9zaXRpb24oY2MudjIoMCwgMCkpO1xuICAgICAgICAvLyAgICAgbGV0IGxpc3RWaWV3ID0gcm9vdC5nZXRDaGlsZEJ5TmFtZShcInZpZXdcIikuZ2V0Q2hpbGRCeU5hbWUoXCJjb250ZW50XCIpLmdldENvbXBvbmVudChcIkxpc3RWaWV3XCIpO1xuICAgICAgICAvLyAgICAgbGlzdFZpZXcuY3JlYXRlKGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMLCAxLCAxLCAxLCAyNDAsIDE1MCk7XG4gICAgICAgIC8vICAgICBsaXN0Vmlldy5zZXRJdGVtTW9kZWwoXCJjb250cm9sL1JlbmRlcmVyXCIsIDE2MCwgNjApO1xuXG4gICAgICAgIC8vICAgICB2YXIgYXJyYXkgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICAvLyAgICAgdmFyIHRlc3QgPSBuZXcgYXJyYXkoKTtcbiAgICAgICAgLy8gICAgIGZvcihpID0gMDsgaSA8IDU7IGkrKyl7XG4gICAgICAgIC8vICAgICAgICAgdGVzdC5wdXNoQmFjayhpICsgMTAwKVxuICAgICAgICAvLyAgICAgfVxuXG4gICAgICAgIC8vICAgICBsaXN0Vmlldy5zZXREYXRhUHJvdmlkZXIodGVzdCk7XG5cblxuICAgICAgICAvLyAgICAgc2VsZi5ub2RlLmFkZENoaWxkKHJvb3QpO1xuICAgICAgICAvLyB9KTtcblxuICAgICAgICAvL+aaguaXtuS4jeeUqOWumuaXtuWZqFxuICAgICAgICAvLyB0aGlzLnNjaGVkdWxlKGZ1bmN0aW9uKCl7XG4gICAgICAgIC8vICAgICB0aGlzLnVwZGF0ZVRpbWUoKTtcbiAgICAgICAgLy8gfSwgMSk7XG4gICAgfSxcblxuICAgIHVwZGF0ZVRpbWU6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInRoaXMuY291bnQgPSBcIiArIHRoaXMuY291bnQpO1xuICAgICAgICB0aGlzLmNvdW50ID0gdGhpcy5jb3VudCArIDE7XG4gICAgICAgIC8vIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLlZBUl9DSEFOR0UoXCJzZWMxXCIpO1xuICAgICAgICBjYy50b29sLmdhbWVWYXJpYWJsZS5zZWMgPSBjYy50b29sLmdhbWVWYXJpYWJsZS5zZWMgKyAxO1xuICAgIH0sXG5cbiAgICB0ZXN0RnVuYzogZnVuY3Rpb24oKSB7XG4gICAgICAgIHZhciBzdHIxID0gXCJoZWxsb3dvcmRcIjtcbiAgICAgICAgdGhpcy5oZWxsb3dvcmQgPSBmdW5jdGlvbigpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ3b3RlZnVuY2tcIik7XG4gICAgICAgIH1cbiAgICAgICAgdGhpc1tzdHIxXSgpO1xuICAgIH0sXG5cbiAgICBpbml0U2NlbmU6IGZ1bmN0aW9uKCkge1xuICAgICAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnNldFJvb3QodGhpcy5ub2RlKTtcbiAgICAgICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwiaGFoaGFoYWhhYVwiKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ0ZXN0IHR5cGVcIiArIHR5cGVvZiB0aGlzLmhhaGFbXCJ3b2Nhb1wiXSk7XG4gICAgfSxcblxuICAgIHRlc3RSZW1vdmU6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjYy50b29sLnZpZXdNYW5hZ2VyLmNoYW5nZVZpZXcoXCJrbVZpZXdcIik7XG4gICAgfSxcblxuICAgIGJ0bkJhY2s6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjYy50b29sLnZpZXdNYW5hZ2VyLmJhY2tQcmV2aWV3KCk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBjb25uZWN0VGVzdDogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29yayBjb25uZWN0XCIpO1xuICAgICAgICB2YXIgc29ja2V0ID0gaW8uY29ubmVjdCgnMTAuMTAuMzAuMjM0OjEyMzQ1JywgZnVuY3Rpb24obXNnKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKG1zZyk7XG4gICAgICAgIH0pO1xuICAgICAgICBmb3IodmFyIGkgPSAwOyBpIDwgY2MudG9vbC5wcm90b2NvbEluaXQudG1SZXMubGVuZ3RoOyBpKyspe1xuICAgICAgICAgICAgc29ja2V0Lm9uKGNjLnRvb2wucHJvdG9jb2xJbml0LnRtUmVzW2ldLCBjYy50b29sLnByb3RvY29sSGFuZGxlcltjYy50b29sLnByb3RvY29sSW5pdC50bVJlc1tpXV0pO1xuICAgICAgICB9XG4gICAgICAgIHNvY2tldC5lbWl0KCdoZWhlaGFoYScsIHthYmM6XCJ3b3poZW5kZXJpbGVnb3VsZVwifSk7XG4gICAgfSxcblxuICAgIHN0YXJ0VDogZnVuY3Rpb24oKXtcbiAgICAgICAgY2MudG9vbC50aW1lSGFuZGxlci5zdGFydFRpbWVyKCk7XG4gICAgfSxcblxuICAgIHN0b3BUOiBmdW5jdGlvbigpe1xuICAgICAgICBjYy50b29sLnRpbWVIYW5kbGVyLnN0b3BUaW1lcigpO1xuICAgIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgbGlzdDogW10sXG4gICAgICAgIHNpemU6IDAsXG4gICAgICAgIG5wb3M6IC0xLFxuICAgIH0sXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29ya2VkXCIpO1xuICAgIH0sXG5cbiAgICBhc2ZkZnNkZjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW9cIik7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKHR5cGVvZiB0aGlzLmxpc3QpO1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xuICAgIH0sXG5cbiAgICBzdGF0dXM6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTFcIik7XG4gICAgICAgIGNvbnNvbGUubG9nKHRoaXMuc2l6ZSk7XG4gICAgICAgIGNvbnNvbGUubG9nKFwic2VsZi5zaXplMlwiKTtcbiAgICB9LFxuICAgIC8vXG4gICAgcHVzaEJhY2s6IGZ1bmN0aW9uKGRhdGEpIHtcbiAgICAgICAgdGhpcy5saXN0W3RoaXMuc2l6ZV0gPSBkYXRhO1xuICAgICAgICB0aGlzLnNpemUgPSB0aGlzLnNpemUgKyAxO1xuICAgIH0sXG5cbiAgICBhdDogZnVuY3Rpb24oaWR4KXtcbiAgICAgICAgcmV0dXJuIHRoaXMubGlzdFtpZHhdO1xuICAgIH0sXG5cbiAgICBmaW5kOiBmdW5jdGlvbih2YWx1ZSl7XG4gICAgICAgIHZhciBpbmRleCA9IHRoaXMubnBvcztcbiAgICAgICAgaWYgKHR5cGVvZiB2YWx1ZSA9PSBcImZ1bmN0aW9uXCIpe1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgICAgIGlmKHZhbHVlKGkpKSByZXR1cm4gaTtcbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgICAgIGlmKHRoaXMubGlzdFtpXSA9PSB2YWx1ZSl7XG4gICAgICAgICAgICAgICAgICAgIGluZGV4ID0gaTtcbiAgICAgICAgICAgICAgICAgICAgYnJlYWs7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgfVxuICAgICAgICB9XG4gICAgICAgIHJldHVybiBpbmRleDtcbiAgICB9LFxuXG4gICAgcmVtb3ZlOiBmdW5jdGlvbihwb3MsIGxlbil7XG4gICAgICAgIGlmKHBvcyA8IDApIHBvcyA9IDA7XG4gICAgICAgIGlmKGxlbiA9PSAwKSByZXR1cm47XG4gICAgICAgIGlmKGxlbiA9PSBudWxsIHx8IGxlbiA8IDApe1xuICAgICAgICAgICAgbGVuID0gMTtcbiAgICAgICAgfVxuICAgICAgICBpZihwb3MgPCB0aGlzLnNpemUpe1xuICAgICAgICAgICAgaWYocG9zICsgbGVuID4gdGhpcy5zaXplKVxuICAgICAgICAgICAgICAgIGxlbiA9IHRoaXMuc2l6ZSAtIHBvcztcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IGxlbjsgaSsrKVxuICAgICAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbcG9zICsgaV07XG4gICAgICAgICAgICBmb3IoaSA9IHBvcyArIGxlbjsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxuICAgICAgICAgICAgICAgIHRoaXMubGlzdFtpIC0gbGVuXSA9IHRoaXMubGlzdFtpXTtcbiAgICAgICAgICAgIHRoaXMuc2l6ZSA9IHRoaXMuc2l6ZSAtIGxlbjtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBjbGVhcjogZnVuY3Rpb24oKXtcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICBkZWxldGUgdGhpcy5saXN0W2ldO1xuICAgICAgICB0aGlzLnNpemUgPSAwO1xuICAgIH0sXG5cbiAgICBnZXRTaXplOiBmdW5jdGlvbigpIHtcbiAgICAgICAgcmV0dXJuIHRoaXMuc2l6ZTtcbiAgICB9LFxuXG4gICAgYmFjazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGlmKHRoaXMuc2l6ZSA+IDApe1xuICAgICAgICAgICAgcmV0dXJuIHRoaXMubGlzdFt0aGlzLnNpemUgLSAxXTtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgZW1wdHk6IGZ1bmN0aW9uKCkge1xuICAgICAgICByZXR1cm4gdGhpcy5zaXplID09IDA7XG4gICAgfSxcblxuICAgIG91dFB1dDogZnVuY3Rpb24oKSB7XG4gICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxuICAgICAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50XCIgKyBpICsgXCIgPSBcIiArIHRoaXMubGlzdFtpXSk7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiZWxlbWVudCBzaXplID0gXCIgKyB0aGlzLnNpemUpO1xuICAgIH0sXG5cbiAgICBleGN1dGVXaXRoRnVuYzogZnVuY3Rpb24oZnVuYykge1xuICAgICAgICBmb3IodmFyIGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xuICAgICAgICAgICAgZnVuYyh0aGlzLmxpc3RbaV0sIGkpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIHJlbW92ZVdpdGhGdW5jOiBmdW5jdGlvbihmdW5jKXtcbiAgICAgICAgZm9yKHZhciBpID0gdGhpcy5zaXplIC0gMTsgaSA+PSAwOyBpLS0pe1xuICAgICAgICAgICAgaWYoZnVuYyh0aGlzLmxpc3RbaV0pKXtcbiAgICAgICAgICAgICAgICB0aGlzLnJlbW92ZShpKTtcbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBwb3BCYWNrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgaWYodGhpcy5zaXplID4gMCl7XG4gICAgICAgICAgICBkZWxldGUgdGhpcy5saXN0W3RoaXMuc2l6ZSAtIDFdO1xuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gMTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBwcmludEludDogZnVuY3Rpb24oKXtcbiAgICAgICAgZm9yKHZhciBpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiaW5kZXggXCIgKyBpICsgXCIgPSBcIiArIHRoaXMubGlzdFtpXSk7XG4gICAgICAgIH1cbiAgICB9XG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJ2YXIgQ29uZmlnID0ge307XG5cbkNvbmZpZy5EaXJlY3Rpb24gPSB7fTtcbkNvbmZpZy5EaXJlY3Rpb24uVkVSVElDQUwgPSAwO1xuQ29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMID0gMTtcblxubW9kdWxlLmV4cG9ydHMgPSBDb25maWc7IiwidmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIilcbnZhciB0ZXN0ID0gcmVxdWlyZShcInRlc3RcIilcblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IHRlc3QsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGV2ZW50TGlzdGVuZXI6IFtdLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgXG4gICAgfSxcblxuICAgIGluaXQ6IGZ1bmN0aW9uKCkge1xuICAgICAgICB0aGlzLnN1cGVyLnRlc3RXb3JrKCk7XG4gICAgfSxcblxuICAgIHRlc3RXb3JrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ6ZW5tZSBodWkgemhleWFuZ1wiKTtcbiAgICB9LFxuXG4gICAgYWRkRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlLCB0YXJnZXQsIGZ1bmMpIHtcbiAgICAgICAgdGFyZ2V0Lm91dHB1dCgpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZygpXG4gICAgICAgIGlmKCF0YXJnZXQgfHwgIWZ1bmMpIHJldHVybjtcbiAgICAgICAgaWYoIXRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdKXtcbiAgICAgICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdID0gbmV3IGFycmF5MSgpO1xuICAgICAgICB9XG4gICAgICAgIHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdLnB1c2hCYWNrKHt0YXJnZXQ6dGFyZ2V0LCBmdW5jOmZ1bmN9KTtcbiAgICB9LFxuXG4gICAgcmVtb3ZlRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlLCB0YXJnZXQsIGZ1bmMpe1xuICAgICAgICBpZih0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSl7XG4gICAgICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXS5yZW1vdmVXaXRoRnVuYyhmdW5jdGlvbihkYXRhKXtcbiAgICAgICAgICAgICAgICByZXR1cm4gZGF0YS50YXJnZXQgPT0gdGFyZ2V0O1xuICAgICAgICAgICAgfSk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgdGVzdFdvcmtMaXN0ZW5lcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidG8gdGVzdCBsaXN0ZW5lclwiKTtcbiAgICAgICAgZm9yKHZhciBrZXkgaW4gdGhpcy5ldmVudExpc3RlbmVyW1wiaGFoYWhhXCJdKXtcbiAgICAgICAgICAgIHZhciBmdW5jID0gdGhpcy5ldmVudExpc3RlbmVyW1wiaGFoYWhhXCJdW2tleV07XG4gICAgICAgICAgICBmdW5jKFwiaGFoYWhhXCIpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGRpc3BhdGNoRXZlbnRMaXN0ZW5lcjogZnVuY3Rpb24oZXZlbnRUeXBlKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiZXZlbnRUeXBlXCIpO1xuICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXS5leGN1dGVXaXRoRnVuYyhmdW5jdGlvbihpdGVtLCBpbmRleCl7XG4gICAgICAgICAgICB2YXIgZnVuYyA9IGl0ZW0uZnVuYztcbiAgICAgICAgICAgIHZhciB0YXJnZXQgPSBpdGVtLnRhcmdldDtcbiAgICAgICAgICAgIGZ1bmModGFyZ2V0LCBldmVudFR5cGUpO1xuICAgICAgICB9KVxuICAgICAgICAvLyBmb3IodmFyIGtleSBpbiB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSl7XG4gICAgICAgIC8vICAgICB2YXIgZnVuYyA9IHRoaXMuZXZlbnRMaXN0ZW5lcltldmVudFR5cGVdW2tleV07XG4gICAgICAgIC8vICAgICBmdW5jKGtleSwgZXZlbnRUeXBlKTtcbiAgICAgICAgLy8gfVxuICAgIH0sXG5cbiAgICBWQVJfQ0hBTkdFOiBmdW5jdGlvbih2YXJOYW1lKXtcbiAgICAgICAgdGhpcy5kaXNwYXRjaEV2ZW50TGlzdGVuZXIodmFyTmFtZSk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsInZhciBnYW1lVmFyID0gW107XG5cbmdhbWVWYXIuc2VjID0gMDtcblxubW9kdWxlLmV4cG9ydHMgPSBnYW1lVmFyOyIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIGJ0bkhvbWU6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjYy50b29sLnZpZXdNYW5hZ2VyLmNoYW5nZVZpZXcoXCJIb21lVmlld1wiKTtcbiAgICB9XG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBldmVudFR5cGU6IG51bGwsXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICB0aGlzLmV2ZW50VHlwZSA9IG5ldyBBcnJheShcInNlYzFcIiwgXCJzZWMyXCIsIFwic2VjM1wiKTtcbiAgICAgICAgXG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgZm9yKHZhciBpID0gMDsgaSA8IHRoaXMuZXZlbnRUeXBlLmxlbmd0aDsgaSsrKXtcbiAgICAgICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLmFkZEV2ZW50TGlzdGVuZXIoc2VsZi5ldmVudFR5cGVbaV0sIHNlbGYsIHNlbGYub25WYXJDYWxsYmFjayk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgb25WYXJDYWxsYmFjazogZnVuY3Rpb24oc2VsZiwgdmFyTmFtZSkge1xuICAgICAgICBpZih2YXJOYW1lID09IFwic2VjMVwiKXtcbiAgICAgICAgICAgIC8vc2VsZi5vdXRwdXQoKTtcbiAgICAgICAgICAgIHNlbGYubm9kZS5nZXRDaGlsZEJ5TmFtZShcInR4dGhhaGFcIikuZ2V0Q29tcG9uZW50KGNjLkxhYmVsKS5zdHJpbmcgPSBcInNlYyA9IFwiICsgY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjO1xuICAgICAgICB9XG4gICAgICAgIGVsc2UgaWYodmFyTmFtZSA9PSBcIlwiKXtcblxuICAgICAgICB9XG4gICAgfSxcblxuICAgIG91dHB1dDogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3byBjYW8gbmkgbWEgZ2UgY2hvdSBoYWlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBidG5UZWFtOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwia2lsaWU1Vmlld1wiKTtcbiAgICB9LFxufSk7XG4iLCJ2YXIgTGFuZyA9IFtdO1xuXG5MYW5nW1wiSVRFTV9WQUxVRVwiXSA9IFwi5Y+Y5oiQ5Lit5paH55qE5oOF5Ya1XCI7XG5cbm1vZHVsZS5leHBvcnRzID0gTGFuZzsiLCIvL+WwseWDj2x1YemHjOeahENhc2VmdW5jXG52YXIgXyA9IFtdO1xuXG5fLm1zZ19idXlfcmVzID0gZnVuY3Rpb24ocmVzKXtcblxufVxuXy5tc2dfbG9naW5fcmVzID0gZnVuY3Rpb24ocmVzKXtcblxufVxuXy5tc2dfcHZwX3JlcyA9IGZ1bmN0aW9uKHJlcyl7XG4gICAgY29uc29sZS5sb2coXCJyZXMncyB0ZXh0ID0gXCIgKyByZXMudGV4dCk7XG59XG5cbm1vZHVsZS5leHBvcnRzID0gXzsiLCIvL+WwseWDj2x1YemCo+i+ueeahG5ldHByb3RvY29sL2luaXQubHVhXG52YXIgcHJvdG9jb2wgPSBbXTtcblxucHJvdG9jb2wudG1SZXEgPSBbXTtcbnByb3RvY29sLnRtUmVxID0ge1xuICAgIFswXTpcIm1zZ19idXlfcmVxXCIsXG4gICAgWzFdOlwibXNnX2xvZ2luX3JlcVwiLFxuICAgIFsyXTpcIm1zZ19sb2dpbl9yZXFcIixcbn07XG5cbnByb3RvY29sLnRtUmVzID0gW107XG52YXIgdG1SZXMgPSBwcm90b2NvbC50bVJlcztcbnRtUmVzWzBdID0gXCJtc2dfYnV5X3Jlc1wiO1xudG1SZXNbMV0gPSBcIm1zZ19sb2dpbl9yZXNcIjtcbnRtUmVzWzJdID0gXCJtc2dfcHZwX3Jlc1wiO1xuXG5jb25zb2xlLmxvZyhcImxlbmd0aCBcIiArIHByb3RvY29sLnRtUmVzLmxlbmd0aCk7XG5cbm1vZHVsZS5leHBvcnRzID0gcHJvdG9jb2w7IiwiY29uc3Qge2NjY2xhc3MsIHByb3BlcnR5fSA9IGNjLl9kZWNvcmF0b3I7XG5cbkBjY2NsYXNzXG5leHBvcnQgZGVmYXVsdCBjbGFzcyBOZXdDbGFzcyBleHRlbmRzIGNjLkNvbXBvbmVudCB7XG5cbiAgICBAcHJvcGVydHkoY2MuTGFiZWwpXG4gICAgbGFiZWw6IGNjLkxhYmVsO1xuXG4gICAgQHByb3BlcnR5KHtcbiAgICAgICAgZGVmYXVsdDogJ2hlbGxvJ1xuICAgIH0pXG4gICAgdGV4dDogc3RyaW5nID0gJ2hlbGxvJztcblxuICAgIG9uTG9hZCgpIHtcbiAgICAgICAgLy8gaW5pdCBsb2dpY1xuICAgICAgICBcbiAgICB9XG59XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICB0ZXN0V29yazogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyBuaW1hYmlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsInZhciB0aW1lckNvdW50ID0gMDtcblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgc2VsZjogY2MuQ29tcG9uZW50LCAvL+eUqOaMgui9veWcqHNjZW5l5LiK55qE6ISa5pys5L2c5Li66K6h5pe25ZmoXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgfSxcblxuICAgIGluaXQ6IGZ1bmN0aW9uKHNlbGYpIHtcbiAgICAgICAgdGhpcy5zZWxmID0gc2VsZjtcbiAgICB9LFxuXG4gICAgdXBkYXRlVGltZXI6IGZ1bmN0aW9uKCkge1xuICAgICAgICB0aW1lckNvdW50ID0gdGltZXJDb3VudCArIDE7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid28gY2FcIik7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidGVzdCBXb3JrID0gXCIgKyB0aW1lckNvdW50KTtcbiAgICB9LFxuXG4gICAgc3RhcnRUaW1lcjogZnVuY3Rpb24oKXtcbiAgICAgICAgdGltZXJDb3VudCA9IDA7XG4gICAgICAgIHRoaXMuc2VsZi5zY2hlZHVsZSh0aGlzLnVwZGF0ZVRpbWVyLCAxKTtcbiAgICB9LFxuXG4gICAgc3RvcFRpbWVyOiBmdW5jdGlvbigpe1xuICAgICAgICB0aW1lckNvdW50ID0gMDtcbiAgICAgICAgY29uc29sZS5sb2coXCLlgZzkuIshIVwiKTtcbiAgICAgICAgdGhpcy5zZWxmLnVuc2NoZWR1bGUodGhpcy51cGRhdGVUaW1lcik7XG4gICAgfSxcblxuICAgIGRvc29tZXRoaW5nOiBmdW5jdGlvbigpe1xuICAgICAgICBjb25zb2xlLmxvZyhcImRzZ2ZzZGFndmRnYVwiKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2coXCJ0aGlzLmNvdW50ID0gXCIgKyB0aGlzLmNvdW50KTtcbiAgICAgICAgLy8gdGhpcy5jb3VudCA9IHRoaXMuY291bnQgKyAxO1xuICAgIH0sXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiXG5cbmNjLkNsYXNzKHtcbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIHZpZXdMaXN0OiBudWxsLFxuICAgICAgICB2aWV3SW5mbzogW10sXG4gICAgICAgIHZpZXc6IG51bGwsXG4gICAgICAgIHZpZXdOYW1lOiBudWxsLFxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJoaGhlaGVoZVwiKTtcbiAgICAgICAgdmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3QgPSBuZXcgYXJyYXkxKCk7XG4gICAgICAgIC8vIHRoaXMuYXJyYXkxID0gbmV3IHJlcXVpcmUoXCJhcnJheTFcIik7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIHRoaXMudmlld0xpc3QucHVzaEJhY2soe2E6MSwgYjoyfSk7XG4gICAgICAgIHRoaXMudmlld0xpc3Quc3RhdHVzKCk7XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBzZXRSb290OiBmdW5jdGlvbihub2RlKSB7XG4gICAgICAgIHRoaXMucm9vdCA9IG5vZGU7XG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICAvLyBjb25zb2xlLmxvZyhcImhhaGFoYWhoYVwiKTtcblxuICAgICAgICAvLyBjYy52YXJpYWJsZS52aWV3SW5mby5hc2ZkZnNkZigpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy52aWV3TmFtZSk7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBpbml0OiBmdW5jdGlvbigpe1xuICAgICAgICB0aGlzLnZpZXdJbmZvID0gW107XG4gICAgfSxcblxuICAgIHJlZ2lzdFZpZXc6IGZ1bmN0aW9uKHZpZXdOYW1lLCBtb2R1bGUsIHRpdGxlKXtcbiAgICAgICAgdGhpcy52aWV3SW5mb1t2aWV3TmFtZV0gPSB7dmlld05hbWU6dmlld05hbWUsIG1vZHVsZTptb2R1bGUsIHRpdGxlOnRpdGxlfTtcbiAgICB9LFxuXG4gICAgY2hhbmdlVmlldzogZnVuY3Rpb24odmlld05hbWUpe1xuICAgICAgICBpZighdGhpcy52aWV3TGlzdC5lbXB0eSgpICYmIHRoaXMudmlld0xpc3QuYmFjaygpID09IHZpZXdOYW1lKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwidmlldyBpcyBzYW1lXCIpO1xuICAgICAgICAgICAgcmV0dXJuIHRoaXMudmlldztcbiAgICAgICAgfVxuXG4gICAgICAgIHZhciB2aWV3QWJvdXQgPSB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXVxuXG4gICAgICAgIHZhciBpZHggPSB0aGlzLnZpZXdMaXN0LmZpbmQodmlld05hbWUpO1xuICAgICAgICBpZihpZHggIT0gdGhpcy52aWV3TGlzdC5ucG9zKXtcbiAgICAgICAgICAgIHZhciBsZW4gPSB0aGlzLnZpZXdMaXN0LmdldFNpemUoKSAtIGlkeDtcbiAgICAgICAgICAgIHRoaXMudmlld0xpc3QucmVtb3ZlKGlkeCArIDEsIGxlbiAtIDEpO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHZpZXdOYW1lKTtcbiAgICAgICAgfVxuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIDNcIik7XG5cbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICAvL+mAmui/h+mTvuaOpSDliqDovb3nmoTotYTmupAg5b+F6aG75pS+5ZyocmVzb3VyY2XkuItcbiAgICAgICAgY2MubG9hZGVyLmxvYWRSZXModmlld0Fib3V0Lm1vZHVsZSwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgICAgIGlmKHNlbGYudmlldyAhPSBudWxsKXtcbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgIHNlbGYudmlldy5kZXN0cm95KCk7XG4gICAgICAgICAgICAgICAgc2VsZi52aWV3ID0gbnVsbDtcbiAgICAgICAgICAgIH1cbiAgICAgICAgICAgIHNlbGYudmlldyA9IHJvb3Q7XG4gICAgICAgIH0pO1xuICAgICAgICBcbiAgICAgICAgdGhpcy52aWV3TmFtZSA9IHZpZXdOYW1lO1xuICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgIH0sXG5cbiAgICBjdXJWaWV3OiBmdW5jdGlvbigpIHtcbiAgICAgICAgLy8gdGhpcy50ZXN0QWRkQ2hpbGQoKTtcbiAgICAgICAgdmFyIHNlbGYgPSB0aGlzO1xuICAgICAgICBjYy50b29sLmV2ZW50TWFuYWdlci5hZGRFdmVudExpc3RlbmVyKFwiaGFoYWhhXCIsIHNlbGYsIHNlbGYudGVzdEFkZENoaWxkKTtcbiAgICAgICAgY2MudG9vbC5ldmVudE1hbmFnZXIudGVzdFdvcmtMaXN0ZW5lcigpXG4gICAgICAgIHRoaXMudmlldy5yZW1vdmVGcm9tUGFyZW50KGZhbHNlKTtcbiAgICAgICAgY2MubG9hZGVyLnJlbGVhc2VSZXMoXCJwcmVmYWIvVGVzdDFQYW5lbFwiKTtcblxuICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgIH0sXG5cbiAgICB0ZXN0QWRkQ2hpbGQ6IGZ1bmN0aW9uKHZhck5hbWUpe1xuICAgICAgICBpZih2YXJOYW1lID09IFwiaGFoYWhhXCIpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyB0YW1hYmlcIik7XG4gICAgICAgIH1cbiAgICAgICAgZWxzZSBpZih2YXJOYW1lID0gXCJ3b2Nhb25pbWFcIil7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIj8/PyB3b2RldGlhblwiKTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBjdXJWaWV3TmFtZTogZnVuY3Rpb24oKXtcbiAgICAgICAgcmV0dXJuIHRoaXMudmlld05hbWU7XG4gICAgfSxcblxuICAgIGJhY2tQcmV2aWV3OiBmdW5jdGlvbigpe1xuICAgICAgICBpZih0aGlzLnZpZXdMaXN0LmdldFNpemUoKSA+IDApe1xuICAgICAgICAgICAgdGhpcy52aWV3TGlzdC5wb3BCYWNrKCk7XG5cbiAgICAgICAgICAgIHZhciB2aWV3TmFtZSA9IHRoaXMudmlld0xpc3QuYmFjaygpO1xuICAgICAgICAgICAgdmFyIHZpZXdBYm91dCA9IHRoaXMudmlld0luZm9bdmlld05hbWVdO1xuICAgICAgICAgICAgaWYodmlld0Fib3V0ID09IG51bGwpe1xuICAgICAgICAgICAgICAgIGlmKHRoaXMudmlldyAhPSBudWxsKXtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy52aWV3LnJlbW92ZUZyb21QYXJlbnQoKTtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy52aWV3LmRlc3Ryb3koKTtcbiAgICAgICAgICAgICAgICAgICAgdGhpcy52aWV3ID0gbnVsbDtcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgdGhpcy52aWV3TmFtZSA9IG51bGw7XG4gICAgICAgICAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgICAgICAgICB9XG5cbiAgICAgICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKHZpZXdBYm91dC5tb2R1bGUsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgICAgICB2YXIgcm9vdCA9IGNjLmluc3RhbnRpYXRlKHByZWZhYik7XG4gICAgICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgICAgICAgICBpZihzZWxmLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldy5yZW1vdmVGcm9tUGFyZW50KCk7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldy5kZXN0cm95KCk7XG4gICAgICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IG51bGw7XG4gICAgICAgICAgICAgICAgfVxuICAgICAgICAgICAgICAgIHNlbGYudmlldyA9IHJvb3Q7XG4gICAgICAgICAgICB9KTtcbiAgICAgICAgICAgIHRoaXMudmlld05hbWUgPSB2aWV3TmFtZTtcbiAgICAgICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgICAgIH1cbiAgICAgICAgcmV0dXJuIG51bGw7XG4gICAgfSxcbn0pO1xuIiwiY29uc29sZS5sb2coXCJoZWhlYWhoYWhhIOa1i+ivleWFqOWxgOeUqOazlVwiKTtcblxuXG5tb2R1bGUuZXhwb3J0cyA9IGZ1bmN0aW9uKCl7XG4gICAgY2MudG9vbC52aWV3TWFuYWdlci5yZWdpc3RWaWV3KFwia21WaWV3XCIsIFwidWkva21WaWV3XCIsIDIpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImtpbGllNVZpZXdcIiwgXCJ1aS9raWxpZTVWaWV3XCIsIDIpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcIkhvbWVWaWV3XCIsIFwidWkvSG9tZVZpZXdcIiwgMik7XG59OyJdLCJzb3VyY2VSb290IjoiIn0=