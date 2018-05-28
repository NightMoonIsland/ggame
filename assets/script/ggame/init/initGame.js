module.exports = function(gameObject) {
    require("initViewInfo")();

    cc.ggame.gameVariable = require("gameVariable");
    cc.ggame.Lang = require("langZh");

    cc.ggame.config = require("config");

    cc.ggame.timeHandler.init(gameObject);
    cc.ggame.timeHandler.startTimer();
};
