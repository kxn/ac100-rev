// func arp_defend_recover_ap_config_cb @ 00476d70 size=496

int arp_defend_recover_ap_config_cb(int param_1,int *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    iVar3 = -1;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n","arp_defend_recover_ap_config_cb",0x42);
    }
  }
  else {
    iVar3 = 0;
    if (*(int *)(param_1 + 0x3c) != 0) {
      iVar1 = arp_defend_db_ap_entry_not_used(*(undefined2 *)(param_1 + 0x10));
      if (iVar1 == 0) {
        if (arp_defend_debug_switch == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        __format = 
        "[ARP_DEFEND_DEBUG]%s()/%d ##########ap_id[%d] is used, NO need to recover!##########\n";
        uVar2 = 0x5e;
      }
      else {
        if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[ARP_DEFEND_DEBUG]%s()/%d ##########ap_id[%d] is firmed, but still NOT have apbind entry in DB!##########\n"
                 ,"arp_defend_recover_ap_config_cb",0x4b,(uint)*(ushort *)(param_1 + 0x10));
        }
        iVar3 = arp_defend_db_ap_entry_add(*(undefined2 *)(param_1 + 0x10));
        if (iVar3 == 0) {
          iVar3 = arp_defend_db_ap_firm(*(undefined2 *)(param_1 + 0x10));
          if (iVar3 == 0) {
            *param_2 = *param_2 + 1;
            if (arp_defend_debug_switch == 0) {
              return 0;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 0;
            }
            __format = 
            "[ARP_DEFEND_DEBUG]%s()/%d ##########succeed to recover ap_id[%d]!##########\n";
            uVar2 = 0x5a;
          }
          else {
            if (arp_defend_err_switch == 0) {
              return iVar3;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return iVar3;
            }
            __format = "[ARP_DEFEND_ERROR]%s()/%d fail to arp_defend_db_ap_firm(ap_id[%d])\n";
            uVar2 = 0x56;
          }
        }
        else {
          if (arp_defend_err_switch == 0) {
            return iVar3;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return iVar3;
          }
          __format = "[ARP_DEFEND_ERROR]%s()/%d fail to arp_defend_db_ap_entry_add(ap_id[%d])\n";
          uVar2 = 0x4f;
        }
      }
      printf(__format,"arp_defend_recover_ap_config_cb",uVar2,(uint)*(ushort *)(param_1 + 0x10));
    }
  }
  return iVar3;
}

