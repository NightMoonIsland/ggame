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
        this.container.setHandler(self);
        this.container.setRectangle(width, height)

        if(dir == cc.tool.config.Direction.VERTICAL){
            var self = this;
            this.getStartIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;
			    var interval = self.itemHeight + self.vgap;
			    var startLine = Math.floor(self.container.getCy() / interval);
			    var startIdx = startLine * self.lines + 1;
                return startIdx;
            }
            this.getEndIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;

			    var interval = self.itemHeight + self.vgap;
			    var endLine = Math.ceil((self.container.getCy() + self.height) / interval);
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
			    var startLine = Math.floor(self.container.getCx() / interval)
			    var startIdx = startLine * self.lines + 1;
                return startIdx;
            }
            this.getEndIdx = function(self){
                if(self.dp == null || self.dp.getSize() == 0)
                    return 0;
			    var interval = self.itemWidth + self.vgap;
			    var endLine = Math.ceil((self.container.getCx() + self.width) / interval)
			    var endIdx = Math.min(endLine * self.lines, self.dp.getSize());
                return endIdx;
            }
        }
    },

    setItemModel: function(item, itemWidth, itemHeight) {
        this.newItem = item;
        var self = this;
        cc.loader.loadRes(this.newItem, cc.prefab, function(){
            self.updateView();
        });
	    this.itemWidth = itemWidth
	    this.itemHeight = itemHeight
    },

    addTo: function(parent) {
        parent.addChild(this.container.node);
    },

    setDataProvider: function(dp) {
        if(!dp){
            this.dp = null;
            this.selectIdx = 0;
            this.container.setPositionC(0, 0);
            this.container.removeAllChildren();
            return
        }
        if(this.dp != dp){
            this.dp = dp;
            this.selectIdx = 0;
            this.container.setPositionC(0, 0);
        }

        this.startIdx = null;
        this.endIdx = null;
        this.container.removeAllChildren();

        var num = Math.ceil(dp.getSize() / this.lines);
        if(this.dir == cc.tool.config.Direction.VERTICAL)
            this.container.setInnerRectangle(this.itemWidth * this.lines + this.hgap * (this.lines - 1),
                            this.itemHeight * num + this.vgap * (num - 1));
        else
            this.container.setInnerRectangle(this.itemWidth * num + this.hgap * (num - 1),
                            this.itemHeight * this.lines + this.vgap * (this.lines - 1));
        this.selectIdx = Math.min(this.selectIdx, dp.getSize());
        this.updateView();
    },

    updateView: function() {
        var self        =   this;
        var startIdx    =   this.getStartIdx(self);
        var endIdx      =   this.getEndIdx(self);

        if(startIdx == 0 && endIdx == 0){
            this.container.removeAllChildren();
            return;
        }

        var childIdx = 0;
        var renderer = null;
        var renderers = this.container.getChildren();

        var prefab = cc.loader.getRes(this.newItem, cc.Prefab);
        if(!prefab) return;

        if(this.startIdx != startIdx || this.endIdx != endIdx){
            this.startIdx = startIdx;
            this.endIdx = endIdx;

            var childNum = renderers.length;
            for(var i = startIdx - 1; i <= endIdx - 1; i++){
                if(childIdx < childNum){
                    renderer = renderers[childIdx].getComponent('xxxRenderer');
                }
                else{
                    let item = cc.instantiate(prefab);
                    renderer = item.getComponent('xxxRenderer');
                    this.container.getNode().addChild(item);
                    renderers[childIdx] = item;
                }
                renderer.setData(this.dp.at(i), childIdx);
                childIdx = childIdx + 1;
            }
        }

        for(var i = childIdx; i < childNum; i++){
            renderer = renderers[childIdx].getComponent('xxxRenderer');
        }

        childIdx = 0;
        renderers = this.container.getChildren();
        var r = 0, c = 0, posx = 0, posy = 0;
        for(var i = startIdx - 1; i <= endIdx - 1; i++){
            //renderer = renderers[childIdx].getComponent('xxxRenderer');

            if(this.dir == cc.tool.config.Direction.VERTICAL){
                r = Math.floor(i / this.lines);
                c = i % this.lines;
            }
            else{
                r = i % this.lines;
                c = Math.floor(i / this.lines);
            }
            posx = c * (this.itemWidth + this.hgap);
            posy = r * (this.itemHeight + this.vgap) + this.itemHeight;

            posx = posx - this.container.getCx();
            posy = this.height - (posy - this.container.getCy());
            renderers[childIdx].setPosition(cc.v2(posx, posy));
            childIdx = childIdx + 1;
        }
    },

    addEventListener: function(callback){
        this.callback = callback;
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
