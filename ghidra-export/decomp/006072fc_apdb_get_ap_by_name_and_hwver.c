// func apdb_get_ap_by_name_and_hwver @ 006072fc size=392

undefined4 apdb_get_ap_by_name_and_hwver(char *param_1,void *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *__src;
  
  if ((((param_1 == (char *)0x0) || (param_2 == (void *)0x0)) || (param_3 == (void *)0x0)) ||
     (*param_1 == '\0')) {
    if (apdb_warning_switch != 0) {
      printf("[APDB_WARNING]%s()/line %d : input apmodel_name or hwver or ap invalid.\n",
             "apdb_get_ap_by_name_and_hwver",0x2225);
    }
  }
  else {
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    for (iVar3 = 0; iVar3 < l_apdb_ap_item_cnt_cur; iVar3 = iVar3 + 1) {
      iVar2 = 0;
      while (iVar1 = l_apdb_ap_item_cur + iVar3 * 0x58, iVar2 < *(int *)(iVar1 + 0x4c)) {
        __src = (void *)(*(int *)(iVar1 + 0x54) + iVar2 * 0x168);
        iVar1 = strcmp(param_1,(char *)((int)__src + 0xda));
        if (iVar1 == 0) {
          iVar1 = memcmp(*(void **)((int)__src + 0x164),param_2,4);
          if (iVar1 == 0) {
            memcpy(param_3,__src,0x168);
            FUN_00407f30(l_apdb_mutex);
            return 0;
          }
          iVar2 = iVar2 + 1;
        }
        else {
          iVar2 = iVar2 + 1;
        }
      }
    }
    FUN_00407f30(l_apdb_mutex);
  }
  return 0xffffffff;
}

