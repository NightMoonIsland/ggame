var MAX_TIP_NUM = 5;

cc.Class({
    extends: cc.Component,

    properties: {
        tipTrashPool: null,
    },

    ctor: function () {
        this.node = new cc.Node();
        this.node.width = 1120;
        this.node.height = 1120;

        this.node.anchorX = 0.5;
        this.node.anchorY = 0.5;

        this.swallowTouchEnabled = false

        //click anim
        this.newFunction();

        

        cc.loader.loadRes("ui/click", cc.prefab,function(err, prefab){
            console.log("load click suceesss");
        });
        

        //tip anim
        this.tipTrashPool = new (require("array1"))();
        cc.loader.loadRes("ui/simpleTip", cc.prefab, function(err, prefab){
            console.log("load simpleTip suceesss");
        });
        this.tipNum = 0;
    },

    oldFunction: function() {
        var self = this;
        var listener = {
            event: cc.EventListener.TOUCH_ONE_BY_ONE,
            onTouchBegan: function(touch, event){
                console.log("touch began");
                self.listenerCallBack.setSwallowTouches(self.swallowTouchEnabled);
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
                self.listenerCallBack.setSwallowTouches(self.swallowTouchEnabled);
            },
            // onTouchCancelled: function(touch, event){
            //     console.log("touch cancel");
            //     self.listenerCallBack.setSwallowTouches(false);
            // },
        }
        self.listenerCallBack = cc.eventManager.addListener(listener, self.node)
    },

    newFunction: function() {
        // var listener = cc.EventListener.create({
        //     event: cc.EventListener.TOUCH_ONE_BY_ONE,
        //     onKeyPressed: function (keyCode, event) {
        //         cc.log('pressed key: ' + keyCode);
        //     },
        //     onKeyReleased: function (keyCode, event) {
        //         cc.log('released key: ' + keyCode);
        //     }
        // });

        // console.log("new A");
        // var listener = new EventListeners();
        // listener.add(cc.Node.EventType.TOUCH_END, function(event){
        //     console.log("touch ended");
        // });
        // console.log("new B");
        // this.node._addEventFlag(cc.Node.EventType.TOUCH_END, listener);
        // console.log("new C");

        // this.node._addEventFlag(cc.EventListener.TOUCH_ONE_BY_ONE, listener);

        // this.node.setSwallowTouches(false);
        var self = this;
        this.node.on("touchend", function (event) {
            var prefab = cc.loader.getRes("ui/click", cc.Prefab);
            if(prefab){
                let item = cc.instantiate(prefab);
                var pos = self.node.convertToNodeSpace(event.touch.getLocation());
                item.setPosition(pos.x - self.node.width / 2, pos.y - self.node.height / 2);
                self.node.addChild(item);
            }

            var endEvent = new cc.Event.EventTouch(event.getTouches(), event.bubbles);
            endEvent.type = "touchend";
            endEvent.touch = event.touch;
            endEvent.simulate = true;
            var view = cc.ggame.globalHandler.getCanvas().getChildByName("view");
            if(view) {
                console.log(view.childrenCount);
                view.getComponent("homeView").dispatchEvent(endEvent);
            }
            // cc.ggame.globalHandler.getCanvas().dispatchEvent(endEvent);
            cc.log("this is callback");
        }, this.node);

        // console.log("touchEnd = ", touchEnd);
        // console.log("can gogo1");
        // touchEnd.setSwallowTouches(this.swallowTouchEnabled);
        // console.log("can gogo2");
    },

    generateTipNode: function() {
        if(this.tipTrashPool.getSize() > 0){
            for(var i = 0; i < this.tipTrashPool.getSize(); i++){
                var tipNode = this.tipTrashPool.at(i);
                tipNode.removeFromParent();
            }
            this.tipTrashPool.clear();
        }

        var prefab = cc.loader.getRes("ui/simpleTip", cc.Prefab);
        if(prefab) {
            let tipNode = cc.instantiate(prefab);
            return tipNode;
        }
        else{
            return null;
        }
    },

    addTip: function(tip) {
        var tipNode = this.generateTipNode();
        if(tipNode){
            this.tipNum = this.tipNum + 1;
            var label = tipNode.getChildByName("txt").getComponent(cc.Label);
            label.string = tip;
            tipNode.setPosition(0, (1 - this.tipNum) * 41 + 200);
            this.node.addChild(tipNode);

            var self = this;
            var actDisappear = cc.sequence(
                cc.delayTime(1.0),
                cc.fadeOut(0.5),
                cc.callFunc(function(){
                    console.log("fade out finished");
                    self.tipNum = self.tipNum - 1;
                    self.tipTrashPool.pushBack(tipNode);
                }, tipNode)
            )
            tipNode.runAction(actDisappear);
        }
    },

    addBusyCount: function() {

    },

    removeBusyCount: function() {

    },
});
