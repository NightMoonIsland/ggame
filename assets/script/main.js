var fs = require("fs");

cc.Class({
    extends: cc.Component,

    onLoad: function () {
        (require("initFramework"))();
        (require("initGame"))(this);

        var prefab = cc.ggame.resManager.getPrefab("homeView");

        var funcTest = function() {
            console.log("wait B 2")
        }

        if(fs.statSync("ui").isDirectory()) {
            
        }

        cc.ggame.resManager.getPrefab("homeView", function(err, prefab){
            console.log("wait B 1");
            funcTest();
        });
        console.log("wait C");
        // cc.ggame.viewManager.changeView("homeView");

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
