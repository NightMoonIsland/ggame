cc.Class({
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
        this.node = new cc.Node();
        this.node.addComponent(cc.Layout);

        console.log(this.node.height + "---" + this.node.width);

        var self = this;
        this.container = new (require("RectContainer"))();
        this.container.handler = self;
    },

    create: function(dir, lines, hgap, vgap, width, height) {
        this.dir = dir;
        this.lines = lines;
        this.hgap = hgap;
        this.vgap = vgap;
        this.width = width;
        this.height = height;

        var self = this;
        this.container = new (require("RectContainer"))();
        this.container.handler = self;
        this.container.setRectangle(width, height)

        if(dir == cc.tool.config.VERTICAL){
            var self = this;
            this.getStartIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;
			    var interval = self.itemHeight + self.vgap;
			    var startLine = Math.floor(self.container.cy / interval);
			    var startIdx = startLine * self.lines + 1;
                return startIdx;
            }
            this.getEndIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;
			    var interval = self.itemHeight + self.vgap;
			    var endLine = Math.ceil((self.container.cy + self.height) / interval);
			    var endIdx = Math.min(endLine * self.lines, self.dp.getSize());
                return endIdx;
            }
        }
        else if(dir == cc.tool.config.HORIZONTAL){
            var self = this;
            this.getStartIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;
			    var interval = self.itemWidth + self.vgap;
			    var startLine = Math.floor(self.container.cx / interval)
			    var startIdx = startLine * self.lines + 1;
                return startIdx;
            }
            this.getEndIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;
			    var interval = self.itemWidth + self.vgap;
			    var endLine = Math.ceil((self.container.cx + self.width) / interval)
			    var endIdx = Math.min(endLine * self.lines, self.dp.getSize());
                return endIdx;
            }
        }
    },

    setItemModel: function(item, itemWidth, itemHeight) {
        this.newItem = item;
        cc.loader.loadRes(this.newItem);
	    this.itemWidth = itemWidth
	    this.itemHeight = itemHeight
    },

    addTo: function(parent, pos) {

    },

    setDataProvider: function(dp) {
        if(!dp){

        }
        if(this.dp != dp){
            this.dp = dp;
            this.selectIdx = 0;
            this.container.cx = 0;
            this.container.cy = 0;
        }

        this.startIdx = null;
        this.endIdx = null;
        this.container.removeAllChildren();
    },

    // use this for initialization
    onLoad: function () {

    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
