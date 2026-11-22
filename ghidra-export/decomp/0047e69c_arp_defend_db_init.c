// func arp_defend_db_init @ 0047e69c size=1528

undefined4 arp_defend_db_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *__s;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 auStack_28 [12];
  
  if (g_arp_defend_data != 0) {
    return 0;
  }
  iVar1 = apmngr_db_get_ap_max();
  iVar2 = apmngr_db_get_template_max();
  iVar5 = 30000;
  if ((iVar1 + iVar2) * 3 < 0x7531) {
    iVar1 = apmngr_db_get_ap_max();
    iVar2 = apmngr_db_get_template_max();
    iVar5 = (iVar1 + iVar2) * 3;
  }
  g_arp_defend_msgq = FUN_00408460("/arp_defend_msgq",iVar5,8,4);
  if (g_arp_defend_msgq == -1) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Create arp_defend msgQ failed.\n";
    uVar6 = 0x93d;
LAB_0047e96c:
    printf(pcVar4,"arp_defend_db_init",uVar6);
    return 0xffffffff;
  }
  DAT_007670f8 = FUN_00407f00("arp_defend_ap_mutex",1);
  if (DAT_007670f8 == 0) {
    if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_0047e9a8;
    pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Create arp_defend ap mutex failed.\n";
    uVar6 = 0x944;
  }
  else {
    DAT_007670fc = FUN_00407f00("arp_defend_arp_mutex",1);
    if (DAT_007670fc == 0) {
      if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_0047e9a8;
      pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Create arp_defend arp mutex failed.\n";
      uVar6 = 0x94b;
    }
    else {
      iVar1 = FUN_0051eb48("ac_arp_defend","max_arp",&g_arp_defend_profile);
      if (iVar1 == -1) {
        if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
          g_arp_defend_profile = 300;
        }
        else {
          printf("[ARP_DEFEND_ERROR]%s()/%d get profile[arp_defend->max_arp] fail.\n",
                 "arp_defend_db_init",0x952);
          g_arp_defend_profile = 300;
        }
      }
      iVar1 = FUN_0051eb48("ac_arp_defend","max_bind_num",&DAT_007670f0);
      if (iVar1 == -1) {
        if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d get profile[arp_defend->max_bind_num] fail.\n",
                 "arp_defend_db_init",0x959);
        }
        DAT_007670f0 = 0x30;
      }
      DAT_00767100 = FUN_004080e0(g_arp_defend_profile);
      if (DAT_00767100 == 0) {
        if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
        goto LAB_0047e9a8;
        pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Not enough momery.\n";
        uVar6 = 0x960;
      }
      else {
        iVar1 = apmngr_db_get_ap_max();
        iVar2 = apmngr_db_get_template_max();
        DAT_00767104 = FUN_004082a0(iVar1 + iVar2,0x10,0x965);
        iVar1 = 0;
        if (DAT_00767104 == 0) {
          if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_0047e9a8;
          pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Not enough memory.\n";
          uVar6 = 0x968;
        }
        else {
          while( true ) {
            iVar5 = apmngr_db_get_ap_max();
            iVar3 = apmngr_db_get_template_max();
            iVar2 = DAT_00767104;
            if (iVar5 + iVar3 <= iVar1) break;
            uVar6 = FUN_004082a0(DAT_007670f0,4,0x96e);
            iVar5 = DAT_00767104 + iVar1 * 0x10;
            *(undefined4 *)(iVar2 + iVar1 * 0x10 + 0xc) = uVar6;
            if (*(int *)(iVar5 + 0xc) == 0) {
              if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0047e9a8;
              pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Not enough memory.\n";
              uVar6 = 0x971;
              goto LAB_0047ea6c;
            }
            iVar1 = iVar1 + 1;
            _arp_defend_ap_entry_init();
          }
          __s = (undefined4 *)FUN_004082a0(g_arp_defend_profile,0x120,0x978);
          DAT_0076710c = __s;
          if (__s == (undefined4 *)0x0) {
            if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_0047e9a8;
            pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Not enough memory.\n";
            uVar6 = 0x97b;
          }
          else {
            for (uVar7 = 0; uVar7 < g_arp_defend_profile; uVar7 = uVar7 + 1) {
              memset(__s,0,0x120);
              *__s = 0xffffffff;
              __s = __s + 0x48;
            }
            iVar1 = arp_defend_sqlite_load_arp_service();
            if (iVar1 == 0) {
              FUN_004083b0(DAT_00767100);
              iVar1 = arp_defend_sqlite_load_ap_service();
              if (iVar1 == 0) {
                iVar1 = FUN_004084e0(auStack_28,"arp_defend_task",arp_defend_db_work_task,0);
                if (iVar1 == 0) {
                  g_arp_defend_data = 1;
                  FUN_00408620("/etc/nouci_config/dbs/arp_defend.db",arp_defend_get_msgq_len);
                  if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0))
                  {
                    printf("[ARP_DEFEND_DEBUG]%s()/%d arp_defend_init OK.\n","arp_defend_db_init",
                           0x99c);
                  }
                  if (arp_defend_debug_switch == 0) {
                    return 0;
                  }
                  iVar1 = is_target_debug_ap();
                  if (iVar1 == 0) {
                    return 0;
                  }
                  printf("[ARP_DEFEND_DEBUG]%s()/%d g_arp_defend_mem_stat is %d.\n",
                         "arp_defend_db_init",0x99f,0);
                  return 0;
                }
                if (arp_defend_err_switch == 0) {
                  return 0xffffffff;
                }
                iVar1 = is_target_debug_ap();
                if (iVar1 == 0) {
                  return 0xffffffff;
                }
                pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d Create arp_defend thread failed.\n";
                uVar6 = 0x993;
                goto LAB_0047e96c;
              }
              if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0047e9a8;
              pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_sqlite_load_ap_service() falied.\n";
              uVar6 = 0x98c;
            }
            else {
              if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
              goto LAB_0047e9a8;
              pcVar4 = "[ARP_DEFEND_ERROR]%s()/%d arp_defend_sqlite_load_arp_service() falied.\n";
              uVar6 = 0x986;
            }
          }
        }
      }
    }
  }
LAB_0047ea6c:
  printf(pcVar4,"arp_defend_db_init",uVar6);
LAB_0047e9a8:
  g_arp_defend_data = 0;
  arp_defend_db_uninit();
  return 0xffffffff;
}

