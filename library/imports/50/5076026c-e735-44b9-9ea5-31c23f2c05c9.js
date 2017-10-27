"use strict";
cc._RF.push(module, '50760Js5zVEuZ6lMcI/LAXJ', 'protocolHandler');
// script/netprotocol/protocolHandler.js

"use strict";

//就像lua里的Casefunc
var _ = [];

_.msg_buy_res = function (res) {};
_.msg_login_res = function (res) {};
_.msg_pvp_res = function (res) {
    console.log("res's text = " + res.text);
};

module.exports = _;

cc._RF.pop();