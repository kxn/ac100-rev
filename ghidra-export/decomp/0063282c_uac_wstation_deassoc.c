// func uac_wstation_deassoc @ 0063282c size=168

undefined4
uac_wstation_deassoc(undefined4 param_1,undefined1 param_2,undefined1 param_3,void *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (param_4 == (void *)0x0) {
    uVar1 = 0xffffffff;
    if ((g_wsta_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[error]%s(): %d  -> mac is null\r\n","uac_wstation_deassoc",0x573);
    }
  }
  else {
    local_14 = (uint)CONCAT11(param_2,param_3) << 0x10;
    local_18 = param_1;
    memcpy((void *)((int)&local_14 + 2),param_4,6);
    uVar1 = wsta_db_sta_deassoc(&local_18,0,0);
  }
  return uVar1;
}

