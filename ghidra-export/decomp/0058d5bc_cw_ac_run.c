// func cw_ac_run @ 0058d5bc size=1224

undefined4 cw_ac_run(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  char acStack_ec [100];
  char local_88 [104];
  
  local_f0 = 0xffffffff;
  local_f4 = 0xffffffff;
  memset(local_88,0,100);
  memset(acStack_ec,0,100);
  local_f8 = 0xffffffff;
  puVar4 = (undefined4 *)0x0;
  while (puVar4 < (undefined4 *)ac[6]) {
    memset(acStack_ec,0,100);
    snprintf(acStack_ec,100,"ac_dt_thread[%d]",puVar4);
    iVar1 = FUN_004084e0(ac[8] + (int)puVar4 * 4,acStack_ec,cw_ac_data_run,
                         ac[7] + (int)puVar4 * 0xa0);
    if (iVar1 != 0) {
      uVar5 = 0xffffffff;
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar2 = "[CW_ERROR]%32s():%4d create ac_data[%d]\'s handler thread failed.\n";
      uVar3 = 0xc0e;
      goto LAB_0058d850;
    }
    if (capwap_debug_switch == 0) {
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      else {
        printf("[CW_DEBUG]%32s():%4d ac_data[%d]\'s handler thread[%d] created\n","cw_ac_run",0xc11,
               puVar4,*(undefined4 *)(ac[8] + (int)puVar4 * 4));
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
    }
  }
  memset(local_88,0,100);
  builtin_strncpy(local_88,"ac_thread",9);
  if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[CW_DEBUG]%32s():%4d bind socket\n","cw_ac_run",0xc17);
  }
  iVar1 = capwap_socket_bind(ac[3],ac[1],*(undefined2 *)(ac + 2));
  if (iVar1 == 0) {
    iVar1 = capwap_ipv6_socket_bind(ac[4],*(undefined2 *)(ac + 2));
    if (iVar1 == 0) {
      iVar1 = capwap_netlink_socket_bind(ac[5]);
      if (iVar1 == 0) {
        *ac = 1;
        iVar1 = FUN_004084e0(&local_f0,local_88,cw_ac_run_callback,0);
        if (iVar1 == 0) {
          if ((capwap_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[CW_DEBUG]%32s():%4d ac[%p]\'s handler thread[%d] created\n","cw_ac_run",0xc35,
                   ac,local_f0);
          }
          iVar1 = FUN_004084e0(&local_f4,"check_cw_recv_queue_thread",
                               cw_ac_check_recv_queue_threshold,0);
          if (iVar1 == 0) {
            iVar1 = FUN_004084e0(&local_f8,"write_snapshot_thread",write_snapshot_thread_callback,0)
            ;
            if (iVar1 != 0) {
              if (capwap_err_switch == 0) {
                return 0xffffffff;
              }
              iVar1 = is_target_debug_ap();
              if (iVar1 == 0) {
                return 0xffffffff;
              }
              pcVar2 = "[CW_ERROR]%32s():%4d create write_snapshot_thread handler thread failed\n";
              uVar5 = 0xc40;
              goto LAB_0058d8e4;
            }
            uVar5 = 0;
            if (capwap_debug_switch == 0) {
              return 0;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0;
            }
            pcVar2 = "[CW_DEBUG]%32s():%4d ac[%p] enter run\n";
            uVar3 = 0xc44;
            puVar4 = ac;
          }
          else {
            uVar5 = 0xffffffff;
            if (capwap_err_switch == 0) {
              return 0xffffffff;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0xffffffff;
            }
            pcVar2 = "[CW_ERROR]%32s():%4d create ac[%p]\'s handler thread failed\n";
            uVar3 = 0xc39;
            puVar4 = ac;
          }
        }
        else {
          uVar5 = 0xffffffff;
          if (capwap_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          pcVar2 = "[CW_ERROR]%32s():%4d create ac[%p]\'s handler thread failed\n";
          uVar3 = 0xc32;
          puVar4 = ac;
        }
LAB_0058d850:
        printf(pcVar2,"cw_ac_run",uVar3,puVar4);
        return uVar5;
      }
      capwap_socket_destroy(ac[5]);
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar2 = "[CW_ERROR]%32s():%4d bind socket failed.\n";
      uVar5 = 0xc2b;
    }
    else {
      capwap_socket_destroy(ac[4]);
      if (capwap_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar2 = "[CW_ERROR]%32s():%4d bind socket failed.\n";
      uVar5 = 0xc24;
    }
  }
  else {
    capwap_socket_destroy(ac[3]);
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[CW_ERROR]%32s():%4d bind socket failed.\n";
    uVar5 = 0xc1c;
  }
LAB_0058d8e4:
  printf(pcVar2,"cw_ac_run",uVar5);
  return 0xffffffff;
}

