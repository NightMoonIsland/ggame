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
},{}]},{},["ListView","Renderer","appStart","config","langZh","array1","kmView","protocolHandler","protocolInit","timeHandler","testTs","eventManager","test","urlManager","viewManager","viewRegister","gameVariable"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9MaXN0Vmlldy5qcyIsImFzc2V0cy9yZXNvdXJjZXMvY29udHJvbC9SZW5kZXJlci5qcyIsImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvY29uZmlnLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL2V2ZW50TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdmFyaWFibGUvZ2FtZVZhcmlhYmxlLmpzIiwiYXNzZXRzL3NjcmlwdC9tb2R1bGUva21WaWV3LmpzIiwiYXNzZXRzL3NjcmlwdC9jb25maWcvbGFuZ1poLmpzIiwiYXNzZXRzL3NjcmlwdC9uZXRwcm90b2NvbC9wcm90b2NvbEhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L25ldHByb3RvY29sL3Byb3RvY29sSW5pdC5qcyIsImFzc2V0cy9zY3JpcHQvdGVzdFRzLnRzIiwiYXNzZXRzL3NjcmlwdC90b29sL3Rlc3QuanMiLCJhc3NldHMvc2NyaXB0L3Byb2Nlc3MvdGltZUhhbmRsZXIuanMiLCJhc3NldHMvc2NyaXB0L3Rvb2wvdXJsTWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3TWFuYWdlci5qcyIsImFzc2V0cy9zY3JpcHQvdG9vbC92aWV3UmVnaXN0ZXIuanMiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6Ijs7Ozs7Ozs7Ozs7QUFBQTs7QUFFQTtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDSTtBQUNBO0FBRlE7O0FBTVo7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUE5QlE7O0FBaUNaO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUdBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0k7QUFHQTtBQUNIO0FBQ0o7QUFFRztBQUNJO0FBR0E7QUFDSDtBQUNKO0FBQ0o7O0FBekVMO0FBNEVRO0FBQ0g7QUFRRzs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDtBQUdHOztBQUVBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNIO0FBQ0o7QUFHRztBQUNBO0FBQ0g7Ozs7Ozs7Ozs7QUN4SUw7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTtBQWpDSzs7Ozs7Ozs7Ozs7O0FDQVQ7QUFDSTtBQUNBO0FBQ0E7QUFDQTs7QUFHQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7QUFDQTs7QUFFQTtBQUNBOztBQUVBO0FBQ0E7O0FBRUE7O0FBRUE7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVpROztBQWVaO0FBQ0E7QUFDSTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7OztBQUdBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0k7QUFDSDtBQUNEO0FBQ0g7QUFoR0k7Ozs7Ozs7Ozs7QUNsQ1Q7O0FBRUk7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQWJRO0FBZVo7QUFDQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIO0FBQ0Q7QUFDQTtBQUNJO0FBQ0E7QUFDSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDSTtBQUNIO0FBQ0o7QUFFRztBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBQ0o7QUFDSjtBQUNEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0k7QUFDSDtBQUNEO0FBQ0k7QUFFQTtBQUNJO0FBREo7QUFHSTtBQURKO0FBR0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFESjtBQUdIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUVHO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFFRDtBQUNJO0FBQ0k7QUFDSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7QUFDSjs7QUFySEk7Ozs7Ozs7Ozs7QUNBVDs7QUFFQTtBQUNBO0FBQ0E7O0FBRUE7Ozs7Ozs7Ozs7QUNOQTtBQUNBOztBQUVBO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWFE7O0FBY1o7QUFDQTs7QUFJQTtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQS9ESTs7Ozs7Ozs7OztBQ0hUOztBQUVBOztBQUVBOzs7Ozs7Ozs7O0FDSkE7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFYUTs7QUFjWjtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNJO0FBQ0g7QUFDSjs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIO0FBSUo7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7O0FBRUk7QUFDSDtBQWpESTs7Ozs7Ozs7OztBQ0FUOztBQUVBOztBQUVBOzs7Ozs7Ozs7O0FDSkE7O0FBRUE7QUFHQTtBQUdBO0FBQ0k7QUFDSDs7QUFFRDs7Ozs7Ozs7Ozs7Ozs7QUNaQTs7QUFFQTtBQUNBOztBQU1BO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7O0FBRUE7O0FBRUE7Ozs7Ozs7OztBQ2pCTTtBQUdOO0FBQXNDO0FBRHRDO0FBQUE7QUFTSTs7QUFNSjtBQUpJO0FBQ0k7QUFFSjtBQUNKO0FBQUE7QUFYSTtBQURDO0FBQ2U7QUFLaEI7QUFIQztBQUNHO0FBQ0g7QUFDc0I7QUFSTjtBQURwQjtBQUNvQjtBQUFBOzs7Ozs7Ozs7O0FDSHJCO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBSUE7QUFDSTtBQUNIOztBQXZCSTs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBWFE7O0FBY1o7QUFDQTs7QUFHQTtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQWhDSTs7Ozs7Ozs7OztBQ0FUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQVZROztBQWFaO0FBQ0E7O0FBakJLOzs7Ozs7Ozs7O0FDRVQ7QUFDSTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFkUTs7QUFpQlo7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUVIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7O0FBRUE7QUFDQTtBQUNIOztBQUVEO0FBQ0E7O0FBRUE7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0E7QUFDQTs7QUFFQTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBRUc7QUFDSDtBQUNEOztBQUVBO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDSDtBQUNEO0FBQ0g7O0FBRUQ7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBQ0g7QUFFRztBQUNIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSTs7QUFFQTtBQUNBO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNBO0FBQ0k7QUFDQTtBQUNBO0FBQ0k7QUFDQTtBQUNIO0FBQ0Q7QUFDSDtBQUNEO0FBQ0E7QUFDSDtBQUNEO0FBQ0g7QUFsSkk7Ozs7Ozs7Ozs7QUNGVDs7QUFHQSIsInNvdXJjZXNDb250ZW50IjpbInZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuXG5jYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuXG4gICAgICAgIHNjcm9sbFZpZXc6IHtcbiAgICAgICAgICAgIGRlZmF1bHQ6IG51bGwsXG4gICAgICAgICAgICB0eXBlOiBjYy5TY3JvbGxWaWV3XG4gICAgICAgIH0sXG5cbiAgICAgICAgXG4gICAgICAgIGRpcjogMCwgXG4gICAgICAgIGxpbmVzOiAwLCBcbiAgICAgICAgaGdhcDogMCwgXG4gICAgICAgIHZnYXA6IDAsIFxuICAgICAgICB3aWR0aDogMCwgXG4gICAgICAgIGhlaWdodDogMCxcbiAgICAgICAgXG5cbiAgICAgICAgZHA6IG51bGwsXG4gICAgICAgIGl0ZW06IGNjLlByZWZhYixcbiAgICAgICAgaXRlbVB3ZDogbnVsbCxcbiAgICAgICAgaXRlbUhlaWdodDogMCxcbiAgICAgICAgaXRlbVdpZHRoOiAwLFxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgdGhpcy51cGRhdGVUaW1lciA9IDA7XG4gICAgICAgIGRwID0gbmV3IGFycmF5MSgpO1xuICAgIH0sXG5cbiAgICBjcmVhdGU6IGZ1bmN0aW9uKGRpciwgbGluZXMsIGhnYXAsIHZnYXAsIHdpZHRoLCBoZWlnaHQpIHtcbiAgICAgICAgdGhpcy5kaXIgPSBkaXI7XG4gICAgICAgIHRoaXMubGluZXMgPSBsaW5lcztcbiAgICAgICAgdGhpcy5oZ2FwID0gaGdhcDtcbiAgICAgICAgdGhpcy52Z2FwID0gdmdhcDtcbiAgICAgICAgdGhpcy53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLmhlaWdodCA9IGhlaWdodDtcblxuXG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LndpZHRoID0gd2lkdGg7XG4gICAgICAgIHRoaXMubm9kZS5wYXJlbnQucGFyZW50LmhlaWdodCA9IGhlaWdodDtcbiAgICAgICAgdGhpcy5ub2RlLnBhcmVudC53aWR0aCA9IHdpZHRoO1xuICAgICAgICB0aGlzLm5vZGUucGFyZW50LmhlaWdodCA9IGhlaWdodDtcblxuICAgICAgICAvLyB0aGlzLm5vZGUucGFyZW50LnBhcmVudC5zZXRDb250ZW50U2l6ZShjYy5TaXplKHdpZHRoLCBoZWlnaHQpKTtcbiAgICAgICAgLy8gdGhpcy5ub2RlLnBhcmVudC5zZXRDb250ZW50U2l6ZShjYy5TaXplKHdpZHRoLCBoZWlnaHQpKTtcbiAgICAgICAgaWYoZGlyID09IGNjLnRvb2wuY29uZmlnLkRpcmVjdGlvbi5IT1JJWk9OVEFMKXtcbiAgICAgICAgICAgIHRoaXMuY2FsY1NlY3Rpb24gPSBmdW5jdGlvbihzZWxmKSB7XG4gICAgICAgICAgICAgICAgaWYoIXNlbGYuZHAgfHwgc2VsZi5kcC5zaXplKCkgPT0gMCl7XG4gICAgICAgICAgICAgICAgICAgIFxuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB2YXIgaW50ZXJ2YWwgPSBzZWxmLml0ZW1IZWlnaHQgKyBzZWxmLnZnYXA7XG4gICAgICAgICAgICB9O1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICB0aGlzLmNhbGNTZWN0aW9uID0gZnVuY3Rpb24oc2VsZikge1xuICAgICAgICAgICAgICAgIGlmKCFzZWxmLmRwIHx8IHNlbGYuZHAuc2l6ZSgpID09IDApe1xuICAgICAgICAgICAgICAgICAgICBcbiAgICAgICAgICAgICAgICB9XG4gICAgICAgICAgICAgICAgdmFyIGludGVydmFsID0gc2VsZi5pdGVtSGVpZ2h0ICsgc2VsZi52Z2FwO1xuICAgICAgICAgICAgfTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2codGhpcy53aWR0aCArIFwiIHdvY2FvIFwiICsgdGhpcy5oZWlnaHQpO1xuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcblxuICAgIH0sXG5cbiAgICBzZXRJdGVtTW9kZWw6IGZ1bmN0aW9uKGl0ZW0sIGl0ZW1XaWR0aCwgaXRlbUhlaWdodCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG5cbiAgICAgICAgdGhpcy5pdGVtUHdkID0gaXRlbTtcbiAgICAgICAgLy8gY2MubG9hZGVyLmxvYWRSZXMoaXRlbSwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgIC8vICAgICAvLyBjYy50b29sLnByZWZhYi5saXN0VmlldyA9IHByZWZhYjtcbiAgICAgICAgLy8gICAgIGNvbnNvbGUubG9nKFwidHlwZSBwcmVmYWIgPSBcIiArIHR5cGVvZiBwcmVmYWIpXG4gICAgICAgIC8vICAgICBzZWxmLml0ZW0gPSBwcmVmYWI7XG4gICAgICAgIC8vIH0pO1xuICAgICAgICBjYy5sb2FkZXIubG9hZFJlcyhpdGVtLCBjYy5QcmVmYWIpO1xuICAgICAgICBzZWxmLml0ZW1XaWR0aCA9IGl0ZW1XaWR0aDtcbiAgICAgICAgc2VsZi5pdGVtSGVpZ2h0ID0gaXRlbUhlaWdodDtcbiAgICB9LFxuXG4gICAgc2V0RGF0YVByb3ZpZGVyOiBmdW5jdGlvbihkbCkge1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG5cbiAgICAgICAgaWYodGhpcy5kaXIgPT0gY2MudG9vbC5jb25maWcuRGlyZWN0aW9uLkhPUklaT05UQUwpe1xuICAgICAgICAgICAgdGhpcy5ub2RlLmhlaWdodCA9IGRsLmdldFNpemUoKSAqICh0aGlzLml0ZW1IZWlnaHQgKyB0aGlzLmhnYXApIC0gdGhpcy5oZ2FwO1xuICAgICAgICAgICAgdGhpcy5ub2RlLndpZHRoID0gdGhpcy53aWR0aDtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgdGhpcy5ub2RlLmhlaWdodCA9IHRoaXMuaGVpZ2h0O1xuICAgICAgICB9ICAgIFxuXG4gICAgICAgIGRsLmV4Y3V0ZVdpdGhGdW5jKGZ1bmN0aW9uKGRhdGEsIGluZGV4KXtcbiAgICAgICAgICAgIHZhciBwcmVmYWIgPSBjYy5sb2FkZXIuZ2V0UmVzKHNlbGYuaXRlbVB3ZCwgY2MuUHJlZmFiKTtcblxuICAgICAgICAgICAgbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vIGl0ZW0uc2V0UG9zWSgtdGhpcy5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgaXRlbS5zZXRQb3MoMCwgLXNlbGYuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuXG4gICAgICAgICAgICAvLyBjYy5sb2FkZXIuZ2V0UmVzKHNlbGYuaXRlbVB3ZCwgY2MuUHJlZmFiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgICAgICAvLyAgICAgbGV0IGl0ZW0gPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpLmdldENvbXBvbmVudCgnUmVuZGVyZXInKTtcbiAgICAgICAgICAgIC8vICAgICAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vICAgICBpdGVtLnNldFBvcygwLCAtc2VsZi5pdGVtSGVpZ2h0ICogKGluZGV4ICsgMSkpO1xuICAgICAgICAgICAgLy8gICAgIHNlbGYubm9kZS5hZGRDaGlsZChpdGVtLm5vZGUpO1xuICAgICAgICAgICAgLy8gfSk7XG5cbiAgICAgICAgICAgIC8vIGxldCBpdGVtID0gY2MuaW5zdGFudGlhdGUoc2VsZi5pdGVtKS5nZXRDb21wb25lbnQoJ1JlbmRlcmVyJyk7XG4gICAgICAgICAgICAvLyAvLyBpdGVtLnNldFBvc1koLXRoaXMuaXRlbUhlaWdodCAqIChpbmRleCArIDEpKTtcbiAgICAgICAgICAgIC8vIGl0ZW0uc2V0UG9zKDAsIC1zZWxmLml0ZW1IZWlnaHQgKiAoaW5kZXggKyAxKSk7XG4gICAgICAgICAgICAvLyBzZWxmLm5vZGUuYWRkQ2hpbGQoaXRlbS5ub2RlKTtcbiAgICAgICAgfSk7XG4gICAgfSxcblxuICAgIHVwZGF0ZSAoZHQpIHtcbiAgICAgICAgdGhpcy51cGRhdGVUaW1lciArPSBkdDtcbiAgICAgICAgaWYodGhpcy51cGRhdGVUaW1lciA8IHRoaXMudXBkYXRlSW50ZXJ2YWwpIHJldHVybjtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgc2V0UG9zWTogZnVuY3Rpb24oeSkge1xuICAgICAgICB0aGlzLm5vZGUueSA9IHk7XG4gICAgfSxcblxuICAgIHNldFBvczogZnVuY3Rpb24oeCwgeSkge1xuICAgICAgICB0aGlzLm5vZGUueCA9IHg7XG4gICAgICAgIHRoaXMubm9kZS55ID0geTtcbiAgICB9XG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJmdW5jdGlvbiBpbml0KCl7XG4gICAgY2MudG9vbCA9IHt9XG4gICAgdmFyIHZpZXdNYW5hZ2VyID0gcmVxdWlyZShcInZpZXdNYW5hZ2VyXCIpO1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIgPSBuZXcgdmlld01hbmFnZXIoKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyLmluaXQoKTtcblxuXG4gICAgcmVxdWlyZShcInZpZXdSZWdpc3RlclwiKTtcbiAgICB2aWV3UmVnaXN0ZXIoKTtcblxuICAgIHZhciB0aW1lSGFuZGxlciA9IHJlcXVpcmUoXCJ0aW1lSGFuZGxlclwiKTtcbiAgICBjYy50b29sLnRpbWVIYW5kbGVyID0gbmV3IHRpbWVIYW5kbGVyKCk7XG5cbiAgICB2YXIgZXZlbnRNYW5hZ2VyID0gcmVxdWlyZShcImV2ZW50TWFuYWdlclwiKTtcbiAgICBjYy50b29sLmV2ZW50TWFuYWdlciA9IG5ldyBldmVudE1hbmFnZXIoKTtcblxuICAgIGNjLnRvb2wuZ2FtZVZhcmlhYmxlID0gcmVxdWlyZShcImdhbWVWYXJpYWJsZVwiKTtcbiAgICBjYy50b29sLkxhbmcgPSByZXF1aXJlKFwibGFuZ1poXCIpO1xuXG4gICAgY2MudG9vbC5wcmVmYWIgPSB7fTtcbiAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJoYWhhaGFcIiwgXCJoZWhlaGVcIiwgXCJoaWhpaGlcIik7XG5cbiAgICBjYy50b29sLmNvbmZpZyA9IHJlcXVpcmUoXCJjb25maWdcIik7XG5cbiAgICBjYy50b29sLnByb3RvY29sSW5pdCA9IHJlcXVpcmUoXCJwcm90b2NvbEluaXRcIik7XG4gICAgY2MudG9vbC5wcm90b2NvbEhhbmRsZXIgPSByZXF1aXJlKFwicHJvdG9jb2xIYW5kbGVyXCIpO1xuICAgIGNvbnNvbGUubG9nKFwiYXJyYXkncyBsZW5ndGggPSBcIiArIGNjLnRvb2wucHJvdG9jb2xJbml0LnRtUmVzLmxlbmd0aCk7XG59XG5cbmZ1bmN0aW9uIHZpZXdSZWdpc3Rlcigpe1xuICAgIGNjLnRvb2wudmlld01hbmFnZXIucmVnaXN0VmlldyhcImttVmlld1wiLCBcInVpL2ttVmlld1wiLCAyKTtcbiAgICBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJraWxpZTVWaWV3XCIsIFwidWkva2lsaWU1Vmlld1wiLCAyKTtcbn1cblxuY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICAgICAgaGFoYTogW10sXG4gICAgICAgIGNvdW50OiAwLFxuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgaW5pdCgpO1xuXG4gICAgICAgIC8vIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgLy8gY2MubG9hZGVyLmxvYWRSZXMoXCJjb250cm9sL0xpc3RWaWV3XCIsIGNjLlByZWZhYiwgZnVuY3Rpb24oZXJyLCBwcmVmYWIpe1xuICAgICAgICAvLyAgICAgLy8gY2MudG9vbC5wcmVmYWIubGlzdFZpZXcgPSBwcmVmYWI7XG4gICAgICAgIC8vICAgICBjb25zb2xlLmxvZyhcInR5cGUgcHJlZmFiID0gXCIgKyB0eXBlb2YgcHJlZmFiKVxuXG4gICAgICAgIC8vICAgICB2YXIgcm9vdCA9IGNjLmluc3RhbnRpYXRlKHByZWZhYik7XG4gICAgICAgIC8vICAgICByb290LnNldFBvc2l0aW9uKGNjLnYyKDAsIDApKTtcbiAgICAgICAgLy8gICAgIGxldCBsaXN0VmlldyA9IHJvb3QuZ2V0Q2hpbGRCeU5hbWUoXCJ2aWV3XCIpLmdldENoaWxkQnlOYW1lKFwiY29udGVudFwiKS5nZXRDb21wb25lbnQoXCJMaXN0Vmlld1wiKTtcbiAgICAgICAgLy8gICAgIGxpc3RWaWV3LmNyZWF0ZShjYy50b29sLmNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCwgMSwgMSwgMSwgMjQwLCAxNTApO1xuICAgICAgICAvLyAgICAgbGlzdFZpZXcuc2V0SXRlbU1vZGVsKFwiY29udHJvbC9SZW5kZXJlclwiLCAxNjAsIDYwKTtcblxuICAgICAgICAvLyAgICAgdmFyIGFycmF5ID0gcmVxdWlyZShcImFycmF5MVwiKTtcbiAgICAgICAgLy8gICAgIHZhciB0ZXN0ID0gbmV3IGFycmF5KCk7XG4gICAgICAgIC8vICAgICBmb3IoaSA9IDA7IGkgPCA1OyBpKyspe1xuICAgICAgICAvLyAgICAgICAgIHRlc3QucHVzaEJhY2soaSArIDEwMClcbiAgICAgICAgLy8gICAgIH1cblxuICAgICAgICAvLyAgICAgbGlzdFZpZXcuc2V0RGF0YVByb3ZpZGVyKHRlc3QpO1xuXG5cbiAgICAgICAgLy8gICAgIHNlbGYubm9kZS5hZGRDaGlsZChyb290KTtcbiAgICAgICAgLy8gfSk7XG5cbiAgICAgICAgLy/mmoLml7bkuI3nlKjlrprml7blmahcbiAgICAgICAgLy8gdGhpcy5zY2hlZHVsZShmdW5jdGlvbigpe1xuICAgICAgICAvLyAgICAgdGhpcy51cGRhdGVUaW1lKCk7XG4gICAgICAgIC8vIH0sIDEpO1xuXG4gICAgICAgIHRoaXMudGVzdEZ1bmMoKTtcbiAgICB9LFxuXG4gICAgdXBkYXRlVGltZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwidGhpcy5jb3VudCA9IFwiICsgdGhpcy5jb3VudCk7XG4gICAgICAgIHRoaXMuY291bnQgPSB0aGlzLmNvdW50ICsgMTtcbiAgICAgICAgLy8gY2MudG9vbC5ldmVudE1hbmFnZXIuVkFSX0NIQU5HRShcInNlYzFcIik7XG4gICAgICAgIGNjLnRvb2wuZ2FtZVZhcmlhYmxlLnNlYyA9IGNjLnRvb2wuZ2FtZVZhcmlhYmxlLnNlYyArIDE7XG4gICAgfSxcblxuICAgIHRlc3RGdW5jOiBmdW5jdGlvbigpIHtcbiAgICAgICAgdmFyIHN0cjEgPSBcImhlbGxvd29yZFwiO1xuICAgICAgICB0aGlzLmhlbGxvd29yZCA9IGZ1bmN0aW9uKCl7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIndvdGVmdW5ja1wiKTtcbiAgICAgICAgfVxuICAgICAgICB0aGlzW3N0cjFdKCk7XG4gICAgfSxcblxuICAgIGluaXRTY2VuZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIuc2V0Um9vdCh0aGlzLm5vZGUpO1xuICAgICAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLmNoYW5nZVZpZXcoXCJoYWhoYWhhaGFhXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyhcInRlc3QgdHlwZVwiICsgdHlwZW9mIHRoaXMuaGFoYVtcIndvY2FvXCJdKTtcbiAgICB9LFxuXG4gICAgdGVzdFJlbW92ZTogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImttVmlld1wiKTtcbiAgICB9LFxuXG4gICAgYnRuQmFjazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNjLnRvb2wudmlld01hbmFnZXIuYmFja1ByZXZpZXcoKTtcbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcblxuICAgIGNvbm5lY3RUZXN0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b3JrIGNvbm5lY3RcIik7XG4gICAgICAgIHZhciBzb2NrZXQgPSBpby5jb25uZWN0KCcxMC4xMC4zMC4yMzQ6MTIzNDUnLCBmdW5jdGlvbihtc2cpe1xuICAgICAgICAgICAgY29uc29sZS5sb2cobXNnKTtcbiAgICAgICAgfSk7XG4gICAgICAgIGZvcih2YXIgaSA9IDA7IGkgPCBjYy50b29sLnByb3RvY29sSW5pdC50bVJlcy5sZW5ndGg7IGkrKyl7XG4gICAgICAgICAgICBzb2NrZXQub24oY2MudG9vbC5wcm90b2NvbEluaXQudG1SZXNbaV0sIGNjLnRvb2wucHJvdG9jb2xIYW5kbGVyW2NjLnRvb2wucHJvdG9jb2xJbml0LnRtUmVzW2ldXSk7XG4gICAgICAgIH1cbiAgICAgICAgc29ja2V0LmVtaXQoJ2hlaGVoYWhhJywge2FiYzpcIndvemhlbmRlcmlsZWdvdWxlXCJ9KTtcbiAgICB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgICAgIGxpc3Q6IFtdLFxuICAgICAgICBzaXplOiAwLFxuICAgICAgICBucG9zOiAtMSxcbiAgICB9LFxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvcmtlZFwiKTtcbiAgICB9LFxuXG4gICAgYXNmZGZzZGY6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy5saXN0KTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcbiAgICB9LFxuXG4gICAgc3RhdHVzOiBmdW5jdGlvbigpIHtcbiAgICAgICAgY29uc29sZS5sb2coXCJzZWxmLnNpemUxXCIpO1xuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLnNpemUpO1xuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTJcIik7XG4gICAgfSxcbiAgICAvL1xuICAgIHB1c2hCYWNrOiBmdW5jdGlvbihkYXRhKSB7XG4gICAgICAgIHRoaXMubGlzdFt0aGlzLnNpemVdID0gZGF0YTtcbiAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplICsgMTtcbiAgICB9LFxuXG4gICAgYXQ6IGZ1bmN0aW9uKGlkeCl7XG4gICAgICAgIHJldHVybiB0aGlzLmxpc3RbaWR4XTtcbiAgICB9LFxuXG4gICAgZmluZDogZnVuY3Rpb24odmFsdWUpe1xuICAgICAgICB2YXIgaW5kZXggPSB0aGlzLm5wb3M7XG4gICAgICAgIGlmICh0eXBlb2YgdmFsdWUgPT0gXCJmdW5jdGlvblwiKXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih2YWx1ZShpKSkgcmV0dXJuIGk7XG4gICAgICAgICAgICB9XG4gICAgICAgIH1cbiAgICAgICAgZWxzZXtcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcbiAgICAgICAgICAgICAgICBpZih0aGlzLmxpc3RbaV0gPT0gdmFsdWUpe1xuICAgICAgICAgICAgICAgICAgICBpbmRleCA9IGk7XG4gICAgICAgICAgICAgICAgICAgIGJyZWFrO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgIH1cbiAgICAgICAgfVxuICAgICAgICByZXR1cm4gaW5kZXg7XG4gICAgfSxcblxuICAgIHJlbW92ZTogZnVuY3Rpb24ocG9zLCBsZW4pe1xuICAgICAgICBpZihwb3MgPCAwKSBwb3MgPSAwO1xuICAgICAgICBpZihsZW4gPT0gbnVsbCB8fCBsZW4gPD0gMCl7XG4gICAgICAgICAgICBsZW4gPSAxO1xuICAgICAgICB9XG4gICAgICAgIGlmKHBvcyA8IHRoaXMuc2l6ZSl7XG4gICAgICAgICAgICBpZihwb3MgKyBsZW4gPiB0aGlzLnNpemUpXG4gICAgICAgICAgICAgICAgbGVuID0gdGhpcy5zaXplIC0gcG9zO1xuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgbGVuOyBpKyspXG4gICAgICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtwb3MgKyBpXTtcbiAgICAgICAgICAgIGZvcihpID0gcG9zICsgbGVuOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICAgICAgdGhpcy5saXN0W2kgLSBsZW5dID0gdGhpcy5saXN0W2ldO1xuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gbGVuO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGNsZWFyOiBmdW5jdGlvbigpe1xuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbaV07XG4gICAgICAgIHRoaXMuc2l6ZSA9IDA7XG4gICAgfSxcblxuICAgIGdldFNpemU6IGZ1bmN0aW9uKCkge1xuICAgICAgICByZXR1cm4gdGhpcy5zaXplO1xuICAgIH0sXG5cbiAgICBiYWNrOiBmdW5jdGlvbigpIHtcbiAgICAgICAgaWYodGhpcy5zaXplID4gMCl7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy5saXN0W3RoaXMuc2l6ZSAtIDFdO1xuICAgICAgICB9XG4gICAgICAgIGVsc2V7XG4gICAgICAgICAgICByZXR1cm4gbnVsbDtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBlbXB0eTogZnVuY3Rpb24oKSB7XG4gICAgICAgIHJldHVybiB0aGlzLnNpemUgPT0gMDtcbiAgICB9LFxuXG4gICAgb3V0UHV0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnRcIiArIGkgKyBcIiA9IFwiICsgdGhpcy5saXN0W2ldKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50IHNpemUgPSBcIiArIHRoaXMuc2l6ZSk7XG4gICAgfSxcblxuICAgIGV4Y3V0ZVdpdGhGdW5jOiBmdW5jdGlvbihmdW5jKSB7XG4gICAgICAgIGZvcih2YXIgaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKyl7XG4gICAgICAgICAgICBmdW5jKHRoaXMubGlzdFtpXSwgaSk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgcG9wQmFjazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGlmKHRoaXMuc2l6ZSA+IDApe1xuICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFt0aGlzLnNpemUgLSAxXTtcbiAgICAgICAgICAgIHRoaXMuc2l6ZSA9IHRoaXMuc2l6ZSAtIDE7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xuXG4gICAgLy8gfSxcbn0pO1xuIiwidmFyIENvbmZpZyA9IHt9O1xuXG5Db25maWcuRGlyZWN0aW9uID0ge307XG5Db25maWcuRGlyZWN0aW9uLlZFUlRJQ0FMID0gMDtcbkNvbmZpZy5EaXJlY3Rpb24uSE9SSVpPTlRBTCA9IDE7XG5cbm1vZHVsZS5leHBvcnRzID0gQ29uZmlnOyIsInZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpXG52YXIgdGVzdCA9IHJlcXVpcmUoXCJ0ZXN0XCIpXG5cbmNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiB0ZXN0LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBldmVudExpc3RlbmVyOiBbXSxcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgICAgIFxuICAgIH0sXG5cbiAgICBpbml0OiBmdW5jdGlvbigpIHtcbiAgICAgICAgdGhpcy5zdXBlci50ZXN0V29yaygpO1xuICAgIH0sXG5cbiAgICB0ZXN0V29yazogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiemVubWUgaHVpIHpoZXlhbmdcIik7XG4gICAgfSxcblxuICAgIGFkZEV2ZW50TGlzdGVuZXI6IGZ1bmN0aW9uKGV2ZW50VHlwZSwgdGFyZ2V0LCBmdW5jKSB7XG4gICAgICAgIHRhcmdldC5vdXRwdXQoKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2coKVxuICAgICAgICBpZighdGFyZ2V0IHx8ICFmdW5jKSByZXR1cm47XG4gICAgICAgIGlmKCF0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSl7XG4gICAgICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXSA9IG5ldyBhcnJheTEoKTtcbiAgICAgICAgfVxuICAgICAgICB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXS5wdXNoQmFjayh7dGFyZ2V0OnRhcmdldCwgZnVuYzpmdW5jfSk7XG4gICAgfSxcblxuICAgIHRlc3RXb3JrTGlzdGVuZXI6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRlc3QgbGlzdGVuZXJcIik7XG4gICAgICAgIGZvcih2YXIga2V5IGluIHRoaXMuZXZlbnRMaXN0ZW5lcltcImhhaGFoYVwiXSl7XG4gICAgICAgICAgICB2YXIgZnVuYyA9IHRoaXMuZXZlbnRMaXN0ZW5lcltcImhhaGFoYVwiXVtrZXldO1xuICAgICAgICAgICAgZnVuYyhcImhhaGFoYVwiKTtcbiAgICAgICAgfVxuICAgIH0sXG5cbiAgICBkaXNwYXRjaEV2ZW50TGlzdGVuZXI6IGZ1bmN0aW9uKGV2ZW50VHlwZSkge1xuICAgICAgICBjb25zb2xlLmxvZyhcImV2ZW50VHlwZVwiKTtcbiAgICAgICAgdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0uZXhjdXRlV2l0aEZ1bmMoZnVuY3Rpb24oaXRlbSwgaW5kZXgpe1xuICAgICAgICAgICAgdmFyIGZ1bmMgPSBpdGVtLmZ1bmM7XG4gICAgICAgICAgICB2YXIgdGFyZ2V0ID0gaXRlbS50YXJnZXQ7XG4gICAgICAgICAgICBmdW5jKHRhcmdldCwgZXZlbnRUeXBlKTtcbiAgICAgICAgfSlcbiAgICAgICAgLy8gZm9yKHZhciBrZXkgaW4gdGhpcy5ldmVudExpc3RlbmVyW2V2ZW50VHlwZV0pe1xuICAgICAgICAvLyAgICAgdmFyIGZ1bmMgPSB0aGlzLmV2ZW50TGlzdGVuZXJbZXZlbnRUeXBlXVtrZXldO1xuICAgICAgICAvLyAgICAgZnVuYyhrZXksIGV2ZW50VHlwZSk7XG4gICAgICAgIC8vIH1cbiAgICB9LFxuXG4gICAgVkFSX0NIQU5HRTogZnVuY3Rpb24odmFyTmFtZSl7XG4gICAgICAgIHRoaXMuZGlzcGF0Y2hFdmVudExpc3RlbmVyKHZhck5hbWUpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJ2YXIgZ2FtZVZhciA9IFtdO1xuXG5nYW1lVmFyLnNlYyA9IDA7XG5cbm1vZHVsZS5leHBvcnRzID0gZ2FtZVZhcjsiLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBldmVudFR5cGU6IG51bGwsXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuICAgICAgICB0aGlzLmV2ZW50VHlwZSA9IG5ldyBBcnJheShcInNlYzFcIiwgXCJzZWMyXCIsIFwic2VjM1wiKTtcbiAgICAgICAgXG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgZm9yKHZhciBpID0gMDsgaSA8IHRoaXMuZXZlbnRUeXBlLmxlbmd0aDsgaSsrKXtcbiAgICAgICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLmFkZEV2ZW50TGlzdGVuZXIoc2VsZi5ldmVudFR5cGVbaV0sIHNlbGYsIHNlbGYub25WYXJDYWxsYmFjayk7XG4gICAgICAgIH1cbiAgICB9LFxuXG4gICAgb25WYXJDYWxsYmFjazogZnVuY3Rpb24oc2VsZiwgdmFyTmFtZSkge1xuICAgICAgICBpZih2YXJOYW1lID09IFwic2VjMVwiKXtcbiAgICAgICAgICAgIC8vc2VsZi5vdXRwdXQoKTtcbiAgICAgICAgICAgIHNlbGYubm9kZS5nZXRDaGlsZEJ5TmFtZShcInR4dGhhaGFcIikuZ2V0Q29tcG9uZW50KGNjLkxhYmVsKS5zdHJpbmcgPSBcInNlYyA9IFwiICsgY2MudG9vbC5nYW1lVmFyaWFibGUuc2VjO1xuICAgICAgICB9XG4gICAgICAgIGVsc2UgaWYodmFyTmFtZSA9PSBcIlwiKXtcblxuICAgICAgICB9XG4gICAgfSxcblxuICAgIG91dHB1dDogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3byBjYW8gbmkgbWEgZ2UgY2hvdSBoYWlcIik7XG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG5cbiAgICBidG5UZWFtOiBmdW5jdGlvbigpIHtcbiAgICAgICAgXG4gICAgICAgIC8vIGNjLnRvb2wudmlld01hbmFnZXIuY2hhbmdlVmlldyhcImtpbGllNVZpZXdcIik7XG4gICAgfSxcbn0pO1xuIiwidmFyIExhbmcgPSBbXTtcblxuTGFuZ1tcIklURU1fVkFMVUVcIl0gPSBcIuWPmOaIkOS4reaWh+eahOaDheWGtVwiO1xuXG5tb2R1bGUuZXhwb3J0cyA9IExhbmc7IiwidmFyIF8gPSBbXTtcblxuXy5tc2dfYnV5X3JlcyA9IGZ1bmN0aW9uKHJlcyl7XG5cbn1cbl8ubXNnX2xvZ2luX3JlcyA9IGZ1bmN0aW9uKHJlcyl7XG5cbn1cbl8ubXNnX3B2cF9yZXMgPSBmdW5jdGlvbihyZXMpe1xuICAgIGNvbnNvbGUubG9nKFwicmVzJ3MgdGV4dCA9IFwiICsgcmVzLnRleHQpO1xufVxuXG5tb2R1bGUuZXhwb3J0cyA9IF87IiwidmFyIHByb3RvY29sID0gW107XG5cbnByb3RvY29sLnRtUmVxID0gW107XG5wcm90b2NvbC50bVJlcSA9IHtcbiAgICBbMF06XCJtc2dfYnV5X3JlcVwiLFxuICAgIFsxXTpcIm1zZ19sb2dpbl9yZXFcIixcbiAgICBbMl06XCJtc2dfbG9naW5fcmVxXCIsXG59O1xuXG5wcm90b2NvbC50bVJlcyA9IFtdO1xudmFyIHRtUmVzID0gcHJvdG9jb2wudG1SZXM7XG50bVJlc1swXSA9IFwibXNnX2J1eV9yZXNcIjtcbnRtUmVzWzFdID0gXCJtc2dfbG9naW5fcmVzXCI7XG50bVJlc1syXSA9IFwibXNnX3B2cF9yZXNcIjtcblxuY29uc29sZS5sb2coXCJsZW5ndGggXCIgKyBwcm90b2NvbC50bVJlcy5sZW5ndGgpO1xuXG5tb2R1bGUuZXhwb3J0cyA9IHByb3RvY29sOyIsImNvbnN0IHtjY2NsYXNzLCBwcm9wZXJ0eX0gPSBjYy5fZGVjb3JhdG9yO1xuXG5AY2NjbGFzc1xuZXhwb3J0IGRlZmF1bHQgY2xhc3MgTmV3Q2xhc3MgZXh0ZW5kcyBjYy5Db21wb25lbnQge1xuXG4gICAgQHByb3BlcnR5KGNjLkxhYmVsKVxuICAgIGxhYmVsOiBjYy5MYWJlbDtcblxuICAgIEBwcm9wZXJ0eSh7XG4gICAgICAgIGRlZmF1bHQ6ICdoZWxsbydcbiAgICB9KVxuICAgIHRleHQ6IHN0cmluZyA9ICdoZWxsbyc7XG5cbiAgICBvbkxvYWQoKSB7XG4gICAgICAgIC8vIGluaXQgbG9naWNcbiAgICAgICAgXG4gICAgfVxufVxuIiwiY2MuQ2xhc3Moe1xuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcblxuICAgIHByb3BlcnRpZXM6IHtcbiAgICAgICAgLy8gZm9vOiB7XG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxuICAgICAgICAvLyB9LFxuICAgICAgICAvLyAuLi5cbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG5cbiAgICB9LFxuXG4gICAgdGVzdFdvcms6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gbmltYWJpXCIpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxufSk7XG4iLCJjYy5DbGFzcyh7XG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxuXG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICBjb3VudDogMCxcbiAgICB9LFxuXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXG4gICAgb25Mb2FkOiBmdW5jdGlvbiAoKSB7XG4gICAgfSxcblxuICAgIGN0b3I6IGZ1bmN0aW9uKCkge1xuICAgICAgICBjb25zb2xlLmxvZyhcInplbm0gZWh1aXpoZXlhbmdcIik7XG4gICAgICAgIHRoaXMuc2NoZWR1bGUoZnVuY3Rpb24oKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiaGFoYWhhaGFoaGFcIik7XG4gICAgICAgIH0sIDEpO1xuICAgIH0sXG5cbiAgICBkb3NvbWV0aGluZzogZnVuY3Rpb24oKXtcbiAgICAgICAgY29uc29sZS5sb2coXCJkc2dmc2RhZ3ZkZ2FcIik7XG4gICAgICAgIC8vIGNvbnNvbGUubG9nKFwidGhpcy5jb3VudCA9IFwiICsgdGhpcy5jb3VudCk7XG4gICAgICAgIC8vIHRoaXMuY291bnQgPSB0aGlzLmNvdW50ICsgMTtcbiAgICB9LFxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsImNjLkNsYXNzKHtcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXG5cbiAgICBwcm9wZXJ0aWVzOiB7XG4gICAgICAgIC8vIGZvbzoge1xuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcbiAgICAgICAgLy8gfSxcbiAgICAgICAgLy8gLi4uXG4gICAgfSxcblxuICAgIC8vIHVzZSB0aGlzIGZvciBpbml0aWFsaXphdGlvblxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xuXG4gICAgfSxcblxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcblxuICAgIC8vIH0sXG59KTtcbiIsIlxuXG5jYy5DbGFzcyh7XG4gICAgcHJvcGVydGllczoge1xuICAgICAgICAvLyBmb286IHtcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXG4gICAgICAgIC8vIH0sXG4gICAgICAgIC8vIC4uLlxuICAgICAgICB2aWV3TGlzdDogbnVsbCxcbiAgICAgICAgdmlld0luZm86IFtdLFxuICAgICAgICB2aWV3OiBudWxsLFxuICAgICAgICB2aWV3TmFtZTogbnVsbCxcbiAgICB9LFxuXG4gICAgY3RvcjogZnVuY3Rpb24oKSB7XG4gICAgICAgIGNvbnNvbGUubG9nKFwiaGhoZWhlaGVcIik7XG4gICAgICAgIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0ID0gbmV3IGFycmF5MSgpO1xuICAgICAgICAvLyB0aGlzLmFycmF5MSA9IG5ldyByZXF1aXJlKFwiYXJyYXkxXCIpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnN0YXR1cygpO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnB1c2hCYWNrKHthOjEsIGI6Mn0pO1xuICAgICAgICB0aGlzLnZpZXdMaXN0LnN0YXR1cygpO1xuICAgICAgICBcbiAgICB9LFxuXG4gICAgc2V0Um9vdDogZnVuY3Rpb24obm9kZSkge1xuICAgICAgICB0aGlzLnJvb3QgPSBub2RlO1xuICAgIH0sXG5cbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcbiAgICAgICAgLy8gY29uc29sZS5sb2coXCJoYWhhaGFoaGFcIik7XG5cbiAgICAgICAgLy8gY2MudmFyaWFibGUudmlld0luZm8uYXNmZGZzZGYoKTtcbiAgICAgICAgLy8gY29uc29sZS5sb2codHlwZW9mIHRoaXMudmlld05hbWUpO1xuICAgIH0sXG5cbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XG5cbiAgICAvLyB9LFxuXG4gICAgaW5pdDogZnVuY3Rpb24oKXtcbiAgICAgICAgdGhpcy52aWV3SW5mbyA9IFtdO1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMVwiKTtcbiAgICAgICAgdGhpcy52aWV3SW5mb1tcImhhaGFcIl0gPSB7YToxLCBiOjJ9O1xuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMlwiKTtcbiAgICB9LFxuXG4gICAgcmVnaXN0VmlldzogZnVuY3Rpb24odmlld05hbWUsIG1vZHVsZSwgdGl0bGUpe1xuICAgICAgICB0aGlzLnZpZXdJbmZvW3ZpZXdOYW1lXSA9IHt2aWV3TmFtZTp2aWV3TmFtZSwgbW9kdWxlOm1vZHVsZSwgdGl0bGU6dGl0bGV9O1xuICAgIH0sXG5cbiAgICBjaGFuZ2VWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSl7XG4gICAgICAgIGlmKCF0aGlzLnZpZXdMaXN0LmVtcHR5KCkgJiYgdGhpcy52aWV3TGlzdC5iYWNrKCkgPT0gdmlld05hbWUpe1xuICAgICAgICAgICAgY29uc29sZS5sb2coXCJ2aWV3IGlzIHNhbWVcIik7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgICAgICB9XG5cbiAgICAgICAgdmFyIHZpZXdBYm91dCA9IHRoaXMudmlld0luZm9bdmlld05hbWVdXG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW8gMVwiKTtcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyAyXCIpO1xuXG4gICAgICAgIHZhciBpZHggPSB0aGlzLnZpZXdMaXN0LmZpbmQodmlld05hbWUpO1xuICAgICAgICBpZihpZHggIT0gdGhpcy52aWV3TGlzdC5ucG9zKXtcbiAgICAgICAgICAgIHZhciBsZW4gPSB0aGlzLnZpZXdMaXN0LmdldFNpemUoKSAtIGlkeDtcbiAgICAgICAgICAgIHRoaXMudmlld0xpc3QucmVtb3ZlKGlkeCwgbGVuKTtcbiAgICAgICAgfVxuICAgICAgICBlbHNle1xuICAgICAgICAgICAgdGhpcy52aWV3TGlzdC5wdXNoQmFjayh2aWV3TmFtZSk7XG4gICAgICAgIH1cbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2NhbyAzXCIpO1xuXG4gICAgICAgIHZhciBzZWxmID0gdGhpcztcbiAgICAgICAgLy/pgJrov4fpk77mjqUg5Yqg6L2955qE6LWE5rqQIOW/hemhu+aUvuWcqHJlc291cmNl5LiLXG4gICAgICAgIGNjLmxvYWRlci5sb2FkUmVzKHZpZXdBYm91dC5tb2R1bGUsIGZ1bmN0aW9uKGVyciwgcHJlZmFiKXtcbiAgICAgICAgICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcbiAgICAgICAgICAgIGNjLmRpcmVjdG9yLmdldFNjZW5lKCkuZ2V0Q2hpbGRCeU5hbWUoXCJDYW52YXNcIikuYWRkQ2hpbGQocm9vdCk7XG4gICAgICAgICAgICBpZihzZWxmLnZpZXcgIT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgc2VsZi52aWV3LnJlbW92ZUZyb21QYXJlbnQoKTtcbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcgPSBudWxsO1xuICAgICAgICAgICAgfVxuICAgICAgICAgICAgc2VsZi52aWV3ID0gcm9vdDtcbiAgICAgICAgfSk7XG4gICAgICAgIFxuICAgICAgICB0aGlzLnZpZXdOYW1lID0gdmlld05hbWU7XG4gICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgfSxcblxuICAgIGN1clZpZXc6IGZ1bmN0aW9uKCkge1xuICAgICAgICAvLyB0aGlzLnRlc3RBZGRDaGlsZCgpO1xuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgIGNjLnRvb2wuZXZlbnRNYW5hZ2VyLmFkZEV2ZW50TGlzdGVuZXIoXCJoYWhhaGFcIiwgc2VsZiwgc2VsZi50ZXN0QWRkQ2hpbGQpO1xuICAgICAgICBjYy50b29sLmV2ZW50TWFuYWdlci50ZXN0V29ya0xpc3RlbmVyKClcbiAgICAgICAgdGhpcy52aWV3LnJlbW92ZUZyb21QYXJlbnQoZmFsc2UpO1xuICAgICAgICBjYy5sb2FkZXIucmVsZWFzZVJlcyhcInByZWZhYi9UZXN0MVBhbmVsXCIpO1xuXG4gICAgICAgIHJldHVybiB0aGlzLnZpZXc7XG4gICAgfSxcblxuICAgIHRlc3RBZGRDaGlsZDogZnVuY3Rpb24odmFyTmFtZSl7XG4gICAgICAgIGlmKHZhck5hbWUgPT0gXCJoYWhhaGFcIil7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvIHRhbWFiaVwiKTtcbiAgICAgICAgfVxuICAgICAgICBlbHNlIGlmKHZhck5hbWUgPSBcIndvY2FvbmltYVwiKXtcbiAgICAgICAgICAgIGNvbnNvbGUubG9nKFwiPz8/IHdvZGV0aWFuXCIpO1xuICAgICAgICB9XG4gICAgfSxcblxuICAgIGN1clZpZXdOYW1lOiBmdW5jdGlvbigpe1xuICAgICAgICByZXR1cm4gdGhpcy52aWV3TmFtZTtcbiAgICB9LFxuXG4gICAgYmFja1ByZXZpZXc6IGZ1bmN0aW9uKCl7XG4gICAgICAgIGlmKHRoaXMudmlld0xpc3QuZ2V0U2l6ZSgpID4gMCl7XG4gICAgICAgICAgICB0aGlzLnZpZXdMaXN0LnBvcEJhY2soKTtcblxuICAgICAgICAgICAgdmFyIHZpZXdOYW1lID0gdGhpcy52aWV3TGlzdC5iYWNrKCk7XG4gICAgICAgICAgICB2YXIgdmlld0Fib3V0ID0gdGhpcy52aWV3SW5mb1t2aWV3TmFtZV07XG4gICAgICAgICAgICBpZih2aWV3QWJvdXQgPT0gbnVsbCl7XG4gICAgICAgICAgICAgICAgaWYodGhpcy52aWV3ICE9IG51bGwpe1xuICAgICAgICAgICAgICAgICAgICB0aGlzLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICB0aGlzLnZpZXdOYW1lID0gbnVsbDtcbiAgICAgICAgICAgICAgICB0aGlzLnZpZXcgPSBudWxsO1xuICAgICAgICAgICAgICAgIHJldHVybiBudWxsO1xuICAgICAgICAgICAgfVxuXG4gICAgICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XG4gICAgICAgICAgICBjYy5sb2FkZXIubG9hZFJlcyh2aWV3QWJvdXQubW9kdWxlLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XG4gICAgICAgICAgICAgICAgdmFyIHJvb3QgPSBjYy5pbnN0YW50aWF0ZShwcmVmYWIpO1xuICAgICAgICAgICAgICAgIGNjLmRpcmVjdG9yLmdldFNjZW5lKCkuZ2V0Q2hpbGRCeU5hbWUoXCJDYW52YXNcIikuYWRkQ2hpbGQocm9vdCk7XG4gICAgICAgICAgICAgICAgaWYoc2VsZi52aWV3ICE9IG51bGwpe1xuICAgICAgICAgICAgICAgICAgICBzZWxmLnZpZXcucmVtb3ZlRnJvbVBhcmVudCgpO1xuICAgICAgICAgICAgICAgICAgICBzZWxmLnZpZXcgPSBudWxsO1xuICAgICAgICAgICAgICAgIH1cbiAgICAgICAgICAgICAgICBzZWxmLnZpZXcgPSByb290O1xuICAgICAgICAgICAgfSk7XG4gICAgICAgICAgICB0aGlzLnZpZXdOYW1lID0gdmlld05hbWU7XG4gICAgICAgICAgICByZXR1cm4gdGhpcy52aWV3O1xuICAgICAgICB9XG4gICAgICAgIHJldHVybiBudWxsO1xuICAgIH0sXG59KTtcbiIsImNvbnNvbGUubG9nKFwiaGVoZWFoaGFoYSDmtYvor5XlhajlsYDnlKjms5VcIik7XG5cblxubW9kdWxlLmV4cG9ydHMgPSBudWxsOyJdLCJzb3VyY2VSb290IjoiIn0=