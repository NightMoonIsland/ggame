// Learn cc.Class:
//  - [Chinese] http://docs.cocos.com/creator/manual/zh/scripting/class.html
//  - [English] http://www.cocos2d-x.org/docs/creator/en/scripting/class.html
// Learn Attribute:
//  - [Chinese] http://docs.cocos.com/creator/manual/zh/scripting/reference/attributes.html
//  - [English] http://www.cocos2d-x.org/docs/creator/en/scripting/reference/attributes.html
// Learn life-cycle callbacks:
//  - [Chinese] http://docs.cocos.com/creator/manual/zh/scripting/life-cycle-callbacks.html
//  - [English] http://www.cocos2d-x.org/docs/creator/en/scripting/life-cycle-callbacks.html

cc.Class({
    extends: cc.Component,

    properties: {
        // foo: {
        //     // ATTRIBUTES:
        //     default: null,        // The default value will be used only when the component attaching
        //                           // to a node for the first time
        //     type: cc.SpriteFrame, // optional, default is typeof default
        //     serializable: true,   // optional, default is true
        // },
        // bar: {
        //     get () {
        //         return this._bar;
        //     },
        //     set (value) {
        //         this._bar = value;
        //     }
        // },
    },

    // LIFE-CYCLE CALLBACKS:

    // onLoad () {},

    start () {
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

    // update (dt) {},
});
