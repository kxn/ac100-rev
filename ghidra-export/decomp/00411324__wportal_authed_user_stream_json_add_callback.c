// func _wportal_authed_user_stream_json_add_callback @ 00411324 size=876

undefined4 _wportal_authed_user_stream_json_add_callback(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar5;
  char *__format;
  uint uVar4;
  uint uVar6;
  int iVar7;
  ushort local_c0 [2];
  char local_bc [20];
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined1 local_84;
  undefined1 local_83;
  
  local_bc[0] = '\0';
  local_bc[1] = '\0';
  local_bc[2] = '\0';
  local_bc[3] = '\0';
  local_bc[4] = '\0';
  local_bc[5] = '\0';
  local_bc[6] = '\0';
  local_bc[7] = '\0';
  local_bc[8] = '\0';
  local_bc[9] = '\0';
  local_bc[10] = '\0';
  local_bc[0xb] = '\0';
  local_bc[0xc] = '\0';
  local_bc[0xd] = '\0';
  local_bc[0xe] = '\0';
  local_bc[0xf] = '\0';
  local_bc[0x10] = '\0';
  local_bc[0x11] = '\0';
  memset(auStack_a8,0,0x80);
  local_c0[0] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d inputs error.\n";
    uVar2 = 0x9f4;
  }
  else {
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      snprintf(local_bc,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0xc),
               (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe),
               (uint)*(byte *)(param_1 + 0xf),(uint)*(byte *)(param_1 + 0x10),
               (uint)*(byte *)(param_1 + 0x11));
      uVar2 = json_object_new_string(local_bc);
      json_object_object_add(iVar1,"mac",uVar2);
      iVar3 = wsta_db_get_entry_by_mac(param_1 + 0xc,auStack_a8);
      bVar5 = false;
      if (iVar3 == 0) {
        if (g_portal_auth_mode == 0) {
          iVar3 = uac_wservice_get_wserv_id(local_88,local_84,local_83);
          if (iVar3 == -1) {
            if (wportal_debug_switch == 0) {
              iVar7 = *(int *)(param_1 + 0x14);
            }
            else {
              iVar7 = is_target_debug_ap();
              if (iVar7 == 0) {
                iVar7 = *(int *)(param_1 + 0x14);
              }
              else {
                printf("[WPORTAL_DBG]%s()/%d Get wserv_id fail\n\n",
                       "_wportal_authed_user_stream_json_add_callback",0xa0a);
                iVar7 = *(int *)(param_1 + 0x14);
              }
            }
          }
          else {
            iVar7 = *(int *)(param_1 + 0x14);
          }
          bVar5 = iVar3 == iVar7;
        }
        else {
          bVar5 = false;
          if (g_portal_auth_mode == 1) {
            iVar3 = uac_wservice_get_vlan(local_88,local_84,local_83,local_c0);
            uVar4 = (uint)local_c0[0];
            if ((iVar3 != 0) && (wportal_debug_switch != 0)) {
              iVar3 = is_target_debug_ap();
              if (iVar3 == 0) {
                uVar4 = (uint)local_c0[0];
              }
              else {
                printf("[WPORTAL_DBG]%s()/%d uac_wservice_get_vlan get fail\n\n",
                       "_wportal_authed_user_stream_json_add_callback",0xa16);
                uVar4 = (uint)local_c0[0];
              }
            }
            bVar5 = uVar4 == *(uint *)(param_1 + 0x14);
          }
        }
      }
      uVar4 = *(uint *)(param_1 + 0x174);
      uVar6 = *(uint *)(param_1 + 0x17c);
      iVar3 = *(int *)(param_1 + 0x170);
      iVar7 = *(int *)(param_1 + 0x178);
      uVar2 = json_object_new_int(bVar5);
      json_object_object_add(iVar1,"is_online",uVar2);
      uVar2 = _wportal_auth_type_int2str(*(undefined1 *)(param_1 + 0x80));
      uVar2 = json_object_new_string(uVar2);
      json_object_object_add(iVar1,"auth_type",uVar2);
      uVar2 = json_object_new_int64(0,uVar4 << 10);
      json_object_object_add(iVar1,"acctInputOctets",uVar2);
      uVar2 = json_object_new_int64(0,iVar3 << 10 | uVar4 >> 0x16);
      json_object_object_add(iVar1,"acctInputGigawords",uVar2);
      uVar2 = json_object_new_int64(0,uVar6 << 10);
      json_object_object_add(iVar1,"acctOutputOctets",uVar2);
      uVar2 = json_object_new_int64(0,iVar7 << 10 | uVar6 >> 0x16);
      json_object_object_add(iVar1,"acctOutputGigawords",uVar2);
      json_object_array_add(param_2,iVar1);
      return 0;
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d malloc json obj failed.\n";
    uVar2 = 0x9fb;
  }
  printf(__format,"_wportal_authed_user_stream_json_add_callback",uVar2);
  return 0xffffffff;
}

