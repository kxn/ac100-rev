// func _apdb_ap_item_get_index_by_id @ 005f969c size=248

int _apdb_ap_item_get_index_by_id(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (l_apdb_ap_item_cnt_cur != 0) {
    if ((l_apdb_ap_item_cur == 0) ||
       (iVar2 = l_apdb_ap_item_cnt_cur + -1, l_apdb_ap_item_cnt_cur < 0)) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : apdb not initialized.\n","_apdb_ap_item_get_index_by_id",
               0x476);
      }
    }
    else {
      iVar1 = 0;
      do {
        iVar4 = (iVar1 + iVar2) / 2;
        iVar3 = *(int *)(l_apdb_ap_item_cur + iVar4 * 0x58);
        if (param_1 == iVar3) {
          return iVar4;
        }
        if (param_1 < iVar3) {
          iVar2 = iVar4 + -1;
        }
        else {
          iVar1 = iVar4 + 1;
        }
      } while (iVar1 <= iVar2);
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : GET AP INDEX FAILED.\n----->>>middle: %d----->>>size:%d------>>>id:%d\n"
               ,"_apdb_ap_item_get_index_by_id",0x490,iVar4,l_apdb_ap_item_cnt_cur,param_1);
      }
    }
  }
  return -1;
}

