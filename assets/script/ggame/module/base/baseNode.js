cc.Class({
    extends: cc.Component,


    onLoad() {
        var self = this;
        this.node.on('touchstart', function(event){
            console.log("mouse down" + event.getLocationX() + " --- " + event.getLocationY());
            var pos = self.node.convertToNodeSpace(event.getLocation());
            event.stopPropagation();
        }, this);

        this.node.on('touchend', function(event){
            console.log("mouse up");
            event.stopPropagation();
        }, this);

        this.node.on('mouseleave', function(event){
            console.log("leave");
            event.stopPropagation();
        }, this);

        console.log("baseNode");
        this.initNode();
    },
});
