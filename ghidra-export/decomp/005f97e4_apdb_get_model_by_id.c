// func apdb_get_model_by_id @ 005f97e4 size=500

undefined4 apdb_get_model_by_id(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_a0 [132];
  
  memset(auStack_a0,0,0x80);
  if (param_2 == 0) {
    uVar4 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : the fwid is NULL\n","apdb_get_model_by_id",0x2244);
    }
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    iVar2 = _apdb_ap_item_get_index_by_id(param_1);
    if (iVar2 == -1) {
      uVar4 = 0xffffffff;
      FUN_00407f30(l_apdb_mutex);
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d :  Failed to search ap[0x%x].\n","apdb_get_model_by_id",
               0x2250,param_1);
      }
    }
    else {
      iVar3 = *(int *)(l_apdb_ap_item_cur + iVar2 * 0x58 + 0x50);
      if ((iVar3 == 0) || (*(int *)(iVar3 + 0x14) != 0)) {
        iVar3 = FUN_00407fa0(iVar3,param_2);
        uVar1 = l_apdb_mutex;
        if (iVar3 == 0) {
          uVar4 = 0xffffffff;
          FUN_00407f30(l_apdb_mutex);
          FUN_004084f0(param_2,0x10,auStack_a0);
          if (apdb_warning_switch != 0) {
            printf("[APDB_WARNING]%s()/line %d : Failed to search ap[0x%x],fw_id[%s].\n",
                   "apdb_get_model_by_id",0x2264,param_1,auStack_a0);
          }
        }
        else {
          uVar4 = 0;
          *param_3 = *(undefined4 *)
                      (*(int *)(l_apdb_ap_item_cur + iVar2 * 0x58 + 0x54) +
                       *(int *)(iVar3 + 0x10) * 0x168 + 0x164);
          FUN_00407f30(uVar1);
        }
      }
      else {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : fwid_hash size is 0, err!!!!\n","apdb_get_model_by_id",
                 0x2258);
        }
        uVar4 = 0xffffffff;
        FUN_00407f30(l_apdb_mutex);
      }
    }
  }
  return uVar4;
}

