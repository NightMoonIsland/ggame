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

    dispatchEvent(event) {
        this.dispatchEventToAll(this.node, event, 0);
    },

    dispatchEventToAll(node, event, ceng) {
        if(!node){ 
            return;
        }
        else{
            var str = "";
            for(var i=0; i < ceng; i++) str = str + " ";
            console.log("node name = " + str, node.name);
            node.dispatchEvent(event);
        }
        for(var i = 0; i < node.childrenCount; i++) {
            this.dispatchEventToAll(node.children[i], event, ceng + 1);
        }
    }
});
