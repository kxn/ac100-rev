// func _uac_wsta_ap_disconnect @ 00632d78 size=264

undefined4 _uac_wsta_ap_disconnect(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0xc) != 3)) {
    if (g_wsta_debug == 0) {
      uVar2 = *(undefined2 *)(param_1 + 0x10);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar2 = *(undefined2 *)(param_1 + 0x10);
      }
      else {
        printf("<wsta>[debug]%s(): %d  -> _uac_wsta_ap_disconnect() begin.\r\n",
               "_uac_wsta_ap_disconnect",0x4dd);
        uVar2 = *(undefined2 *)(param_1 + 0x10);
      }
    }
    iVar1 = uac_wstation_free_all_sta_in_ap(uVar2,0);
    if (iVar1 == 0) {
      uVar4 = 0;
      if (g_wsta_debug == 0) {
        return 0;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0;
      }
      __format = "<wsta>[debug]%s(): %d  -> _uac_wsta_ap_disconnect() success.\r\n";
      uVar3 = 0x4e4;
    }
    else {
      uVar4 = 0xffffffff;
      if (g_wsta_error == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "<wsta>[error]%s(): %d  -> _uac_wsta_ap_disconnect() fail\r\n";
      uVar3 = 0x4e1;
    }
    printf(__format,"_uac_wsta_ap_disconnect",uVar3);
  }
  return uVar4;
}

