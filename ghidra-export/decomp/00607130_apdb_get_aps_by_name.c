// func apdb_get_aps_by_name @ 00607130 size=1

undefined4 apdb_get_aps_by_name(char *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if (((param_1 == (char *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) {
    if (apdb_warning_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_WARNING]%s()/line %d : input apmodel_name or ap_id_arror ap_id_num invalid.\n"
    ;
    uVar3 = 0x21e5;
  }
  else {
    iVar1 = FUN_00408450(0x28,0x21e9);
    if (iVar1 != 0) {
      iVar5 = 0;
      iVar6 = 0;
      FUN_004082d0(l_apdb_mutex,0xffffffff);
      while (uVar3 = l_apdb_mutex, iVar6 < l_apdb_ap_item_cnt_cur) {
        puVar4 = (undefined4 *)(l_apdb_ap_item_cur + iVar6 * 0x58);
        iVar2 = strcmp(param_1,(char *)(puVar4 + 2));
        iVar6 = iVar6 + 1;
        if (iVar2 == 0) {
          iVar2 = iVar5 * 4;
          iVar5 = iVar5 + 1;
          *(undefined4 *)(iVar1 + iVar2) = *puVar4;
        }
      }
      if (iVar5 != 0) {
        *param_3 = iVar5;
        *param_2 = iVar1;
        FUN_00407f30(uVar3);
        return 0;
      }
      if (apdb_warning_switch != 0) {
        printf("[APDB_WARNING]%s()/line %d : cannot find any ap id in apdb.\n",
               "apdb_get_aps_by_name",0x21fd);
      }
      FUN_00407f30(l_apdb_mutex);
      FUN_00407df0(iVar1);
      return 0xffffffff;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : malloc failed.\n";
    uVar3 = 0x21ec;
  }
  printf(__format,"apdb_get_aps_by_name",uVar3);
  return 0xffffffff;
}

