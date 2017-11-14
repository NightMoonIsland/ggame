
var ZORDER_BG = 0;
var ZORDER_ROOT = 1;
var ZORDER_VIEW = 2;
var ZORDER_BOX = 3;

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
        viewList: null,
        viewInfo: [],
        view: null,
        viewName: null,
    },

    ctor: function() {
        console.log("hhhehehe");
        var array1 = require("array1");
        this.viewList = new array1();
        // this.array1 = new require("array1");
        this.viewList.status();
        this.viewList.pushBack({a:1, b:2});
        this.viewList.status();
        
    },

    setRoot: function(node) {
        this.root = node;
    },

    // use this for initialization
    onLoad: function () {
        // console.log("hahahahha");

        // cc.variable.viewInfo.asfdfsdf();
        // console.log(typeof this.viewName);
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

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
        cc.tool.eventManager.addEventListener("hahaha", self, self.testAddChild);
        cc.tool.eventManager.testWorkListener()
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

    addBox: function(box, z = ZORDER_BOX){
        // cc.director.getScene().
        var box = new (require("testBox"))();
    },
});
