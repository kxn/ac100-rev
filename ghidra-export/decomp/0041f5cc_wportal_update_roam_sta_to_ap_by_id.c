// func wportal_update_roam_sta_to_ap_by_id @ 0041f5cc size=576

undefined4 wportal_update_roam_sta_to_ap_by_id(uint param_1,void *param_2,undefined4 param_3)

{
  undefined4 *__s;
  undefined4 uVar1;
  undefined1 uVar3;
  int iVar2;
  undefined1 auStack_28 [20];
  
  if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Update roam sta entry to ap: %d, len = %d\n",
           "wportal_update_roam_sta_to_ap_by_id",0x3589,param_1,0x24);
  }
  __s = (undefined4 *)FUN_00408450(0x24,0x358c);
  uVar1 = 0xffffffff;
  if (__s != (undefined4 *)0x0) {
    memset(__s,0,0x24);
    *__s = param_3;
    __s[2] = 1;
    memcpy(__s + 6,param_2,6);
    if (wportal_debug_switch == 0) {
      uVar3 = *(undefined1 *)((int)param_2 + 6);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        uVar3 = *(undefined1 *)((int)param_2 + 6);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d rStaEntry.mac: %02x:%02x:%02x:%02x:%02x:%02x\n",
               "wportal_update_roam_sta_to_ap_by_id",0x359c,(uint)*(byte *)(__s + 6),
               (uint)*(byte *)((int)__s + 0x19),(uint)*(byte *)((int)__s + 0x1a),
               (uint)*(byte *)((int)__s + 0x1b),(uint)*(byte *)(__s + 7),
               (uint)*(byte *)((int)__s + 0x1d));
        uVar3 = *(undefined1 *)((int)param_2 + 6);
      }
    }
    *(undefined1 *)((int)__s + 0x1e) = uVar3;
    *(undefined1 *)((int)__s + 0x1f) = *(undefined1 *)((int)param_2 + 7);
    __s[8] = *(undefined4 *)((int)param_2 + 8);
    if (wportal_debug_switch == 0) {
      iVar2 = __s[8];
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = __s[8];
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d roamSta->vlan_id=%d\n","wportal_update_roam_sta_to_ap_by_id",
               0x35a0,*(undefined4 *)((int)param_2 + 8));
        iVar2 = __s[8];
      }
    }
    if (iVar2 == 0) {
      iVar2 = 0xfff;
    }
    __s[8] = iVar2;
    if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d pTempEntry->vlan_id=%d, rd_id:%d, needAuth:%d\n",
             "wportal_update_roam_sta_to_ap_by_id",0x35a2,__s[8],(uint)*(byte *)((int)__s + 0x1e),
             (uint)*(byte *)((int)__s + 0x1f));
    }
    serv_wtp_address_arg_init(auStack_28);
    apmngr_db_get_addr_by_capacity(param_1 & 0xffff,auStack_28,1,1,0x15f0000,0);
    uVar1 = _wportal_update_to_ap(__s,0x24,auStack_28,0);
    FUN_00407df0(__s);
    serv_wtp_address_arg_destroy(auStack_28);
  }
  return uVar1;
}

