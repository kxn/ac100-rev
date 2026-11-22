// func _ap_item_add_to_config @ 005ff4b8 size=1032

undefined4 _ap_item_add_to_config(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__s;
  size_t __n;
  size_t sVar4;
  int iVar5;
  undefined4 uVar6;
  FILE *__s_00;
  undefined4 uVar7;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  if (nego_ap_root == 0) {
    _apdb_init_json_mem();
  }
  FUN_00407e80("_ap_item_add_to_config");
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  iVar1 = cJSON_GetObjectItem(nego_ap_root,"ap_item_list");
  if (iVar1 == 0) {
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : get apdb item json failed\n","_ap_item_add_to_config",
             0x1dae);
    }
    _apdb_init_json_mem();
LAB_005ff738:
    uVar7 = 0xffffffff;
    uVar6 = 0;
    __s_00 = (FILE *)0x0;
    __s = (char *)0x0;
  }
  else {
    _apdb_add_item_to_list(local_30,param_1);
    if (param_2 == 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : replace the item\n","_ap_item_add_to_config",0x1dbd);
      }
      iVar2 = cJSON_GetArraySize(iVar1);
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : the array size is %d\n","_ap_item_add_to_config",0x1dbf,
               iVar2);
      }
      for (iVar5 = 0; iVar5 < iVar2; iVar5 = iVar5 + 1) {
        uVar6 = cJSON_GetArrayItem(iVar1,iVar5);
        iVar3 = cJSON_GetObjectItem(uVar6,"id");
        if ((iVar3 == 0) || (*(int *)(iVar3 + 0xc) != 3)) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : parse id failed.\n","_ap_item_add_to_config",0x1dc8);
          }
          goto LAB_005ff738;
        }
        if (*(int *)(iVar3 + 0x14) == *param_1) {
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : get id success:%d\n","_ap_item_add_to_config",0x1dce)
            ;
          }
          cJSON_ReplaceItemInArray(iVar1,iVar5,local_30[0]);
          break;
        }
      }
    }
    else {
      cJSON_AddItemToArray(iVar1,local_30[0]);
    }
    __s = (char *)cJSON_Print(nego_ap_root);
    if (__s == (char *)0x0) {
      if (apdb_debug_switch == 0) {
        uVar7 = 0;
        uVar6 = 1;
      }
      else {
        uVar7 = 0;
        printf("[APDB_DEBUG]%s()/line %d : json change to string error\n\n","_ap_item_add_to_config"
               ,0x1dff);
        uVar6 = 1;
      }
    }
    else {
      __n = strlen(__s);
      if (((int)__n < 0x100001) && (__n != 0)) {
        nego_db_manage = 1;
        __s_00 = fopen("/etc/nouci_config/dbs/apdb_nego.db","w");
        if (__s_00 == (FILE *)0x0) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : Failed to open file[%s]\n","_ap_item_add_to_config",
                   0x1de8,"/etc/nouci_config/dbs/apdb_nego.db");
          }
        }
        else {
          sVar4 = fwrite(__s,1,__n,__s_00);
          if (__n == sVar4) {
            if (apdb_debug_switch != 0) {
              printf("[APDB_DEBUG]%s()/line %d : write file %d bytes success\n",
                     "_ap_item_add_to_config",0x1df7,__n);
            }
            uVar6 = 1;
            _apdb_refresh_update_count(0);
            nego_db_manage = 0;
            uVar7 = 0;
            goto LAB_005ff610;
          }
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : read apdb data failed.\n","_ap_item_add_to_config",
                   0x1df1);
          }
        }
        nego_db_manage = 0;
        uVar6 = 0;
        uVar7 = 0xffffffff;
        goto LAB_005ff610;
      }
      if (apdb_err_switch == 0) {
        uVar7 = 0xffffffff;
        uVar6 = 0;
      }
      else {
        uVar7 = 0xffffffff;
        printf("[APDB_ERROR]%s()/line %d : file is too large or zero.\n","_ap_item_add_to_config",
               0x1dde);
        uVar6 = 0;
      }
    }
    __s_00 = (FILE *)0x0;
  }
LAB_005ff610:
  FUN_00407f30(l_apdb_mutex);
  FUN_004082b0(uVar6,"_ap_item_add_to_config");
  if (__s != (char *)0x0) {
    free(__s);
  }
  if (__s_00 != (FILE *)0x0) {
    fclose(__s_00);
  }
  return uVar7;
}

