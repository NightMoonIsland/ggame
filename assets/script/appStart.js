function init(){
    cc.tool = {}
    var viewManager = require("viewManager");
    cc.tool.viewManager = new viewManager();
    cc.tool.viewManager.init();

    require("viewRegister");

    var eventManager = require("eventManager");
    cc.tool.eventManager = new eventManager();


    cc.tool.Lang = require("langZh");
    console.log(cc.tool.Lang["ITEM_VALUE"]);
    // cc.tool.viewManager.registView("hahaha", "hehehe", "hihihi");

    var haha = [];
    for(i=0;i < 5;i++){
        haha[i] = i;
    }
    console.log(haha.length)
    delete haha[2];
    for(i=0;i < 5;i++){
        console.log(typeof haha[i]);
    }

    var array = require("array1");
    var test = new array();
    test.outPut();
    for(i = 0; i < 5; i++){
        test.pushBack(i + 100)
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
        haha: [],
    },

    // use this for initialization
    onLoad: function () {
        console.log("hahahahhsfassaga");
        init();
        this.initScene();
    },

    initScene: function() {
        // cc.tool.viewManager.setRoot(this.node);
        // cc.tool.viewManager.changeView("hahhahahaa");
        console.log("test type" + typeof this.haha["wocao"]);
    },

    testRemove: function() {
        var test = require("eventManager")
        var haha = new test();
        haha.init();
        cc.tool.viewManager.curView();
        // var test = require("eventManager")
        // var haha = new test();
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
