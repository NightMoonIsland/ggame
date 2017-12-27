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
    },

    // use this for initialization
    onLoad: function () {
        var widget = this.node.getComponent(cc.Widget);
        widget.target = cc.director.getScene().getChildByName("Canvas");
        widget.updateAlignment();
    },

    initPmdNode: function(node) {
        this.node = node;
        this.lenX = this.getRichText().width + 480;
        this.getRichText().x = this.lenX;
    },

    showNext: function() {
        console.log("show next");
        var self = this;
        this.getRichText().x = this.lenX;
        var action = cc.sequence(cc.moveTo(3, 0, 0), cc.callFunc(function(){
            console.log("wota fucnk");
        }, self), cc.delayTime(2), cc.moveTo(3, -this.lenX, 0));
        this.getRichText().runAction(action);
    },

    getRichText: function() {
        return this.node.getChildByName("mask").getChildByName('richText');
    }

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
