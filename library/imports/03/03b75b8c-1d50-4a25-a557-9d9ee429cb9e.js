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

        // var listview = new (require("ListView0"))()
        // this.node.addChild(listview.node);

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