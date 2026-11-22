// func _mesh_pkt_config_status_req_listen @ 004c0628 size=748

undefined4
_mesh_pkt_config_status_req_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 local_3e8;
  undefined4 local_3e4;
  undefined4 local_3e0;
  undefined4 local_3dc;
  undefined4 local_3d8;
  char *local_3d4;
  undefined4 local_3d0;
  undefined4 local_3cc;
  undefined4 local_3c8;
  char local_3c4 [20];
  undefined4 local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  undefined4 local_3a0;
  char acStack_39c [32];
  undefined2 local_37c;
  char *local_378;
  undefined2 local_374;
  char *local_370;
  char acStack_36c [33];
  char acStack_34b [64];
  char acStack_30b [35];
  undefined1 auStack_2e8 [20];
  int local_2d4;
  uint local_94;
  byte abStack_85 [117];
  
  memset(auStack_2e8,0,0x2d8);
  local_3d8 = 0;
  local_3d4 = (char *)0x0;
  local_3b0 = 0;
  local_3ac = 0;
  local_3a8 = 0;
  local_3a4 = 0;
  local_3a0 = 0;
  local_3d0 = 0;
  local_3cc = 0;
  local_3c8 = 0;
  memset(acStack_39c,0,0x30);
  local_3e0 = 0;
  local_3dc = 0;
  local_3e4 = 0;
  local_3e8 = 0;
  memset(acStack_36c,0,0x82);
  local_3c4[0] = '\0';
  local_3c4[1] = '\0';
  local_3c4[2] = '\0';
  local_3c4[3] = '\0';
  local_3c4[4] = '\0';
  local_3c4[5] = '\0';
  local_3c4[6] = '\0';
  local_3c4[7] = '\0';
  uVar3 = 0;
  local_3c4[8] = '\0';
  local_3c4[9] = '\0';
  local_3c4[10] = '\0';
  local_3c4[0xb] = '\0';
  local_3c4[0xc] = '\0';
  local_3c4[0xd] = '\0';
  local_3c4[0xe] = '\0';
  local_3c4[0xf] = '\0';
  local_3c4[0x10] = 0;
  iVar1 = apmngr_db_entry_get_by_mac(param_2,auStack_2e8);
  if ((iVar1 == 0) &&
     (((((local_2d4 == 1 || (local_2d4 == 3)) || (local_2d4 == 2)) ||
       (((local_2d4 == 4 || (local_2d4 == 8)) || (local_2d4 == 6)))) &&
      (uVar3 = 0, (local_94 & 0x1000) != 0)))) {
    iVar1 = mesh_db_backhaul_info_get(acStack_36c);
    if ((iVar1 == 0) && (iVar1 = mesh_db_web_password_get(local_3c4,0x11), iVar1 == 0)) {
      FUN_0051ad88(&local_3d0);
      FUN_0051ad88(&local_3a8);
      sVar2 = strlen(local_3c4);
      local_3d8 = CONCAT22((short)sVar2,local_3d8._2_2_);
      local_3d4 = local_3c4;
      strncpy(acStack_39c,acStack_36c,0x20);
      sVar2 = strlen(acStack_34b);
      local_37c = (undefined2)sVar2;
      local_378 = acStack_34b;
      sVar2 = strlen(acStack_30b);
      local_374 = (undefined2)sVar2;
      local_370 = acStack_30b;
      if (((local_94 & 0x1000) != 0) &&
         (iVar1 = apmngr_db_get_sub_capability_idx(0x2c), (abStack_85[iVar1 * 4] & 0x20) != 0)) {
        mesh_db_policy_mask_get(&local_3e4);
        mesh_db_policy_get(&local_3e8);
        local_3dc = local_3e8;
        local_3e0 = local_3e4;
        iVar1 = FUN_004081e0();
        if (iVar1 == 1) {
          cw_priv_mesh_private_control_add(&local_3d0,0x1b,&local_3e0);
        }
      }
      iVar1 = cw_priv_mesh_private_control_add(&local_3d0,0xf,&local_3d8);
      if (((iVar1 == 0) &&
          (iVar1 = cw_priv_mesh_private_control_add(&local_3d0,10,acStack_39c), iVar1 == 0)) &&
         (iVar1 = cw_service_msg_add(param_3,0x25,&local_3b0,1,0x76,&local_3d0), iVar1 == 0)) {
        cw_priv_mesh_private_control_sub_ele_free(&local_3d0);
        mesh_pkt_dump(param_1);
        uVar3 = 0;
        mesh_pkt_dump(param_3);
      }
      else {
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d Add backhaul info or web password or policy failed\n",
                 "_mesh_pkt_config_status_req_listen",0x211);
        }
        uVar3 = 0xffffffff;
        cw_priv_mesh_private_control_sub_ele_free(&local_3d0);
      }
    }
    else {
      uVar3 = 0xffffffff;
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d Get backhaul info or web password failed\n",
               "_mesh_pkt_config_status_req_listen",0x1f2);
      }
    }
  }
  return uVar3;
}

