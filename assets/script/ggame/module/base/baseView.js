var baseNode = require("baseNode");

cc.Class({
    extends: baseNode,

    initView() {
        console.log("init View");

        //控件 适配 对齐
        for(var i = 0; i < this.node.childrenCount; i++) {
            var child = this.node.children[i];
            if(child) {
                var widget = child.getComponent(cc.Widget);
                if(widget != null) {
                    widget.target = cc.ggame.globalHandler.getCanvas();
                }
            }
        }
    },
});
