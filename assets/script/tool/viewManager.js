var ZORDER_BG = 0;
var ZORDER_ROOT = 1;
var ZORDER_VIEW = 2;
var ZORDER_BOX = 3;
var ZORDER_TOP = 4;

cc.Class({
    properties: {
        viewList: null,
        viewInfo: [],
        view: null,
        viewName: null,
    },

    ctor: function() {
        this.viewList = new (require("array1"))();

        this.topLayer = new (require("topLayer"))();
        cc.director.getScene().getChildByName("Canvas").addChild(this.topLayer.node, ZORDER_TOP);

        this.initRootLayer();
    },

    getTopLayer: function(){
        return this.topLayer;
    },

    initRootLayer: function() {
        cc.loader.loadRes("ui/rootLayer", cc.Prefab, function(err, prefab){
            var root = cc.instantiate(prefab);
            cc.director.getScene().getChildByName("Canvas").addChild(root, ZORDER_ROOT);
        });
    },

    setRoot: function(node) {
        this.root = node;
    },

    init: function(){
        this.viewInfo = [];
    },

    registView: function(viewName, module, title){
        this.viewInfo[viewName] = {viewName:viewName, module:module, title:title};
    },

    changeView: function(viewName){
        if(!this.viewList.empty() && this.viewList.back() == viewName){
            console.log("view is same");
            return this.view;
        }

        var viewAbout = this.viewInfo[viewName]

        var idx = this.viewList.find(viewName);
        if(idx != this.viewList.npos){
            var len = this.viewList.getSize() - idx;
            this.viewList.remove(idx + 1, len - 1);
        }
        else{
            this.viewList.pushBack(viewName);
        }
        console.log("wocao 3");

        var self = this;
        //通过链接 加载的资源 必须放在resource下
        cc.loader.loadRes(viewAbout.module, function(err, prefab){
            var root = cc.instantiate(prefab);
            cc.director.getScene().getChildByName("Canvas").addChild(root);
            if(self.view != null){
                self.view.removeFromParent();
                self.view.destroy();
                self.view = null;
            }
            self.view = root;
        });
        
        this.viewName = viewName;
        return this.view;
    },

    curView: function() {
        // this.testAddChild();
        var self = this;
        cc.ggame.eventManager.addEventListener("hahaha", self, self.testAddChild);
        cc.ggame.eventManager.testWorkListener()
        this.view.removeFromParent(false);
        cc.loader.releaseRes("prefab/Test1Panel");

        return this.view;
    },

    testAddChild: function(varName){
        if(varName == "hahaha"){
            console.log("wocao tamabi");
        }
        else if(varName = "wocaonima"){
            console.log("??? wodetian");
        }
    },

    curViewName: function(){
        return this.viewName;
    },

    backPreview: function(){
        if(this.viewList.getSize() > 0){
            this.viewList.popBack();

            var viewName = this.viewList.back();
            var viewAbout = this.viewInfo[viewName];
            if(viewAbout == null){
                if(this.view != null){
                    this.view.removeFromParent();
                    this.view.destroy();
                    this.view = null;
                }
                this.viewName = null;
                return null;
            }

            var self = this;
            cc.loader.loadRes(viewAbout.module, function(err, prefab){
                var root = cc.instantiate(prefab);
                cc.director.getScene().getChildByName("Canvas").addChild(root);
                if(self.view != null){
                    self.view.removeFromParent();
                    self.view.destroy();
                    self.view = null;
                }
                self.view = root;
            });
            this.viewName = viewName;
            return this.view;
        }
        return null;
    },

    addBox: function(boxName){
        var self = this;
        if(this.box){
            this.box.removeFromParent();
            this.box.destroy();
        }
        cc.loader.loadRes(boxName, cc.Prefab, function(err, prefab){
            var _box = cc.instantiate(prefab);
            var box = _box.getChildByName("box");
            if(box){
                box.opacity = 0;
                box.scale = 0.5;
                box.runAction(cc.spawn(cc.fadeIn(0.2), cc.scaleTo(0.2, 1).easing(cc.easeBackOut())));
                self.box = box;
            }
            cc.director.getScene().getChildByName("Canvas").addChild(_box, ZORDER_BOX);
        });
    },
});
