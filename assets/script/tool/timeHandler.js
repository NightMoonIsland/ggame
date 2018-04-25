var timerCount = 0;

cc.Class({
    extends: cc.Component,

    properties: {
        gameObject: cc.Component, //用挂载在scene上的脚本作为计时器
    },

    ctor: function() {
    },

    init: function(gameObject) {
        this.gameObject = gameObject;
    },

    updateTimer: function() {
        timerCount = timerCount + 1;
        // console.log("pass time count = " + timerCount);
    },

    startTimer: function(){
        timerCount = 0;
        this.gameObject.schedule(this.updateTimer, 1);
    },

    stopTimer: function(){
        timerCount = 0;
        console.log("停下!!");
        this.gameObject.unschedule(this.updateTimer);
    },

    dosomething: function(){
        console.log("dsgfsdagvdga");
    },
});
