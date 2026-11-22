// func _wportal_wserv_modify_rdt_wsta_manage @ 0041d834 size=256

undefined4 _wportal_wserv_modify_rdt_wsta_manage(int param_1,undefined4 *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  uint local_30;
  
  uVar2 = 0xffffffff;
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = *(ushort *)(param_1 + 0x2e);
    uVar2 = *param_2;
    memset(&local_38,0,0x28);
    local_30 = (uint)uVar1;
    memcpy(&local_38,(void *)(param_1 + 0x68),6);
    if (wportal_debug_switch == 0) {
      uVar4 = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        uVar4 = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d Add for station: apid: %d, rdid: %d, wlanid: %d, vlan: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n"
               ,"_wportal_wserv_modify_rdt_wsta_manage",0x1de7,*(undefined4 *)(param_1 + 0x20),
               (uint)*(byte *)(param_1 + 0x24),(uint)*(byte *)(param_1 + 0x25),(uint)uVar1,
               (uint)local_38,(uint)local_37,(uint)local_36,(uint)local_35,(uint)local_34,
               (uint)local_33);
        uVar4 = *(undefined4 *)(param_1 + 0x20);
      }
    }
    wportal_update_user_to_ap_by_id(uVar4,&local_38,uVar2);
    uVar2 = 0;
  }
  return uVar2;
}

