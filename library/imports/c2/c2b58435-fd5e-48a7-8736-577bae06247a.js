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