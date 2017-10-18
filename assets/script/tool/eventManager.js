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
        // console.log()
        if(!target || !func) return;
        if(!this.eventListener[eventType]){
            this.eventListener[eventType] = [];
        }
        this.eventListener[eventType][target] = func;
    },

    testWorkListener: function() {
        console.log("to test listener");
        for(var key in this.eventListener["hahaha"]){
            var func = this.eventListener["hahaha"][key];
            func("hahaha");
        }
    },

    dispatchEventListener: function(eventType) {
        for(var key in this.eventListener[eventType]){
            var func = this.eventListener[eventType][key];
            func(eventType);
        }
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
