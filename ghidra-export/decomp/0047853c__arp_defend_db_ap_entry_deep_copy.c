// func _arp_defend_db_ap_entry_deep_copy @ 0047853c size=252

undefined4 _arp_defend_db_ap_entry_deep_copy(void *param_1,void *param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  void *__dest;
  
  if ((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d Invalid params.\n";
    uVar2 = 0xb1;
  }
  else {
    __dest = *(void **)((int)param_1 + 0xc);
    if ((__dest != (void *)0x0) && (*(int *)((int)param_2 + 0xc) != 0)) {
      memcpy(param_1,param_2,0x10);
      memcpy(__dest,*(void **)((int)param_2 + 0xc),DAT_007670f0 << 2);
      *(void **)((int)param_1 + 0xc) = __dest;
      return 0;
    }
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[ARP_DEFEND_ERROR]%s()/%d Invalid bind_id_list.\n";
    uVar2 = 0xb7;
  }
  printf(__format,"_arp_defend_db_ap_entry_deep_copy",uVar2);
  return 0xffffffff;
}

