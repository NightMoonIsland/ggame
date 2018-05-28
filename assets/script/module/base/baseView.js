var baseNode = require("baseNode");

cc.Class({
    extends: baseNode,
    properties: {
    },

    initView() {
        console.log("init View");
        this.node.getChildren();
        for(var i = 0; i < this.node.childrenCount; i++) {
            var child = this.node.children[i];
            if(child) {
                console.log("child name = " + child.name);
                var widget = child.getComponent(cc.Widget);
                if(widget != null) {
                    widget.target = cc.game.getScene().getChildByName("Canvas");
                    console.log("child name = " + child.name);
                }
            }
        }
    },

    onLoad() {
        //对齐 场景
        // this.node.getChildren();
        // for(var i = 0; i < this.node.childrenCount; i++) {
        //     var child = this.node.children[i];
        //     if(child) {
        //         console.log("child name = " + child.name);
        //         var widget = child.getComponent(cc.Widget);
        //         if(widget != null) {
        //             widget.target = cc.game.getScene().getChildByName("Canvas");
        //             console.log("child name = " + child.name);
        //         }
        //     }
        // }
        console.log("baseView");
        this._super();
    },
});
