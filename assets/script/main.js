cc.Class({
    extends: cc.Component,

    onLoad: function () {
        (require("initFramework"))();
        (require("initGame"))(this);

        cc.ggame.viewManager.changeView("homeView");

        this.node.on('touchstart', function (event) {
            console.log('反对舒服的沙发上');
        }, this);
    },

    btnBack: function() {
        cc.ggame.viewManager.backPreview();
        if(cc.ggame.viewManager.getTopLayer()){
            console.log("exist !!!");
        }
    },
});
