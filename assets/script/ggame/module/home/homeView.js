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
        var cbname = event.getCurrentTarget().name;
        var tagName = customEventData;
        if(tagName == ""){
        }
        else if(tagName == "") {

        }
        console.log(customEventData);
    },
});
