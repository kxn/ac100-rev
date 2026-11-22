// func apdb_traversal @ 0060b33c size=344

undefined4 apdb_traversal(code *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == (code *)0x0) {
    uVar3 = 0xffffffff;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : input error.\n","apdb_traversal",0x2ab4);
    }
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    for (iVar4 = 0; iVar4 < l_apdb_ap_item_cnt_cur; iVar4 = iVar4 + 1) {
      iVar5 = 0;
      iVar2 = l_apdb_ap_item_cur + iVar4 * 0x58;
      while (iVar5 < *(int *)(iVar2 + 0x4c)) {
        iVar1 = *(int *)(iVar2 + 0x54) + iVar5 * 0x168;
        if (iVar1 == 0) {
          if (apdb_warning_switch == 0) {
            iVar5 = iVar5 + 1;
          }
          else {
            printf("[APDB_WARNING]%s()/line %d : ap model null,[index:%d].\n","apdb_traversal",
                   0x2ac2,iVar4);
            iVar5 = iVar5 + 1;
          }
        }
        else {
          (*param_1)(iVar1,param_2);
          iVar5 = iVar5 + 1;
        }
      }
    }
    uVar3 = 0;
    FUN_00407f30(l_apdb_mutex);
  }
  return uVar3;
}

