// func FUN_00474804 @ 00474804 size=452

undefined4 FUN_00474804(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == (int *)0x0)) {
    uVar4 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n","_uac_arp_defend_update_and_notify",0x211
            );
    }
  }
  else {
    uVar4 = 0;
    for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {
      if (*param_3 == 1) {
        iVar1 = arp_defend_db_ap_update(*param_1);
        if (iVar1 != 0) {
          uVar4 = 0xffffffff;
        }
        iVar1 = arp_defend_db_ap_entry_get(*param_1,&local_38);
        if (iVar1 == 0) {
          arp_defend_print_ap_entry(&local_38);
          iVar1 = arp_defend_wtp_pkt_send(local_38,&local_38,1);
          if (iVar1 != 0) {
            uVar4 = 0xffffffff;
            if (arp_defend_warning_switch == 0) goto LAB_00474884;
            iVar1 = is_target_debug_ap();
            if (iVar1 != 0) {
              uVar2 = 0x22b;
              __format = "[ARP_DEFEND_WARNING]%s()/%d arp_defend_wtp_pkt_send(%d) failed.\n";
              uVar3 = local_38;
              goto LAB_004748f8;
            }
          }
        }
        else {
          uVar4 = 0xffffffff;
          if (arp_defend_warning_switch == 0) {
LAB_00474884:
            uVar4 = 0xffffffff;
          }
          else {
            iVar1 = is_target_debug_ap();
            if (iVar1 != 0) {
              uVar2 = 0x221;
              __format = "[ARP_DEFEND_WARNING]%s()/%d arp_defend_db_ap_entry_get(%d) failed.\n";
              uVar3 = *param_1;
LAB_004748f8:
              uVar4 = 0xffffffff;
              printf(__format,"_uac_arp_defend_update_and_notify",uVar2,uVar3);
            }
          }
        }
      }
      param_3 = param_3 + 1;
      param_1 = param_1 + 1;
    }
  }
  return uVar4;
}

