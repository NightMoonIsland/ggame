cc.Class({
    extends: cc.Component,

    properties: {
        count: 0,
    },

    onLoad: function () {
        (require("initFramework"))();
        (require("initGame"))(this);


        console.log(cc.ggame.Lang["ITEM_VALUE"]);

        cc.ggame.viewManager.changeView("homeView");

        this.node.on('touchstart', function (event) {
            console.log('反对舒服的沙发上');
        }, this);
    },

    updateTime: function() {
        console.log("this.count = " + this.count);
        this.count = this.count + 1;
        cc.ggame.gameVariable.sec = cc.ggame.gameVariable.sec + 1;
    },

    testFunc: function() {
        var str1 = "helloword";
        this.helloword = function(){
            console.log("wotefunck");
        }
        this[str1]();
    },

    initScene: function() {

    },

    testRemove: function() {
        
    },

    btnBack: function() {
        cc.ggame.viewManager.backPreview();
        if(cc.ggame.viewManager.getTopLayer()){
            console.log("exist !!!");
        }
    },
});
