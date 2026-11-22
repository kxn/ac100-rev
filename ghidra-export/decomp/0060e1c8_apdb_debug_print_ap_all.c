// func apdb_debug_print_ap_all @ 0060e1c8 size=1

void apdb_debug_print_ap_all(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : -----------------new apdb--------------------\n\n",
           "apdb_print_ap_all",0x2b7e);
  }
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  if (l_apdb_ap_item_new == 0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : new apdb is empty.\n","apdb_print_ap_all",0x2b8e);
    }
  }
  else {
    _apdb_print_ap_head();
    for (iVar4 = 0; iVar4 < l_apdb_ap_item_cnt_new; iVar4 = iVar4 + 1) {
      iVar3 = 0;
      while( true ) {
        iVar1 = l_apdb_ap_item_new + iVar4 * 0x58;
        iVar2 = iVar3 * 0x168;
        if (*(int *)(iVar1 + 0x4c) <= iVar3) break;
        iVar3 = iVar3 + 1;
        _apdb_print_ap(*(int *)(iVar1 + 0x54) + iVar2);
      }
    }
  }
  FUN_00407f30(l_apdb_mutex);
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : -----------------old apdb--------------------\n\n",
           "apdb_print_ap_all",0x2b93);
  }
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  if (l_apdb_ap_item_cur == 0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : old apdb is empty.\n","apdb_print_ap_all",0x2ba4);
    }
  }
  else {
    _apdb_print_ap_head();
    for (iVar4 = 0; iVar4 < l_apdb_ap_item_cnt_cur; iVar4 = iVar4 + 1) {
      iVar3 = 0;
      while( true ) {
        iVar1 = l_apdb_ap_item_cur + iVar4 * 0x58;
        iVar2 = iVar3 * 0x168;
        if (*(int *)(iVar1 + 0x4c) <= iVar3) break;
        iVar3 = iVar3 + 1;
        _apdb_print_ap(*(int *)(iVar1 + 0x54) + iVar2);
      }
    }
  }
  FUN_00407f30(l_apdb_mutex);
  return;
}

