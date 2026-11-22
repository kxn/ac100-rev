// func arp_defend_db_apbind_entry_batch_clear_arps @ 0047b8a4 size=640

undefined4 arp_defend_db_apbind_entry_batch_clear_arps(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if ((param_1 == (int *)0x0) || (param_2 == 0)) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d Invalid ap params.\n";
    uVar4 = 0x53a;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      FUN_004082d0(DAT_007670f8,0xffffffff);
      for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {
        *param_3 = 0;
        iVar6 = DAT_00767104;
        iVar5 = *param_1;
        if (49999 < iVar5) {
          iVar1 = apmngr_db_get_ap_max();
          iVar2 = apmngr_db_get_template_max();
          iVar5 = iVar5 + -50000 + iVar1 + iVar2;
        }
        uVar7 = 0;
        if (*(int *)(iVar6 + iVar5 * 0x10 + 8) < 1) {
          if ((arp_defend_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d No arp is binded to ap_id[%d], No need to clear!\n",
                   "arp_defend_db_apbind_entry_batch_clear_arps",0x54c,*param_1);
          }
        }
        else {
          for (; iVar5 = DAT_00767104, uVar7 < DAT_007670f0; uVar7 = uVar7 + 1) {
            iVar6 = *param_1;
            if (49999 < iVar6) {
              iVar1 = apmngr_db_get_ap_max();
              iVar2 = apmngr_db_get_template_max();
              iVar6 = iVar6 + -50000 + iVar1 + iVar2;
            }
            *(undefined4 *)(*(int *)(iVar5 + iVar6 * 0x10 + 0xc) + uVar7 * 4) = 0xffffffff;
          }
          iVar6 = *param_1;
          if (49999 < iVar6) {
            iVar1 = apmngr_db_get_ap_max();
            iVar2 = apmngr_db_get_template_max();
            iVar6 = iVar6 + -50000 + iVar1 + iVar2;
          }
          *(undefined4 *)(iVar5 + iVar6 * 0x10 + 8) = 0;
          *param_3 = 1;
        }
        param_3 = param_3 + 1;
        param_1 = param_1 + 1;
      }
      FUN_00407f30(DAT_007670f8);
      return 0;
    }
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n";
    uVar4 = 0x540;
  }
  printf(__format,"arp_defend_db_apbind_entry_batch_clear_arps",uVar4);
  return 0xffffffff;
}

