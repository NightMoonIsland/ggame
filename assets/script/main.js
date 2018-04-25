cc.Class({
    extends: cc.Component,

    properties: {
        count: 0,
    },

    onLoad: function () {
        (require("initGame"))(this);

        console.log(cc.ggame.Lang["ITEM_VALUE"]);

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
        cc.ggame.viewManager.changeView("homeView");
    },

    btnBack: function() {
        cc.ggame.viewManager.backPreview();
        if(cc.ggame.viewManager.getTopLayer()){
            console.log("exist !!!");
        }
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    connectTest: function() {
        // console.log("work connect");
        var socket = io.connect('10.10.30.234:9876', function(msg){
            console.log(msg);
        });
        for(var i = 0; i < cc.ggame.protocolInit.tmRes.length; i++){
            socket.on(cc.ggame.protocolInit.tmRes[i], cc.ggame.protocolHandler[cc.ggame.protocolInit.tmRes[i]]);
        }
        socket.emit('hehehaha', {abc:"wozhenderilegoule"});

        // var self = this;
        // cc.loader.loadRes("ui/ceshiBox", cc.prefab, function(err, prefab){
        //     let box = cc.instantiate(prefab);
        //     self.node.addChild(box);
        // });
        // cc.ggame.viewManager.addBox("ui/ceshiBox")
    },
});
