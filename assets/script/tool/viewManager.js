

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
    },

    ctor: function() {
        console.log("hhhehehe");
        var array1 = require("array1");
        this.array1 = new array1();
        // this.array1 = new require("array1");
        this.array1.status();
        this.array1.pushBack({a:1, b:2});
        this.array1.status();
    },
    // use this for initialization
    onLoad: function () {
        // console.log("hahahahha");

        // cc.variable.viewList.asfdfsdf();
        // console.log(typeof this.viewName);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    init: function(){
        this.viewList = [];
    },

    changeView: function(viewName){

    },

    backPreview: function(){

    },
});
