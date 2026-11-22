// func _apdb_ap_item_get_index_by_id_array @ 005fb324 size=228

int _apdb_ap_item_get_index_by_id_array(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    if ((param_2 == 0) || (iVar2 = param_3 + -1, param_3 < 0)) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : apdb not initialized.\n",
               "_apdb_ap_item_get_index_by_id_array",1099);
      }
    }
    else {
      iVar1 = 0;
      do {
        iVar4 = (iVar1 + iVar2) / 2;
        iVar3 = *(int *)(param_2 + iVar4 * 0x58);
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
               ,"_apdb_ap_item_get_index_by_id_array",0x465,iVar4,param_3,param_1);
      }
    }
  }
  return -1;
}

