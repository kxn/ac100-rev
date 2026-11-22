// func apdb_name_valid @ 00608988 size=1

undefined4 apdb_name_valid(char *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == (char *)0x0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : input ap name error.\n","apdb_name_valid",0x252f);
    }
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar1 = l_apdb_ap_item_cnt_cur;
    if (l_apdb_ap_item_cnt_cur != 0) {
      if ((l_apdb_ap_item_cur == 0) || (iVar6 = 0, l_apdb_ap_item_cnt_cur < 0)) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : apdb not initialized.\n","_apdb_get_index_by_name",
                 0x1155);
        }
      }
      else {
        iVar4 = 0;
        iVar3 = l_apdb_ap_item_cur;
        do {
          iVar5 = iVar4 * 0x168;
          while (iVar4 < *(int *)(iVar3 + 0x4c)) {
            iVar2 = *(int *)(iVar3 + 0x54) + iVar5;
            iVar5 = iVar5 + 0x168;
            iVar2 = strcmp((char *)(iVar2 + 0xda),param_1);
            iVar4 = iVar4 + 1;
            if (iVar2 == 0) {
              FUN_00407f30(l_apdb_mutex);
              return 1;
            }
          }
          iVar6 = iVar6 + 1;
          iVar3 = iVar3 + 0x58;
        } while (iVar6 < iVar1);
      }
    }
    FUN_00407f30(l_apdb_mutex);
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d :  Failed to search ap[%s].\n","apdb_name_valid",0x2539,
             param_1);
    }
  }
  return 0;
}

