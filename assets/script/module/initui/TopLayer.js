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
        cc.loader.loadRes("ui/Click", cc.prefab,function(err, prefab){
            console.log("load suceesss");
        });
        // this.node.on('touchstart', function (event) {
        // }, this);

        this.node.on('touchend', function(event){
            console.log("touch end");
            var pos = self.node.convertToNodeSpace(event.getLocation())
            var prefab = cc.loader.getRes("ui/Click", cc.Prefab);
            if(prefab){
                let item = cc.instantiate(prefab);
                item.setPosition(event.getLocationX() - 480, event.getLocationY() - 320);
                self.node.addChild(item);
            }
        }, this);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
