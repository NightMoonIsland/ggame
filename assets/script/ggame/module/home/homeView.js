var baseView = require("baseView");
cc.Class({
    extends: baseView,

    properties: {
    },

    onLoad: function () {
        this.initView();
    },

    onClickEvent: function(event, customEventData){
        console.log("");
        console.log(event.type);
        var cbname = event.getCurrentTarget().name;
        var tagName = customEventData;
        if(tagName == "test"){
            console.log("clicked")
        }
        else if(tagName == "") {

        }
        console.log(customEventData);
    },
});
