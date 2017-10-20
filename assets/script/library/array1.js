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
        npos: -1,
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

    at: function(idx){
        return this.list[idx];
    },

    find: function(value){
        var index = this.npos;
        if (typeof value == "function"){
            for(i = 0; i < this.size; i++){
                if(value(i)) return i;
            }
        }
        else{
            for(i = 0; i < this.size; i++){
                if(this.list[i] == value){
                    index = i;
                    break;
                }
            }
        }
        return index;
    },

    remove: function(pos, len){
        if(pos < 0) pos = 0;
        if(len == null || len <= 0){
            len = 1;
        }
        if(pos < this.size){
            if(pos + len > this.size)
                len = this.size - pos;
            for(i = 0; i < len; i++)
                delete this.list[pos + i];
            for(i = pos + len; i < this.size; i++)
                this.list[i - len] = this.list[i];
            this.size = this.size - len;
        }
    },

    clear: function(){
        for(i = 0; i < this.size; i++)
            delete this.list[i];
        this.size = 0;
    },

    getSize: function() {
        return this.size;
    },

    empty: function() {
        return this.size == 0;
    },

    outPut: function() {
        for(i = 0; i < this.size; i++)
            console.log("element" + i + " = " + this.list[i]);
        console.log("element size = " + this.size);
    },

    excuteWithFunc: function(func) {
        for(var i = 0; i < this.size; i++){
            func(this.list[i], i);
        }
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },
});
