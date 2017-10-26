//就像lua那边的netprotocol/init.lua
var protocol = [];

protocol.tmReq = [];
protocol.tmReq = {
    [0]:"msg_buy_req",
    [1]:"msg_login_req",
    [2]:"msg_login_req",
};

protocol.tmRes = [];
var tmRes = protocol.tmRes;
tmRes[0] = "msg_buy_res";
tmRes[1] = "msg_login_res";
tmRes[2] = "msg_pvp_res";

console.log("length " + protocol.tmRes.length);

module.exports = protocol;