// func uac_profile_get_string @ 0051ed74 size=616

undefined4 uac_profile_get_string(int param_1,int param_2,char *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char *__format;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (param_3 == (char *)0x0) {
    return 0xffffffff;
  }
  if ((int)param_4 < 1) {
    return 0xffffffff;
  }
  iVar1 = luaL_newstate();
  if (iVar1 == 0) {
    puts("[profile]Create Lua handle failed");
    return 0xffffffff;
  }
  luaL_openlibs(iVar1);
  iVar2 = luaL_loadstring(iVar1,
                          "local uci = require \"luci.model.uci\" local uci_r = uci.cursor() function uac_get_profile(section, option)\t\treturn uci_r:get_profile(section, option) end\t\t\t\t\t\t\t\t"
                         );
  if ((iVar2 == 0) && (iVar2 = lua_pcall(iVar1,0,0xffffffff,0), iVar2 == 0)) {
    lua_getfield(iVar1,0xffffd8ee,"uac_get_profile");
    lua_pushstring(iVar1,param_1);
    lua_pushstring(iVar1,param_2);
    iVar2 = lua_pcall(iVar1,2,1,0);
    if (iVar2 == 0) {
      iVar2 = lua_isstring(iVar1,0xffffffff);
      if (iVar2 != 0) {
        pcVar3 = (char *)lua_tolstring(iVar1,0xffffffff,0);
        sVar4 = strlen(pcVar3);
        if (sVar4 < param_4) {
          uVar5 = 0;
          strcpy(param_3,pcVar3);
        }
      }
      goto LAB_0051ee4c;
    }
    pcVar3 = (char *)luaL_checklstring(iVar1,0xffffffff,0);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "Unknown error";
      __format = "[profile]Run pcall failed, err=%s\n";
    }
    else {
      __format = "[profile]Run pcall failed, err=%s\n";
    }
  }
  else {
    pcVar3 = (char *)luaL_checklstring(iVar1,0xffffffff,0);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "Unknown error";
    }
    __format = "[profile]Run script failed, err=%s\n";
  }
  uVar5 = 0xffffffff;
  printf(__format,pcVar3);
LAB_0051ee4c:
  lua_settop(iVar1,0);
  lua_close(iVar1);
  return uVar5;
}

