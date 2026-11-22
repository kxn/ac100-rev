// func apmngr_ap_edit_mesh_switch @ 0052dc54 size=716

undefined4 apmngr_ap_edit_mesh_switch(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int local_2f8 [2];
  undefined1 auStack_2f0 [16];
  ushort local_2e0;
  int local_2dc;
  char local_e9;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f0,0,0x2d8);
  local_2f8[0] = 0;
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
  if (iVar1 != 0) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n","apmngr_ap_edit_mesh_switch",0x836,
           param_1);
    return 0xffffffff;
  }
  iVar1 = mesh_db_mesh_enable_get(local_2f8);
  if (iVar1 == 0) {
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d global_mesh_switch %d\n","apmngr_ap_edit_mesh_switch",0x841,
             local_2f8[0]);
    }
    if (local_2f8[0] == 0) {
      return 0;
    }
    if (local_2dc - 2U < 2) {
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d ap(%u) role %d ap mesh witch need keep open \n",
               "apmngr_ap_edit_mesh_switch",0x849,(uint)local_2e0,local_2dc);
      }
      local_e9 = '\x01';
    }
    else {
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d ap(%u) role %d ap mesh  \n","apmngr_ap_edit_mesh_switch",0x84e
               ,(uint)local_2e0,local_2dc);
      }
      iVar1 = json_object_object_get(param_2,"ap_mesh_switch");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          pcVar3 = (char *)json_object_get_string(iVar1);
          iVar1 = atoi(pcVar3);
          local_e9 = (char)iVar1;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "apmngr_ap_edit_mesh_switch",0x850);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "apmngr_ap_edit_mesh_switch",0x850);
          }
          local_e9 = -1;
        }
      }
    }
    iVar1 = apmngr_set_ap_mesh_switch(param_1,(int)local_e9);
    if (iVar1 == 0) {
      return 0;
    }
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APMNGR_ERROR]%s()/%d set apmngr set ap mesh switch failed!\n";
    uVar4 = 0x855;
  }
  else {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar3 = "[APMNGR_ERROR]%s()/%d mesh_db_mesh_enable_get failed\n";
    uVar4 = 0x83d;
  }
  printf(pcVar3,"apmngr_ap_edit_mesh_switch",uVar4);
  return 0xffffffff;
}

