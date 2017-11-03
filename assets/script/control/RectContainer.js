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
        this.node.addComponent(cc.Layout);

        console.log(this.node.height + "---" + this.node.width);
        this.node.on('touchstart', function(event){
            console.log("mouse down");
            event.stopPropagation();
        }, this);

        this.node.on('touchend', function(event){
            
            console.log("mouse up");
            event.stopPropagation();
        }, this);
    },

    setRectangle: function(width, height) {
        this.node.width = width;
        this.node.height = height;
    },

    moveTo: function(x, y) {
        if(this.cx != x || this.cy != y){
            // this.cx = Math.max(0, Math.min())
        }
    },

    moveBy: function(x, y) {

    },

    // use this for initialization
    onLoad: function () {

    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
