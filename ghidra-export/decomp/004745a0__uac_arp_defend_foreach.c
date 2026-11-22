// func _uac_arp_defend_foreach @ 004745a0 size=480

undefined4 _uac_arp_defend_foreach(int param_1,int *param_2)

{
  char *__format;
  int iVar1;
  undefined4 uVar2;
  int local_20 [4];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  if (*(int *)(param_1 + 0x3c) != 0) {
    if (arp_defend_debug_switch == 0) {
      iVar1 = param_2[5];
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        iVar1 = param_2[5];
      }
      else {
        printf("[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_foreach(%d) begin.\n",
               "_uac_arp_defend_foreach",0x14d,(uint)*(ushort *)(param_1 + 0x10));
        iVar1 = param_2[5];
      }
    }
    if (iVar1 == 0) {
      iVar1 = param_2[4];
    }
    else if ((code *)param_2[6] == (code *)0x0) {
      iVar1 = param_2[4];
    }
    else {
      iVar1 = (*(code *)param_2[6])(*(undefined2 *)(param_1 + 0x10));
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = param_2[4];
    }
    param_2[4] = iVar1 + 1;
    if (param_2[2] < *param_2) {
      param_2[2] = param_2[2] + 1;
    }
    else if (param_2[3] < param_2[1]) {
      param_2[3] = param_2[3] + 1;
      iVar1 = arp_defend_db_ap_entry_get(*(undefined2 *)(param_1 + 0x10),local_20);
      if (iVar1 == 0) {
        if (local_20[0] == -1) {
          if (arp_defend_debug_switch == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          __format = "[ARP_DEFEND_DEBUG]%s()/%d Invalid ap entry.\n";
          uVar2 = 0x170;
        }
        else {
          _uac_arp_defend_get_ap_entry(param_1,local_20,param_2[7]);
          if (arp_defend_debug_switch == 0) {
            return 0;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0;
          }
          __format = "[ARP_DEFEND_DEBUG]%s()/%d _uac_arp_defend_foreach() finish.\n";
          uVar2 = 0x176;
        }
        printf(__format,"_uac_arp_defend_foreach",uVar2);
      }
      else if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_ap_entry_get(%d) failed.\n",
               "_uac_arp_defend_foreach",0x16a,(uint)*(ushort *)(param_1 + 0x10));
      }
    }
  }
  return 0;
}

