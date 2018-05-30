module.exports = function() {
    cc.ggame = {}

    cc.ggame.globalHandler = require("globalHandler");
    cc.ggame.viewManager = new (require("viewManager"))();
    cc.ggame.eventManager = new (require("eventManager"))();
    cc.ggame.timeHandler = new (require("timeHandler"))();
};
