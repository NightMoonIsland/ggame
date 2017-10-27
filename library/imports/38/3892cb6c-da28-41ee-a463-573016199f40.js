"use strict";
cc._RF.push(module, '3892cts2ihB7qRjVzAWGZ9A', 'TopLayer');
// script/module/initui/TopLayer.js

'use strict';

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

    // use this for initialization
    onLoad: function onLoad() {
        this.node.on('mousedown', function (event) {
            console.log('Mouse down');
        }, this);
    }

});

cc._RF.pop();