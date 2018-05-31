cc.Class({
    properties: {
        prefabPwd: "ui/",
    },

    setPrefabPwd: function(pwd) {
        this.prefabPwd = pwd;
    },

    getPrefab: function(name, callback) {
        console.log("wait A");
        var prefab = cc.loader.getRes(this.prefabPwd + name, cc.Prefab);
        if (prefab){
            callback(null, prefab);
        }
        else{
            cc.loader.loadRes(this.prefabPwd + name, cc.Prefab, callback);
        }
    },

    removePrefab: function(name) {
        cc.loader.releaseRes(this.prefabPwd + name);
    },
});
