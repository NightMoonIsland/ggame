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

        var listener = {
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            onTouchBegan: function(touch, event){
                console.log("touch began");
                self.listenerCallBack.setSwallowTouches(false);
                return true;
            },
            // onTouchMoved: function(touch, event){
            //     console.log("touch move");
            //     self.listenerCallBack.setSwallowTouches(false);
            // },
            onTouchEnded: function(touch, event){
                console.log("touch end");

                var prefab = cc.loader.getRes("ui/Click", cc.Prefab);
                if(prefab){
                    let item = cc.instantiate(prefab);
                    item.setPosition(touch.getLocationX(), touch.getLocationY());
                    cc.director.getScene().addChild(item, 5);
                }

                self.listenerCallBack.setSwallowTouches(false);
            },
            // onTouchCancelled: function(touch, event){
            //     console.log("touch cancel");
            //     self.listenerCallBack.setSwallowTouches(false);
            // },
        }

        this.listenerCallBack = cc.eventManager.addListener(listener, self.node)

        // this.node.on('touchend', function(event){
        //     self.setTouchSwallow(false);
        //     console.log("touch end");
        //     var pos = self.node.convertToNodeSpace(event.getLocation())
        //     var prefab = cc.loader.getRes("ui/Click", cc.Prefab);
        //     if(prefab){
        //         let item = cc.instantiate(prefab);
        //         // item.setPosition(event.getLocationX() - 480, event.getLocationY() - 320);
        //         // self.node.addChild(item);
        //         item.setPosition(event.getLocationX(), event.getLocationY());
        //         cc.director.getScene().addChild(item, 5);
        //     }
        // }, this);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
