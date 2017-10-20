var array1 = require("array1");

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

        scrollView: {
            default: null,
            type: cc.ScrollView
        },

        
        dir: 0, 
        lines: 0, 
        hgap: 0, 
        vgap: 0, 
        width: 0, 
        height: 0,
        

        dp: array1,
        item: cc.Prefab,
        itemPwd: null,
        itemHeight: 0,
        itemWidth: 0,
    },

    ctor: function() {
        this.updateTimer = 0;
        dp = null;
    },

    create: function(dir, lines, hgap, vgap, width, height) {
        this.dir = dir;
        this.lines = lines;
        this.hgap = hgap;
        this.vgap = vgap;
        this.width = width;
        this.height = height;


        this.node.parent.parent.width = width;
        this.node.parent.parent.height = height;
        this.node.parent.width = width;
        this.node.parent.height = height;

        // this.node.parent.parent.setContentSize(cc.Size(width, height));
        // this.node.parent.setContentSize(cc.Size(width, height));
        if(dir == cc.tool.config.Direction.HORIZONTAL){
            this.calcSection = function(self) {
                if(!self.dp || self.dp.size() == 0){
                    
                }
                var interval = self.itemHeight + self.vgap;
            };
        }
        else{
            this.calcSection = function(self) {
                if(!self.dp || self.dp.size() == 0){
                    
                }
                var interval = self.itemHeight + self.vgap;
            };
        }
    },

    ctor: function() {
        console.log(this.width + " wocao " + this.height);
    },

    // use this for initialization
    onLoad: function () {

    },

    setItemModel: function(item, itemWidth, itemHeight) {
        var self = this;

        this.itemPwd = item;
        // cc.loader.loadRes(item, cc.Prefab, function(err, prefab){
        //     // cc.tool.prefab.listView = prefab;
        //     console.log("type prefab = " + typeof prefab)
        //     self.item = prefab;
        // });
        cc.loader.loadRes(item, cc.Prefab);
        self.itemWidth = itemWidth;
        self.itemHeight = itemHeight;
    },

    setDataProvider: function(dl) {
        var self = this;

        if(this.dir == cc.tool.config.Direction.HORIZONTAL){
            this.node.height = dl.getSize() * (this.itemHeight + this.hgap) - this.hgap;
            this.node.width = this.width;
        }
        else{
            this.node.height = this.height;
        }    

        dl.excuteWithFunc(function(data, index){
            var prefab = cc.loader.getRes(self.itemPwd, cc.Prefab);

            let item = cc.instantiate(prefab).getComponent('Renderer');
            // item.setPosY(-this.itemHeight * (index + 1));
            item.setPos(0, -self.itemHeight * (index + 1));
            self.node.addChild(item.node);

            // cc.loader.getRes(self.itemPwd, cc.Prefab, function(err, prefab){
            //     let item = cc.instantiate(prefab).getComponent('Renderer');
            //     // item.setPosY(-this.itemHeight * (index + 1));
            //     item.setPos(0, -self.itemHeight * (index + 1));
            //     self.node.addChild(item.node);
            // });

            // let item = cc.instantiate(self.item).getComponent('Renderer');
            // // item.setPosY(-this.itemHeight * (index + 1));
            // item.setPos(0, -self.itemHeight * (index + 1));
            // self.node.addChild(item.node);
        });
    },

    update (dt) {
        this.updateTimer += dt;
        if(this.updateTimer < this.updateInterval) return;
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
