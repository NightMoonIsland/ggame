module.exports = {
    getScene: function() {
        return cc.director.getScene();
    },

    getCanvas: function() {
        return this.getScene().getChildByName("Canvas");
    },
}
