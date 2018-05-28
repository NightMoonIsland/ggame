module.exports = function(gameObject) {
    cc.ggame = {}

    cc.game.getScene = function() {
        return cc.director.getScene();
    }

    cc.ggame.viewManager = new (require("viewManager"))();
    require("viewRegister")();

    cc.ggame.eventManager = new (require("eventManager"))();

    cc.ggame.gameVariable = require("gameVariable");
    cc.ggame.Lang = require("langZh");

    cc.ggame.config = require("config");

    cc.ggame.timeHandler = new (require("timeHandler"))();
    cc.ggame.timeHandler.init(gameObject);
    cc.ggame.timeHandler.startTimer();
};
