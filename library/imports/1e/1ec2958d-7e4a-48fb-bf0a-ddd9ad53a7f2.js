"use strict";
cc._RF.push(module, '1ec29WNfkpI+78K3dmtU6fy', 'listView');
// script/control/listView.js

"use strict";

cc.Class({
    extends: cc.Layout,

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

    create: function create() {},

    ctor: function ctor() {
        console.log(this.width + " wocao " + this.height);
    },

    // use this for initialization
    onLoad: function onLoad() {}

});

cc._RF.pop();