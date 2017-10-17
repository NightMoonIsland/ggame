require=(function e(t,n,r){function s(o,u){if(!n[o]){if(!t[o]){var a=typeof require=="function"&&require;if(!u&&a)return a(o,!0);if(i)return i(o,!0);var f=new Error("Cannot find module '"+o+"'");throw f.code="MODULE_NOT_FOUND",f}var l=n[o]={exports:{}};t[o][0].call(l.exports,function(e){var n=t[o][1][e];return s(n?n:e)},l,l.exports,e,t,n,r)}return n[o].exports}var i=typeof require=="function"&&require;for(var o=0;o<r.length;o++)s(r[o]);return s})({"appStart":[function(require,module,exports){
"use strict";
cc._RF.push(module, '03b75uMHVBKJaVXnZ7kKcue', 'appStart');
// script/appStart.js

"use strict";

var _typeof = typeof Symbol === "function" && typeof Symbol.iterator === "symbol" ? function (obj) { return typeof obj; } : function (obj) { return obj && typeof Symbol === "function" && obj.constructor === Symbol && obj !== Symbol.prototype ? "symbol" : typeof obj; };

function init() {
    cc.tool = {};
    var viewManager = require("viewManager");
    console.log("wocao nima");
    require("viewRegister");
    cc.tool.viewManager = new viewManager();
    cc.tool.viewManager.init();
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
    },

    // use this for initialization
    onLoad: function onLoad() {
        console.log("hahahahhsfassaga");
        init();
        this.initScene();
    },

    initScene: function initScene() {
        cc.tool.viewManager.setRoot(this.node);
        cc.tool.viewManager.changeView("hahhahahaa");
    },

    testRemove: function testRemove() {
        cc.tool.viewManager.curView();
    }

});

cc._RF.pop();
},{"array1":"array1","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
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
},{}],"viewManager":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'c2b58Q1/V5Ip4c2V3uuBiR6', 'viewManager');
// script/tool/viewManager.js

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
        array1: null,
        viewList: [],
        root: cc.Node
    },

    ctor: function ctor() {
        console.log("hhhehehe");
        var array1 = require("array1");
        this.array1 = new array1();
        // this.array1 = new require("array1");
        this.array1.status();
        this.array1.pushBack({ a: 1, b: 2 });
        this.array1.status();
    },

    setRoot: function setRoot(node) {
        this.root = node;
    },

    // use this for initialization
    onLoad: function onLoad() {
        // console.log("hahahahha");

        // cc.variable.viewList.asfdfsdf();
        // console.log(typeof this.viewName);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    init: function init() {
        this.viewList = [];
        console.log("to this 1");
        this.viewList["haha"] = { a: 1, b: 2 };
        console.log("to this 2");
    },

    registView: function registView(viewName, module, title) {
        this.viewList[viewName] = { viewName: viewName, module: module, title: title };

        var viewInfo = this.viewList[viewName];
        this.viewList[0] = "hahah";
        this.viewList[1] = "wocao";
        console.log(viewInfo);
        console.log(this.viewList.length);
    },


    changeView: function changeView(viewName) {
        var idx = this.array1.find(viewName);
        if (idx != this.array1.npos) {} else {}
        var self = this;
        //通过链接 加载的资源 必须放在resource下
        cc.loader.loadRes("prefab/Test1Panel", function (err, prefab) {
            var root = cc.instantiate(prefab);
            self.root = root;
            cc.director.getScene().getChildByName("Canvas").addChild(root);
        });

        return this.root;
    },

    curView: function curView() {
        this.root.removeFromParent(false);
        // cc.loader.releaseRes("prefab/Test1Panel");
    },

    testAddChild: function testAddChild() {},

    backPreview: function backPreview() {}
});

cc._RF.pop();
},{"array1":"array1"}],"viewRegister":[function(require,module,exports){
"use strict";
cc._RF.push(module, '8f625ZW1F9O2ZNLWZmuFA5B', 'viewRegister');
// script/tool/viewRegister.js

"use strict";

console.log("heheahhaha");

cc._RF.pop();
},{}]},{},["appStart","array1","viewManager","viewRegister"])

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL3ZpZXdNYW5hZ2VyLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL3ZpZXdSZWdpc3Rlci5qcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiOzs7Ozs7Ozs7QUFBQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDQTtBQUNBO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0E7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUE5Qkk7Ozs7Ozs7Ozs7QUNsQ1Q7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBYlE7QUFlWjtBQUNBO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7QUFDRDtBQUNBO0FBQ0k7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNJO0FBQ0g7QUFDSjtBQUVHO0FBQ0k7QUFDSTtBQUNBO0FBQ0g7QUFDSjtBQUNKO0FBQ0Q7QUFDSDs7QUFFRDtBQUNJO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDSTtBQUVBO0FBQ0k7QUFESjtBQUdJO0FBREo7QUFHSDtBQUNKOztBQUVEO0FBQ0k7QUFDSTtBQURKO0FBR0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDSDs7QUFFRDtBQUNJO0FBQ0k7QUFESjtBQUdIOztBQWhHSTs7Ozs7Ozs7OztBQ0VUO0FBQ0k7O0FBRUE7QUFDSTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQWJROztBQWdCWjtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBRUg7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0E7QUFDSTs7QUFFQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDQTs7QUFFQTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0g7OztBQUVEO0FBQ0k7QUFDQTtBQU1BO0FBQ0E7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7O0FBSUE7QUE1Rks7Ozs7Ozs7Ozs7QUNGVCIsInNvdXJjZXNDb250ZW50IjpbImZ1bmN0aW9uIGluaXQoKXtcclxuICAgIGNjLnRvb2wgPSB7fVxyXG4gICAgdmFyIHZpZXdNYW5hZ2VyID0gcmVxdWlyZShcInZpZXdNYW5hZ2VyXCIpO1xyXG4gICAgY29uc29sZS5sb2coXCJ3b2NhbyBuaW1hXCIpO1xyXG4gICAgcmVxdWlyZShcInZpZXdSZWdpc3RlclwiKTtcclxuICAgIGNjLnRvb2wudmlld01hbmFnZXIgPSBuZXcgdmlld01hbmFnZXIoKTtcclxuICAgIGNjLnRvb2wudmlld01hbmFnZXIuaW5pdCgpO1xyXG4gICAgLy8gY2MudG9vbC52aWV3TWFuYWdlci5yZWdpc3RWaWV3KFwiaGFoYWhhXCIsIFwiaGVoZWhlXCIsIFwiaGloaWhpXCIpO1xyXG5cclxuICAgIHZhciBoYWhhID0gW107XHJcbiAgICBmb3IoaT0wO2kgPCA1O2krKyl7XHJcbiAgICAgICAgaGFoYVtpXSA9IGk7XHJcbiAgICB9XHJcbiAgICBjb25zb2xlLmxvZyhoYWhhLmxlbmd0aClcclxuICAgIGRlbGV0ZSBoYWhhWzJdO1xyXG4gICAgZm9yKGk9MDtpIDwgNTtpKyspe1xyXG4gICAgICAgIGNvbnNvbGUubG9nKHR5cGVvZiBoYWhhW2ldKTtcclxuICAgIH1cclxuXHJcbiAgICB2YXIgYXJyYXkgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xyXG4gICAgdmFyIHRlc3QgPSBuZXcgYXJyYXkoKTtcclxuICAgIHRlc3Qub3V0UHV0KCk7XHJcbiAgICBmb3IoaSA9IDA7IGkgPCA1OyBpKyspe1xyXG4gICAgICAgIHRlc3QucHVzaEJhY2soaSArIDEwMClcclxuICAgIH1cclxuICAgIHRlc3Qub3V0UHV0KCk7XHJcbiAgICB0ZXN0LnJlbW92ZSgyKTtcclxuICAgIHRlc3Qub3V0UHV0KCk7XHJcblxyXG4gICAgLy8gY2MudmFyaWFibGUgPSB7fTtcclxuICAgIC8vIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xyXG4gICAgLy8gY2MudmFyaWFibGUudmlld0xpc3QgPSBuZXcgYXJyYXkxKCk7XHJcbn1cclxuXHJcbmNjLkNsYXNzKHtcclxuICAgIGV4dGVuZHM6IGNjLkNvbXBvbmVudCxcclxuXHJcbiAgICBwcm9wZXJ0aWVzOiB7XHJcbiAgICAgICAgLy8gZm9vOiB7XHJcbiAgICAgICAgLy8gICAgZGVmYXVsdDogbnVsbCwgICAgICAvLyBUaGUgZGVmYXVsdCB2YWx1ZSB3aWxsIGJlIHVzZWQgb25seSB3aGVuIHRoZSBjb21wb25lbnQgYXR0YWNoaW5nXHJcbiAgICAgICAgLy8gICAgICAgICAgICAgICAgICAgICAgICAgICB0byBhIG5vZGUgZm9yIHRoZSBmaXJzdCB0aW1lXHJcbiAgICAgICAgLy8gICAgdXJsOiBjYy5UZXh0dXJlMkQsICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0eXBlb2YgZGVmYXVsdFxyXG4gICAgICAgIC8vICAgIHNlcmlhbGl6YWJsZTogdHJ1ZSwgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxyXG4gICAgICAgIC8vICAgIHZpc2libGU6IHRydWUsICAgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHJ1ZVxyXG4gICAgICAgIC8vICAgIGRpc3BsYXlOYW1lOiAnRm9vJywgLy8gb3B0aW9uYWxcclxuICAgICAgICAvLyAgICByZWFkb25seTogZmFsc2UsICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIGZhbHNlXHJcbiAgICAgICAgLy8gfSxcclxuICAgICAgICAvLyAuLi5cclxuICAgIH0sXHJcblxyXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXHJcbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcclxuICAgICAgICBjb25zb2xlLmxvZyhcImhhaGFoYWhoc2Zhc3NhZ2FcIik7XHJcbiAgICAgICAgaW5pdCgpO1xyXG4gICAgICAgIHRoaXMuaW5pdFNjZW5lKCk7XHJcbiAgICB9LFxyXG5cclxuICAgIGluaXRTY2VuZTogZnVuY3Rpb24oKSB7XHJcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5zZXRSb290KHRoaXMubm9kZSk7XHJcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jaGFuZ2VWaWV3KFwiaGFoaGFoYWhhYVwiKTtcclxuICAgIH0sXHJcblxyXG4gICAgdGVzdFJlbW92ZTogZnVuY3Rpb24oKSB7XHJcbiAgICAgICAgY2MudG9vbC52aWV3TWFuYWdlci5jdXJWaWV3KCk7XHJcbiAgICB9LFxyXG5cclxuICAgIC8vIGNhbGxlZCBldmVyeSBmcmFtZSwgdW5jb21tZW50IHRoaXMgZnVuY3Rpb24gdG8gYWN0aXZhdGUgdXBkYXRlIGNhbGxiYWNrXHJcbiAgICAvLyB1cGRhdGU6IGZ1bmN0aW9uIChkdCkge1xyXG5cclxuICAgIC8vIH0sXHJcbn0pO1xyXG4iLCJjYy5DbGFzcyh7XHJcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXHJcblxyXG4gICAgcHJvcGVydGllczoge1xyXG4gICAgICAgIC8vIGZvbzoge1xyXG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xyXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxyXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcclxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcclxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcclxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXHJcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxyXG4gICAgICAgIC8vIH0sXHJcbiAgICAgICAgLy8gLi4uXHJcbiAgICAgICAgbGlzdDogW10sXHJcbiAgICAgICAgc2l6ZTogMCxcclxuICAgICAgICBucG9zOiAtMSxcclxuICAgIH0sXHJcbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cclxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xyXG4gICAgICAgIGNvbnNvbGUubG9nKFwid29ya2VkXCIpO1xyXG4gICAgfSxcclxuXHJcbiAgICBhc2ZkZnNkZjogZnVuY3Rpb24oKSB7XHJcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcclxuICAgICAgICAvLyBjb25zb2xlLmxvZyh0eXBlb2YgdGhpcy5saXN0KTtcclxuICAgICAgICBjb25zb2xlLmxvZyhcIndvY2FvXCIpO1xyXG4gICAgfSxcclxuXHJcbiAgICBzdGF0dXM6IGZ1bmN0aW9uKCkge1xyXG4gICAgICAgIGNvbnNvbGUubG9nKFwic2VsZi5zaXplMVwiKTtcclxuICAgICAgICBjb25zb2xlLmxvZyh0aGlzLnNpemUpO1xyXG4gICAgICAgIGNvbnNvbGUubG9nKFwic2VsZi5zaXplMlwiKTtcclxuICAgIH0sXHJcbiAgICAvL1xyXG4gICAgcHVzaEJhY2s6IGZ1bmN0aW9uKGRhdGEpIHtcclxuICAgICAgICB0aGlzLmxpc3RbdGhpcy5zaXplXSA9IGRhdGE7XHJcbiAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplICsgMTtcclxuICAgIH0sXHJcblxyXG4gICAgYXQ6IGZ1bmN0aW9uKGlkeCl7XHJcbiAgICAgICAgcmV0dXJuIHRoaXMubGlzdFtpZHhdO1xyXG4gICAgfSxcclxuXHJcbiAgICBmaW5kOiBmdW5jdGlvbih2YWx1ZSl7XHJcbiAgICAgICAgdmFyIGluZGV4ID0gdGhpcy5ucG9zO1xyXG4gICAgICAgIGlmICh0eXBlb2YgdmFsdWUgPT0gXCJmdW5jdGlvblwiKXtcclxuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspe1xyXG4gICAgICAgICAgICAgICAgaWYodmFsdWUoaSkpIHJldHVybiBpO1xyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgfVxyXG4gICAgICAgIGVsc2V7XHJcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcclxuICAgICAgICAgICAgICAgIGlmKHRoaXMubGlzdFtpXSA9PSB2YWx1ZSl7XHJcbiAgICAgICAgICAgICAgICAgICAgaW5kZXggPSBpO1xyXG4gICAgICAgICAgICAgICAgICAgIGJyZWFrO1xyXG4gICAgICAgICAgICAgICAgfVxyXG4gICAgICAgICAgICB9XHJcbiAgICAgICAgfVxyXG4gICAgICAgIHJldHVybiBpbmRleDtcclxuICAgIH0sXHJcblxyXG4gICAgcmVtb3ZlOiBmdW5jdGlvbihwb3MsIGxlbil7XHJcbiAgICAgICAgaWYocG9zIDwgMCkgcG9zID0gMDtcclxuICAgICAgICBpZihsZW4gPT0gbnVsbCB8fCBsZW4gPD0gMCl7XHJcbiAgICAgICAgICAgIGxlbiA9IDE7XHJcbiAgICAgICAgfVxyXG4gICAgICAgIGlmKHBvcyA8IHRoaXMuc2l6ZSl7XHJcbiAgICAgICAgICAgIGlmKHBvcyArIGxlbiA+IHRoaXMuc2l6ZSlcclxuICAgICAgICAgICAgICAgIGxlbiA9IHRoaXMuc2l6ZSAtIHBvcztcclxuICAgICAgICAgICAgZm9yKGkgPSAwOyBpIDwgbGVuOyBpKyspXHJcbiAgICAgICAgICAgICAgICBkZWxldGUgdGhpcy5saXN0W3BvcyArIGldO1xyXG4gICAgICAgICAgICBmb3IoaSA9IHBvcyArIGxlbjsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxyXG4gICAgICAgICAgICAgICAgdGhpcy5saXN0W2kgLSBsZW5dID0gdGhpcy5saXN0W2ldO1xyXG4gICAgICAgICAgICB0aGlzLnNpemUgPSB0aGlzLnNpemUgLSBsZW47XHJcbiAgICAgICAgfVxyXG4gICAgfSxcclxuXHJcbiAgICBjbGVhcjogZnVuY3Rpb24oKXtcclxuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcclxuICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtpXTtcclxuICAgICAgICB0aGlzLnNpemUgPSAwO1xyXG4gICAgfSxcclxuXHJcbiAgICBnZXRTaXplOiBmdW5jdGlvbigpIHtcclxuICAgICAgICByZXR1cm4gdGhpcy5zaXplO1xyXG4gICAgfSxcclxuXHJcbiAgICBlbXB0eTogZnVuY3Rpb24oKSB7XHJcbiAgICAgICAgcmV0dXJuIHRoaXMuc2l6ZSA9PSAwO1xyXG4gICAgfSxcclxuXHJcbiAgICBvdXRQdXQ6IGZ1bmN0aW9uKCkge1xyXG4gICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKVxyXG4gICAgICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnRcIiArIGkgKyBcIiA9IFwiICsgdGhpcy5saXN0W2ldKTtcclxuICAgICAgICBjb25zb2xlLmxvZyhcImVsZW1lbnQgc2l6ZSA9IFwiICsgdGhpcy5zaXplKTtcclxuICAgIH0sXHJcblxyXG5cclxuXHJcbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xyXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcclxuXHJcbiAgICAvLyB9LFxyXG59KTtcclxuIiwiXHJcblxyXG5jYy5DbGFzcyh7XHJcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXHJcblxyXG4gICAgcHJvcGVydGllczoge1xyXG4gICAgICAgIC8vIGZvbzoge1xyXG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xyXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxyXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcclxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcclxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcclxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXHJcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxyXG4gICAgICAgIC8vIH0sXHJcbiAgICAgICAgLy8gLi4uXHJcbiAgICAgICAgYXJyYXkxOiBudWxsLFxyXG4gICAgICAgIHZpZXdMaXN0OiBbXSxcclxuICAgICAgICByb290OiBjYy5Ob2RlLFxyXG4gICAgfSxcclxuXHJcbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcclxuICAgICAgICBjb25zb2xlLmxvZyhcImhoaGVoZWhlXCIpO1xyXG4gICAgICAgIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xyXG4gICAgICAgIHRoaXMuYXJyYXkxID0gbmV3IGFycmF5MSgpO1xyXG4gICAgICAgIC8vIHRoaXMuYXJyYXkxID0gbmV3IHJlcXVpcmUoXCJhcnJheTFcIik7XHJcbiAgICAgICAgdGhpcy5hcnJheTEuc3RhdHVzKCk7XHJcbiAgICAgICAgdGhpcy5hcnJheTEucHVzaEJhY2soe2E6MSwgYjoyfSk7XHJcbiAgICAgICAgdGhpcy5hcnJheTEuc3RhdHVzKCk7XHJcbiAgICAgICAgXHJcbiAgICB9LFxyXG5cclxuICAgIHNldFJvb3Q6IGZ1bmN0aW9uKG5vZGUpIHtcclxuICAgICAgICB0aGlzLnJvb3QgPSBub2RlO1xyXG4gICAgfSxcclxuXHJcbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cclxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xyXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKFwiaGFoYWhhaGhhXCIpO1xyXG5cclxuICAgICAgICAvLyBjYy52YXJpYWJsZS52aWV3TGlzdC5hc2ZkZnNkZigpO1xyXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKHR5cGVvZiB0aGlzLnZpZXdOYW1lKTtcclxuICAgIH0sXHJcblxyXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcclxuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XHJcblxyXG4gICAgLy8gfSxcclxuXHJcbiAgICBpbml0OiBmdW5jdGlvbigpe1xyXG4gICAgICAgIHRoaXMudmlld0xpc3QgPSBbXTtcclxuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMVwiKTtcclxuICAgICAgICB0aGlzLnZpZXdMaXN0W1wiaGFoYVwiXSA9IHthOjEsIGI6Mn07XHJcbiAgICAgICAgY29uc29sZS5sb2coXCJ0byB0aGlzIDJcIik7XHJcbiAgICB9LFxyXG5cclxuICAgIHJlZ2lzdFZpZXcodmlld05hbWUsIG1vZHVsZSwgdGl0bGUpe1xyXG4gICAgICAgIHRoaXMudmlld0xpc3Rbdmlld05hbWVdID0ge3ZpZXdOYW1lOnZpZXdOYW1lLCBtb2R1bGU6bW9kdWxlLCB0aXRsZTp0aXRsZX07XHJcblxyXG4gICAgICAgIHZhciB2aWV3SW5mbyA9IHRoaXMudmlld0xpc3Rbdmlld05hbWVdO1xyXG4gICAgICAgIHRoaXMudmlld0xpc3RbMF0gPSBcImhhaGFoXCI7XHJcbiAgICAgICAgdGhpcy52aWV3TGlzdFsxXSA9IFwid29jYW9cIjtcclxuICAgICAgICBjb25zb2xlLmxvZyh2aWV3SW5mbyk7XHJcbiAgICAgICAgY29uc29sZS5sb2codGhpcy52aWV3TGlzdC5sZW5ndGgpO1xyXG4gICAgfSxcclxuXHJcbiAgICBjaGFuZ2VWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSl7XHJcbiAgICAgICAgdmFyIGlkeCA9IHRoaXMuYXJyYXkxLmZpbmQodmlld05hbWUpO1xyXG4gICAgICAgIGlmKGlkeCAhPSB0aGlzLmFycmF5MS5ucG9zKXtcclxuXHJcbiAgICAgICAgfVxyXG4gICAgICAgIGVsc2V7XHJcblxyXG4gICAgICAgIH1cclxuICAgICAgICB2YXIgc2VsZiA9IHRoaXM7XHJcbiAgICAgICAgLy/pgJrov4fpk77mjqUg5Yqg6L2955qE6LWE5rqQIOW/hemhu+aUvuWcqHJlc291cmNl5LiLXHJcbiAgICAgICAgY2MubG9hZGVyLmxvYWRSZXMoXCJwcmVmYWIvVGVzdDFQYW5lbFwiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XHJcbiAgICAgICAgICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcclxuICAgICAgICAgICAgc2VsZi5yb290ID0gcm9vdDtcclxuICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcclxuICAgICAgICB9KTtcclxuICAgICAgICBcclxuICAgICAgICByZXR1cm4gdGhpcy5yb290O1xyXG4gICAgfSxcclxuXHJcbiAgICBjdXJWaWV3OiBmdW5jdGlvbigpIHtcclxuICAgICAgICB0aGlzLnJvb3QucmVtb3ZlRnJvbVBhcmVudChmYWxzZSk7XHJcbiAgICAgICAgLy8gY2MubG9hZGVyLnJlbGVhc2VSZXMoXCJwcmVmYWIvVGVzdDFQYW5lbFwiKTtcclxuICAgIH0sXHJcblxyXG4gICAgdGVzdEFkZENoaWxkOiBmdW5jdGlvbigpe1xyXG5cclxuICAgIH0sXHJcblxyXG4gICAgYmFja1ByZXZpZXc6IGZ1bmN0aW9uKCl7XHJcblxyXG4gICAgfSxcclxufSk7XHJcbiIsImNvbnNvbGUubG9nKFwiaGVoZWFoaGFoYVwiKTsiXSwic291cmNlUm9vdCI6IiJ9