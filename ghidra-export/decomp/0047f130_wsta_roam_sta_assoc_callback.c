// func wsta_roam_sta_assoc_callback @ 0047f130 size=224

undefined4 wsta_roam_sta_assoc_callback(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_68 [8];
  int local_60;
  
  memset(auStack_68,0,0x4c);
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if (wsta_roam_err_switch != '\0') {
      printf("[WSTA_ROAM_ERROR]%s()/%d inputs error.\n","wsta_roam_sta_assoc_callback",0x143);
    }
  }
  else {
    iVar1 = wsta_roam_db_pmk_get_by_mac(param_1 + 0x68,auStack_68);
    uVar2 = 0;
    if ((((iVar1 != -1) && (local_60 != -1)) &&
        (iVar1 = uac_wservice_get_wserv_id
                           (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                            *(undefined1 *)(param_1 + 0x25)), iVar1 != -1)) && (local_60 == iVar1))
    {
      wsta_roam_db_pmk_expiretime_set(param_1 + 0x68,0);
    }
  }
  return uVar2;
}

