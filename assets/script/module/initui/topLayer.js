cc.Class({
    extends: cc.Component,

    properties: {
    },

    ctor: function () {
        this.node = new cc.Node();
        this.node.width = 1120;
        this.node.height = 1120;

        this.node.anchorX = 0.5;
        this.node.anchorY = 0.5;

        var self = this;
        cc.loader.loadRes("ui/click", cc.prefab,function(err, prefab){
            console.log("load suceesss");
        });

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

                var prefab = cc.loader.getRes("ui/click", cc.Prefab);
                if(prefab){
                    let item = cc.instantiate(prefab);
                    var pos = self.node.convertToNodeSpace(touch.getLocation());
                    item.setPosition(pos.x - 560, pos.y - 560);
                    // cc.director.getScene().addChild(item, 5);
                    self.node.addChild(item);
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
        //     var prefab = cc.loader.getRes("ui/click", cc.Prefab);
        //     if(prefab){
        //         let item = cc.instantiate(prefab);
        //         // item.setPosition(event.getLocationX() - 480, event.getLocationY() - 320);
        //         // self.node.addChild(item);
        //         item.setPosition(event.getLocationX(), event.getLocationY());
        //         cc.director.getScene().addChild(item, 5);
        //     }
        // }, this);
    },
});
