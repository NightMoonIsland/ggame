var baseView = require("baseView");
cc.Class({
    extends: baseView,

    properties: {
    },

    ctor: function() {
        console.log("ctor finished");  
    },

    onLoad: function () {
        console.log("onload start");
        this.initView();
        // var widget = this.node.getChildByName("btnAddBox").getComponent(cc.Widget);
        // widget.target = cc.game.getScene().getChildByName("Canvas");

        // var self = this;
        // this.node.on('touchstart', function(event){
        //     console.log("mouse down" + event.getLocationX() + " --- " + event.getLocationY());
        //     var pos = self.node.convertToNodeSpace(event.getLocation())
        //     console.log("local position = " + pos.x + " _ _ " + pos.y);
        //     event.stopPropagation();
        // }, this);

        // this.node.on('touchend', function(event){
        //     console.log("mouse up");
        //     event.stopPropagation();
        // }, this);

        // this.node.on('mouseleave', function(event){
        //     console.log("leave");
        //     event.stopPropagation();
        // }, this);

        // this._super();
    },

    onClickEvent: function(event, customEventData){
        console.log("");
        var cbname = event.getCurrentTarget().name;
        var tagName = customEventData;
        if(tagName == ""){

        }
        else if(tagName == "") {

        }
        console.log(customEventData);
    },
});
