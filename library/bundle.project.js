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
    }

});

cc._RF.pop();
},{"array1":"array1","viewManager":"viewManager","viewRegister":"viewRegister"}],"array1":[function(require,module,exports){
"use strict";
cc._RF.push(module, 'fb6a6Ja9dNOP5bnlzovehME', 'array1');
// script/tool/array1.js

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

    outPut: function outPut() {
        for (i = 0; i < this.size; i++) {
            console.log("element" + i + " = " + this.list[i]);
        }console.log("element size = " + this.size);
    }

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
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

        //通过链接 加载的资源 必须放在resource下
        cc.loader.loadRes("prefab/Test1Panel", function (err, prefab) {
            var root = cc.instantiate(prefab);
            cc.director.getScene().getChildByName("Canvas").addChild(root);
        });

        return this.root;
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

//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImFzc2V0cy9zY3JpcHQvYXBwU3RhcnQuanMiLCJhc3NldHMvc2NyaXB0L2xpYnJhcnkvYXJyYXkxLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL3ZpZXdNYW5hZ2VyLmpzIiwiYXNzZXRzL3NjcmlwdC90b29sL3ZpZXdSZWdpc3Rlci5qcyJdLCJuYW1lcyI6W10sIm1hcHBpbmdzIjoiOzs7Ozs7Ozs7QUFBQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBOztBQUVBO0FBQ0E7QUFDSTtBQUNIO0FBQ0Q7QUFDQTtBQUNBO0FBQ0k7QUFDSDs7QUFFRDtBQUNBO0FBQ0E7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNBO0FBQ0E7O0FBRUE7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBVlE7O0FBYVo7QUFDQTtBQUNJO0FBQ0E7QUFDQTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNIOztBQTFCSTs7Ozs7Ozs7OztBQ2xDVDtBQUNJOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFiUTtBQWVaO0FBQ0E7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNBO0FBQ0E7QUFDSDtBQUNEO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSTtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0k7QUFDSDtBQUNKO0FBRUc7QUFDSTtBQUNJO0FBQ0E7QUFDSDtBQUNKO0FBQ0o7QUFDRDtBQUNIOztBQUVEO0FBQ0k7QUFDQTtBQUNJO0FBQ0g7QUFDRDtBQUNJO0FBRUE7QUFDSTtBQURKO0FBR0k7QUFESjtBQUdIO0FBQ0o7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDSTtBQUNJO0FBREo7QUFHSDs7QUFJRDtBQUNBOztBQUVBO0FBbkdLOzs7Ozs7Ozs7O0FDRVQ7QUFDSTs7QUFFQTtBQUNJO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBYlE7O0FBZ0JaO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFFSDs7QUFFRDtBQUNJO0FBQ0g7O0FBRUQ7QUFDQTtBQUNJOztBQUVBO0FBQ0E7QUFDSDs7QUFFRDtBQUNBOztBQUVBOztBQUVBO0FBQ0k7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7QUFFRDtBQUNJOztBQUVBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDSDs7O0FBRUQ7QUFDSTtBQUNBOztBQU9BO0FBQ0E7QUFDSTtBQUNBO0FBQ0g7O0FBRUQ7QUFDSDs7QUFFRDs7QUFJQTtBQXRGSzs7Ozs7Ozs7OztBQ0ZUIiwic291cmNlc0NvbnRlbnQiOlsiZnVuY3Rpb24gaW5pdCgpe1xyXG4gICAgY2MudG9vbCA9IHt9XHJcbiAgICB2YXIgdmlld01hbmFnZXIgPSByZXF1aXJlKFwidmlld01hbmFnZXJcIik7XHJcbiAgICBjb25zb2xlLmxvZyhcIndvY2FvIG5pbWFcIik7XHJcbiAgICByZXF1aXJlKFwidmlld1JlZ2lzdGVyXCIpO1xyXG4gICAgY2MudG9vbC52aWV3TWFuYWdlciA9IG5ldyB2aWV3TWFuYWdlcigpO1xyXG4gICAgY2MudG9vbC52aWV3TWFuYWdlci5pbml0KCk7XHJcbiAgICAvLyBjYy50b29sLnZpZXdNYW5hZ2VyLnJlZ2lzdFZpZXcoXCJoYWhhaGFcIiwgXCJoZWhlaGVcIiwgXCJoaWhpaGlcIik7XHJcblxyXG4gICAgdmFyIGhhaGEgPSBbXTtcclxuICAgIGZvcihpPTA7aSA8IDU7aSsrKXtcclxuICAgICAgICBoYWhhW2ldID0gaTtcclxuICAgIH1cclxuICAgIGNvbnNvbGUubG9nKGhhaGEubGVuZ3RoKVxyXG4gICAgZGVsZXRlIGhhaGFbMl07XHJcbiAgICBmb3IoaT0wO2kgPCA1O2krKyl7XHJcbiAgICAgICAgY29uc29sZS5sb2codHlwZW9mIGhhaGFbaV0pO1xyXG4gICAgfVxyXG5cclxuICAgIHZhciBhcnJheSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XHJcbiAgICB2YXIgdGVzdCA9IG5ldyBhcnJheSgpO1xyXG4gICAgdGVzdC5vdXRQdXQoKTtcclxuICAgIGZvcihpID0gMDsgaSA8IDU7IGkrKyl7XHJcbiAgICAgICAgdGVzdC5wdXNoQmFjayhpICsgMTAwKVxyXG4gICAgfVxyXG4gICAgdGVzdC5vdXRQdXQoKTtcclxuICAgIHRlc3QucmVtb3ZlKDIpO1xyXG4gICAgdGVzdC5vdXRQdXQoKTtcclxuXHJcbiAgICAvLyBjYy52YXJpYWJsZSA9IHt9O1xyXG4gICAgLy8gdmFyIGFycmF5MSA9IHJlcXVpcmUoXCJhcnJheTFcIik7XHJcbiAgICAvLyBjYy52YXJpYWJsZS52aWV3TGlzdCA9IG5ldyBhcnJheTEoKTtcclxufVxyXG5cclxuY2MuQ2xhc3Moe1xyXG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxyXG5cclxuICAgIHByb3BlcnRpZXM6IHtcclxuICAgICAgICAvLyBmb286IHtcclxuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcclxuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcclxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XHJcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXHJcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXHJcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxyXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcclxuICAgICAgICAvLyB9LFxyXG4gICAgICAgIC8vIC4uLlxyXG4gICAgfSxcclxuXHJcbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cclxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xyXG4gICAgICAgIGNvbnNvbGUubG9nKFwiaGFoYWhhaGhzZmFzc2FnYVwiKTtcclxuICAgICAgICBpbml0KCk7XHJcbiAgICAgICAgdGhpcy5pbml0U2NlbmUoKTtcclxuICAgIH0sXHJcblxyXG4gICAgaW5pdFNjZW5lOiBmdW5jdGlvbigpIHtcclxuICAgICAgICBjYy50b29sLnZpZXdNYW5hZ2VyLnNldFJvb3QodGhpcy5ub2RlKTtcclxuICAgICAgICBjYy50b29sLnZpZXdNYW5hZ2VyLmNoYW5nZVZpZXcoXCJoYWhoYWhhaGFhXCIpO1xyXG4gICAgfSxcclxuXHJcbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xyXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcclxuXHJcbiAgICAvLyB9LFxyXG59KTtcclxuIiwiY2MuQ2xhc3Moe1xyXG4gICAgZXh0ZW5kczogY2MuQ29tcG9uZW50LFxyXG5cclxuICAgIHByb3BlcnRpZXM6IHtcclxuICAgICAgICAvLyBmb286IHtcclxuICAgICAgICAvLyAgICBkZWZhdWx0OiBudWxsLCAgICAgIC8vIFRoZSBkZWZhdWx0IHZhbHVlIHdpbGwgYmUgdXNlZCBvbmx5IHdoZW4gdGhlIGNvbXBvbmVudCBhdHRhY2hpbmdcclxuICAgICAgICAvLyAgICAgICAgICAgICAgICAgICAgICAgICAgIHRvIGEgbm9kZSBmb3IgdGhlIGZpcnN0IHRpbWVcclxuICAgICAgICAvLyAgICB1cmw6IGNjLlRleHR1cmUyRCwgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHR5cGVvZiBkZWZhdWx0XHJcbiAgICAgICAgLy8gICAgc2VyaWFsaXphYmxlOiB0cnVlLCAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXHJcbiAgICAgICAgLy8gICAgdmlzaWJsZTogdHJ1ZSwgICAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyB0cnVlXHJcbiAgICAgICAgLy8gICAgZGlzcGxheU5hbWU6ICdGb28nLCAvLyBvcHRpb25hbFxyXG4gICAgICAgIC8vICAgIHJlYWRvbmx5OiBmYWxzZSwgICAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgZmFsc2VcclxuICAgICAgICAvLyB9LFxyXG4gICAgICAgIC8vIC4uLlxyXG4gICAgICAgIGxpc3Q6IFtdLFxyXG4gICAgICAgIHNpemU6IDAsXHJcbiAgICAgICAgbnBvczogLTEsXHJcbiAgICB9LFxyXG4gICAgLy8gdXNlIHRoaXMgZm9yIGluaXRpYWxpemF0aW9uXHJcbiAgICBvbkxvYWQ6IGZ1bmN0aW9uICgpIHtcclxuICAgICAgICBjb25zb2xlLmxvZyhcIndvcmtlZFwiKTtcclxuICAgIH0sXHJcblxyXG4gICAgYXNmZGZzZGY6IGZ1bmN0aW9uKCkge1xyXG4gICAgICAgIGNvbnNvbGUubG9nKFwid29jYW9cIik7XHJcbiAgICAgICAgLy8gY29uc29sZS5sb2codHlwZW9mIHRoaXMubGlzdCk7XHJcbiAgICAgICAgY29uc29sZS5sb2coXCJ3b2Nhb1wiKTtcclxuICAgIH0sXHJcblxyXG4gICAgc3RhdHVzOiBmdW5jdGlvbigpIHtcclxuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTFcIik7XHJcbiAgICAgICAgY29uc29sZS5sb2codGhpcy5zaXplKTtcclxuICAgICAgICBjb25zb2xlLmxvZyhcInNlbGYuc2l6ZTJcIik7XHJcbiAgICB9LFxyXG4gICAgLy9cclxuICAgIHB1c2hCYWNrOiBmdW5jdGlvbihkYXRhKSB7XHJcbiAgICAgICAgdGhpcy5saXN0W3RoaXMuc2l6ZV0gPSBkYXRhO1xyXG4gICAgICAgIHRoaXMuc2l6ZSA9IHRoaXMuc2l6ZSArIDE7XHJcbiAgICB9LFxyXG5cclxuICAgIGF0OiBmdW5jdGlvbihpZHgpe1xyXG4gICAgICAgIHJldHVybiB0aGlzLmxpc3RbaWR4XTtcclxuICAgIH0sXHJcblxyXG4gICAgZmluZDogZnVuY3Rpb24odmFsdWUpe1xyXG4gICAgICAgIHZhciBpbmRleCA9IHRoaXMubnBvcztcclxuICAgICAgICBpZiAodHlwZW9mIHZhbHVlID09IFwiZnVuY3Rpb25cIil7XHJcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IHRoaXMuc2l6ZTsgaSsrKXtcclxuICAgICAgICAgICAgICAgIGlmKHZhbHVlKGkpKSByZXR1cm4gaTtcclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgICAgICBlbHNle1xyXG4gICAgICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKyl7XHJcbiAgICAgICAgICAgICAgICBpZih0aGlzLmxpc3RbaV0gPT0gdmFsdWUpe1xyXG4gICAgICAgICAgICAgICAgICAgIGluZGV4ID0gaTtcclxuICAgICAgICAgICAgICAgICAgICBicmVhaztcclxuICAgICAgICAgICAgICAgIH1cclxuICAgICAgICAgICAgfVxyXG4gICAgICAgIH1cclxuICAgICAgICByZXR1cm4gaW5kZXg7XHJcbiAgICB9LFxyXG5cclxuICAgIHJlbW92ZTogZnVuY3Rpb24ocG9zLCBsZW4pe1xyXG4gICAgICAgIGlmKHBvcyA8IDApIHBvcyA9IDA7XHJcbiAgICAgICAgaWYobGVuID09IG51bGwgfHwgbGVuIDw9IDApe1xyXG4gICAgICAgICAgICBsZW4gPSAxO1xyXG4gICAgICAgIH1cclxuICAgICAgICBpZihwb3MgPCB0aGlzLnNpemUpe1xyXG4gICAgICAgICAgICBpZihwb3MgKyBsZW4gPiB0aGlzLnNpemUpXHJcbiAgICAgICAgICAgICAgICBsZW4gPSB0aGlzLnNpemUgLSBwb3M7XHJcbiAgICAgICAgICAgIGZvcihpID0gMDsgaSA8IGxlbjsgaSsrKVxyXG4gICAgICAgICAgICAgICAgZGVsZXRlIHRoaXMubGlzdFtwb3MgKyBpXTtcclxuICAgICAgICAgICAgZm9yKGkgPSBwb3MgKyBsZW47IGkgPCB0aGlzLnNpemU7IGkrKylcclxuICAgICAgICAgICAgICAgIHRoaXMubGlzdFtpIC0gbGVuXSA9IHRoaXMubGlzdFtpXTtcclxuICAgICAgICAgICAgdGhpcy5zaXplID0gdGhpcy5zaXplIC0gbGVuO1xyXG4gICAgICAgIH1cclxuICAgIH0sXHJcblxyXG4gICAgY2xlYXI6IGZ1bmN0aW9uKCl7XHJcbiAgICAgICAgZm9yKGkgPSAwOyBpIDwgdGhpcy5zaXplOyBpKyspXHJcbiAgICAgICAgICAgIGRlbGV0ZSB0aGlzLmxpc3RbaV07XHJcbiAgICAgICAgdGhpcy5zaXplID0gMDtcclxuICAgIH0sXHJcblxyXG4gICAgZ2V0U2l6ZTogZnVuY3Rpb24oKSB7XHJcbiAgICAgICAgcmV0dXJuIHRoaXMuc2l6ZTtcclxuICAgIH0sXHJcblxyXG4gICAgb3V0UHV0OiBmdW5jdGlvbigpIHtcclxuICAgICAgICBmb3IoaSA9IDA7IGkgPCB0aGlzLnNpemU7IGkrKylcclxuICAgICAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50XCIgKyBpICsgXCIgPSBcIiArIHRoaXMubGlzdFtpXSk7XHJcbiAgICAgICAgY29uc29sZS5sb2coXCJlbGVtZW50IHNpemUgPSBcIiArIHRoaXMuc2l6ZSk7XHJcbiAgICB9XHJcblxyXG5cclxuXHJcbiAgICAvLyBjYWxsZWQgZXZlcnkgZnJhbWUsIHVuY29tbWVudCB0aGlzIGZ1bmN0aW9uIHRvIGFjdGl2YXRlIHVwZGF0ZSBjYWxsYmFja1xyXG4gICAgLy8gdXBkYXRlOiBmdW5jdGlvbiAoZHQpIHtcclxuXHJcbiAgICAvLyB9LFxyXG59KTtcclxuIiwiXHJcblxyXG5jYy5DbGFzcyh7XHJcbiAgICBleHRlbmRzOiBjYy5Db21wb25lbnQsXHJcblxyXG4gICAgcHJvcGVydGllczoge1xyXG4gICAgICAgIC8vIGZvbzoge1xyXG4gICAgICAgIC8vICAgIGRlZmF1bHQ6IG51bGwsICAgICAgLy8gVGhlIGRlZmF1bHQgdmFsdWUgd2lsbCBiZSB1c2VkIG9ubHkgd2hlbiB0aGUgY29tcG9uZW50IGF0dGFjaGluZ1xyXG4gICAgICAgIC8vICAgICAgICAgICAgICAgICAgICAgICAgICAgdG8gYSBub2RlIGZvciB0aGUgZmlyc3QgdGltZVxyXG4gICAgICAgIC8vICAgIHVybDogY2MuVGV4dHVyZTJELCAgLy8gb3B0aW9uYWwsIGRlZmF1bHQgaXMgdHlwZW9mIGRlZmF1bHRcclxuICAgICAgICAvLyAgICBzZXJpYWxpemFibGU6IHRydWUsIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcclxuICAgICAgICAvLyAgICB2aXNpYmxlOiB0cnVlLCAgICAgIC8vIG9wdGlvbmFsLCBkZWZhdWx0IGlzIHRydWVcclxuICAgICAgICAvLyAgICBkaXNwbGF5TmFtZTogJ0ZvbycsIC8vIG9wdGlvbmFsXHJcbiAgICAgICAgLy8gICAgcmVhZG9ubHk6IGZhbHNlLCAgICAvLyBvcHRpb25hbCwgZGVmYXVsdCBpcyBmYWxzZVxyXG4gICAgICAgIC8vIH0sXHJcbiAgICAgICAgLy8gLi4uXHJcbiAgICAgICAgYXJyYXkxOiBudWxsLFxyXG4gICAgICAgIHZpZXdMaXN0OiBbXSxcclxuICAgICAgICByb290OiBjYy5Ob2RlLFxyXG4gICAgfSxcclxuXHJcbiAgICBjdG9yOiBmdW5jdGlvbigpIHtcclxuICAgICAgICBjb25zb2xlLmxvZyhcImhoaGVoZWhlXCIpO1xyXG4gICAgICAgIHZhciBhcnJheTEgPSByZXF1aXJlKFwiYXJyYXkxXCIpO1xyXG4gICAgICAgIHRoaXMuYXJyYXkxID0gbmV3IGFycmF5MSgpO1xyXG4gICAgICAgIC8vIHRoaXMuYXJyYXkxID0gbmV3IHJlcXVpcmUoXCJhcnJheTFcIik7XHJcbiAgICAgICAgdGhpcy5hcnJheTEuc3RhdHVzKCk7XHJcbiAgICAgICAgdGhpcy5hcnJheTEucHVzaEJhY2soe2E6MSwgYjoyfSk7XHJcbiAgICAgICAgdGhpcy5hcnJheTEuc3RhdHVzKCk7XHJcbiAgICAgICAgXHJcbiAgICB9LFxyXG5cclxuICAgIHNldFJvb3Q6IGZ1bmN0aW9uKG5vZGUpIHtcclxuICAgICAgICB0aGlzLnJvb3QgPSBub2RlO1xyXG4gICAgfSxcclxuXHJcbiAgICAvLyB1c2UgdGhpcyBmb3IgaW5pdGlhbGl6YXRpb25cclxuICAgIG9uTG9hZDogZnVuY3Rpb24gKCkge1xyXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKFwiaGFoYWhhaGhhXCIpO1xyXG5cclxuICAgICAgICAvLyBjYy52YXJpYWJsZS52aWV3TGlzdC5hc2ZkZnNkZigpO1xyXG4gICAgICAgIC8vIGNvbnNvbGUubG9nKHR5cGVvZiB0aGlzLnZpZXdOYW1lKTtcclxuICAgIH0sXHJcblxyXG4gICAgLy8gY2FsbGVkIGV2ZXJ5IGZyYW1lLCB1bmNvbW1lbnQgdGhpcyBmdW5jdGlvbiB0byBhY3RpdmF0ZSB1cGRhdGUgY2FsbGJhY2tcclxuICAgIC8vIHVwZGF0ZTogZnVuY3Rpb24gKGR0KSB7XHJcblxyXG4gICAgLy8gfSxcclxuXHJcbiAgICBpbml0OiBmdW5jdGlvbigpe1xyXG4gICAgICAgIHRoaXMudmlld0xpc3QgPSBbXTtcclxuICAgICAgICBjb25zb2xlLmxvZyhcInRvIHRoaXMgMVwiKTtcclxuICAgICAgICB0aGlzLnZpZXdMaXN0W1wiaGFoYVwiXSA9IHthOjEsIGI6Mn07XHJcbiAgICAgICAgY29uc29sZS5sb2coXCJ0byB0aGlzIDJcIik7XHJcbiAgICB9LFxyXG5cclxuICAgIHJlZ2lzdFZpZXcodmlld05hbWUsIG1vZHVsZSwgdGl0bGUpe1xyXG4gICAgICAgIHRoaXMudmlld0xpc3Rbdmlld05hbWVdID0ge3ZpZXdOYW1lOnZpZXdOYW1lLCBtb2R1bGU6bW9kdWxlLCB0aXRsZTp0aXRsZX07XHJcblxyXG4gICAgICAgIHZhciB2aWV3SW5mbyA9IHRoaXMudmlld0xpc3Rbdmlld05hbWVdO1xyXG4gICAgICAgIHRoaXMudmlld0xpc3RbMF0gPSBcImhhaGFoXCI7XHJcbiAgICAgICAgdGhpcy52aWV3TGlzdFsxXSA9IFwid29jYW9cIjtcclxuICAgICAgICBjb25zb2xlLmxvZyh2aWV3SW5mbyk7XHJcbiAgICAgICAgY29uc29sZS5sb2codGhpcy52aWV3TGlzdC5sZW5ndGgpO1xyXG4gICAgfSxcclxuXHJcbiAgICBjaGFuZ2VWaWV3OiBmdW5jdGlvbih2aWV3TmFtZSl7XHJcbiAgICAgICAgdmFyIGlkeCA9IHRoaXMuYXJyYXkxLmZpbmQodmlld05hbWUpO1xyXG4gICAgICAgIGlmKGlkeCAhPSB0aGlzLmFycmF5MS5ucG9zKXtcclxuXHJcbiAgICAgICAgfVxyXG4gICAgICAgIGVsc2V7XHJcblxyXG4gICAgICAgIH1cclxuXHJcbiAgICAgICAgLy/pgJrov4fpk77mjqUg5Yqg6L2955qE6LWE5rqQIOW/hemhu+aUvuWcqHJlc291cmNl5LiLXHJcbiAgICAgICAgY2MubG9hZGVyLmxvYWRSZXMoXCJwcmVmYWIvVGVzdDFQYW5lbFwiLCBmdW5jdGlvbihlcnIsIHByZWZhYil7XHJcbiAgICAgICAgICAgIHZhciByb290ID0gY2MuaW5zdGFudGlhdGUocHJlZmFiKTtcclxuICAgICAgICAgICAgY2MuZGlyZWN0b3IuZ2V0U2NlbmUoKS5nZXRDaGlsZEJ5TmFtZShcIkNhbnZhc1wiKS5hZGRDaGlsZChyb290KTtcclxuICAgICAgICB9KTtcclxuICAgICAgICBcclxuICAgICAgICByZXR1cm4gdGhpcy5yb290O1xyXG4gICAgfSxcclxuXHJcbiAgICB0ZXN0QWRkQ2hpbGQ6IGZ1bmN0aW9uKCl7XHJcblxyXG4gICAgfSxcclxuXHJcbiAgICBiYWNrUHJldmlldzogZnVuY3Rpb24oKXtcclxuXHJcbiAgICB9LFxyXG59KTtcclxuIiwiY29uc29sZS5sb2coXCJoZWhlYWhoYWhhXCIpOyJdLCJzb3VyY2VSb290IjoiIn0=