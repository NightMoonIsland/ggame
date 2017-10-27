"use strict";
cc._RF.push(module, '28590V+IBZHjKbwC7JY9Daj', 'protocolInit');
// script/netprotocol/protocolInit.js

"use strict";

var _protocol$tmReq;

function _defineProperty(obj, key, value) { if (key in obj) { Object.defineProperty(obj, key, { value: value, enumerable: true, configurable: true, writable: true }); } else { obj[key] = value; } return obj; }

//就像lua那边的netprotocol/init.lua
var protocol = [];

protocol.tmReq = [];
protocol.tmReq = (_protocol$tmReq = {}, _defineProperty(_protocol$tmReq, 0, "msg_buy_req"), _defineProperty(_protocol$tmReq, 1, "msg_login_req"), _defineProperty(_protocol$tmReq, 2, "msg_login_req"), _protocol$tmReq);

protocol.tmRes = [];
var tmRes = protocol.tmRes;
tmRes[0] = "msg_buy_res";
tmRes[1] = "msg_login_res";
tmRes[2] = "msg_pvp_res";

console.log("length " + protocol.tmRes.length);

module.exports = protocol;

cc._RF.pop();