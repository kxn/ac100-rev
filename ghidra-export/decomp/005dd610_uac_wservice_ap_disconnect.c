// func uac_wservice_ap_disconnect @ 005dd610 size=296

void uac_wservice_ap_disconnect(int param_1,undefined4 param_2)

{
  int iVar1;
  size_t __n;
  uint uVar2;
  uint uVar3;
  void *__s;
  
  if ((-1 < param_1) && (iVar1 = apmngr_db_get_ap_max(), param_1 < iVar1)) {
    iVar1 = param_1 * 0xc;
    FUN_004082d0(DAT_007598e4,0xffffffff);
    *(undefined1 *)(DAT_007598e8 + iVar1) = 0xff;
    *(undefined1 *)(DAT_007598e8 + iVar1 + 1) = 0xff;
    *(undefined1 *)(DAT_007598e8 + iVar1 + 2) = 0;
    *(undefined1 *)(DAT_007598e8 + iVar1 + 3) = 0;
    *(undefined1 *)(DAT_007598e8 + iVar1 + 4) = 0;
    for (uVar3 = 0; uVar2 = rdmngr_profile_get_max_rd_per_ap(), uVar3 < uVar2; uVar3 = uVar3 + 1) {
      __s = *(void **)(*(int *)(DAT_007598e8 + iVar1 + 8) + uVar3 * 4);
      __n = rdmngr_profile_get_max_wlan_per_rd();
      memset(__s,0,__n);
    }
    FUN_00407f30(DAT_007598e4);
  }
  wserv_db_ap_disconnect(param_1,param_2);
  return;
}

