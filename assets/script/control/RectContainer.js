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

    ctor: function() {
        this.cx = this.cy = 0;
        this.innerWidth = 0;
        this.innerHeight = 0;
        this.moveDir = 0;
        this.moveSpeed = 0;

        this.node = new cc.Node();
        this.node.addComponent(cc.Sprite);
        this.node.addComponent(cc.Layout);
        // this.node.width = 120;
        // this.node.height = 120;
        // sprite.spriteFrame = "default-panel";

        console.log(this.node.height + "---" + this.node.width);

        
        this.node.on('touchstart', function(event){
            self.onTouchBegan(event);
            event.stopPropagation();
        }, this);

        this.node.on('touchmove', function(event){
            self.onTouchMoved(event);
            event.stopPropagation();
        }, this);

        this.node.on('touchend', function(event){
            self.onTouchEnded(event);
            event.stopPropagation();
        }, this);
    },

    onTouchBegan: function(event) {
        console.log("mouse down");
        var self = this;
        this.unscheduleUpdate(self);
    },

    onTouchMoved: function(event) {
        console.log("mouse moved!!");
        this.delta = event.getDelta();
        this.moveBy(this.delta.x, this.delta.y);
    },

    onTouchEnded:function(event) {
        console.log("mouse up");
        var self = this;
        this.scheduleUpdate(self, 0, false, function(dt){
            self.update(dt);
        })
    },

    moveTo: function(x, y){
        if(this.cx != x || this.cy != y){
            this.cx = Math.max(0, Math.min(x, this.innerWidth - this.node.width));
            this.cy = Math.max(0, Math.min(y, this.innerHeight - this.node.height));
            this.handler.updateView();
        }
    },

    moveBy: function(x, y){
        this.cx = this.cx - x;
        this.cy = this.cy + y;
        this.cx = Math.max(0, Math.min(this.cx, this.innerWidth - this.node.width));
        this.cy = Math.max(0, Math.min(this.cy, this.innerHeight - this.node.height));
        this.handler.updateView();
    },

    setRectangle: function(width, height) {
        var self = this;
        cc.loader.loadRes("pic/test", cc.SpriteFrame, function (err, spriteFrame) {
            self.node.getComponent(cc.Sprite).spriteFrame = spriteFrame;
            self.node.getComponent(cc.Sprite).type = cc.Sprite.Type.SIMPLE;
            self.node.width = width;
            self.node.height = height;
        });
        this.node.color = new cc.Color(255, 255, 255);
        
    },

    getChildren: function() {
        return this.node.children;
    },

    removeAllChildren: function() {
        this.node.removeAllChildren();
    },

    update: function(dt){
        this.moveSpeed = this.moveSpeed * 0.95;
        var self = this;
        if(Math.abs(this.moveSpeed) < 1){
            this.unscheduleUpdate(self);
        }

        if(this.moveDir == cc.tool.config.Direction.VERTICAL){
            this.moveBy(0, this.moveSpeed);
            if((this.cy >= this.innerHeight - this.node.height) ||
                this.cy <= 0)
                this.unscheduleUpdate(self);
        }
        else{
            this.moveBy(this.moveSpeed, 0);
            if((this.cx >= this.innerWidth - this.width) || 
                this.cx <= 0)
                this.unscheduleUpdate(self);
        }
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
