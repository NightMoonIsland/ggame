"use strict";
cc._RF.push(module, 'f76aaCRISVCx45YQ6l8pzov', 'ListView0');
// script/control/ListView0.js

"use strict";

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
    },

    ctor: function ctor() {
        this.node = new cc.Node();
        this.node.addComponent(cc.Layout);

        console.log(this.node.height + "---" + this.node.width);
    },

    // use this for initialization
    onLoad: function onLoad() {}

});

cc._RF.pop();