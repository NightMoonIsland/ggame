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
        list: [],
        size: 0,
    },
    // use this for initialization
    onLoad: function () {
        console.log("worked");
    },

    asfdfsdf: function() {
        console.log("wocao");
        // console.log(typeof this.list);
        console.log("wocao");
    },

    status: function() {
        console.log("self.size1");
        console.log(this.size);
        console.log("self.size2");
    },
    //
    pushBack: function(data) {
        this.list[this.size] = data;
        this.size = this.size + 1;
    },

    clear: function(){
        this.size = 0;
    },

    getSize: function() {
        return this.size;
    },



    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
