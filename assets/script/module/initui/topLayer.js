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

        //click anim
        var self = this;
        cc.loader.loadRes("ui/click", cc.prefab,function(err, prefab){
            console.log("load click suceesss");
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
                var prefab = cc.loader.getRes("ui/click", cc.Prefab);
                if(prefab){
                    let item = cc.instantiate(prefab);
                    var pos = self.node.convertToNodeSpace(touch.getLocation());
                    item.setPosition(pos.x - self.node.width / 2, pos.y - self.node.height / 2);
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

        //tip anim
        cc.loader.loadRes("ui/simpleTip", cc.prefab,function(err, prefab){
            console.log("load simpleTip suceesss");
        });
        this.tipNum = 0;


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

    addTip: function(tip) {

        // self.tipContainer.tipNum = self.tipContainer.tipNum + 1
        // local tipNode = cc.CSLoader:createNode("SimpleTip.csb")
        // tipNode:setCascadeOpacityEnabled(true)
        // tipNode:getChild("txt"):setString(tip)
        // tipNode:setPosition(0, (1 - self.tipContainer.tipNum) * 41)
        // self.tipContainer:addChild(tipNode)

        // local actDisappear = cc.Sequence:create(
        //     cc.DelayTime:create(1.0),
        //     cc.FadeOut:create(.5),
        //     cc.CallFunc:create(function()
        //         self.tipContainer.tipNum = self.tipContainer.tipNum - 1
        //         tipNode:removeFromParent()
        //     end)
        // )
        // tipNode:runAction(actDisappear)
        console.log("add tip worked !!!");
        var prefab = cc.loader.getRes("ui/simpleTip", cc.Prefab);
        this.tipNum = this.tipNum + 1;
        if(prefab){
            console.log("generate a new tip");
            let tipNode = cc.instantiate(prefab);
            var label = tipNode.getChildByName("txt").getComponent(cc.Label);
            label.string = tip;
            tipNode.setPosition(0, (1 - this.tipNum) * 41 + 200);
            this.node.addChild(tipNode);

            var self = this;
            var actDisappear = cc.sequence(
                cc.delayTime(1.0),
                cc.fadeOut(0.5),
                cc.callFunc(function(){
                    self.tipNum = self.tipNum - 1;
                    tipNode.removeFromParent();
                }, self)
            )
            tipNode.runAction(actDisappear);
        }
    },
});
