"use strict";
cc._RF.push(module, '977ccDhLh1BToFB9khDpdNi', 'timeHandler');
// script/process/timeHandler.js

"use strict";

var timerCount = 0;

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
        self: cc.Component },

    // use this for initialization

    ctor: function ctor() {},

    init: function init(self) {
        this.self = self;
    },

    updateTimer: function updateTimer() {
        timerCount = timerCount + 1;
        console.log("wo ca");
        console.log("test Work = " + timerCount);
    },

    startTimer: function startTimer() {
        timerCount = 0;
        this.self.schedule(this.updateTimer, 1);
    },

    stopTimer: function stopTimer() {
        timerCount = 0;
        console.log("停下!!");
        this.self.unschedule(this.updateTimer);
    },

    dosomething: function dosomething() {
        console.log("dsgfsdagvdga");
        // console.log("this.count = " + this.count);
        // this.count = this.count + 1;
    }
});

cc._RF.pop();