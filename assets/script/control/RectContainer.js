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
        var mask = this.node.addComponent(cc.Mask);
        mask.type = cc.Mask.Type.RECT;

        this.node.anchorX = 0;
        this.node.anchorY = 0;

        console.log(this.node.height + "---" + this.node.width);

        var self = this;
        this.node.on('touchstart', function(event){
            self.onTouchBegan(event, self);
            event.stopPropagation();
        }, this);

        this.node.on('touchmove', function(event){
            self.onTouchMoved(event, self);
            event.stopPropagation();
        }, this);

        this.node.on('touchend', function(event){
            self.onTouchEnded(event, self);
            event.stopPropagation();
        }, this);
    },

    onTouchBegan: function(event, self) {
        console.log("mouse down");
        var scheduler = cc.director.getScheduler();
        scheduler.unscheduleUpdate(self);
    },

    onTouchMoved: function(event, self) {
        console.log("mouse moved!!");
        this.delta = event.getDelta();
        this.moveBy(this.delta.x, this.delta.y);
    },

    onTouchEnded:function(event, self) {
        console.log("mouse up");
        var scheduler = cc.director.getScheduler();
        scheduler.scheduleUpdate(self, 0, false, function(dt){
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
        console.log("this.innerWidth = " + this.innerWidth);
        console.log("this.innerHeight = " + this.innerHeight);
        console.log(x + "---delta---" + y);
        console.log(this.cx + "---cxcy---" + this.cy);
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

    setInnerRectangle: function(width, height) {
        this.innerWidth = width;
        this.innerHeight = height;
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
        var scheduler = cc.director.getScheduler();
        if(Math.abs(this.moveSpeed) < 1){
            scheduler.unscheduleUpdate(self);
        }

        if(this.moveDir == cc.tool.config.Direction.VERTICAL){
            this.moveBy(0, this.moveSpeed);
            if((this.cy >= this.innerHeight - this.node.height) ||
                this.cy <= 0)
                scheduler.unscheduleUpdate(self);
        }
        else{
            this.moveBy(this.moveSpeed, 0);
            if((this.cx >= this.innerWidth - this.width) || 
                this.cx <= 0)
                scheduler.unscheduleUpdate(self);
        }
    },

    setPositionC: function(x, y){
        this.cx = x; this.cy = y;
    },

    getCx: function() {
        return this.cx;
    },

    getCy: function() {
        return this.cy;
    },

    setHandler: function(self) {
        this.handler = self;
    },

    getNode: function() {
        return this.node;
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
