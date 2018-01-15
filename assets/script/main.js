function initGame(self){
    cc.ggame = {}

    cc.ggame.viewManager = new (require("viewManager"))();
    cc.ggame.viewManager.init();
    require("viewRegister")();

    cc.ggame.eventManager = new (require("eventManager"))();

    cc.ggame.gameVariable = require("gameVariable");
    cc.ggame.Lang = require("langZh");

    cc.ggame.config = require("config");

    cc.ggame.protocolInit = require("protocolInit");
    cc.ggame.protocolHandler = require("protocolHandler");

    cc.ggame.timeHandler = new (require("timeHandler"))();
    cc.ggame.timeHandler.init(self);
    cc.ggame.timeHandler.startTimer();
}

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
        haha: [],
        count: 0,
    },

    // use this for initialization
    onLoad: function () {
        var self = this;
        initGame(self);

        this.node.on('touchstart', function (event) {
            console.log('反对舒服的沙发上');
        }, this);

        // var self = this;
        // cc.loader.loadRes("control/ListView", cc.Prefab, function(err, prefab){
        //     // cc.ggame.prefab.listView = prefab;
        //     console.log("type prefab = " + typeof prefab)

        //     var root = cc.instantiate(prefab);
        //     root.setPosition(cc.v2(0, 0));
        //     let listView = root.getChildByName("view").getChildByName("content").getComponent("ListView");
        //     listView.create(cc.ggame.config.Direction.HORIZONTAL, 1, 1, 1, 240, 150);
        //     listView.setItemModel("control/Renderer", 160, 60);

        //     var array = require("array1");
        //     var test = new array();
        //     for(i = 0; i < 5; i++){
        //         test.pushBack(i + 100)
        //     }

        //     listView.setDataProvider(test);


        //     self.node.addChild(root);
        // });

        //暂时不用定时器
        // this.schedule(function(){
        //     this.updateTime();
        // }, 1);
    },

    updateTime: function() {
        console.log("this.count = " + this.count);
        this.count = this.count + 1;
        // cc.ggame.eventManager.VAR_CHANGE("sec1");
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
        // let text = this.node.getChildByName("paomadeng").getChildByName("hello");
        // text.setPosition(cc.p(400, 0));
        // var seq = cc.sequence(cc.callFunc(function(){
        //                             console.log("AAAAAA");
        //                         }),
        //                         cc.moveTo(1, cc.p(0, 0)), 
        //                         cc.callFunc(function(){
        //                             console.log("BBBBBB");
        //                         }),
        //                         cc.delayTime(1), 
        //                         cc.moveTo(1, cc.p(-400, 0)));
        //                         cc.callFunc(function(){
        //                             console.log("CCCCCC");
        //                         }),
        // text.runAction(seq);
        cc.ggame.viewManager.changeView("homeView");
        // cc.ggame.viewManager.addBox("ui/ceshiBox");
    },

    btnBack: function() {
        cc.ggame.viewManager.backPreview();
        if(cc.ggame.viewManager.getTopLayer()){
            console.log("exist !!!");
        }
        // var test = new (require("array1"))()
        // for(var i = 0; i < 30; i++){
        //     var data = {};
        //     data.num = i;
        //     test.pushBack(data);
        // }

        // var listview = new (require("ListView0"))();
        // listview.create(cc.ggame.config.Direction.VERTICAL, 2, 2, 2, 205, 222);
        // listview.setItemModel("ui/xxxRenderer", 100, 20);
        // listview.setDataProvider(test);
        // listview.addTo(this.node);
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
