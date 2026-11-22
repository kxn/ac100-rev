// func apmngr_set_ap_mesh_switch @ 0052d9f0 size=612

uint apmngr_set_ap_mesh_switch(uint param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int local_2f8 [2];
  undefined1 auStack_2f0 [519];
  char local_e9;
  
  iVar5 = (int)param_2;
  param_1 = param_1 & 0xffff;
  memset(auStack_2f0,0,0x2d8);
  local_2f8[0] = 0;
  iVar1 = mesh_db_mesh_enable_get(local_2f8);
  if (iVar1 == 0) {
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d global_mesh_switch %d\n","apmngr_set_ap_mesh_switch",0x802,
             local_2f8[0]);
    }
    uVar4 = 0;
    if (local_2f8[0] != 0) {
      iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2f0);
      if (iVar1 == 0) {
        if (local_e9 == iVar5) {
          if (apmngr_debug_switch == '\0') {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          __format = 
          "[APMNGR_DEBUG]%s()/%d ap_id:%d, mesh switch don\'t change, so don\'t need send\n";
          uVar3 = 0x811;
        }
        else {
          if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(param_1), iVar1 != 0)) {
            printf("[APMNGR_DEBUG]%s()/%d set %d\'s mesh switch to %d\n","apmngr_set_ap_mesh_switch"
                   ,0x816,param_1,iVar5);
          }
          local_e9 = param_2;
          apmngr_db_ap_mesh_switch_update(param_1,iVar5);
          iVar1 = ap_mesh_switch_is_enable(param_1);
          if (iVar1 == 0) {
            uVar2 = mesh_pkt_enable_request_send(param_1,0);
            uVar4 = close_ap_mesh_switch_cb(param_1);
            uVar4 = uVar4 | uVar2;
            if (apmngr_debug_switch == '\0') {
              return uVar4;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return uVar4;
            }
            __format = "[APMNGR_DEBUG]%s()/%d send mesh disable to ap %d\n";
            uVar3 = 0x827;
          }
          else {
            uVar4 = mesh_pkt_enable_request_send(param_1,1);
            if (apmngr_debug_switch == '\0') {
              return uVar4;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return uVar4;
            }
            __format = "[APMNGR_DEBUG]%s()/%d send mesh enable to ap %d\n";
            uVar3 = 0x821;
          }
        }
      }
      else {
        uVar4 = 0xffffffff;
        if (apmngr_err_switch == '\0') {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[APMNGR_ERROR]%s()/%d get ap entry failed id:%d\n";
        uVar3 = 0x80a;
      }
      printf(__format,"apmngr_set_ap_mesh_switch",uVar3,param_1);
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d mesh_db_mesh_enable_get failed\n","apmngr_set_ap_mesh_switch",
             0x7fe);
    }
  }
  return uVar4;
}

