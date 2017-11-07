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
        // var self = this;
        // this.container = new (require("RectContainer"))();
        // this.container.handler = self;
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

        if(dir == cc.tool.config.Direction.VERTICAL){
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
        else if(dir == cc.tool.config.Direction.HORIZONTAL){
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

        var num = Math.ceil(dp.getSize() / this.lines);
        if(this.dir == cc.tool.config.Direction.VERTICAL){
            this.container.innerWidth = this.itemWidth * this.lines + this.hgap * (this.lines - 1);
            this.container.innerHeight = this.itemHeight * num + this.vgap * (num - 1);
        }
        else{
            this.container.innerWidth = this.itemWidth * num + this.hgap * (num - 1);
            this.container.innerHeight = this.itemHeight * this.lines + this.vgap * (this.lines - 1);
        }
        this.selectIdx = Math.min(this.selectIdx, dp.getSize());
    },

    updateView: function() {
        var self        =   this;
        var startIdx    =   this.getStartIdx(self);
        var endIdx      =   this.getendIdx(self);

        if(startIdx == 0 && endIdx == 0){
            this.container.removeAllChildren();
            return;
        }

        var childIdx = 1;
        var renderer = null;
        var renderers = this.container.getChildren();

        if(this.startIdx != startIdx || this.endIdx != endIdx){
            this.startIdx = startIdx;
            this.endIdx = endIdx;

            var childNum = renderers.length;
            for(var i = startIdx; i <= endIdx; i++){
                if(childIdx < childNum){
                    renderer = renderers[childIdx];
                    var rendererComp = renderer.getComponent('xxxRenderer');
                }
                renderer = renderers[i];
                var prefab = cc.loader.getRes(self.newItem, cc.Prefab);
            }
        }
    },

    // use this for initialization
    onLoad: function () {

    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
