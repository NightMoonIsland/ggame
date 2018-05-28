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
        eventType: null,
    },

    // use this for initialization
    onLoad: function () {
        this.eventType = new Array("sec1", "sec2", "sec3");
        
        var self = this;
        for(var i = 0; i < this.eventType.length; i++){
            cc.ggame.eventManager.addEventListener(self.eventType[i], self, self.onVarCallback);
        }
    },

    onVarCallback: function(self, varName) {
        if(varName == "sec1"){
            //self.output();
            self.node.getChildByName("txthaha").getComponent(cc.Label).string = "sec = " + cc.ggame.gameVariable.sec;
        }
        else if(varName == ""){

        }
    },

    output: function(){
        console.log("wo cao ni ma ge chou hai");
    },

    // called every frame, uncomment this function to activate update callback
    // update: function (dt) {

    // },

    btnTeam: function() {
        cc.ggame.viewManager.changeView("kilie5View");
    },
});
