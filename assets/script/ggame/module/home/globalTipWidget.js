cc.Class({
    extends: cc.Component,

    properties: {

    },

    onLoad: function () {

    },

    initPmdNode: function(node) {
        this.node = node;
        this.lenX = this.getRichText().width + 480;
        this.getRichText().x = this.lenX;

        this.paomadengOn = false
    },

    showNext: function() {
        if(this.paomadengOn){
            console.log("running now!!!");
            return;
        }
        var self = this;
        this.getRichText().x = this.lenX;
        var action = cc.sequence(cc.callFunc(function(){
            self.paomadengOn = true
            console.log("paomadeng start");
        }, self), 
        cc.moveTo(3, 0, 0), 
        cc.callFunc(function(){
            console.log("wota fucnk");
        }, self), 
        cc.delayTime(2), 
        cc.moveTo(3, -this.lenX, 0),
        cc.callFunc(function(){
            self.paomadengOn = false
            console.log("paomadeng end");
        }, self));
        this.getRichText().runAction(action);
    },

    getRichText: function() {
        return this.node.getChildByName("mask").getChildByName('richText');
    }
});
