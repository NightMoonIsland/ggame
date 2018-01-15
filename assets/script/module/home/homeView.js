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
        console.log("is Loaded");
        var self = this;
        this.node.on('touchstart', function(event){
            console.log("mouse down" + event.getLocationX() + " --- " + event.getLocationY());
            var pos = self.node.convertToNodeSpace(event.getLocation())
            console.log("local position = " + pos.x + " _ _ " + pos.y);
            event.stopPropagation();
        }, this);

        this.node.on('touchend', function(event){
            console.log("mouse up");
            event.stopPropagation();
        }, this);

        // this.node.on('mousemove', function(event){
        //     var delta = event.getDelta();
        //     console.log(delta.x + "-----" + delta.y);
        //     event.stopPropagation();
        // }, this);

        this.node.on('mouseleave', function(event){
            console.log("leave");
            event.stopPropagation();
        }, this);

    },

    ctor: function(){
        console.log("is ctor");
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    onWorkAddBox: function(){
        cc.ggame.viewManager.addBox("ui/ceshiBox");
    },

    onDestroy: function() {
        console.log("is Destory");
    }
});
