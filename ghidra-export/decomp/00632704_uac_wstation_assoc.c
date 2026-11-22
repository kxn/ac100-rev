// func uac_wstation_assoc @ 00632704 size=296

undefined4
uac_wstation_assoc(undefined4 param_1,undefined1 param_2,undefined1 param_3,void *param_4,
                  undefined1 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  int param_9)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_a0 [32];
  undefined4 local_80;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 auStack_72 [7];
  undefined1 local_6b;
  undefined1 auStack_38 [28];
  
  uVar2 = 0xffffffff;
  memset(auStack_a0,0,0x80);
  if ((param_4 != (void *)0x0) && (param_9 != 0)) {
    local_6b = param_5;
    local_80 = param_1;
    local_7c = param_2;
    local_7b = param_3;
    memcpy(auStack_38,param_4,6);
    iVar1 = uac_wservice_get_vlan(param_1,param_2,param_3,auStack_72);
    if (iVar1 == 0) {
      uVar2 = wsta_db_sta_assoc(auStack_a0,param_6,_uac_wsta_implicit_del_cb,0,param_7,param_8,
                                param_9);
    }
    else if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> uac_wservice_get_vlan() fail\r\n","uac_wstation_assoc",0x567
            );
    }
  }
  return uVar2;
}

