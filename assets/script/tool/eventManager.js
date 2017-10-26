var array1 = require("array1")
var test = require("test")

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
        eventListener: [],
    },

    // use this for initialization
    onLoad: function () {
        
    },

    init: function() {
        this.super.testWork();
    },

    testWork: function() {
        console.log("zenme hui zheyang");
    },

    addEventListener: function(eventType, target, func) {
        target.output();
        // console.log()
        if(!target || !func) return;
        if(!this.eventListener[eventType]){
            this.eventListener[eventType] = new array1();
        }
        this.eventListener[eventType].pushBack({target:target, func:func});
    },

    testWorkListener: function() {
        console.log("to test listener");
        for(var key in this.eventListener["hahaha"]){
            var func = this.eventListener["hahaha"][key];
            func("hahaha");
        }
    },

    dispatchEventListener: function(eventType) {
        console.log("eventType");
        this.eventListener[eventType].excuteWithFunc(function(item, index){
            var func = item.func;
            var target = item.target;
            func(target, eventType);
        })
        // for(var key in this.eventListener[eventType]){
        //     var func = this.eventListener[eventType][key];
        //     func(key, eventType);
        // }
    },

    VAR_CHANGE: function(varName){
        this.dispatchEventListener(varName);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
