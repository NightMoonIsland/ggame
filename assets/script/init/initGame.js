var initGame = function(gameObject) {
    cc.ggame = {}

    cc.ggame.viewManager = new (require("viewManager"))();
    cc.ggame.viewManager.init();
    require("viewRegister")();

    cc.ggame.eventManager = new (require("eventManager"))();

    cc.ggame.gameVariable = require("gameVariable");
    cc.ggame.Lang = require("langZh");

    cc.ggame.config = require("config");

    cc.ggame.protocolInit = require("protocolInit");
    cc.ggame.protocolHandler = require("protocolHandler");

    cc.ggame.timeHandler = new (require("timeHandler"))();
    cc.ggame.timeHandler.init(gameObject);
    cc.ggame.timeHandler.startTimer();
};

module.exports = initGame;
