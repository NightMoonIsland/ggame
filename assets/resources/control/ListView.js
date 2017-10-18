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

        testList: {
            default: null,
            type: cc.ScrollView
        },
    },

    ctor: function() {
        this.updateTimer = 0;
    },

    create: function() {
    },

    ctor: function() {
        console.log(this.width + " wocao " + this.height);
    },

    // use this for initialization
    onLoad: function () {

    },

    setItemModel: function() {

    },

    setDataProvider: function() {

    },

    update (dt) {
        this.updateTimer += dt;
        if(this.updateTimer < this.updateInterval) return;
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
