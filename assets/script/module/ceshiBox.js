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
        var self = this;
        this.node.getChildByName("bg").on('touchstart', function(event){
            self.node.removeFromParent();
            event.stopPropagation();
        }, this);
        this.node.getChildByName("bg").on('touchmove', function(event){
            event.stopPropagation();
        }, this);
        this.node.getChildByName("bg").on('mousemove', function(event){
            event.stopPropagation();
        }, this);
        this.node.getChildByName("bg").on('touchend', function(event){
            event.stopPropagation();
        }, this);

        this.node.getChildByName("box").on('touchstart', function(event){
            event.stopPropagation();
        }, this);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
