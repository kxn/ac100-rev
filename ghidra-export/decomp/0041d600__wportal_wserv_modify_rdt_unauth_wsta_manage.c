// func _wportal_wserv_modify_rdt_unauth_wsta_manage @ 0041d600 size=564

undefined4 _wportal_wserv_modify_rdt_unauth_wsta_manage(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort local_1c8 [2];
  byte local_1c4;
  byte local_1c3;
  byte local_1c2;
  byte local_1c1;
  byte local_1c0;
  byte local_1bf;
  uint local_1bc;
  undefined1 auStack_198 [20];
  uint local_184;
  
  local_1c8[0] = 0;
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  uVar4 = *param_2;
  uac_wservice_get_vlan
            (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
             *(undefined1 *)(param_1 + 0x25),local_1c8);
  uVar1 = uac_wservice_get_wserv_id
                    (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                     *(undefined1 *)(param_1 + 0x25));
  if (uVar1 == 0xffffffff) {
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_DBG]%s()/%d Get wserv id error, wsta->ap_id[%d], wsta->rd_id[%d], wsta->wlan_id[%d] invalid!\n"
           ,"_wportal_wserv_modify_rdt_unauth_wsta_manage",0x1e34,*(undefined4 *)(param_1 + 0x20),
           (uint)*(byte *)(param_1 + 0x24),(uint)*(byte *)(param_1 + 0x25));
    return 0xffffffff;
  }
  memset(auStack_198,0,0x180);
  iVar2 = wportal_db_aut_get(param_1 + 0x68,auStack_198);
  if (iVar2 == 0) {
    if (g_portal_auth_mode == 1) {
      uVar1 = 0xfff;
      if (local_1c8[0] != 0) {
        uVar1 = (uint)local_1c8[0];
      }
    }
    else if (g_portal_auth_mode != 0) goto LAB_0041d6a0;
    if (uVar1 == local_184) {
      if (wportal_info_switch == 0) {
        return 0;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0;
      }
      printf("[WPORTAL_INFO]%s()/%d no action cause sta already authed\n",
             "_wportal_wserv_modify_rdt_unauth_wsta_manage",0x1e3f);
      return 0;
    }
  }
LAB_0041d6a0:
  memset(&local_1c4,0,0x28);
  local_1bc = (uint)local_1c8[0];
  memcpy(&local_1c4,(void *)(param_1 + 0x68),6);
  if (wportal_debug_switch == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x20);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x20);
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d Do action[%d] for station: apid: %d, rdid: %d, wlanid: %d, vlan: %d, mac: %02x:%02x:%02x:%02x:%02x:%02x\n\n"
             ,"_wportal_wserv_modify_rdt_unauth_wsta_manage",0x1e4a,uVar4,
             *(undefined4 *)(param_1 + 0x20),(uint)*(byte *)(param_1 + 0x24),
             (uint)*(byte *)(param_1 + 0x25),(uint)local_1c8[0],(uint)local_1c4,(uint)local_1c3,
             (uint)local_1c2,(uint)local_1c1,(uint)local_1c0,(uint)local_1bf);
      uVar3 = *(undefined4 *)(param_1 + 0x20);
    }
  }
  wportal_update_user_to_ap_by_id(uVar3,&local_1c4,uVar4);
  return 0;
}

