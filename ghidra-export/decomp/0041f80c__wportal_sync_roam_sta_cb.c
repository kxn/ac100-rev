// func _wportal_sync_roam_sta_cb @ 0041f80c size=364

undefined4 _wportal_sync_roam_sta_cb(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined1 uVar3;
  int iVar2;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  
  uVar1 = 0;
  if (((*param_2 == *(int *)(param_1 + 0x28)) && (*(char *)(param_1 + 0x34) == '\x01')) &&
     ((uint)*(ushort *)(param_1 + 0x2e) == param_2[3])) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    memcpy(&local_20,(void *)(param_1 + 0x68),6);
    if (wportal_debug_switch == 0) {
      uVar3 = *(undefined1 *)(param_1 + 0x24);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        uVar3 = *(undefined1 *)(param_1 + 0x24);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d rStaEntry.mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
               "_wportal_sync_roam_sta_cb",0x65c,local_20 >> 0x18,local_20 >> 0x10 & 0xff,
               local_20 >> 8 & 0xff,local_20 & 0xff,local_1c >> 0x18,local_1c >> 0x10 & 0xff);
        uVar3 = *(undefined1 *)(param_1 + 0x24);
      }
    }
    local_18 = (uint)*(ushort *)(param_1 + 0x2e);
    local_1c = CONCAT31(CONCAT21(local_1c._0_2_,uVar3),*(undefined1 *)(param_2 + 2));
    if (wportal_debug_switch == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        uVar1 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d change roam sta status, vlan_id: %d, rd_id: %d, needAuth: %d\n"
               ,"_wportal_sync_roam_sta_cb",0x661,local_18,local_1c >> 8 & 0xff,local_1c & 0xff);
        uVar1 = *(undefined4 *)(param_1 + 0x20);
      }
    }
    uVar1 = wportal_update_roam_sta_to_ap_by_id(uVar1,&local_20,param_2[1]);
  }
  return uVar1;
}

