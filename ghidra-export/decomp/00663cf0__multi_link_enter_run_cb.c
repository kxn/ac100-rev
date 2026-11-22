// func _multi_link_enter_run_cb @ 00663cf0 size=1064

undefined4 _multi_link_enter_run_cb(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *__s2;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 local_8c8;
  undefined4 local_8c4;
  undefined4 local_8c0;
  undefined4 local_8bc;
  undefined4 local_8b8;
  undefined4 local_8b4;
  undefined1 auStack_8b0 [16];
  ushort local_8a0;
  undefined1 auStack_5d8 [16];
  ushort local_5c8;
  int local_5c4;
  undefined1 auStack_33e [62];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  
  memset(auStack_300,0,0x2d8);
  iVar2 = apmngr_db_entry_get_by_mac(param_1,auStack_300);
  if (iVar2 == 0) {
    if (((*(char *)(param_1 + 0xc) == '\0') &&
        (iVar2 = apmngr_db_capacity_support(local_2f0,1,4), iVar2 != 1)) &&
       (iVar2 = apmngr_db_capacity_support(local_2f0,1,0x33), iVar2 != 1)) {
      if (multi_link_warning_switch == '\0') {
        uVar4 = *(undefined4 *)(param_1 + 0x30);
      }
      else {
        printf("[MULTI_LINK_WARNING]%s()/%d AP does NOT supported dual-link function, force to submit configurations.\n"
               ,"_multi_link_enter_run_cb",0x203);
        uVar4 = *(undefined4 *)(param_1 + 0x30);
      }
      uVar4 = multi_link_status_switch
                        (local_2f0,1,1,*(undefined4 *)(param_1 + 0x2c),uVar4,
                         *(undefined4 *)(param_1 + 0x28));
    }
    else {
      uVar4 = 0;
      if (*(char *)(param_1 + 0xc) != '\0') {
        memset(auStack_5d8,0,0x2d8);
        memset(auStack_8b0,0,0x2d8);
        local_8c8 = 0;
        local_8c4 = 0;
        local_8c0 = 0;
        local_8bc = 0;
        local_8b8 = 0;
        local_8b4 = 0;
        iVar2 = apmngr_db_entry_get_by_mac(param_1,auStack_5d8);
        if (((iVar2 == 0) && (uVar4 = 0, local_5c4 == 5)) &&
           (iVar3 = apmngr_db_entry_get_by_mac(param_1 + 6,auStack_8b0), iVar2 = g_multi_link_array,
           iVar3 == 0)) {
          uVar5 = (uint)local_8a0;
          if (49999 < uVar5) {
            iVar3 = apmngr_db_get_ap_max();
            uVar5 = (uVar5 - 50000) + iVar3;
          }
          cVar1 = *(char *)(iVar2 + uVar5);
          __s2 = (void *)cw_msg_ele_priv_val_get_from_pkt(param_2,0x41);
          iVar2 = g_multi_link_config_changed_array;
          if (cVar1 == '\x01') {
            uVar7 = 4;
            if (__s2 != (void *)0x0) {
              if (multi_link_debug_switch != '\0') {
                printf("[MULTI_LINK_DEBUG]%s()/%d Received an MD5-Checksum.\n",
                       "_multi_link_enter_run_child_cb",0x1d3);
              }
              iVar2 = memcmp(auStack_33e,__s2,0x10);
              if (iVar2 == 0) {
                if (multi_link_debug_switch != '\0') {
                  printf("[MULTI_LINK_DEBUG]%s()/%d Config matched, no need to submit.\n",
                         "_multi_link_enter_run_child_cb",0x1dc);
                }
                iVar2 = g_multi_link_config_changed_array;
                uVar5 = (uint)local_5c8;
                if (49999 < uVar5) {
                  iVar3 = apmngr_db_get_ap_max();
                  uVar5 = (uVar5 - 50000) + iVar3;
                }
                uVar7 = 3;
                *(undefined1 *)(iVar2 + uVar5) = 0;
              }
              else {
                if (multi_link_debug_switch != '\0') {
                  printf("[MULTI_LINK_DEBUG]%s()/%d Config is not matched.\n",
                         "_multi_link_enter_run_child_cb",0x1d6);
                }
                iVar2 = g_multi_link_config_changed_array;
                uVar5 = (uint)local_5c8;
                if (49999 < uVar5) {
                  iVar3 = apmngr_db_get_ap_max();
                  uVar5 = (uVar5 - 50000) + iVar3;
                }
                uVar7 = 4;
                *(undefined1 *)(iVar2 + uVar5) = 1;
              }
            }
            iVar2 = g_multi_link_config_changed_array;
            uVar6 = (uint)local_5c8;
            uVar5 = uVar6;
            if (49999 < uVar6) {
              iVar3 = apmngr_db_get_ap_max();
              uVar5 = (uVar6 - 50000) + iVar3;
            }
            multi_link_status_switch
                      (uVar6,1,*(undefined1 *)(iVar2 + uVar5),*(undefined4 *)(param_1 + 0x2c),
                       *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x28));
          }
          else {
            uVar6 = (uint)local_5c8;
            uVar5 = uVar6;
            if (49999 < uVar6) {
              iVar3 = apmngr_db_get_ap_max();
              uVar5 = (uVar6 - 50000) + iVar3;
            }
            uVar7 = 2;
            multi_link_status_switch
                      (uVar6,0,*(undefined1 *)(iVar2 + uVar5),*(undefined4 *)(param_1 + 0x2c),
                       *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x28));
          }
          iVar2 = g_multi_link_config_changed_array;
          uVar5 = (uint)local_5c8;
          if (49999 < uVar5) {
            iVar3 = apmngr_db_get_ap_max();
            uVar5 = (uVar5 - 50000) + iVar3;
          }
          *(undefined1 *)(iVar2 + uVar5) = 1;
          uVar4 = 0;
          if ((__s2 != (void *)0x0) && (param_3 != 0)) {
            uVar4 = 0xffffffff;
            FUN_0051ad88(&local_8bc);
            local_8c8 = uVar7;
            iVar2 = cw_service_msg_add(param_3,0x25,&local_8c4,1,0x40,&local_8c8);
            if (iVar2 == 0) {
              uVar4 = 0;
            }
          }
        }
      }
    }
  }
  else {
    uVar4 = 0xffffffff;
    if (multi_link_warning_switch != '\0') {
      printf("[MULTI_LINK_WARNING]%s()/%d Failed to find ap when go to run-state.\n",
             "_multi_link_enter_run_cb",0x1fc);
    }
  }
  return uVar4;
}

