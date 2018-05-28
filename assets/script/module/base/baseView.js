var baseNode = require("baseNode");

cc.Class({
    extends: baseNode,
    properties: {
    },

    initView() {
        console.log("init View");

        //控件 适配 对齐
        for(var i = 0; i < this.node.childrenCount; i++) {
            var child = this.node.children[i];
            if(child) {
                var widget = child.getComponent(cc.Widget);
                if(widget != null) {
                    widget.target = cc.game.globalHandler.getCanvas();
                }
            }
        }
    },

    onLoad() {
        console.log("baseView");
        this._super();
    },
});
