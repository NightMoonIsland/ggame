function init(){
    cc.tool = {}
    var viewManager = require("viewManager");
    cc.tool.viewManager = new viewManager();
    // cc.tool.viewManager.init();
    cc.tool.viewManager.registView("hahaha", "hehehe", "hihihi");

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
    onLoad: function () {
        console.log("hahahahhsfassaga");
        init();
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
